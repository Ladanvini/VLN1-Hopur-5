#include "displaylist.h"
#include "ui_displaylist.h"
#include "mainwindow.h"

using namespace std;

DisplayList::DisplayList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayList) {
    _dbpath =  QCoreApplication::applicationDirPath() + "/create.sqlite";

    _cs = CompService(Database(_dbpath));
    _ps = appservice(Database(_dbpath));
    _ls = LinkService(Database(_dbpath));

    ui->setupUi(this);
    displayPeople();
    displayComps();
    displayLinks();
}

DisplayList::~DisplayList() {
    delete ui;
}

void DisplayList::on_pBPBack_clicked() {
    MainWindow mw;
    mw.show();
    this ->close();
}

void DisplayList::on_pBLBack_clicked() {
    on_pBPBack_clicked();
}

void DisplayList::on_pBCBack_clicked() {
    on_pBPBack_clicked();
}

void DisplayList::on_pBCAdd_clicked() {
    AddComputerMenu adcm;
    adcm.exec();
    displayComps();
}

void DisplayList::on_tableWidget_activated(const QModelIndex &index) {
    cerr << index.isValid();
    QTableWidgetItem* item = new QTableWidgetItem("YO");
    //QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(_cs.getList().at(0).getName()), 0);
    ui->ListComputers->setItem(0, 0, item);
}

void DisplayList::on_ListComputers_clicked(const QModelIndex &index) {
    cerr << index.isValid();
    ui->pBCEdit->setEnabled(true);
    ui->pBCDelete->setEnabled(true);
}

void DisplayList::on_pBLAdd_clicked() {
    AddLinksMenu alm;
    alm.currentlyDisplayedLinks = currentlyDisplayedLink;
    alm.currentlyDisplayedComps = currentlyDisplayedComps;
    alm.currentlyDisplayedPeople = currentlyDisplayedPerson;

    alm.exec();
    displayLinks();
}

void DisplayList::on_pBPAdd_clicked() {
    PersonCreateMenu pcm;
    pcm.exec();
    displayPeople();
}

void DisplayList::on_ListLinks_clicked(const QModelIndex &index) {
    cerr << index.isValid() << endl;
    ui->pBLDelete->setEnabled(true);
}

void DisplayList::on_ListPersons_clicked(const QModelIndex &index) {
    cerr << index.isValid() << endl;
    ui->pBPEdit->setEnabled(true);
    ui->pBPDelete->setEnabled(true);
}

void DisplayList::on_pBPDelete_clicked() {
    string currentlySelectedName;
    int currentlySelectedBirth;

    int index = ui->ListPersons->currentIndex().row();
    int currentlySelectedID = ui->ListPersons->item(index, 0)->text().toInt();

    Person currentlySelectedPerson = _ps.getPersonFromId(currentlySelectedID);

    currentlySelectedName = currentlySelectedPerson.getName();
    currentlySelectedBirth = currentlySelectedPerson.getBirth();

    _ps.deletePerson(currentlySelectedName, currentlySelectedBirth);

    displayPeople();
    displayLinks();

    ui->pBPEdit->setEnabled(false);
    ui->pBPDelete->setEnabled(false);
}

void DisplayList::on_pBCDelete_clicked() {
    string currentlySelectedName;
    string currentlySelectedType;

    int index = ui->ListComputers->currentIndex().row();
    int selId = ui->ListComputers->item(index, 0)->text().toInt();
    Comps currentlySelectedComps = _cs.getCompFromId(selId);

    currentlySelectedName = currentlySelectedComps.getName();
    currentlySelectedType = currentlySelectedComps.getType();

    _cs.deleteComputers(currentlySelectedName, currentlySelectedType);

    displayComps();
    displayLinks();

    ui->pBCEdit->setEnabled(false);
    ui->pBCDelete->setEnabled(false);
}

void DisplayList::on_pBLDelete_clicked() {
    int currentlySelectedPerson;
    int currentlySelectedComps;
    int index = ui->ListLinks->currentIndex().row();
    int selCompId = ui->ListLinks->item(index, 2)->text().toInt();
    int selPerId = ui->ListLinks->item(index, 0)->text().toInt();


    currentlySelectedPerson = _ps.getPersonFromId(selPerId).getId();
    currentlySelectedComps = _cs.getCompFromId(selCompId).getId();

    _ls.deleteLink(currentlySelectedComps, currentlySelectedPerson);

    displayLinks();

    ui->pBLEdit->setEnabled(false);
    ui->pBLDelete->setEnabled(false);
}

