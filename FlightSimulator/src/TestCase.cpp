/*
 * TestCase.cpp
 *
 *	Description: Test case for the demo of ATC project.
 *			     Instantiate and use member array.
 *
 */

#include "TestCase.h"

TestCase::TestCase() {

}

int TestCase::airplane_schedule[40] = {
	  //id, speedx, speed y, speed z, posx, posy, posz, entry time
		-1, -50, 0, 0, 55000, 30000, 10000, 13,
		1, 50, 0, 0, 53000, 30000, 10000, 14,
//		-1, -180, -446, -186, 41000, 100000, 6000, 31,
//		3, 474, -239, 428, 38000, 0, 14000, 44,
//		-1, -535, 520, 360, 95000, 100000, 1000, 49,
//		-1, -164, -593, -501, 83000, 100000, 12000, 67,
//		6, 512, 614, 520, 86000, -1571, 9000, 87,
//		7, -275, 153, -399, 47000, 100000, 12000, 103,
		8, -129, 525, -300, 92000, 100000, 1000, 16,
//		9, 437, 574, 339, 32000, 0, 8000, 129,
		10, 568, 538, 192, 50000, 0, 4000, 17,
		11, 347, 529, -599, 83000, -1799, 10000, 18};
//		12, -512, -482, 578, 35000, 100000, 4000, 142,
//		13, 619, -280, 194, 74000, 0, 10000, 157,
//		14, -141, 427, -321, 41000, 102251, 11000, 165,
//		15, -199, 242, -205, 56000, 100000, 4000, 172,
//		16, 315, -197, -365, 77000, 0, 1000, 187,
//		17, -138, 455, 602, 23000, 102290, 14000, 199,
//		18, -150, 557, -356, 38000, 100000, 1000, 204,
//		19, 194, 184, 598, 35000, 0, 2000, 221 };

