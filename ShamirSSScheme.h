#pragma once
#pragma comment(lib, "D://+info+//Libraries//NTL//Debug//NTL.LIB")

#include <NTL/ZZ.h>
#include <vector> 
 
class ShamirSSScheme 
{ 
public: 
	typedef unsigned int UInt; 
	typedef NTL::ZZ BigNumber;
	typedef std::vector<BigNumber> BigNrVec; 
public: 
	// Parameters: 
	//	n - total number of people 
	//	k - people need to discover secret 
	ShamirSSScheme(UInt n, UInt k); 
public: 
	~ShamirSSScheme(void); 
 
public: 
	// Return the secret parts 
	const BigNrVec& GetSecretParts(); 
	// The people from vPeople try to acces the secret 
	bool AccesSecret(const std::vector<UInt>& vPeople, const BigNrVec &vPeopleSecrets); 
 
private: 
	// generates the base polynom fro the scheme 
	void GeneratePolynom(); 
	// calculate the sharing parts 
	void CalculateSharingParts(); 
 
private: 
	BigNrVec m_vPolynom; // coef of base polynom 
						// polynom[0] = the secret 
	BigNrVec m_vSharingParts; // secret parts know by each people: 
 
	UInt m_nN; // total number of people which have a piece of secret 
	UInt m_nK; // nr of people need to discover the secret 
 
	BigNumber m_bnPrimeNr; // the prime number for modulo opration 
}; 