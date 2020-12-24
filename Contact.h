#pragma once
using namespace std;
class ContType;
class Contact
{
public:
	string DataInfo;
	string Descr;
	ContType CntType;
	string BeginDt;
	string EndDt;

	Contact();
	Contact(string _dateInfo, string _descr = "", ContType _CntType = ContType("�������"), string _beginDt = "������� �����", string _endDate = "������� �����");
	~Contact();
	bool Clone(Contact Cont);
	bool operator!=(Contact Ref);
	bool operator==(Contact Ref);
};

