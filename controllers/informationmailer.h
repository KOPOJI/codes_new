#ifndef INFORMATIONMAILER_H
#define INFORMATIONMAILER_H

#include <TActionMailer>
#include "users.h"
#include "privatemessages.h"

class InformationMailer : public TActionMailer
{
public:
    InformationMailer() { }
    void send();
    void send(const Users& userTo, const Users& userFrom, const PrivateMessages &message);
};

#endif // INFORMATIONMAILER_H
