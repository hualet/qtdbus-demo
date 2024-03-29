#ifndef SERVER_H
#define SERVER_H

#include <QObject>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);

signals:
    void Tick();

public slots:
    QString Hello();
};

#endif // SERVER_H
