#include "MainWindow.h"

using namespace filterfunctions;
using namespace sortfunctions;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QString Path="XML/Products.xml";  
    memory::Memory& m=memory::Memory::getCentralMemoryInstance();
    m.LoadFromFile(Path);
    page = new PageWidget(m.getCatalog());
    QWidget* centralContainer = new QWidget(this);
    centralContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    MainLayout = new QVBoxLayout(centralContainer);
    sortfilter = new SortFilterWidget;
    sortfilter->setStyleSheet("background-color: lightblue;");
    page->setStyleSheet("background-color: lightgreen;");
    MainLayout->addWidget(sortfilter);
    MainLayout->addWidget(page);
    MainLayout->setStretch(0, 1);
    MainLayout->setStretch(1, 12);
    centralContainer->setLayout(MainLayout);
    setCentralWidget(centralContainer);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(sortfilter, &SortFilterWidget::filterModified, this, &MainWindow::updateFilter);
    connect(sortfilter, &SortFilterWidget::searchModified, this, &MainWindow::UpdateSearch);
    connect(this, &MainWindow::productsFiltered, page, &PageWidget::updateProducts);
    connect(sortfilter, &SortFilterWidget::sortModified, this, &MainWindow::updateSort);
    connect(this, &MainWindow::productsSorted, page, &PageWidget::updateProducts);
    connect(this, &MainWindow::productsSearched, page, &PageWidget::updateProducts);
    connect(sortfilter, &SortFilterWidget::AddClicked, this, &MainWindow::CallAddWindow);
    connect(page, &PageWidget::Callsortfilter, this, &MainWindow::Callfilter);
}

void MainWindow::updateFilter(const QString& selectedFilter) {
    activeFilter=selectedFilter;
    std::vector<product::Product*> Products=mem.getCatalog();
    std::vector<product::Product*> filtered = applyFilter(selectedFilter, Products);
    if(!activeSort.isEmpty()) {
        filtered=applySort(activeSort, filtered);
    }
    if(!activeSearch.isEmpty()) {
        filtered=SearchProduct(activeSearch, filtered);
    }
    emit productsFiltered(filtered);
}

void MainWindow::updateSort(const QString& selectedSort) {
    activeSort=selectedSort;
    std::vector<product::Product*> Products=mem.getCatalog();
    std::vector<product::Product*> sorted = applySort(selectedSort, Products);
    if(!activeFilter.isEmpty()) {
        sorted=applyFilter(activeFilter, sorted);
    }
    if(!activeSearch.isEmpty()) {
        sorted=SearchProduct(activeSearch, sorted);
    }
    emit productsSorted(sorted);
}



void MainWindow::UpdateSearch(const QString& text) {
    activeSearch=text;
    std::vector<product::Product*> Products=mem.getCatalog();
    std::vector<product::Product*> searchedProducts=SearchProduct(text, Products);
    if(!activeFilter.isEmpty()) {
        searchedProducts=applyFilter(activeFilter, searchedProducts);
    }
    if(!activeSort.isEmpty()) {
        searchedProducts=applySort(activeSort, searchedProducts);
    }
    emit productsSearched(searchedProducts);
}

std::vector<product::Product*> MainWindow::SearchProduct(const QString& searchText, const std::vector<product::Product*>& allProducts) {
    std::vector<product::Product*> filtered;
    std::string searchLower = searchText.toLower().toStdString();
    for (product::Product* p : allProducts) {
        std::string name = QString::fromStdString(p->getName()).toLower().toStdString();
        if (name.find(searchLower) != std::string::npos) {
            filtered.push_back(p);
        }
    }
    return filtered; 
}

void MainWindow::CallAddWindow(const QString& type) {
    page->callAddWindow(type);
}

void MainWindow::Callfilter() {
    if(!activeFilter.isEmpty()) {
        updateFilter(activeFilter);
    } else if(!activeSort.isEmpty()) {
        updateSort(activeSort);
    } else if((!activeSearch.isEmpty())) {
        UpdateSearch(activeSearch);
    }
}
