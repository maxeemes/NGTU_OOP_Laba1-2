#pragma once
class SubFirm
{
public:
	string BossName;
	string Email;
	string Name;
	string Tel;
	string OfcBossName;
	bool IsMain;
	int CountCont;
	SbFirmType FirmTpy;

	bool AddContact(Contact Cont);
	bool ExistContact(Contact Cont);
	string IsYourType();

	SubFirm();
	~SubFirm();
private:
	string _bossName;
	string _email;
	string _name;
	string _ofcBossName;
	string _tel;
	Contact *_conts;
	SbFirmType _tpy;

};

