#include "url.h"

Url::Url()
{

}

QString Url::getBaseUrl()
{
    return baseUrl;
}

QString Url::baseUrl{
    "http://localhost:3000"
};
