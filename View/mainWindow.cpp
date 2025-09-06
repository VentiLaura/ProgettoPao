#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    qDebug() <<"dentro main window";
    QWidget* centralContainer = new QWidget(this);
    centralContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QHBoxLayout* layout = new QHBoxLayout(centralContainer);
    leftWidget->setStyleSheet("background-color: lightblue;");
    rightWidget->setStyleSheet("background-color: lightgreen;");

    layout->addWidget(leftWidget);
    layout->addWidget(rightWidget);

    // Imposta proporzioni: left 40%, right 60% (2:3 ratio)
    layout->setStretch(0, 2);
    layout->setStretch(1, 3);

    centralContainer->setLayout(layout);
    setCentralWidget(centralContainer);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}


