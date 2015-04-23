#include "httpclientcontext.h"

HTTPClientContext::HTTPClientContext(QObject *parent) : QObject(parent)
{

}

HTTPClientContext::~HTTPClientContext()
{
    for(auto x : headerList)
        delete x;
}

void HTTPClientContext::AddHeader(const HTTPHeader *h)
{
    headerList << const_cast<HTTPHeader *> (h);
}

const QList<HTTPHeader *> *HTTPClientContext::GetHeaderList() const
{
    return &headerList;
}

void HTTPClientContext::SetBody(const QByteArray &b)
{
    body = b;
}

const QByteArray *HTTPClientContext::GetBody() const
{
    return &body;
}
