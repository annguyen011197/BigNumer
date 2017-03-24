#pragma once
#include <bitset>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
const unsigned bitLength = 128;
class Qintnum
{
	bitset<bitLength> U;
public:
	Qintnum();
	Qintnum(string);
	Qintnum(bitset<bitLength>);
	Qintnum& Sobu2();
	bool operator[](unsigned);
	bitset<bitLength> getBitSet();
	void setBitSet(bitset<bitLength>);
	Qintnum& operator+(Qintnum&);
	Qintnum& operator-(Qintnum&);
	Qintnum& operator*(Qintnum&);
	Qintnum& operator/(Qintnum&);
	Qintnum& operator%(Qintnum&);
	Qintnum& decStringToQintnum(string&);
	string& toDecString(string&);
	Qintnum& hexStringToQintnum(string);
	string& toHexString();
	friend istream& operator>>(istream&, Qintnum&);
	friend ostream& operator<<(ostream&, Qintnum&);
	~Qintnum();
};

class exceptionQintnum : public out_of_range
{
public:
	exceptionQintnum(char* M) : out_of_range(M){};
	exceptionQintnum(string M) :out_of_range(M){};
};

