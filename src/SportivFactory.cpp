#include "../include/SportivFactory.h"
#include "../include/Exceptii.h"
#include <iostream>
#include <iomanip>

std::unique_ptr<Sportiv> SportivFactory::createJucator(const std::string &type, std::istream &is)
{
    if (type == "fotbalist")
    {
        std::string nume, post;
        int varsta, id, numar_tricou;
        is >> std::quoted(nume) >> varsta >> id >> post >> numar_tricou;
        return std::make_unique<JucatorFotbal>(nume, varsta, id, post, numar_tricou);
    }
    else if (type == "boxer")
    {
        std::string nume;
        int varsta, id;
        double greutate;
        is >> std::quoted(nume) >> varsta >> id >> greutate;
        return std::make_unique<JucatorBox>(nume, varsta, id, greutate);
    }
    else if (type == "inotator")
    {
        std::string nume;
        int varsta, id;
        double timp_record;
        is >> std::quoted(nume) >> varsta >> id >> timp_record;
        return std::make_unique<JucatorInot>(nume, varsta, id, timp_record);
    }
    else if (type == "tenismen")
    {
        std::string nume;
        int varsta, id, clasament_wta;
        is >> std::quoted(nume) >> varsta >> id >> clasament_wta;
        return std::make_unique<JucatorTenis>(nume, varsta, id, clasament_wta);
    }
    else
    {
        throw TipJucatorException("Nu exista acest tip de jucator");
    }
}
