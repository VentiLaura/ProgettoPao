#include <QApplication>
#include "View/mainwindow.h"

int main(int argc, char *argv[]){
    qDebug() << "Avvio main";
    QApplication videogameLibrary(argc, argv);
    qDebug() << "Avvio app";
    MainWindow window;
    window.show();
    window.show(); //CHIEDERE ALLA ANGELA SE COSI VA BENE
    return videogameLibrary.exec();
}