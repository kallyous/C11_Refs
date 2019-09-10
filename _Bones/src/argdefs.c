#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "globals.h"
#include "debug.h"
#include "argdefs.h"


extern byte* INPUT_FILE_NAME;
extern byte* OUTPUT_FILE_NAME;
extern byte OPERATION;


bool parse_arguments(int argc, byte * argv[])
{
    // Deteca flag de DEBUG nos argumentos recebidos
    load_debug_setting(argc, argv);

    if (argc < 2) {
        printf("Huffman O'Cool XVIII - Usos\n");
        printf("huffmanocool --pack input/file/path.txt\n");
        printf("huffmanocool --unpack input/file/path.txt.huff\n");
        printf("huffmanocool -p input/file/path.txt\n");
        printf("huffmanocool -u input/file/path.txt.huff\n");
        return false; }

    for (int i=0; i < argc; i++)
    {
        dfprint("Analizando argumento: '%s'\n", argv[i]);
        if (strcmp(argv[i], "--pack")==0 || strcmp(argv[i], "-p")==0) {
            if (argc < i+1) {
                printf("Faltando caminho do arquivo após argumento --pack\n");
                return false; }
            INPUT_FILE_NAME = (byte*)malloc((strlen(argv[i+1]) * sizeof(byte))+1);
            strcpy(INPUT_FILE_NAME, argv[i+1]);
            OPERATION = 'P'; // --pack
            dfprint("A compactar arquivo: '%s'\n", INPUT_FILE_NAME);
        }
        else if (strcmp(argv[i], "--unpack")==0 || strcmp(argv[i], "-u")==0) {
            if (argc < i+1) {
                printf("Faltando caminho do arquivo após argumento --unpack\n");
                return false; }
            INPUT_FILE_NAME = (byte*)malloc((strlen(argv[i+1]) * sizeof(byte))+1);
            strcpy(INPUT_FILE_NAME, argv[i+1]);
            OPERATION = 'U'; // --unpack
            dfprint("A descompactar arquivo: '%s'\n", INPUT_FILE_NAME);
        }
    }

    dfprint("Arguments parsed.\n\n");

    return true;
}
