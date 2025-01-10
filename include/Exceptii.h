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

class JocNeinitializatException : public JocException
{
public:
    explicit JocNeinitializatException(const std::string &detalii);
};

class ScorInvalidException : public JocException
{
public:
    explicit ScorInvalidException(const std::string &detalii);
};

class TipJucatorException : public JocException
{
public:
    explicit TipJucatorException(const std::string &detalii);
};

#endif