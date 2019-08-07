#include "server.h"
#include "ch05_adaptor.h"

#include <QCoreApplication>
#include <QDBusConnection>
#include <QDebug>
#include <QDBusError>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server s;
    QDBusConnection sb = QDBusConnection::sessionBus();

    Ch05Adaptor adp(&s);
    Q_UNUSED(adp);

    bool result;
    result = sb.registerService("com.deepin.ch05");
    if (!result) {
        qWarning() << "failed to register dbus service" << sb.lastError().message();
    }

    result = sb.registerObject("/com/deepin/ch05",
                               "com.deepin.Ch05", &s,
                               QDBusConnection::ExportAdaptors);
    if (!result) {
        qWarning() << "failed to register dbus object" << sb.lastError().message();
    }

    return a.exec();
}
