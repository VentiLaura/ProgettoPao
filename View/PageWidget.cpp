#include "PageWidget.h"
#include <QVBoxLayout>

PageWidget::PageWidget(const std::vector<product::Product*>& products, QWidget* parent)
    : QWidget(parent)
{
    scrollArea = new QScrollArea(this);
    
    scrollArea->setWidgetResizable(true);
    //scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    scrollContent = new QWidget();
    scrollContent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    gridLayout = new QGridLayout(scrollContent);
    gridLayout->setSpacing(10);
    gridLayout->setContentsMargins(10, 10, 10, 10);

    scrollContent->setLayout(gridLayout);
    scrollArea->setWidget(scrollContent);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea);
    setLayout(mainLayout);

    populateGrid(products);
    
}

void PageWidget::populateGrid(const std::vector<product::Product*>& products)
{
    const int columns = 4;

    for (int i = 0; i < static_cast<int>(products.size()); ++i) {
        int row = i / columns;
        int col = i % columns;

        ProductWidget* pw = new ProductWidget(products[i]);
        gridLayout->addWidget(pw, row, col);
    }
    scrollContent->adjustSize(); 
}