#ifndef CONTROLMANUAL_H
#define CONTROLMANUAL_H

#include <QWidget>
#include "encargadoComunicacion.h"

namespace Ui {
class controlManual;
}

class controlManual : public QWidget
{
    Q_OBJECT
    
public:
    explicit controlManual(QWidget *parent = 0);
    void setEmisor(encargadoComunicacion* emisor);
    ~controlManual();
    
private slots:
    void on_vs_pulgar_valueChanged(int value);

    void on_vs_indice_valueChanged(int value);

    void on_vs_medio_valueChanged(int value);

    void on_vs_anular_valueChanged(int value);

    void on_vs_menique_valueChanged(int value);

private:
    Ui::controlManual *ui;
    encargadoComunicacion* comunicador_;

};

#endif // CONTROLMANUAL_H
