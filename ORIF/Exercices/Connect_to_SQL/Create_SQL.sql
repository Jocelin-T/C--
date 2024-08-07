-- Jocelin Thumelin
-- 27.03.2024
-- Connect C++ to a database

 DROP DATABASE orif_ex_connect_to_cpp; -- DEBUG

CREATE DATABASE orif_ex_connect_to_cpp;

USE orif_ex_connect_to_cpp;

CREATE TABLE day_entry (
    id_day INT PRIMARY KEY AUTO_INCREMENT,
    day_current DATE,
    day_start DATETIME,
    day_end DATETIME
);

CREATE TABLE employees (
    id_employee INT PRIMARY KEY AUTO_INCREMENT,
    emp_last_name VARCHAR(32),
    emp_first_name VARCHAR(32),
    emp_email VARCHAR(50),
    emp_password VARCHAR(18),
    id_day INT,
    FOREIGN KEY(id_day) REFERENCES day_entry(id_day)
);
