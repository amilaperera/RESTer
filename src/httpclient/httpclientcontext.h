#ifndef HTTPCLIENTCONTEXT_H
#define HTTPCLIENTCONTEXT_H

#include <QObject>
#include <QList>
#include "httpheader.h"

class HTTPClientContext : public QObject
{
    Q_OBJECT
public:
    explicit HTTPClientContext(QObject *parent = 0);
    ~HTTPClientContext();

    void AddHeader(const HTTPHeader *h);
    const QList<HTTPHeader *> *GetHeaderList() const;
    void SetBody(const QByteArray &b);
    const QByteArray *GetBody() const;

private:
    QList<HTTPHeader *> headerList;
    QByteArray body;
};

#endif // HTTPCLIENTCONTEXT_H
