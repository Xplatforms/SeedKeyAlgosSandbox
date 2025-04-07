#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "mmpc222_18_19_01_20181009031020.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("MMPC222_18_19_01_20181009031020", "Main");

    MMPC222_18_19_01_20181009031020 seed;

    std::vector<uint8_t> inputArray = {0xFF, 0xFF, 0xFF, 0xFF};
    std::vector<uint8_t> outputArray(4);
    Parameter<int> paramOut;

    auto result = seed.GenerateKey(inputArray, 0x01, "", "", outputArray, paramOut);

    qDebug() << "RESULT: " << (int)result;

    qDebug() << "KEY: " << QString::number(outputArray[0], 16) << QString::number(outputArray[1], 16) << QString::number(outputArray[2], 16) << QString::number(outputArray[3], 16);
    qDebug() << "param out " << paramOut.data;

    return app.exec();
}
