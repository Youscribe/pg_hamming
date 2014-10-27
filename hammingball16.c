#include <stdlib.h>
#include <stdio.h>
#include "postgres.h"
#include "fmgr.h"
#include "utils/array.h"

Datum hammingball16(PG_FUNCTION_ARGS);
PG_FUNCTION_INFO_V1(hammingball16);

int global_index = 0;
short global_value = 0;
short bits[16] = {0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80,0x100,0x200,0x400,0x800,0x1000,0x2000,0x4000,0x8000};
void rec_combination(char startbit, char nb_bits_picks, Datum * memwrite);
void rec_combination(char startbit, char nb_bits_picks, Datum * memwrite) {	
	if(nb_bits_picks != 0) {
		if(startbit != 7) {
			short tmp_value;
			tmp_value = global_value;
			//check if we can afford to not switch the bit
			if(startbit >= nb_bits_picks) {
				rec_combination(startbit-1, nb_bits_picks, memwrite);
			}
			global_value = global_value^bits[startbit];
			rec_combination(startbit-1, nb_bits_picks-1, memwrite);
			global_value = tmp_value;
		} else {
			    if(nb_bits_picks == 1) {
			    	memwrite[global_index++] = global_value^0x1; 
				memwrite[global_index++] = global_value^0x2; 
				memwrite[global_index++] = global_value^0x4; 
				memwrite[global_index++] = global_value^0x8;
				memwrite[global_index++] = global_value^0x10;
				memwrite[global_index++] = global_value^0x20; 
				memwrite[global_index++] = global_value^0x40; 
				memwrite[global_index++] = global_value^0x80;
			    } else {
				    if(nb_bits_picks == 2) {
				    	memwrite[global_index++] = global_value^0x3;
					memwrite[global_index++] = global_value^0x5;
					memwrite[global_index++] = global_value^0x9;
					memwrite[global_index++] = global_value^0x11;
					memwrite[global_index++] = global_value^0x21;
					memwrite[global_index++] = global_value^0x41;
					memwrite[global_index++] = global_value^0x81;
					memwrite[global_index++] = global_value^0x6;
					memwrite[global_index++] = global_value^0xA;
					memwrite[global_index++] = global_value^0x12;
					memwrite[global_index++] = global_value^0x22;
					memwrite[global_index++] = global_value^0x42;
					memwrite[global_index++] = global_value^0x82;
					memwrite[global_index++] = global_value^0xC;
					memwrite[global_index++] = global_value^0x14;
					memwrite[global_index++] = global_value^0x24;
					memwrite[global_index++] = global_value^0x44;
					memwrite[global_index++] = global_value^0x84;
					memwrite[global_index++] = global_value^0x18;
					memwrite[global_index++] = global_value^0x28;
					memwrite[global_index++] = global_value^0x48;
					memwrite[global_index++] = global_value^0x88;
					memwrite[global_index++] = global_value^0x30;
					memwrite[global_index++] = global_value^0x50;
					memwrite[global_index++] = global_value^0x90;
					memwrite[global_index++] = global_value^0x60;
					memwrite[global_index++] = global_value^0xA0;
					memwrite[global_index++] = global_value^0xC0;
				    } else {
					    if(nb_bits_picks == 3) {
						memwrite[global_index++] = global_value^0x7;
						memwrite[global_index++] = global_value^0xB;
						memwrite[global_index++] = global_value^0x13;
						memwrite[global_index++] = global_value^0x23;
						memwrite[global_index++] = global_value^0x43;
						memwrite[global_index++] = global_value^0x83;
						memwrite[global_index++] = global_value^0xD;
						memwrite[global_index++] = global_value^0x15;
						memwrite[global_index++] = global_value^0x25;
						memwrite[global_index++] = global_value^0x45;
						memwrite[global_index++] = global_value^0x85;
						memwrite[global_index++] = global_value^0x19;
						memwrite[global_index++] = global_value^0x29;
						memwrite[global_index++] = global_value^0x49;
						memwrite[global_index++] = global_value^0x89;
						memwrite[global_index++] = global_value^0x31;
						memwrite[global_index++] = global_value^0x51;
						memwrite[global_index++] = global_value^0x91;
						memwrite[global_index++] = global_value^0x61;
						memwrite[global_index++] = global_value^0xA1;
						memwrite[global_index++] = global_value^0xC1;
						memwrite[global_index++] = global_value^0xE;
						memwrite[global_index++] = global_value^0x16;
						memwrite[global_index++] = global_value^0x26;
						memwrite[global_index++] = global_value^0x46;
						memwrite[global_index++] = global_value^0x86;
						memwrite[global_index++] = global_value^0x1A;
						memwrite[global_index++] = global_value^0x2A;
						memwrite[global_index++] = global_value^0x4A;
						memwrite[global_index++] = global_value^0x8A;
						memwrite[global_index++] = global_value^0x32;
						memwrite[global_index++] = global_value^0x52;
						memwrite[global_index++] = global_value^0x92;
						memwrite[global_index++] = global_value^0x62;
						memwrite[global_index++] = global_value^0xA2;
						memwrite[global_index++] = global_value^0xC2;
						memwrite[global_index++] = global_value^0x1C;
						memwrite[global_index++] = global_value^0x2C;
						memwrite[global_index++] = global_value^0x4C;
						memwrite[global_index++] = global_value^0x8C;
						memwrite[global_index++] = global_value^0x34;
						memwrite[global_index++] = global_value^0x54;
						memwrite[global_index++] = global_value^0x94;
						memwrite[global_index++] = global_value^0x64;
						memwrite[global_index++] = global_value^0xA4;
						memwrite[global_index++] = global_value^0xC4;
						memwrite[global_index++] = global_value^0x38;
						memwrite[global_index++] = global_value^0x58;
						memwrite[global_index++] = global_value^0x98;
						memwrite[global_index++] = global_value^0x68;
						memwrite[global_index++] = global_value^0xA8;
						memwrite[global_index++] = global_value^0xC8;
						memwrite[global_index++] = global_value^0x70;
						memwrite[global_index++] = global_value^0xB0;
						memwrite[global_index++] = global_value^0xD0;
						memwrite[global_index++] = global_value^0xE0;
					    } else {

						    if(nb_bits_picks == 4) {
							memwrite[global_index++] = global_value^0xF;
							memwrite[global_index++] = global_value^0x17;
							memwrite[global_index++] = global_value^0x27;
							memwrite[global_index++] = global_value^0x47;
							memwrite[global_index++] = global_value^0x87;
							memwrite[global_index++] = global_value^0x1B;
							memwrite[global_index++] = global_value^0x2B;
							memwrite[global_index++] = global_value^0x4B;
							memwrite[global_index++] = global_value^0x8B;
							memwrite[global_index++] = global_value^0x33;
							memwrite[global_index++] = global_value^0x53;
							memwrite[global_index++] = global_value^0x93;
							memwrite[global_index++] = global_value^0x63;
							memwrite[global_index++] = global_value^0xA3;
							memwrite[global_index++] = global_value^0xC3;
							memwrite[global_index++] = global_value^0x1D;
							memwrite[global_index++] = global_value^0x2D;
							memwrite[global_index++] = global_value^0x4D;
							memwrite[global_index++] = global_value^0x8D;
							memwrite[global_index++] = global_value^0x35;
							memwrite[global_index++] = global_value^0x55;
							memwrite[global_index++] = global_value^0x95;
							memwrite[global_index++] = global_value^0x65;
							memwrite[global_index++] = global_value^0xA5;
							memwrite[global_index++] = global_value^0xC5;
							memwrite[global_index++] = global_value^0x39;
							memwrite[global_index++] = global_value^0x59;
							memwrite[global_index++] = global_value^0x99;
							memwrite[global_index++] = global_value^0x69;
							memwrite[global_index++] = global_value^0xA9;
							memwrite[global_index++] = global_value^0xC9;
							memwrite[global_index++] = global_value^0x71;
							memwrite[global_index++] = global_value^0xB1;
							memwrite[global_index++] = global_value^0xD1;
							memwrite[global_index++] = global_value^0xE1;
							memwrite[global_index++] = global_value^0x1E;
							memwrite[global_index++] = global_value^0x2E;
							memwrite[global_index++] = global_value^0x4E;
							memwrite[global_index++] = global_value^0x8E;
							memwrite[global_index++] = global_value^0x36;
							memwrite[global_index++] = global_value^0x56;
							memwrite[global_index++] = global_value^0x96;
							memwrite[global_index++] = global_value^0x66;
							memwrite[global_index++] = global_value^0xA6;
							memwrite[global_index++] = global_value^0xC6;
							memwrite[global_index++] = global_value^0x3A;
							memwrite[global_index++] = global_value^0x5A;
							memwrite[global_index++] = global_value^0x9A;
							memwrite[global_index++] = global_value^0x6A;
							memwrite[global_index++] = global_value^0xAA;
							memwrite[global_index++] = global_value^0xCA;
							memwrite[global_index++] = global_value^0x72;
							memwrite[global_index++] = global_value^0xB2;
							memwrite[global_index++] = global_value^0xD2;
							memwrite[global_index++] = global_value^0xE2;
							memwrite[global_index++] = global_value^0x3C;
							memwrite[global_index++] = global_value^0x5C;
							memwrite[global_index++] = global_value^0x9C;
							memwrite[global_index++] = global_value^0x6C;
							memwrite[global_index++] = global_value^0xAC;
							memwrite[global_index++] = global_value^0xCC;
							memwrite[global_index++] = global_value^0x74;
							memwrite[global_index++] = global_value^0xB4;
							memwrite[global_index++] = global_value^0xD4;
							memwrite[global_index++] = global_value^0xE4;
							memwrite[global_index++] = global_value^0x78;
							memwrite[global_index++] = global_value^0xB8;
							memwrite[global_index++] = global_value^0xD8;
							memwrite[global_index++] = global_value^0xE8;
							memwrite[global_index++] = global_value^0xF0;
						    } else {
							    if(nb_bits_picks == 5) {
								memwrite[global_index++] = global_value^(0x7^0xFF);
								memwrite[global_index++] = global_value^(0xB^0xFF);
								memwrite[global_index++] = global_value^(0x13^0xFF);
								memwrite[global_index++] = global_value^(0x23^0xFF);
								memwrite[global_index++] = global_value^(0x43^0xFF);
								memwrite[global_index++] = global_value^(0x83^0xFF);
								memwrite[global_index++] = global_value^(0xD^0xFF);
								memwrite[global_index++] = global_value^(0x15^0xFF);
								memwrite[global_index++] = global_value^(0x25^0xFF);
								memwrite[global_index++] = global_value^(0x45^0xFF);
								memwrite[global_index++] = global_value^(0x85^0xFF);
								memwrite[global_index++] = global_value^(0x19^0xFF);
								memwrite[global_index++] = global_value^(0x29^0xFF);
								memwrite[global_index++] = global_value^(0x49^0xFF);
								memwrite[global_index++] = global_value^(0x89^0xFF);
								memwrite[global_index++] = global_value^(0x31^0xFF);
								memwrite[global_index++] = global_value^(0x51^0xFF);
								memwrite[global_index++] = global_value^(0x91^0xFF);
								memwrite[global_index++] = global_value^(0x61^0xFF);
								memwrite[global_index++] = global_value^(0xA1^0xFF);
								memwrite[global_index++] = global_value^(0xC1^0xFF);
								memwrite[global_index++] = global_value^(0xE^0xFF);
								memwrite[global_index++] = global_value^(0x16^0xFF);
								memwrite[global_index++] = global_value^(0x26^0xFF);
								memwrite[global_index++] = global_value^(0x46^0xFF);
								memwrite[global_index++] = global_value^(0x86^0xFF);
								memwrite[global_index++] = global_value^(0x1A^0xFF);
								memwrite[global_index++] = global_value^(0x2A^0xFF);
								memwrite[global_index++] = global_value^(0x4A^0xFF);
								memwrite[global_index++] = global_value^(0x8A^0xFF);
								memwrite[global_index++] = global_value^(0x32^0xFF);
								memwrite[global_index++] = global_value^(0x52^0xFF);
								memwrite[global_index++] = global_value^(0x92^0xFF);
								memwrite[global_index++] = global_value^(0x62^0xFF);
								memwrite[global_index++] = global_value^(0xA2^0xFF);
								memwrite[global_index++] = global_value^(0xC2^0xFF);
								memwrite[global_index++] = global_value^(0x1C^0xFF);
								memwrite[global_index++] = global_value^(0x2C^0xFF);
								memwrite[global_index++] = global_value^(0x4C^0xFF);
								memwrite[global_index++] = global_value^(0x8C^0xFF);
								memwrite[global_index++] = global_value^(0x34^0xFF);
								memwrite[global_index++] = global_value^(0x54^0xFF);
								memwrite[global_index++] = global_value^(0x94^0xFF);
								memwrite[global_index++] = global_value^(0x64^0xFF);
								memwrite[global_index++] = global_value^(0xA4^0xFF);
								memwrite[global_index++] = global_value^(0xC4^0xFF);
								memwrite[global_index++] = global_value^(0x38^0xFF);
								memwrite[global_index++] = global_value^(0x58^0xFF);
								memwrite[global_index++] = global_value^(0x98^0xFF);
								memwrite[global_index++] = global_value^(0x68^0xFF);
								memwrite[global_index++] = global_value^(0xA8^0xFF);
								memwrite[global_index++] = global_value^(0xC8^0xFF);
								memwrite[global_index++] = global_value^(0x70^0xFF);
								memwrite[global_index++] = global_value^(0xB0^0xFF);
								memwrite[global_index++] = global_value^(0xD0^0xFF);
								memwrite[global_index++] = global_value^(0xE0^0xFF);
							    } else {
								    if(nb_bits_picks == 6) {
								    	memwrite[global_index++] = global_value^(0x3^0xFF);
									memwrite[global_index++] = global_value^(0x5^0xFF);
									memwrite[global_index++] = global_value^(0x9^0xFF);
									memwrite[global_index++] = global_value^(0x11^0xFF);
									memwrite[global_index++] = global_value^(0x21^0xFF);
									memwrite[global_index++] = global_value^(0x41^0xFF);
									memwrite[global_index++] = global_value^(0x81^0xFF);
									memwrite[global_index++] = global_value^(0x6^0xFF);
									memwrite[global_index++] = global_value^(0xA^0xFF);
									memwrite[global_index++] = global_value^(0x12^0xFF);
									memwrite[global_index++] = global_value^(0x22^0xFF);
									memwrite[global_index++] = global_value^(0x42^0xFF);
									memwrite[global_index++] = global_value^(0x82^0xFF);
									memwrite[global_index++] = global_value^(0xC^0xFF);
									memwrite[global_index++] = global_value^(0x14^0xFF);
									memwrite[global_index++] = global_value^(0x24^0xFF);
									memwrite[global_index++] = global_value^(0x44^0xFF);
									memwrite[global_index++] = global_value^(0x84^0xFF);
									memwrite[global_index++] = global_value^(0x18^0xFF);
									memwrite[global_index++] = global_value^(0x28^0xFF);
									memwrite[global_index++] = global_value^(0x48^0xFF);
									memwrite[global_index++] = global_value^(0x88^0xFF);
									memwrite[global_index++] = global_value^(0x30^0xFF);
									memwrite[global_index++] = global_value^(0x50^0xFF);
									memwrite[global_index++] = global_value^(0x90^0xFF);
									memwrite[global_index++] = global_value^(0x60^0xFF);
									memwrite[global_index++] = global_value^(0xA0^0xFF);
									memwrite[global_index++] = global_value^(0xC0^0xFF);
								    } else {
									    if(nb_bits_picks == 7) {
									    	memwrite[global_index++] = global_value^(0x1^0xFF);
										memwrite[global_index++] = global_value^(0x2^0xFF);
										memwrite[global_index++] = global_value^(0x4^0xFF);
										memwrite[global_index++] = global_value^(0x8^0xFF);
										memwrite[global_index++] = global_value^(0x10^0xFF);
										memwrite[global_index++] = global_value^(0x20^0xFF);
										memwrite[global_index++] = global_value^(0x40^0xFF);
										memwrite[global_index++] = global_value^(0x80^0xFF);
									    } else {
										    if(nb_bits_picks == 8) {
										    	memwrite[global_index++] = global_value^0xFF;
										    }	
									    }
								    }
					 		      }
							}
						}
					}
				}			
			}
	} else {
		memwrite[global_index++] = global_value;	
	}
}
Datum hammingball16(PG_FUNCTION_ARGS) {
    //short c[17] = {1,16,120,560,1820,4368,8008,11440,12870,11440,8008,4368,1820,560,120,16,1};
    int c[17] = {1,17,137,697,2517,6885,14893,26333,39203,50643,58651,63019,64839,65399,65519,65535,65536};
    int16   q = PG_GETARG_INT16(0);
    int32   r = PG_GETARG_INT32(1);
    Datum* memwrite = palloc(c[r]*sizeof(Datum));
    Oid element_type = get_fn_expr_argtype(fcinfo->flinfo, 0);
    int16       typlen;
    bool        typbyval;
    char        typalign;
    ArrayType* result;
    int i;
    global_index = 0;
    for(i=0;i<=r;++i) {
	global_value = q;
    	rec_combination(15,i,memwrite);
    }
    get_typlenbyvalalign(element_type, &typlen, &typbyval, &typalign);
    result = construct_array(
	memwrite,
	c[r],
	element_type,
	typlen,
	typbyval,
	typalign 
	);
	PG_RETURN_ARRAYTYPE_P(result);
}
