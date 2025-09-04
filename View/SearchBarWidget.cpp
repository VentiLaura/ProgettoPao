#include "SearchBarWidget.h"
SearchBarWidget::SearchBarWidget(QWidget* parent): QWidget(parent), searchBar(new QLineEdit(this)), searchLayout(new QHBoxLayout(this)) {
searchLayout->addWidget(searchBar);
setLayout(searchLayout);
}