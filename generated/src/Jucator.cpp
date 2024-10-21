#include "Jucator.h"

Jucator::Jucator(const std::string &nume_, const std::string &post_, int numar_tricou_, int varsta_, int id_)
    : nume(nume_), post(post_), numar_tricou(numar_tricou_), varsta(varsta_), id(id_) {}

Jucator::Jucator(const Jucator &other)
    : nume(other.nume), post(other.post), numar_tricou(other.numar_tricou), varsta(other.varsta), id(other.id) {}

Jucator &Jucator::operator=(const Jucator &other)
{
    if (this != &other)
    {
        this->nume = other.nume;
        this->post = other.post;
        this->numar_tricou = other.numar_tricou;
        this->varsta = other.varsta;
        this->id = other.id;
    }
    return *this;
}

Jucator::~Jucator() {}

std::istream &operator>>(std::istream &is, Jucator &jucator)
{
    is >> jucator.nume >> jucator.post >> jucator.numar_tricou >> jucator.varsta >> jucator.id;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Jucator &jucator)
{
    // os << "Nume: " << jucator.nume << "\n"
    //    << "Post: " << jucator.post << "\n"
    //    << "Numar tricou: " << jucator.numar_tricou << "\n"
    //    << "Varsta: " << jucator.varsta << "\n"
    //    << "Id: " << jucator.id << "\n";

    os << "Nume: " << jucator.nume << "\n";

    return os;
}

std::string Jucator::get_nume()
{
    return this->nume;
}