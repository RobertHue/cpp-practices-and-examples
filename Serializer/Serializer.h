/* 
 * File:   HDF5_Archiver.h
 * Author: robert
 */
#ifndef SERIALIZER_H_
#define SERIALIZER_H_

#include <type_traits>	// for typeid(T).name()
#include <memory>	// for unique_ptr
#include <fstream>	// for ostream and istream
#include <utility>	// for std::forward


// boost.serialization (XML)
#include <boost/config.hpp>
#include <boost/archive/tmpdir.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/string.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <string>

// types to support for serialization
#include <boost/preprocessor/stringize.hpp>	// for BOOST_PP_STRINGIZE(text) Macro


//#include <H5Cpp.h>	// for C++ style HDF5 support
//#include <hdf5.h>	// for C style HDF5 support



/// @brief	stores the persistent Location the specific Serializer chooses
struct Location {
	std::string fileName;
	std::string uuid;
};

/*class HDF5Serializer {
public:
	HDF5Serializer(const std::string& filename) : m_fileID(0), m_status(0) {
		// To create an HDF5 file:
		// 1. Specify property lists(or use the defaults)
		// 2. Create the file
		m_fileID = H5Fcreate(
				filename.c_str(),
				H5F_ACC_TRUNC, 	// FLAGS
				// H5F_ACC_TRUNC: overwrite existing file, otherwhise if non-existant create a new file
				H5P_DEFAULT, 	// create property list
				H5P_DEFAULT		// access property list
		);
	}
	~HDF5Serializer() {
		// 3. Close the file (and property lists if needed)
		m_status = H5Fclose(m_fileID);
	}

	///  @param	uuid	uuid which is used as uuid to specify the dataset_name
	template< typename T >
	Location save(const std::string& uuid, const T& value)
	{
		// Steps to create a dataset:
		// create the dataspace
//		dims[0] = 4;
//		dims[1] = 6;
//		dataspaceID = H5Screate_simple(2, dims, NULL);

		// 1. Define the dataset characteristics
		// 2. Decide which group to attach the dataset to
		// 3. Create the dataset
//		datasetID = H5Dcreate(m_fileID, groupName, H5T_STD_I32BE, dataspaceID, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);

		// 4. Close the dataset handle from step 3


//		return m_strategy.save(uuid, value);
		return Location {"",""};
	};

	template< typename T >
	void load(const Location& loc, T& value)
	{
//		m_strategy.load(value);
	};

private:
	hid_t 	m_fileID;
	herr_t 	m_status;
};*/


class BoostXMLSerializer {
public:
	BoostXMLSerializer(const std::string& filename) : m_filename(filename) { }
	~BoostXMLSerializer() {  }

	template< typename T >
	Location save(const std::string& uuid, const T& value) {
		Location loc = { m_filename, BOOST_PP_STRINGIZE(value) };

		// make an archive
		std::ofstream ofstr(m_filename + "_" + uuid);
		boost::archive::xml_oarchive oa(ofstr);
		oa << BOOST_SERIALIZATION_NVP(value);
		ofstr.close();

		return Location { m_filename, uuid };
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
 * @note	the strategy is set during compile-time
 * @usage	MySerializer< SerializerStrategy > serializer( fileName );
 * 			Location loc = serializer.save( uuid, valueToSave );	// returns a Location
 * 			serializer.load( loc, valueToLoadTo );
 * @tparam	<Strategy>	The strategy to choose for serialization (default=HDF5Serializer)
 * 						current possiblities:	BoostXMLSerializer, HDF5Serializer
 */
template<typename Strategy = BoostXMLSerializer>
class Serializer {
public:
	template< typename ... _Args >
	Serializer(_Args ... args) : m_strategy(std::forward<_Args>(args)...) {}

	/*
	 * @brief	saves the value with the Serializer Strategy
	 * @param 	uuid	A uuid which identifies where to store the serialized object
	 * @param	value	The value of type <T> which needs to be stored
	 * @return 	Returns a Location object
	 */
	template< typename T >
	Location save(const std::string& uuid, const T& value)
	{
		return m_strategy.save(uuid, value);
	};

	/*
	 * @brief	load the value with the Serializer Strategy
	 * @param 	loc	A Location which identifies where to find the serialized object
	 * @param	value	The value of type <T> which the serialized Location needs to be loaded into
	 */
	template< typename T >
	void load(const Location& loc, T& value)
	{
		m_strategy.load(value);
	};
 private:
     Strategy m_strategy;
};



/*
 * @brief	Derive from this Interface to force implementation of an Serializable class
 */
/*
class ISerializable {
    friend class boost::serialization::access;
public:
	virtual ~ISerializable() {};
	void serialize(Archive & ar, const unsigned int version) =0;
};

#include <boost/variant.hpp>
using PolyArchive = boost::variant<
            boost::archive::polymorphic_oarchive&,
            boost::archive::polymorphic_iarchive&
        >;

struct ISerializable {
    virtual void serialize(PolyArchive, unsigned) = 0;
};
*/

#endif /* SERIALIZER_H_ */
