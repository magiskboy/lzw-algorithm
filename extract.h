#ifndef __EXTRACT_H__
#define __EXTRACT_H__

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "lzw.h"

void lzw_extract(char*);

unsigned char outstring(unsigned char);

#endif
