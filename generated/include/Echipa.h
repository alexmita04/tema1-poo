#ifndef ECHIPA_H
#define ECHIPA_H

#include <iostream>
#include <string>

class Echipa
{
    std::string nume;
    std::string nationalitate;

public:
    Echipa(const std::string &nume_ = "", const std::string &nationalitate_ = "");

    friend std::istream &operator>>(std::istream &is, Echipa &echipa);

    friend std::ostream &operator<<(std::ostream &os, const Echipa &echipa);
};

#endif
