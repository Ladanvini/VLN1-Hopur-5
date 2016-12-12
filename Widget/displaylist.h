#ifndef DISPLAYLIST_H
#define DISPLAYLIST_H

#include <QWidget>

namespace Ui {
class DisplayList;
}

class DisplayList : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayList(QWidget *parent = 0);
    ~DisplayList();

private:
    Ui::DisplayList *ui;
};

#endif // DISPLAYLIST_H
