#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include "utils/ParseXML.h"
#include "LogWrapper.h"
#include "utils/Log.h"
#include "src/Controller/PlayBackController/PlayBackController.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    std::cout<<"application run"<<std::endl;    
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;    
    //register qml cpp class
    LogWrapper qmlLogObj;
    PlayBackController qmlPlayBackControllerObj;
    qmlRegisterSingletonInstance("LogWrapper",1,0,"LogWrapper",&qmlLogObj);
    qmlRegisterSingletonInstance("PlayBackController",1,0,"PlayBackController",&qmlPlayBackControllerObj);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
