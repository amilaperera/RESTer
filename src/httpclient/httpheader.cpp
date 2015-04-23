#include "httpheader.h"

HTTPHeader::HTTPHeader(QString n, QString v, QObject *parent) :
    QObject(parent), name {n}, value {v}
{

}

HTTPHeader::~HTTPHeader()
{

}

QString HTTPHeader::GetName()
{
    return name;
}

QString HTTPHeader::GetValue()
{
    return value;
}

