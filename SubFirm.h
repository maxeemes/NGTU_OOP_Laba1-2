#pragma once
class SubFirm
{
public:
	string Name;
	string OfcBossName;
	string BossName;
	string Email;
	string Tel;
	SbFirmType FirmTpy;
	list <Contact> Conts;

	string GetMain();//Вывод основной информации об суб-фирме
	string IsYourType();// возвращает тип суб-фирмы
	bool AddContact(Contact _cont);
	bool ExistContact(Contact _cont);
	int GetCountCont();

	//SubFirm();
	SubFirm(string _name);
	SubFirm(string _name, string _ofcBossName, string _bossName, string _email, string _tel, string _sbFirmType = "Суб-фирма", bool _sbFirmIsMain = false);
	~SubFirm();
};

