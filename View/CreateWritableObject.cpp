#include "CreateWritableObjectWidget.h"
CreateWritableObjectWidget::CreateWritableObjectWidget(QWidget* parent): QWidget(parent) {
}
void CreateWritableObjectWidget::createProduct(product::Product* product) {
    layout = new QVBoxLayout(this);
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
}

void CreateWritableObjectWidget::visitVideogame(product::Videogame* videogame) {
    createProduct(videogame);
    layout->addWidget(new QLabel("Producer:"));
    QLineEdit* producerEdit = new QLineEdit;
    layout->addWidget(producerEdit);

    layout->addWidget(new QLabel("Compatibility (one per row):"));
    QLineEdit* compatEdit = new QLineEdit;
    layout->addWidget(compatEdit);

    layout->addWidget(new QLabel("Genres (one per row):"));
    QLineEdit* genresEdit = new QLineEdit;
    layout->addWidget(genresEdit);
}

void visitConsole(product::Console*) {

}
void CreateWritableObjectWidget::visitTshirt(product::T_shirt* tshirt) {
    createProduct(tshirt);
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
void CreateWritableObjectWidget::visitCollectible(product::Collectible* coll) {
    createProduct(coll);
    layout->addWidget(new QLabel("Category:"));
    QLineEdit* categoryEdit = new QLineEdit;
    layout->addWidget(categoryEdit);

    layout->addWidget(new QLabel("Franchise:"));
    QLineEdit* franchiseEdit = new QLineEdit;
    layout->addWidget(franchiseEdit);

    layout->addWidget(new QLabel("Producer:"));
    QLineEdit* producerEdit = new QLineEdit;
    layout->addWidget(producerEdit);
}
void CreateWritableObjectWidget::visitConsole(product::Console* console) {
    createProduct(console);
    layout->addWidget(new QLabel("Serie:"));
    QLineEdit* serieEdit = new QLineEdit;
    layout->addWidget(serieEdit);

    layout->addWidget(new QLabel("Memory:"));
    QLineEdit* memoryEdit = new QLineEdit;
    layout->addWidget(memoryEdit);
}
void CreateWritableObjectWidget::visitAccessory(product::Accessory* acc) {
    createProduct(acc);
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
}