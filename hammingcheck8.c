#include <stdlib.h>
#include <stdio.h>
#include "postgres.h"
#include "fmgr.h"
#include "utils/array.h"

Datum hammingcheck8(PG_FUNCTION_ARGS);
PG_FUNCTION_INFO_V1(hammingcheck8);
Datum hammingcheck8(PG_FUNCTION_ARGS) {
  int64 w0 = PG_GETARG_INT64(0);
  int64 t0 = PG_GETARG_INT64(1);
  int64 r = PG_GETARG_INT16(2);
  int16 dist = 0;
  int i;
  int64 b = w0;
  int64 a = t0;
  for (i = 0; i < 8; ++i)
  {
     if((0x1 & a) ^ (0x1 & b)) ++dist;
     if((0x2 & a) ^ (0x2 & b)) ++dist;
     if((0x4 & a) ^ (0x4 & b)) ++dist;
     if((0x8 & a) ^ (0x8 & b)) ++dist;
     if((0x10 & a) ^ (0x10 & b)) ++dist;
     if((0x20 & a) ^ (0x20 & b)) ++dist;
     if((0x40 & a) ^ (0x40 & b)) ++dist;
     if((0x80 & a) ^ (0x80 & b)) ++dist;

      if(dist > r) {
	PG_RETURN_INT16(dist);
      }
      a = a >> 8;
      b = b >> 8;
  }
  PG_RETURN_INT16(dist);   
}
