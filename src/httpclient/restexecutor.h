#ifndef RESTEXECUTOR_H
#define RESTEXECUTOR_H

#include <QObject>
#include "httprequest.h"
#include "httpresponse.h"
#include "httpmethod.h"

class RestExecutor : public QObject
{
    Q_OBJECT
public:
    explicit RestExecutor(HTTPMethod *m, QObject *parent = 0);
    ~RestExecutor();
    bool Execute();

private:
    HTTPRequest rqst;
    HTTPResponse resp;
    HTTPMethod *method;
};

#endif // RESTEXECUTOR_H
