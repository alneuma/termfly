#ifndef PERSON_H
#define PERSON_H

#include <stdbool.h>
#include "date.h"
#include <stddef.h>

typedef struct person_type *Person;
typedef uint16_t age_t; // uint16_t for biblical characters

Person person_create(void);
// returns pointer to a dynamically
// allocated empty Person-file
// first_name, last_name and id will be empty
// null terminated strings
// Birthday will be set to the non valid date
// 0,0,0
//
// retruns NULL if unsuccessful

bool person_destroy(Person *person);
// returns true if destruction succeeded
// otherwise false
// Sets *person to NULL after destruction.
// Returns false, if *person or person is NULL

bool person_copy(Person target, Person source);
// Copies all person data from source to target
// overwriting everything, that has been there.
// Retruns true on success, otherwise false.

size_t person_get_size_first_name(Person person);
// returns the size of the persons first name
// (a null terminated string in byte)
// The empty string returns 1

size_t person_get_size_last_name(Person person);
// returns the size of the persons last name
// (a null terminated string in byte)
// The empty string returns 1

size_t person_get_size_id(Person person);
// returns the size of the persons id
// (a null terminated string in byte)
// The empty string returns 1

size_t person_get_first_name(char first_name[], size_t max_length, Person person);
// Writes the person's first name (null terminated string)
// into first_name, occupying a maximum of max_length bytes.
// The last written byte will always be '\0'
//
// returns the number of written bytes
// The return value can be compared to
// person_get_size_first_name(person)
// to check if truncation happened
//
// If zero bytes go written, one cause can be,
// that person == NULL

size_t person_get_last_name(char last_name[], size_t max_length, Person person);
// Writes the person's last name (null terminated string)
// into last_name, occupying a maximum of max_length bytes.
// The last written byte will always be '\0'
//
// returns the number of written bytes
// The return value can be compared to
// person_get_size_last_name(person)
// to check if truncation happened
//
// If zero bytes go written, one cause can be,
// that person == NULL

size_t person_get_id(char id[], size_t max_length, Person person);
// Writes the person's id (null terminated string)
// into id, occupying a maximum of max_length bytes.
// The last written byte will always be '\0'
//
// returns the number of written bytes
// The return value can be compared to
// person_get_size_id(person)
// to check if truncation happened
//
// If zero bytes go written, one cause can be,
// that person == NULL

bool person_get_birthday(Date birthday, Person person);
// writes the birthday of person into birthday
// replacing all previous data
// returns true on success, otherwise false

bool person_set_first_name(char first_name[], Person person);
bool person_set_last_name(char last_name[], Person person);
bool person_set_id(char id[], Person person);
bool person_set_birthday(Date birthday, Person person);

#endif // PERSON_H
