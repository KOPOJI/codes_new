#ifndef INCLUDECONTROLLER_H
#define INCLUDECONTROLLER_H

#include <TActionController>

class IncludeController : public TActionController
{
public:
    IncludeController();

    const THttpRequest &getRequest();

    const THttpResponse &getResponse();

    const TSession &getSession();
};

#endif // INCLUDECONTROLLER_H
