# termfly

This is a hobby/practice project, that aims to be a commandline operated client/server pair with online forum funtionality somewhen in the future.

## todo

- [ ] server
    - [ ] write forum-member functionality
    - [ ] write forum-content functionality
    - [ ] make it networked
- [ ] client

## server

#### forum-member functionality

##### todo

###### utility_number.h

- [x] implement utility_numbers.c
    - [x] implement count_digits_int64()
    - [x] implement count_digits_uint64()
    - [x] implement macro COUNT_DIGITS_INT()

- [x] test utility_numbers.h
    - [x] test count_digits_int64()
    - [x] test count_digits_uint64()
    - [x] test macro COUNT_DIGITS_INT()

###### date.h

- [ ] implement date.c
    - [x] implement date_create()
    - [x] implement date_destroy()
    - [x] implement date_validate()
    - [x] implement date_get_day()
    - [x] implement date_get_month()
    - [x] implement date_get_year()
    - [x] implement date_set_day()
    - [x] implement date_set_month()
    - [x] implement date_set_year()
    - [x] implement date_get_string_length()
    - [x] implement date_get_string_max_length()
    - [x] implement date_get_string()
    - [x] implement date_get_size()
    - [ ] implement date_get_delta_months()
    - [ ] implement date_get_delta_days()
    - [ ] implement date_get_delta_years()
    - [x] implement private function is_leap_year()
    - [x] implement private function days_in_month()
    - [x] implement private function date_get_characters_in_month()

- [ ] test date.h
    - [x] test date_destroy()
    - [x] test date_validate()
    - [x] test date_get_day()
    - [x] test date_get_month()
    - [x] test date_get_year()
    - [x] test date_set_day()
    - [x] test date_set_month()
    - [x] test date_set_year()
    - [x] test date_get_string_length()
    - [x] test date_get_string_max_length()
    - [ ] test date_get_string()
    - [ ] test date_get_delta_months()
    - [ ] test date_get_delta_days()
    - [ ] test date_get_delta_years()

###### person.h

- [ ] implement person.c
    - [ ] implement person_init()
    - [ ] implement person_destroy()
    - [ ] implement person_get_first_name()
    - [ ] implement person_get_last_name()
    - [ ] implement person_get_id()
    - [ ] implement person_get_age()
    - [ ] implement person_set_first_name()
    - [ ] implement person_set_last_name()
    - [ ] implement person_set_id()
    - [ ] implement person_set_age()
    - [ ] implement person_get_birthday()

- [ ] test person.h
    - [ ] test person_init()
    - [ ] test person_destroy()
    - [ ] test person_get_first_name()
    - [ ] test person_get_last_name()
    - [ ] test person_get_id()
    - [ ] test person_get_age()
    - [ ] test person_set_first_name()
    - [ ] test person_set_last_name()
    - [ ] test person_set_id()
    - [ ] test person_set_age()
    - [ ] test person_get_birthday()

#### forum-content functionality

#### networking

### client
