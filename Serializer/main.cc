#include <iostream>
#include <string>
#include <list>
#include <hdf5.h>   // for C style HDF5 support

// #include "Serializer.h"  // for serializer strategies

class Person
{
public:
    struct home_t
    {
    	home_t(std::string s, std::string p) : street(s), plz(p) {}
        std::string street;
        std::string plz;

        /*
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & BOOST_SERIALIZATION_NVP(street);
            ar & BOOST_SERIALIZATION_NVP(plz);
        }
         */
    };

public:
    Person() : name("Max Mustermann"), age(20), home("SomeStreet 20", "000000") {}
    Person(std::string n, int a, home_t h) : name(n), age(a), home{h} {}

        /*
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & BOOST_SERIALIZATION_NVP(name);
        ar & BOOST_SERIALIZATION_NVP(age);
        ar & BOOST_SERIALIZATION_NVP(home);
    } */

private:
    std::string name;
    int age;
    home_t home;
};

class Car
{
	Car() : id(0) {}

private:
	int id;
};

#define FILE "dset.h5"

int main()
{
    std::cout << "hello world!" << std::endl;
    
    // setup some data to be serialized
    Car test();

    std::list<std::string> strList;
    strList.push_back("Barking");
    strList.push_back("up");
    strList.push_back("the");
    strList.push_back("wrong");
    strList.push_back("tree");

    std::list<Person> personList;
    personList.push_back(Person());
    personList.push_back(Person("SomeoneElse", 22, Person::home_t("SomeOtherStreet 22", "111111")));

    /*
    Serializer<BoostXMLSerializer> ser("fileName1");
    ser.save("uuid1", strList);
    ser.save("uuid2", personList);
     */
    

    hid_t       file_id, dataset_id, dataspace_id;  /* identifiers */
    hsize_t     dims[2];
    herr_t      status;

    /* Create a new file using default properties. */
    file_id = H5Fcreate(FILE, H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);

    /* Create the data space for the dataset. */
    dims[0] = 4; 
    dims[1] = 6; 
    dataspace_id = H5Screate_simple(2, dims, NULL);

    /* Create the dataset. */
    dataset_id = H5Dcreate2(file_id, "/dset", H5T_STD_I32BE, dataspace_id, 
                           H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);

    /* End access to the dataset and release resources used by it. */
    status = H5Dclose(dataset_id);

    /* Terminate access to the data space. */ 
    status = H5Sclose(dataspace_id);

    /* Close the file. */
    status = H5Fclose(file_id);
}
