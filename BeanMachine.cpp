#include <iostream>
#include <crtdbg.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
#ifdef _DEBUG
	// _CrtSetBreakAlloc(96);
	_onexit(_CrtDumpMemoryLeaks);
#endif

	//int* a=(int*)malloc(sizeof(int)*10);

	int ballAmount;
	int levelDrop;

	cout << "How many balls you wish to drop?\n";
	cin >> ballAmount;

	cout << "How many levels to drop them through?\n";
	cin >> levelDrop;

	int* finishingBuckets = (int*)malloc(sizeof(int) * ballAmount); //array of balls
	int* bucketCount = (int*)malloc(sizeof(int) * (levelDrop + 1)); //array to count balls in bucket

	srand((unsigned int)time(nullptr)); //random number generator

	for (int i = 0; i <= levelDrop; ++i) {
		bucketCount[i] = 0;
	}

	for (int i = 0; i < ballAmount; i++) { // iterate through each ball
		int ballPosition = 0; // starting position
		for (int level = 0; level < levelDrop; ++level) {
			int bounce = rand() % 2; // bounce left or right
			if (bounce == 1) { // 0 for left, 1 for right
				ballPosition++;
			}

		}

		finishingBuckets[i] = ballPosition;

		if (ballPosition <= levelDrop) {
			bucketCount[ballPosition]++;
		}
	}


	for (int i = 0; i < ballAmount; i++) {
		cout << "Ball " << (i + 1) << " finished in bucket " << finishingBuckets[i] << endl;
	}

	free(finishingBuckets);


	for (int i = 0; i <= levelDrop; i++) {
		cout << "Bucket " << i << ": " << bucketCount[i] << " balls\n";
	}

	free(bucketCount);

	return 0;
}