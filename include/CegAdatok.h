#ifndef CEGADATOK_H
#define CEGADATOK_H

#include <iostream>
#include "AdatFile.h"
using namespace std;

class CegAdatok
{
    public:
        CegAdatok();
        virtual ~CegAdatok();

        AdatFile getAdatok();
};

#endif // CEGADATOK_H
