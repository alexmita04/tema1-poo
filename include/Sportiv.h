#ifndef SPORTIV_H
#define SPORTIV_H

#include <iostream>
#include <string>
#include <memory>

class Sportiv
{
private:
    std::string nume;
    int varsta;
    int id;

public:
    static int counter_jucatori;

    explicit Sportiv(const std::string &nume_ = "", int varsta_ = 0, int id_ = 0);
    virtual ~Sportiv();

    virtual std::unique_ptr<Sportiv> clone() const = 0;
    virtual bool nuEsteFotbalist() const = 0;
    std::string getNume()
    {
        return this->nume;
    }

    friend std::ostream &operator<<(std::ostream &os, const Sportiv &sportiv_);
    friend std::istream &operator>>(std::istream &is, Sportiv &sportiv_);

protected:
    virtual void afisare(std::ostream &os) const = 0;
    virtual void citire(std::istream &is) = 0;
};

class JucatorFotbal : public Sportiv
{
    std::string post;
    int numar_tricou;

    void afisare(std::ostream &os) const override;
    void citire(std::istream &is) override;

public:
    static int counter_jucatori_fotbal;

    JucatorFotbal();
    JucatorFotbal(const std::string &nume_, int varsta_, int id_, const std::string &post_, int numar_tricou_);
    ~JucatorFotbal() override;

    std::unique_ptr<Sportiv> clone() const override;
    virtual bool nuEsteFotbalist() const override;
};

class JucatorBox : public Sportiv
{
    double greutate;
    void afisare(std::ostream &os) const override;
    void citire(std::istream &is) override;

public:
    static int counter_jucatori_box;

    JucatorBox();
    JucatorBox(const std::string &nume_, int varsta_, int id_, double greutate_);
    ~JucatorBox() override;

    std::unique_ptr<Sportiv> clone() const override;
    virtual bool nuEsteFotbalist() const override;
};

class JucatorInot : public Sportiv
{
    double timp_record;
    void afisare(std::ostream &os) const override;
    void citire(std::istream &is) override;

public:
    static int counter_jucatori_inot;

    JucatorInot();
    JucatorInot(const std::string &nume_, int varsta_, int id_, double timp_record_);
    ~JucatorInot() override;

    std::unique_ptr<Sportiv> clone() const override;
    virtual bool nuEsteFotbalist() const override;
};

#endif