#include <iostream>
#include "include/Sportiv.h"
#include "include/Echipa.h"
#include "include/Scor.h"
#include "include/Joc.h"
#include "include/Exceptions.h"

int main()
{
    try
    {
        Joc joc_actual("echipe.txt", "sportivi_fotbal.txt", "sportivi_box.txt", "sportivi_inot.txt");
        joc_actual.start_game();
    }
    catch (const GameException &ex)
    {
        std::cerr << "Eroare: " << ex.what() << "\n";
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Eroare necunoscuta: " << ex.what() << "\n";
    }
    return 0;
}
