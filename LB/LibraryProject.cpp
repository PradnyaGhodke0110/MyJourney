#include <iostream>
using namespace std;
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Structure : nodeS
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the structure for singly linear and circular Linked list
//****************************************************************************************************//

#pragma pack(1)
template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Structure : nodeD
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the structure for Doubly linear and Doubly circular linked list
//****************************************************************************************************//

template <class T>
struct nodeD
{
    T data;
    struct nodeD *prev;
    struct nodeD *next;
};

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : SinglyLL
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for Singly linear  linked list
//****************************************************************************************************//

template <class T>
class SinglyLL
{
public:
    struct nodeS<T> *First;

    SinglyLL();
    void InsertFirst(T iNo);
    void InsertLast(T iNo);
    void InsertAtPos(T iNo, int iPos);
    void Display();
    int Count();
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    void ReverseElement();
    int CheckFirstOccurence(T iNo);
    int CheckLastOccurence(T iNo);
    T LargestElements();
    T SmallestElements();
    T displayAddition();
    T displaySecondMax();
    bool SearchElement(T iNo);
    int FrequencyOfElement(T iNo);
    SinglyLL<int> EvenNo();
    SinglyLL<int> OddNo();
    SinglyLL<int> DisplayAdditionOfDigit();
    SinglyLL<int> DisplayPerfectNo();
    SinglyLL<int> DisplayPrimeNo();
};

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the constructor : SinglyLL
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the constructor for Singly linear  linked list
//****************************************************************************************************//

