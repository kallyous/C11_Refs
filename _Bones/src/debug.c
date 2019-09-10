#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>

#include "globals.h"
#include "debug.h"


extern bool DEBUG;


void dfprint(const byte * format, ...)
{
    if (DEBUG) {
        va_list arglist; // Declara variavel do tipo va_list
        va_start( arglist, format ); // Aloca memória para a variável arglist
        vprintf( format, arglist ); // Usa função específica para dar print formatado com va_list's
        va_end( arglist ); // Libera memória
    }
}


void load_debug_setting(int argc, byte * argv[])
{
    DEBUG = false;
    if (argc > 1) {
        int i;
        for (i = 1; i < argc; i++)
            if (strcmp(argv[i], "--debug") == 0) DEBUG = true;
    }
    dfprint("DEBUG mode set.\n");
}


unsigned long dump_to_file(const byte* file_name, const byte* buffer,
   unsigned long buffer_start, unsigned long buffer_end)
{
    FILE* fptr = fopen(file_name, "wb");
    unsigned long result = fwrite(&(buffer[buffer_start]), sizeof(byte), buffer_end-buffer_start, fptr);
    fclose(fptr);
    return result;
}


void dump_table(const byte* file_name, const byte* table[], unsigned long row_count, unsigned long row_length)
{
    if (DEBUG)
    {
        FILE* fptr = fopen(file_name, "wb");
        if (fptr)
        {
            for (int rc=0; rc < row_count; rc++)
            {
                for (int rl=0; rl < row_length; rl++) fputc(table[rc][rl], fptr);
                fputc('\n', fptr);
            }
            fclose(fptr);
        }
    }
}
