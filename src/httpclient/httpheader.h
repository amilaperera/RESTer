#ifndef HTTPHEADER_H
#define HTTPHEADER_H

#include <QObject>

class HTTPHeader : public QObject
{
    Q_OBJECT
public:
    explicit HTTPHeader(QObject *parent = 0);
    ~HTTPHeader();

signals:

public slots:
};

#endif // HTTPHEADER_H
