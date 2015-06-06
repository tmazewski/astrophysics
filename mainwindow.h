#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "infooaplikacji.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void rysujWykresIMF();
    ~MainWindow();

private slots:
    void on_actionInformacja_o_aplikacji_triggered();
    void on_obliczIMF_button();

private:
    Ui::MainWindow *ui;
    InfoOAplikacji *info;
};

#endif // MAINWINDOW_H
