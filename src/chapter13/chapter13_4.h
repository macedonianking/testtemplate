#ifndef CPRIMER_CHAPTER13_CHAPTER13_4_H
#define CPRIMER_CHAPTER13_CHAPTER13_4_H

#include <vector>
#include <string>

namespace chapter13 {

class Folder;

class Message {
public:
    Message(const std::string &contents = "") : mEmailContents(contents) {
    }
    Message(const Message &item);
    virtual ~Message();
    
    Message &operator=(const Message &item);
    void AddFolder(Folder &folder);
    void DelFolder(Folder &folder);

    friend class Folder;
private:
    std::vector<Folder*>::iterator FindFolder(Folder *folder);
    bool IsEmpty() const {
        return mFolderList.empty();
    }
    
private:
    std::string mEmailContents;
    std::vector<Folder*> mFolderList;
};

class Folder {
public:
    Folder(std::string &name);
    virtual ~Folder();
    
    void AddMessage(Message *message);
    void DelMessage(Message *message);

private:
    void ReleaseMessageInternal(Message *ptr);
    std::vector<Message*>::iterator FindMessage(Message *ptr);

private:
    std::string mFolderName;
    std::vector<Message*> mMessageList;

    DISALLOW_COPY_AND_ASSIGN(Folder);
};

}

#endif 