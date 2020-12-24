#include "stdafx.h"

bool ContTypeCol::Add(ContType _type)
{
	if (GetContType(_type.Name).Name != "") {
		ContTypes.push_front(_type);
		return true;
	}
	return false;
}

bool ContTypeCol::Clear()
{
	if (ContTypes.empty())return false;
	ContTypes.clear();
	return true;
}

ContType ContTypeCol::GetContType(string _typeName)
{
	for (auto tp : ContTypes) {
		if (tp.Name == _typeName) return tp;
	}
	return ContType("");
}

ContTypeCol::ContTypeCol()
{
}


ContTypeCol::~ContTypeCol()
{
}
