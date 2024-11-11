#include "../include/Joc.h"
#include <algorithm>
#include <random>

Joc::Joc(const Scor &scorul_jocului_, const std::vector<Echipa> &echipe_, const std::vector<Jucator> &jucatori_)
    : scorul_jocului(scorul_jocului_), echipe(echipe_), jucatori(jucatori_), jucatori_selectati(), game_running(0) {}

Joc::Joc(const std::string &fisier_echipe, const std::string &fisier_jucatori)
    : scorul_jocului(0, 0), jucatori_selectati(), game_running(0)
{
    std::ifstream fin_echipe(fisier_echipe);
    if (!fin_echipe)
    {
        std::cout << "Nu s-a putut deschide fisierul pentru echipe!\n";
        return;
    }

    // std::string nume, nationalitate;
    while (true)
    {
        Echipa echipa;
        if (!(fin_echipe >> echipa))
            break;

        this->echipe.push_back(echipa);
    }

    fin_echipe.close();

    std::ifstream fin_jucatori(fisier_jucatori);
    if (!fin_jucatori)
    {
        std::cout << "Nu s-a putut deschide fisierul pentru jucatori!\n";
        return;
    }

    while (true)
    {
        Jucator jucator;
        if (!(fin_jucatori >> jucator))
            break;

        this->jucatori.push_back(jucator);
    }

    fin_jucatori.close();
}

std::ostream &operator<<(std::ostream &os, const Joc &joc)
{
    os << "Joc:\n";
    os << joc.scorul_jocului;
    os << "Echipe:\n";
    for (const auto &echipa : joc.echipe)
    {
        os << echipa;
    }
    os << "Jucatori:\n";
    for (const auto &jucator : joc.jucatori)
    {
        os << jucator;
    }
    return os;
}

void Joc::start_game()
{
    this->descriere_joc();
    this->game_running = 1;
    while (this->game_running)
    {
        this->tura_joc();
        this->amesteca_jucatori();
    }
}

void Joc::descriere_joc()
{
    std::cout << "===================================\n"
              << "          MEMORY GAME              \n"
              << "===================================\n"
              << "Bine ai venit la Memory Game!\n\n"
              << "Scopul jocului este simplu:\n"
              << "Memorează jucătorii de fotbal pe care i-ai selectat,\n"
              << "astfel încât să îi alegi pe toți fără să te repeți.\n\n"
              << "Atenție! Dacă te repeți, scorul tău va deveni 0\n"
              << "și va trebui să o iei de la capăt!\n\n"
              << "Și nu uita: de fiecare dată când selectezi un jucător,\n"
              << "aceștia se vor amesteca. Fii atent și concentrează-te!\n\n"
              << "Good luck!\n"
              << "===================================\n";
};

void Joc::amesteca_jucatori()
{
    std::shuffle(jucatori.begin(), jucatori.end(), std::default_random_engine(std::random_device{}()));
}

int Joc::cauta_jucator_in_jucatori_selectati(const std::string &nume_jucator)
{
    int gasit = 0;
    for (size_t i = 0; i < this->jucatori_selectati.size(); i++)
    {
        if (this->jucatori_selectati[i] == nume_jucator)
            gasit = 1;
    }

    return gasit;
}

bool Joc::check_game_over()
{
    return this->jucatori_selectati.size() == this->jucatori.size();
}

void Joc::tura_joc()
{
    int scor_a = this->scorul_jocului.get_scor_actual();
    int scor_b = this->scorul_jocului.get_cel_mai_bun_scor();
    int scor_i = this->scorul_jocului.get_incercari();

    std::cout
        << "Alege un jucator:\n"
        << "Scor actual: " << scor_a << "\n"
        << "Best score: " << scor_b << "\n"
        << "Incercari gresite pana acum: " << scor_i << "\n";

    for (size_t i = 0; i < jucatori.size(); i++)
    {
        std::cout << i << ". " << jucatori[i] << "\n";
    }

    size_t index;
    std::cin >> index;

    if (index >= this->jucatori.size())
    {
        std::cout << "Introdu un numar valid\n";
        return;
    }

    std::string nume_jucator_ales = this->jucatori[index].get_nume();
    int gasit = this->cauta_jucator_in_jucatori_selectati(nume_jucator_ales);

    if (gasit == 1)
    {
        this->jucatori_selectati.clear();
        this->scorul_jocului.set_scor_actual(0);
        this->scorul_jocului.set_incercari(scor_i + 1);
        if (scor_i + 1 >= 3)
        {
            this->game_running = 0;
            std::cout << "Din pacate ai pierdut...";
            return;
        }
        return;
    }

    scor_a += 1;

    this->jucatori_selectati.push_back(nume_jucator_ales);
    this->scorul_jocului.set_scor_actual(scor_a);

    if (scor_a > scor_b)
        this->scorul_jocului.set_cel_mai_bun_scor(scor_a);

    int game_over = this->check_game_over();
    if (game_over)
    {
        this->game_running = 0;
        std::cout << "CONGRATS AI CASTIGAT!\n";
    }
}