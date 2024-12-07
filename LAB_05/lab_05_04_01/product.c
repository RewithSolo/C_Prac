#include "product.h"

int read_student_from_file(FILE *f, struct product_t *product)
{
    if (fread(product, sizeof(struct product_t), 1, f) != 1)
        return ERR_PROCESS;
    
    return ERR_OK;
}

int write_student_into_file(FILE *f, struct product_t *product)
{
    if (fwrite(product, sizeof(struct product_t), 1, f) != 1)
        return ERR_PROCESS;
    
    return ERR_OK;
}

int product_read(FILE *f, struct product_t *pp)
{
    char buf_surname[TITLE_LEN + 2];
    size_t len_title;
    char buf_name[DEVELOPER_LEN + 2];
    size_t len_developer;
    char tmp[8];
    uint32_t marks[4];
    if (!fgets(buf_surname, sizeof(buf_surname), f))
        return ERR_PROCESS;
    
    len_title = strlen(buf_surname);

    if (!fgets(buf_name, sizeof(buf_name), f))
        return ERR_PROCESS;

    len_developer = strlen(buf_name);

    if (len_title && buf_surname[len_title] == '\n')
    {
        buf_surname[len_title] = '\0';
        len_title--;
    }
    if (!len_title || len_title > TITLE_LEN)
        return ERR_PROCESS;

    if (len_developer && buf_name[len_developer] == '\n')
    {
        buf_name[len_developer] = '\0';
        len_developer--;
    }

    if (!len_developer || len_developer > TITLE_LEN)
        return ERR_PROCESS;
    
    if (fscanf(f, "%u %u %u %u", &marks[0], &marks[1], &marks[2], &marks[3]) != 4)
        return ERR_PROCESS;

    fgets(tmp, sizeof(tmp), f);
    strcpy(pp->surname, buf_surname);
    strcpy(pp->name, buf_name);
    memcpy(pp->marks, marks, sizeof(marks));
    
    return ERR_OK;
}

