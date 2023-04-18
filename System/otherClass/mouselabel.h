#ifndef MOUSELABEL_H
#define MOUSELABEL_H

#include <QLabel>
#include <QPixmap>
#include <QMouseEvent>
#include <QString>

class MouseLabel : public QLabel
{
    Q_OBJECT
private:
    QString img_1;
    QString img_2;
    bool imgId=true;
public:
    MouseLabel(const QString&str1,const QString&str2="");

    void mousePressEvent(QMouseEvent *ev);

signals:
    void mousePress(bool imgId);

public slots:
};

#endif // MOUSELABEL_H
