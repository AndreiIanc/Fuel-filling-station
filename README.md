# Fuel-filling-station

### Built With 

![Qt](https://img.shields.io/badge/Qt-%23217346.svg?style=for-the-badge&logo=Qt&logoColor=white)

![Postgres](https://img.shields.io/badge/postgres-%23316192.svg?style=for-the-badge&logo=postgresql&logoColor=white)


## Description

Ceating a desktop application for a fuel charging station for agricultural machinery.

### Users:

#### Normal user (employee):

- subtracts from the tanks when purchased and adds a new payment to the database
- CRUD on customers
- machine food history

#### Administrator (store manager/responsible):

- all those from the normal user
- CRUD on employees
- resetting tank status (filling)

#### Other requirements:

- Login

## Database


### Customer Table

- username - string
- password - string
- first name - string
- last name - string
- phoneNumber - string(10)
- birthDate - date
- creationDate - date
- combustible - float
- medium price - float
- fully paid - float

### Employee Table

- username - string
- password - string
- first name - string
- last name - string
- phoneNumber -string(10)
- birthDate - date
- creationDate - date
- admin - boolean

### Tank Table

- number - integer
- capacity - float
- current level - float
- last fill - date
