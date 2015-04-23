#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include "httpmessage.h"
#include "httpresponse.h"

class HTTPRequest : public HTTPMessage
{
public:
    HTTPRequest();
    ~HTTPRequest();
};

#endif // HTTPREQUEST_H
