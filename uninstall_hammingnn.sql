/* $PostgreSQL $ */

-- Adjust this setting to control where the objects get dropped.
SET search_path = public;

DROP FUNCTION hammingnn (smallint, int4);
DROP FUNCTION hammingball16 (smallint, int4);
DROP FUNCTION hammingcheck16(bigint, bigint, bigint, bigint,smallint);
DROP FUNCTION hammingcheck32(bigint, bigint, bigint, bigint,bigint, bigint, bigint, bigint, smallint);
