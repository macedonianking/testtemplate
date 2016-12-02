#include "chapter13/chapter13_4.h"

namespace chapter13 {

Message::Message(const Message &item)
: mEmailContents(item.mEmailContents),
  mFolderList(item.mFolderList) {
    for (std::vector<Folder*>::iterator iter = mFolderList.begin();
         iter != mFolderList.end(); ++iter) {
        (*iter)->AddMessage(this);
    }
}

Message::~Message() {
    std::vector<Folder*>::iterator iter;
    while (!mFolderList.empty()) {
        iter = mFolderList.begin() + (mFolderList.size() - 1);
        mFolderList.erase(iter);
        (*iter)->DelMessage(this);
    }
}

Message &Message::operator=(const Message &item) {
    if (&item == this) {
        return *this;
    }

    mEmailContents = item.mEmailContents;
    for (std::vector<Folder*>::iterator iter = mFolderList.begin();
         iter != mFolderList.end(); ++iter) {
        (*iter)->DelMessage(this);
    }
    mFolderList = item.mFolderList;
    for (std::vector<Folder*>::iterator iter = mFolderList.begin();
         iter != mFolderList.end(); ++iter) {
        (*iter)->AddMessage(this);
    }
    return *this;
}

void Message::AddFolder(Folder& folder) {
    if (FindFolder(&folder) != mFolderList.end()) {
        mFolderList.push_back(&folder);
    }
}

void Message::DelFolder(Folder &folder) {
    std::vector<Folder*>::iterator iter = FindFolder(&folder);
    if (iter != mFolderList.end()) {
        mFolderList.erase(iter);
    }
}

std::vector<Folder*>::iterator Message::FindFolder(Folder *folder) {
    for (std::vector<Folder*>::iterator iter = mFolderList.begin();
         iter != mFolderList.end(); iter++) {
        if (*iter == folder) {
            return iter;
        }
    }
    return mFolderList.end();
}

void Folder::ReleaseMessageInternal(Message *ptr) {
    ptr->DelFolder(*this);
    if (ptr->IsEmpty()) {
        delete ptr;
    }
}

Folder::~Folder() {
    std::vector<Message*>::iterator iter;

    while (!mMessageList.empty()) {
        iter = mMessageList.begin() + (mMessageList.size() - 1);
        mMessageList.erase(iter);
        ReleaseMessageInternal(*iter);    
    }
}

std::vector<Message*>::iterator Folder::FindMessage(Message *ptr) {
    std::vector<Message*>::iterator result = mMessageList.end();
    for (std::vector<Message*>::iterator iter = mMessageList.begin();
         iter != mMessageList.end();
         iter++) {
        if (*iter == ptr) {
            result = iter;
            break;
        }
    }
    return result;
}

void Folder::AddMessage(Message *ptr) {
    if (FindMessage(ptr) == mMessageList.end()) {
        mMessageList.push_back(ptr);
    }
}

void Folder::DelMessage(Message *ptr) {
    std::vector<Message*>::iterator iter = FindMessage(ptr);
    if (iter != mMessageList.end()) {
        mMessageList.erase(iter);
    }
}

}