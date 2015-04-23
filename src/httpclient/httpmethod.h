#ifndef HTTPMETHOD_H
#define HTTPMETHOD_H

#include <QObject>
#include "httprequest.h"
#include "httpresponse.h"

// This is an Abstract Base Class,
// which works as a Strategy class
class HTTPMethod : public QObject
{
    Q_OBJECT
public:
    explicit HTTPMethod(QObject *parent = 0);
    ~HTTPMethod();

    virtual bool Execute(HTTPRequest &rqst, HTTPResponse &resp) = 0;
};

#endif // HTTPMETHOD_H
