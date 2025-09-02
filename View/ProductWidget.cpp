#include "ProductWidget.h"
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>

 ProductWidget::ProductWidget(product::Product* product, std::string ImagePath, QWidget *parent): QWidget(parent), Product(product) {
       QVBoxLayout *layout = new QVBoxLayout;
       layout->setAlignment(Qt::AlignTop);
       layout->addWidget(image);
       layout->addWidget(title);
       layout->addWidget(price);
        }