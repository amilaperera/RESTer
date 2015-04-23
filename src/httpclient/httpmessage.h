#ifndef HTTPMESSAGE_H
#define HTTPMESSAGE_H

#include <QObject>
#include <QList>
#include "httpheader.h"

class HTTPMessage : public QObject
{
    Q_OBJECT
public:
    explicit HTTPMessage(QObject *parent = 0);
    ~HTTPMessage();

    void AddHeader(const HTTPHeader *h);
    const QList<HTTPHeader *> *GetHeaderList() const;
    void SetBody(const QByteArray &b);
    const QByteArray *GetBody() const;

private:
    QList<HTTPHeader *> headerList;
    QByteArray body;
};

#endif // HTTPMESSAGE_H
