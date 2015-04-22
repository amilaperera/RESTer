#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include "httpclientcontext.h"

class HTTPRequest : public HTTPClientContext
{
public:
    HTTPRequest();
    ~HTTPRequest();
};

#endif // HTTPREQUEST_H
