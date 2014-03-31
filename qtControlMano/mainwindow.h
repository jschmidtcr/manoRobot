#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "encargadocomunicacionserial.h"
#include "control_Leap.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    control_leap* control;
    Controller controller;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
