#pragma once

class Firm
{
public:
	string Country = "Россия";
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

	bool AddField(string Name, string Value = "");//Добавить поле
	string GetField(string Name);//Полуить значение поля
	bool SetField(string Name, string Value);//установить знаачение поля
	bool RenameField(string OldName, string NewName);//Переименоавание поля
	string GetMain();//Выввод основной информациии о фирме

	bool AddSbFirm();
	bool AddCont();
	bool ExistContact();
	bool AddContToSbFirm();
private:
	map <string, string> _usrFields;
	int _ыbFirmsCount;
	
};

