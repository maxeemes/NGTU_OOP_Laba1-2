#pragma once

class Firm
{
public:
	string Country = "������";
	string DateIn;
	string Email;
	string Name;
	string PostInx;
	string Region;
	string Street;
	string Town;
	string Web;
	list <SubFirm> SbFirms;

	Firm();
	~Firm();

	bool AddField(string Name, string Value = "");//�������� ����
	string GetField(string Name);//������� �������� ����
	bool SetField(string Name, string Value);//���������� ��������� ����
	bool RenameField(string OldName, string NewName);//��������������� ����
	string GetMain();//������ �������� ����������� � �����

	bool AddSbFirm();
	bool AddCont();
	bool ExistContact();
	bool AddContToSbFirm();
private:
	map <string, string> _usrFields;
	int _�bFirmsCount;
	
};

