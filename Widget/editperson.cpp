#include "editperson.h"
#include "ui_editperson.h"

editPerson::editPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editPerson)
{
    ui->setupUi(this);
}

editPerson::~editPerson()
{
    delete ui;
}

void editPerson::on_pBEdit_clicked()
{
    int id = 0;
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
}

void editPerson::on_pBCancel_clicked()
{

}
