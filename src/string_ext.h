#ifndef MAIN_STRING_EXT_H
#define MAIN_STRING_EXT_H

#define IS_CHAR_EMPTY(ch) ({char _ch = (ch); _ch == '\n' || _ch == '\t' || _ch == ' ';})

int string_substr(char *dst, const char *src, int start, int len);

char *_s_strdup(const char *str);

void string_deblank(char *str);

char *string_find_char(const char *src, const char *chars);

char *string_find_substr(const char *src, const char *substr);

/**
 * Remove the first substr in the str string object.
 */
int string_delete_substring(char *str, const char *substr);

/*
 * Reverse the string contents.
 */
void string_reverse(char *str);

#endif // MAIN_STRING_EXT_H
