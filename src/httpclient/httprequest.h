#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include "httpclientcontext.h"
#include "httpmethod.h"
#include "httpresponse.h"
#include "QUrl"

class HTTPRequest : public HTTPClientContext
{
public:
    HTTPRequest();
    ~HTTPRequest();
    void SetMethod(HTTPMethod *m);

private:
    HTTPMethod *method;
    QUrl url;
};

#endif // HTTPREQUEST_H
