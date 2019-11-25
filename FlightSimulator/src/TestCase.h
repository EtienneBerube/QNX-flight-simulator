/*
 * TestCase.h
 *
 *	Description: Test case for the demo of ATC project.
 *			     Instantiate and use member array.
 *
 */

#ifndef SRC_TESTCASE_H_
#define SRC_TESTCASE_H_

/*
 * Class name: TestCase
 *
 * Description: Provides int array containing data of incoming aircraft provided by the radar.
 *
 * */
class TestCase {
public:
	//each line is an airplane: ID, speed_x, speed_y, speed_z, x, y, z, entry time.
	static int airplane_schedule[8];

	TestCase();
};

#endif /* SRC_TESTCASE_H_ */
