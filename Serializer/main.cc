#include <iostream>
#include <string>
#include <list>
#include <ostream>

#include "Serializer.h"  // for serializer strategies

class Person {
    friend std::ostream& operator<<(std::ostream& os, const Person& person);

public:

    struct home_t {
        friend std::ostream& operator<<(std::ostream& os, const home_t& h);

        home_t(std::string s, std::string p) : street(s), plz(p) {
        }
        std::string street;
        std::string plz;

        template<class Archive>
        void serialize(Archive & ar, const unsigned int version) {
            ar & BOOST_SERIALIZATION_NVP(street);
            ar & BOOST_SERIALIZATION_NVP(plz);
        }
    };

public: 

    Person() : name("Max Mustermann"), age(20), home("SomeStreet 20", "000000") {
    }
    Person(std::string n, int a, home_t h) : name(n), age(a), home{h}
    {
    }

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
        ar & BOOST_SERIALIZATION_NVP(name);
        ar & BOOST_SERIALIZATION_NVP(age);
        ar & BOOST_SERIALIZATION_NVP(home);
    }

private:
    std::string name;
    int age;
    home_t home;
};

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "\nName: " << person.name << "\nAge: " << person.age << "\t" << person.home;
    return os; // to support chaining
}

std::ostream& operator<<(std::ostream& os, const Person::home_t& h) {
    os << "\nPLZ: " << h.plz << "\nStreet: " << h.street;
    return os; // to support chaining
}

int main() {
    std::cout << "hello world!" << std::endl;

    /////////////////////////////////////////
    // setup some data to be serialized
    
    std::list<std::string> strList;
    strList.push_back("Barking");
    strList.push_back("up");
    strList.push_back("the");
    strList.push_back("wrong");
    strList.push_back("tree");

    std::list<Person> personList;
    personList.push_back(Person());
    personList.push_back(Person("SomeoneElse", 22, Person::home_t("SomeOtherStreet 22", "111111")));
    
    // std::unique_ptr<Person> personOnHeap(new Person("Bernd", 30, Person::home_t("-","-") ));     // ensures RAII principle 
    // (here: wrapper unique_ptr which owns the object and takes care of proper deletion after scope is being left)

    /////////////////////////////////////////
    // setup Serializer and call its save method
    Serializer<BinarySerializer> ser("fileName1");
    Location loc1 = ser.save("uuid1", strList);
    Location loc2 = ser.save("uuid2", personList);

    /////////////////////////////////////////
    // delete the old memory to show that its being read solely from the file
    // delete personList;
    // delete strList;
    // personOnHeap.reset();

    /////////////////////////////////////////
    // declare some variables which can hold the data from the file
    std::list<std::string> newStrList;
    std::list<Person> newPersonList;
    
    /////////////////////////////////////////
    // load the data from the file
    ser.load(loc1, newStrList);
    ser.load(loc2, newPersonList);

    /////////////////////////////////////////
    // output the data for debug purposes
    std::cout << "---------------" << std::endl;
    std::cout << "In MEM again:" << std::endl;
    std::cout << "---------------" << std::endl;
    for (auto i : newStrList)       std::cout << i << std::endl;
    std::cout << "---------------" << std::endl;
    for (auto i : newPersonList)    std::cout << i << std::endl;
    std::cout << "---------------" << std::endl;


    std::cout << "finished..." << std::endl;
}
