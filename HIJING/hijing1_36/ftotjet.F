* $Id$
C
C
C
	FUNCTION FTOTJET(X)
#include "hiparnt.inc"
	OMG=OMG0(X)*HINT1(11)/HIPR1(31)/2.0
	FTOTJET=1.0-EXP(-2.0*OMG)
	RETURN
	END
