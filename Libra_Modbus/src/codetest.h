#ifndef CODETEST_H
#define CODETEST_H

#include <QObject>

class CodeTest : public QObject
{
    Q_OBJECT
public:
    explicit CodeTest(QObject *parent = 0);

signals:

public slots:
};

#endif // CODETEST_H