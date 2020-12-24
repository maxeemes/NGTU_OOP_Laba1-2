#pragma once
using namespace std;
class SbFirmType
{
public:
	SbFirmType();
	SbFirmType(string _name, bool _isMain = false);
	~SbFirmType();
	bool IsMain = false;
	string Name;
};

