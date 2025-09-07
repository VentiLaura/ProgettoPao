#include "ModifyPageWidget.h"
ModifyPageWidget::ModifyPageWidget(QWidget* parent): QWidget(parent) {
    pageLayout = new QVBoxLayout(this); // layout principale della pagina
    // Barra in alto con pulsante Quit
    bar=new QWidget;
    topBarLayout = new QHBoxLayout(bar);
    cancelButton = new QPushButton("Cancel");
    acceptButton=new QPushButton("Accept");
    topBarLayout->addStretch();           // spinge il pulsante a destra
    topBarLayout->addWidget(acceptButton);
    topBarLayout->addWidget(cancelButton); 
    bar->setLayout(topBarLayout);  // aggiunge il pulsante
    pageLayout->addWidget(bar, 1);  // aggiunge la barra in alto al layout principale
    setLayout(pageLayout);
    connect(cancelButton, &QPushButton::clicked, this, &ModifyPageWidget::cancelClicked);
    connect(cancelButton, &QPushButton::clicked, this, &ModifyPageWidget::DeleteDetails);
}
void ModifyPageWidget::ModifyInfoOf(product::Product* product) {
    details=new QWidget;
    QVBoxLayout* layout = new QVBoxLayout(details);

    // Etichetta generale
    layout->addWidget(new QLabel("Modify product:"));

    // Nome - disponibile per tutti i prodotti
    layout->addWidget(new QLabel("Name:"));
    QLineEdit* nameEdit = new QLineEdit;
    layout->addWidget(nameEdit);
    layout->addWidget(new QLabel("Price:"));
    QLineEdit* priceEdit = new QLineEdit;
    layout->addWidget(priceEdit);

    // Campo: ID Prodotto
    layout->addWidget(new QLabel("ID product:"));
    QLineEdit* idEdit = new QLineEdit;
    layout->addWidget(idEdit);

    // Campo: Path immagine
    layout->addWidget(new QLabel("image Path:"));
    QLineEdit* imageEdit = new QLineEdit;
    layout->addWidget(imageEdit);

    // Campo: Copie disponibili
    layout->addWidget(new QLabel("Copies Available:"));
    QLineEdit* copiesEdit = new QLineEdit;
    layout->addWidget(copiesEdit);

    // Tipo Accessory
    if (auto acc = dynamic_cast<product::Accessory*>(product)) {
        layout->addWidget(new QLabel("Height (in cm):"));
        QLineEdit* heightEdit = new QLineEdit;
        layout->addWidget(heightEdit);

        layout->addWidget(new QLabel("Lenght (in cm):"));
        QLineEdit* lengthEdit = new QLineEdit;
        layout->addWidget(lengthEdit);

        layout->addWidget(new QLabel("Depth (in cm):"));
        QLineEdit* depthEdit = new QLineEdit;
        layout->addWidget(depthEdit);

        layout->addWidget(new QLabel("Weight (in gramms):"));
        QLineEdit* weightEdit = new QLineEdit;
        layout->addWidget(weightEdit);

        layout->addWidget(new QLabel("Compatibility (one per row):"));
        QLineEdit* compatEdit = new QLineEdit;
        layout->addWidget(compatEdit);
    } else if (auto vg = dynamic_cast<product::Videogame*>(product)) {
    layout->addWidget(new QLabel("Producer:"));
    QLineEdit* producerEdit = new QLineEdit;
    layout->addWidget(producerEdit);

    layout->addWidget(new QLabel("Compatibility (one per row):"));
    QLineEdit* compatEdit = new QLineEdit;
    layout->addWidget(compatEdit);

    layout->addWidget(new QLabel("Genres (one per row):"));
    QLineEdit* genresEdit = new QLineEdit;
    layout->addWidget(genresEdit);
} else if (auto console = dynamic_cast<product::Console*>(product)) {
    layout->addWidget(new QLabel("Serie:"));
    QLineEdit* serieEdit = new QLineEdit;
    layout->addWidget(serieEdit);

    layout->addWidget(new QLabel("Memory:"));
    QLineEdit* memoryEdit = new QLineEdit;
    layout->addWidget(memoryEdit);
} else if (auto coll = dynamic_cast<product::Collectible*>(product)) {
    layout->addWidget(new QLabel("Category:"));
    QLineEdit* categoryEdit = new QLineEdit;
    layout->addWidget(categoryEdit);

    layout->addWidget(new QLabel("Franchise:"));
    QLineEdit* franchiseEdit = new QLineEdit;
    layout->addWidget(franchiseEdit);

    layout->addWidget(new QLabel("Producer:"));
    QLineEdit* producerEdit = new QLineEdit;
    layout->addWidget(producerEdit);
} else if (auto tshirt = dynamic_cast<product::T_shirt*>(product)) {
    layout->addWidget(new QLabel("Franchise:"));
    QLineEdit* franchiseEdit = new QLineEdit;
    layout->addWidget(franchiseEdit);

    layout->addWidget(new QLabel("Size:"));
    QLineEdit* sizeEdit = new QLineEdit;
    layout->addWidget(sizeEdit);

    layout->addWidget(new QLabel("Chest (cm):"));
    QLineEdit* chestEdit = new QLineEdit;
    layout->addWidget(chestEdit);

    layout->addWidget(new QLabel("Waist (cm):"));
    QLineEdit* waistEdit = new QLineEdit;
    layout->addWidget(waistEdit);

    layout->addWidget(new QLabel("Hips (cm):"));
    QLineEdit* hipsEdit = new QLineEdit;
    layout->addWidget(hipsEdit);

    layout->addWidget(new QLabel("Sleeve length (cm):"));
    QLineEdit* sleeveEdit = new QLineEdit;
    layout->addWidget(sleeveEdit);
}    
    // Imposta il layout
    details->setLayout(layout);
    pageLayout->addWidget(details, 9);
}
void ModifyPageWidget::DeleteDetails() {
    pageLayout->removeWidget(details);
    delete details;
}