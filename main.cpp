#include <iostream>
#include <vector>
#include "include/Jucator.h"
#include "include/Echipa.h"
#include "include/Scor.h"
#include "include/Joc.h"

int main()
{

    Joc joc_actual("echipe.txt", "jucatori.txt");
    joc_actual.start_game();

    return 0;
}