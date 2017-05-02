/* 
 * File:   HDF5_Archiver.h
 * Author: robert
 */
#ifndef SERIALIZER_H_
#define SERIALIZER_H_

#include <type_traits> // for typeid(T).name()
#include <memory> // for unique_ptr
#include <fstream> // for ostream and istream
#include <utility> // for std::forward
#include <boost/preprocessor/stringize.hpp> // for BOOST_PP_STRINGIZE(text) Macro
#include <string>
#include <map>

// boost.serialization (XML)
#include <boost/config.hpp>
#include <boost/archive/tmpdir.hpp>

// types to support for serialization
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/string.hpp>

// XML-Archives
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>

// binary-Archives
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

// binary-Archives
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

/// @brief	stores the persistent Location the specific Serializer chooses

struct Location {
    std::string fileName;
    std::string uuid;
};

/*
 * @brief   a class to serialize your c++ classes binary
 *          keeps the file with filename open as long as the Serializer object exists
 */
class BinarySerializer {
public:
 
    BinarySerializer(const std::string& filename)
    : m_filename(filename),
      m_fstr(filename, std::fstream::out | std::fstream::in | std::fstream::binary),
      m_ofstr(filename, std::fstream::out | std::fstream::binary),
      m_ifstr(filename, std::fstream::in | std::fstream::binary) 
    {
        std::cout << "construct file: " << m_filename << std::endl;
    }

    ~BinarySerializer() {
        m_fstr.close();
    }

    template< typename T >
    Location save(const std::string& uuid, const T& value) {
        Location loc = {m_filename, uuid};
        
        // make an archive and save data to it
        {
            std::cout << "uuid: " << uuid << " - fPos: " << m_ofstr.tellp() << std::endl;
            boost::archive::binary_oarchive oa(m_ofstr);
            uuid2StreamPosMap[uuid] = m_ofstr.tellp();
            oa << value;
        }
        return Location{ m_filename, uuid};
    }

    template< typename T >
    void load(const Location& loc, T& value) {
        // open the archive and load data from it
        {
            boost::archive::binary_iarchive ia(m_ifstr);
            // restore the value from the archive
            m_ifstr.seekg( uuid2StreamPosMap[loc.uuid] );
            ia >> value;
        }
    }
private:
    std::string m_filename;
    std::fstream m_fstr;
    std::ofstream m_ofstr;
    std::ifstream m_ifstr;
    std::map<std::string, std::streampos> uuid2StreamPosMap;
};

class BoostXMLSerializer {
public:

    BoostXMLSerializer(const std::string& filename) : m_filename(filename) {
    }

    ~BoostXMLSerializer() {
    }

    template< typename T >
    Location save(const std::string& uuid, const T& value) {
        // make an archive
        std::ofstream ofstr(m_filename + "_" + uuid);
        boost::archive::xml_oarchive oa(ofstr);
        oa << BOOST_SERIALIZATION_NVP(value);
        ofstr.close();

        return Location{ m_filename, uuid};
    }

    template< typename T >
    void load(const Location& loc, T& value) {
        // open the archive
        std::ifstream istr(m_filename + "_" + loc.uuid);
        boost::archive::xml_iarchive ia(istr);

        // restore the value from the archive
        ia >> BOOST_SERIALIZATION_NVP(value);
        istr.close();
    }
private:
    std::string m_filename;
};

/*
 * @class	Serializer
 * @brief	A Serializer used to create a serializer strategy which is specified as template parameter
 * @note	the strategy is set during compile-time (static polymorphism)
 * @usage	MySerializer< SerializerStrategy > serializer( fileName );
 *              Location loc = serializer.save( uuid, valueToSave );	// returns a Location
 * 		serializer.load( loc, valueToLoadTo );
 * @tparam	<Strategy>	The strategy to choose for serialization
 * 				current possiblities:	BoostXMLSerializer, ...
 */
template<typename Strategy = BoostXMLSerializer>
class Serializer {
public:
    // variadic template parameter pack to avoid enforcing any implicit interface onto the constructors of the concrete strategies
    template< typename ... _Args >
    Serializer(_Args ... args) : m_strategy(std::forward<_Args>(args)...) {
    }

    /*
     * @brief	saves the value with the Serializer Strategy
     * @param 	uuid	A uuid which identifies where to store the serialized object
     * @param	value	The value of type <T> which needs to be stored
     * @return 	Returns a Location object
     */
    template< typename T >
    Location save(const std::string& uuid, const T& value) {
        return m_strategy.save(uuid, value);
    };

    /*
     * @brief	load the value with the Serializer Strategy
     * @param 	loc	A Location which identifies where to find the serialized object
     * @param	value	The value of type <T> which the serialized Location needs to be loaded into
     */
    template< typename T >
    void load(const Location& loc, T& value) {
        m_strategy.load(loc, value);
    };
private:
    Strategy m_strategy;
};

#endif /* SERIALIZER_H_ */
