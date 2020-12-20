#pragma once
class FirmFactory
{
public:

	FirmFactory();
	~FirmFactory();
	string NameMain;

	Firm Create(string FirmName, string *fields);
	list <string> flds;
private:
};

