#ifndef __TABLE_H__
#define __TABLE_H__

#include "lzw.h"

int table_not_full = 1;
struct lzw_table_entry lzw_table[256];

void init_table();

int lookup(unsigned char, unsigned char, int*);

void addcode(unsigned char, unsigned char, int);

int not_code_in_table(unsigned char);

#endif
