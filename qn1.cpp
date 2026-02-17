#include<iostream>
using namespace std;

/*********************************************************************
File name: qn1.cpp 
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


class ArrayList
{
    private:
        int array[100];
        int iSize = 0;
    
    public: 
        static const int MAX_SIZE = 100;

        void insert(int iValue) //inserts the new value at the end of the list 
        {
            array[iSize] = iValue;
            iSize++;
        }

        void printList() //prints the list
        {
            for(int i =0; i < iSize; i++)
            {
                cout << array[i] << " ";
            }
            cout << endl;
        }

        int access(int iIndex)   //return the value
        {
            return array[iIndex];
        }
};

int main()
{
    int iNum;
    while(true)
    {
        cout << "Enter number of elements: ";
        cin >> iNum;

        if(iNum <= ArrayList::MAX_SIZE) //if number is less than max size then consider it the valid size
            break;

        cout << "Error! Number is too large" << endl;
    }

    //create the objects
    ArrayList A;
    ArrayList B;

    //input and insert elements of array list A
    cout << "Enter elements of of array list A: " << endl;
    for(int i = 0; i < iNum; i++)
    {
        int iVal;
        cin >> iVal;
        A.insert(iVal);
    } 

    //input and insert elements of array list B
    cout << "Enter elements of of array list B: " << endl;
    for(int i = 0; i < iNum; i++)
    {
        int iVal;
        cin >> iVal;
        B.insert(iVal);
    }

    cout << endl;

    //print all elements of array list A
    cout << "Array list A: ";
    A.printList();

    //print all elements of array list B
    cout << "Array list B: ";
    B.printList();

    cout << endl;

    //sum of the corresponding elements
    cout << "Sum of corresponding elements: ";
    for(int i = 0; i < iNum; i++)
    {
        cout << A.access(i) + B.access(i) << " ";
    }
}