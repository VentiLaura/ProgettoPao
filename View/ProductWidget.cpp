#include "ProductWidget.h"
#include "../LogicModel/Products/Console.h"
#include "../LogicModel/Products/Enums.h"
#include "mainwindow.h"
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QApplication>
#include <QScreen>
#include <QDebug>
#include <QSizePolicy>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QSizePolicy>
#include <QFont>

ProductWidget::ProductWidget(product::Product* product, QWidget *parent)
    : QWidget(parent), Product(product) {

    // Setup image label
    QPixmap pixmap(QString::fromStdString(product->getImage()));
originalPixmap = pixmap; // salva l'originale se vuoi usarlo nel resizeEvent
image->setPixmap(pixmap);
image->setScaledContents(true); // permette alla QLabel di scalare l'immagine da sola
    image->setAlignment(Qt::AlignCenter);
    image->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Setup title label
    title->setText(QString::fromStdString(product->getName()));
    title->setAlignment(Qt::AlignCenter);
    QFont titleFont;
    titleFont.setBold(true);
    titleFont.setPointSize(10);
    title->setFont(titleFont);
    title->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);

    // Setup price label
    price->setText(QString("€%1").arg(product->getPrice(), 0, 'f', 2));
    price->setAlignment(Qt::AlignCenter);
    QFont priceFont;
    priceFont.setPointSize(9);
    price->setFont(priceFont);
    price->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);

    // Layout for widget
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(image, /*stretch=*/3);  // Give more space to image
    layout->addWidget(title, /*stretch=*/1);
    layout->addWidget(price, /*stretch=*/1);

    layout->setSpacing(5);
    layout->setContentsMargins(10, 10, 10, 10);

    setLayout(layout);

    // Ensure widget expands to fill grid cell
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setMaximumSize(300, 400);  // esempio
}