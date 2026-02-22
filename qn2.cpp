#include<iostream>
using namespace std;

/*********************************************************************
File name: qn2.cpp
Author: KRIPA HAYANJU
Date: 02/21/2026

Purpose:
    The program reads the linked list L and P. 
    It makes sure the user enders valid positions.     
Command Parameters:
    No parameters to main().
Input:
    The user provides the elements for the linked list L, and the postitions for the linked list P.
Results:
    The program displays the linked list L, linked list P, and the elements of linked list L whose postitions are specified in linked list P. 
Notes:
    -
*********************************************************************/

//singly linked list
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

        //destructor 
        ~LinkedList()
        {
            Node* pCurrent;

            while(pHead != nullptr)
            {
                pCurrent = pHead;
                pHead = pHead->pNext;
                delete pCurrent;
            }
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

        //copy from the temp linked list to linked list P
        void copyFrom(const LinkedList& other)
        {
            // clear existing list first
            Node* pTemp;
            while(pHead != nullptr)
            {
                pTemp = pHead;
                pHead = pHead->pNext;
                delete pTemp;
            }

            Node* pCurr = other.pHead;
            while(pCurr != nullptr)
            {
                insert(pCurr->iData);
                pCurr = pCurr->pNext;
            }
        }

        //print the elements of linked list L whose positions are specified in linked list P
        void printLots(const LinkedList& L, const LinkedList& P)
        {
            Node* pL = L.pHead;
            Node* pP = P.pHead;

            int currentPosition = 1;

            //assume the user enters the integer positions in linked list P in ascending order 
            while(pL != nullptr && pP != nullptr)
            {
                if(currentPosition == pP->iData)   
                {
                    //print the elements of linked list L
                    cout << pL->iData << " ";
                    pP = pP->pNext;
                }

                pL = pL->pNext;
                currentPosition++;
            }
            cout << endl;
        }
};

int main()
{
    int iNum = 0;   //number of elements in the linked list L
    int iValue;  //value entered by the user 

    //validate the number so that there is no negative or zero size of the linked list L
    while(iNum <= 0)
    {
        cout << "Enter number of elements in linked list L: ";
        cin >> iNum;
    }
    
    LinkedList L; //object of the linked list L

    //insert the elements with the input from the user
    cout<< "Enter elements of the linked list L:" << endl;

    for(int i = 0; i < iNum; i++)
    {
        cin >> iValue;
        L.insert(iValue);
    }

    cout << endl;

    //print all elements of the linked list L
    cout << "Linked list L: ";
    L.print();

    cout << endl; 


    int iX;  //number of postions in linked list P

    while(true)
    {
        cout << "Enter number of elements in linked list P: ";
        cin >> iX;

        if(iX <= iNum && iX >= 0)
        {
            break;
        }
        else
        {
            cout << "Error: Number of positions in P cannot be greater than length of L (" << iNum << ") and less than 0. " << endl;
        }
    }

    LinkedList P; //object of the linked list P
    
    //make sure the positions in P are valid positions in L
    while(true)
    {
        //temporary linked list
        LinkedList tempP;
        bool valid = true;

        //insert the positions with the input from the user
        cout<< "Enter elements of the linked list P:" << endl;

        for(int i = 0; i < iX; i++)
        {
            cin >> iValue;

            if(iValue < 1 || iValue > iNum)
            {
                valid = false;
            }
            tempP.insert(iValue);
        }

        if(valid)
        {
            P.copyFrom(tempP);   //copy if it all the positions are valid
            break;
        }
        else
        {
            cout << "Error: One or more positions are invalid. Positions must be between 1 and " << iNum << ". " << endl;
        }
    }

    cout << endl;

    //print all positions of the linked list P
    cout << "Linked list P: ";
    P.print();

    cout << endl;

    //print elements of linked list L whose positions are specified in linked list P
    cout << "Elements in L at positions specified by P: ";
    P.printLots(L, P);
}
