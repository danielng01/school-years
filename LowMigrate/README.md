LowMigrate
==========

This is low level migration framework written in C++ -> Well it is just program for automating SUBD exam in TUES...

It works with `MySQL` or `XAMPP MySQL` or `PHPMyAdmin` or `whatever you want MySQL`

To make it run you should download

`LowMigrate/ProjectVS/LowMigrate/Debug/`

and start `LowMigrate.exe` in `Command Prompth`

The available options are:

---

`-host`
the next argument should be host the default is

`tcp://127.0.0.1:3306`

---

`-user`

the next argument should be username the default is `root`

---

`-pass`

the next argument should be password the default is `root`

---

`-query`

the next argument should be SQL query.

It should be enclosed in "" aka

`"CREATE TABLE Category (id INT, name varchar(100), date_created_on date)"`

---

`-CreateTable`

`LowMigrate.exe -CreateTable Category name varchar(100) date_created_on date`

The format is `-CreateTable` `tablename` `columns and types separated by space`

The command generates this

`CREATE TABLE Category (id INT, name varchar(100), date_created_on date)`

---

`-SplitMigrate`

used like this

`LowMigrate.exe -SplitMigrate article price`

or

`LowMigrate.exe -SplitMigrate` `table name` `column to migrate`

and it generates someting like this:

```
----------------------------------
Executing query:`
DROP TABLE IF EXISTS article_part1
Query execution succesfull
----------------------------------
Executing query:
DROP TABLE IF EXISTS article_part2
Query execution succesfull
----------------------------------
Executing query:
CREATE TABLE article_part1 ( name_id INT,  id  INT,  price  DECIMAL)
Query execution succesfull
----------------------------------
Executing query:
CREATE TABLE article_part2 (id INT, name VARCHAR(100) )
Query execution succesfull
```

and INSERT statement for migration of fields

---
`-AddColumn`

used like this:

`LowMigrate.exe -AddColumn article content varchar(100)`

and generates:

```
----------------------------------
Executing query:
ALTER TABLE article ADD content varchar(100)
Query execution succesfull

```

---

`-OneToMany`

makes one to many relationship

used like this:

`LowMigrate.exe -OneToMany user tag`

and generates:

well one to many relationship

---

`-ManyToMany`

makes many to many relationship

used like this:

`LowMigrate.exe -ManyToMany user article`

and generates something like this:

```
----------------------------------
Executing query:
DROP TABLE IF EXISTS user_article
Query execution succesfull
----------------------------------
Executing query:
CREATE TABLE user_article ( user_id INT ,article_id INT )
Query execution succesfull
```

---

and that is pretty much it.






--------
------------
-----------
----------
--------

So for the exam. Lets say we have:
```
1. Create the following tables
Create table Article with columns
         published_on:date
         name:varchar

Create table Category with columns
         description:varchar
         name:varchar

Create table User with columns
         name:varchar
         created_on:date
         age:integer

Create table Tag with columns
         priority:int
         description:varchar

As a result SQL queries must be created

2. Connect the tables in the following way
User has a many to many connection to Tag
Tag has a many to one connection to Article
Article has a one to many connection to Category
As a result SQL queries must be created


3. Insert
Add at least two records in each table
As a result SQL queries must be created

4. Answer the following question
Which are the Article(s) for a given User
As a result SQL query must be created

5. Export the Data Base to SQL or CSV

6. Execute the following migration
Separate Tag on two tables
Tag_part1 containing priority
Tag_part2 containing all the other fields
As a result SQL queries+code in other programming language must be create

7. Export the Data Base to SQL or CSV

8. Answer the following question
Which are the Category(s) for a given Tag
As a result SQL query must be created

```


###For 1. run:

`Debug>LowMigrate.exe -CreateTable Article published_on date name varchar(100)`


```
----------------------------------
Executing query:
DROP TABLE IF EXISTS Article
Query execution succesfull
----------------------------------
Executing query:
CREATE TABLE Article ( id INT ,published_on date, name varchar(100))
Query execution succesfull
```


`Debug>LowMigrate.exe -CreateTable Category description varchar(100) name varchar(100)`

```
----------------------------------
Executing query:
DROP TABLE IF EXISTS Category
Query execution succesfull
----------------------------------
Executing query:
CREATE TABLE Category ( id INT ,description varchar(100), name varchar(100))
Query execution succesfull
```


`Debug>LowMigrate.exe -CreateTable User name varchar(100) created_on date age int`

`Debug>LowMigrate.exe -CreateTable Tag priority int description varchar(100)`

###For 2. run:

```
Debug>LowMigrate.exe -ManyToMany user tag
----------------------------------
Executing query:
DROP TABLE IF EXISTS user_tag
Query execution succesfull
----------------------------------
Executing query:
CREATE TABLE user_tag ( user_id INT ,tag_id INT )
Query execution succesfull
```

```
Debug>LowMigrate.exe -OneToMany Article tag
----------------------------------
Executing query:
ALTER TABLE tag ADD Article_id INT
Query execution succesfull
```

```
Debug>LowMigrate.exe -OneToMany Article category
----------------------------------
Executing query:
ALTER TABLE category ADD Article_id INT
Query execution succesfull
```

###For 3. run:

It is just stupid easy with PHPMyAdmin

###For 4. run:

Sorry I can't help you

###For 5. run:

It is just stupid easy with PHPMyAdmin

###For 6. run:

`Debug>LowMigrate.exe -SplitMigrate Tag priority`

###For 7. run:

It is just stupid easy with PHPMyAdmin

###For 8. run:

Sorry I can't help you
