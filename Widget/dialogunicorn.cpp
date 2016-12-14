#include "dialogunicorn.h"
#include "ui_dialogunicorn.h"

DialogUnicorn::DialogUnicorn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUnicorn) {
    ui->setupUi(this);
}

DialogUnicorn::~DialogUnicorn() {
    delete ui;
}
