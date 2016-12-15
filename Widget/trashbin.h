#ifndef TRASHBIN_H
#define TRASHBIN_H

#include <QDialog>

namespace Ui {
class TrashBin;
}

class TrashBin : public QDialog
{
    Q_OBJECT

public:
    explicit TrashBin(QWidget *parent = 0);
    ~TrashBin();

private:
    Ui::TrashBin *ui;
};

#endif // TRASHBIN_H
