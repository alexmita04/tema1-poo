#ifndef JUCATOR_H
#define JUCATOR_H

#include <iostream>
#include <string>

class Jucator
{
    std::string nume;
    std::string post;
    int numar_tricou;
    int varsta;
    int id;

public:
    explicit Jucator(const std::string &nume_ = "", const std::string &post_ = "", int numar_tricou_ = 0, int varsta_ = 0, int id_ = 0);
    Jucator(const Jucator &other);
    Jucator &operator=(const Jucator &other);
    ~Jucator();

    friend std::istream &operator>>(std::istream &is, Jucator &jucator);
    friend std::ostream &operator<<(std::ostream &os, const Jucator &jucator);

    std::string get_nume();
};

#endif
