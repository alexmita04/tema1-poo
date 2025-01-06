#include <iostream>
#include <vector>
#include "include/Sportiv.h"
#include "include/Echipa.h"
#include "include/Scor.h"
#include "include/Joc.h"

int main()
{

    Joc joc_actual("echipe.txt", "sportivi_fotbal.txt", "sportivi_box.txt", "sportivi_inot.txt");
    joc_actual.start_game();

    return 0;
}