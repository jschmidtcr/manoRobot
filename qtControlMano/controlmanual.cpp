#include "controlmanual.h"
#include "ui_controlmanual.h"

controlManual::controlManual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::controlManual)
{
    ui->setupUi(this);
}

void controlManual::setEmisor(encargadoComunicacion *emisor)
{
    comunicador_ = emisor;
}

controlManual::~controlManual()
{
    delete ui;
}

void controlManual::on_vs_pulgar_valueChanged(int value)
{
    ui->le_pulgar->setText(QString::number(value));
    comunicador_->enviarMovimiento(encargadoComunicacion::PULGAR,value);

}

void controlManual::on_vs_indice_valueChanged(int value)
{
    ui->le_indice->setText(QString::number(value));
    comunicador_->enviarMovimiento(encargadoComunicacion::INDICE,value);

}

void controlManual::on_vs_medio_valueChanged(int value)
{
    ui->le_medio->setText(QString::number(value));
    comunicador_->enviarMovimiento(encargadoComunicacion::MEDIO,value);

}

void controlManual::on_vs_anular_valueChanged(int value)
{
    ui->le_anular->setText(QString::number(value));
    comunicador_->enviarMovimiento(encargadoComunicacion::ANULAR,value);

}

void controlManual::on_vs_menique_valueChanged(int value)
{
    ui->le_menique->setText(QString::number(value));
    comunicador_->enviarMovimiento(encargadoComunicacion::MENIQUE,value);

}
