#ifndef FCACS_H
#define FCACS_H

#include <fcacs.ui>

namespace Ui {
class FCACS;
}

class FCACS : public FCACS
{
    Q_OBJECT;

public:
    explicit FCACS(QWidget *parent = 0);
    ~FCACS();

private:
    Ui::FCACS *ui;
};

#endif // FCACS_H
