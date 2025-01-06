#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <exception>
#include <string>

class JocException : public std::exception
{
protected:
    std::string mesaj;

public:
    explicit JocException(const std::string &mesaj_);
    const char *what() const noexcept override;
};

class FisierInaccesibilException : public JocException
{
public:
    explicit FisierInaccesibilException(const std::string &nume_fisier);
};

class IndexInvalidException : public JocException
{
public:
    explicit IndexInvalidException(size_t index);
};

class JucatorInvalidException : public JocException
{
public:
    explicit JucatorInvalidException(const std::string &nume_jucator);
};

#endif
