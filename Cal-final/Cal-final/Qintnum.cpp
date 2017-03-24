#include "Qintnum.h"
#include <algorithm>

Qintnum::Qintnum()
{
	U = bitset<bitLength>(0);
}

Qintnum::Qintnum(string S)
{
	*this = this->decStringToQintnum(S);
};

Qintnum::~Qintnum()
{
	U.reset();
}

Qintnum::Qintnum(bitset<bitLength> Arg)
{
	U = Arg;
}

Qintnum& Qintnum::Sobu2()
{
	bitset<bitLength> ketqua = U;
	ketqua.flip();
	for (unsigned i = 0; i<bitLength; i++)
	{
		if (ketqua[i] == false) 
		{
			ketqua[i] = true;
			break;
		}
		else
		{
			ketqua[i] = false;
		}
	}
	Qintnum* result = new Qintnum(ketqua);
	return *result;
}

bool Qintnum::operator[](unsigned index)
{
	return U[index];
}

bitset<bitLength> Qintnum::getBitSet()
{
	return U;
}

void Qintnum::setBitSet(bitset<bitLength> bitSetArg)
{
	U = bitSetArg;
}

Qintnum& Qintnum::operator+(Qintnum& B)
{
	bitset<bitLength> S;
	bool c = false;
	for (unsigned i = 0; i <bitLength; i++)
	{
		S[i] = (this->U[i] ^ B[i]) ^ c;
		c = (this->U[i] & B[i]) | (this->U[i] & c) | (B[i] & c);
	}
	Qintnum* result = new Qintnum(S);
	return *result;
}

Qintnum& Qintnum::operator-(Qintnum& B)
{
	bitset<bitLength> S;
	bool c = false;
	for (unsigned i = 0; i<bitLength; i++)
	{
		S[i] = this->U[i] ^ (B[i] ^ c);
		if ((B[i] && c) || (U[i] == false && B[i] == true) || (U[i] == false && c == true)) { c = true; }
		else c = false;
	}
	Qintnum* result = new Qintnum(S);
	return *result;
}

Qintnum& Qintnum::operator*(Qintnum& B)
{
	bool co1 = false, co2 = false;
	if (U[bitLength-1] == true) 
	{
		*this = this->Sobu2(); co1 = true;
	}
	if (B[bitLength-1] == true) 
	{
		B = B.Sobu2(); co2 = true;
	}
	Qintnum *result = new Qintnum();
	for (unsigned i = 0; i<bitLength; i++)
	{
		if (B[i] && !U[bitLength-1]) 
		{
			U <<= (i);
			*result = *result + *this;
			U >>= (i);
		}
		try
		{
			if (B[bitLength-1]) throw exceptionQintnum("out of memory");
		}
		catch (exception &e)
		{
			cout << e.what() << endl;
		}
	}
	if (co2) B = B.Sobu2();
	if (co1 ^ co2) *result = result->Sobu2();
	return *result;
}

Qintnum& Qintnum::operator/(Qintnum& B)
{
	Qintnum *result = new Qintnum();				//gia tri ket qua se tra ve, kieu Qintnum
	bitset<bitLength> bitResult;			//chuoi bitset mang gia tri ket qua
	Qintnum tempDevice = B;
	Qintnum tempDeviced = *this;

	//tao 2 bien co hieu, doi dau cac SBC va SC

	bool flagSBC = true, flagSC = true;
	if (tempDeviced[bitLength - 1]){
		tempDeviced = tempDeviced.Sobu2();
		flagSBC = false;
	}
	if (tempDevice[bitLength - 1]){
		tempDevice = tempDevice.Sobu2();
		flagSC = false;
	}

	Qintnum C = tempDeviced - tempDevice;
	int count = 0;
	while (!C[bitLength-1])			//khi so bi chia (SBC) con lon hon so chia (SC) thi shifhLeft so chia 1 bit, tang bien dem len 1
	{                               //C[bitLength-1]==true <=> SBC<SC
		tempDevice.setBitSet(tempDevice.getBitSet() <<= (1));
		C = tempDeviced - tempDevice;
		count++;
	}
	while (count != 0 || !C[bitLength-1])								//thuc hien phep chia, neu SBC < SC thi SGR SC 1 bit, count--; nguoc lai bitResult[count]=true, SBC = SBC - SC
	{
		if (C[bitLength-1]) 
		{
			tempDevice.setBitSet(tempDevice.getBitSet() >>= (1));
			count--;
		}
		else
		{
			bitResult[count] = true;
			tempDeviced = tempDeviced - tempDevice;
		}
		C = tempDeviced - tempDevice;
	} ;
	result->setBitSet(bitResult);
	if (flagSBC^flagSC) *result = result->Sobu2();
	return *result;
}

