#include "person.h"
#include "date.h"
#include <stdlib.h>
#include <string.h>

struct person_type {
        char *first_name;
        char *last_name;
        char *id;
        Date birthday;
};

Person person_init(void) {
}

bool person_destroy(Person person) {
}

bool person_get_first_name(char *first_name, size_t max_length, Person person) {
}

bool person_get_last_name(char *last_name, size_t max_length, Person person) {
}

bool person_get_id(char *id, size_t max_length, Person person) {
}

bool person_get_age(age_t *age, Person person) {
}

bool person_set_first_name(char *first_name, Person person) {
}

bool person_set_last_name(char *last_name, Person person) {
}

bool person_set_id(char *id, Person person) {
}

bool person_set_age(age_t *age, Person person) {
}

bool person_get_birthday(Date birthday, Person person)  {
}
