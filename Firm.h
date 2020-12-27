#pragma once
using namespace std;
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

	Firm();
	Firm(string _name, string _country = "������", string _dateIn = "������� ����", string _email = "", string  _web = "", string _region = "", string _town = "", string _street = "", string _postInx = "");
	//~Firm();
	~Firm(void);

	bool AddField(string Name, string Value = "");//�������� ����
	string GetField(string Name);//������� �������� ����
	bool SetField(string Name, string Value);//���������� �������� ����
	bool RenameField(string OldName, string NewName);//��������������� ����
	string GetMain();//������ �������� ����������� � �����

	bool AddSbFirm(string _name, string _ofcBossName = "", string _bossName = "", string _email = "", string _tel = "", string _sbFirmType = "���-�����", bool _sbFirmIsMain = false);//���������� ���-�����
	bool AddSbFirm(SubFirm _sbFirm);//���������� ���-�����
	bool AddCont(Contact _cont);
	bool ExistContact(Contact _cont);
	bool AddContToSbFirm(string _sbFirmName, Contact _cont);
	list<SubFirm> GetSbFirms();
	SubFirm GetSbFirm(string _name);
private:
	list<SubFirm> SbFirms;
	list <SubFirm> ::iterator GetSbFirmIt(string _name);
	map <string, string> _usrFields;
};

