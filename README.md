# name_database

A simple name database that serves as a practice project.
The plan is to use this as a basis for a networked application.

## todo

### general 

[x] general
    [x] write Makefile
    [x] add license
    [x] set up testing framework unity

### utility_number.h

[x] implement utility_numbers.c
    [x] implement count_digits_int64()
    [x] implement count_digits_uint64()
    [x] implement macro COUNT_DIGITS_INT()

[x] test utility_numbers.h
    [x] test count_digits_int64()
    [x] test count_digits_uint64()
    [x] test macro COUNT_DIGITS_INT()

### date.h

[ ] implement date.c
    [x] implement date_create()
    [x] implement date_destroy()
    [x] implement date_validate()
    [x] implement date_get_day()
    [x] implement date_get_month()
    [x] implement date_get_year()
    [x] implement date_set_day()
    [x] implement date_set_month()
    [x] implement date_set_year()
    [ ] implement date_get_string_length()
    [ ] implement date_get_string_max_length()
    [ ] implement date_get_string()
    [x] implement date_get_size()
    [x] implement private function is_leap_year()
    [x] implement private function days_in_month()
    [x] implement date_get_characters_in_month()

[ ] test date.h
    [x] test date_destroy()
    [x] test date_validate()
    [x] test date_get_day()
    [x] test date_get_month()
    [x] test date_get_year()
    [x] test date_set_day()
    [x] test date_set_month()
    [x] test date_set_year()
    [ ] test date_get_string_length()
    [ ] test date_get_string_max_length()
    [ ] test date_get_string()

### person.h

[ ] implement person.c
    [ ] implement person_init()
    [ ] implement person_destroy()
    [ ] implement person_get_first_name()
    [ ] implement person_get_last_name()
    [ ] implement person_get_id()
    [ ] implement person_get_age()
    [ ] implement person_set_first_name()
    [ ] implement person_set_last_name()
    [ ] implement person_set_id()
    [ ] implement person_set_age()
    [ ] implement person_get_birthday()

[ ] test person.h
    [ ] test person_init()
    [ ] test person_destroy()
    [ ] test person_get_first_name()
    [ ] test person_get_last_name()
    [ ] test person_get_id()
    [ ] test person_get_age()
    [ ] test person_set_first_name()
    [ ] test person_set_last_name()
    [ ] test person_set_id()
    [ ] test person_set_age()
    [ ] test person_get_birthday()
