#pragma once
class SbFirmTypeCol//����� ��� �������� ������ ����� ��� �����������
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

