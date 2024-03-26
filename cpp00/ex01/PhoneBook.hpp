#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <iomanip>
class Contact
{
private:
    int index;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string number;
    std::string darkestSecret;
public:
    void setfirstName(std::string firstName);
    void setlastName(std::string lastName);
    void setnickname(std::string nickname);
    void setnumber(std::string number);
    void setdarkestSecret(std::string darkestSecret);
    void setindex(int index);
    std::string getfirstName();
    std::string getlastName();
    std::string getnickname();
    std::string getnumber();
    std::string getdarkestSecret();
    int getindex();
};

class PhoneBook
{
private:
    int nextIndex;
    Contact contacts[8];
public:
    PhoneBook();
    void addContact(std::string firstName, std::string lastName, std::string nickname, std::string number, std::string darkestSecret);
    void displayAllContact();
    void displayOneContact(int index);
    int  displayContact();
    void setNextIndex(int nextIndex);
    int getNextIndex();
};
#endif