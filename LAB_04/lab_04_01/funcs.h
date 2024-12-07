#ifndef __FUNCS_H__
#define __FUNCS_H__

char *my_strpbrk(const char *str, const char *sym);

size_t my_strspn(const char *str, const char *sym);

size_t my_strcspn(const char *str, const char *sym);

char *my_strchr(const char *str, int ch);

char *my_strrchr(const char *str, int ch);

size_t test_strpbrk();

size_t test_strspn();

size_t test_strcspn();

size_t test_strchr();

size_t test_strrchr();

#endif

