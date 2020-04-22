#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include "Databaseconnection.h"
#include "message.h"
#include <vector>

class Messagehandler : private Databaseconnection {
public:
    void sendMessage(Message &);
    vector<Message> getUnreadMessages(User &);
    void deleteMessage(Message &);
    vector<Message> listAllMessages(User &);
};
#endif // MESSAGEHANDLER_H
