#include "PageContainerWidget.h"


PageContainerWidget::PageContainerWidget(QWidget* parent): QWidget(parent), stackedLayout(new QStackedLayout) {}
PageContainerWidget::PageContainerWidget(std::vector<product::Product*> products, QWidget* parent): QWidget(parent), stackedLayout(new QStackedLayout) {
    setStyleSheet("background-color: lightgreen; border: 2px solid red;");
    int productCounter=0;
    std::vector<product::Product*> pageProducts;
    for(std::vector<product::Product*>::iterator it=products.begin(); it!=products.end(); it++) {
        if(productCounter==13) {
            productCounter=0;
            PageWidget* page=new PageWidget(pageProducts, this);
            pageProducts.clear();
            Pages.push_back(page);
            stackedLayout->addWidget(page);
        } else {
            pageProducts.push_back(*it);
        }
    }
    productCounter=0;
    if(!pageProducts.empty()) {
        PageWidget* page=new PageWidget(pageProducts, this);
        pageProducts.clear();
        Pages.push_back(page);
    }
    stackedLayout->setCurrentIndex(0);
}
int PageContainerWidget::getPageNumber() {
    return Pages.size();
}
void PageContainerWidget::AddPage(PageWidget* page) {
    Pages.push_back(page);
    stackedLayout->addWidget(page);
}
void PageContainerWidget::updateProducts(const std::vector<product::Product*>& products) {
    // Pulire le pagine precedenti:
    for (std::vector<PageWidget*>::iterator it = Pages.begin(); it != Pages.end(); ++it) {
        PageWidget* page = *it;
        stackedLayout->removeWidget(page);
        delete(page); 
    }
    Pages.clear();

    // Ricreare le pagine con i prodotti filtrati
    int productCounter = 0;
    std::vector<product::Product*> pageProducts;
    for (std::vector<product::Product*>::const_iterator it = products.begin(); it != products.end(); ++it) {
        product::Product* prod = *it;
        pageProducts.push_back(prod);
        if (++productCounter == 13) {
            auto* page = new PageWidget(pageProducts, this);
            stackedLayout->addWidget(page);
            Pages.push_back(page);
            pageProducts.clear();
            productCounter = 0;
        }
    }
    // eventuale ultima pagina
    if (!pageProducts.empty()) {
        auto* page = new PageWidget(pageProducts, this);
        stackedLayout->addWidget(page);
        Pages.push_back(page);
    }

    stackedLayout->setCurrentIndex(0);
}