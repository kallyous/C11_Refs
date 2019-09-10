#include <stdio.h>

#include "globals.h"
#include "argdefs.h"
#include "debug.h"

int main(int argc, byte* argv[])
{
    // Analiza argumentos recebidos
    parse_arguments(argc, argv);

    printf("Olá, mundo!\n");
    dfprint("DEBUG: Va se foder!\n");

    return 0;
}