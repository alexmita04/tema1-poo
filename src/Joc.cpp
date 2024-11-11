#include "../include/Joc.h"
#include <algorithm>
#include <random>
#include <chrono>

Joc::Joc(const Scor &scorul_jocului_, const std::vector<Echipa> &echipe_, const std::vector<Jucator> &jucatori_)
    : scorul_jocului(scorul_jocului_), echipe(echipe_), jucatori(jucatori_), jucatori_selectati(), game_running(0) {}

Joc::Joc(const std::string &fisier_echipe, const std::string &fisier_jucatori)
    : scorul_jocului(0, 0), jucatori_selectati(), game_running(0)
{
    std::ifstream fin_echipe(fisier_echipe);
    if (!fin_echipe)
    {
        std::cout << "===============================================\n"
                  << "         EROARE LA DESCHIDEREA FISIERULUI      \n"
                  << "===============================================\n"
                  << "Nu s-a putut deschide fisierul pentru echipe!\n"
                  << "Asigura-te ca fisierul exista si este accesibil.\n"
                  << "===============================================\n";

        return;
    }

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
        std::cout << "===============================================\n"
                  << "         EROARE LA DESCHIDEREA FISIERULUI      \n"
                  << "===============================================\n"
                  << "Nu s-a putut deschide fisierul pentru jucatori!\n"
                  << "Verifica daca fisierul exista si daca ai permisiuni de citire.\n"
                  << "Asigura-te ca calea catre fisier este corecta.\n"
                  << "===============================================\n";

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

bool Joc::cauta_jucator_in_jucatori_selectati(const std::string &nume_jucator)
{
    int gasit = false;
    for (size_t i = 0; i < this->jucatori_selectati.size(); i++)
    {
        if (this->jucatori_selectati[i] == nume_jucator)
            gasit = true;
    }

    return gasit;
}

bool Joc::check_game_over()
{
    return this->jucatori_selectati.size() == this->jucatori.size();
}

long long Joc::calculeaza_timpul_scurs(const std::chrono::time_point<std::chrono::high_resolution_clock> &start,
                                       const std::chrono::time_point<std::chrono::high_resolution_clock> &sfarsit)
{
    auto durata = std::chrono::duration_cast<std::chrono::seconds>(sfarsit - start);
    return durata.count();
}

void Joc::tura_joc()
{

    auto timp_start = std::chrono::high_resolution_clock::now();

    std::cout
        << "Alege un jucator, si nu uita,\n"
        << "daca nu te poti decide ce jucator\n"
        << "si vrei sa lasi aceasta alegere\n"
        << "in voia calculatorului, tasteaza 999:\n"
        << this->scorul_jocului
        << "\n";

    for (size_t i = 0; i < jucatori.size(); i++)
    {
        std::cout << i << ". " << jucatori[i] << "\n";
    }

    size_t index;
    std::cin >> index;
    if (index == 999)
    {
        this->genereaza_jucator_random();
    }
    else if (index >= this->jucatori.size())
    {
        std::cout << "Introdu un numar valid.\n"
                  << "Te rog sa alegi un index intre 0 si "
                  << this->jucatori.size() - 1 << ",\n"
                  << "care reprezinta jucatorii disponibili.\n";

        return;
    }

    std::string nume_jucator_ales = this->jucatori[index].get_nume();
    int gasit = this->cauta_jucator_in_jucatori_selectati(nume_jucator_ales);

    if (gasit)
    {
        this->jucatori_selectati.clear();
        this->scorul_jocului.resetare_scor();
        this->scorul_jocului.incrementare_incercari();

        auto timp_sfarsit = std::chrono::high_resolution_clock::now();
        long long durata = calculeaza_timpul_scurs(timp_start, timp_sfarsit);
        std::cout << "Timpul scurs: " << durata << " secunde" << std::endl;

        if (this->scorul_jocului.verifica_incercari())
        {
            this->game_running = 0;
            std::cout << "===============================================\n"
                      << "               Din pacate ai pierdut...       \n"
                      << "===============================================\n"
                      << "Ai incercat sa alegi un jucator deja selectat,\n"
                      << "si din aceasta cauza jocul tau a fost resetat.\n"
                      << "Incearca sa fii mai atent la jucatorii pe care ii alegi.\n"
                      << "Nu te descuraja! Poate data viitoare vei fi mai norocos.\n"
                      << "Memoreaza jucatorii si nu-i alege de doua ori!\n"
                      << "===============================================\n";

            return;
        }
        return;
    }

    this->jucatori_selectati.push_back(nume_jucator_ales);
    this->scorul_jocului.incrementare_scor_actual();

    int game_over = this->check_game_over();

    auto timp_sfarsit = std::chrono::high_resolution_clock::now();
    long long durata = calculeaza_timpul_scurs(timp_start, timp_sfarsit);
    std::cout << "Timpul scurs: " << durata << " secunde" << std::endl;

    if (game_over)
    {
        this->game_running = 0;
        std::cout << "===============================================\n"
                  << "                  FELICITARI!                 \n"
                  << "===============================================\n"
                  << "Ai reusit sa castigi jocul! Felicitari pentru\n"
                  << "memoria ta excelenta si pentru atentia de care\n"
                  << "ai dat dovada in timpul jocului.\n"
                  << "Ai reusit sa alegi toti jucatorii fara sa te\n"
                  << "repeti, ceea ce este o realizare mare!\n"
                  << "Este o dovada de concentrare si perserverenta.\n"
                  << "Speram ca te-ai distrat si ca te vei intoarce\n"
                  << "pentru o noua provocare in curand.\n"
                  << "===============================================\n";
    }
}

size_t Joc::genereaza_jucator_random()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distributie(0, this->jucatori.size() - 1);

    size_t numar = distributie(gen);

    std::cout << "Ai ales functia 999 care a ales in locul tau urmatorul jucator: "
              << this->jucatori[numar].get_nume()
              << "\n";

    return numar;
}