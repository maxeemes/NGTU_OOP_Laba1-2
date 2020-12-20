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
	bool AddField(string Name);//Добавить поле
	string GetField(string Name);//Полуить значение поля
	string SetField(string Name, string Value);//установить знаачение поля
	string RenameField(string OldName, string NewName);//Переименоавание поля
	string GetMain();//Выввод основной информациии о фирме

	//наполнить класс SubFirm
	bool AddSbFirm();
	//наполнить класс Contact
	bool AddCont();
	bool ExistContact();
	bool AddContToSbFirm();
private:
	string _conutry;
	string _dateIn;//посмотреть тип данных для даты
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

