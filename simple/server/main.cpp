#include <QCoreApplication>

#include <QDBusConnection>
#include <QDebug>
#include <QDBusError>

#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server s;
    QDBusConnection sb = QDBusConnection::sessionBus();

    bool result;
    result = sb.registerService("com.deepin.ch05");
    if (!result) {
        qWarning() << "failed to register dbus service" << sb.lastError().message();
    }

    QDBusConnection::RegisterOptions options = QDBusConnection::ExportAllSlots \
                                              | QDBusConnection::ExportAllSignals;
    result = sb.registerObject("/com/deepin/ch05",
                               "com.deepin.Ch05", &s,
                               options);
    if (!result) {
        qWarning() << "failed to register dbus object" << sb.lastError().message();
    }

    return a.exec();
}
