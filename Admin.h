#ifndef __ADMIN_H_
#define __ADMIN_H_

class Admin : public Person
{
public:
    Admin();
    Admin(string name, string password, uint8_t *salt,
          int id, Course *courses, int courseNums);
    void print();
};

Admin::Admin() : Person()
{
}

Admin::Admin(string name, string password, uint8_t *salt,
             int id, Course *courses, int courseNums) : Person(name, password, salt, id)
{
}

void Admin::print()
{
    cout << "Admin name: " << this->getName() << endl;
    cout << "Admin id: " << this->getId() << endl;
}

#endif