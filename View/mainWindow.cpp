#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include "../Utility/FilterFunctions.h"
using namespace filterfunctions;


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    qDebug() <<"dentro main window";
    QWidget* centralContainer = new QWidget(this);
    centralContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QHBoxLayout* layout = new QHBoxLayout(centralContainer);
    sortfilter->setStyleSheet("background-color: lightblue;");
    rightWidget->setStyleSheet("background-color: lightgreen;");

    layout->addWidget(sortfilter);
    layout->addWidget(rightWidget);

    // Imposta proporzioni: left 40%, right 60% (2:3 ratio)
    layout->setStretch(0, 2);
    layout->setStretch(1, 3);

    centralContainer->setLayout(layout);
    setCentralWidget(centralContainer);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    connect(sortfilter, &SortFilterWidget::filterModified,
        this, &MainWindow::updateFilter);
    
    connect(this, &MainWindow::productsFiltered,
        rightWidget, &MainRightWidget::updateProducts);
}

void MainWindow::updateFilter(const QString& selectedFilter) {
    auto allProducts = memory::Memory::getCentralMemoryInstance().getCatalog();
    std::vector<product::Product*> filtered = applyFilter(selectedFilter, allProducts);
    emit productsFiltered(filtered);
}