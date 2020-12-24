#pragma once
class Contact
{
public:
	string DataInfo;
	string Descr;
	ContType CntType;
	string BeginDt;
	string EndDt;

	Contact();
	Contact(string _dateInfo, string _descr = "", string _type = "�������", string _beginDt = "������� �����", string _endDate = "������� �����");
	~Contact();
	bool Clone(Contact Cont);
	bool operator!=(Contact Ref);
	bool operator==(Contact Ref);
};

