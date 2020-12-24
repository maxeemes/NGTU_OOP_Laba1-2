#include "stdafx.h"
#include "SubFirm.h"

Firm::Firm()
{
	Country = "Россия";
	time_t _dateIn;
	time(&_dateIn);
	char timebuf[26];
	ctime_s(timebuf, 26, &_dateIn);
	DateIn = timebuf;
}

Firm::Firm(string _name, string _country, string _dateIn, string _email, string _web, string _region, string _town, string _street, string _postInx): Name(_name)
{
	Firm();
	if (_country != "Россия" || _dateIn != "Текущая дата" || _email != "" || _web != "" || _region != "" || _town != "" || _street != "" || _postInx != "") {
		Country = _country;
		DateIn = _dateIn;
		Email = _email;
		Web = _web;
		Region = _region;
		Town = _town;
		Street = _street;
		PostInx = _postInx;
	}
}


Firm::~Firm()
{
}

bool Firm::AddField(string Name, string Value)
{
	auto search = _usrFields.find(Name);
	if (search != _usrFields.end())
	{
		_usrFields[Name] = "";
		return true;
	}
	return false;
}

string Firm::GetField(string Name)
{
	auto search = _usrFields.find(Name);
	if (search != _usrFields.end())
	{
		return _usrFields[Name];
	}
	return string();
}

bool Firm::SetField(string Name, string Value)
{
	auto search = _usrFields.find(Name);
	if (search != _usrFields.end())
	{
		_usrFields[Name] = Value;
		return true;
	}
	return false;
}

bool Firm::RenameField(string OldName, string NewName)
{
	auto search = _usrFields.find(OldName);
	if (search != _usrFields.end())
	{
		_usrFields[NewName] = _usrFields[OldName];
		_usrFields.erase(search);
		return true;
	}
	return false;
}

string Firm::GetMain()
{
	string result = "Страна: " + Country +
		";Дата добавления: " + DateIn +
		";Элетронная почта: " + Email +
		";Почтовый индекс: " + PostInx +
		";Регион: " + Region +
		";Город: " + Town +
		";Улица: " + Street +
		";Сайт: " + Web + ";";
	for (auto val : _usrFields) {
		result += val.first + ": " + val.second + ";";
	}
	return result;
}

bool Firm::AddSbFirm(string _name, string _ofcBossName, string _bossName, string _email, string _tel, string _sbFirmType, bool _sbFirmIsMain)
{
	if (_name.length() > 0 && (SbFirms.empty() || GetSbFirm(_name) != SbFirms.end()))
	{
		SubFirm NewSbFirm = SubFirm(_name);
		if (_ofcBossName.length() > 0 || _bossName.length() > 0 || _email.length() > 0 || _tel.length() || _sbFirmType != "Суб-фирма" || _sbFirmIsMain != false)
		{
			NewSbFirm = SubFirm(_name, _ofcBossName, _bossName, _email, _tel, _sbFirmType, _sbFirmIsMain);
		}
		if (_sbFirmIsMain) SbFirms.push_back(NewSbFirm);
		else SbFirms.push_front(NewSbFirm);
		return true;
	}
	return false;
}

bool Firm::AddCont(Contact _cont)
{
	if (SbFirms.empty() == false)
	{
		SbFirms.back().AddContact(_cont);
		return true;
	}
	return false;
}

bool Firm::ExistContact(Contact _cont)
{
	for (auto sbFirm : SbFirms) if (sbFirm.ExistContact(_cont)) return true;
	return false;
}

bool Firm::AddContToSbFirm(string _sbFirmName, Contact _cont)
{
	auto SbFirmFromList = GetSbFirm(_sbFirmName);
	if (SbFirmFromList != SbFirms.end()) {
		if (SbFirmFromList->AddContact(_cont) == true) return false;
	}
	return false;
}

list<SubFirm>::iterator Firm::GetSbFirm(string _name)
{
	for (list <SubFirm> ::iterator it = SbFirms.begin(); it != SbFirms.end(); it++) if (it->Name == _name) return it;
	return SbFirms.end();
}	