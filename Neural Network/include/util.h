#ifndef UTIL_H_
#define UTIL_H_

#define ARRAY_LEN(arr) sizeof( (arr) ) / sizeof( (arr)[0] )
float rand_float(void);
float sigmoidf(float x);

#ifdef UTIL_IMPLEMENTATION_

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>



float rand_float(void)
{
	return (float)rand() / (float)RAND_MAX;
}

float sigmoidf(float x)
{
	return 1.0f / (1.0f + expf(-x));
}

#endif //UTIL_IMPLEMENTATION_
#endif //UTIL_H_
     
