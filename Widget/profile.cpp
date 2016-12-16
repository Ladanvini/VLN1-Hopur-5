#include "profile.h"
#include "ui_profile.h"

Profile::Profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Profile) {
    ui->setupUi(this);
}

Profile::~Profile() {
    delete ui;
}

void Profile::showPersonWithID(int id) {
    Person p = _ps.getPersonFromId(id);

    ui->l_turing_pers->setText(QString::number(p.getTuringYear()));
    ui->l_birth_pers->setText(QString::number(p.getBirth()));
    ui->l_cont_pers->setText(QString::fromStdString(p.getContribution()));
    ui->l_death_pers->setText(QString::number(p.getDeath()));
    ui->l_name_pers->setText(QString::fromStdString(p.getName()));
    ui->l_id_pers->setText(QString::number(p.getId()));
    ui->l_sex_pers->setText(QString(p.getSex()));
}

void Profile::on_pProBack_clicked() {
    DisplayList dl;
    dl.show();
    this->close();
}
