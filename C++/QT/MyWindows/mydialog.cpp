#include "mydialog.h"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);

QPixmap pix("/Codigos/QT/windowss/MyWindows/20211129_232307.jpg");
 int w = ui->label_picture->width();
 int h = ui->label_picture->height();
 //ui->label_picture->setPixmap(pix);
 ui->label_picture->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_showButton_clicked()
{
    ui->label_picture->setVisible(true);
}
void MyDialog::on_hideButton_clicked()
{
    ui->label_picture->setVisible(false);
}

