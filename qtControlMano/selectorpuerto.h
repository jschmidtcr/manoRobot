#ifndef SELECTORPUERTO_H
#define SELECTORPUERTO_H

#include <QWidget>

namespace Ui {
class selectorPuerto;
}

class selectorPuerto : public QWidget
{
    Q_OBJECT

public:
    explicit selectorPuerto(QWidget *parent = 0);
    ~selectorPuerto();

private:
    Ui::selectorPuerto *ui;
};

#endif // SELECTORPUERTO_H
