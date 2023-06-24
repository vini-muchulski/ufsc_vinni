#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->addItem("AAA");
    ui->listWidget->addItem("BBB");
    ui->listWidget->addItem("CCC");
    for(int i = 10; i < 20; i++)
    {
        ui->listWidget->addItem(QString::number(i) + " item" );
    }

    QListWidgetItem *item1 = new QListWidgetItem (QIcon(":/rec/mgs-v-wallpaper-Image-by-xelander_.jpg"), " item 1");
    ui->listWidget->addItem(item1);
    QListWidgetItem *item2 = new QListWidgetItem (QIcon(":/rec/o70YYg6.pngng"), " item 2");
    ui->listWidget->addItem(item2);




}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selectButton_clicked()
{
    // ui->listWidget->currentItem()->setText("Up");
    QListWidgetItem *itm = ui->listWidget->currentItem();
    itm->setText("Up");
    itm->setTextColor(Qt::blue);
    itm->setBackground(QColor(0, 0, 255, 127));
}



void MainWindow::on_removeButton_clicked()
{
    delete ui->listWidget->currentItem();
}



void MainWindow::on_addButton_clicked()
{
    ui->listWidget->addItem(ui->lineEdit->text());
}

