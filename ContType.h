#pragma once
class ContType
{
public:
	string Name = "Имя отсутствует";
	string Note = "";


	ContType();
	ContType(string _name, string _note = "");
	~ContType();
};

