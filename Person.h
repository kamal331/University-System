#ifndef __PERSON_H_
#define __PERSON_H_

class Person
{
private:
    string name;
    string password;
    uint8_t *salt;
    int id;

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
    this->name = name;
    this->password = password;
    this->salt = salt;
    this->id = id;
}

Person::Person()
{
    this->name = "";
    this->password = "";
    this->id = 0;
}

string Person::getName()
{
    return this->name;
}

string Person::getPassword()
{
    return this->password;
}

uint8_t *Person::getSalt()
{
    return this->salt;
}

int Person::getId()
{
    return this->id;
}

void Person::setName(string name)
{
    this->name = name;
}

void Person::setPassword(string password)
{
    this->password = password;
}

void Person::setSalt(uint8_t *salt)
{
    this->salt = salt;
}

void Person::setId(int id)
{
    this->id = id;
}

Person::~Person()
{
    delete[] this->salt;
}

#endif