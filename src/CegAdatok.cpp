#include "CegAdatok.h"

CegAdatok::CegAdatok()
{}

CegAdatok::~CegAdatok()
{}

AdatFile CegAdatok::getAdatok()
{
    AdatFile adatFile("cegadatok.txt");
    return adatFile;
}
