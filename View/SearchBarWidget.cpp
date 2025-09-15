#include "SearchBarWidget.h"

SearchBarWidget::SearchBarWidget(QWidget* parent): QWidget(parent), searchBar(new QLineEdit(this)), searchButton(new QPushButton("Cerca", this)), searchLayout(new QHBoxLayout(this)) {
    searchLayout->addWidget(searchBar);
    searchLayout->addWidget(searchButton);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    setLayout(searchLayout);
    connect(searchButton, &QPushButton::clicked, this, &SearchBarWidget::search);
}

void SearchBarWidget::search() {
    emit searchRequested(searchBar->text());
}
