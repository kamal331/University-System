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

    // Admin *operator=(Admin *admin);
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

// Admin *Admin::operator=(Admin *admin)
// {
//     this->setName(admin->getName());
//     this->setPassword(admin->getPassword());
//     this->setSalt(admin->getSalt());
//     this->setId(admin->getId());
//     return this;
// }

#endif