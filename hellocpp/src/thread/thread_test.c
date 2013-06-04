#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>

pthread_key_t key;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

/*
 * Project->Properties->C/C++Build->Settings
 * ->Tool Settings->GCC C++ Linker->Libraries
 * ->Libraries (-l) -> add :
 * pthread
 *
 * */
static unsigned long abc = 0;
static void* Test03(void*);

static void* Test01(void* ptr) {
	pthread_cleanup_push(Test03, NULL); /* push */
		while (1) {
			abc++;
			pthread_testcancel();
		}

		pthread_cleanup_pop(0);
		/* pop */
	return NULL;
}

static void* Test02(void* ptr) {
	while (1) {
		usleep(2);
		printf("2222cond_wait:abc=0x%08x\n", abc);
	}
	return NULL;
}

static void* Test03(void *p) {
	printf("Cancel point");
	return NULL;
}

int clang_thread_test_main(void) {
	int tid1, tid2;
	int ret;

	printf("Start:\n");

	ret = pthread_create(&tid1, NULL, Test01, NULL);
	printf("thread Id:%d", ret);
	ret = pthread_create(&tid2, NULL, Test02, NULL);
	printf("thread Id:%d", ret);

	usleep(6);
	return 0;
}
