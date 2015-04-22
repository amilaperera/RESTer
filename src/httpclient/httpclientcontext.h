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

signals:

public slots:
};

#endif // HTTPCLIENTCONTEXT_H
