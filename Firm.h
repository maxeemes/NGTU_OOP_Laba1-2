#pragma once

class Firm
{
public:
	string Name;
	string Email;
	string Web;
	string Region;
	string Town;
	string Street;
	string PostInx;
	string Country;
	string DateIn;
	list <SubFirm> SbFirms;

	Firm();
	Firm(string _name);
	Firm(string _name, string _country = "������", string _dateIn = "������� ����", string _email = "", string  _web = "", string _region = "", string _town = "", string _street = "", string _postInx = "");
	~Firm();

	bool AddField(string Name, string Value = "");//�������� ����
	string GetField(string Name);//������� �������� ����
	bool SetField(string Name, string Value);//���������� ��������� ����
	bool RenameField(string OldName, string NewName);//��������������� ����
	string GetMain();//������ �������� ����������� � �����

	bool AddSbFirm(string _name, string _ofcBossName = "", string _bossName = "", string _email = "", string _tel = "", string _sbFirmType = "���-�����", bool _sbFirmIsMain = false);//���������� ���-�����
	bool AddCont(Contact _cont);
	bool ExistContact(Contact _cont);
	bool AddContToSbFirm(string _sbFirmName, Contact _cont);
private:
	list <SubFirm> ::iterator GetSbFirm(string _name);
	map <string, string> _usrFields;
};

