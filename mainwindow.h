#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_reset_pressed();

    void on_pushButton_generation_pressed();

    void on_checkBox_stateChanged(int arg1);

    void on_lineEdit_letters_down_textChanged(const QString &arg1);

    void on_lineEdit_letters_up_textChanged(const QString &arg1);

    void on_lineEdit_digits_textChanged(const QString &arg1);

    void on_lineEdit_special_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    bool repetition_symbols = false;
};
#endif // MAINWINDOW_H
