#pragma once
class SbFirmTypeCol//����� ��� �������� ������ ����� ��� �����������
{
public:
	int Count;

	bool Add(SbFirmType Type);
	bool Clear();
	SbFirmType GetSbFirmType(string TypeName);
	SbFirmTypeCol();
	~SbFirmTypeCol();
};

