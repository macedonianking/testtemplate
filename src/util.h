#ifndef MAIN_UTIL_H
#define MAIN_UTIL_H

#include <stddef.h>

#define NARRAY(array) 	(sizeof(array)/sizeof(array[0]))
#define MIN(a, b) 		((a) > (b) ? (b) : (a))
#define MAX(a, b) 		((a) < (b) ? (b) : (a))

#define CONTAINER_OF(p, type, m) ({ \
	(type*)(((void*)p) - (void*)offsetof(type, m)); \
})

#ifndef MAX_BUFFER_SIZE
#define MAX_BUFFER_SIZE	1024
#endif

#endif // MAIN_UTIL_H
