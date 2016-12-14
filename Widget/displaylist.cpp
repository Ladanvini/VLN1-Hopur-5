#include "displaylist.h"
#include "ui_displaylist.h"

#include "mainwindow.h"
DisplayList::DisplayList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayList)
{
    ui->setupUi(this);
    displayPeople();
    displayComps();
    displayLinks();
}

DisplayList::~DisplayList()
{
    delete ui;
}

void DisplayList::on_pBPBack_clicked()
{
    MainWindow mw;
    mw.show();
    this ->close();
}

void DisplayList::on_pBLBack_clicked()
{
    on_pBPBack_clicked();
}

void DisplayList::on_pBCBack_clicked()
{
    on_pBPBack_clicked();
}

void DisplayList::on_pBCAdd_clicked()
{
    AddComputerMenu adcm;
    //this->hide();
    adcm.exec();
   //this->show();

    displayComps();
}

void DisplayList::on_tableWidget_activated(const QModelIndex &index)
{

    QTableWidgetItem* item = new QTableWidgetItem("YO");
    //QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(_cs.getList().at(0).getName()), 0);
    ui->ListComputers->setItem(0, 0, item);

}

void DisplayList::on_ListComputers_clicked(const QModelIndex &index)
{

    ui->pBCEdit->setEnabled(true);
    ui->pBCDelete->setEnabled(true);

}

void DisplayList::on_pBLAdd_clicked()
{
    AddLinksMenu alm;
    alm.exec();

    displayLinks();
}

void DisplayList::on_pBPAdd_clicked()
{
    PersonCreateMenu pcm;
    //DisplayList->hide();
    pcm.exec();
    //this->show();

    displayPeople();
}

void DisplayList::on_ListLinks_clicked(const QModelIndex &index)
{
    ui->pBLEdit->setEnabled(true);
    ui->pBLDelete->setEnabled(true);
}

void DisplayList::on_ListPersons_clicked(const QModelIndex &index)
{
    ui->pBPEdit->setEnabled(true);
    ui->pBPDelete->setEnabled(true);
}

void DisplayList::on_pBPDelete_clicked()
{
    string currentlySelectedName;
    int currentlySelectedBirth;

    int currentlySelectedPersonIndex = ui->ListPersons->currentIndex().row();
    Person currentlySelectedPerson = currentlyDisplayedPerson.at(currentlySelectedPersonIndex);

    currentlySelectedName = currentlySelectedPerson.getName();
    currentlySelectedBirth = currentlySelectedPerson.getBirth();

    _ps.deletePerson(currentlySelectedName, currentlySelectedBirth);

    displayPeople();

    ui->pBPEdit->setEnabled(false);
    ui->pBPDelete->setEnabled(false);
}

void DisplayList::on_pBCDelete_clicked()
{
    string currentlySelectedName;
    string currentlySelectedType;

    int currentlySelectedCompsIndex = ui->ListComputers->currentIndex().row();
    Comps currentlySelectedComps = currentlyDisplayedComps.at(currentlySelectedCompsIndex);

    currentlySelectedName = currentlySelectedComps.getName();
    currentlySelectedType = currentlySelectedComps.getType();

    _cs.deleteComputers(currentlySelectedName, currentlySelectedType);

    displayComps();

    ui->pBCEdit->setEnabled(false);
    ui->pBPDelete->setEnabled(false);
}

void DisplayList::on_pBLDelete_clicked()
{
    int currentlySelectedPerson;
    int currentlySelectedComps;

    int currentlySelectedLinkIndex = ui->ListLinks->currentIndex().row();
    Links currentlySelectedLink = currentlyDisplayedLink.at(currentlySelectedLinkIndex);

    currentlySelectedPerson = currentlySelectedLink.getPID();
    currentlySelectedComps = currentlySelectedLink.getCID();

    _ls.deleteLink(currentlySelectedComps, currentlySelectedPerson);

    displayLinks();

    ui->pBCEdit->setEnabled(false);
    ui->pBPDelete->setEnabled(false);
}

void DisplayList::displayComps() {

    vector<Comps> comps = _cs.getList();

    ui->ListComputers->setRowCount(comps.size());

    QString Name;
    QString Type;
    QString YearBuilt;

    for(unsigned int i=0; i<comps.size(); i++){
        Name = QString::fromStdString(comps.at(i).getName());
        Type = QString::fromStdString(comps.at(i).getType());
        YearBuilt = QString::number(comps.at(i).getYearBuilt());

        ui->ListComputers->setItem(i, 0, new QTableWidgetItem(Name));
        ui->ListComputers->setItem(i, 1, new QTableWidgetItem(Type));
        ui->ListComputers->setItem(i, 2, new QTableWidgetItem(YearBuilt));

    }

    currentlyDisplayedComps = comps;
}

void DisplayList::displayPeople() {
    vector<Person> people = _ps.getList();

    ui->ListPersons->setRowCount(people.size());

    QString PName;
    QString PGender;
    QString PAge;
    QString PBirth;
    QString PDeath;
    QString PTuring;
    QString PContribution;

    for(unsigned int i = 0; i < people.size(); i++) {
        PName = QString::fromStdString(people.at(i).getName());
        if(people.at(i).getSex() == 'm')
            PGender = "Male";
        else
            PGender = "Female";
        if(people.at(i).getAge() < 10)
            PAge = "0" + QString::number(people.at(i).getAge());
        else
            PAge = QString::number(people.at(i).getAge());

        PBirth = QString::number(people.at(i).getBirth());
        PDeath = QString::number(people.at(i).getDeath());
        PTuring = QString::number(people.at(i).getTuringYear());
        PContribution = QString::fromStdString(people.at(i).getContribution());

        ui->ListPersons->setItem(i, 0, new QTableWidgetItem(PName));
        ui->ListPersons->setItem(i, 1, new QTableWidgetItem(PGender));
        ui->ListPersons->setItem(i, 2, new QTableWidgetItem(PAge));
        ui->ListPersons->setItem(i, 3, new QTableWidgetItem(PBirth));
        ui->ListPersons->setItem(i, 4, new QTableWidgetItem(PDeath));
        ui->ListPersons->setItem(i, 5, new QTableWidgetItem(PTuring));
        //ui->ListPersons->setItem(i, 6, new QTableWidgetItem(PContribution));

    }

    currentlyDisplayedPerson = people;
}

void DisplayList::displayLinks() {
    vector<Links> links = _ls.getLinkList();

    ui->ListLinks->setRowCount(links.size());

    QString LName;
    QString LComp;

    for(unsigned int i=0; i<links.size(); i++){
        LName = QString::fromStdString(_ps.getPersonFromId(links.at(i).getPID()).getName());
        LComp = QString::fromStdString(_cs.getCompFromId(links.at(i).getCID()).getName());
        ui->ListLinks->setItem(i, 0, new QTableWidgetItem(LName));
        ui->ListLinks->setItem(i, 1, new QTableWidgetItem(LComp));

    }

    currentlyDisplayedLink = links;
}
