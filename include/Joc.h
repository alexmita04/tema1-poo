#ifndef JOC_H
#define JOC_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include "Scor.h"
#include "Echipa.h"
#include "Jucator.h"

class Joc
{
    Scor scorul_jocului;
    std::vector<Echipa> echipe;
    std::vector<Jucator> jucatori;
    std::vector<std::string> jucatori_selectati;
    int game_running;

public:
    Joc(const Scor &scorul_jocului_, const std::vector<Echipa> &echipe_, const std::vector<Jucator> &jucatori_);
    Joc(const std::string &fisier_echipe, const std::string &fisier_jucatori);
    friend std::ostream &operator<<(std::ostream &os, const Joc &joc);
    void start_game();
    int cauta_jucator_in_jucatori_selectati(const std::string &nume_jucator);
    int check_game_over();

private:
    void descriere_joc();
    void amesteca_jucatori();
    void tura_joc();
};

#endif