void DisplayList::displayComps() {
    ui->ListComputers->setColumnWidth(0, 50);
    ui->ListComputers->setColumnWidth(3, 150);

    vector<Comps> comps = _cs.getList();

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

void DisplayList::displayPeople() {
    vector<Person> people = _ps.getList();

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

        cout << people.at(i).getName() << endl;
        currentlyDisplayedPerson.push_back(people.at(i));
    }

}

void DisplayList::displayLinks() {
    vector<Links> links = _ls.getLinkList();

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

void DisplayList::on_pBPEdit_clicked() {
    int currentlySelectedID;

    int currentlySelectedPersonIndex = ui->ListPersons->currentIndex().row();

    currentlySelectedID = ui->ListPersons->item(currentlySelectedPersonIndex, 0)->text().toInt();


    editPerson ep;
    ep._editPersonWithId(currentlySelectedID);
    ep.exec();
    displayPeople();
}

void DisplayList::on_pBCEdit_clicked() {
    int currentlySelectedID;

    int currentlySelectedCompsIndex = ui->ListComputers->currentIndex().row();

    currentlySelectedID = ui->ListComputers->item(currentlySelectedCompsIndex, 0)->text().toInt();

    editComputer ec;

    ec._editWithId(currentlySelectedID);
    ec.exec();
    displayComps();
}

/*************************SEARCH****************************/
//Checks what the combo box is set to and searches it
void DisplayList::on_input_SearchComp_clicked() {
    string CompsCB = ui->cB_SearchForComp->currentText().toStdString();

    if(CompsCB == "Name")
        displayComps(_cs.searchByName(ui->le_SearchComp->text().toStdString()));
    else if(CompsCB == "Type")
        displayComps(_cs.searchByType(ui->le_SearchComp->text().toStdString()));
    else if(CompsCB == "Built")
        displayComps(_cs.searchByBuilt(ui->le_SearchComp->text().toStdString()));
    else if(CompsCB == "ID")
        displayComps(_cs.searchById(ui->le_SearchComp->text().toStdString()));
}

void DisplayList::on_input_SearchPers_clicked() {
    string PersonCB = ui->cB_SearchForPers->currentText().toStdString();

    if(PersonCB == "Name")
        displayPeople(_ps.searchByName(ui->le_SearchPers->text().toStdString()));
    else if(PersonCB == "Gender")
        displayPeople(_ps.searchBySex(ui->le_SearchPers->text().toStdString()));
    else if(PersonCB == "Age")
        displayPeople(_ps.searchByAge(ui->le_SearchPers->text().toStdString()));
    else if(PersonCB == "Birth")
        displayPeople(_ps.searchByBirth(ui->le_SearchPers->text().toStdString()));
    else if(PersonCB == "Death")
        displayPeople(_ps.searchByDeath(ui->le_SearchPers->text().toStdString()));
    else if(PersonCB == "Turing")
        displayPeople(_ps.searchByTuring(ui->le_SearchPers->text().toStdString()));
    else if(PersonCB == "Contribution")
        displayPeople(_ps.searchByContribution(ui->le_SearchPers->text().toStdString()));
}

void DisplayList::displayPeople(vector<Person> people) {
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
void DisplayList::displayComps(vector<Comps> comps){
    ui->ListComputers->setColumnWidth(0, 50);
    ui->ListComputers->setColumnWidth(3, 150);

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
void DisplayList::displayLinks(vector<Links> links) {
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

void DisplayList::on_cB_SearchForPers_currentTextChanged(const QString &arg1) {
    cerr << arg1.toStdString() << endl;

    if(ui->cB_SearchForPers->currentText() == "Gender") {
        ui->le_SearchPers->setPlaceholderText("Input 'F'or 'M' ");
    }
    else if(ui->cB_SearchForPers->currentText() == "Turing") {
        ui->le_SearchPers->setPlaceholderText("Input 'Yes' or 'No'");
    }
    else
        ui->le_SearchPers->setText("");
}

void DisplayList::on_input_SearchLink_clicked() {
    string CompsCB = ui->cB_SearchForLinks->currentText().toStdString();

    if(CompsCB == "Name") {
        displayLinks(_ls.searchByName(ui->le_Searchlink->text().toStdString()));
    }
    else if (CompsCB == "ID") {
        displayLinks(_ls.searchById(ui->le_Searchlink->text().toStdString()));
    }
}

void DisplayList::on_ListPersons_doubleClicked(const QModelIndex &index) {
    cerr << index.isValid() << endl;

    int currentlySelectedIndex = ui->ListPersons->currentIndex().row();
    int currentlySelectedID = ui->ListPersons->item(currentlySelectedIndex, 0)->text().toInt();

    Profile pro;
    pro.showPersonWithID(currentlySelectedID);
    pro.exec();
}
