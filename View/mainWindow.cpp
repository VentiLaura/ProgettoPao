#include "mainwindow.h"
#include <QVBoxLayout>
#include <QWidget>
#include "../Utility/FilterFunctions.h"
#include "../Utility/SortFunctions.h"

using namespace filterfunctions;
using namespace sortfunctions;


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    //QString Path="JSON/Products.json";
    QString Path="XML/Products.xml";  
    memory::Memory& m=memory::Memory::getCentralMemoryInstance();
    //m.Add(json::JsonReader(Path));
    m.Add(xml::XMLReader(Path));
    page = new PageWidget(m.getCatalog());
    qDebug() << m.getCatalog().size();


    qDebug() <<"dentro main window";
    QWidget* centralContainer = new QWidget(this);
    centralContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QVBoxLayout* layout = new QVBoxLayout(centralContainer);
    sortfilter->setStyleSheet("background-color: lightblue;");
    page->setStyleSheet("background-color: lightgreen;");

    layout->addWidget(sortfilter);
    layout->addWidget(page);

    // Imposta proporzioni: left 40%, right 60% (2:3 ratio)
    layout->setStretch(0, 1);
    layout->setStretch(1, 3);

    centralContainer->setLayout(layout);
    setCentralWidget(centralContainer);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    connect(sortfilter, &SortFilterWidget::filterModified,
        this, &MainWindow::updateFilter);
    
    connect(this, &MainWindow::productsFiltered,
        page, &PageWidget::updateProducts);

    connect(sortfilter, &SortFilterWidget::sortModified,
        this, &MainWindow::updateSort);
    
    connect(this, &MainWindow::productsSorted,
        page, &PageWidget::updateProducts);
}

void MainWindow::updateFilter(const QString& selectedFilter) {
    auto allProducts = memory::Memory::getCentralMemoryInstance().getCatalog();
    std::vector<product::Product*> filtered = applyFilter(selectedFilter, allProducts);
    emit productsFiltered(filtered);
}

void MainWindow::updateSort(const QString& selectedSort) {
    auto allProducts = memory::Memory::getCentralMemoryInstance().getCatalog();
    std::vector<product::Product*> sorted = applySort(selectedSort, allProducts);
    emit productsSorted(sorted);
}