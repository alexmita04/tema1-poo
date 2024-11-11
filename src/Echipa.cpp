#include "../include/Echipa.h"

Echipa::Echipa(const std::string &nume_, const std::string &nationalitate_)
    : nume(nume_), nationalitate(nationalitate_) {}

std::istream &operator>>(std::istream &is, Echipa &echipa)
{
    is >> echipa.nume >> echipa.nationalitate;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Echipa &echipa)
{
    os << "===========================================\n"
       << "        DETALII ECHIPA                    \n"
       << "===========================================\n"
       << "Numele echipei:        " << echipa.nume << "\n"
       << "Nationalitate:         " << echipa.nationalitate << "\n"
       << "===========================================\n";

    return os;
}
