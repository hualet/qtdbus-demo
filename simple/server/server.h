#ifndef SERVER_H
#define SERVER_H

#include <QObject>

class Server : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.deepin.Ch05")
public:
    explicit Server(QObject *parent = 0);

signals:
    void Tick();

public slots:
    QString Hello();
};

#endif // SERVER_H
