#include "httprequest.h"

HTTPRequest::HTTPRequest()
{

}

HTTPRequest::~HTTPRequest()
{

}

void HTTPRequest::SetMethod(HTTPMethod *m)
{
    method = m;
}
