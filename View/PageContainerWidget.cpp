#include "PageContainerWidget.h"


PageContainerWidget::PageContainerWidget(QWidget* parent): QWidget(parent), stackedLayout(new QStackedLayout) {}
PageContainerWidget::PageContainerWidget(std::vector<product::Product*> products, QWidget* parent): QWidget(parent), stackedLayout(new QStackedLayout) {
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