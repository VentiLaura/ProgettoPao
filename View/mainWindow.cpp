#include "MainWindow.h"

using namespace filterfunctions;
using namespace sortfunctions;


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    //QString Path="JSON/Products.json";
    QString Path="XML/Products.xml";  
    memory::Memory& m=memory::Memory::getCentralMemoryInstance();
    //m.Add(json::JsonReader(Path));
    //m.Add(xml::XMLReader(Path));
    m.LoadFromFile(Path);
    page = new PageWidget(m.getCatalog());
    qDebug() << m.getCatalog().size();


    qDebug() <<"dentro main window";
    QWidget* centralContainer = new QWidget(this);
    centralContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QVBoxLayout* layout = new QVBoxLayout(centralContainer);
    sortfilter->setStyleSheet("background-color: lightblue;");
    page->setStyleSheet("background-color: lightgreen;");

    
    //layout->addWidget(addButton);
    //layout->setStretch(0, 1);  // AddButton = 0
    //layout->setStretch(1, 1);  // sortfilter = 1
    //layout->setStretch(2, 8);  // page = 9


    layout->addWidget(sortfilter);
    layout->addWidget(page);

    // Imposta proporzioni: left 40%, right 60% (2:3 ratio)
    layout->setStretch(0, 1);
    layout->setStretch(1, 9);

    centralContainer->setLayout(layout);
    setCentralWidget(centralContainer);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    connect(sortfilter, &SortFilterWidget::filterModified, this, &MainWindow::updateFilter);
    connect(this, &MainWindow::productsFiltered, page, &PageWidget::updateProducts);
    connect(sortfilter, &SortFilterWidget::sortModified, this, &MainWindow::updateSort);
    connect(this, &MainWindow::productsSorted, page, &PageWidget::updateProducts);
    //connect(this, &MainWindow::CallAddWindow, sortfilter, &SortFilterWidget::AddClicked);
    connect(sortfilter, &SortFilterWidget::AddClicked, this, &MainWindow::CallAddWindow);
    //connect(this, &MainWindow::ReloadFilters, sortfilter, &SortFilterWidget::Reload);
    connect(page, &PageWidget::Callsortfilter, this, &MainWindow::Callfilter);
    connect(page, &PageWidget::Callsortfilter, this, &MainWindow::Callsort);
    
}

void MainWindow::updateFilter(const QString& selectedFilter) {
    auto Products = memory::Memory::getCentralMemoryInstance().getCatalog();
    activeFilter=selectedFilter;
    //auto Products=page->currentProducts;
    std::vector<product::Product*> filtered = applyFilter(selectedFilter, Products);
    if(!activeSort.isEmpty()) {
        applySort(activeSort, filtered);
    }
    emit productsFiltered(filtered);
}

void MainWindow::updateSort(const QString& selectedSort) {
    auto Products = memory::Memory::getCentralMemoryInstance().getCatalog();
    activeSort=selectedSort;
    //auto Products=page->currentProducts;
    std::vector<product::Product*> sorted = applySort(selectedSort, Products);
    if(!activeFilter.isEmpty()) {
        sorted=applyFilter(activeFilter, Products);
    }
    emit productsSorted(sorted);
}

void MainWindow::CallAddWindow(const QString& type) {
    page->callAddWindow(type);
}

void MainWindow::Callfilter() {
    if(!activeFilter.isEmpty())
        updateFilter(activeFilter);
}

void MainWindow::Callsort() {
    if(!activeSort.isEmpty())
        updateSort(activeSort);
}