Qintnum& Qintnum::operator%(Qintnum& B)
{
	bitset<bitLength> bitResult;			//chuoi bitset mang gia tri ket qua chia
	Qintnum tempDevice = B;
	Qintnum tempDeviced = *this;

	//tao 2 bien co hieu, doi dau cac SBC va SC

	bool flagSBC = true, flagSC = true;
	if (tempDeviced[bitLength - 1]){
		tempDeviced = tempDeviced.Sobu2();
		flagSBC = false;
	}
	if (tempDevice[bitLength - 1]){
		tempDevice = tempDevice.Sobu2();
		flagSC = false;
	}
	Qintnum C = tempDeviced - tempDevice;
	int count = 0;
	while (!C[bitLength - 1])			//khi so bi chia (SBC) con lon hon so chia (SC) thi shifhLeft so chia 1 bit, tang bien dem len 1
	{                               //C[bitLength-1]==true <=> SBC<SC
		tempDevice.setBitSet(tempDevice.getBitSet() <<= (1));
		C = tempDeviced - tempDevice;
		count++;
	}
	while (count != 0 || !C[bitLength - 1])								//thuc hien phep chia, neu SBC < SC thi SGR SC 1 bit, count--; nguoc lai bitResult[count]=true, SBC = SBC - SC
	{
		if (C[bitLength - 1])
		{
			tempDevice.setBitSet(tempDevice.getBitSet() >>= (1));
			count--;
		}
		else
		{
			bitResult[count] = true;
			tempDeviced = tempDeviced - tempDevice;
		}
		C = tempDeviced - tempDevice;
	};
	if (!flagSBC) tempDeviced = tempDeviced.Sobu2();
	return *(new Qintnum(tempDeviced.getBitSet()));
}


//chuyen doi 1 chuoi so nguyen he thap phan thanh 1 day nhi phan Qintnum 

Qintnum& Qintnum::decStringToQintnum(string& Temp)					
{
	bool co = true;
	Qintnum SoMu=Qintnum(bitset<bitLength>(1000000000));
	Qintnum HeSo=Qintnum(bitset<bitLength>(1));
	Qintnum* Result=new Qintnum();
	if (Temp[0] == '-') {
		//dat co = false neu Temp la so am

		co = false; Temp.erase(Temp.begin());
	}
	while (Temp.length() >= 9)
	{
		//cat chuoi so dau vao Temp thanh cac chuoi con co do dai 9 ky tu
		//chuyen doi chuoi vua cat thanh bien TempInt
		//nhan TempInt voi HeSo va cong vao ket qua cuoi
		//sau moi vong lap HeSo=HeSo*1.000.000.000; HeSo va Result la cac bien kieu TempInt

		int TempInt = stoul(Temp.substr(Temp.length() - 9, 9));
		Qintnum Bit(bitset<bitLength>((unsigned)TempInt));
		*Result = *Result + Bit*HeSo;
		HeSo = HeSo*SoMu;
		Temp.erase(Temp.length() - 9, 9);
	}
	//sau vong lap Temp con du mot doan co do dai [0,9)
	//neu do dai nay lon hon 0
	//nhan doan nay voi HeSo va cong vao Result
	//neu co == false doi cau Result

	if (Temp.length() > 0){
		int TempInt = stoul(Temp);
		Qintnum Bit(bitset<bitLength>((unsigned)TempInt));
		*Result = *Result + Bit*HeSo;
	}
	if (!co) *Result = Result->Sobu2();
	return *Result;
}


