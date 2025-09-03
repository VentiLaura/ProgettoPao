#include "ProductWidget.h"
#include "../LogicModel/Products/Console.h"
#include "../LogicModel/Products/Enums.h"
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>

ProductWidget::ProductWidget(product::Product* product, QWidget *parent): QWidget(parent), Product(product) {
      title->setText(QString::fromStdString(product->getName()));
      price->setText(QString("Prezzo: %1 €").arg(product->getPrice()));
      QPixmap i(QString::fromStdString(product->getImage()));
      image->setPixmap(i);
      QVBoxLayout *layout = new QVBoxLayout;
      layout->setAlignment(Qt::AlignTop);
      layout->addWidget(image);
      layout->addWidget(title);
      layout->addWidget(price);
      setLayout(layout);
}