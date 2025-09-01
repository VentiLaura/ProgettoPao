#include <QApplication>
#include "View/mainwindow.cpp"

int main(int argc, char *argv[]){
    QApplication videogameLibrary(argc, argv);
/*    mainWindow window;
    window.show(); */
    return videogameLibrary.exec();
}