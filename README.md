# Structured File Parser

## Description 

This is a project for a simple parser for files that contain structured data. The data in the file must be structured in a format similar to a .csv file and the output of the program is a doubly linked list. The list supports CRUD operations and can be saved to file. The structures can only contain primitive data types.

This application is written in C++11.

## _SF_ File Format And Use

The input for the program must be a .sf file. This file must be formated in the following way. 

1. The first line must specify the data type in the structure, separated by "pipes"(|).
* Example: int|float|char|float
* If this line is not present or the format is not correct the program will terminate with and error.
2. Every other line must contain data of the specified type, separated by a "pipe".
* Example: 242|42.0|g|22
* A "pipe" **cannot** be a character in the data.
* If a line is not in the correct format, the program print an error with number of the incorrect line and the line will be skipped.

## Using the program

This is a console application that can be used in the following way.

1. You will be prompted to either enter a valid path to a .sf file, that is to be parsed **or** to run tests.
2. If you chose the first option, if everything ran correctly, you will be able to work with the data in a way specified by the interface in the console.

## Future work

The application can be extended in the future in the following ways:

1. Add the option of reading/writing non-primitive data in the .sf files.

## Known issues

1. Add and Remove not fully implemented.
2. Some inputs not properly validated. 
