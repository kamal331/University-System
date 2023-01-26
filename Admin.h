#ifndef __ADMIN_H_
#define __ADMIN_H_

/***********************************************************************
 * \class Admin                                                        *
 * \brief A class for admin which is child class of Person.            *
 *       Admin can add, student, professor and course.                 *
 *                                                                     *
 * \param name, password, salt, id (are inherited from Person class)   *
 ***********************************************************************/

class Admin : public Person
{
public:
    Admin();
    Admin(string name, string password, uint8_t *salt,
          int id);
    void print();
};

Admin::Admin() : Person()
{
}

Admin::Admin(string name, string password, uint8_t *salt,
             int id) : Person(name, password, salt, id)
{
}

void Admin::print()
{
    cout << MAGENTA "Admin name: " RESET << this->getName() << endl;
    cout << BLUE "Admin id: " RESET << this->getId() << endl;
}

#endif