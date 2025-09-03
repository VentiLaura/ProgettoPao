#include "mainwindow.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
/*
MainWindow::MainWindow(QWidget *parent):QMainWindow(parent){
    QHBoxLayout *mainLayout = new QHBoxLayout;
        //mainLayout->addWidget(sortfilter);
        QString path="JSON/Products.json";
        std::vector<product::Product*> prova=json::JsonReader(path);
        QWidget* pcw=new PageContainerWidget(prova);
        mainLayout->addWidget(pcw);
        setLayout(mainLayout);
    
  //  QVBoxLayout *leftLayout = new QVBoxLayout;   cavare e creare file SortFilterWidget (possibiltà: creare fx che il costruttore del widget usa per creare i sottowidget e collegarli al resto)
  //  QVBoxLayout *rightLayout = new QVBoxLayout;   cavare e fare un widget di dx
}*/
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    // Crea un widget centrale
    QWidget *central = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout;

    QString path = "JSON/Products.json";
    std::vector<product::Product*> prova = json::JsonReader(path);
    QWidget* pcw = new PageContainerWidget(prova);
    mainLayout->addWidget(pcw);

    // Imposta il layout sul widget centrale
    central->setLayout(mainLayout);

    // Imposta il central widget sulla finestra principale
    setCentralWidget(central);
}

