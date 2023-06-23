#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Notepad; }
QT_END_NAMESPACE

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = nullptr);
    ~Notepad();

private slots:
    void on_quitButton_clicked();

    void on_openBTN_clicked();

    void on_salvarBTN_clicked();

private:
    Ui::Notepad *ui;
};
#endif // NOTEPAD_H
