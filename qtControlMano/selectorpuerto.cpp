#include "selectorpuerto.h"
#include "ui_selectorpuerto.h"

selectorPuerto::selectorPuerto(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectorPuerto)
{
    ui->setupUi(this);
}

selectorPuerto::~selectorPuerto()
{
    delete ui;
}
