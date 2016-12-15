#include "addlinksmenu.h"
#include "ui_addlinksmenu.h"

AddLinksMenu::AddLinksMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLinksMenu) {

    _dbpath =  QCoreApplication::applicationDirPath() + "/create.sqlite";

    _cs = CompService(Database(_dbpath));
    _ps = appservice(Database(_dbpath));
    _ls = LinkService(Database(_dbpath));

    ui->setupUi(this);

    displayPeople();
    displayComps();
}

AddLinksMenu::~AddLinksMenu() {
    delete ui;
}

void AddLinksMenu::on_pLAdd_clicked() {

    string PID = ui->input_PID->text().toStdString();
    string CID = ui->input_CID->text().toStdString();

    cout << "PID : " << PID << endl;
    cout << "CID : " << CID << endl;

    //Check if person id exists

    if(!(_ps.checkIDExists(PID)))
        ui->p_error->setText("<span style='color: #ff0000'>ID not found!</span>");
    else
        ui->p_error->setText("<span style='color: #00ff00'>" + QString::fromStdString(_ps.getPersonFromId(stoi(PID)).getName()) + "</span>");

//Check if computer id exists

    if(!(_cs.checkIDExists(CID)))
    {

        ui->c_error->setText("<span style='color: #ff0000'>ID not found!</span>");
    }
    else
    {

        ui->c_error->setText("<span style='color: #00ff00'>" +  QString::fromStdString((_cs.getCompFromId(stoi(CID)).getName())) + "</span>");

    }

//creating the person

    _ls.create(CID, PID);
    DisplayList dll;
    //this->close();
    dll.displayLinks();
}

void AddLinksMenu::on_pLBack_clicked() {
    DisplayList dl;
    dl.show();
    this->close();
}

void AddLinksMenu::displayPeople() {
    vector<Person> people = _ps.getList();

    ui->table_person->setColumnWidth(0, 25);
    //ui->table_person->setColumnWidth(1, 31);

     ui->table_person->setRowCount(people.size());

     QString PID;
     QString PName;

     for(unsigned int i = 0; i < people.size(); i++) {
         PID = QString::number(people.at(i).getId());
         PName = QString::fromStdString(people.at(i).getName());

         ui->table_person->setItem(i, 0, new QTableWidgetItem(PID));
         ui->table_person->setItem(i, 1, new QTableWidgetItem(PName));
     }



}

void AddLinksMenu::displayComps() {
    ui->table_comps->setColumnWidth(0, 25);
    //ui->table_comps->setColumnWidth(1, 31);

    vector<Comps> comps = _cs.getList();

    ui->table_comps->setRowCount(comps.size());

    QString ID;
    QString Name;

    for(unsigned int i = 0; i < comps.size(); i++) {
        ID = QString::number(comps.at(i).getId());
        Name = QString::fromStdString(comps.at(i).getName());

        ui->table_comps->setItem(i, 0, new QTableWidgetItem(ID));
        ui->table_comps->setItem(i, 1, new QTableWidgetItem(Name));
    }
}

void AddLinksMenu::on_table_person_clicked(const QModelIndex &index)
{
    int currentlySelectedPersIndex =
            ui->table_person->currentIndex().row();
    int pid = (currentlyDisplayedPeople.at(currentlySelectedPersIndex)).getId();
    ui->input_PID->setText(QString::number(pid));


}

void AddLinksMenu::on_table_comps_clicked(const QModelIndex &index)
{
    int currentlySelectedCompIndex =
            ui->table_comps->currentIndex().row();
    int cid = (currentlyDisplayedComps.at(currentlySelectedCompIndex)).getId();
    ui->input_CID->setText(QString::number(cid));
}
