#ifndef _UNIT_TEST_FRAMEWORK_H
#define _UNIT_TEST_FRAMEWORK_H

void TestSuite(void(*toRun)(), char testName[], int numOfRuns);
void TestSuiteRandom(void(*toRun)(), char testName[], int numOfRuns, int random1, int random2, int random3, int random4);
void testInfoOutput(char testName[80], char testInfo[]);
void assertTest(void *given, void *expected, char info[]);
void testPass(char info[]);
void testFail(char info[], void *given, void *expected);
void testSeparate();
void outputResults();
int randomSetup(int min, int max);

#endif
