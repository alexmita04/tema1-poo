#include "../include/Scor.h"

Scor::Scor(int scor_actual_, int cel_mai_bun_scor_)
    : scor_actual(scor_actual_), cel_mai_bun_scor(cel_mai_bun_scor_), incercari(0) {}

std::ostream &operator<<(std::ostream &os, const Scor &scor)
{
    os << "Scor Actual: " << scor.scor_actual << "\n"
       << "Cel mai bun scor: " << scor.cel_mai_bun_scor << "\n"
       << "Incercari gresite pana acum: " << scor.incercari << "\n";
    return os;
}

void Scor::incrementare_scor_actual()
{
    this->scor_actual += 1;
    this->actualizare_cel_mai_bun_scor();
}

void Scor::resetare_scor()
{
    this->scor_actual = 0;
}

void Scor::incrementare_incercari()
{
    this->incercari += 1;
}

void Scor::actualizare_cel_mai_bun_scor()
{
    if (this->scor_actual > this->cel_mai_bun_scor)
    {
        this->cel_mai_bun_scor = this->scor_actual;
    }
}

bool Scor::verifica_incercari()
{
    return this->incercari >= 3;
}
