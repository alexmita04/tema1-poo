#ifndef SCOR_H
#define SCOR_H

#include <iostream>

class Scor
{
    int scor_actual;
    int cel_mai_bun_scor;
    int incercari;

public:
    Scor(int scor_actual_, int cel_mai_bun_scor_);

    friend std::ostream &operator<<(std::ostream &os, const Scor &scor);

    void set_scor_actual(int scor);
    void set_cel_mai_bun_scor(int scor);
    void set_incercari(int incercari_);
    int get_scor_actual();
    int get_cel_mai_bun_scor();
    int get_incercari();
};

#endif
