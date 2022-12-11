#ifndef URL_H
#define URL_H

#include <QString>

class Url
{
public:
    Url();
    static QString getBaseUrl();

private:
    static QString baseUrl;
};

#endif // URL_H
