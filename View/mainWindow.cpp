#include "mainwindow.h"

#include <QHBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent){
    qDebug() << "mainwindow";
    QHBoxLayout *mainLayout = new QHBoxLayout;
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
