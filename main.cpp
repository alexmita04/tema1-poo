#include <iostream>
#include <vector>
#include "generated/include/Jucator.h"
#include "generated/include/Echipa.h"
#include "generated/include/Scor.h"
#include "generated/include/Joc.h"

int main()
{

    Joc joc_actual("echipe.txt", "jucatori.txt");
    joc_actual.start_game();

    return 0;
}