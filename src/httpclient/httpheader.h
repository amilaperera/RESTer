#ifndef HTTPHEADER_H
#define HTTPHEADER_H

#include <QObject>

class HTTPHeader : public QObject
{
    Q_OBJECT
public:
    explicit HTTPHeader(QString n, QString v, QObject *parent = 0);
    ~HTTPHeader();

    QString GetName();
    QString GetValue();

private:
    QString name;
    QString value;
};

#endif // HTTPHEADER_H
