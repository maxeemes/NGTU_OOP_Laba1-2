#include "stdafx.h"
#include <map>

Firm::Firm()
{
	time_t _dateIn;
	time(&_dateIn);
	char timebuf[26];
	ctime_s(timebuf, 26, &_dateIn);
	DateIn = _dateIn;
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
	return string();
}

