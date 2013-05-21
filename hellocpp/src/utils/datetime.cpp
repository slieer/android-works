#include <cstdio>
#include <cstdlib>
#include <ctime>
#include<sys/types.h>
#include<sys/timeb.h>

/**
 * http://www.32133.com/labrary/98.html
 */
class DateTimeTest {
public:
	void timeTest(void) {
		long i = 10000000L;
		clock_t start, finish;
		double duration;
		/* 测量一个事件持续的时间*/
		printf("Time to do %ld empty loops is ", i);
		start = clock();
		while (i--)
			;
		finish = clock();
		duration = (double) (finish - start) / CLOCKS_PER_SEC;
		printf("%f seconds\n", duration);
		system("pause");
	}

	void ftimeTest(void) {
		struct timeb fStartTime;
		struct timeb fEndTime;

		ftime(&fStartTime);
		//work...
		ftime(&fEndTime);

		float temp = (float) (fEndTime.time - fStartTime.time);

		float temp1 = (float) (fEndTime.millitm - fStartTime.millitm) * 0.001;
		double dbTotalProcessTime = (float) (temp + temp1);

	}
};

