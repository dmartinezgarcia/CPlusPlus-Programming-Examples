#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>
#include <iostream>

class Person
{
    // Friends.
    friend inline std::ostream& print(std::ostream& out, const Person& data);
    friend inline std::istream& read(std::istream& in, Person& data);

public:
    // Constructors.
    //// Default constructor that initializes data members to their in-class initializers.
    inline Person() = default;
    //// Constructor with a parameter list.
    inline Person(const std::string &personName, const std::string &personAddress) : name(personName), address(personAddress) {}
    //// Constructor that just provides a name.
    inline Person(const std::string &personName) : name(personName) {}

    // Function members.
    inline const std::string &getName(void) const { return this->name; }
    inline const std::string &getAddress(void) const { return this->address; }

private:
    // Data members.
    std::string name = std::string();
    std::string address = std::string();
};

// Non member functions declarations.
inline std::ostream& print(std::ostream& out, const Person& data);
inline std::istream& read(std::istream& in, Person& data);

// Inline functions.
inline std::ostream& print(std::ostream& out, const Person& data)
{
    out << "Name: " << data.name << std::endl;
    out << "Address: " << data.address << std::endl;
    return out;
}

inline std::istream& read(std::istream& in, Person& data)
{
    in >> data.name >> data.address;
    return in;
}

#endif // __PERSON_H__
