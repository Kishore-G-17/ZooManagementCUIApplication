#include "AnimalDetails.h"

void AnimalDetails::setName(char *name)
{
    this->name = name;
}
void AnimalDetails::setAge(int age)
{
    this->age = age;
}
void AnimalDetails::setBreakFastTime(float break_fast_time)
{
    this->break_fast_time = break_fast_time;
}
void AnimalDetails::setLunchTime(float lunch_time)
{
    this->lunch_time = lunch_time;
}
void AnimalDetails::setDinnerTime(float dinner_time)
{
    this->dinner_time = dinner_time;
}
char *AnimalDetails::getName()
{
    return (this->name);
}
int AnimalDetails::getAge()
{
    return (this->age);
}
float AnimalDetails::getBreakFastTime()
{
    return (this->break_fast_time);
}
float AnimalDetails::getLunchTime()
{
    return (this->lunch_time);
}
float AnimalDetails::getDinnerTime()
{
    return (this->dinner_time);
}
void AnimalDetails::MemoryAllocationForName()
{
    this->name = new char[30];
}
int A_list::getSize()
{
    return this->size;
}
int A_list::getCapacity()
{
    return this->capacity;
}
int A_list::getAgeForCheckingAnimalExistence(int position)
{
    return (arr[position - 1].getAge());
}
char *A_list::getNameForCheckingAnimalExistence(int position)
{
    return (arr[position - 1].getName());
}
A_list::A_list(int capacity, int size) //parameterized constructor
{
    this->capacity = capacity;
    this->size = size;
    this->arr = new AnimalDetails[capacity];
    for (int i = 0; i < capacity; i++)
    {
        arr[i].setAge(-1);
        arr[i].MemoryAllocationForName();
    }
}
int A_list::InsertAtFirst(A_list *List, int position, AnimalDetails temp)
{
    if (isFull(List))
    {
        return 0;
    }
    else
    {
        List->size = size + 1;
        List->arr[position] = temp;
        return 1;
    }
}
int A_list::isFull(A_list *List)
{
    if ((List->size) >= (List->capacity))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int A_list::isEmpty(A_list *List)
{
    if (List->size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int A_list::Display(A_list *List)
{
    if (isEmpty(List))
    {
        return 0;
    }
    else
    {
        cout << endl
             << "********************************** Animal Details **************************************************************" << endl
             << endl;
        for (int i = 0; i < (List->capacity); i++)
        {
            if (arr[i].getAge() != -1)
            {
                DisplayOneAnimal(i);
            }
        }
        cout << endl
             << endl
             << "******************************************************************************************************************" << endl;
        return 1;
    }
}
int A_list::InsertAtLast(A_list *List, AnimalDetails temp)
{
    if (isFull(List))
    {
        return 0;
    }
    else
    {
        arr[size] = temp;
        size = size + 1;
        return 1;
    }
}
void A_list::InsertAtSpecificPosition(A_list *List, int position,AnimalDetails temp,bool isNew)
{
    List->arr[position - 1] = temp;
    if(isNew)
    {
        size=size+1;
    }
}
char* A_list::DeleteAtFirst(A_list *List)
{
    if (isEmpty(List))
    {
        return NULL;
    }
    else
    {
        int i;
        char *nme=arr[0].getName();
        for (i = 0; i < (size - 1); i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[i].setName("");
        arr[i].setAge(-1);
        arr[i].setBreakFastTime(0);
        arr[i].setLunchTime(0);
        arr[i].setDinnerTime(0);
        size = size - 1;
        return nme;
    }
}
char* A_list::DeleteAtLast(A_list *List)
{
    if (isEmpty(List))
    {
        return NULL;
    }
    else
    {
        char *nme=arr[size - 1].getName();
        arr[size - 1].setName("");
        arr[size - 1].setAge(-1);
        arr[size - 1].setBreakFastTime(0);
        arr[size - 1].setLunchTime(0);
        arr[size - 1].setDinnerTime(0);
        size = size - 1;
        return nme;
    }
}
char* A_list::DeleteAtSpecificPosition(A_list *List, int position)
{
    if (isEmpty(List))
    {
        return NULL;
    }
    else
    {
        int i;   
        char* nme=arr[position - 1].getName();
        for (i = (position - 1); i < (capacity - 1); i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[i].setName("");
        arr[i].setAge(-1);
        arr[i].setBreakFastTime(0);
        arr[i].setLunchTime(0);
        arr[i].setDinnerTime(0);
        size = size - 1;
        return nme;
    }

}
int A_list::DeleteUsingAnimalName(A_list *List,char* name)
{
    if (isEmpty(List))
    {
        return 0;
    }
    else
    {
        int i, flag = 0, j;
        for (i = 0; i < capacity; i++)
        {
            if (strcmp(arr[i].getName(),name) == 0)
            {
                flag = 1;
                for (j = i; j < (size - 1); j++)
                {
                    arr[j] = arr[j + 1];
                }
                arr[j].setName("");
                arr[j].setAge(-1);
                arr[j].setBreakFastTime(0);
                arr[j].setLunchTime(0);
                arr[j].setDinnerTime(0);
                break;
            }
        }
        if (flag == 0)
        {
            return 1;
        }
        else
        {
            size = size - 1;
            return (i+1);
        }
    }
}
int A_list::SearchAnAnimal(A_list *List, char *name)
{
    if (isEmpty(List))
    {
        return 0;
    }
    else
    {
        int i, flag = 0, j;
        for (i = 0; i < size; i++)
        {
            if (strcmp(arr[i].getName(),name) == 0)
            {
                flag = 1;
                DisplayOneAnimal(i);
                break;
            }
        }
        if (flag == 0)
        {
            return 1;
        }
        else
        {
            return 2;
        }
        
    }
}
int A_list::Sorting(A_list *List)
{
    if (isEmpty(List))
    {
        return 0;
    }
    else
    {
        AnimalDetails temp;
        int i, flag = 0, j;
        for (i = 0; i < (size - 1); i++)
        {
            for (j = (i + 1); j < size; j++)
            {

                if (arr[i].getAge() > arr[j].getAge())
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;

                    break;
                }
            }
        }
        return 1;
    }
}
void A_list::DisplayOneAnimal(int i)
{
    cout << "               ********************** Animal " << (i + 1) << " **********************************" << endl
        << endl;
    cout << "                         Name          : " << arr[i].getName() << endl;
    cout << "                         Age           : " << arr[i].getAge()<< endl;
    cout << "                         Breakfast time: " << arr[i].getBreakFastTime() << endl;
    cout << "                         Lunch time    : " << arr[i].getLunchTime()<< endl;
    cout << "                         Dinner time   : " << arr[i].getDinnerTime()<< endl
        << endl;
    cout << "               ******************************************************************" << endl
        << endl;

}
