#include "calculator.h"
#include "ui_calculator.h"
#include <iostream>


Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);

    // pic10b
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
    QObject::connect(ui->radioButton_B1 ,SIGNAL(clicked()),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->radioButton_B2 ,SIGNAL(clicked()),
                     this, SLOT(compute_overall()));

    // pic10c
    QObject::connect(ui->slider_c1 ,SIGNAL(valueChanged(int)),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->slider_c2 ,SIGNAL(valueChanged(int)),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->slider_c3 ,SIGNAL(valueChanged(int)),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->slider_c4 ,SIGNAL(valueChanged(int)),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->slider_c5,SIGNAL(valueChanged(int)),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->slider_c6,SIGNAL(valueChanged(int)),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->radioButton_C1 ,SIGNAL(clicked()),
                     this, SLOT(compute_overall()));
    QObject::connect(ui->radioButton_C2 ,SIGNAL(clicked()),
                     this, SLOT(compute_overall()));


}

Calculator::~Calculator()
{
    delete ui;
}


void Calculator::compute_overall(){

    // PIC 10B
    if(ui->tab_1->isActiveWindow()){
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


        if(ui->radioButton_B1->isChecked()) {
            sum = hw_avg*0.25 + midterm1*0.2 + midterm2*0.2 + final*0.35;
            ui->score10b->setText(QString::number(sum));
        }
        if(ui->radioButton_B2->isChecked()){
            sum = hw_avg*0.25 + max_midterm*0.3 + final*0.44;
            ui->score10b->setText(QString::number(sum));
        }
    }

    // PIC 10C
    if(ui->tab_2->isActiveWindow()){
        double hw1 = ui -> slider_c1 ->value();
        double hw2 = ui -> slider_c2 ->value();
        double hw3 = ui -> slider_c3 ->value();
        double hw_avg = (hw1+hw2+hw3)/3;

        double midterm = ui -> slider_c4 ->value();
        double final = ui -> slider_c5 ->value();
        double project = ui -> slider_c6 ->value();

        double sum = 0;

        if(ui->radioButton_C1->isChecked()) {
            sum = hw_avg*0.15 + midterm*0.25 + final*0.30 + project*0.35;
            ui->score10c->setText(QString::number(sum));
        }
        if(ui->radioButton_C2->isChecked()){
            sum = hw_avg*0.15 + final*0.50 + project*0.35;
            ui->score10c->setText(QString::number(sum));
        }
    }


}


//void Calculator::update_overall(int score){
//    //double score = 31.4;
//    //score = static_cast<double>(unused);

//    ui->score->setText(QString::number(score));

//    return;
//}
