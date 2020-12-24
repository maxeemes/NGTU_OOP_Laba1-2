#pragma once
class ContTypeCol
{
public:
	bool Add(ContType _type);
	bool Clear();
	ContType GetContType(string _typeName);

	ContTypeCol();
	~ContTypeCol();
private:
	list <ContType> ContTypes;
};

