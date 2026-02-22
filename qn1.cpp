#include<iostream>
using namespace std;

/*********************************************************************
File name: qn1.cpp 
Author: KRIPA HAYANJU
Date: 02/17/2026

Purpose:
    The program reads the size of two array lists. 
    It outputs the sum of the corresponding elements of the array lists.
Command Parameters:
    No parameters to main().
Input:
    The user provides the list size, and the elements of the two array lists.
Results:
    The program displays the sum of the corresponding elements of the array lists.
Notes:
    -
*********************************************************************/

class ArrayList
{
    private:
        int array[100];
        int iSize = 0;
    
    public: 
        static const int MAX_SIZE = 100;  //makes the array max size accessible outside class and keeps it constant
        
        //inserts the new value at the end of the list 
        void insert(int iValue) 
        {
            array[iSize] = iValue;
            iSize++;
        }

        //prints the array list
        void printList() 
        {
            for(int i =0; i < iSize; i++)
            {
                cout << array[i] << " ";
            }
            cout << endl;
        }
        
        //return the value of the index
        int access(int iIndex)   
        {
            //no need to check for bound as the index will be between 0 and iNum
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

        //check if the number is negative or zero
        if(iNum > 0 && iNum <= ArrayList::MAX_SIZE) //if number is less than max size then consider it the valid size
            break;

        cout << "Error! Number is too large or can't be negative or zero" << endl;
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

    cout << endl;
}