#include "ProductWidget.h"
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>

 ProductWidget::ProductWidget(QWidget *parent): QWidget(parent) {
       QVBoxLayout *layout = new QVBoxLayout;
       layout->setAlignment(Qt::AlignTop);
       layout->addWidget(image);
       layout->addWidget(title);
       layout->addWidget(price);
        }