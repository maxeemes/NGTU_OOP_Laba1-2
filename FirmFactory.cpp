#include "stdafx.h"
#include "FirmFactory.h"


FirmFactory::FirmFactory()
{
}


FirmFactory::~FirmFactory()
{
}

Firm FirmFactory::Create(string _name, list<string> flds, string _country, string _dateIn, string _email, string _web, string _region, string _town, string _street, string _postInx)
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
