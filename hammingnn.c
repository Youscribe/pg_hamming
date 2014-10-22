#include <stdlib.h>
#include <stdio.h>
#include "postgres.h"
#include "fmgr.h"
#include "utils/array.h"


#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

char c[9] = {1,8,28,56,70,56,28,8,1};
// buffer must have length >= sizeof(int) + 1
// Write to the buffer backwards so that the binary representation
// is in the correct order i.e.  the LSB is on the far right
// instead of the far left of the printed string
#define BUF_SIZE 9
/*char *int2bin(int16 a, char *buffer, int buf_size) {
    buffer[BUF_SIZE - 1] = '\0';
    buffer += (buf_size - 1);
    int  i;
    for (i = 7; i >= 0; i--) {
        *buffer-- = (a & 1) + '0';

        a >>= 1;
    }

    return buffer;
}*/
Datum hammingnn(PG_FUNCTION_ARGS);
PG_FUNCTION_INFO_V1(hammingnn);
/*int16* hammingnn(int q, int r);
int main() {
	 char buffer[BUF_SIZE];
	int r = 8;
	int16* arr = hammingnn(0x28, r);
	int i;	
	for(i=0;i<c[r];i++) {
		int2bin(arr[i], buffer, BUF_SIZE - 1);
		printf("a = %s\n", buffer);	
	}
	free(arr);
}*/
Datum hammingnn(PG_FUNCTION_ARGS) {
    int16   q = PG_GETARG_INT16(0);
    int32   r = PG_GETARG_INT32(0);
    int16* values = (int16*)palloc(c[r]*sizeof(int16));
    Oid element_type = get_fn_expr_argtype(fcinfo->flinfo, 0);
    int16       typlen;
    bool        typbyval;
    char        typalign;
    ArrayType* result;
    
    if(r == 0) {
    	values[0] = q;
	PG_RETURN_ARRAYTYPE_P(result);
    } else {
    if(r == 1) {
    	values[0] = q^0x1;
	values[1] = q^0x2;
	values[2] = q^0x4;
	values[3] = q^0x8;
	values[4] = q^0x10;
	values[5] = q^0x20;
	values[6] = q^0x40;
	values[7] = q^0x80;
	PG_RETURN_ARRAYTYPE_P(result);
    } else {
    if(r == 2) {
    	values[0] = q^0x3;
	values[1] = q^0x5;
	values[2] = q^0x9;
	values[3] = q^0x11;
	values[4] = q^0x21;
	values[5] = q^0x41;
	values[6] = q^0x81;
	values[7] = q^0x6;
	values[8] = q^0xA;
	values[9] = q^0x12;
	values[10] = q^0x22;
	values[11] = q^0x42;
	values[12] = q^0x82;
	values[13] = q^0xC;
	values[14] = q^0x14;
	values[15] = q^0x24;
	values[16] = q^0x44;
	values[17] = q^0x84;
	values[18] = q^0x18;
	values[19] = q^0x28;
	values[20] = q^0x48;
	values[21] = q^0x88;
	values[22] = q^0x30;
	values[23] = q^0x50;
	values[24] = q^0x90;
	values[25] = q^0x60;
	values[26] = q^0xA0;
	values[27] = q^0xC0;
	PG_RETURN_ARRAYTYPE_P(result);
    } else {
	    if(r == 3) {
		values[0] = q^0x7;
		values[1] = q^0xB;
		values[2] = q^0x13;
		values[3] = q^0x23;
		values[4] = q^0x43;
		values[5] = q^0x83;
		values[6] = q^0xD;
		values[7] = q^0x15;
		values[8] = q^0x25;
		values[9] = q^0x45;
		values[10] = q^0x85;
		values[11] = q^0x19;
		values[12] = q^0x29;
		values[13] = q^0x49;
		values[14] = q^0x89;
		values[15] = q^0x31;
		values[16] = q^0x51;
		values[17] = q^0x91;
		values[18] = q^0x61;
		values[19] = q^0xA1;
		values[20] = q^0xC1;
		values[21] = q^0xE;
		values[22] = q^0x16;
		values[23] = q^0x26;
		values[24] = q^0x46;
		values[25] = q^0x86;
		values[26] = q^0x1A;
		values[27] = q^0x2A;
		values[28] = q^0x4A;
		values[29] = q^0x8A;
		values[30] = q^0x32;
		values[31] = q^0x52;
		values[32] = q^0x92;
		values[33] = q^0x62;
		values[34] = q^0xA2;
		values[35] = q^0xC2;
		values[36] = q^0x1C;
		values[37] = q^0x2C;
		values[38] = q^0x4C;
		values[39] = q^0x8C;
		values[40] = q^0x34;
		values[41] = q^0x54;
		values[42] = q^0x94;
		values[43] = q^0x64;
		values[44] = q^0xA4;
		values[45] = q^0xC4;
		values[46] = q^0x38;
		values[47] = q^0x58;
		values[48] = q^0x98;
		values[49] = q^0x68;
		values[50] = q^0xA8;
		values[51] = q^0xC8;
		values[52] = q^0x70;
		values[53] = q^0xB0;
		values[54] = q^0xD0;
		values[56] = q^0xE0;
		PG_RETURN_ARRAYTYPE_P(result);
	    } else {

	    if(r == 4) {
		values[0] = q^0xF;
		values[1] = q^0x17;
		values[2] = q^0x27;
		values[3] = q^0x47;
		values[4] = q^0x87;
		values[5] = q^0x1B;
		values[6] = q^0x2B;
		values[7] = q^0x4B;
		values[8] = q^0x8B;
		values[9] = q^0x33;
		values[10] = q^0x53;
		values[11] = q^0x93;
		values[12] = q^0x63;
		values[13] = q^0xA3;
		values[14] = q^0xC3;
		values[15] = q^0x1D;
		values[16] = q^0x2D;
		values[17] = q^0x4D;
		values[18] = q^0x8D;
		values[19] = q^0x35;
		values[20] = q^0x55;
		values[21] = q^0x95;
		values[22] = q^0x65;
		values[23] = q^0xA5;
		values[24] = q^0xC5;
		values[25] = q^0x39;
		values[26] = q^0x59;
		values[27] = q^0x99;
		values[28] = q^0x69;
		values[29] = q^0xA9;
		values[30] = q^0xC9;
		values[31] = q^0x71;
		values[32] = q^0xB1;
		values[33] = q^0xD1;
		values[34] = q^0xE1;
		values[35] = q^0x1E;
		values[36] = q^0x2E;
		values[37] = q^0x4E;
		values[38] = q^0x8E;
		values[39] = q^0x36;
		values[40] = q^0x56;
		values[41] = q^0x96;
		values[42] = q^0x66;
		values[43] = q^0xA6;
		values[44] = q^0xC6;
		values[45] = q^0x3A;
		values[46] = q^0x5A;
		values[47] = q^0x9A;
		values[48] = q^0x6A;
		values[49] = q^0xAA;
		values[50] = q^0xCA;
		values[51] = q^0x72;
		values[52] = q^0xB2;
		values[53] = q^0xD2;
		values[54] = q^0xE2;
		values[56] = q^0x3C;
		values[57] = q^0x5C;
		values[58] = q^0x9C;
		values[59] = q^0x6C;
		values[60] = q^0xAC;
		values[61] = q^0xCC;
		values[62] = q^0x74;
		values[63] = q^0xB4;
		values[64] = q^0xD4;
		values[65] = q^0xE4;
		values[66] = q^0x78;
		values[67] = q^0xB8;
		values[68] = q^0xD8;
		values[69] = q^0xE8;
		values[70] = q^0xF0;
		PG_RETURN_ARRAYTYPE_P(result);
	    } else {
		    if(r == 5) {
			values[0] = q^(0x7^0xFF);
			values[1] = q^(0xB^0xFF);
			values[2] = q^(0x13^0xFF);
			values[3] = q^(0x23^0xFF);
			values[4] = q^(0x43^0xFF);
			values[5] = q^(0x83^0xFF);
			values[6] = q^(0xD^0xFF);
			values[7] = q^(0x15^0xFF);
			values[8] = q^(0x25^0xFF);
			values[9] = q^(0x45^0xFF);
			values[10] = q^(0x85^0xFF);
			values[11] = q^(0x19^0xFF);
			values[12] = q^(0x29^0xFF);
			values[13] = q^(0x49^0xFF);
			values[14] = q^(0x89^0xFF);
			values[15] = q^(0x31^0xFF);
			values[16] = q^(0x51^0xFF);
			values[17] = q^(0x91^0xFF);
			values[18] = q^(0x61^0xFF);
			values[19] = q^(0xA1^0xFF);
			values[20] = q^(0xC1^0xFF);
			values[21] = q^(0xE^0xFF);
			values[22] = q^(0x16^0xFF);
			values[23] = q^(0x26^0xFF);
			values[24] = q^(0x46^0xFF);
			values[25] = q^(0x86^0xFF);
			values[26] = q^(0x1A^0xFF);
			values[27] = q^(0x2A^0xFF);
			values[28] = q^(0x4A^0xFF);
			values[29] = q^(0x8A^0xFF);
			values[30] = q^(0x32^0xFF);
			values[31] = q^(0x52^0xFF);
			values[32] = q^(0x92^0xFF);
			values[33] = q^(0x62^0xFF);
			values[34] = q^(0xA2^0xFF);
			values[35] = q^(0xC2^0xFF);
			values[36] = q^(0x1C^0xFF);
			values[37] = q^(0x2C^0xFF);
			values[38] = q^(0x4C^0xFF);
			values[39] = q^(0x8C^0xFF);
			values[40] = q^(0x34^0xFF);
			values[41] = q^(0x54^0xFF);
			values[42] = q^(0x94^0xFF);
			values[43] = q^(0x64^0xFF);
			values[44] = q^(0xA4^0xFF);
			values[45] = q^(0xC4^0xFF);
			values[46] = q^(0x38^0xFF);
			values[47] = q^(0x58^0xFF);
			values[48] = q^(0x98^0xFF);
			values[49] = q^(0x68^0xFF);
			values[50] = q^(0xA8^0xFF);
			values[51] = q^(0xC8^0xFF);
			values[52] = q^(0x70^0xFF);
			values[53] = q^(0xB0^0xFF);
			values[54] = q^(0xD0^0xFF);
			values[56] = q^(0xE0^0xFF);
			PG_RETURN_ARRAYTYPE_P(result);
		    } else {
			    if(r == 6) {
			    	values[0] = q^(0x3^0xFF);
				values[1] = q^(0x5^0xFF);
				values[2] = q^(0x9^0xFF);
				values[3] = q^(0x11^0xFF);
				values[4] = q^(0x21^0xFF);
				values[5] = q^(0x41^0xFF);
				values[6] = q^(0x81^0xFF);
				values[7] = q^(0x6^0xFF);
				values[8] = q^(0xA^0xFF);
				values[9] = q^(0x12^0xFF);
				values[10] = q^(0x22^0xFF);
				values[11] = q^(0x42^0xFF);
				values[12] = q^(0x82^0xFF);
				values[13] = q^(0xC^0xFF);
				values[14] = q^(0x14^0xFF);
				values[15] = q^(0x24^0xFF);
				values[16] = q^(0x44^0xFF);
				values[17] = q^(0x84^0xFF);
				values[18] = q^(0x18^0xFF);
				values[19] = q^(0x28^0xFF);
				values[20] = q^(0x48^0xFF);
				values[21] = q^(0x88^0xFF);
				values[22] = q^(0x30^0xFF);
				values[23] = q^(0x50^0xFF);
				values[24] = q^(0x90^0xFF);
				values[25] = q^(0x60^0xFF);
				values[26] = q^(0xA0^0xFF);
				values[27] = q^(0xC0^0xFF);
				PG_RETURN_ARRAYTYPE_P(result);
			    } else {
				    if(r == 7) {
				    	values[0] = q^(0x1^0xFF);
					values[1] = q^(0x2^0xFF);
					values[2] = q^(0x4^0xFF);
					values[3] = q^(0x8^0xFF);
					values[4] = q^(0x10^0xFF);
					values[5] = q^(0x20^0xFF);
					values[6] = q^(0x40^0xFF);
					values[7] = q^(0x80^0xFF);
					PG_RETURN_ARRAYTYPE_P(result);
				    } else {
					    if(r == 8) {
					    	values[0] = q^0xFF;
						PG_RETURN_ARRAYTYPE_P(result);
					    } else
					    {
					    	PG_RETURN_ARRAYTYPE_P(result);
					    }
				    }
			    }
		     }
		}
	    }
	}
    }
}
    get_typlenbyvalalign(element_type, &typlen, &typbyval, &typalign);
    result = construct_array(
	(Datum*) values,
	c[r],
	element_type,
	typlen,
	typbyval,
	typalign 
	);
	PG_RETURN_ARRAYTYPE_P(result);
}

