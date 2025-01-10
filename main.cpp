#include <iostream>
#include "include/Sportiv.h"
#include "include/Echipa.h"
#include "include/Scor.h"
#include "include/Joc.h"
#include "include/Exceptii.h"
int main()
{
    try
    {
        Joc joc_actual("echipe.txt", "jucatori.txt");
        joc_actual.start_game();
    }
    catch (const JocNeinitializatException &e)
    {
        std::cerr << "Eroare de inițializare a jocului: " << e.what() << std::endl;
        return 1;
    }
    catch (const ScorInvalidException &e)
    {
        std::cerr << "Eroare de scor: " << e.what() << std::endl;
        return 2;
    }
    catch (const TipJucatorException &e)
    {
        std::cerr << "Eroare tip jucator: " << e.what() << std::endl;
        return 3;
    }
    catch (const std::ios_base::failure &e)
    {
        std::cerr << "Eroare I/O: " << e.what() << std::endl;
        return 4;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Eroare neașteptată: " << e.what() << std::endl;
        return 5;
    }
    catch (...)
    {
        std::cerr << "Eroare necunoscută." << std::endl;
        return 6;
    }

    return 0;
}