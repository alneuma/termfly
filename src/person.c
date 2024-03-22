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

Person person_create(void) {
        Person new_person = malloc(sizeof(*new_person));
        if (new_person == NULL)
                return NULL;

        new_person->first_name = malloc(sizeof(*new_person->first_name));
        if (new_person->first_name == NULL)
                return NULL;

        new_person->last_name = malloc(sizeof(*new_person->last_name));
        if (new_person->last_name == NULL)
                return NULL;

        new_person->id = malloc(sizeof(*new_person->id));
        if (new_person->id == NULL)
                return NULL;

        new_person->birthday = date_create();
        if (new_person->birthday == NULL)
                return NULL;

        *new_person->first_name = '\0';
        *new_person->last_name = '\0';
        *new_person->id = '\0';

        return new_person;
}

bool person_destroy(Person *person) {
        if (person == NULL)
                return false;
        if (*person == NULL)
                return false;
        free((*person)->first_name);
        free((*person)->last_name);
        free((*person)->id);
        date_destroy(&(*person)->birthday);
        free(*person);
        *person = NULL;
        return true;
}

bool person_copy(Person target, Person source) {
        if (target == NULL || source == NULL)
                return false;

        if (!date_copy(target->birthday, source->birthday))
                return false;

        // first allocate all the memory
        free(target->first_name);
        target->first_name = malloc(person_get_size_first_name(source) * sizeof(*target->first_name));
        if (target->first_name == NULL)
                return false;

        free(target->last_name);
        target->last_name = malloc(person_get_size_last_name(source) * sizeof(*target->last_name));
        if (target->last_name == NULL)
                return false;

        free(target->id);
        target->id = malloc(person_get_size_id(source) * sizeof(*target->id));
        if (target->id == NULL)
                return false;
        
        strcpy(target->first_name, source->first_name); 
        strcpy(target->last_name, source->last_name); 
        strcpy(target->id, source->id); 

        return true;
}

size_t person_get_size_first_name(Person person) {
        return strlen(person->first_name);
}

size_t person_get_size_last_name(Person person) {
        return strlen(person->last_name);
}

size_t person_get_size_id(Person person) {
        return strlen(person->id);
}

size_t person_get_first_name(char first_name[], size_t max_length, Person person) {
        if (first_name == NULL || person == NULL)
                return 0;

        size_t i = 0;
        while (i < max_length-1 && person->first_name[i] != '\0') {
                first_name[i] = person->first_name[i];
                i++;
        }
        first_name[i] = '\0';

        return i;
}

size_t person_get_last_name(char last_name[], size_t max_length, Person person) {
        if (last_name == NULL || person == NULL)
                return 0;

        size_t i = 0;
        while (i < max_length-1 && person->last_name[i] != '\0') {
                last_name[i] = person->last_name[i];
                i++;
        }
        last_name[i] = '\0';

        return i;
}

size_t person_get_id(char id[], size_t max_length, Person person) {
        if (id == NULL || person == NULL)
                return 0;

        size_t i = 0;
        while (i < max_length-1 && person->id[i] != '\0') {
                id[i] = person->id[i];
                i++;
        }
        id[i] = '\0';

        return i;
}

bool person_get_birthday(Date birthday, Person person) {
        if (birthday == NULL || person == NULL)
                return false;
        return date_copy(birthday, person->birthday);
}

bool person_set_first_name(char first_name[], Person person) {
        if (first_name == NULL || person == NULL)
                return false;

        free(person->first_name);
        person->first_name = malloc(strlen(first_name) * sizeof(*person->first_name));
        if (person->first_name == NULL)
                return false;

        strcpy(person->first_name, first_name);
        return true;
}

bool person_set_last_name(char last_name[], Person person) {
        if (last_name == NULL || person == NULL)
                return false;

        free(person->last_name);
        person->last_name = malloc(strlen(last_name) * sizeof(*person->last_name));
        if (person->last_name == NULL)
                return false;

        strcpy(person->last_name, last_name);
        return true;
}

bool person_set_id(char id[], Person person) {
        if (id == NULL || person == NULL)
                return false;

        free(person->id);
        person->id = malloc(strlen(id) * sizeof(*person->id));
        if (person->id == NULL)
                return false;

        strcpy(person->id, id);
        return true;
}

bool person_set_birthday(Date birthday, Person person) {
        if (birthday == NULL || person == NULL)
                return false;
        return date_copy(person->birthday, birthday);
}
