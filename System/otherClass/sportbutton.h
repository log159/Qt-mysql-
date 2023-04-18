#ifndef SPORTBUTTON_H
#define SPORTBUTTON_H

#include <QPushButton>
#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QPoint>

class SportButton : public QPushButton
{
    Q_OBJECT

private:
    QPoint initPoint;
public:
    SportButton();
    ~SportButton();

    void setInitPoint(const QPoint&p);

    //单次效果
    void moveLeftToRight(int step);

    void mousePressEvent(QMouseEvent *e);

    void enterEvent(QEvent *event);

    void leaveEvent(QEvent *event);

signals:

public slots:
};

#endif // SPORTBUTTON_H
