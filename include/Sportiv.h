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

    virtual std::unique_ptr<Sportiv> clone() const = 0;
    virtual bool nuEsteFotbalist() const = 0;
    virtual void citeste(std::istream &is) = 0;
    virtual void scrie(std::ostream &os) const = 0;
    std::string getNume()
    {
        return this->nume;
    }

    friend std::istream &operator>>(std::istream &is, Sportiv &sportiv);
    friend std::ostream &operator<<(std::ostream &os, const Sportiv &sportiv);
};

class JucatorFotbal : public Sportiv
{
    std::string post;
    int numar_tricou;

public:
    JucatorFotbal();
    JucatorFotbal(const std::string &nume_, int varsta_, int id_, const std::string &post_, int numar_tricou_);

    std::unique_ptr<Sportiv> clone() const override;
    virtual bool nuEsteFotbalist() const;
    void citeste(std::istream &is) override;
    void scrie(std::ostream &os) const override;
};

class JucatorBox : public Sportiv
{
    double greutate;

public:
    JucatorBox();
    JucatorBox(const std::string &nume_, int varsta_, int id_, double greutate_);

    std::unique_ptr<Sportiv> clone() const override;
    virtual bool nuEsteFotbalist() const;
    void citeste(std::istream &is) override;
    void scrie(std::ostream &os) const override;
};

class JucatorInot : public Sportiv
{
    double timp_record;

public:
    JucatorInot();
    JucatorInot(const std::string &nume_, int varsta_, int id_, double timp_record_);

    std::unique_ptr<Sportiv> clone() const override;
    virtual bool nuEsteFotbalist() const;
    void citeste(std::istream &is) override;
    void scrie(std::ostream &os) const override;
};

#endif
