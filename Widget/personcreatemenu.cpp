#include "personcreatemenu.h"
#include "ui_personcreatemenu.h"

PersonCreateMenu::PersonCreateMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonCreateMenu) {
    ui->setupUi(this);
}

PersonCreateMenu::~PersonCreateMenu() {
    delete ui;
}

void PersonCreateMenu::on_pBAddPerson_clicked() {
    int id = 0;
    int birth = ui->input_YearBorn->text().toInt();
    int death = ui->input_YearDeath->text().toInt();
    int age;
    char sex;
    string name = ui->input_Name->text().toStdString();
    string contribution = ui->input_Contribution->toPlainText().toStdString();
    int turing = ui->cB_TuringYear->currentData().toInt();

//Calculating age:
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t);
    int currYear = (now->tm_year + 1900);
    //int currMonth = (now->tm_mon + 1);
    //int currDay = now->tm_mday;

    if(death == 0)
        age = currYear - birth;
    else
        age = death - birth;

//setting gender:
    if(ui->rBMale->isChecked())
        sex = 'm';
    else if(ui->rBFemale->isChecked())
        sex = 'f';

//creating the person
    _ps.create(id, name, age, sex, birth, death, contribution, turing);
    DisplayList dlp;
    this->close();
    dlp.displayPeople();
}

void PersonCreateMenu::on_pBBack_clicked() {
    DisplayList dl;
    dl.show();
    this->close();
}
