#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    encargadoComunicacionSerial* a;
    a = new encargadoComunicacionSerial();
    a->enviarMovimiento(encargadoComunicacion::INDICE,1);
    control = new control_leap(a);
      // Have the sample listener receive events from the controller

      controller.addListener(*control);

}

MainWindow::~MainWindow()
{
    delete ui;
}
