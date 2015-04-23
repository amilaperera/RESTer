#include "restexecutor.h"

RestExecutor::RestExecutor(HTTPMethod *m, QObject *parent) :
    QObject(parent), method {m}
{

}

RestExecutor::~RestExecutor()
{

}

bool RestExecutor::Execute()
{
    return method->Execute(rqst, resp);
}

