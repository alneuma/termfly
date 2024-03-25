# termfly

termfly is a hobby/practice project, that aims to be a commandline operated client/server pair with online forum funtionality somewhen in the future.

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
    - [x] implement date_copy()
    - [x] implement date_validate()
    - [x] implement date_compare()
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
    - [x] test date_copy()
    - [x] test date_validate()
    - [ ] test date_compare()
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

- [x] implement person.c
    - [x] implement person_create()
    - [x] implement person_destroy()
    - [x] implement person_copy()
    - [x] implement person_get_size_first_name()
    - [x] implement person_get_size_last_name()
    - [x] implement person_get_size_id()
    - [x] implement person_get_first_name()
    - [x] implement person_get_last_name()
    - [x] implement person_get_id()
    - [x] implement person_get_birthday()
    - [x] implement person_set_first_name()
    - [x] implement person_set_last_name()
    - [x] implement person_set_id()
    - [x] implement person_set_birthday()

- [ ] test person.h
    - [x] test person_create()
    - [x] test person_destroy()
    - [ ] test person_copy()
    - [x] test person_get_size_first_name()
    - [x] test person_get_size_last_name()
    - [x] test person_get_size_id()
    - [x] test person_get_first_name()
    - [x] test person_get_last_name()
    - [x] test person_get_id()
    - [x] test person_get_birthday()
    - [x] test person_set_first_name()
    - [x] test person_set_last_name()
    - [x] test person_set_id()
    - [x] test person_set_birthday()

#### forum-content functionality

#### networking

### client
