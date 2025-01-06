#include "../include/Sportiv.h"

#include <iostream>
#include <memory>

Sportiv::Sportiv(const std::string &nume_, int varsta_, int id_)
    : nume(nume_), varsta(varsta_), id(id_) {}

Sportiv::~Sportiv() {}

void Sportiv::afisare_completa() const
{
    std::cout << "Nume: " << nume << ", Varsta: " << varsta << ", ID: " << id << std::endl;
    afiseaza();
}

JucatorFotbal::JucatorFotbal(const std::string &nume_, int varsta_, int id_, const std::string &post_, int numar_tricou_)
    : Sportiv(nume_, varsta_, id_), post(post_), numar_tricou(numar_tricou_) {}

void JucatorFotbal::afiseaza() const
{
    std::cout << "Post: " << post << ", Numar tricou: " << numar_tricou << std::endl;
}

std::unique_ptr<Sportiv> JucatorFotbal::clone() const
{
    return std::make_unique<JucatorFotbal>(*this);
}

JucatorBox::JucatorBox(const std::string &nume_, int varsta_, int id_, double greutate_)
    : Sportiv(nume_, varsta_, id_), greutate(greutate_) {}

void JucatorBox::afiseaza() const
{
    std::cout << "Greutate: " << greutate << " kg" << std::endl;
}

std::unique_ptr<Sportiv> JucatorBox::clone() const
{
    return std::make_unique<JucatorBox>(*this);
}

JucatorInot::JucatorInot(const std::string &nume_, int varsta_, int id_, double timp_record_)
    : Sportiv(nume_, varsta_, id_), timp_record(timp_record_) {}

void JucatorInot::afiseaza() const
{
    std::cout << "Timp record: " << timp_record << " secunde" << std::endl;
}

std::unique_ptr<Sportiv> JucatorInot::clone() const
{
    return std::make_unique<JucatorInot>(*this);
}
