#include "stdafx.h"
#include "FirmFactory.h"

string GetSimpleField(string src, string identifier);
list<string> GetArrayObjects(string src, string identifier);//todo

FirmFactory::FirmFactory()
{
}


FirmFactory::~FirmFactory()
{
}

Firm FirmFactory::CreateFromMainFields(string _name, list<string> flds, string _country, string _dateIn, string _email, string _web, string _region, string _town, string _street, string _postInx)
{
	Firm result = Firm(_name, _country, _dateIn, _email, _web, _region, _town, _street, _postInx);
	if (flds.empty() == false)
	{
		for (string fld : flds)
		{
			result.AddField(fld);
		}
	}
	return result;
}

Firm FirmFactory::CreateFromClasses(Firm _firmMainInfo, map<string, string> _userFields, list<SubFirm> _sbFirms)
{
	for (auto fld : _userFields)
	{
		_firmMainInfo.AddField(fld.first, fld.second);
	}
	for (auto sbFrm : _sbFirms)
	{
		if (_firmMainInfo.AddSbFirm(sbFrm) == false)
		{
			_firmMainInfo.Name = "Ошибочная фирма";
			return _firmMainInfo;
		}
	}

	return _firmMainInfo;
}

Firm FirmFactory::CreateFromStructuredString(string _firm)
{
	//Пример строки: Имя_фирмы: Ромашка, Элетронная_почта: romashka@m.ru, Сайт: r.ru, Регион: Нижегородская область, Город: Нижний Новгород, Улица: "Горького, 1", Индекс: 603000, Страна: Россия, Дата_добавления: 01.12.2020, 
	//Дополнительные_поля: [
	//{Имя_поля: Направление, Значениие_поля: Консультационные услуги},
	//{Имя_поля: Годовой оборот, Значениие_поля: Консультационные услуги},
	//],
	//Суб_фирмы: [
	//	{Имя_суб-фирмы: Ромашка ритейл, Имя_начальника: Михаил Павлович, Имя_начальника_суб-фирмы: Иван Иванович, Элетронная_почта: romashka_ret@m.ru, Телефон: +7(800)603-09-30, Тип_суб-фирмы: Продажа продукции, Главная_суб-фирма: да},
	//	{Имя_суб-фирмы: Ромашка продакт, Имя_начальника: Михаил Павлович, Имя_начальника_суб-фирмы: Григорий Иванович,								   Телефон: +7(800)603-09-31, Тип_суб-фирмы: Производство продукции, Главная_суб-фирма: нет}
	//]
	//разбор основных полей фирмы
	Firm NewFirm = Firm(
		GetSimpleField(_firm, "Имя_фирмы"),
		GetSimpleField(_firm, "Страна"),
		GetSimpleField(_firm, "Дата_добавления"),
		GetSimpleField(_firm, "Элетронная_почта"),
		GetSimpleField(_firm, "Сайт"),
		GetSimpleField(_firm, "Регион"),
		GetSimpleField(_firm, "Город"),
		GetSimpleField(_firm, "Улица"),
		GetSimpleField(_firm, "Индекс")
	);
	//разбор дополнительных полей фирмы 
	//получение массива строк
	list<string> AddFlds = GetArrayObjects(_firm, "Дополнительные_поля");
	for (string AddFld : AddFlds)
	{
		string FldName = GetSimpleField(AddFld, "Имя_поля");
		string FldValue = GetSimpleField(AddFld, "Значениие_поля");
		
		if (NewFirm.AddField(FldName, FldValue) == false)
		{
			return Firm();
		}
	}
	//получение массива суб-фирм
	list<string> Sbfrms = GetArrayObjects(_firm, "Суб_фирмы");
	for (string Sbfrm : Sbfrms)
	{
		//string test = GetSimpleField(_firm, "Имя_начальника_суб-фирмы");
		SubFirm NewSbFirm = SubFirm(
			GetSimpleField(Sbfrm, "Имя_суб-фирмы"),
			GetSimpleField(Sbfrm, "Имя_начальника"),
			GetSimpleField(Sbfrm, "Имя_начальника_суб-фирмы"),
			GetSimpleField(Sbfrm, "Элетронная_почта"),
			GetSimpleField(Sbfrm, "Телефон"),
			GetSimpleField(Sbfrm, "Тип_суб-фирмы"),
			GetSimpleField(Sbfrm, "Главная_суб-фирма") == "да"
		);
		if (NewFirm.AddSbFirm(NewSbFirm) == false) return Firm();
	}

	return NewFirm;
}

string GetSimpleField(string src, string identifier)
{
	int FldEnd = -1;
	int FldSmpStart = src.find(identifier + ": ") + identifier.length() + 2;
	//int FldAltStart = src.find(identifier + ": \"") + identifier.length() + 3;
	if (src[FldSmpStart] == '"')
	{
		FldSmpStart++;
		FldEnd = src.find('"', FldSmpStart);
		string res = src.substr(FldSmpStart, FldEnd - FldSmpStart);
		return res;
	}
	else if (FldSmpStart >= int(identifier.length() + 2))
	{
		FldEnd = src.find(",", FldSmpStart);
		if (FldEnd < FldSmpStart) FldEnd = src.length();
		string res = src.substr(FldSmpStart, FldEnd - FldSmpStart);
		return res;
	}
	
	return string();
}

list<string> GetArrayObjects(string src, string identifier)
{
	list<string> objects;
	int FldStart = src.find(identifier + ":") + identifier.length() + 1;
	int ArrStart = src.find("[", FldStart) + 1;
	int ArrEnd = src.find("]", ArrStart);
	string ArrElements = src.substr(ArrStart, ArrEnd - ArrStart + 1);
	for (int ElementStart = ArrElements.find("{") + 1, ElementEnd = ArrElements.find("}", ElementStart);
		ElementEnd > ElementStart && ElementStart >= 1;
		ElementStart = ArrElements.find("{", ElementEnd) + 1, ElementEnd = ArrElements.find("}", ElementStart))
	{
		objects.push_back(ArrElements.substr(ElementStart, ElementEnd - ElementStart));
	}
	return objects;
}

