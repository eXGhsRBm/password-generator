
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "constants.h"

#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_letters_up->setText(LETTERS_UP);
    ui->lineEdit_letters_down->setText(LETTERS_DOWN);
    ui->lineEdit_digits->setText(DIGITS);
    ui->lineEdit_special->setText(SPECIAL);

    uint size = 99;
    ui->spinBox_number_letters_down->setMaximum(size);
    ui->spinBox_number_letters_up->setMaximum(size);
    ui->spinBox_number_digits->setMaximum(size);
    ui->spinBox_number_special->setMaximum(size);

    srand((unsigned int)time(NULL));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_reset_pressed()
{
    ui->lineEdit_letters_up->setText(LETTERS_UP);
    ui->lineEdit_letters_down->setText(LETTERS_DOWN);
    ui->lineEdit_digits->setText(DIGITS);
    ui->lineEdit_special->setText(SPECIAL);
}

uint getRandomNumber(uint min, uint max)
{
    return min + rand() % (max - min + 1);
}

void randomizer(uint size, uint count, uint *array, bool A)
{
    for (uint i = 1; i < size; i++)
    {
        while(true)
        {
            uint r = getRandomNumber(0, count);

            if (A)
            {
                array[i] = r;
                break;
            }

            bool b = false;
            for (uint j = 0; j < i; j++)
            {
                if (r == array[j]) b = true;
            }

            if (b)
            {
                continue;
            }
            else
            {
                array[i] = r;
                break;
            }
        }
    }
}

void shuffle(uint *array, uint size)
{
    QMap<uint, uint> buffer_array;
    for (uint i = 0; i < size; i++)
    {
        uint a = getRandomNumber(0, 99999);
        uint b = array[i];
        buffer_array.insert(a, b);
    }

    int i = 0;
    for (const auto &j : buffer_array.values())
    {
        array[i] = j;
        i++;
    }
    buffer_array.clear();
}

void MainWindow::on_pushButton_generation_pressed()
{
    QString buffer;

    if (ui->checkBox_letters_up->isChecked() && ui->spinBox_number_letters_up->value() > 0)
    {
        uint count = ui->lineEdit_letters_up->text().length() - 1;
        uint array_size = ui->spinBox_number_letters_up->value();

        uint random_array[array_size];
        random_array[0] = getRandomNumber(0, count);

        randomizer(array_size, count, random_array, repetition_symbols);

        QString origin = ui->lineEdit_letters_up->text();
        for (uint i = 0; i < array_size; i++)
        {
            uint j = random_array[i];
            QChar qch = origin[j];
            buffer += qch;
        }
    }

    if (ui->checkBox_letters_down->isChecked() && ui->spinBox_number_letters_down->value() > 0)
    {
        uint count = ui->lineEdit_letters_down->text().length() - 1;
        uint array_size = ui->spinBox_number_letters_down->value();

        uint random_array[array_size];
        random_array[0] = getRandomNumber(0, count);

        randomizer(array_size, count, random_array, repetition_symbols);

        QString origin = ui->lineEdit_letters_down->text();
        for (uint i = 0; i < array_size; i++)
        {
            uint j = random_array[i];
            QChar qch = origin[j];
            buffer += qch;
        }
    }

    if (ui->checkBox_digits->isChecked() && ui->spinBox_number_digits->value() > 0)
    {
        uint count = ui->lineEdit_digits->text().length() - 1;
        uint array_size = ui->spinBox_number_digits->value();

        uint random_array[array_size];
        random_array[0] = getRandomNumber(0, count);

        randomizer(array_size, count, random_array, repetition_symbols);

        QString origin = ui->lineEdit_digits->text();
        for (uint i = 0; i < array_size; i++)
        {
            uint j = random_array[i];
            QChar qch = origin[j];
            buffer += qch;
        }
    }

    if (ui->checkBox_special->isChecked() && ui->spinBox_number_special->value() > 0)
    {
        uint count = ui->lineEdit_special->text().length() - 1;
        uint array_size = ui->spinBox_number_special->value();

        uint random_array[array_size];
        random_array[0] = getRandomNumber(0, count);

        randomizer(array_size, count, random_array, repetition_symbols);

        QString origin = ui->lineEdit_special->text();
        for (uint i = 0; i < array_size; i++)
        {
            uint j = random_array[i];
            QChar qch = origin[j];
            buffer += qch;
        }
    }

    uint size = buffer.length();
    uint array[size];
    QMap<uint, QChar> char_array;
    for (uint i = 0; i < size; i++)
    {
        array[i] = i;
        char_array[i] = buffer[i];
    }

    shuffle(array, size);

    QString finish;
    for (uint i = 0; i < size; i++)
    {
        finish += char_array[array[i]];
    }
    char_array.clear();

    ui->lineEdit_generation_result->setText(finish);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    repetition_symbols = arg1;

    uint size = 99;
    if (repetition_symbols)
    {
        ui->spinBox_number_letters_down->setMaximum(size);
        ui->spinBox_number_letters_up->setMaximum(size);
        ui->spinBox_number_digits->setMaximum(size);
        ui->spinBox_number_special->setMaximum(size);
    }
    else
    {
        size = ui->lineEdit_letters_down->text().length() - 1;
        ui->spinBox_number_letters_down->setMaximum(size);

        size = ui->lineEdit_letters_up->text().length() - 1;
        ui->spinBox_number_letters_up->setMaximum(size);

        size = ui->lineEdit_digits->text().length() - 1;
        ui->spinBox_number_digits->setMaximum(size);

        size = ui->lineEdit_special->text().length() - 1;
        ui->spinBox_number_special->setMaximum(size);
    }

    size = 0;
    ui->spinBox_number_letters_down->setValue(size);
    ui->spinBox_number_letters_up->setValue(size);
    ui->spinBox_number_digits->setValue(size);
    ui->spinBox_number_special->setValue(size);
}

void MainWindow::on_lineEdit_letters_down_textChanged(const QString &arg1)
{
    uint size = arg1.length() - 1;
    ui->spinBox_number_letters_down->setMaximum(size);
}

void MainWindow::on_lineEdit_letters_up_textChanged(const QString &arg1)
{
    uint size = arg1.length() - 1;
    ui->spinBox_number_letters_up->setMaximum(size);
}

void MainWindow::on_lineEdit_digits_textChanged(const QString &arg1)
{
    uint size = arg1.length() - 1;
    ui->spinBox_number_digits->setMaximum(size);
}

void MainWindow::on_lineEdit_special_textChanged(const QString &arg1)
{
    uint size = arg1.length() - 1;
    ui->spinBox_number_special->setMaximum(size);
}
