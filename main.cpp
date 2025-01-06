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

        Joc joc_actual("echipe.txt", "sportivi_fotbal.txt", "sportivi_box.txt", "sportivi_inot.txt");

        joc_actual.start_game();
    }
    catch (const JocException &e)
    {
        std::cerr << "Eroare specifică: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Eroare neașteptată: " << e.what() << std::endl;
        return 2;
    }
    catch (...)
    {
        std::cerr << "Eroare necunoscută a apărut." << std::endl;
        return 3;
    }

    return 0;
}