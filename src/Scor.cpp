#include "../include/Scor.h"
#include "../include/Exceptii.h"

Scor::Scor(int scor_actual_, int cel_mai_bun_scor_)
    : scor_actual(scor_actual_), cel_mai_bun_scor(cel_mai_bun_scor_), incercari(0)
{
    if (scor_actual < 0)
    {
        throw ScorInvalidException("Scor actual negativ la inițializare: " + std::to_string(scor_actual));
    }
}

std::ostream &operator<<(std::ostream &os, const Scor &scor)
{
    os << "==============================================\n"
       << "                SCOR ACTUAL                  \n"
       << "==============================================\n"
       << "Scor Actual:            "
       << scor.scor_actual << "\n"
       << "Cel mai bun scor:      "
       << scor.cel_mai_bun_scor << "\n"
       << "Incercari gresite:     "
       << scor.incercari << "\n"
       << "==============================================\n";

    return os;
}

void Scor::incrementare_scor_actual()
{
    this->scor_actual += 1;
    this->actualizare_cel_mai_bun_scor();
}

void Scor::resetare_scor()
{
    this->afisare_scor_actual_dupa_greseala();
    this->scor_actual = 0;
}

void Scor::incrementare_incercari()
{
    this->incercari += 1;
}

int Scor::get_incercari()
{
    return this->incercari;
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

void Scor::afisare_scor_actual_dupa_greseala()
{
    std::cout << "===============================================\n"
              << "       SCORUL TAU INAINTE DE A GRESI          \n"
              << "===============================================\n"
              << "Scorul tau inainte de a gresi era:          "
              << this->scor_actual << "\n"
              << "===============================================\n";
}