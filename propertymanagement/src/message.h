#ifndef MESSAGE_H
#define MESSAGE_H

#include <ctime>
#include "user.h"
#include <string>

using namespace std;

class Message {
private:
    int messageId;
    time_t timedatesent;
    bool isread;
    User sender;
    User receiver;
    string message;
    string subject;
public:
    Message(User , User , time_t);
    void setMessageId(int);
    void setTimeDateSent(time_t);
    void setIsRead(bool);
    void setSender(User);
    void setReceiver(User);
    void setMessage(string);
    void setSubject(string);
    int getMessageId();
    time_t getTimeDateSent();
    bool getIsRead();
    User getSender();
    User getReceiver();
    string getMessage();
    string getSubject();

};

#endif // MESSAGE_H
