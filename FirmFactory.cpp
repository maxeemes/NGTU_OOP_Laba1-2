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
			_firmMainInfo.Name = "��������� �����";
			return _firmMainInfo;
		}
	}

	return _firmMainInfo;
}

Firm FirmFactory::CreateFromStructuredString(string _firm)
{
	//������ ������: ���_�����: �������, ����������_�����: romashka@m.ru, ����: r.ru, ������: ������������� �������, �����: ������ ��������, �����: "��������, 1", ������: 603000, ������: ������, ����_����������: 01.12.2020, 
	//��������������_����: [
	//{���_����: �����������, ���������_����: ���������������� ������},
	//{���_����: ������� ������, ���������_����: ���������������� ������},
	//],
	//���_�����: [
	//	{���_���-�����: ������� ������, ���_����������: ������ ��������, ���_����������_���-�����: ���� ��������, ����������_�����: romashka_ret@m.ru, �������: +7(800)603-09-30, ���_���-�����: ������� ���������, �������_���-�����: ��},
	//	{���_���-�����: ������� �������, ���_����������: ������ ��������, ���_����������_���-�����: �������� ��������,								   �������: +7(800)603-09-31, ���_���-�����: ������������ ���������, �������_���-�����: ���}
	//]
	//������ �������� ����� �����
	//string FName = GetSimpleField(_firm, "���_�����");
	//string FCoutr = GetSimpleField(_firm, "������");
	//string FDt = GetSimpleField(_firm, "����_����������");
	//string FEm = GetSimpleField(_firm, "����������_�����");
	//string Fweb = GetSimpleField(_firm, "����");
	//string FReg = GetSimpleField(_firm, "������");
	//string FTow = GetSimpleField(_firm, "�����");
	//string FStrt = GetSimpleField(_firm, "�����");
	//string FInx = GetSimpleField(_firm, "������");


	Firm NewFirm = Firm(
		GetSimpleField(_firm, "���_�����"),
		GetSimpleField(_firm, "������"),
		GetSimpleField(_firm, "����_����������"),
		GetSimpleField(_firm, "����������_�����"),
		GetSimpleField(_firm, "����"),
		GetSimpleField(_firm, "������"),
		GetSimpleField(_firm, "�����"),
		GetSimpleField(_firm, "�����"),
		GetSimpleField(_firm, "������")
	);
	//������� �������������� ����� ����� 
	//��������� ������� �����
	list<string> AddFlds = GetArrayObjects(_firm, "��������������_����");
	for (string AddFld : AddFlds)
	{
		string FldName = GetSimpleField(AddFld, "���_����");
		string FldValue = GetSimpleField(AddFld, "���������_����");
		
		if (NewFirm.AddField(FldName, FldValue) == false)
		{
			return Firm();
		}
	}
	//��������� ������� ���-����
	list<string> Sbfrms = GetArrayObjects(_firm, "���_�����");
	for (string Sbfrm : Sbfrms)
	{
		//string test = GetSimpleField(_firm, "���_����������_���-�����");
		SubFirm NewSbFirm = SubFirm(
			GetSimpleField(Sbfrm, "���_���-�����"),
			GetSimpleField(Sbfrm, "���_����������"),
			GetSimpleField(Sbfrm, "���_����������_���-�����"),
			GetSimpleField(Sbfrm, "����������_�����"),
			GetSimpleField(Sbfrm, "�������"),
			GetSimpleField(Sbfrm, "���_���-�����"),
			GetSimpleField(Sbfrm, "�������_���-�����") == "��"
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

