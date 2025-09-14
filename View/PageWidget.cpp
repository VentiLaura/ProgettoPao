#include "PageWidget.h"
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
    mpw=new ModifyPageWidget;
    connect(detailsPage, &DetailsPageWidget::quitClicked, this, &PageWidget::showGrid);
    connect(detailsPage, &DetailsPageWidget::DeleteGridProduct, this, &PageWidget::DeleteProduct);
    connect(detailsPage, &DetailsPageWidget::ReturnToGrid, this, &PageWidget::eraseGrid);
    //connect(mpw, &ModifyPageWidget::cancelClicked, this, &PageWidget::eraseGrid); 
    connect(mpw, &ModifyPageWidget::cancelClicked, this, &PageWidget::showGrid);
    //connect(mpw, &ModifyPageWidget::acceptClicked, this, &PageWidget::AddProduct);
    connect(mpw, &ModifyPageWidget::acceptClicked, this, &PageWidget::Callsortfilter);
    connect(mpw, &ModifyPageWidget::acceptClicked, this, &PageWidget::eraseGrid); 
    //connect(mpw, &ModifyPageWidget::acceptClicked, this, &PageWidget::showGrid);
    //connect(mpw, &ModifyPageWidget::acceptClicked, this, &PageWidget::ReloadFilters); 
        
        
} 


/*void PageWidget::AddProduct() {
    memory::Memory& m=memory::Memory::getCentralMemoryInstance();
    currentProducts=m.getCatalog();
}*/



void PageWidget::eraseGrid() {
    qDebug()<<"dopo prima aggiunta";
    //qDebug()<<currentProducts.size();
    //currentProducts=mem.getCatalog();
    updateProducts(currentProducts);
    qDebug()<<"fuori erased grid";
}


void PageWidget::populateGrid(const std::vector<product::Product*>& products) { 
    qDebug()<<"dentro oioulategrid";
    //currentProducts.clear();
    currentProducts=products;
    qDebug()<<"dentro oioulategrid: current product size:";
    qDebug()<<currentProducts.size();
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
        return;
} 
void PageWidget::updateProducts(const std::vector<product::Product*>& products) { 
    qDebug()<<"dentro updaateproduct pagewidget";

    // Svuota il layout in modo sicuro
    QLayoutItem* item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            delete item->widget();  // Lascia che Qt gestisca la distruzione
        }
        delete item; // Libera il layout item stesso
    }
    
    Products.clear(); 
    populateGrid(products); 
} 

void PageWidget::showProductDetails(product::Product* product) {
    selected=product;
     if(scrollArea&&!scrollArea->isHidden()) {
    layout()->removeWidget(scrollArea);    // Rimuove la griglia (se presente)
    scrollArea->hide();
    }

    if(mpw&&!mpw->isHidden()) {
    layout()->removeWidget(mpw);
    mpw->hide();
    }

    detailsPage->ShowDetailsOf(product);   // Prepara la pagina dettagliata

    layout()->addWidget(detailsPage);      // Aggiunge la pagina dettagliata
    detailsPage->show();                   // Mostra visivamente
    qDebug()<<"fine updaateproduct pagewidget";
}

void PageWidget::showGrid() {
    if(detailsPage&&!detailsPage->isHidden()) {
    layout()->removeWidget(detailsPage);
    detailsPage->hide();
    }
    if(mpw&&!mpw->isHidden()) {
    layout()->removeWidget(mpw);
    mpw->hide();
    }
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

void PageWidget::callAddWindow(const QString& type) {
    if(scrollArea&&!scrollArea->isHidden()) {
    layout()->removeWidget(scrollArea);    // Rimuove la griglia (se presente)
    scrollArea->hide();
    }
    if(detailsPage&&!detailsPage->isHidden() && detailsPage) {
    layout()->removeWidget(detailsPage);
    detailsPage->hide();
    }
    if(mpw&&mpw->isVisible()) {
        layout()->removeWidget(mpw);
        delete mpw;
        mpw=new ModifyPageWidget();
    }
    mpw->CreateProduct(type);
    /*if(AddWidget) {
        delete AddWidget;
        AddWidget=nullptr;
    }
    AddWidget = new CreateWidget(type);   // Prepara la pagina dettagliata
    
    layout()->addWidget(AddWidget);      // Aggiunge la pagina dettagliata
    AddWidget->show();*/
    qDebug()<<"problema?";
    layout()->addWidget(mpw);      // Aggiunge la pagina dettagliata
    qDebug()<<"Problema?";
    mpw->show();
}