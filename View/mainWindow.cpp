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
    connect(sortfilter, &SortFilterWidget::searchModified, this, &MainWindow::UpdateSearch);
    connect(this, &MainWindow::productsFiltered, page, &PageWidget::updateProducts);
    connect(sortfilter, &SortFilterWidget::sortModified, this, &MainWindow::updateSort);
    connect(this, &MainWindow::productsSorted, page, &PageWidget::updateProducts);
    connect(this, &MainWindow::productsSearched, page, &PageWidget::updateProducts);
    //connect(this, &MainWindow::CallAddWindow, sortfilter, &SortFilterWidget::AddClicked);
    connect(sortfilter, &SortFilterWidget::AddClicked, this, &MainWindow::CallAddWindow);
    //connect(this, &MainWindow::ReloadFilters, sortfilter, &SortFilterWidget::Reload);
    connect(page, &PageWidget::Callsortfilter, this, &MainWindow::Callfilter);
    connect(page, &PageWidget::Callsortfilter, this, &MainWindow::Callsort);
    connect(page, &PageWidget::Callsortfilter, this, &MainWindow::CallSearch);
    
}

void MainWindow::updateFilter(const QString& selectedFilter) {
    //auto Products = memory::Memory::getCentralMemoryInstance().getCatalog();
    activeFilter=selectedFilter;
    std::vector<product::Product*> Products=mem.getCatalog();
    //auto Products=page->currentProducts;
    qDebug()<<"Dentro updateFilter";
    qDebug()<<Products.size();
    std::vector<product::Product*> filtered = applyFilter(selectedFilter, Products);
    qDebug()<<"size prima:";
    qDebug()<<filtered.size();
    if(!activeSort.isEmpty()) {
        filtered=applySort(activeSort, filtered);
        qDebug()<<"Dentro updateFilter activeSort";
    }
    if(!activeSearch.isEmpty()) {
        filtered=SearchProduct(activeSearch, filtered);
        qDebug()<<"Dentro updateFilter activeSearch";
    }
     qDebug()<<"size:";
     qDebug()<<filtered.size();
    emit productsFiltered(filtered);
}

void MainWindow::updateSort(const QString& selectedSort) {
    //auto Products = memory::Memory::getCentralMemoryInstance().getCatalog();
    activeSort=selectedSort;
    std::vector<product::Product*> Products=mem.getCatalog();
    //auto Products=page->currentProducts;
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
    qDebug()<<"dentro UpdateSearch, dopo chiamata funzione size:";
    qDebug()<<searchedProducts.size();
    if(!activeFilter.isEmpty()) {
        searchedProducts=applyFilter(activeFilter, searchedProducts);
        qDebug()<<"filtro attivo";
    }
    if(!activeSort.isEmpty()) {
        searchedProducts=applySort(activeSort, searchedProducts);
        qDebug()<<"sort attivo";
    }
    qDebug()<<searchedProducts.size();
    emit productsSearched(searchedProducts);
    qDebug()<<"fine updatesearch";
}

std::vector<product::Product*> MainWindow::SearchProduct(const QString& searchText, const std::vector<product::Product*>& allProducts) {
    qDebug()<<"dentro SearchProduct";
    std::vector<product::Product*> filtered;
    std::string searchLower = searchText.toLower().toStdString();
    for (product::Product* p : allProducts) {
        std::string name = QString::fromStdString(p->getName()).toLower().toStdString();
        if (name.find(searchLower) != std::string::npos) {
            filtered.push_back(p);
        }
    }
    qDebug()<<"fine SearchProduct";
    return filtered;
    
    
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

void MainWindow::CallSearch() {
    if(!activeSearch.isEmpty())
        UpdateSearch(activeSearch);
}
