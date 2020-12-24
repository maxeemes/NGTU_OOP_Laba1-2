#include "stdafx.h"


SbFirmType::SbFirmType(): Name("Суб-фирма"), IsMain(false)
{
}

SbFirmType::SbFirmType(string _name, bool _isMain) : Name(_name), IsMain(_isMain)
{
}

SbFirmType::~SbFirmType()
{
}
