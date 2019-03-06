#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

signals:
    void compute_overall();

public slots:
    void update_overall(int);

private:
    Ui::Calculator *ui;
};

#endif // CALCULATOR_H
