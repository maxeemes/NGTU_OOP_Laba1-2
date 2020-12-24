#include "stdafx.h"
#include "SbFirmType.h"

string SubFirm::GetMain()
{
	string result = "��� ���-�����: " + Name + ";"
		+ "��� �����: " + FirmTpy.Name + ";"
		+ "������� ���-�����: " + (FirmTpy.IsMain ? "��" : "���") + ";"
		+ "��� ���������: " + BossName + ";"
		+ "���������� ����: " + OfcBossName + ";"
		+ "����������� �����: " + Email + ";"
		+ "�������: " + Tel + ";";
	return result;
}

string SubFirm::IsYourType()
{
	return FirmTpy.Name;
}

bool SubFirm::AddContact(Contact Cont)
{
	if (ExistContact(Cont) == false)
	{
		Conts.push_front(Cont);
		return true;
	}
	return false;
}

bool SubFirm::ExistContact(Contact Cont)
{
	
	for (list <Contact> ::iterator it = Conts.begin(); it != Conts.end(); it++) if (*it == Cont) return true;
	return false;
}

int SubFirm::GetCountCont()
{
	return Conts.size();
}


SubFirm::SubFirm(string _name) : Name(_name), FirmTpy(SbFirmType())
{
}

SubFirm::SubFirm(string _name, string _ofcBossName, string _bossName, string _email, string _tel, string _sbFirmType, bool _sbFirmIsMain) : 
	Name(_name), 
	OfcBossName(_ofcBossName), 
	Email(_email), 
	Tel(_tel), 
	FirmTpy(SbFirmType(_sbFirmType, _sbFirmIsMain))
{
}


SubFirm::~SubFirm()
{
}