istream& operator>>(istream& is, Qintnum& Q)
{
	string Temp;
	is >> Temp;
	try
	{
		//kiem tra tat ca cac ky tu trong Temp co phai la ky tu so va dau khong

		bool flag = all_of(Temp.begin(), Temp.end(), [](char c){return (c >= 48 & c <= 57) | c == 45; });

		//neu trong Temp co ky tu dau, ky tu dau do phai nam o vi tri dau tien
		
		size_t location = Temp.find_last_of('-');
		if (location > 0 && location!=-1) flag = false;

		// neu co hieu la sai, thong bao ra man hinh "wrong type input" va gan gia tri dang dung thanh 0

		if (!flag) throw exceptionQintnum("wrong type input");
		Q = Q.decStringToQintnum(Temp);
	}
	catch (exception& e)
	{
		Q.setBitSet(bitset<bitLength>(0));
		cout << e.what() << endl;
	}
	return is;
}

string& Qintnum::toDecString(string& s)
{
	//khoi tap co hieu bang true neu this la 1 so duong

	bool flag = true;						
	Qintnum blockUnit = Qintnum(bitset<bitLength>(1000000000));
	Qintnum blockCondition = Qintnum(bitset<bitLength>(999999999));
	Qintnum condition;
	Qintnum tempThis = *this;
	if (U[bitLength - 1]) {

		//this la so am, tempThis la so bu 2 cua this, bat co hieu thanh false

		tempThis = Sobu2(); flag = false;	
	}
	condition = tempThis - blockCondition;
	while (!condition[bitLength-1])			//neu gia tri condition > 0 thi
	{
		Qintnum thisBlock = tempThis%blockUnit;
		unsigned blockInt = thisBlock.getBitSet().to_ullong();
		s = to_string(blockInt) + s;
		tempThis = tempThis / blockUnit;
		condition = tempThis - blockCondition;
	}
	unsigned blockInt = tempThis.getBitSet().to_ullong();
	s = to_string(blockInt) + s;
	if (!flag) s = '-' + s;
	return s;
}

ostream& operator<<(ostream& os, Qintnum& Q)
{
	string ketqua;
	os << Q.toDecString(ketqua);
	return os;
}

Qintnum& Qintnum::hexStringToQintnum(string Temp)
{
	U.reset();
	for (unsigned i = Temp.length()-1; i >=0; i--)
	{
		switch (Temp[i])
		{
		case '1':
			U[i * 4] = true; break;
		case '2':
			U[i * 4 + 1] = true; break;
		case '3':
			U[i * 4 ] = true;
			U[i * 4 + 1] = true;
			break;
		case '4':
			U[i * 4 + 2] = true; break;
		case '5':
			U[i * 4 + 2] = true;
			U[i * 4] = true;
			break;
		case '6':
			U[i * 4 + 1] = true;
			U[i * 4 + 2] = true;
			break;
		case '7':
			U[i * 4 + 1] = true;
			U[i * 4 + 2] = true;
			U[i * 4] = true;
			break;
		case '8':
			U[i * 4 + 3] = true; break;
		case '9':
			U[i * 4 + 3] = true;
			U[i * 4] = true;
			break;
		case 'A':
			U[i * 4 + 3] = true;
			U[i * 4 + 1] = true;
			break;
		case 'B':
			U[i * 4 + 3] = true;
			U[i * 4 + 1] = true;
			U[i * 4] = true;
			break;
		case 'C':
			U[i * 4 + 3] = true;
			U[i * 4 + 2] = true;
			break;
		case 'D':
			U[i * 4 + 3] = true;
			U[i * 4 + 2] = true;
			U[i * 4] = true;
			break;
		case 'E':
			U[i * 4 + 3] = true;
			U[i * 4 + 2] = true;
			U[i * 4 + 1] = true;
			break;
		case 'F':
			U[i * 4 + 3] = true;
			U[i * 4 + 2] = true;
			U[i * 4 + 1] = true;
			U[i * 4] = true;
			break;
		}
	}
	return *this;
}

string& Qintnum::toHexString()
{
	string* result=new string();
	char Hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	for (unsigned i = 0; i < bitLength; i+=4)
	{
		int index = 0;
		if (U[i]) index++;
		if (U[i + 1]) index += 2;
		if (U[i + 2])index += 4;
		if (U[i + 3])index += 8;
		*result = Hex[index] + *result;
	}
	return *result;
}