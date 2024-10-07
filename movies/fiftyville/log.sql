-- Keep a log of any SQL queries you execute as you solve the mystery.
-- First let's get a sense of the schema
.schema
-- Let's check out one of the tables
SELECT * from crime_scene_reports;
-- Too much data, let's see what other tables we're working with
.tables
-- A lot of them. Let's check the architecture of a couple
.tables airports
-- Repeat as necessary, nothng to go on
-- Look for thefts in crime scene report
SELECT *
FROM crime_scene_reports
WHERE description LIKE "%thef%";
-- Verify that no crimes involve 'thieves', 'thieving', or 'thieved', none found
SELECT *
FROM crime_scene_reports
WHERE description LIKE "%theiv%";
-- Observe crime_scene_report.id = 295 describing duck theft.
SELECT description FROM crime_scene_reports WHERE id = 295;
-- +--------------------------------------------------------------+
-- |                         description                          |
-- +--------------------------------------------------------------+
-- | Theft of the CS50 duck took place at 10:15am at the Humphrey |
-- |  Street bakery. Interviews were conducted today with three w |
-- | itnesses who were present at the time – each of their interv |
-- | iew transcripts mentions the bakery.                         |
-- +--------------------------------------------------------------+
-- Review schema again, let's check out 'interviews'
.schema interviews
-- Let's browse the whole thing and keep an eye on transcript
SELECT * FROM interviews;
-- Too many to browse. Sort by date of crime_scene_report.id = 295 (2023-07-28)
SELECT * FROM interviews WHERE year = 2023 AND month = 7 AND day >= 28;
-- Crime interview can't happen before crime. Checked for interviews on or after 28th
-- All interviews happened on the 28th.
-- Whoops, many crimes happened on 2023-7-28:
SELECT * FROM crime_scene_reports  WHERE year = 2023 AND month = 7 AND day = 28;
-- Only one theft though, let's try that
SELECT * FROM interviews WHERE year = 2023 AND month = 7 AND day >= 28 AND transcript LIKE '%thie%' OR '%thef%';
-- Returns three names: Ruth, Eugene, Raymond. Looks like one transcript per person, no conversation.
-- Any one of these could be suspects, but let's start with Ruth takling about cars and security footage.
.schema bakery_security_logs;
-- Theft occurred at 10:15am. Report says exit within 10min
SELECT * FROM bakery_security_logs WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = 'exit';
-- Let's knit license plates to people in the people table
SELECT name
FROM people
WHERE license_plate IN
    (SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2023
        AND month = 7
        AND day = 28
        AND hour = 10
        AND minute < 25
        AND activity = 'exit');
-- A good list of 8 names. Now let's pursue Eugene's info about ATMs
.schema atm_transactions
-- We can't really make a useful global variable for our timestamp, so it'll be just a bunch of copy-paste.
SELECT * from atm_transactions  WHERE year = 2023 AND month = 7 AND day = 28;
-- Lots of returns, let's filter on same street and transaction type
SELECT * from atm_transactions
WHERE year = 2023
    AND month = 7
    AND day = 28
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw';
-- We get some account numbers, can we knit those to people:
.schema bank_acounts
-- Gotta knit it back to people, let's go
SELECT name
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE bank_accounts.account_number IN
    (SELECT account_number FROM atm_transactions
    WHERE year = 2023
        AND month = 7
        AND day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw');
-- Okay so we've got two lists from Ruth and Eugene.
-- Let's generate the third list from Raymond concerning phone calls
.schema phone_calls
-- Let's see what's there
SELECT *
FROM phone_calls
WHERE year = 2023
    AND month = 7
    AND day = 28;
-- A bunch of repeat values. We can knit the caller ID to people
