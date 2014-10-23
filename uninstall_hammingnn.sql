/* $PostgreSQL $ */

-- Adjust this setting to control where the objects get dropped.
SET search_path = public;

DROP FUNCTION hammingnn (smallint, int4);
DROP FUNCTION hammingcheck (smallint, smallint[], smallint[], smallint);
