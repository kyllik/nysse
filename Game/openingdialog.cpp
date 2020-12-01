#include "openingdialog.hh"
#include "ui_openingdialog.h"

OpeningDialog::OpeningDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpeningDialog)
{
    ui->setupUi(this);
    connect(ui->startButton,&QPushButton::clicked,this,&OpeningDialog::accept);
    connect(this,&OpeningDialog::finished,this,&OpeningDialog::endDialog);
    ui->radioButton30s->click();
}

OpeningDialog::~OpeningDialog()
{
    delete ui;
}

void OpeningDialog::endDialog()
{
   if(ui->radioButton30s->QRadioButton::isChecked())
   {
       emit tellGameLenght(30);
   } else if (ui->radioButton1min->QRadioButton::isChecked()){
       emit tellGameLenght(60);
   } else if (ui->radioButton2min->QRadioButton::isChecked()){
       emit tellGameLenght(120);
   }
}
