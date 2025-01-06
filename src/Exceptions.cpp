#include "../include/Exceptions.h"

GameException::GameException(const std::string &msg) : mesaj(msg) {}

const char *GameException::what() const noexcept
{
    return mesaj.c_str();
}

FileOpenException::FileOpenException(const std::string &filename)
    : GameException("Eroare la deschiderea fisierului: " + filename) {}

InvalidPlayerException::InvalidPlayerException(const std::string &nume_jucator)
    : GameException("Jucator invalid: " + nume_jucator) {}

GameOverException::GameOverException(const std::string &motiv)
    : GameException("Joc incheiat: " + motiv) {}
