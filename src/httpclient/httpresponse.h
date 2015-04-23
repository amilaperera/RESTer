#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include "httpmessage.h"

class HTTPResponse : public HTTPMessage
{
public:
    HTTPResponse();
    ~HTTPResponse();
};

#endif // HTTPRESPONSE_H
