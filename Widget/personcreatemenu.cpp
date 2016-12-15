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
    bool isOk_b = false;
    bool isOk_d = false;

    int id = 0;
    int birth = ui->input_YearBorn->text().toInt(&isOk_b);
    int death = ui->input_YearDeath->text().toInt(&isOk_d);
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

    ui->l_error_name->setText("");


//Error check TODO
        if(name.empty() || name.at(0) == ' '||!isNumb(name)) {
            ui->l_error_name->setText("<span style='color: #ff0000'>Name not accepted!</span>");
            return;
        }
        if(birth == NULL||!isOk_b){
            ui->l_error_birth->setText("<span style='color: #ff0000'>Birth year not accepted!</span>");
            return;
        }
        if(death == NULL||!isOk_d){
            ui->l_error_death->setText("<span style='color: #ff0000'>Death year is not accepted!</span>");
            return;
        }

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

//In: String
//Out: True if the string contains no numbers or symbols
bool PersonCreateMenu:: isNumb(string inputname){

    QString qInputName = QString::fromStdString(inputname);
    for(int i = 0; i < inputname.length();i++)
    {
        if(qInputName.at(i).isDigit()||!qInputName.at(i).isLetter())
            return false;
        else
            return true;
    }

}
