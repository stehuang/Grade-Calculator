#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);

    QObject::connect(ui->slider_1 ,SIGNAL(valueChanged(int)),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->slider_2 ,SIGNAL(valueChanged(int)),
                     this, SLOT(compute_overall()));

}

Calculator::~Calculator()
{
    delete ui;
}


void Calculator::compute_overall(){
    double hw1 = ui -> slider_1 ->value();
    double hw2 = ui -> slider_2 ->value();
    double sum = hw1+hw2;

    ui->score->setText(QString::number(sum));
}


void Calculator::update_overall(int unused){
    double score = 31.4;
    //score = static_cast<double>(unused);

    ui->score->setText(QString::number(score));

    return;
}
