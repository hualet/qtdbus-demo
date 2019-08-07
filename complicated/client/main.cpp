#include <QCoreApplication>

#include <QDBusInterface>
#include <QDebug>

#include "ch05_interface.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    com::deepin::Ch05 client("com.deepin.ch05", "/com/deepin/ch05", QDBusConnection::sessionBus());
    QDBusPendingReply<QString> ret = client.Hello();
    ret.waitForFinished();
    qDebug() << ret.value();

    QObject::connect(&client, &com::deepin::Ch05::Tick, [] {
        qDebug() << "tick";
    });

    return a.exec();
}
