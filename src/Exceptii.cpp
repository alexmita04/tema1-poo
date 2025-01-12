#include "../include/Exceptii.h"

JocException::JocException(const std::string &mesaj_) : mesaj(mesaj_) {}

const char *JocException::what() const noexcept
{
    return mesaj.c_str();
}

JocNeinitializatException::JocNeinitializatException(const std::string &detalii)
    : JocException("Eroare: Jocul nu a fost inițializat corect. Detalii: " + detalii) {}

ScorInvalidException::ScorInvalidException(const std::string &detalii)
    : JocException("Eroare: Scorul este invalid. Detalii: " + detalii) {}

TipJucatorException::TipJucatorException(const std::string &detalii)
    : JocException("Eroare: Scorul este invalid. Detalii: " + detalii) {}

InputInvalidException::InputInvalidException(const std::string &detalii)
    : JocException("Eroare: Input invalid. Detalii: " + detalii) {}