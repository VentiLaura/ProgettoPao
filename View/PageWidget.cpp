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
    connect(mpw, &ModifyPageWidget::cancelClicked, this, &PageWidget::showGrid);
    connect(mpw, &ModifyPageWidget::acceptClicked, this, &PageWidget::Callsortfilter);
    connect(mpw, &ModifyPageWidget::acceptClicked, this, &PageWidget::eraseGrid); 
    connect(mpw, &ModifyPageWidget::acceptClicked, this, &PageWidget::showGrid);
    connect(mpw, &ModifyPageWidget::acceptClicked, this, &PageWidget::CloseAllWindows);
    connect(mpw, &ModifyPageWidget::cancelClicked, this, &PageWidget::CloseAllWindows);
} 

void PageWidget::eraseGrid() {
    updateProducts(currentProducts);
}

void PageWidget::populateGrid(const std::vector<product::Product*>& products) { 
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
        return;
} 
void PageWidget::updateProducts(const std::vector<product::Product*>& products) { 
    QLayoutItem* item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
    Products.clear(); 
    populateGrid(products); 
} 

void PageWidget::showProductDetails(product::Product* product) {
    selected=product;
     if(scrollArea&&!scrollArea->isHidden()) {
    layout()->removeWidget(scrollArea);
    scrollArea->hide();
    }
    if(mpw&&!mpw->isHidden()) {
    layout()->removeWidget(mpw);
    mpw->hide();
    }
    detailsPage->ShowDetailsOf(product);
    layout()->addWidget(detailsPage);
    detailsPage->show();
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
    auto it=currentProducts.begin();
    while((*it)->getIdProduct()!=selected->getIdProduct()) {
        it++;
    }
    currentProducts.erase(it);
}

void PageWidget::callAddWindow(const QString& type) {
    if(scrollArea&&!scrollArea->isHidden()) {
    layout()->removeWidget(scrollArea);    
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
    layout()->addWidget(mpw);
    mpw->show();
}

void PageWidget::CloseAllWindows() {
    detailsPage->DeleteAll();
}