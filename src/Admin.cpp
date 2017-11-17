#include "Admin.h"

Admin::Admin(const string& felhasznaloNev, const string& vezetekNev, const string& keresztNev) :
    Felhasznalo(felhasznaloNev, vezetekNev, keresztNev)
{
}

Admin::~Admin()
{}

void Admin::menuMutat()
{
    cout << "Bejelentkezve mint: " << felhasznaloNev << endl;
    cout << "> 1 : ceg felvetele" << endl;
    cout << "> 2 : ceg torlese" << endl;
    cout << "> 3 : ceg modositasa" << endl;
    cout << "> 4 : felhasznalo felvetele" << endl;
    cout << "> 5 : felhasznalok listazasa" << endl;
    cout << "> 6 : felhasznalo torlese" << endl;
    cout << "> 7 : felhasznalo modositasa" << endl;
    cout << "> 8 : cegek listazasa" << endl;
    cout << "> 9 : kilepes" << endl;
}

bool Admin::parancsFeldolgoz(int parancs, Adatok& adatok)
{
    return true;
}
