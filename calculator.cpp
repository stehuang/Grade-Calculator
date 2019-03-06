#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
}


void Calculator::update_overall(int unused){
    // double score = 31.4;
    double score = static_cast<double>(unused);

    //ui->label_14->setText(QString::number(score));

    return;
}
