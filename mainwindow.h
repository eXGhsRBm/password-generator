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

    void on_pushButton_copy_pressed();

    void on_pushButton_special_decrease_pressed();

    void on_pushButton_letters_down_decrease_pressed();

    void on_pushButton_letters_down_increase_pressed();

    void on_pushButton_letters_up_decrease_pressed();

    void on_pushButton_letters_up_increase_pressed();

    void on_pushButton_digits_decrease_pressed();

    void on_pushButton_digits_increase_pressed();

    void on_pushButton_special_increase_pressed();

private:
    Ui::MainWindow *ui;

    bool repetition_symbols = false;
};
#endif // MAINWINDOW_H
