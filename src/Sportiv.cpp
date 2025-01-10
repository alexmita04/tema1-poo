#include "../include/Sportiv.h"
#include <iostream>
#include <memory>

int Sportiv::counter_jucatori = 0;
int JucatorFotbal::counter_jucatori_fotbal = 0;
int JucatorBox::counter_jucatori_box = 0;
int JucatorInot::counter_jucatori_inot = 0;
int JucatorTenis::counter_jucatori_tenis = 0;

Sportiv::Sportiv(const std::string &nume_, int varsta_, int id_)
    : nume(nume_), varsta(varsta_), id(id_)
{
    ++counter_jucatori;
}

Sportiv::Sportiv(const Sportiv &other)
    : nume(other.nume), varsta(other.varsta), id(other.id)
{
    ++counter_jucatori;
}

Sportiv &Sportiv::operator=(const Sportiv &other)
{
    if (this != &other)
    {
        nume = other.nume;
        varsta = other.varsta;
        id = other.id;
    }
    return *this;
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

JucatorFotbal::JucatorFotbal(const JucatorFotbal &other)
    : Sportiv(other), post(other.post), numar_tricou(other.numar_tricou)
{
    ++counter_jucatori_fotbal;
}

JucatorFotbal &JucatorFotbal::operator=(const JucatorFotbal &other)
{
    if (this != &other)
    {
        Sportiv::operator=(other);
        post = other.post;
        numar_tricou = other.numar_tricou;
    }
    return *this;
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

JucatorBox::JucatorBox(const JucatorBox &other)
    : Sportiv(other), greutate(other.greutate)
{
    ++counter_jucatori_box;
}

JucatorBox &JucatorBox::operator=(const JucatorBox &other)
{
    if (this != &other)
    {
        Sportiv::operator=(other);
        greutate = other.greutate;
    }
    return *this;
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

JucatorInot::JucatorInot(const JucatorInot &other)
    : Sportiv(other), timp_record(other.timp_record)
{
    ++counter_jucatori_inot;
}

JucatorInot &JucatorInot::operator=(const JucatorInot &other)
{
    if (this != &other)
    {
        Sportiv::operator=(other);
        timp_record = other.timp_record;
    }
    return *this;
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

JucatorTenis::JucatorTenis() : Sportiv(), clasament_wta(0)
{
    ++counter_jucatori_tenis;
}

JucatorTenis::JucatorTenis(const std::string &nume_, int varsta_, int id_, int clasament_wta_)
    : Sportiv(nume_, varsta_, id_), clasament_wta(clasament_wta_)
{
    ++counter_jucatori_tenis;
}

JucatorTenis::JucatorTenis(const JucatorTenis &other)
    : Sportiv(other), clasament_wta(other.clasament_wta)
{
    ++counter_jucatori_tenis;
}

JucatorTenis &JucatorTenis::operator=(const JucatorTenis &other)
{
    if (this != &other)
    {
        Sportiv::operator=(other);
        clasament_wta = other.clasament_wta;
    }
    return *this;
}

JucatorTenis::~JucatorTenis()
{
    --counter_jucatori_tenis;
}

void JucatorTenis::afisare(std::ostream &os) const
{
    os << clasament_wta;
}

void JucatorTenis::citire(std::istream &is)
{
    is >> clasament_wta;
}

std::unique_ptr<Sportiv> JucatorTenis::clone() const
{
    return std::make_unique<JucatorTenis>(*this);
}

bool JucatorTenis::nuEsteFotbalist() const
{
    return true;
}