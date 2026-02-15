#include<iostream>
using namespace std;

/*********************************************************************
File name: qn2.cpp
Author: KRIPA HAYANJU
Date: 09/18/2025

Purpose:
    The program reads movie data from a file and stores it in an array of structures. 
    It allows tracking the number of times each movie has been watched, computes the total runtime of all movies, and identifies the least-watched movie.
Command Parameters:
    No parameters to main().
Input:
    The user provides the file name, selects movies to watch by entering their serial number, and exit the program by typing “quit".
Results:
    The program displays the list of movies, along with the total runtime of all movies and the title of the least-watched movie.
Notes:
    The program uses stoi function to turn string into integer. The program will allow invalid input and coninue running till the user inputs "quit".
*********************************************************************/