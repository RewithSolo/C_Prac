#include <stdio.h>
#include <string.h>
#include "funcs.h"


char *my_strpbrk(const char *str, const char *sym)
{
    char *now, *prev = NULL;
    for (size_t i = 0; i < strlen(sym); i++)
    {
        now = my_strchr(str, sym[i]);
        if ((now && !prev) || (now && prev && now < prev))
            prev = now;
    }

    return prev;
}


size_t my_strspn(const char *str, const char *sym)
{
    size_t i;
    char *pos;
    for (i = 0; i < strlen(str); i++)
    {
        pos = my_strpbrk(str + i, sym);
        if (pos != str + i)
            return i;
    }

    return i;
}


size_t my_strcspn(const char *str, const char *sym)
{
    size_t i = 0;
    char *cur = my_strpbrk(str, sym);
    if (cur)
        return cur - str;
    else
        while (str[i])
            i++;

    return i;
}


char *my_strchr(const char *str, int ch)
{
    size_t i = 0;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == ch)
            return (char*)(str + i);
    }

    if (!ch)
        return (char*)(str + i);
    else
        return NULL;
}


char *my_strrchr(const char *str, int ch)
{
    size_t i = 0;
    size_t cur = 0;
    while (str[i])
    {
        if (str[i] == ch)
            cur = i;

        i++;
    }


    if (!ch)
        return (char*)(str + i);

    if (str[cur] == ch)
        return (char*)(str + cur);
    else
        return NULL;
}

size_t test_strpbrk()
{
    size_t fails = 0;
    fails += strpbrk("HelloWorld", "elo") != my_strpbrk("HelloWorld", "elo");
    fails += strpbrk("HelloWorld", " ") != my_strpbrk("HelloWorld", " ");
    fails += strpbrk("HelloWorld", "d") != my_strpbrk("HelloWorld", "d");
    fails += strpbrk("Hello World", " ") != my_strpbrk("Hello World", " ");
    return fails;
}

size_t test_strspn()
{
    size_t fails = 0;
    fails += strspn("HelloWorld", "elo") != my_strspn("HelloWorld", "elo");
    fails += strspn("HelloWorld", " ") != my_strspn("HelloWorld", " ");
    fails += strspn("HelloWorld", "d") != my_strspn("HelloWorld", "d");
    fails += strspn("Hello World", " ") != my_strspn("Hello World", " ");
    return fails;
}

size_t test_strcspn()
{
    size_t fails = 0;
    fails += strcspn("HelloWorld", "elo") != my_strcspn("HelloWorld", "elo");
    fails += strcspn("HelloWorld", " ") != my_strcspn("HelloWorld", " ");
    fails += strcspn(" ", " ") != my_strcspn(" ", " ");
    fails += strcspn("Hello World", " ") != my_strcspn("Hello World", " ");
    return fails;
}

size_t test_strchr()
{
    size_t fails = 0;
    fails += strchr("HelloWorld", 'l') != my_strchr("HelloWorld", 'l');
    fails += strchr("HelloWorld", ' ') != my_strchr("HelloWorld", ' ');
    fails += strchr("Hello World", ' ') != my_strchr("Hello World", ' ');
    return fails;
}

size_t test_strrchr()
{
    size_t fails = 0;
    fails += strrchr("HelloWorld", 'l') != my_strrchr("HelloWorld", 'l');
    fails += strrchr("HelloWorld", ' ') != my_strrchr("HelloWorld", ' ');
    fails += strrchr("Hello World", ' ') != my_strrchr("Hello World", ' ');
    return fails;
}
