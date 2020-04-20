#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include "Databaseconnection.h"
#include "message.h"
#include <vector>

class Messagehandler : private Databaseconnection {
    void sendMessage(Message);
    vector<Message> getUnreadMessages(User);
    void deleteMessage(Message);
    vector<Message> listAllMessages();
};
#endif // MESSAGEHANDLER_H
