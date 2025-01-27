#ifndef SPORTIV_H
#define SPORTIV_H

#include <iostream>
#include <string>
#include <memory>

template <typename Derived>
class Countable
{
    static int nrObiecte;

protected:
    Countable()
    {
        ++nrObiecte;
    }
    ~Countable()
    {
        --nrObiecte;
    }

public:
    static int getNr()
    {
        return nrObiecte;
    }
};

template <typename Derived>
int Countable<Derived>::nrObiecte = 0;

class Sportiv : public Countable<Sportiv>
{
protected:
    std::string nume;
    int marcat_ca_scapare = 0;

private:
    int varsta;
    int id;

public:
    explicit Sportiv(const std::string &nume_ = "", int varsta_ = 0, int id_ = 0);
    Sportiv(const Sportiv &other);
    Sportiv &operator=(const Sportiv &other);
    virtual ~Sportiv();

    static std::unique_ptr<Sportiv> createJucator(const std::string &type, std::istream &is);
    void marcheazaAlegereGresita(int incercari);

    virtual std::unique_ptr<Sportiv> clone() const = 0;
    std::string getNume();
    virtual void schimbaNume() = 0;
    virtual void schimbaPropietate(int incercari) = 0;
    virtual int scapare() = 0;
    int verificaScapare();

    friend std::ostream &operator<<(std::ostream &os, const Sportiv &sportiv_);
    friend std::istream &operator>>(std::istream &is, Sportiv &sportiv_);

protected:
    virtual void afisare(std::ostream &os) const = 0;
    virtual void citire(std::istream &is) = 0;
};

class JucatorFotbal : public Sportiv, public Countable<JucatorFotbal>
{
    std::string post;
    int numar_tricou;

    void afisare(std::ostream &os) const override;
    void citire(std::istream &is) override;

public:
    JucatorFotbal();
    JucatorFotbal(const std::string &nume_, int varsta_, int id_, const std::string &post_, int numar_tricou_);
    JucatorFotbal(const JucatorFotbal &other);
    JucatorFotbal &operator=(const JucatorFotbal &other);
    ~JucatorFotbal() override;

    std::unique_ptr<Sportiv> clone() const override;
    void schimbaNume() override;
    void schimbaPropietate(int incercari) override;
    int scapare() override;
};

class JucatorBox : public Sportiv, public Countable<JucatorBox>
{
    double greutate;
    void afisare(std::ostream &os) const override;
    void citire(std::istream &is) override;

public:
    JucatorBox();
    JucatorBox(const std::string &nume_, int varsta_, int id_, double greutate_);
    JucatorBox(const JucatorBox &other);
    JucatorBox &operator=(const JucatorBox &other);
    ~JucatorBox() override;

    std::unique_ptr<Sportiv> clone() const override;
    void schimbaNume() override;
    void schimbaPropietate(int incercari) override;
    int scapare() override;
};

class JucatorInot : public Sportiv, public Countable<JucatorInot>
{
    double timp_record;
    void afisare(std::ostream &os) const override;
    void citire(std::istream &is) override;

public:
    JucatorInot();
    JucatorInot(const std::string &nume_, int varsta_, int id_, double timp_record_);
    JucatorInot(const JucatorInot &other);
    JucatorInot &operator=(const JucatorInot &other);
    ~JucatorInot() override;

    std::unique_ptr<Sportiv> clone() const override;
    void schimbaNume() override;
    void schimbaPropietate(int incercari) override;
    int scapare() override;
};

class JucatorTenis : public Sportiv, public Countable<JucatorTenis>
{
private:
    int clasament_wta;
    void afisare(std::ostream &os) const override;
    void citire(std::istream &is) override;

public:
    JucatorTenis();
    JucatorTenis(const std::string &nume_, int varsta_, int id_, int numar_rachete_);
    JucatorTenis(const JucatorTenis &other);
    JucatorTenis &operator=(const JucatorTenis &other);
    ~JucatorTenis() override;

    std::unique_ptr<Sportiv> clone() const override;
    void schimbaNume() override;
    void schimbaPropietate(int incercari) override;
    int scapare() override;
};

#endif