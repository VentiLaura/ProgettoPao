#include <QApplication>
#include "View/mainwindow.h"

int main(int argc, char *argv[]){
    QApplication videogameLibrary(argc, argv);
    MainWindow window;
    window.show(); //CHIEDERE ALLA ANGELA SE COSI VA BENE
    return videogameLibrary.exec();
}