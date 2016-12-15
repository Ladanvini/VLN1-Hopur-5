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


    bool isOk_b = false;
    bool isOk_d = false;
    int id = _id;
    int birth = ui->input_birthYear->text().toInt(&isOk_b);
    string birthstr = ui->input_birthYear->text().toStdString();
    int death = ui->input_deathYear->text().toInt(&isOk_d);
    string deathstr = ui->input_deathYear->text().toStdString();
    int age;
    char sex;
    string name = ui->input_name->text().toStdString();
    string contribution = ui->input_contribution->toPlainText().toStdString();
    int turing = ui->cB_TuringYear->currentText().toInt();

//Setting death = 0 if empty
    if(deathstr.empty()) {
        death = 0;
        isOk_d = true;
    }


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

    string msg = _ps.editPersonWith(id, name, sex, birth,death, contribution, turing);
    if(msg != "")
    {
        QMessageBox mb(this);
        mb.setText(QString::fromStdString(msg));
        mb.exec();
    }
    ui->l_error_name->setText("");
    ui->l_error_birth->setText("");
    ui->l_error_death->setText("");
    ui->l_error_turing->setText("");

//Error check
    if(name.empty() || name.at(0) == ' '|| !isNumb(name)) {
        ui->l_error_name->setText("<span style='color: #ff0000'>Name not accepted!</span>");

        if(birthstr.empty() || !isOk_b || birth < 1000 || birth >= currYear) {
            ui->l_error_birth->setText("<span style='color: #ff0000'>Birth year not accepted!</span>");
        }

        if(!isOk_d || (death != 0 && death <= birth) || death >= currYear) {
            ui->l_error_death->setText("<span style='color: #ff0000'>Death year not accepted!</span>");
        }

        if((turing != 0 && turing < birth) || turing > currYear) {
            ui->l_error_turing->setText("<span style='color: #ff0000'>Turing year not accepted!</span>");
        }

        if(death != 0 && turing > death) {
            ui->l_error_turing->setText("<span style='color: #ff0000'>Turing award after death not accepted!</span>");
        }
        return;
    }
    if(birthstr.empty() || !isOk_b || birth < 1000 || birth >= currYear) {
        ui->l_error_birth->setText("<span style='color: #ff0000'>Birth year not accepted!</span>");

        if(!isOk_d || (death != 0 && death <= birth) || death >= currYear) {
            ui->l_error_death->setText("<span style='color: #ff0000'>Death year not accepted!</span>");
        }

        if((turing != 0 && turing < birth) || turing > currYear) {
            ui->l_error_turing->setText("<span style='color: #ff0000'>Turing year not accepted!</span>");
        }

        if(death != 0 && turing > death) {
            ui->l_error_turing->setText("<span style='color: #ff0000'>Turing award after death not accepted!</span>");
        }
        return;
    }
    if(!isOk_d || (death != 0 && death <= birth) || death >= currYear) {
        ui->l_error_death->setText("<span style='color: #ff0000'>Death year not accepted!</span>");

        if((turing != 0 && turing < birth) || turing > currYear) {
            ui->l_error_turing->setText("<span style='color: #ff0000'>Turing year not accepted!</span>");
        }

        if(death != 0 && turing > death) {
            ui->l_error_turing->setText("<span style='color: #ff0000'>Turing award after death not accepted!</span>");
        }
        return;
    }

    if((turing < birth && turing != 0) || turing > currYear) {
        ui->l_error_turing->setText("<span style='color: #ff0000'>Turing year not accepted!</span>");
        return;
    }

    if(death != 0 && turing > death) {
        ui->l_error_turing->setText("<span style='color: #ff0000'>Turing award after death not accepted!</span>");
        return;
    }

    if(age >= 150) {
        ui->l_error_death->setText("<span style='color: #ff0000'>This age is not possible!</span>");
        ui->l_error_birth->setText("<span style='color: #ff0000'>This age is not possible!</span>");
        return;
    }

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

//In: String
//Out: True if the string contains no numbers or symbols
bool editPerson:: isNumb(string inputname){

    QString qInputName = QString::fromStdString(inputname);
    for(unsigned int i = 0; i < inputname.length();i++)
    {
        if(!qInputName.at(i).isDigit())
            return false;
    }
    return true;

}
