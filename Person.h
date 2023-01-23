#ifndef __PERSON_H_
#define __PERSON_H_

class Person
{
private:
    string mName;
    string mPassword;
    uint8_t *mPSalt;
    int mId;

public:
    Person(string name, string password, uint8_t *salt, int id);
    Person();
    string getName();
    string getPassword();
    uint8_t *getSalt();
    int getId();

    void setName(string name);
    void setPassword(string password);
    void setSalt(uint8_t *salt);
    void setId(int id);

    virtual void print() = 0;
    ~Person();
};

Person::Person(string name, string password, uint8_t *salt, int id)
{
    this->mName = name;
    this->mPassword = password;
    this->mPSalt = salt;
    this->mId = id;
}

Person::Person()
{
    this->mName = "";
    this->mPassword = "";
    this->mId = 0;
}

string Person::getName()
{
    return this->mName;
}

string Person::getPassword()
{
    return this->mPassword;
}

uint8_t *Person::getSalt()
{
    return this->mPSalt;
}

int Person::getId()
{
    return this->mId;
}

void Person::setName(string name)
{
    this->mName = name;
}

void Person::setPassword(string password)
{
    this->mPassword = password;
}

void Person::setSalt(uint8_t *salt)
{
    this->mPSalt = salt;
}

void Person::setId(int id)
{
    this->mId = id;
}

Person::~Person()
{
    delete[] this->mPSalt;
}

#endif