#include "Scor.h"

Scor::Scor(int scor_actual_, int cel_mai_bun_scor_)
    : scor_actual(scor_actual_), cel_mai_bun_scor(cel_mai_bun_scor_) {}

std::ostream &operator<<(std::ostream &os, const Scor &scor)
{
    os << "Scor Actual: " << scor.scor_actual << "\n"
       << "Cel mai bun scor: " << scor.cel_mai_bun_scor << "\n";
    return os;
}

void Scor::set_scor_actual(int scor)
{
    this->scor_actual = scor;
}

void Scor::set_cel_mai_bun_scor(int scor)
{
    this->cel_mai_bun_scor = scor;
}

int Scor::get_scor_actual()
{
    return this->scor_actual;
}

int Scor::get_cel_mai_bun_scor()
{
    return this->cel_mai_bun_scor;
}