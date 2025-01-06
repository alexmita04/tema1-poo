#include "../include/Sportiv.h"
#include <iostream>
#include <memory>

int Sportiv::counter_jucatori = 0;
int JucatorFotbal::counter_jucatori_fotbal = 0;
int JucatorBox::counter_jucatori_box = 0;
int JucatorInot::counter_jucatori_inot = 0;

Sportiv::Sportiv(const std::string &nume_, int varsta_, int id_)
    : nume(nume_), varsta(varsta_), id(id_)
{
    ++counter_jucatori;
}

Sportiv::~Sportiv()
{
    --counter_jucatori;
}

std::ostream &operator<<(std::ostream &os, const Sportiv &sportiv_)
{
    os << sportiv_.nume << " ";
    sportiv_.afisare(os);
    return os;
}
std::istream &operator>>(std::istream &is, Sportiv &sportiv_)
{
    std::string nume;
    int varsta, id;

    is >> nume;
    is >> varsta;
    is >> id;

    sportiv_.nume = nume;
    sportiv_.varsta = varsta;
    sportiv_.id = id;

    sportiv_.citire(is);
    return is;
}

void JucatorFotbal::afisare(std::ostream &os) const
{
    os << numar_tricou;
}

void JucatorFotbal::citire(std::istream &is)
{
    is >> post;
    is >> numar_tricou;
}

JucatorFotbal::JucatorFotbal() : Sportiv(), post("Necunoscut"), numar_tricou(0)
{
    ++counter_jucatori_fotbal;
}

JucatorFotbal::JucatorFotbal(const std::string &nume_, int varsta_, int id_, const std::string &post_, int numar_tricou_)
    : Sportiv(nume_, varsta_, id_), post(post_), numar_tricou(numar_tricou_)
{
    ++counter_jucatori_fotbal;
}

JucatorFotbal::~JucatorFotbal()
{
    --counter_jucatori_fotbal;
}

std::unique_ptr<Sportiv> JucatorFotbal::clone() const
{
    return std::make_unique<JucatorFotbal>(*this);
}

bool JucatorFotbal::nuEsteFotbalist() const
{
    return false;
}

void JucatorBox::afisare(std::ostream &os) const
{
    os << greutate;
}

void JucatorBox::citire(std::istream &is)
{
    is >> greutate;
}

JucatorBox::JucatorBox() : Sportiv(), greutate(0.0)
{
    ++counter_jucatori_box;
}

JucatorBox::JucatorBox(const std::string &nume_, int varsta_, int id_, double greutate_)
    : Sportiv(nume_, varsta_, id_), greutate(greutate_)
{
    ++counter_jucatori_box;
}

JucatorBox::~JucatorBox()
{
    --counter_jucatori_box;
}

std::unique_ptr<Sportiv> JucatorBox::clone() const
{
    return std::make_unique<JucatorBox>(*this);
}

bool JucatorBox::nuEsteFotbalist() const
{
    return true;
}

void JucatorInot::afisare(std::ostream &os) const
{
    os << timp_record;
}

void JucatorInot::citire(std::istream &is)
{
    is >> timp_record;
}

JucatorInot::JucatorInot() : Sportiv(), timp_record(0.0)
{
    ++counter_jucatori_inot;
}

JucatorInot::JucatorInot(const std::string &nume_, int varsta_, int id_, double timp_record_)
    : Sportiv(nume_, varsta_, id_), timp_record(timp_record_)
{
    ++counter_jucatori_inot;
}

JucatorInot::~JucatorInot()
{
    --counter_jucatori_inot;
}

std::unique_ptr<Sportiv> JucatorInot::clone() const
{
    return std::make_unique<JucatorInot>(*this);
}

bool JucatorInot::nuEsteFotbalist() const
{
    return true;
}
