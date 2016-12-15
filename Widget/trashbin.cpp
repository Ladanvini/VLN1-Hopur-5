#include "trashbin.h"
#include "ui_trashbin.h"

TrashBin::TrashBin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrashBin)
{
    QString _dbpath =  QCoreApplication::applicationDirPath() + "/create.sqlite";

    _cs = CompService(Database(_dbpath));
    _ps = appservice(Database(_dbpath));
    _ls = LinkService(Database(_dbpath));

    ui->setupUi(this);
    displayPeople();
    displayComps();
    displayLinks();

}

TrashBin::~TrashBin()
{
    delete ui;
}
void TrashBin::displayComps(){

    ui->ListComputers->setColumnWidth(0, 50);
    ui->ListComputers->setColumnWidth(3, 150);

    vector<Comps> comps = _ts.getTrashComp();

    ui->ListComputers->setRowCount(comps.size());

    QString ID;
    QString Name;
    QString Type;
    QString YearBuilt;

    for(unsigned int i = 0; i < comps.size(); i++) {
        if(comps.at(i).getId() < 10)
            ID = "0" + QString::number(comps.at(i).getId());
        else
            ID = QString::number(comps.at(i).getId());
        Name = QString::fromStdString(comps.at(i).getName());
        Type = QString::fromStdString(comps.at(i).getType());
        YearBuilt = QString::number(comps.at(i).getYearBuilt());

        ui->ListComputers->setItem(i, 0, new QTableWidgetItem(ID));
        ui->ListComputers->setItem(i, 1, new QTableWidgetItem(Name));
        ui->ListComputers->setItem(i, 2, new QTableWidgetItem(Type));
        ui->ListComputers->setItem(i, 3, new QTableWidgetItem(YearBuilt));
    }
    currentlyDisplayedComps = comps;


}
void TrashBin::displayLinks()
{
    QString _dbpath =  QCoreApplication::applicationDirPath() + "/create.sqlite";

    CompService _cs = CompService(Database(_dbpath));
    appservice _ps = appservice(Database(_dbpath));
    LinkService _ls = LinkService(Database(_dbpath));

    vector<Links> links = _ts.getTrashLinks();

    ui->ListLinks->setColumnWidth(0, 50);
    ui->ListLinks->setColumnWidth(1, 150);
    ui->ListLinks->setColumnWidth(2, 50);
    ui->ListLinks->setColumnWidth(3, 150);

    ui->ListLinks->setRowCount(links.size());

    QString LPID;
    QString LCID;
    QString LName;
    QString LComp;

    for(unsigned int i = 0; i < links.size(); i++) {
        if(links.at(i).getPID() < 10)
            LPID = "0" + QString::number(links.at(i).getPID());
        else
            LPID = QString::number(links.at(i).getPID());
        LName = QString::fromStdString(_ps.getPersonFromId(links.at(i).getPID()).getName());
        if(links.at(i).getCID() < 10)
            LCID = "0" + QString::number(links.at(i).getCID());
        else
            LCID = QString::number(links.at(i).getCID());
        LComp = QString::fromStdString(_cs.getCompFromId(links.at(i).getCID()).getName());

        ui->ListLinks->setItem(i, 0, new QTableWidgetItem(LPID));
        ui->ListLinks->setItem(i, 1, new QTableWidgetItem(LName));
        ui->ListLinks->setItem(i, 2, new QTableWidgetItem(LCID));
        ui->ListLinks->setItem(i, 3, new QTableWidgetItem(LComp));
    }
    currentlyDisplayedLink = links;

}
void TrashBin::displayPeople()
{
    vector<Person> people = _ts.getTrashPeople();

    ui->ListPersons->setColumnWidth(0, 50);
    ui->ListPersons->setColumnWidth(1, 100);
    ui->ListPersons->setColumnWidth(2, 50);
    ui->ListPersons->setColumnWidth(3, 50);
    ui->ListPersons->setColumnWidth(4, 75);
    ui->ListPersons->setColumnWidth(5, 75);
    ui->ListPersons->setColumnWidth(6, 75);
    ui->ListPersons->setColumnWidth(7, 175);

    ui->ListPersons->setRowCount(people.size());

    QString PID;
    QString PName;
    QString PGender;
    QString PAge;
    QString PBirth;
    QString PDeath;
    QString PTuring;
    QString PContribution;

    for(unsigned int i = 0; i < people.size(); i++) {
        if(people.at(i).getId() < 10)
            PID = "0" + QString::number(people.at(i).getId());
        else
            PID = QString::number(people.at(i).getId());
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

        ui->ListPersons->setItem(i, 0, new QTableWidgetItem(PID));
        ui->ListPersons->setItem(i, 1, new QTableWidgetItem(PName));
        ui->ListPersons->setItem(i, 2, new QTableWidgetItem(PGender));
        ui->ListPersons->setItem(i, 3, new QTableWidgetItem(PAge));
        ui->ListPersons->setItem(i, 4, new QTableWidgetItem(PBirth));
        ui->ListPersons->setItem(i, 5, new QTableWidgetItem(PDeath));
        ui->ListPersons->setItem(i, 6, new QTableWidgetItem(PTuring));
        ui->ListPersons->setItem(i, 7, new QTableWidgetItem(PContribution));
    }
    currentlyDisplayedPerson = people;

}

void TrashBin::on_pBLRestore_clicked()
{
    int currentIndex = ui->ListLinks->currentIndex().row();

    _ts.restoreLink(currentlyDisplayedLink.at(currentIndex));

    displayLinks();
}

void TrashBin::on_pBCRestore_clicked()
{
    int currentIndex = ui->ListComputers->currentIndex().row();

    _ts.restoreComp(currentlyDisplayedComps.at(currentIndex));

    displayComps();
}

void TrashBin::on_pBPRestore_clicked()
{
    int currentIndex = ui->ListPersons->currentIndex().row();

    _ts.restorePers(currentlyDisplayedPerson.at(currentIndex));

    displayPeople();
}

void TrashBin::on_pBPTBack_clicked()
{
    DisplayList dl;
    this->hide();
    dl.exec();
}

void TrashBin::on_pBCTBack_clicked()
{
    DisplayList dl;
    this->hide();
    dl.exec();
}

void TrashBin::on_pBLTBack_clicked()
{
    DisplayList dl;
    this->hide();
    dl.exec();
}
