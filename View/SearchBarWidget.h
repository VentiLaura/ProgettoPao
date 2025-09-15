#ifndef SEARCHBARWIDGET_H
#define SEARCHBARWIDGET_H
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>

class SearchBarWidget: public QWidget {
    Q_OBJECT
    private:
    QHBoxLayout* searchLayout;
    QLineEdit* searchBar;
    QPushButton* searchButton;
    public:
    SearchBarWidget(QWidget* parent = nullptr);
    void search();
    signals:
    void searchRequested(const QString& text);
};

#endif
