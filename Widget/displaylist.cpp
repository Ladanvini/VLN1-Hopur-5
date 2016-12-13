#include "displaylist.h"
#include "ui_displaylist.h"

#include "mainwindow.h"
DisplayList::DisplayList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayList)
{

    vector<Comps> comps = _cs.getList();

    ui->setupUi(this);

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
    AddComputerMenu adcm(this);
    this->hide();
    adcm.exec();
   //this->show();
}

void DisplayList::on_tableWidget_activated(const QModelIndex &index)
{

    QTableWidgetItem* item = new QTableWidgetItem("YO");
    //QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(_cs.getList().at(0).getName()), 0);
    ui->ListComputers->setItem(0, 0, item);

}

void DisplayList::on_ListComputers_clicked(const QModelIndex &index)
{

    QString Name = "BARABARAAAA";

    ui->ListComputers->setItem(0, 0, new QTableWidgetItem(Name));


}

void DisplayList::on_pBLAdd_clicked()
{
    on_pBCAdd_clicked();
}

void DisplayList::on_pBPAdd_clicked()
{
    on_pBCAdd_clicked();
}
