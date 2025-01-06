#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class GameException : public std::exception
{
protected:
    std::string mesaj;

public:
    explicit GameException(const std::string &msg);
    const char *what() const noexcept override;
};

class FileOpenException : public GameException
{
public:
    explicit FileOpenException(const std::string &filename);
};

class InvalidPlayerException : public GameException
{
public:
    explicit InvalidPlayerException(const std::string &nume_jucator);
};

class GameOverException : public GameException
{
public:
    explicit GameOverException(const std::string &motiv);
};

#endif
