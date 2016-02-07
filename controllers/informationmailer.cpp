#include "informationmailer.h"


void InformationMailer::send()
{
    //
    // write code
    //

    deliver("mail");
}

void InformationMailer::send(const Users &userTo, const Users &userFrom, const PrivateMessages &message)
{
    texport(userTo);
    texport(userFrom);
    texport(message);

    deliver("mail");
}

