#pragma once
class ContTypeCol
{
public:
	int Count;

	bool Add(ContType Type);
	bool Clear();
	ContType GetContType(string TypeName);
	ContTypeCol();
	~ContTypeCol();
private:
	list <ContType> _lst;

};

