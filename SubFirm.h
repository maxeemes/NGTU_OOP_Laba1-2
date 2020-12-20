#pragma once
class SubFirm
{
public:
	string BossName;

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

