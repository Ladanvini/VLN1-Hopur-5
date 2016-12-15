#include "personcreatemenu.h"
#include "ui_personcreatemenu.h"

PersonCreateMenu::PersonCreateMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonCreateMenu) {
/*    _dbpath =  QCoreApplication::applicationDirPath() + "/create.sqlite";

    _cs = CompService(_dbpath);
    _ps = appservice(_dbpath);
    _ls = LinkService(_dbpath);
*/
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
    string birthstr = ui->input_YearBorn->text().toStdString();
    int death = ui->input_YearDeath->text().toInt(&isOk_d);
    string deathstr = ui->input_YearDeath->text().toStdString();
    int age;
    char sex;
    string name = ui->input_Name->text().toStdString();
    string contribution = ui->input_Contribution->toPlainText().toStdString();
    int turing = ui->cB_TuringYear->currentText().toInt();

//Setting death = 0 if empty
    if(deathstr.empty()) {
        death = 0;
        isOk_d = true;
    }

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
    ui->l_error_birth->setText("");
    ui->l_error_death->setText("");
    ui->l_error_turing->setText("");

//Error check
    if(name.empty() || name.at(0) == ' '||!isNumb(name)) {
        ui->l_error_name->setText("<span style='color: #ff0000'>Name not accepted!</span>");

        if(birthstr.empty() || !isOk_b || birth < 1000 || birth >= currYear) {
            ui->l_error_birth->setText("<span style='color: #ff0000'>Birth year not accepted!</span>");
        }

        if(!isOk_d || (death != 0 && death < birth) || death >= currYear) {
            ui->l_error_death->setText("<span style='color: #ff0000'>Death year not accepted!</span>");
        }

        if((turing != 0 && turing < birth) || turing > currYear) {
            ui->l_error_turing->setText("<span style='color: #ff0000'>Turing year not accepted!</span>");
        }

        if(death != 0 && turing > death) {
            ui->l_error_turing->setText("<span style='color: #ff0000'>You cannot win a Turing award after you'r dead!</span>");
        }
        return;
    }
    if(birthstr.empty() || !isOk_b || birth < 1000 || birth >= currYear) {
        ui->l_error_birth->setText("<span style='color: #ff0000'>Birth year not accepted!</span>");

        if(!isOk_d || (death != 0 && death < birth) || death >= currYear) {
            ui->l_error_death->setText("<span style='color: #ff0000'>Death year not accepted!</span>");
        }

        if((turing != 0 && turing < birth) || turing > currYear) {
            ui->l_error_turing->setText("<span style='color: #ff0000'>Turing year not accepted!</span>");
        }

        if(death != 0 && turing > death) {
            ui->l_error_turing->setText("<span style='color: #ff0000'>You cannot win a Turing award after you'r dead!</span>");
        }
        return;
    }
    if(!isOk_d || (death != 0 && death < birth) || death >= currYear) {
        ui->l_error_death->setText("<span style='color: #ff0000'>Death year not accepted!</span>");

        if((turing != 0 && turing < birth) || turing > currYear) {
            ui->l_error_turing->setText("<span style='color: #ff0000'>Turing year not accepted!</span>");
        }

        if(death != 0 && turing > death) {
            ui->l_error_turing->setText("<span style='color: #ff0000'>You cannot win a Turing award after you'r dead!</span>");
        }
        return;
    }
    if((turing < birth && turing != 0) || turing > currYear) {
        ui->l_error_turing->setText("<span style='color: #ff0000'>Turing year not accepted!</span>");
        return;
    }
    if(death != 0 && turing > death) {
        ui->l_error_turing->setText("<span style='color: #ff0000'>You cannot win a Turing award after you'r dead!</span>");
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
