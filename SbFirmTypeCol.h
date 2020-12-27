#pragma once
class SbFirmTypeCol// ласс дл€ хранени€ списка типов суб организаций
{
public:
	bool Add(SbFirmType Type);
	bool Clear();
	SbFirmType GetSbFirmType(string TypeName);
	SbFirmTypeCol();
	~SbFirmTypeCol();
private:
	list <ContType> SbFirrmTypes;
};

