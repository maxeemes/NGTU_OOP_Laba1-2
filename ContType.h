#pragma once
using namespace std;
class ContType
{
public:
	string Name;
	string Note;

	ContType();
	ContType(string _name, string _note = "");
	~ContType();
};

