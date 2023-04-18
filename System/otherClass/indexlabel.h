#ifndef INDEXLABEL_H
#define INDEXLABEL_H

#include <QLabel>

class IndexLabel : public QLabel
{
    Q_OBJECT
public:
    bool noChange=false;

    int cardId;

    QString idStr;

public:
    IndexLabel();

    void mousePressEvent(QMouseEvent *ev);

    void enterEvent(QEvent *);

    void leaveEvent(QEvent *);

signals:
    void pass();

public slots:
};

#endif // INDEXLABEL_H
