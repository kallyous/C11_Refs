#ifndef DEBUG_H
#define DEBUG_H


void dfprint(const byte * format, ...);


void load_debug_setting(int argc, byte * argv[]);


unsigned long dump_to_file(const byte* file_name, const byte* buffer,
   unsigned long buffer_start, unsigned long buffer_end);


void dump_table(const byte* file_name, const byte* table[], unsigned long row_count, unsigned long row_length);


#endif //DEBUG_H
