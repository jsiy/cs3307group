

#include <iostream>
#include "mainWindow.h"
#include <QApplication>
#include <QLabel>
#include <QFile>
/*
 *  template taken from the qt website, push example. 
 */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    
    //the style
    QFile styleSheetFile("./Adaptic.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    app.setStyleSheet(styleSheet);


    mainWindow.setWindowTitle("Controller");
    //create the size of the window to be 400 by 500 instead of 100 by 100 as that created a very small window size.
    mainWindow.resize(300,300);
    
    //I decided to use show instead of showMaximized because it was not as user friendly.
    mainWindow.show();
 
    return app.exec();
}
