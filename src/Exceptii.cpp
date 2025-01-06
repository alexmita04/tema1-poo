#include "../include/Exceptii.h"

JocException::JocException(const std::string &mesaj_) : mesaj(mesaj_) {}

const char *JocException::what() const noexcept
{
    return mesaj.c_str();
}

FisierInaccesibilException::FisierInaccesibilException(const std::string &nume_fisier)
    : JocException("Eroare: Fișierul \"" + nume_fisier + "\" nu poate fi accesat.") {}

IndexInvalidException::IndexInvalidException(size_t index)
    : JocException("Eroare: Index invalid \"" + std::to_string(index) + "\".") {}

JucatorInvalidException::JucatorInvalidException(const std::string &nume_jucator)
    : JocException("Eroare: Jucătorul \"" + nume_jucator + "\" nu este valid pentru această acțiune.") {}
