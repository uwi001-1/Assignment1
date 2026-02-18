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

class LinkedList
{
    private: 
        struct Node
        {
            int iData;
            Node* pNext;
        };
        Node* pHead;
    
    public:
        //default constructor
        LinkedList()
        {
            pHead = nullptr;
        }

        //insert the elements into the linked list
        void insert(int iValue)
        {
            //create the new node and populate it
            Node* pNew = new Node;
            pNew->iData = iValue;
            pNew->pNext = nullptr;
            
            //insert it at head or add the first element to the linked list
            if(pHead == nullptr)
            {
                pHead = pNew;
            }
            //else insert it at the end of the linked list
            else
            {
                Node* pCurr = pHead;

                while(pCurr->pNext != nullptr)
                {
                    pCurr = pCurr->pNext;
                }
                pCurr->pNext = pNew;
            }
        }

        //print all the elements of the linked list
        void print()
        {
            if(pHead == nullptr)
            {
                cout << "Linked list is empty" << endl;
            }
            else
            {
                Node* pCurr = pHead;

                //loop through the list and print the element 
                while(pCurr != nullptr)
                {
                    cout << pCurr->iData;

                    if(pCurr->pNext != nullptr)
                        cout << " -> ";
                    
                    pCurr = pCurr->pNext;
                }

                cout << endl;
            }
        }
};

int main()
{
    int iNum;   //number of elements in the list
    int iValue;  //value entered by the user

    //validate the number so that there is no negative or zero size of the list
    while(iNum <= 0)
    {
        cout << "Enter number of elements in linked list L: ";
        cin >> iNum;
    }
    
    LinkedList L; //object of the linked list 

    //inser the elements with the input from the user
    cout<< "Enter elements of the linked list L:" << endl;

    for(int i = 0; i < iNum; i++)
    {
        cin >> iValue;
        L.insert(iValue);
    }

    //print all elements of the linked list 
    cout << "Linked list L: ";
    L.print();
}