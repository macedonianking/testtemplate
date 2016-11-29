#include "string_ext.h"

#include <stdlib.h>
#include <string.h>

int string_substr(char *dst, const char *src, int start, int len) {
	char *ptr;
	int n;

	ptr = dst;
	n = strlen(src);
	if (start < 0 || start >= n) {
		*ptr = '\0';
		return 0;
	}

	src += start;
	while (len-- && *src != '\0') {
		*ptr++ = *src++;
	}
	*ptr = '\0';

	return ptr - dst;
}

void string_deblank(char *str) {
	char *dst;

	dst = str;
	if (*dst == '\0') {
		return;
	}

	++str;
	while (*str != '\0') {
		if (!IS_CHAR_EMPTY(*str)) {
			*++dst = *str;
		} else if (!IS_CHAR_EMPTY(*dst)) {
			*++dst = ' ';
		}
		++str;
	}

	*dst = '\0';
}

char *string_find_char(const char *src, const char *chars) {
	const char *ptr;

	for (; *src != '\0'; ++src) {
		for (ptr = chars; *ptr != '\0' && *ptr != *src; ++ptr)
			;
		if (*ptr != '\0') {
			return (char*)src;
		}
	}
	return NULL;
}

char *string_find_substr(const char *str, const char *substr) {
	const char *p, *q;
	if (*substr == '\0') {
		return NULL;
	}

	for (; *str != '\0'; ++str) {
		for (p = str, q = substr;
			 *p != '\0' && *q != '\0' && *p == *q; ++p, ++q)
			;
		if (*q == '\0') {
			return (char *)str;
		}
	}
	return NULL;
}

static void string_strcpy(char *dst, const char *src) {
	while (*src != '\0') {
		*dst++ = *src++;
	}
	*dst = '\0';
}

int string_delete_substring(char *src, const char *substr) {
	int n, r;
	char *start;

	r = 0;
	n = strlen(substr);
	if (n == 0) {
		return r;
	}

	start = string_find_substr(src, substr);
	if (start != NULL) {
		string_strcpy(start, start + n);
		r = 1;
	}
	return r;
} 

void string_reverse(char *str) {
	char *p, *q;
	char t;

	p = str;
	q = str + strlen(str) - 1;
	for (; p < q; ++p, --q) {
		t = *p;
		*p = *q;
		*q = t;
	}
}

char *_s_strdup(const char *str) {
	char *dst;

	dst = (char*) malloc(strlen(str) + 1);
	if (dst != NULL) {
		strcpy(dst, str);
	}
	return dst;
}
