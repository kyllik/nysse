#include "openingdialog.hh"
#include "ui_openingdialog.h"

OpeningDialog::OpeningDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpeningDialog)
{
    ui->setupUi(this);
    connect(ui->startButton,&QPushButton::clicked,this,&OpeningDialog::endDialog);
}

OpeningDialog::~OpeningDialog()
{
    delete ui;
}

void OpeningDialog::endDialog()
{
   if(ui->radioButton1->QRadioButton::isChecked())
   {
       emit tellGameLenght(1);
   } else if (ui->radioButton3->QRadioButton::isChecked()){
       emit tellGameLenght(3);
   } else if (ui->radioButton5->QRadioButton::isChecked()){
       emit tellGameLenght(5);
   }
}
