#include "httpmessage.h"

HTTPMessage::HTTPMessage(QObject *parent) : QObject(parent)
{

}

HTTPMessage::~HTTPMessage()
{
    for(auto x : headerList)
        delete x;
}

void HTTPMessage::AddHeader(const HTTPHeader *h)
{
    headerList << const_cast<HTTPHeader *> (h);
}

const QList<HTTPHeader *> *HTTPMessage::GetHeaderList() const
{
    return &headerList;
}

void HTTPMessage::SetBody(const QByteArray &b)
{
    body = b;
}

const QByteArray *HTTPMessage::GetBody() const
{
    return &body;
}
