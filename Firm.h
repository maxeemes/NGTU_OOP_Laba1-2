#pragma once

class Firm
{
public:
	string Country;
	string DateIn;
	string Email;
	string Name;
	string PostInx;
	string Region;
	string Street;
	string Town;
	string Web;
	int SbFirmsCount;
	
	Firm();
	~Firm();
	bool AddField(string Name);//�������� ����
	string GetField(string Name);//������� �������� ����
	string SetField(string Name, string Value);//���������� ��������� ����
	string RenameField(string OldName, string NewName);//��������������� ����
	string GetMain();//������ �������� ����������� � �����

	//��������� ����� SubFirm
	bool AddSbFirm();
	//��������� ����� Contact
	bool AddCont();
	bool ExistContact();
	bool AddContToSbFirm();
private:
	string _conutry;
	string _dateIn;//���������� ��� ������ ��� ����
	string _email;
	string _name;
	string _postInx;
	string _region;
	string _street;
	string _town;
	string _web;
	map <string, string> _usrFields;
	SubFirm *_sbFirms;
};

