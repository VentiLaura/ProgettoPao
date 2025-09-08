#include <QApplication>
#include "View/mainwindow.h"
#include "LogicModel/Products/Product.h"
int main(int argc, char *argv[]){
    qDebug() << "Avvio main";
    QApplication videogameLibrary(argc, argv);
    qDebug() << "Avvio app";
    MainWindow window;
    window.show();
    return videogameLibrary.exec();

}