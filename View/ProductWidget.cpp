#include "ProductWidget.h"
#include "../LogicModel/Products/Console.h"
#include "../LogicModel/Products/Enums.h"
#include "mainwindow.h"
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QApplication>
#include <QScreen>
static QScreen *screen = QGuiApplication::primaryScreen();
static qreal dpi = screen->logicalDotsPerInch(); 


ProductWidget::ProductWidget(product::Product* product, QWidget *parent): QWidget(parent), Product(product) {
      title->setText(QString::fromStdString(product->getName()));
      price->setText(QString("Prezzo: %1 €").arg(product->getPrice()));
      QPixmap i(QString::fromStdString(product->getImage()));//1
      image->setPixmap(i.scaled(150, 150, Qt::KeepAspectRatio));//1

      //QPixmap i(QString::fromStdString(product->getImage()));//1
      if (i.isNull()) {
    qWarning() << "Immagine non trovata o non valida:" << QString::fromStdString(product->getImage());
}
      image->setPixmap(i);
      QVBoxLayout *layout = new QVBoxLayout;
      layout->setAlignment(Qt::AlignTop);
      layout->addWidget(image);
      layout->addWidget(title);
      layout->addWidget(price);
      setLayout(layout);
      
int WidgetWidth_cm = 4;
int WidgetHeight_cm = 5.5;
int WodgetWidth_px = dpi * (WidgetWidth_cm / 2.54);
int WidgetHeight_px = dpi * (WidgetHeight_cm / 2.54);
setFixedSize(WodgetWidth_px, WidgetHeight_px);
}