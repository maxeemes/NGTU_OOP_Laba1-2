#include "stdafx.h"

ContType::ContType(): Name("Контакт")
{
}

ContType::ContType(string _name, string _note) : Name(_name), Note(_note)
{
}

ContType::~ContType()
{
}
