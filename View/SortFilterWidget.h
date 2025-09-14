#ifndef SORTFILTERWIDGET_H
#define SORTFILTERWIDGET_H
#include "SortWidget.h"
#include "FilterWidget.h"
#include "SearchBarWidget.h"

class SortFilterWidget: public QWidget {
    Q_OBJECT
    public:
        SortFilterWidget (QWidget *parent=nullptr);
        void Reload();
    private:
        SortWidget *sort;
        FilterWidget *filter;
        QWidget *sortFilter;
        SearchBarWidget *searchbar;
        QComboBox* addComboBox;
        QStringList productTypes = {
        "Accessory",
        "Collectible",
        "Console",
        "T-shirt",
        "Videogame"
        };
    signals:
        void filterModified(const QString& text);
        void sortModified(const QString& text);
        void searchModified(const QString& text);
        void AddClicked(const QString&);

    private slots:
        void onFilterModified(const QString &text);
        void onSortModified(const QString &text);
        void onAddComboBoxChanged(int index);

};
#endif