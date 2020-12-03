#include "endingdialog.hh"
#include "ui_endingdialog.h"

EndingDialog::EndingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndingDialog)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&EndingDialog::tellCloseGame);
}

EndingDialog::~EndingDialog()
{
    delete ui;
}

void EndingDialog::showScore(int n)
{
    ui->lcdNumber->display(n);
}

void EndingDialog::tellCloseGame()
{
    emit closeGame();
}
