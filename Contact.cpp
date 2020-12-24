#include "stdafx.h"


Contact::Contact()
{
	DataInfo = "Контакт";
	CntType = ContType("Контакт");

	time_t Date;
	time(&Date);
	char timebuf[26];
	ctime_s(timebuf, 26, &Date);
	BeginDt = timebuf[26];
	EndDt = timebuf[26];
}

Contact::Contact(string _dateInfo, string _descr, ContType _CntType, string _beginDt, string _endDate)
{
	DataInfo = _dateInfo;
	Descr = _descr;
	if (_CntType.Name != "Контакт") CntType = CntType;
	if (_beginDt != "Текущее время") BeginDt = _beginDt;
	if (_endDate != "Текущее время") EndDt = _endDate;
}



Contact::~Contact()
{
}

bool Contact::Clone(Contact Cont)
{
	DataInfo = Cont.DataInfo;
	Descr = Cont.Descr;
	CntType = Cont.CntType;
	BeginDt = Cont.BeginDt;
	EndDt = Cont.EndDt;
	return true;
}

bool Contact::operator!=(Contact Ref)
{
	if(
		DataInfo == Ref.DataInfo &&
		Descr == Ref.Descr &&
		CntType.Name == Ref.CntType.Name &&
		CntType.Note == Ref.CntType.Note &&
		BeginDt == Ref.BeginDt &&
		EndDt == Ref.EndDt 
		) return false;
	return true;
}

bool Contact::operator==(Contact Ref)
{
	return !operator!=(Ref);
}
