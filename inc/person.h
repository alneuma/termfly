#ifndef PERSON_H
#define PERSON_H

#include <stdbool.h>
#include "date.h"
#include <stddef.h>

typedef struct person_type *Person;

bool person_init(Person person,
                char *first_name,
                size_t first_name_length,
                char *last_name,
                size_t last_name_length,
                char *id,
                size_t id_length,
                Date birthday);
bool person_destroy(Person person);
bool person_get_first_name(char *first_name, size_t max_length, Person person);
bool person_get_last_name(char *last_name, size_t max_length, Person person);
bool person_get_id(char *id, size_t max_length, Person person);
bool person_get_age(uint16_t *age, Person person); // uint16_t for biblical characters
bool person_get_birthday(Date birthday, Person person);

#endif // PERSON_H
