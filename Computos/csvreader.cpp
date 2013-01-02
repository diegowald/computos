#include "csvreader.h"
#include <QVector>
#include <QFile>
#include <QTextStream>


CSVReader::CSVReader(QString fileName, bool firstLineHeaders, QChar FieldSeparator, QChar FieldDelimiter, QObject *parent) :
    QObject(parent), filename(fileName),
    hasHeaders(firstLineHeaders), separator(FieldSeparator), fieldDelimiter(FieldDelimiter)
{
}

CSVReader::~CSVReader()
{
    records.clear();
}

void CSVReader::readCSVFile()
{
    QFile file(filename);
    records.clear();
    if (!file.open(QIODevice::ReadOnly))
    {
        // ERROR
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        records.push_back(tokenize(line, separator));
    }
    file.close();
}

QStringList CSVReader::tokenize(QString record, QChar delimiter)
{
    QStringList tokens;
    int pos = 0;
    bool quotes = false;
    QString field = "";

    while (record[pos] != 0x00 &&
           pos < record.length())
    {
        QChar c = record[pos];
        if (!quotes && c == fieldDelimiter)
        {
            quotes = true;
        }
        else if (quotes && c == fieldDelimiter)
        {
            if (pos + 1 < record.length() &&
                    record[pos + 1] == fieldDelimiter)
            {
                field.push_back(c);
                pos++;
            }
            else
            {
                quotes = false;
            }
        }
        else if (!quotes && c == delimiter)
        {
            tokens.push_back(field);
            field.clear();
        }
        else if (!quotes && (c == 0x0A || c == 0x0D))
        {
            tokens.push_back(field);
            field.clear();
        }
        else
        {
            field.push_back(c);
        }
        pos++;
    }
    return tokens;
}

boost::shared_ptr<QStringList> CSVReader::getHeaders()
{
    if (hasHeaders)
        return boost::shared_ptr<QStringList>(new QStringList(records.at(0)));
    else
        return boost::shared_ptr<QStringList>(new QStringList());
}

boost::shared_ptr<QList<QStringList> > CSVReader::getRecords()
{
    if (hasHeaders)
    {
        boost::shared_ptr<QList<QStringList> > res(new QList<QStringList>());
        for (int i = 1; i < records.size(); i++)
        {
            res->push_back(records.at(i));
        }
        return res;
    }
    else
        return boost::shared_ptr<QList<QStringList> >(new QList<QStringList>(records));
}

bool CSVReader::passFilter(QStringList record, boost::shared_ptr<QStringList> filter)
{
    for (int i = 0; i < record.size(); i++)
    {
        if (filter->at(i) != "")
        {
            if (record.at(i) != filter->at(i))
                return false;
        }
    }
    return true;
}

boost::shared_ptr<QList<QStringList> > CSVReader::getRecords(boost::shared_ptr<QStringList> filter)
{
    bool filterEnabled = false;
    foreach (QString filterElement, *filter)
    {
        filterEnabled |= filterElement.size() > 0;
    }

    if (filterEnabled)
    {
        boost::shared_ptr<QList<QStringList> > res(new QList<QStringList>());
        for (int i = hasHeaders ? 1 : 0; i < records.size(); i++)
        {
            if (passFilter(records.at(i), filter))
                res->push_back(records.at(i));
        }
        return res;
    }
    else
        return getRecords();
}

int CSVReader::getRecordCount() const
{
    return hasHeaders ? records.count() - 1 : records.count();
}

int CSVReader::getRecordCount(boost::shared_ptr<QStringList> filter)
{
    bool filterEnabled = false;
    foreach (QString filterElement, *filter)
    {
        filterEnabled |= filterElement.size() > 0;
    }

    if (filterEnabled)
    {
        int count = 0;
        for (int i = hasHeaders ? 1 : 0; i < records.size(); i++)
        {
            if (passFilter(records.at(i), filter))
                count++;
        }
        return count;
    }
    else
        return getRecordCount();
}




int CSVReader::getFieldCount() const
{
    return records.at(0).count();
}

void CSVReader::setHeaderOnFirstRow(bool firstRow)
{
    hasHeaders = firstRow;
}
