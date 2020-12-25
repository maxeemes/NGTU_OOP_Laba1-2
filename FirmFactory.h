#pragma once
class FirmFactory
{
public:
	FirmFactory();
	~FirmFactory();

	Firm Create(
		string _name, 
		list <string> flds, 
		string _country = "������", 
		string _dateIn = "������� ����", 
		string _email = "", 
		string  _web = "", 
		string _region = "", 
		string _town = "", 
		string _street = "", 
		string _postInx = "");
private:
};

