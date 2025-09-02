#include "ProductWidget.h"
#include "../LogicModel/Products/Console.h"
#include "../LogicModel/Products/Enums.h"
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>

ProductWidget::ProductWidget(product::Product* product, QWidget *parent): QWidget(parent), Product(product) {
      title->setWindowTitle(QString::fromStdString(product->getName()));
      QVBoxLayout *layout = new QVBoxLayout;
      layout->setAlignment(Qt::AlignTop);
      layout->addWidget(image);
      layout->addWidget(title);
      layout->addWidget(price);
}