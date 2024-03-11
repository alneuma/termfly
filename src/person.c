#include "person.h"
#include "date.h"
#include <stdlib.h>

struct person_type {
        char *first_name;
        char *last_name;
        char *id;
        Date birthday;
};

bool person_init(Person person,
                char *first_name,
                size_t first_name_length,
                char *last_name,
                size_t last_name_length,
                char *id,
                size_t id_length,
                Date birthday) {

        person = malloc(sizeof(*person));
        if (person == NULL)
                return false;
        person->first_name = malloc(first_name_length * sizeof(*person->first_name));
        if (person->first_name == NULL)
                return false;
        person->last_name = malloc(last_name_length * sizeof(*person->last_name));
        if (person->last_name == NULL)
                return false;
        person->id = malloc(id_length * sizeof(*person->id));
        if (person->id == NULL)
                return false;
        person->birthday = malloc(sizeof(*person->birthday));
        if (person->birthday == NULL)
                return false;

        memcpy(person->first_name, first_name, first_name_length-1);
        person->first_name[first_name_length-1] = '\0';

        memcpy(person->last_name, last_name, last_name_length-1);
        person->last_name[last_name_length-1] = '\0';

        memcpy(person->id, id, id_length-1);
        person->id[id_length-1] = '\0';

        memcpy(person->birthday, birthday, sizeof(*birthday));

        return true;
}

bool person_destroy(Person person) {
        free(person->first_name);
        free(person->last_name);
        free(person->id);
        date_destroy(person->birthday);
        free(person);
        return true;
}

bool person_get_first_name(char *first_name, size_t max_length, Person person);
bool person_get_last_name(char *last_name, size_t max_length, Person person);
bool person_get_id(char *id, size_t max_length, Person person);
bool person_get_age(uint16_t *age, Person person);
bool person_get_birthday(Date birthday, Person person);
