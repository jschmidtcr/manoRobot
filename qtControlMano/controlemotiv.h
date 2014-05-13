#ifndef CONTROLEMOTIV_H
#define CONTROLEMOTIV_H

#include <QWidget>
#include "encargadoComunicacion.h"

namespace Ui {
class controlEmotiv;
}

class controlEmotiv : public QWidget
{
    Q_OBJECT
    
public:
    explicit controlEmotiv(QWidget *parent = 0);
    void setEmisor(encargadoComunicacion* emisor);

    ~controlEmotiv();
    
private:
    Ui::controlEmotiv *ui;
    void keyPressEvent(QKeyEvent* keyevent);
    encargadoComunicacion* comunicador_;

};

#endif // CONTROLEMOTIV_H
