#ifndef HTMLHELPER_H
#define HTMLHELPER_H

#include <QTreeWidget>

class HtmlHelper
{
public:
    static QString toHtml(QString title, QTreeWidget *tree, bool printSubItems);
    static QString toHtml(QTreeWidgetItem *item, QString tab, QString separator, bool printSubItems);
    static QString toHtml(QString title, QStringList headers, QVector<QStringList> body);
    static QString toHtml(QStringList row);
private:
    HtmlHelper();
};

#endif // HTMLHELPER_H
