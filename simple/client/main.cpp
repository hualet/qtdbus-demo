#include <QCoreApplication>

#include <QDBusInterface>
#include <QDebug>

class Client : public QObject {
    Q_OBJECT
public:
    Client() {}

public slots:
    void handleTick() {
        qDebug() << "tick";
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDBusInterface ifce("com.deepin.ch05", "/com/deepin/ch05", "com.deepin.Ch05");
    QDBusMessage msg = ifce.call("Hello");
    QString ret = msg.arguments().at(0).toString();
    qDebug() << ret;

    Client c;
    QDBusConnection sessionBus = QDBusConnection::sessionBus();
    qDebug() << sessionBus.connect("", "", "com.deepin.Ch05", "Tick", &c, SLOT(handleTick()));

    return a.exec();
}

#include "main.moc"
