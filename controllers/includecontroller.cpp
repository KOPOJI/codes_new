#include "includecontroller.h"

IncludeController::IncludeController()
{
}



const THttpRequest& IncludeController::getRequest()
{
    return httpRequest();
}

const THttpResponse& IncludeController::getResponse()
{
    return httpResponse();
}
const TSession& IncludeController::getSession()
{
    return session();
}
