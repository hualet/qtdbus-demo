#include "server.h"

#include <QTimer>

Server::Server(QObject *parent)
    : QObject(parent)
{
    QTimer *timer = new QTimer(this);
    timer->setInterval(1000);
    timer->setSingleShot(false);
    connect(timer, &QTimer::timeout, this, &Server::Tick);
    timer->start();
}

QString Server::Hello()
{
    return "World";
}
