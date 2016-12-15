#include "editperson.h"
#include "ui_editperson.h"

editPerson::editPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editPerson) {
    ui->setupUi(this);
}

editPerson::~editPerson() {
    delete ui;
}

void editPerson::on_pBEdit_clicked() {


    int id = _id;
    int birth = ui->input_birthYear->text().toInt();
    int death = ui->input_deathYear->text().toInt();
    int age;
    char sex;
    string name = ui->input_name->text().toStdString();
    string contribution = ui->input_contribution->toPlainText().toStdString();
    int turing = ui->cB_TuringYear->currentData().toInt();

    //Calculating age:
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    int currYear = (now->tm_year + 1900);
    //int currMonth = (now->tm_mon + 1);
    //int currDay = now->tm_mday;

    if(death == 0)
        age = currYear - birth;
    else
        age = death - birth;

    if(ui->rbMale->isChecked())
        sex = 'm';
    else if(ui->rbFemale->isChecked())
        sex = 'f';

    _ps.editPersonWith(id, name, sex, birth,death, contribution, turing);

    DisplayList dl;
    dl.show();
    this->close();
}

void editPerson::on_pBCancel_clicked() {
    DisplayList dl;
    dl.show();
    this->close();

}

void editPerson::_editPersonWithId(int id){

    _id = id;

    Person p = _ps.getPersonFromId(id);

    ui->cB_TuringYear->setCurrentText(QString::number(p.getTuringYear()));
    ui->input_birthYear->setText(QString::number(p.getBirth()));
    ui->input_contribution->setPlainText(QString::fromStdString(p.getContribution()));
    ui->input_deathYear->setText(QString::number(p.getDeath()));
    ui->input_name->setText(QString::fromStdString(p.getName()));

    if(p.getSex() == 'f')
    {
        ui->rbMale->setChecked(false);
        ui->rbFemale->setChecked(true);
    }
    else
    {
        ui->rbMale->setChecked(true);
        ui->rbFemale->setChecked(false);
    }
}
