#pragma once
class Contact
{
public:
	string BeginDt;
	ContType CntType;
	string DataInfo;
	string Descr;
	string EndDt;

	Contact();
	~Contact();
	Contact Clone(Contact Cont);
private:
	string _beginDt;
	string _dataInfo;
	string _descr;
	string _endDt;

	bool operator!=(Contact Ref);
	bool operator==(Contact Ref);
};

