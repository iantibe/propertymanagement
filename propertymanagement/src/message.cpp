#include "message.h"

Message::Message(User send, User  rec, time_t t): sender(send),receiver(rec){
    timedatesent = t;
    isread = false;
}

void Message::setMessageId(int id){
    this->messageId = id;
}

void Message::setTimeDateSent(time_t t){

    timedatesent = t;
}

void Message::setIsRead(bool r){
    isread = r;
}

void Message::setSender(User send){
    this->sender = send;
}

void Message::setReceiver(User rec){
    this->receiver = rec;
}

void Message::setMessage(string mess){
    this->message = mess;
}

int Message::getMessageId(){
    return messageId;
}

time_t Message::getTimeDateSent(){
    return timedatesent;
}

bool Message::getIsRead(){
    return isread;
}

User Message::getSender(){
    return sender;
}

User Message::getReceiver(){
    return receiver;
}

string Message::getMessage(){
    return message;
}

string Message::getSubject(){
    return subject;

}

void Message::setSubject(string s){
    this->subject = s;
}
