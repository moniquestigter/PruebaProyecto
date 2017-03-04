#ifndef RIGHTCLICK_H
#define RIGHTCLICK_H

#include <QPushButton>
#include <QMouseEvent>


class rightClick: public QPushButton
{
public:
    explicit rightClick(QWidget *parent = 0);

private slots:
    void mousePressEvent(QMouseEvent *e);

signals:
    void rightClicked();

};

#endif // RIGHTCLICK_H
