#include "PageWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>
PageWidget::PageWidget(const std::vector<product::Product*>& products, QWidget* parent) : QWidget(parent) {
     scrollArea = new QScrollArea(this); 
     scrollArea->setWidgetResizable(true);
       scrollContent = new QWidget(); 
       scrollContent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum); 
       gridLayout = new QGridLayout(scrollContent); 
       gridLayout->setSpacing(10); 
       gridLayout->setContentsMargins(10, 10, 10, 10); 
       scrollContent->setLayout(gridLayout);
        scrollArea->setWidget(scrollContent); 
        mainLayout = new QVBoxLayout(this); 
        mainLayout->addWidget(scrollArea); 
        setLayout(mainLayout);
        populateGrid(products); 
        detailsPage=new DetailsPageWidget;
        connect(detailsPage, &DetailsPageWidget::quitClicked, this, &PageWidget::showGrid);
        connect(detailsPage, &DetailsPageWidget::DeleteGridProduct, this, &PageWidget::DeleteProduct);
        connect(detailsPage, &DetailsPageWidget::ReturnToGrid, this, &PageWidget::eraseGrid);
        
        
} 

void PageWidget::eraseGrid() {
    qDebug()<<currentProducts.size();
    updateProducts(currentProducts);
}


void PageWidget::populateGrid(const std::vector<product::Product*>& products) { 
    qDebug()<<"dentro oioulategrid";
    currentProducts=products;
    const int columns = 4; 
    for (int i = 0; i < static_cast<int>(products.size()); ++i) {
            int row = i / columns; 
            int col = i % columns; 
            ProductWidget* pw = new ProductWidget(products[i]); 
            gridLayout->addWidget(pw, row, col); 
            Products.push_back(pw); 
            connect(pw, &ProductWidget::clicked, this, &PageWidget::showProductDetails); 
        } 
        scrollContent->adjustSize(); 
        qDebug()<<"fuori oioulategrid";
} 
void PageWidget::updateProducts(const std::vector<product::Product*>& products) { 
    for(int i=0; i < static_cast<int>(Products.size()); ++i) { 
        delete Products[i]; 
    } 
    Products.clear(); 
    populateGrid(products); 
} 
void PageWidget::showProductDetails(product::Product* product) {
    selected=product;
    layout()->removeWidget(scrollArea);    // Rimuove la griglia (se presente)
    scrollArea->hide();

    detailsPage->ShowDetailsOf(product);   // Prepara la pagina dettagliata

    layout()->addWidget(detailsPage);      // Aggiunge la pagina dettagliata
    detailsPage->show();                   // Mostra visivamente
}

void PageWidget::showGrid() {
    layout()->removeWidget(detailsPage);
    detailsPage->hide();
    layout()->addWidget(scrollArea);
    scrollArea->show();
}

void PageWidget::DeleteProduct() {
    qDebug()<<"dentro delete pr";
    auto it=currentProducts.begin();
    while((*it)->getIdProduct()!=selected->getIdProduct()) {
        it++;
    }
    currentProducts.erase(it);
    qDebug()<<"fine delete pr";
}