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
- tanks history

#### Administrator (store manager/responsible):

- all those from the normal user
- CRUD on employees
- resetting tank status (filling)

#### Other requirements:

- Login
- When the tank is below 10%, the administrator receives a notification by mail that he must refill that tank

## Database


### Customer Table

- firstName - varchar(50)
- lastName - varchar(50)
- phoneNumber - char(10)
- birthDate - date
- created_at - timestamptz  (default now())
- combustible - real
- mediumPrice - real
- fullyPaid - real

### Employee Table

- username - varchar(50)
- password - varchar(50)
- firstName - varchar(50)
- lastName - varchar(50)
- phoneNumber - char(10)
- email - varchar(50)
- birthDate - date
- created_at - timestamptz (default now())
- admin - boolean

### Tank Table

- number - integer
- capacity - real
- currentLevel - real
- lastFill - timestamptz (default null)
