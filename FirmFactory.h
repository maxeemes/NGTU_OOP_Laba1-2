#pragma once
class FirmFactory
{
public:
	FirmFactory();
	~FirmFactory();

	Firm CreateFromMainFields(
		string _name, 
		list <string> flds, 
		string _country = "Россия", 
		string _dateIn = "Текущая дата", 
		string _email = "", 
		string  _web = "", 
		string _region = "", 
		string _town = "", 
		string _street = "", 
		string _postInx = "");
	Firm CreateFromClasses(
		Firm _firmMainInfo,
		map <string, string> _userFields,
		list <SubFirm> _sbFirms
	);
	Firm CreateFromStructuredString(string _firm);
};