/*int16* hammingnn(int q, int r) {    
    int16* values_ = (int16*)palloc(VARHDRSZ + c[r]*sizeof(int16));
    int16* values = &values_[2];
    if(r == 0) {
    	values[0] = q;
	return values;
    }
    if(r == 1) {
    	values[0] = q^0x1;
	values[1] = q^0x2;
	values[2] = q^0x4;
	values[3] = q^0x8;
	values[4] = q^0x10;
	values[5] = q^0x20;
	values[6] = q^0x40;
	values[7] = q^0x80;
	return values;
    }
    if(r == 2) {
    	values[0] = q^0x3;
	values[1] = q^0x5;
	values[2] = q^0x9;
	values[3] = q^0x11;
	values[4] = q^0x21;
	values[5] = q^0x41;
	values[6] = q^0x81;
	values[7] = q^0x6;
	values[8] = q^0xA;
	values[9] = q^0x12;
	values[10] = q^0x22;
	values[11] = q^0x42;
	values[12] = q^0x82;
	values[13] = q^0xC;
	values[14] = q^0x14;
	values[15] = q^0x24;
	values[16] = q^0x44;
	values[17] = q^0x84;
	values[18] = q^0x18;
	values[19] = q^0x28;
	values[20] = q^0x48;
	values[21] = q^0x88;
	values[22] = q^0x30;
	values[23] = q^0x50;
	values[24] = q^0x90;
	values[25] = q^0x60;
	values[26] = q^0xA0;
	values[27] = q^0xC0;
	return values;
    }
    if(r == 3) {
	values[0] = q^0x7;
	values[1] = q^0xB;
	values[2] = q^0x13;
	values[3] = q^0x23;
	values[4] = q^0x43;
	values[5] = q^0x83;
	values[6] = q^0xD;
	values[7] = q^0x15;
	values[8] = q^0x25;
	values[9] = q^0x45;
	values[10] = q^0x85;
	values[11] = q^0x19;
	values[12] = q^0x29;
	values[13] = q^0x49;
	values[14] = q^0x89;
	values[15] = q^0x31;
	values[16] = q^0x51;
	values[17] = q^0x91;
	values[18] = q^0x61;
	values[19] = q^0xA1;
	values[20] = q^0xC1;
	values[21] = q^0xE;
	values[22] = q^0x16;
	values[23] = q^0x26;
	values[24] = q^0x46;
	values[25] = q^0x86;
	values[26] = q^0x1A;
	values[27] = q^0x2A;
	values[28] = q^0x4A;
	values[29] = q^0x8A;
	values[30] = q^0x32;
	values[31] = q^0x52;
	values[32] = q^0x92;
	values[33] = q^0x62;
	values[34] = q^0xA2;
	values[35] = q^0xC2;
	values[36] = q^0x1C;
	values[37] = q^0x2C;
	values[38] = q^0x4C;
	values[39] = q^0x8C;
	values[40] = q^0x34;
	values[41] = q^0x54;
	values[42] = q^0x94;
	values[43] = q^0x64;
	values[44] = q^0xA4;
	values[45] = q^0xC4;
	values[46] = q^0x38;
	values[47] = q^0x58;
	values[48] = q^0x98;
	values[49] = q^0x68;
	values[50] = q^0xA8;
	values[51] = q^0xC8;
	values[52] = q^0x70;
	values[53] = q^0xB0;
	values[54] = q^0xD0;
	values[56] = q^0xE0;
	return values;
    }

    if(r == 4) {
	values[0] = q^0xF;
	values[1] = q^0x17;
	values[2] = q^0x27;
	values[3] = q^0x47;
	values[4] = q^0x87;
	values[5] = q^0x1B;
	values[6] = q^0x2B;
	values[7] = q^0x4B;
	values[8] = q^0x8B;
	values[9] = q^0x33;
	values[10] = q^0x53;
	values[11] = q^0x93;
	values[12] = q^0x63;
	values[13] = q^0xA3;
	values[14] = q^0xC3;
	values[15] = q^0x1D;
	values[16] = q^0x2D;
	values[17] = q^0x4D;
	values[18] = q^0x8D;
	values[19] = q^0x35;
	values[20] = q^0x55;
	values[21] = q^0x95;
	values[22] = q^0x65;
	values[23] = q^0xA5;
	values[24] = q^0xC5;
	values[25] = q^0x39;
	values[26] = q^0x59;
	values[27] = q^0x99;
	values[28] = q^0x69;
	values[29] = q^0xA9;
	values[30] = q^0xC9;
	values[31] = q^0x71;
	values[32] = q^0xB1;
	values[33] = q^0xD1;
	values[34] = q^0xE1;
	values[35] = q^0x1E;
	values[36] = q^0x2E;
	values[37] = q^0x4E;
	values[38] = q^0x8E;
	values[39] = q^0x36;
	values[40] = q^0x56;
	values[41] = q^0x96;
	values[42] = q^0x66;
	values[43] = q^0xA6;
	values[44] = q^0xC6;
	values[45] = q^0x3A;
	values[46] = q^0x5A;
	values[47] = q^0x9A;
	values[48] = q^0x6A;
	values[49] = q^0xAA;
	values[50] = q^0xCA;
	values[51] = q^0x72;
	values[52] = q^0xB2;
	values[53] = q^0xD2;
	values[54] = q^0xE2;
	values[56] = q^0x3C;
	values[57] = q^0x5C;
	values[58] = q^0x9C;
	values[59] = q^0x6C;
	values[60] = q^0xAC;
	values[61] = q^0xCC;
	values[62] = q^0x74;
	values[63] = q^0xB4;
	values[64] = q^0xD4;
	values[65] = q^0xE4;
	values[66] = q^0x78;
	values[67] = q^0xB8;
	values[68] = q^0xD8;
	values[69] = q^0xE8;
	values[70] = q^0xF0;
	return values;
    }
    if(r == 5) {
	values[0] = q^(0x7^0xFF);
	values[1] = q^(0xB^0xFF);
	values[2] = q^(0x13^0xFF);
	values[3] = q^(0x23^0xFF);
	values[4] = q^(0x43^0xFF);
	values[5] = q^(0x83^0xFF);
	values[6] = q^(0xD^0xFF);
	values[7] = q^(0x15^0xFF);
	values[8] = q^(0x25^0xFF);
	values[9] = q^(0x45^0xFF);
	values[10] = q^(0x85^0xFF);
	values[11] = q^(0x19^0xFF);
	values[12] = q^(0x29^0xFF);
	values[13] = q^(0x49^0xFF);
	values[14] = q^(0x89^0xFF);
	values[15] = q^(0x31^0xFF);
	values[16] = q^(0x51^0xFF);
	values[17] = q^(0x91^0xFF);
	values[18] = q^(0x61^0xFF);
	values[19] = q^(0xA1^0xFF);
	values[20] = q^(0xC1^0xFF);
	values[21] = q^(0xE^0xFF);
	values[22] = q^(0x16^0xFF);
	values[23] = q^(0x26^0xFF);
	values[24] = q^(0x46^0xFF);
	values[25] = q^(0x86^0xFF);
	values[26] = q^(0x1A^0xFF);
	values[27] = q^(0x2A^0xFF);
	values[28] = q^(0x4A^0xFF);
	values[29] = q^(0x8A^0xFF);
	values[30] = q^(0x32^0xFF);
	values[31] = q^(0x52^0xFF);
	values[32] = q^(0x92^0xFF);
	values[33] = q^(0x62^0xFF);
	values[34] = q^(0xA2^0xFF);
	values[35] = q^(0xC2^0xFF);
	values[36] = q^(0x1C^0xFF);
	values[37] = q^(0x2C^0xFF);
	values[38] = q^(0x4C^0xFF);
	values[39] = q^(0x8C^0xFF);
	values[40] = q^(0x34^0xFF);
	values[41] = q^(0x54^0xFF);
	values[42] = q^(0x94^0xFF);
	values[43] = q^(0x64^0xFF);
	values[44] = q^(0xA4^0xFF);
	values[45] = q^(0xC4^0xFF);
	values[46] = q^(0x38^0xFF);
	values[47] = q^(0x58^0xFF);
	values[48] = q^(0x98^0xFF);
	values[49] = q^(0x68^0xFF);
	values[50] = q^(0xA8^0xFF);
	values[51] = q^(0xC8^0xFF);
	values[52] = q^(0x70^0xFF);
	values[53] = q^(0xB0^0xFF);
	values[54] = q^(0xD0^0xFF);
	values[56] = q^(0xE0^0xFF);
	return values;
    }
    if(r == 6) {
    	values[0] = q^(0x3^0xFF);
	values[1] = q^(0x5^0xFF);
	values[2] = q^(0x9^0xFF);
	values[3] = q^(0x11^0xFF);
	values[4] = q^(0x21^0xFF);
	values[5] = q^(0x41^0xFF);
	values[6] = q^(0x81^0xFF);
	values[7] = q^(0x6^0xFF);
	values[8] = q^(0xA^0xFF);
	values[9] = q^(0x12^0xFF);
	values[10] = q^(0x22^0xFF);
	values[11] = q^(0x42^0xFF);
	values[12] = q^(0x82^0xFF);
	values[13] = q^(0xC^0xFF);
	values[14] = q^(0x14^0xFF);
	values[15] = q^(0x24^0xFF);
	values[16] = q^(0x44^0xFF);
	values[17] = q^(0x84^0xFF);
	values[18] = q^(0x18^0xFF);
	values[19] = q^(0x28^0xFF);
	values[20] = q^(0x48^0xFF);
	values[21] = q^(0x88^0xFF);
	values[22] = q^(0x30^0xFF);
	values[23] = q^(0x50^0xFF);
	values[24] = q^(0x90^0xFF);
	values[25] = q^(0x60^0xFF);
	values[26] = q^(0xA0^0xFF);
	values[27] = q^(0xC0^0xFF);
	return values;
    }
    if(r == 7) {
    	values[0] = q^(0x1^0xFF);
	values[1] = q^(0x2^0xFF);
	values[2] = q^(0x4^0xFF);
	values[3] = q^(0x8^0xFF);
	values[4] = q^(0x10^0xFF);
	values[5] = q^(0x20^0xFF);
	values[6] = q^(0x40^0xFF);
	values[7] = q^(0x80^0xFF);
	return values;
    }
    if(r == 8) {
    	values[0] = q^0xFF;
	return values;
    }
    
}*/
