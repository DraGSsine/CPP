#include "PhoneBook.hpp"

void Contact::setfirstName(std::string firstName)
{
    this->firstName = firstName;
}
void Contact::setlastName(std::string lastName)
{
    this->lastName = lastName;
}
void Contact::setnickname(std::string nickname)
{
    this->nickname = nickname;
}
void Contact::setnumber(std::string number)
{
    this->number = number;
}
void Contact::setdarkestSecret(std::string darkestSecret)
{
    this->darkestSecret = darkestSecret;
}
void Contact::setindex(int index)
{
    this->index = index;
}
std::string Contact::getfirstName()
{
    return (firstName);
}
std::string Contact::getlastName()
{
    return (lastName);
}
std::string Contact::getnickname()
{
    return (nickname);
}
std::string Contact::getnumber()
{
    return (number);
}
std::string Contact::getdarkestSecret()
{
    return (darkestSecret);
}
int Contact::getindex()
{
    return (index);
}
PhoneBook::PhoneBook()
{
    nextIndex = 0;
}
void PhoneBook::setNextIndex(int nextIndex)
{
    if (this->nextIndex >= 7)
        this->nextIndex = 0;
    else
        this->nextIndex = nextIndex;
}
int PhoneBook::getNextIndex()
{
    return (nextIndex);
}
std::string truncate(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 10 - 4) + "...");
    return (str);
}
void PhoneBook::addContact(std::string firstName, std::string lastName, std::string nickname, std::string number, std::string darkestSecret)
{
    int Index = 0;

    Index = PhoneBook::getNextIndex();
    PhoneBook::setNextIndex(Index + 1);
    
    contacts[Index].setindex(Index);
    contacts[Index].setfirstName(firstName);
    contacts[Index].setlastName(lastName);
    contacts[Index].setnickname(nickname);
    contacts[Index].setnumber(number);
    contacts[Index].setdarkestSecret(darkestSecret);
}
void PhoneBook::displayAllContact()
{
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "| ";
    std::cout << std::setw(10) << "Index"
              << " | ";
    std::cout << std::setw(10) << "First name"
              << " | ";
    std::cout << std::setw(10) << "Last name"
              << " | ";
    std::cout << std::setw(10) << "Nickname |" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;

    for (int j = 0; j < 8; j++)
    {
        if (!contacts[j].getfirstName().empty())
        {
            std::cout << "| ";
            std::cout << std::setw(10) << contacts[j].getindex() << " | ";
            std::cout << std::setw(10) << truncate(contacts[j].getfirstName()) << " | ";
            std::cout << std::setw(10) << truncate(contacts[j].getlastName()) << " | ";
            std::cout << std::setw(10) << truncate(contacts[j].getnickname()) + "|" << std::endl;
            std::cout << "---------------------------------------------------" << std::endl;
        }
    }
    return;
}
void PhoneBook::displayOneContact(int index)
{

    if (contacts[index].getfirstName().empty())
    {
        std::cout << "Error: No contact found" << std::endl;
        return;
    }
    std::cout << "First name: " << contacts[index].getfirstName() << std::endl;
    std::cout << "Last name: " << contacts[index].getlastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getnickname() << std::endl;
    std::cout << "Number: " << contacts[index].getnumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[index].getdarkestSecret() << std::endl;
}

int PhoneBook::displayContact()
{
    PhoneBook::displayAllContact();
    std::string index;
    std::cout << "Index: ";
    std::getline(std::cin, index);
    if (index.empty() == true || index.find_first_not_of("01234567") != std::string::npos || std::stoi(index) < 0 || std::stoi(index) > 7 || std::stoi(index) == -1)
    {
        std::cout << "Error: Invalid index" << std::endl;
        return -1;
    }
    PhoneBook::displayOneContact(std::stoi(index));
    return 0;
}

int parse(std::string firstName, std::string lastName, std::string nickname, std::string number, std::string darkestSecret)
{
    if (firstName.empty() || lastName.empty() || nickname.empty() || number.empty() || darkestSecret.empty())
    {
        std::cout << "Error: All fields are required" << std::endl;
        return -1;
    }
    return 0;
}

int main()
{
    PhoneBook phoneBook;
    std::string command;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string number;
    std::string darkestSecret;

    int error = 0;
    while (std::cout << "Prompt-> " && std::getline(std::cin, command) && !std::cin.eof())
    {
        if (command == "EXIT" || command == "exit")
            return (0);
        if (command == "ADD" || command == "add")
        {
            std::cout << "First name: ";
            std::getline(std::cin, firstName);
            std::cout << "Last name: ";
            std::getline(std::cin, lastName);
            std::cout << "Nickname: ";
            std::getline(std::cin, nickname);
            std::cout << "Number: ";
            std::getline(std::cin, number);
            std::cout << "Darkest secret: ";
            std::getline(std::cin, darkestSecret);

            error = parse(firstName, lastName, nickname, number, darkestSecret);
            if (error == -1)
                continue;
            phoneBook.addContact(firstName, lastName, nickname, number, darkestSecret);
        }
        else if (command == "SEARCH" || command == "search")
        {
            error = phoneBook.displayContact();
            if (error == -1)
                continue;
        }
    }
    return 0;
}