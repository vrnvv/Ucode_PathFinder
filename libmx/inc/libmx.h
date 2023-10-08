#pragma once


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>
#include <limits.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <malloc/malloc.h>

typedef struct s_list
{
    void *data;
    struct s_list *next;
}              t_list;

void mx_printchar(char c);
int mx_strlen(const char *s);
void mx_printstr(const char *s);
void mx_printint(int n);
double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
char *mx_nbr_to_hex(unsigned long nbr);
char *mx_strnew(const int size);
unsigned long mx_hex_to_nbr(const char *hex);
bool mx_isalpha(int c);
bool mx_isdigit(int c);
bool mx_islower(int c);
bool mx_isupper(int c);
void mx_foreach(const int *arr, int size, void (*f)(int));
void mx_print_unicode(wchar_t c);
int mx_binary_search(char **arr, int size, const char *s, int *count);
int mx_strcmp(const char *s1, const char *s2);
int mx_bubble_sort(char **arr, int size);
void mx_swap_char(char *s1, char *s2);
void mx_str_reverse(char *s);
void mx_print_strarr(char **arr, const char *delim);
int mx_quicksort(char **arr, int left, int right);
char *mx_itoa(int number);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
char *mx_strdup(const char *str);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
int mx_get_char_index(const char *str, char c);
char *mx_strcat(char *s1, const char *s2);
char *mx_strjoin(char const *s1, char const *s2);
int mx_count_substr(const char *str, const char *sub);
char *mx_strstr(const char *haystack, const char *needle);
int mx_strncmp(const char *s1, const char *s2, size_t n);
int mx_get_substr_index(const char *str, const char *sub);
int mx_count_words(const char *str, char c);
char *mx_strtrim(const char *str);
bool mx_isspace(char c);
char *mx_del_extra_spaces(const char *str);
char **mx_strsplit(const char *s, char c);
char *mx_file_to_str(const char *filename);
char *mx_replace_substr(const char *str, const char *sub,
                        const char *replace);
void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, 
                size_t little_len);
t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_pop_front(t_list **list);
void mx_push_back(t_list **list, void *data);
void mx_pop_back(t_list **list);
int mx_list_size(t_list *list);
t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b));
unsigned long mx_atol(const char *str);
int mx_atoi(const char *str);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_realloc(void *ptr, size_t size);
int mx_tolower(int c);
int mx_toupper(int c);
int mx_insertion_sort(char **arr, int size);
int mx_quicksort(char **arr, int left, int right);
int mx_linear_search(char **arr, const char *s);
char *mx_concat_words(char **words);
int mx_comparator(const int*arr, int size, int x, bool(*compare)(int, int));
void mx_printerr(char *s);
int mx_arrlen(char **arrlen);
char **mx_strdsplit(const char *s, char c);
char *mx_del_extra_whitespaces(const char *str, char dlm);
char *mx_strchr(const char *s, int c);
