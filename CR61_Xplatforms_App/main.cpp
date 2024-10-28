#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "daimlerstandardsecurityalgo.h"
#include "parameterprovider_cr61_sec_18_25_01_20182620112649.h"
#include "cr61_sec_18_25_01_20182620112649.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qDebug() << "DEBUG";

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("CR61_Xplatforms_App", "Main");


    CR61_sec_18_25_01_20182620112649 seed;

    std::vector<uint8_t> inputArray = {0x01, 0x01, 0x01, 0x02, 0, 0, 0, 0};
    std::vector<uint8_t> outputArray(4);
    Parameter<int> paramOut;

    auto result = seed.GenerateKey(inputArray, 0x09, "", "", outputArray, paramOut);


    qDebug() << "KEY: " << QString::number(outputArray[0], 16) << QString::number(outputArray[1], 16) << QString::number(outputArray[2], 16) << QString::number(outputArray[3], 16);
    qDebug() << "param out " << paramOut.data;

    return app.exec();
}
