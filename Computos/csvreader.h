#ifndef CSVREADER_H
#define CSVREADER_H

#include <QObject>
#include <QList>
#include <QStringList>
#include <boost/shared_ptr.hpp>

class CSVReader : public QObject
{
    Q_OBJECT
public:
    explicit CSVReader(QString fileName, bool firstLineHeaders, QChar FieldSeparator, QChar FieldDelimiter, QObject *parent = 0);
    virtual ~CSVReader();

    void readCSVFile();

    boost::shared_ptr<QStringList> getHeaders();
    boost::shared_ptr<QList<QStringList> > getRecords();
    boost::shared_ptr<QList<QStringList> > getRecords(boost::shared_ptr<QStringList> filter);
    int getRecordCount() const;
    int getRecordCount(boost::shared_ptr<QStringList> filter);
    int getFieldCount() const;
    void setHeaderOnFirstRow(bool firstRow);

signals:

public slots:

private:
    QString filename;
    bool hasHeaders;
    QChar separator;
    QChar fieldDelimiter;
    QList<QStringList> records;

    QStringList tokenize(QString record, QChar delimiter);
    bool passFilter(QStringList record, boost::shared_ptr<QStringList> filter);
};

#endif // CSVREADER_H
