#include "htmlhelper.h"

HtmlHelper::HtmlHelper()
{
}

QString HtmlHelper::toHtml(QString title, QTreeWidget *tree, bool printSubItems)
{
    QString html;
    html = "<table width=\"100%\" border=1 cellspacing=0>\n";

    if (title.size() > 0)
        html += QString("<tr><td colspan=") + tree->columnCount() + " align=\"center\">" + title + "</td></tr>";

    html += "<tr>";
    for (int i = 0; i < tree->columnCount(); i++)
    {
        html += "<td>" + tree->headerItem()->text(i) + "</td>";
    }
    html += "</tr>";

    for (int i = 0; i < tree->topLevelItemCount(); i++)
    {
        html += toHtml(tree->topLevelItem(i), "", "->", printSubItems);
    }
    html += "</table>";
    return html;
}

QString HtmlHelper::toHtml(QTreeWidgetItem *item, QString tab, QString separator, bool printSubItems)
{
    QString html = "<tr>";
    for (int j = 0; j < item->columnCount(); j++)
    {
        html += "<td>" + (j == 0 ? tab : "") +
                item->text(j) + "</td>";
    }
    html += "</tr>";
    if (printSubItems)
    {
        for (int k = 0; k < item->childCount(); k++)
            html += toHtml(item->child(k), tab + separator, separator, printSubItems);
    }
    return html;
}

QString HtmlHelper::toHtml(QStringList row)
{
    QString html = "<tr>";

    for (int i = 0; i < row.count(); i++)
    {
        html += "<td>" + row.at(i) + "</td>";
    }

    html += "</tr>";
    return html;
}

QString HtmlHelper::toHtml(QString title, QStringList headers, QVector<QStringList> body)
{
    QString html;
    html = "<table width=\"100%\" border=1 cellspacing=0>\n";

    if (title.size() > 0)
        html += QString("<tr><td colspan=") + headers.count() + " align=\"center\">" + title + "</td></tr>";

    html += toHtml(headers);

    for (int i = 0; i < body.count(); i++)
    {
        html += toHtml(body.at(i));
    }
    html += "</table>";
    return html;
}
