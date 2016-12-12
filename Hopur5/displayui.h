#ifndef DISPLAYUI_H
#define DISPLAYUI_H

#include <QWidget>

namespace Ui {
class DisplayUi;
}

class DisplayUi : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayUi(QWidget *parent = 0);
    ~DisplayUi();

private:
    Ui::DisplayUi *ui;
};

#endif // DISPLAYUI_H
