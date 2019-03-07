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
    QObject::connect(ui->slider_3 ,SIGNAL(valueChanged(int)),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->slider_4 ,SIGNAL(valueChanged(int)),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->slider_5 ,SIGNAL(valueChanged(int)),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->slider_6 ,SIGNAL(valueChanged(int)),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->slider_7 ,SIGNAL(valueChanged(int)),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->slider_8 ,SIGNAL(valueChanged(int)),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->slider_9 ,SIGNAL(valueChanged(int)),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->slider_10 ,SIGNAL(valueChanged(int)),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->slider_11 ,SIGNAL(valueChanged(int)),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->radioButton_A ,SIGNAL(clicked()),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->comboBox ,SIGNAL(currentIndexChanged()),
                     this, SLOT(compute_overall()));

}

Calculator::~Calculator()
{
    delete ui;
}


void Calculator::compute_overall(){
    QString course = ui->comboBox->currentText();
    if(course == "PIC 10B"){
        double hw1 = ui -> slider_1 ->value();
        double hw2 = ui -> slider_2 ->value();
        double hw3 = ui -> slider_3 ->value();
        double hw4 = ui -> slider_4 ->value();
        double hw5 = ui -> slider_5 ->value();
        double hw6 = ui -> slider_6 ->value();
        double hw7 = ui -> slider_7 ->value();
        double hw8 = ui -> slider_8 ->value();
        double hw_avg = (hw1+hw2+hw3+hw4+hw5+hw6+hw7+hw8)/8;

        double midterm1 = ui -> slider_9 ->value();
        double midterm2 = ui -> slider_10 ->value();
        double final = ui -> slider_11 ->value();

        double max_midterm = 0;
        if(midterm1 > midterm2)
            max_midterm = midterm1;
        else
            max_midterm = midterm2;

        double sum = 0;

        if(ui->radioButton_A->isChecked())
            sum = hw_avg*0.25 + midterm1*0.2 + midterm2*0.2 + final*0.35;
        if(ui->radioButton_B->isChecked())
            sum = hw_avg*0.25 + max_midterm*0.3 + final*0.44;

        update_overall(sum);
        ui->score->setText(QString::number(sum));
    }

}


void Calculator::update_overall(int unused){
    double score = 31.4;
    //score = static_cast<double>(unused);

    ui->score->setText(QString::number(unused));

    return;
}
