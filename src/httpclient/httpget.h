#ifndef HTTPGET_H
#define HTTPGET_H

#include "httpmethod.h"
#include "httprequest.h"
#include "httpresponse.h"

class HTTPGet : public HTTPMethod
{
public:
    HTTPGet();
    ~HTTPGet();

    virtual bool Execute(HTTPRequest &rqst, HTTPResponse &resp) override;
};

#endif // HTTPGET_H
