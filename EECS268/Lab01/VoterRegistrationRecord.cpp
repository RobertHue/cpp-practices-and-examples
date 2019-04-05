#include "VoterRegistrationRecord.h"

string VoterRegistrationRecord::getFirstName() const {
	return m_firstName;
}
string VoterRegistrationRecord::getLastName() const {
	return m_lastName;
}
int VoterRegistrationRecord::getAge() const {
	return m_age;
}
string VoterRegistrationRecord::getAffiliation() const {
	return m_affiliation;
}
