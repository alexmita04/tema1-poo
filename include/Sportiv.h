#ifndef SPORTIV_H
#define SPORTIV_H

#include <iostream>
#include <string>
#include <memory>

class Sportiv
{
protected:
    std::string nume;
    int varsta;
    int id;

public:
    explicit Sportiv(const std::string &nume_ = "", int varsta_ = 0, int id_ = 0);
    virtual ~Sportiv();

    virtual void afiseaza() const = 0;
    virtual std::unique_ptr<Sportiv> clone() const = 0;

    void afisare_completa() const;
};

class JucatorFotbal : public Sportiv
{
    std::string post;
    int numar_tricou;

public:
    JucatorFotbal(const std::string &nume_, int varsta_, int id_, const std::string &post_, int numar_tricou_);

    void afiseaza() const override;
    std::unique_ptr<Sportiv> clone() const override;
};

class JucatorBox : public Sportiv
{
    double greutate;

public:
    JucatorBox(const std::string &nume_, int varsta_, int id_, double greutate_);

    void afiseaza() const override;
    std::unique_ptr<Sportiv> clone() const override;
};

class JucatorInot : public Sportiv
{
    double timp_record;

public:
    JucatorInot(const std::string &nume_, int varsta_, int id_, double timp_record_);

    void afiseaza() const override;
    std::unique_ptr<Sportiv> clone() const override;
};

#endif
