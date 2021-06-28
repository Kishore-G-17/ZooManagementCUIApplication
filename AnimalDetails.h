/*                    Exercise -1                                     */

/*         List ADT implementation using dynamic arrays                     */
/*                 Zoo animals management                                   */
/* In this application , I am going to manipulate zoo animal details        */

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class AnimalDetails
{
    private:
        char *name;
        int age;
        float break_fast_time, dinner_time, lunch_time;

    public:
        void setName(char *);
        void setAge(int);
        void setBreakFastTime(float);
        void setLunchTime(float);
        void setDinnerTime(float);

        char *getName();
        int getAge();
        float getBreakFastTime();
        float getLunchTime();
        float getDinnerTime();

        void MemoryAllocationForName();
};
sample

class A_list
{
    private:
        AnimalDetails *arr;
        int size, capacity;

    public:
        A_list(int, int);
        int InsertAtFirst(A_list *, int, AnimalDetails);
        int InsertAtLast(A_list *, AnimalDetails);
        void InsertAtSpecificPosition(A_list *, int,AnimalDetails,bool);
        int isFull(A_list *);
        int isEmpty(A_list *);
        int Display(A_list *);
        char* DeleteAtFirst(A_list *);
        char* DeleteAtLast(A_list *);
        char* DeleteAtSpecificPosition(A_list *, int);
        int DeleteUsingAnimalName(A_list *,char*);
        int SearchAnAnimal(A_list *, char *);
        int Sorting(A_list *);
        int getCapacity();
        int getSize();
        int getAgeForCheckingAnimalExistence(int);
        char *getNameForCheckingAnimalExistence(int);
        void DisplayOneAnimal(int);
};
int calculateAge();