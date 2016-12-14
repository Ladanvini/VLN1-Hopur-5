        #include "searchmenu.h"
    #include "ui_searchmenu.h"

    SearchMenu::SearchMenu(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::SearchMenu)
    {
        ui->setupUi(this);
    }

    SearchMenu::~SearchMenu()
    {
        delete ui;
    }

    void SearchMenu::on_pbGoBackPer_clicked()
    {
        MainWindow mw;
        mw.show();
        this ->close();
    }

    void SearchMenu::on_pBGoBackCom_clicked()
    {
        MainWindow mw;
        mw.show();
        this ->close();
    }

    void SearchMenu::on_cB_SearchForPers_currentIndexChanged(int index)
    {

    }

    void SearchMenu::on_pB_SearchforPers_clicked()
    {
        if(ui->cB_SearchForPers->currentText().toStdString() == "Name") {
            _ps.searchByName(ui->input_SearchForPers->text().toStdString());
        }
        else if(ui->cB_SearchForPers->currentText().toStdString() == "Age") {
            _ps.searchByAge(ui->input_SearchForPers->text().toStdString());
        }
    }
