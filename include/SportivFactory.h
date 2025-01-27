#ifndef SPORTIV_FACTORY_H
#define SPORTIV_FACTORY_H

#include <memory>
#include <string>
#include <istream>
#include "Sportiv.h"

class SportivFactory
{
public:
    static std::unique_ptr<Sportiv> createJucator(const std::string &type, std::istream &is);
};

#endif