template <class T>
SinglyLL<T>::SinglyLL()
{
    First = NULL;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : InsertFirst
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : [IN] T iNo
// Description: This  Function insert an element at First Position of singly Linear Linked List.
//****************************************************************************************************//

template <class T>
void SinglyLL<T>::InsertFirst(T iNo)
{
    struct nodeS<T> *newn = new struct nodeS<T>;
    newn->data = iNo;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : InsertLast
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : [IN] T iNo
// Description: This  Function insert an element at Last Position of singly Linear Linked List.
//****************************************************************************************************//

template <class T>
void SinglyLL<T>::InsertLast(T iNo)
{
    struct nodeS<T> *newn = new struct nodeS<T>;
    newn->data = iNo;
    newn->next = NULL;
    struct nodeS<T> *temp = First;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : Display
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This  Function Displays an elements  of singly Linear Linked List.
//****************************************************************************************************//

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeS<T> *temp = First;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL"
         << "\n";
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : Count
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This  Function Counts the Number of elements  of singly Linear Linked List.
//****************************************************************************************************//

template <class T>
int SinglyLL<T>::Count()
{
    struct nodeS<T> *temp = First;
    int iCnt = 0;

    while (temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : InsertAtPos
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : [IN] T no,int pos
// Description: This  Function Inserts an elements at specific position of singly Linear Linked List.
//****************************************************************************************************//

template <class T>
void SinglyLL<T>::InsertAtPos(T iNo, int iPos)
{
    struct nodeS<T> *newn = new struct nodeS<T>;
    newn->data = iNo;
    newn->next = NULL;
    struct nodeS<T> *temp = First;
    int iNodeCnt = Count();

    if (iPos < 1 && iPos > iNodeCnt + 1)
    {
        cout << "Invalid Position"
             << "\n";
        return;
    }
    else if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == iNodeCnt + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        for (int i = 0; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : DeleteFirst
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This  Function delete  an elements of first position in singly Linear Linked List.
//****************************************************************************************************//

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeS<T> *temp = First;

    if (First == NULL)
    {
        cout << "Linked List is empty"
             << "\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete temp;
    }
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : DeleteLast
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This  Function delete  an elements of Last position in singly Linear Linked List.
//****************************************************************************************************//

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeS<T> *temp = First;

    if (First == NULL)
    {
        cout << "Linked List is empty"
             << "\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : DeleteAtPos
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : int pos
// Description: This  Function delete  an elements of Perticular position in singly Linear Linked List.
//****************************************************************************************************//

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    struct nodeS<T> *temp1 = First;
    struct nodeS<T> *temp2 = First;

    int iNodeCnt = Count();

    if (iPos < 1 && iPos > iNodeCnt + 1)
    {
        cout << "Invalid Position"
             << "\n";
        return;
    }
    else if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iNodeCnt + 1)
    {
        DeleteLast();
    }
    else
    {
        for (int i = 0; i < iPos - 1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp1->next->next;
        free(temp2);
    }
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : ReverseElement
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function Reverse  an elements of   singly Linear Linked List.
//****************************************************************************************************//


template <class T>
void SinglyLL<T>::ReverseElement()
{
    struct nodeS<T> *previous = NULL;
    struct nodeS<T> *Next = NULL;
    struct nodeS<T> *Current = First;

    while (Current != NULL)
    {
        Next = Current->next;
        Current->next = previous;
        previous = Current;

        Current = Next;
    }
    First = previous;
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : CheckFirstOccurence
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : T iNo
// Description: This  Function returns the First occurence index of given elements of singly Linear Linked List.
//****************************************************************************************************//


template <class T>
int SinglyLL<T>::CheckFirstOccurence(T iNo)
{
    int iPos = -1;
    int Counter = 1;

    int iCount = 0, iTemp = -1;
    struct nodeS<T> *temp1 = First;
    if (temp1 == NULL)
    {
        printf("there are no elements:\n");
    }
    else
    {
        for (iCount = 1; temp1 != NULL; iCount++)
        {
            if (temp1->data == iNo)
            {
                iTemp = iCount;
                break;
            }
            temp1 = temp1->next;
        }
    }
    if (iTemp == -1)
    {
        cout << "No such element is present" << endl;
    }
    return iTemp;
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : CheckLastOccurence
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : T iNo
// Description: This  Function returns the Last occurence index of given elements of singly Linear Linked List.
//****************************************************************************************************//


template <class T>
int SinglyLL<T>::CheckLastOccurence(T iNo)
{
    int iPos = -1;
    int Counter = 1;

    int iCount = 0, iTemp = -1;
    struct nodeS<T> *temp1 = First;
    if (temp1 == NULL)
    {
        printf("there are no elements:\n");
    }
    else
    {
        for (iCount = 1; temp1 != NULL; iCount++)
        {
            if (temp1->data == iNo)
            {
                iTemp = iCount;
            }
            temp1 = temp1->next;
        }
    }
    if (iTemp == -1)
    {
        cout << "No such element is present" << endl;
    }
    return iTemp;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : LargestElements
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function returns the largest elements in  singly Linear Linked List.
//****************************************************************************************************//


template <class T>

T SinglyLL<T>::LargestElements()
{
    int iMax = First->data;

    while (First != NULL)
    {
        if (First->data > iMax)
        {
            iMax = First->data;
        }
        First = First->next;
    }
    return iMax;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : SmallestElements
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function returns the smallest elements in  singly Linear Linked List.
//****************************************************************************************************//


template <class T>

T SinglyLL<T>::SmallestElements()
{
    int iMin = First->data;

    while (First != NULL)
    {
        if (First->data < iMin)
        {
            iMin = First->data;
        }
        First = First->next;
    }
    return iMin;
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : displayAddition
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function returns the Addition of  elements of  singly Linear Linked List.
//****************************************************************************************************//


template <class T>
T SinglyLL<T>::displayAddition()
{
    int Sum = 0;
    if (First == NULL)
    {
        cout << "There is no elements in linked list";
    }
    else
    {
        while (First != NULL)
        {
            Sum = Sum + First->data;
            First = First->next;
        }
    }
    return Sum;
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : displaySecondMax
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function returns the second Maximum elements in  singly Linear Linked List.
//****************************************************************************************************//

template <class T>
T SinglyLL<T>::displaySecondMax()
{
    int Sum = 0;
    int iMax1 = 0;
    int iMax2 = 0;

    if (First == NULL)
    {
        cout << "There is no elements in linked list";
    }
    else
    {

        while (First != NULL)
        {
            if ((First->data) > iMax1)
            {
                iMax2 = iMax1;
                iMax1 = First->data;
            }
            else if ((First->data) > iMax2)
            {
                iMax2 = First->data;
            }
            First = First->next;
        }
    }
    return iMax2;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : SearchElement
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : T iNo
// Description: This  Function checks the elements is present in   singly Linear Linked List or not.
//****************************************************************************************************//


template <class T>
bool SinglyLL<T>::SearchElement(T iNo)
{
    bool flag = false;
    if (First == NULL)
    {
        cout << "There is no elements in linked list";
    }
    else
    {
        while (First != NULL)
        {
            if (First->data == iNo)
            {
                flag = true;
                break;
            }
            First = First->next;
        }
    }
    return flag;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : FrequencyOfElement
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : T iNo
// Description: This  Function returns the Frequency  of element in  singly Linear Linked List.
//****************************************************************************************************//


template <class T>
int SinglyLL<T>::FrequencyOfElement(T iNo)
{
    int Count = 0;
    if (First == NULL)
    {
        cout << "There is no elements in linked list";
    }
    else
    {
        while (First != NULL)
        {
            if (First->data == iNo)
            {
                Count++;
            }
            First = First->next;
        }
    }
    return Count;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : EvenNo
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function returns the even numbers from singly Linear Linked List.
//****************************************************************************************************//

template <>
SinglyLL<int> SinglyLL<int>::EvenNo()
{
    SinglyLL<int> obj;
    bool flag = false;

    if (First == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    while (First != NULL)
    {
        if ((First->data) % 2 == 0)
        {
            flag = true;
            obj.InsertLast(First->data);
        }
        First = First->next;
    }
    if (flag == false)
    {
        cout << "There are no Even elements." << endl;
    }
    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : OddNo
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function returns the Odd numbers from singly Linear Linked List.
//****************************************************************************************************//


template <>
SinglyLL<int> SinglyLL<int>::OddNo()
{
    SinglyLL<int> obj;
    bool flag = false;

    if (First == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    while (First != NULL)
    {
        if ((First->data) % 2 != 0)
        {
            flag = true;
            obj.InsertLast(First->data);
        }
        First = First->next;
    }
    if (flag == false)
    {
        cout << "There are no Even elements." << endl;
    }
    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : DisplayAdditionOfDigit
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function returns the addition of each digit of elements in singly Linear Linked List.
//****************************************************************************************************//


template <>
SinglyLL<int> SinglyLL<int>::DisplayAdditionOfDigit()
{
    SinglyLL<int> obj;
    int Sum;
    int iDigit;

    if (First == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    while (First != NULL)
    {
        Sum = 0;
        while (First->data != 0)
        {
            iDigit = ((First->data) % 10);
            Sum = Sum + iDigit;
            First->data = ((First->data) / 10);
        }
        obj.InsertLast(Sum);

        First = First->next;
    }
    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : DisplayPerfectNo
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function returns the the linked list which contains perfect numbers from given  singly Linear Linked List.
//****************************************************************************************************//

template <>
SinglyLL<int> SinglyLL<int>::DisplayPerfectNo()
{

    SinglyLL<int> obj;
    if (First == NULL)
    {
        cout << "Linked list is empty." << endl;
        return obj;
    }
    else
    {
        while (First != NULL)
        {
            int Sum = 0;

            for (int iCnt = 1; iCnt <= (First->data) / 2; iCnt++)
            {
                if (First->data % iCnt == 0)
                {
                    Sum = Sum + iCnt;
                }
            }

            if (Sum == First->data)
            {
                obj.InsertLast(Sum);
            }

            First = First->next;
        }
    }
    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : DisplayPrimeNo
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function returns the the linked list which contains prime numbers from given  singly Linear Linked List.
//****************************************************************************************************//


template <>
SinglyLL<int> SinglyLL<int>::DisplayPrimeNo()
{
    int iCnt = 0;
    int iTemp;
    SinglyLL<int> obj;

    if (First == NULL)
    {
        printf("Ooops! Linked list is empty:\n");
        return obj;
    }
    else
    {
        while (First != NULL)
        {
            if (First->data == 2)
            {
                obj.InsertLast(First->data);
            }
            for (iCnt = 2; iCnt < (First->data) / 2; iCnt++)
            {

                if ((First->data) % iCnt == 0)
                {
                    iTemp = 0;
                    break;
                }

                {
                    iTemp = 1;
                }
            }
            if (iTemp == 1)
            {
                obj.InsertLast(First->data);
            }
            First = First->next;
        }
    }

    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : SinglyCL
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This class represents the Singly Circular Linked List.
//****************************************************************************************************//


template <class T>
class SinglyCL
{
public:
    struct nodeS<T> *First;
    struct nodeS<T> *Last;

    SinglyCL();
    void InsertFirst(T iNo);
    void InsertLast(T iNo);
    void Display();
    int Count();
    void InsertAtPos(T iNo, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    int CheckFirstOccurence(T iNo);
    int CheckLastOccurence(T iNo);
    T LargestElements();
    T SmallestElements();
    T displayAddition();
    T displaySecondMax();
    bool SearchElement(T iNo);
    int FrequencyOfElement(T iNo);
    SinglyCL<int> EvenNo();
    SinglyCL<int> OddNo();
    SinglyCL<int> DisplayAdditionOfDigit();
    SinglyCL<int> DisplayPerfectNo();
    SinglyCL<int> DisplayPrimeNo();
};

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Counstructor : SinglyCL
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  is the contructor of circular linked  list.
//****************************************************************************************************//


template <class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : InsertFirst
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  is function which insert an elements at First Position in circular linked  list.
//****************************************************************************************************//


template <class T>
void SinglyCL<T>::InsertFirst(T iNo)
{
    struct nodeS<T> *newn = new struct nodeS<T>;
    newn->data = iNo;
    newn->next = NULL;

    if (First == NULL && Last == NULL)
    {
        First = Last = newn;
        Last->next = First;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : InsertLast
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  is function which insert an elements at Last Position in circular linked  list.
//****************************************************************************************************//


template <class T>
void SinglyCL<T>::InsertLast(T iNo)
{
    struct nodeS<T> *newn = new struct nodeS<T>;
    newn->data = iNo;
    newn->next = NULL;

    if (First == NULL && Last == NULL)
    {
        First = Last = newn;
        Last->next = First;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : Display
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This  Function Displays an elements  of singly Circular  Linked List.
//****************************************************************************************************//

template <class T>
void SinglyCL<T>::Display()
{
    cout << "Elements of linked list are:" << endl;
    struct nodeS<T> *temp = First;
    do
    {
        cout << "|" << temp->data << "|->"
             << " ";
        temp = temp->next;
    } while (temp != Last->next);

    cout << "NULL\n";
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : Count
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This  Function Counts the Number of elements  of singly Cicular  Linked List.
//****************************************************************************************************//


template <class T>
int SinglyCL<T>::Count()
{
    int iCnt = 0;
    struct nodeS<T> *temp = First;

    do
    {
        iCnt++;
        temp = temp->next;
    } while (temp != Last->next);
    return iCnt;
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : InsertAtPos
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : [IN] T no,int pos
// Description: This  Function Inserts an elements at specific position of singly Circular Linked List.
//****************************************************************************************************//


template <class T>
void SinglyCL<T>::InsertAtPos(T iNo, int iPos)
{
    struct nodeS<T> *newn = new struct nodeS<T>;
    newn->data = iNo;
    newn->next = NULL;
    struct nodeS<T> *temp = First;

    int iNodeCnt = Count();

    if (iPos < 1 || iPos > iNodeCnt + 1)
    {
        cout << "Invalid Position"
             << "\n";
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == iNodeCnt + 1)
    {
        InsertLast(iNo);
    }

    else
    {
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : DeleteFirst
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This  Function delete  an elements of first position in singly Cicular Linked List.
//****************************************************************************************************//

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if (First == NULL && Last == NULL)
    {
        cout << "Linked list is empty"
             << "\n";
        return;
    }

    else if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        struct nodeS<T> *temp = First;

        First = First->next;

        delete temp;
        temp = NULL;
    }
    Last->next = First;
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : DeleteLast
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This  Function delete  an elements of Last position in singly Linear Linked List.
//****************************************************************************************************//

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if (First == NULL && Last == NULL)
    {
        cout << "Linked list is empty"
             << "\n";
        return;
    }

    else if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        struct nodeS<T> *temp = First;

        while (temp->next != Last)
        {
            temp = temp->next;
        }
        delete temp->next;
        Last = temp;
    }

    Last->next = First;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : DeleteAtPos
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This  Function delete  an elements at specific position in singly Circular Linked List.
//****************************************************************************************************//

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    int iNodeCnt = Count();

    if (iPos < 1 || iPos > iNodeCnt)
    {
        cout << "Invalid Position"
             << "\n";
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iNodeCnt)
    {
        DeleteLast();
    }

    else
    {
        struct nodeS<T> *temp1 = First;
        struct nodeS<T> *temp2 = NULL;

        for (int i = 1; i < iPos - 1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        temp2 = NULL;
    }
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : CheckFirstOccurence
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : T iNo
// Description: This  Function returns the First occurence index of given elements of singly Ciculaar Linked List.
//****************************************************************************************************//


template <class T>
int SinglyCL<T>::CheckFirstOccurence(T iNo)
{
    int iPos = -1;
    int iCount = 1;
    struct nodeS<T> *temp1 = First;
    if (temp1 == NULL)
    {
        printf("there are no elements:\n");
    }

    do
    {
        if (temp1->data == iNo)
        {
            iPos = iCount;
            break;
        }
        iCount++;
        temp1 = temp1->next;
    } while (temp1 != Last->next);

    if (iPos == -1)
    {
        cout << "No such element is present" << endl;
    }
    return iPos;
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : CheckLastOccurence
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : T iNo
// Description: This  Function returns the Last occurence index of given elements of singly Circular Linked List.
//****************************************************************************************************//


template <class T>
int SinglyCL<T>::CheckLastOccurence(T iNo)
{
    int iPos = -1;
    int iCount = 1;
    struct nodeS<T> *temp1 = First;
    if (temp1 == NULL)
    {
        printf("there are no elements:\n");
    }
    do
    {
        if (temp1->data == iNo)
        {
            iPos = iCount;
        }
        iCount++;
        temp1 = temp1->next;
    } while (temp1 != Last->next);

    if (iPos == -1)
    {
        cout << "No such element is present" << endl;
    }
    return iPos;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : LargestElements
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function returns the largest elements in  singly Cicular Linked List.
//****************************************************************************************************//


template <class T>

T SinglyCL<T>::LargestElements()
{
    if (First == NULL)
    {
        cout << "Linked List is Empty." << endl;
    }
    int iMax = First->data;
    do
    {
        if (First->data > iMax)
        {
            iMax = First->data;
        }

        First = First->next;
    } while (First != Last->next);
    return iMax;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : SmallestElements
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function returns the smallest elements in  singly Circular Linked List.
//****************************************************************************************************//


template <class T>

T SinglyCL<T>::SmallestElements()
{
    if (First == NULL)
    {
        cout << "Linked List is Empty." << endl;
    }
    int iMin = First->data;

    do
    {
        if (First->data < iMin)
        {
            iMin = First->data;
        }
        First = First->next;
    } while (First != Last->next);

    return iMin;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : displayAddition
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function returns the addition of elements in  singly Circular Linked List.
//****************************************************************************************************//


template <class T>
T SinglyCL<T>::displayAddition()
{
    int Sum = 0;
    if (First == NULL)
    {
        cout << "There is no elements in linked list";
    }
    else
    {
        do
        {
            Sum = Sum + First->data;
            First = First->next;
        } while (First != Last->next);
    }
    return Sum;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : DisplaySecondMax
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function returns the Second maximum elements in  singly Circular Linked List.
//****************************************************************************************************//


template <class T>
T SinglyCL<T>::displaySecondMax()
{
    int Sum = 0;
    int iMax1 = 0;
    int iMax2 = 0;

    if (First == NULL)
    {
        cout << "There is no elements in linked list";
    }
    else
    {
        do
        {
            if ((First->data) > iMax1)
            {
                iMax2 = iMax1;
                iMax1 = First->data;
            }
            else if ((First->data) > iMax2)
            {
                iMax2 = First->data;
            }
            First = First->next;
        } while (First != Last->next);
    }
    return iMax2;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : SearchElement
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters :  T iNo
// Description: This  Function search the given element is present or not in singly Circular Linked List.
//****************************************************************************************************//




template <class T>
bool SinglyCL<T>::SearchElement(T iNo)
{
    bool flag = false;
    if (First == NULL)
    {
        cout << "There is no elements in linked list";
    }
    else
    {
        do
        {
            if (First->data == iNo)
            {
                flag = true;
                break;
            }
            First = First->next;
        } while (First != Last->next);
    }
    return flag;
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : FrequencyOfElement
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : T iNo
// Description: This  Function returns the Frequency of elements in  singly Circular Linked List.
//****************************************************************************************************//




template <class T>
int SinglyCL<T>::FrequencyOfElement(T iNo)
{
    int Count = 0;
    if (First == NULL)
    {
        cout << "There is no elements in linked list";
    }
    else
    {
        do
        {
            if (First->data == iNo)
            {
                Count++;
            }
            First = First->next;
        } while (First != Last->next);
    }
    return Count;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : EvenNo
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function returns the circular linked list which conatins even numbers in  singly Circular Linked List.
//****************************************************************************************************//



template <>
SinglyCL<int> SinglyCL<int>::EvenNo()
{
    SinglyCL<int> obj;
    bool flag = false;

    if (First == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    do
    {
        if ((First->data) % 2 == 0)
        {
            flag = true;
            obj.InsertLast(First->data);
        }
        First = First->next;
    } while (First != Last->next);
    if (flag == false)
    {
        cout << "There are no Even elements." << endl;
    }
    return obj;
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : OddNo
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function returns the circular linked list which contains odd numbers in  singly Circular Linked List.
//****************************************************************************************************//


template <>
SinglyCL<int> SinglyCL<int>::OddNo()
{
    SinglyCL<int> obj;
    bool flag = false;

    if (First == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    do
    {
        if ((First->data) % 2 != 0)
        {
            flag = true;
            obj.InsertLast(First->data);
        }
        First = First->next;
    } while (First != Last->next);
    if (flag == false)
    {
        cout << "There are no Even elements." << endl;
    }
    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : DisplayAdditionOfProject
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function returns the circular linked list which conatins Addition of Digit in  singly Circular Linked List.
//****************************************************************************************************//


template <>
SinglyCL<int> SinglyCL<int>::DisplayAdditionOfDigit()
{
    SinglyCL<int> obj;
    int Sum;
    int iDigit;

    if (First == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    do
    {
        Sum = 0;
        while (First->data != 0)
        {
            iDigit = ((First->data) % 10);
            Sum = Sum + iDigit;
            First->data = ((First->data) / 10);
        }
        obj.InsertLast(Sum);

        First = First->next;
    } while (First != Last->next);
    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : DisplayPerfectNo
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function returns the circular linked list which conatins perfect numbers in  singly Circular Linked List.
//****************************************************************************************************//


template <>
SinglyCL<int> SinglyCL<int>::DisplayPerfectNo()
{

    SinglyCL<int> obj;
    if (First == NULL)
    {
        cout << "Linked list is empty." << endl;
        return obj;
    }

    do
    {
        int Sum = 0;

        for (int iCnt = 1; iCnt <= (First->data) / 2; iCnt++)
        {
            if (First->data % iCnt == 0)
            {
                Sum = Sum + iCnt;
            }
        }

        if (Sum == First->data)
        {
            obj.InsertLast(Sum);
        }

        First = First->next;
    } while (First != Last->next);

    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : 
// Name of the Author : Pradnya Ramesh Ghodke 
// Date : 13 April 2022
// Parameters : None
// Description: This  Function returns the circular linked list which conatins prime numbers in  singly Circular Linked List.
//****************************************************************************************************//


template <>
SinglyCL<int> SinglyCL<int>::DisplayPrimeNo()
{
    int iCnt = 0;
    int iTemp;
    SinglyCL<int> obj;

    if (First == NULL)
    {
        printf("Ooops! Linked list is empty:\n");
        return obj;
    }
    else
    {
        do
        {
            if (First->data == 2)
            {
                obj.InsertLast(First->data);
            }
            for (iCnt = 2; iCnt < (First->data) / 2; iCnt++)
            {

                if ((First->data) % iCnt == 0)
                {
                    iTemp = 0;
                    break;
                }

                {
                    iTemp = 1;
                }
            }
            if (iTemp == 1)
            {
                obj.InsertLast(First->data);
            }
            First = First->next;
        } while (First != Last->next);
    }

    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : DoublyLL
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for Doubly linear  linked list
//****************************************************************************************************//


template <class T>
class DoublyLL
{
public:
    struct nodeD<T> *First;

    DoublyLL();
    void InsertFirst(T iNo);
    void InsertLast(T iNo);
    void Display();
    int Count();
    void InsertAtPos(T data, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

    int CheckFirstOccurence(T iNo);
    int CheckLastOccurence(T iNo);
    T LargestElements();
    T SmallestElements();
    T displayAddition();
    T displaySecondMax();
    bool SearchElement(T iNo);
    int FrequencyOfElement(T iNo);
    DoublyLL<int> EvenNo();
    DoublyLL<int> OddNo();
    DoublyLL<int> DisplayAdditionOfDigit();
    DoublyLL<int> DisplayPerfectNo();
    DoublyLL<int> DisplayPrimeNo();
};
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the constructor : DoublyLL
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the constructor for Doubly linear  linked list
//****************************************************************************************************//



template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : InsertFirst
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T iNo
// Description: This is the Function which insert elements at first position in  Doubly linear  linked list
//****************************************************************************************************//


template <class T>
void DoublyLL<T>::InsertFirst(T iNo)
{
    struct nodeD<T> *newn = new struct nodeD<T>;

    newn->data = iNo;
    newn->prev = NULL;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : InsertLast
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T iNo
// Description: This is the Function which insert elements at last position in  Doubly linear  linked list
//****************************************************************************************************//

template <class T>
void DoublyLL<T>::InsertLast(T iNo)
{
    struct nodeD<T> *newn = new struct nodeD<T>;

    newn->data = iNo;
    newn->prev = NULL;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeD<T> *temp = First;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : Display
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which Display elements in  Doubly linear  linked list
//****************************************************************************************************//


template <class T>
void DoublyLL<T>::Display()
{
    struct nodeD<T> *temp = First;

    cout << "Elements of linked list are:"
         << "\n";
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|=>";
        temp = temp->next;
    }
    cout << "\n";
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : Count
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which  count elements in  Doubly linear  linked list
//****************************************************************************************************//


template <class T>
int DoublyLL<T>::Count()
{
    struct nodeD<T> *temp = First;
    int iCnt = 0;

    cout << "Elements of linked list are:"
         << "\n";
    while (temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : InsertAtPos
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T iNo,Pos
// Description: This is the Function which Insert element at Perticular position in  Doubly linear  linked list
//****************************************************************************************************//

template <class T>
void DoublyLL<T>::InsertAtPos(T iNo, int iPos)
{
    struct nodeD<T> *newn = new struct nodeD<T>;

    newn->data = iNo;
    newn->prev = NULL;
    newn->next = NULL;

    int iNodeCnt = Count();

    if (iPos < 1 || iPos > iNodeCnt + 1)
    {
        cout << "Invalid Position"
             << "\n";
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == iNodeCnt + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        struct nodeD<T> *temp = First;

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : DeleteFirst
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which Delete  elements at First Position in  Doubly linear  linked list
//****************************************************************************************************//

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (First == NULL)
    {
        cout << "linked list is empty"
             << "\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete (First);
        First = NULL;
    }
    else
    {
        First = First->next;
        delete (First->prev);
        First->prev = NULL;
    }
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : DeleteLast
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which delete  elements at last position in  Doubly linear  linked list
//****************************************************************************************************//

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if (First == NULL)
    {
        cout << "linked list is empty"
             << "\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete (First);
        First = NULL;
    }
    else
    {
        struct nodeD<T> *temp = First;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : DeleteAtPos
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : int Pos
// Description: This is the Function which Display elements in  Doubly linear  linked list
//****************************************************************************************************//

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{

    int iNodeCnt = Count();

    if (iPos < 1 || iPos > iNodeCnt + 1)
    {
        cout << "Invalid Position"
             << "\n";
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iNodeCnt + 1)
    {
        DeleteLast();
    }
    else
    {
        struct nodeD<T> *temp = First;
        struct nodeD<T> *temp2 = NULL;

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp->next->next;
        temp->next->next->prev = temp;
        free(temp2);
    }
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : CheckFirstOccurence
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T iNo
// Description: This is the Function which Display elements First occurence in Doubly linear  linked list
//****************************************************************************************************//


template <class T>
int DoublyLL<T>::CheckFirstOccurence(T iNo)
{
    int iPos = -1;
    int Counter = 1;

    int iCount = 0, iTemp = -1;
    struct nodeD<T> *temp1 = First;
    if (temp1 == NULL)
    {
        printf("there are no elements:\n");
    }

    for (iCount = 1; temp1 != NULL; iCount++)
    {
        if (temp1->data == iNo)
        {
            iTemp = iCount;
            break;
        }
        temp1 = temp1->next;
    }

    if (iTemp == -1)
    {
        cout << "No such element is present" << endl;
    }
    return iTemp;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : CheckLastOccurence
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T iNo
// Description: This is the Function which Display elements Last occurence in Doubly linear  linked list
//****************************************************************************************************//



template <class T>
int DoublyLL<T>::CheckLastOccurence(T iNo)
{
    int iPos = -1;
    int Counter = 1;

    int iCount = 0, iTemp = -1;
    struct nodeD<T> *temp1 = First;
    if (temp1 == NULL)
    {
        printf("there are no elements:\n");
    }
    else
    {
        for (iCount = 1; temp1 != NULL; iCount++)
        {
            if (temp1->data == iNo)
            {
                iTemp = iCount;
            }
            temp1 = temp1->next;
        }
    }
    if (iTemp == -1)
    {
        cout << "No such element is present" << endl;
    }
    return iTemp;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : LargestElements
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which Display Largest elements From Doubly linear  linked list
//****************************************************************************************************//



template <class T>

T DoublyLL<T>::LargestElements()
{
    struct nodeD<T> *temp = First;
    int iMax = temp->data;

    while (temp != NULL)
    {
        if (temp->data > iMax)
        {
            iMax = temp->data;
        }
        temp = temp->next;
    }
    return iMax;
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function: SmallestElements
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which Display Smallest elements From Doubly linear  linked list
//****************************************************************************************************//


template <class T>

T DoublyLL<T>::SmallestElements()
{
    struct nodeD<T> *temp = First;
    int iMin = temp->data;

    while (temp != NULL)
    {
        if (temp->data < iMin)
        {
            iMin = temp->data;
        }
        temp = temp->next;
    }
    return iMin;
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : displayAddition
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which Display Addition of all  elements in Doubly linear  linked list
//****************************************************************************************************//


template <class T>
T DoublyLL<T>::displayAddition()
{
    struct nodeD<T> *temp = First;
    int Sum = 0;
    if (temp == NULL)
    {
        cout << "There is no elements in linked list";
    }
    else
    {
        while (temp != NULL)
        {
            Sum = Sum + temp->data;
            temp = temp->next;
        }
    }
    return Sum;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function: displaySecondMax
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which Display Second Largest elements From Doubly linear  linked list
//****************************************************************************************************//


template <class T>
T DoublyLL<T>::displaySecondMax()
{
    struct nodeD<T> *temp = First;
    int Sum = 0;
    int iMax1 = 0;
    int iMax2 = 0;

    if (temp == NULL)
    {
        cout << "There is no elements in linked list";
    }
    else
    {

        while (temp != NULL)
        {
            if ((temp->data) > iMax1)
            {
                iMax2 = iMax1;
                iMax1 = temp->data;
            }
            else if ((temp->data) > iMax2)
            {
                iMax2 = temp->data;
            }
            temp = temp->next;
        }
    }
    return iMax2;
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : SearchElement
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T iNo
// Description: This is the Function which Display true if element is present or false if elements is not present in Doubly linear  linked list
//****************************************************************************************************//


template <class T>
bool DoublyLL<T>::SearchElement(T iNo)
{
    struct nodeD<T> *temp = First;
    bool flag = false;
    if (temp == NULL)
    {
        cout << "There is no elements in linked list";
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->data == iNo)
            {
                flag = true;
                break;
            }
            temp = temp->next;
        }
    }
    return flag;
}
//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : FrequencyOfElement
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T iNo
// Description: This is the Function returns the Freuency of givrn element From Doubly linear  linked list
//****************************************************************************************************//


template <class T>
int DoublyLL<T>::FrequencyOfElement(T iNo)
{
    struct nodeD<T> *temp = First;
    int Count = 0;
    if (temp == NULL)
    {
        cout << "There is no elements in linked list";
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->data == iNo)
            {
                Count++;
            }
            temp = temp->next;
        }
    }
    return Count;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : EvenNo
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which Display the linked list which contain even No From Doubly linear  linked list
//****************************************************************************************************//


template <>
DoublyLL<int> DoublyLL<int>::EvenNo()
{
    struct nodeD<int> *temp = First;
    DoublyLL<int> obj;
    bool flag = false;

    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    while (temp != NULL)
    {
        if ((temp->data) % 2 == 0)
        {
            flag = true;
            obj.InsertLast(temp->data);
        }
        temp = temp->next;
    }
    if (flag == false)
    {
        cout << "There are no Even elements." << endl;
    }
    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : OddNo
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which Display the linked list which contain Odd No From Doubly linear  linked list
//****************************************************************************************************//


template <>
DoublyLL<int> DoublyLL<int>::OddNo()
{
    struct nodeD<int> *temp = First;
    DoublyLL<int> obj;
    bool flag = false;

    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    while (temp != NULL)
    {
        if ((temp->data) % 2 != 0)
        {
            flag = true;
            obj.InsertLast(temp->data);
        }
        temp = temp->next;
    }
    if (flag == false)
    {
        cout << "There are no Even elements." << endl;
    }
    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : DisplayAdditionOfDigit
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which Display the linked list which contain addition of digit of each element  of Doubly linear  linked list
//****************************************************************************************************//

template <>
DoublyLL<int> DoublyLL<int>::DisplayAdditionOfDigit()
{
    struct nodeD<int> *temp = First;
    DoublyLL<int> obj;
    int Sum;
    int iDigit;

    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    while (temp != NULL)
    {
        Sum = 0;
        while (temp->data != 0)
        {
            iDigit = ((temp->data) % 10);
            Sum = Sum + iDigit;
            temp->data = ((temp->data) / 10);
        }
        obj.InsertLast(Sum);

        temp = temp->next;
    }
    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : DisplayPerfectNo
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which Display the linked list which contain Perfects No From Doubly linear  linked list
//****************************************************************************************************//

template <>
DoublyLL<int> DoublyLL<int>::DisplayPerfectNo()
{
    struct nodeD<int> *temp = First;
    DoublyLL<int> obj;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
        return obj;
    }
    else
    {
        while (temp != NULL)
        {
            int Sum = 0;

            for (int iCnt = 1; iCnt <= (temp->data) / 2; iCnt++)
            {
                if (temp->data % iCnt == 0)
                {
                    Sum = Sum + iCnt;
                }
            }

            if (Sum == temp->data)
            {
                obj.InsertLast(Sum);
            }

            temp = temp->next;
        }
    }
    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : PrimeNo
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which Display the linked list which contain Prime No From Doubly linear  linked list
//****************************************************************************************************//


template <>
DoublyLL<int> DoublyLL<int>::DisplayPrimeNo()
{
    struct nodeD<int> *temp = First;
    int iCnt = 0;
    int iTemp;
    DoublyLL<int> obj;

    if (temp == NULL)
    {
        printf("Ooops! Linked list is empty:\n");
        return obj;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->data == 2)
            {
                obj.InsertLast(temp->data);
            }
            for (iCnt = 2; iCnt < (temp->data) / 2; iCnt++)
            {

                if ((temp->data) % iCnt == 0)
                {
                    iTemp = 0;
                    break;
                }

                {
                    iTemp = 1;
                }
            }
            if (iTemp == 1)
            {
                obj.InsertLast(temp->data);
            }
            temp = temp->next;
        }
    }

    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : DoublyCL
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the class which contain all functions of  Doubly circular  linked list
//****************************************************************************************************//


template <class T>
class DoublyCL
{
public:
    struct nodeD<T> *First;
    struct nodeD<T> *Last;

    DoublyCL();
    void InsertFirst(T iNo);
    void InsertLast(T iNo);
    void Display();
    int Count();
    void InsertAtPos(T iNo, int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    int CheckFirstOccurence(T iNo);
    int CheckLastOccurence(T iNo);
    T LargestElements();
    T SmallestElements();
    T displayAddition();
    T displaySecondMax();
    bool SearchElement(T iNo);
    int FrequencyOfElement(T iNo);
    DoublyCL<int> EvenNo();
    DoublyCL<int> OddNo();
    DoublyCL<int> DisplayAdditionOfDigit();
    DoublyCL<int> DisplayPerfectNo();
    DoublyCL<int> DisplayPrimeNo();
};

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Constructor : DoublyLL
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the constructor for Doubly circular linked list
//****************************************************************************************************//

template <class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : InsertFirst
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T iNo
// Description: This is the Function which is used to insert an elements at First Position in  Doubly circular  linked list
//****************************************************************************************************//



template <class T>
void DoublyCL<T>::InsertFirst(T iNo)
{
    struct nodeD<T> *newn = new struct nodeD<T>;

    newn->data = iNo;
    newn->prev = NULL;
    newn->next = NULL;

    if (First == NULL && Last == NULL)
    {
        First = Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    First->prev = Last;
    Last->next = newn;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : InsertLast
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T iNo
// Description: This is the Function which is used to insert an elements at Last Position in  Doubly circular  linked list
//****************************************************************************************************//

template <class T>
void DoublyCL<T>::InsertLast(T iNo)
{
    struct nodeD<T> *newn = new struct nodeD<T>;

    newn->data = iNo;
    newn->prev = NULL;
    newn->next = NULL;

    if (First == NULL && Last == NULL)
    {
        First = Last = newn;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    First->prev = Last;
    Last->next = First;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : Display
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which is used to display all  elements from  Doubly circular  linked list
//****************************************************************************************************//

template <class T>
void DoublyCL<T>::Display()
{
    struct nodeD<T> *temp = First;
    cout << "Elements of Linked List are:"
         << "\n";
    do
    {
        cout << "|" << temp->data << "|->"
             << " ";
        temp = temp->next;
    } while (temp != Last->next);
    cout << "NULL"
         << "\n";
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : Count
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which return the count of elements in Doubly circular  linked list
//****************************************************************************************************//

template <class T>
int DoublyCL<T>::Count()
{
    struct nodeD<T> *temp = First;
    int iCnt = 0;

    do
    {
        iCnt++;
        temp = temp->next;
    } while (temp != Last->next);
    return iCnt;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : InsertAtPos
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T iNo,int iPos
// Description: This is the Function which is used to insert an elements at perticular Position in  Doubly circular  linked list
//****************************************************************************************************//

template <class T>
void DoublyCL<T>::InsertAtPos(T iNo, int iPos)
{
    struct nodeD<T> *newn = new struct nodeD<T>;

    newn->data = iNo;
    newn->prev = NULL;
    newn->next = NULL;

    int iNodeCnt = Count();

    if (iPos < 1 || iPos > iNodeCnt + 1)
    {
        cout << "Invalid Position"
             << "\n";
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == iNodeCnt + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        struct nodeD<T> *temp = First;

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
    }
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : DeleteFirst
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which is used to Delete  First Position element in  Doubly circular  linked list
//****************************************************************************************************//

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if (First == NULL && Last == NULL)
    {
        cout << "Linked list is Empty"
             << "\n";
        return;
    }
    else if (First == Last)

    {
        delete First;
        First = Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
    }
    First->prev = Last;
    Last->next = First;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : DeleteLast
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T iNo
// Description: This is the Function which is used to Delete an elements from last Position in  Doubly circular  linked list
//****************************************************************************************************//

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if (First == NULL && Last == NULL)
    {
        cout << "Linked list is Empty"
             << "\n";
        return;
    }
    else if (First == Last)

    {
        delete First;
        First = Last = NULL;
    }
    else
    {
        Last = Last->prev;
        delete (First)->prev;
    }
    First->prev = Last;
    Last->next = First;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : DeleteAtPos
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : int iPos
// Description: This is the Function which is used to Delete an elements at perticular Position in  Doubly circular  linked list
//****************************************************************************************************//

template <class T>
void DoublyCL<T>::DeleteAtPos(int ipos)
{
    int iNodeCnt = Count();
    struct nodeD<T> *temp = NULL;
    int iCnt = 0;

    if ((ipos < 1) || (ipos > iNodeCnt))
    {
        cout << "Invalid position"
             << "\n";
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for (iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;
    }
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : CheckFirstOccurence
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T iNo
// Description: This is the Function which is used to check the  First occurance of a element in  Doubly circular  linked list
//****************************************************************************************************//


template <class T>
int DoublyCL<T>::CheckFirstOccurence(T iNo)
{
    int iPos = -1, iCount = 1;
    struct nodeD<T> *temp1 = First;
    if (temp1 == NULL)
    {
        printf("there are no elements:\n");
    }

    do
    {
        if (temp1->data == iNo)
        {
            iPos = iCount;
            break;
        }
        iCount++;
        temp1 = temp1->next;
    } while (temp1 != Last->next);

    if (iPos == -1)
    {
        cout << "No such element is present" << endl;
    }
    return iPos;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : checkLastOccurence
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T iNo
// Description: This is the Function which is used to check last occurence of a element  in  Doubly circular  linked list
//****************************************************************************************************//


template <class T>
int DoublyCL<T>::CheckLastOccurence(T iNo)
{
    int iPos = -1;

    int iCount = 1;
    struct nodeD<T> *temp1 = First;
    if (temp1 == NULL)
    {
        printf("there are no elements:\n");
    }
    do
    {
        if (temp1->data == iNo)
        {
            iPos = iCount;
        }
        iCount++;
        temp1 = temp1->next;
    } while (temp1 != Last->next);

    if (iPos == -1)
    {
        cout << "No such element is present" << endl;
    }
    return iPos;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : LargestElements
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which is used to Display Largest elements from  Doubly circular  linked list
//****************************************************************************************************//


template <class T>

T DoublyCL<T>::LargestElements()
{
    struct nodeD<T> *temp = First;
    int iMax = temp->data;

    do
    {
        if (temp->data > iMax)
        {
            iMax = temp->data;
        }
        temp = temp->next;
    } while (temp != Last->next);
    return iMax;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : SmallestElements
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T iNo
// Description: This is the Function which is used to return smallest element from Doubly circular  linked list
//****************************************************************************************************//


template <class T>

T DoublyCL<T>::SmallestElements()
{
    struct nodeD<T> *temp = First;
    int iMin = temp->data;
    do
    {
        if (temp->data < iMin)
        {
            iMin = temp->data;
        }
        temp = temp->next;
    } while (temp != Last->next);
    return iMin;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : displayAddition
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which is used to display addition of elements from  Doubly circular  linked list
//****************************************************************************************************//


template <class T>
T DoublyCL<T>::displayAddition()
{
    struct nodeD<T> *temp = First;
    int Sum = 0;
    if (temp == NULL)
    {
        cout << "There is no elements in linked list";
    }
    do
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    } while (temp != Last->next);

    return Sum;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : displaySecondMax
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T iNo
// Description: This is the Function which is used to display second maximum element from Doubly circular  linked list
//****************************************************************************************************//


template <class T>
T DoublyCL<T>::displaySecondMax()
{
    struct nodeD<T> *temp = First;
    int Sum = 0;
    int iMax1 = 0;
    int iMax2 = 0;

    if (temp == NULL)
    {
        cout << "There is no elements in linked list";
    }
    do
    {
        if ((temp->data) > iMax1)
        {
            iMax2 = iMax1;
            iMax1 = temp->data;
        }
        else if ((temp->data) > iMax2)
        {
            iMax2 = temp->data;
        }
        temp = temp->next;
    } while (temp != Last->next);

    return iMax2;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : SearchElement
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T iNo
// Description: This is the Function which is used to display true if element is presentor false if element is not present  in  Doubly circular  linked list
//****************************************************************************************************//


template <class T>
bool DoublyCL<T>::SearchElement(T iNo)
{
    struct nodeD<T> *temp = First;
    bool flag = false;
    if (temp == NULL)
    {
        cout << "There is no elements in linked list";
    }
    do
    {
        if (temp->data == iNo)
        {
            flag = true;
            break;
        }
        temp = temp->next;
    } while (temp != Last->next);

    return flag;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : FrequencyOfElement
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T iNo
// Description: This is the Function which is used to display frequency of a element from Doubly circular  linked list
//****************************************************************************************************//

template <class T>
int DoublyCL<T>::FrequencyOfElement(T iNo)
{
    struct nodeD<T> *temp = First;
    int Count = 0;
    if (temp == NULL)
    {
        cout << "There is no elements in linked list";
    }
    do

    {
        if (temp->data == iNo)
        {
            Count++;
        }
        temp = temp->next;
    } while (temp != Last->next);

    return Count;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : EvenNo
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which is used display a linked list which contain even no from  Doubly circular  linked list
//****************************************************************************************************//


template <>
DoublyCL<int> DoublyCL<int>::EvenNo()
{
    struct nodeD<int> *temp = First;
    DoublyCL<int> obj;
    bool flag = false;

    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    do
    {
        if ((temp->data) % 2 == 0)
        {
            flag = true;
            obj.InsertLast(temp->data);
        }
        temp = temp->next;
    } while (temp != Last->next);
    if (flag == false)
    {
        cout << "There are no Even elements." << endl;
    }
    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : OddNo
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which is used display a linked list which contain Odd no from  Doubly circular  linked list
//****************************************************************************************************//


template <>
DoublyCL<int> DoublyCL<int>::OddNo()
{
    struct nodeD<int> *temp = First;
    DoublyCL<int> obj;
    bool flag = false;

    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    do
    {
        if ((temp->data) % 2 != 0)
        {
            flag = true;
            obj.InsertLast(temp->data);
        }
        temp = temp->next;
    } while (temp != Last->next);
    if (flag == false)
    {
        cout << "There are no Even elements." << endl;
    }
    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : DisplayAdditionOfDigit
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which is used display a linked list which conatin addition of digits of each element from  Doubly circular  linked list
//****************************************************************************************************//


template <>
DoublyCL<int> DoublyCL<int>::DisplayAdditionOfDigit()
{
    struct nodeD<int> *temp = First;
    DoublyCL<int> obj;
    int Sum;
    int iDigit;

    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
    }
    do
    {
        Sum = 0;
        while (temp->data != 0)
        {
            iDigit = ((temp->data) % 10);
            Sum = Sum + iDigit;
            temp->data = ((temp->data) / 10);
        }
        obj.InsertLast(Sum);

        temp = temp->next;
    } while (temp != Last->next);
    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : DisplayPerfectNo
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which is used display a linked list which contain perfect no from  Doubly circular  linked list
//****************************************************************************************************//

template <>
DoublyCL<int> DoublyCL<int>::DisplayPerfectNo()
{
    struct nodeD<int> *temp = First;
    DoublyCL<int> obj;
    if (temp == NULL)
    {
        cout << "Linked list is empty." << endl;
        return obj;
    }
    do

    {
        int Sum = 0;

        for (int iCnt = 1; iCnt <= (temp->data) / 2; iCnt++)
        {
            if (temp->data % iCnt == 0)
            {
                Sum = Sum + iCnt;
            }
        }

        if (Sum == temp->data)
        {
            obj.InsertLast(Sum);
        }

        temp = temp->next;
    } while (temp != Last->next);

    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : PrimeNo
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which is used display a linked list which contain Prime no from  Doubly circular  linked list
//****************************************************************************************************//


template <>
DoublyCL<int> DoublyCL<int>::DisplayPrimeNo()
{
    struct nodeD<int> *temp = First;
    int iCnt = 0;
    int iTemp;
    DoublyCL<int> obj;

    if (temp == NULL)
    {
        printf("Ooops! Linked list is empty:\n");
        return obj;
    }
    do

    {
        if (temp->data == 2)
        {
            obj.InsertLast(temp->data);
        }
        for (iCnt = 2; iCnt < (temp->data) / 2; iCnt++)
        {

            if ((temp->data) % iCnt == 0)
            {
                iTemp = 0;
                break;
            }

            {
                iTemp = 1;
            }
        }
        if (iTemp == 1)
        {
            obj.InsertLast(temp->data);
        }
        temp = temp->next;

    } while (temp != Last->next);

    return obj;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : Stack
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for stack.
//****************************************************************************************************//


template <class T>
class Stack
{
public:
    struct nodeS<T> *First;
    int iCount;

    Stack();
    bool IsStackEmpty();
    void Push(T no);
    T Pop();
    void Display();
};

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the : Constructor 
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the constructor for stack.
//****************************************************************************************************//



template <class T>

Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : IsStackEmpty
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the function which display true if stack has no elements or false if stack is not empty. 
//****************************************************************************************************//


template <class T>

bool Stack<T>::IsStackEmpty()
{
    if (iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : Push
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T no
// Description: This is the function which is used to insert an elements in the stack.
//****************************************************************************************************//

template <class T>

void Stack<T>::Push(T no) // InsertFirst
{
    struct nodeS<T> *newn = new nodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;

    cout << no << "gets pushed in the stack successfully"
         << "\n";
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : Pop
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function to delete an elements from stack.
//****************************************************************************************************//


template <class T>

T Stack<T>::Pop() // DeleteFirst
{
    if (First == NULL)
    {
        cout << "Unable to pop the element as stack empty."
             << "\n";
        return -1;
    }
    else
    {
        T value = First->data;

        struct nodeS<T> *temp = First;

        First = First->next;
        delete temp;

        iCount--;
        return value;
    }
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : Display
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which Display all Elements of stack.
//****************************************************************************************************//



template <class T>
void Stack<T>::Display()
{
    if (First == NULL)
    {
        cout << "Stack is empty."
             << "\n";
    }
    else
    {
        cout << "Elements of stack are:"
             << "\n";

        struct nodeS<T> *temp = First;
        while (temp != NULL)
        {
            cout << "|" << temp->data << "|";
            temp = temp->next;
        }
        cout << "NULL"
             << "\n";
    }
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Class : Queue
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for Queue.
//****************************************************************************************************//


template <class T>
class Queue
{
public:
    struct nodeS<T> *First;
    int iCount;

    Queue();
    bool IsQueueEmpty();
    void EnQueue(T no);
    int DeQueue();
    void Display();
};

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Constructor : Queue
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the constructor for Queue.
//****************************************************************************************************//




template <class T>
Queue<T>::Queue()

{
    First = NULL;
    iCount = 0;
}
template <class T>
bool Queue<T>::IsQueueEmpty()
{
    if (iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : EnQueue
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : T iNo
// Description: This is the Function which display elements in a Queue.
//****************************************************************************************************//


template <class T>
void Queue<T>::EnQueue(T no) // InsertLast
{
    struct nodeS<T> *newn = new nodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeS<T> *temp = First;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;

    cout << no << "gets pushed in the Queue successfully"
         << "\n";
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the  Function: DeQueue
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the class which is used to delete an elements from Queue.
//****************************************************************************************************//


template <class T>
int Queue<T>::DeQueue() // DeleteFirst
{
    if (First == NULL)
    {
        cout << "Unable to pop the element as Queue empty."
             << "\n";
        return -1;
    }
    else
    {
        T value = First->data;

        struct nodeS<T> *temp = First;

        First = First->next;
        delete temp;

        iCount--;
        return value;
    }
}

//******************************************************************************************************//
// Name of the Project :Customized Generalized Standard Template Library
// Name of the Function : Display
// Name of the Author : Pradnya Ramesh Ghodke
// Date : 13 April 2022
// Parameters : None
// Description: This is the Function which display all elements from Queue.
//****************************************************************************************************//



template <class T>
void Queue<T>::Display()
{
    if (First == NULL)
    {
        cout << "Queue is empty."
             << "\n";
    }
    else
    {
        cout << "Elements of Queue are:"
             << "\n";

        struct nodeS<T> *temp = First;
        while (temp != NULL)
        {
            cout << "|" << temp->data << "|";
            temp = temp->next;
        }
        cout << "NULL"
             << "\n";
    }
}

// This is the main class.//
 
int main()
{
    
    return 0;
}