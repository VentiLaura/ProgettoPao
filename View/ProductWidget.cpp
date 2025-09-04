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


void ProductWidget::resizeEvent(QResizeEvent* event) {
      setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
      QWidget::resizeEvent(event);

      int availableWidth = title->width(); // larghezza effettiva visibile del QLabel
      QFontMetrics metrics(title->font());

      QString text = QString::fromStdString(Product->getName());
      QString elided = metrics.elidedText(text, Qt::ElideRight, availableWidth);

      title->setText(elided);
      title->setToolTip(text);
}

/*ProductWidget::ProductWidget(product::Product* product, QWidget *parent): QWidget(parent), Product(product) {
      setStyleSheet("border: 1px solid black;");
      title = new QLabel(this);
      title->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
      price = new QLabel(this);
      price->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
      image = new QLabel(this);
      QString text = QString::fromStdString(product->getName());
      title->setText(text);
      title->setToolTip(text);
      title->setWordWrap(false);  
      price->setText(QString("Prezzo: %1 €").arg(product->getPrice()));
      QPixmap i(QString::fromStdString(product->getImage()));
      if (i.isNull()) {
            qWarning() << "Immagine non trovata o non valida:" << QString::fromStdString(product->getImage());
      }
      image->setPixmap(i);      
      QVBoxLayout *layout = new QVBoxLayout;
      layout->setAlignment(Qt::AlignTop);
      image->setAlignment(Qt::AlignHCenter);
      layout->setStretch(0, 4);  // image
      layout->setStretch(1, 1);  // title
      layout->setStretch(2, 1);  // price
      layout->addWidget(image, 0, Qt::AlignHCenter);
      layout->addWidget(title);
      layout->addWidget(price);
      setLayout(layout);



}*/
ProductWidget::ProductWidget(product::Product* product, QWidget *parent): QWidget(parent), Product(product) {
      this->setStyleSheet("border: 1px solid black;");
      QScreen *screen = QGuiApplication::primaryScreen();
      qreal dpi = screen->logicalDotsPerInch();
      int WidgetWidth_cm = 5.5;
      int WidgetHeight_cm = 6;
      int WidgetWidth_px = dpi * (WidgetWidth_cm / 2.54);
      int WidgetHeight_px = dpi * (WidgetHeight_cm / 2.54);
      setFixedSize(WidgetWidth_px, WidgetHeight_px);
      int sideMargin_px = WidgetWidth_px * 0.09;
      int textAreaWidth_px = WidgetWidth_px * 0.91;
      title->setFixedWidth(textAreaWidth_px);
      price->setFixedWidth(textAreaWidth_px);
      title->setContentsMargins(sideMargin_px, 0, sideMargin_px, 0);
      price->setContentsMargins(sideMargin_px, 0, sideMargin_px, 0);
      title = new QLabel(this);
      price = new QLabel(this);
      image = new QLabel(this);
      QFontMetrics metrics(title->font());
      QString text = QString::fromStdString(product->getName());
      QString elided = metrics.elidedText(text, Qt::ElideRight, textAreaWidth_px);
      title->setText(elided);
      title->setToolTip(text);
      title->setWordWrap(false);  
      price->setText(QString("Prezzo: %1 €").arg(product->getPrice()));
      QPixmap i(QString::fromStdString(product->getImage()));
      if (i.isNull()) {
            qWarning() << "Immagine non trovata o non valida:" << QString::fromStdString(product->getImage());
      }
      image->setPixmap(i);      
      QVBoxLayout *layout = new QVBoxLayout;
      layout->setAlignment(Qt::AlignTop);
      int ImageWidth_cm=5.5;
      int ImageHeight_cm=4;
      int ImageWidth_px=dpi*(ImageWidth_cm/2.54);
      int ImageHeight_px=dpi*(ImageHeight_cm/2.54);
      QPixmap scaledImage = i.scaled(ImageWidth_px, ImageHeight_px, Qt::KeepAspectRatio, Qt::SmoothTransformation);
      image->setPixmap(scaledImage);
      image->setFixedSize(ImageWidth_px, ImageHeight_px);
      image->setAlignment(Qt::AlignHCenter);
      layout->addWidget(image, 0, Qt::AlignHCenter);
      int spacing1 = dpi * (0.2 / 2.54);
      layout->addSpacing(spacing1);
      layout->addWidget(title);
      int spacing2 = dpi * (0.2 / 2.54);
      layout->addSpacing(spacing2);
      layout->addWidget(price);
      setLayout(layout);
}