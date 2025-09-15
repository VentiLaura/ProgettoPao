#include "ProductWidget.h"

ProductWidget::ProductWidget(product::Product* product, QWidget *parent): QWidget(parent), p(product) {
    image = new QLabel(this);
    title = new QLabel(this);
    price = new QLabel(this);

    QPixmap pixmap(QString::fromStdString(product->getImage()));
    image->setPixmap(pixmap);
    image->setScaledContents(true);
    image->setAlignment(Qt::AlignCenter);
    image->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    title->setText(QString::fromStdString(product->getName()));
    title->setAlignment(Qt::AlignCenter);
    QFont titleFont;
    titleFont.setBold(true);
    titleFont.setPointSize(10);
    title->setFont(titleFont);
    title->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);

    price->setText(QString("€%1").arg(product->getPrice(), 0, 'f', 2));
    price->setAlignment(Qt::AlignCenter);
    QFont priceFont;
    priceFont.setPointSize(9);
    price->setFont(priceFont);
    price->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(image, 3);
    layout->addWidget(title, 1);
    layout->addWidget(price, 1);
    layout->setSpacing(5);
    layout->setContentsMargins(10, 10, 10, 10);
    setLayout(layout);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    setMaximumSize(250, 350);
}

void ProductWidget::mousePressEvent(QMouseEvent* event) {
    emit clicked(p);
    QWidget::mousePressEvent(event);
}
