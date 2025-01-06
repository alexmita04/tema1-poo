#include "../include/Sportiv.h"
#include <iostream>
#include <memory>

Sportiv::Sportiv(const std::string &nume_, int varsta_, int id_)
    : nume(nume_), varsta(varsta_), id(id_) {}

Sportiv::~Sportiv() {}

std::istream &operator>>(std::istream &is, Sportiv &sportiv)
{
    sportiv.citeste(is);
    return is;
}

std::ostream &operator<<(std::ostream &os, const Sportiv &sportiv)
{
    sportiv.scrie(os);
    return os;
}

JucatorFotbal::JucatorFotbal() : Sportiv(), post("Necunoscut"), numar_tricou(0) {}

JucatorFotbal::JucatorFotbal(const std::string &nume_, int varsta_, int id_, const std::string &post_, int numar_tricou_)
    : Sportiv(nume_, varsta_, id_), post(post_), numar_tricou(numar_tricou_) {}

std::unique_ptr<Sportiv> JucatorFotbal::clone() const
{
    return std::make_unique<JucatorFotbal>(*this);
}

void JucatorFotbal::citeste(std::istream &is)
{
    is >> nume >> varsta >> id >> post >> numar_tricou;
}

void JucatorFotbal::scrie(std::ostream &os) const
{
    os << "Jucator Fotbal: " << nume << ", Varsta: " << varsta << ", ID: " << id
       << ", Post: " << post << ", Numar tricou: " << numar_tricou;
}

JucatorBox::JucatorBox() : Sportiv(), greutate(0.0) {}

JucatorBox::JucatorBox(const std::string &nume_, int varsta_, int id_, double greutate_)
    : Sportiv(nume_, varsta_, id_), greutate(greutate_) {}

std::unique_ptr<Sportiv> JucatorBox::clone() const
{
    return std::make_unique<JucatorBox>(*this);
}

void JucatorBox::citeste(std::istream &is)
{
    is >> nume >> varsta >> id >> greutate;
}

void JucatorBox::scrie(std::ostream &os) const
{
    os << "Jucator Box: " << nume << ", Varsta: " << varsta << ", ID: " << id
       << ", Greutate: " << greutate << " kg";
}

JucatorInot::JucatorInot() : Sportiv(), timp_record(0.0) {}

JucatorInot::JucatorInot(const std::string &nume_, int varsta_, int id_, double timp_record_)
    : Sportiv(nume_, varsta_, id_), timp_record(timp_record_) {}

std::unique_ptr<Sportiv> JucatorInot::clone() const
{
    return std::make_unique<JucatorInot>(*this);
}

void JucatorInot::citeste(std::istream &is)
{
    is >> nume >> varsta >> id >> timp_record;
}

void JucatorInot::scrie(std::ostream &os) const
{
    os << "Jucator Inot: " << nume << ", Varsta: " << varsta << ", ID: " << id
       << ", Timp record: " << timp_record << " secunde";
}
