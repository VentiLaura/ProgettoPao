#include "mainwindow.h"
#include <QHBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent){
    qDebug() << "mainwindow";
    QHBoxLayout *mainLayout = new QHBoxLayout;
<<<<<<< HEAD
      QWidget *central = new QWidget(this);
      mainLayout->addWidget(sortfilter);
      mainLayout->addWidget(rightWidget);
      central->setLayout(mainLayout);
      setCentralWidget(central);
     // connect(filter, &FilterWidget::FilterChanged, this, &MainWindow::onFilterChanged);

      //  QVBoxLayout *leftLayout = new QVBoxLayout;   cavare e creare file SortFilterWidget (possibiltà: creare fx che il costruttore del widget usa per creare i sottowidget e collegarli al resto)
}
void MainWindow::updateFilter(const QString &filtro) {
    qDebug() << "Filtro selezionato in MainWindow:" << filtro;
}
=======
        //mainLayout->addWidget(sortfilter);
        QString path="JSON/Products.json";
        std::vector<product::Product*> prova=json::JsonReader(path);
        QWidget* pcw=new PageContainerWidget(prova);
        mainLayout->addWidget(pcw);
        setLayout(mainLayout);
    
  //  QVBoxLayout *leftLayout = new QVBoxLayout;   cavare e creare file SortFilterWidget (possibiltà: creare fx che il costruttore del widget usa per creare i sottowidget e collegarli al resto)
  //  QVBoxLayout *rightLayout = new QVBoxLayout;   cavare e fare un widget di dx
}*/


/*MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    // Crea un widget centrale
    //1QWidget *central = new QWidget(this);
    //1QHBoxLayout *mainLayout = new QHBoxLayout;

    QString path = "JSON/Products.json";
    std::vector<product::Product*> prova = json::JsonReader(path);
    QWidget* pcw = new PageContainerWidget(prova);
    //1mainLayout->addWidget(pcw);

    // Imposta il layout sul widget centrale
    //1central->setLayout(mainLayout);

    // Imposta il central widget sulla finestra principale
    //1setCentralWidget(central);
    setCentralWidget(pcw);
}*/ //2
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    qDebug() <<"dentro main window";
    QWidget* centralContainer = new QWidget(this);
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
}


>>>>>>> 7bf26185ac194c13ee6d52153b10ebf9213ff26b
