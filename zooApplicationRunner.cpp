#include "AnimalDetails.h"
A_list *List = NULL;
int main()
{
    int option_for_operations;
    do
    {

        cout << endl
             << "******************** Welcome to zoo ************************" << endl
             << endl;
        cout << "                 1.Create list for storing data        " << endl;
        cout << "                 2.Add an animal at first              " << endl;
        cout << "                 3.Add an animal at last               " << endl;
        cout << "                 4.Add an animal at specific position  " << endl;
        cout << "                 5.Remove an animal at first           " << endl;
        cout << "                 6.Remove an animal at last            " << endl;
        cout << "                 7.Remove an animal at specific position" << endl;
        cout << "                 8.Display animal's details             " << endl;
        cout << "                 9.Search an animal                     " << endl;
        cout << "                 10.Sorting animal's list inorder of age" << endl;
        cout << "                 11.Delete an animal using it's name    " << endl;
        cout << "                 12.Quit                                " << endl
             << endl;
        cout << "*********************************************************" << endl;

        cout << "Enter your option : ";
        cin >> option_for_operations;
        cout << endl;

        switch (option_for_operations)
        {
        case 1:
        {
            if (List == NULL)
            {
                int capacity, size = 0;
                cout << "Enter the capacity of the list: ";
                cin >> capacity;
                cout << endl;
                List = new A_list(capacity, size); //parameterized constructor
                cout << "List Created successfully with size " << size << " and capacity " << capacity << endl;
                break;
            }
            else
            {
                cout << "List is already created !" << endl;
            }
            break;
        }
        case 2:
        {
            int position = 0;
            if (List == NULL)
            {
                cout << "List not created yet!" << endl;
            }
            else
            {
                char *name = new char[30];
                int age, res;
                float break_fast_time, dinner_time, lunch_time;
                AnimalDetails temp; //static instance of 'AnimalDetails' class
                temp.MemoryAllocationForName();
                cout << "Enter the name of the animal: ";
                cin >> name;
                temp.setName(name);
                age = calculateAge();
                temp.setAge(age);
                cout << endl
                     << "Enter the break fast time: ";
                cin >> break_fast_time;
                temp.setBreakFastTime(break_fast_time);
                cout << endl
                     << "Enter the lunch time: ";
                cin >> lunch_time;
                temp.setLunchTime(lunch_time);
                cout << endl
                     << "Enter the dinner time: ";
                cin >> dinner_time;
                temp.setDinnerTime(dinner_time);
                res = List->InsertAtFirst(List, position, temp);
                if (res == 0)
                {
                    cout << "List is Full !" << endl;
                }
                else
                {
                    cout << endl
                         << "Animal with name " << name << " and with age " << age << " inserted successfully at first position !" << endl;
                }
            }
            break;
        }
        case 3:
        {
            if (List == NULL)
            {
                cout << "List not created yet!" << endl;
            }
            else
            {
                char *name = new char[30];
                int age, res;
                float break_fast_time, dinner_time, lunch_time;
                AnimalDetails temp; //static instance of 'AnimalDetails' class
                temp.MemoryAllocationForName();
                cout << "Enter the name of the animal: ";
                cin >> name;
                temp.setName(name);
                age = calculateAge();
                temp.setAge(age);
                cout << endl
                     << "Enter the break fast time: ";
                cin >> break_fast_time;
                temp.setBreakFastTime(break_fast_time);
                cout << endl
                     << "Enter the lunch time: ";
                cin >> lunch_time;
                temp.setLunchTime(lunch_time);
                cout << endl
                     << "Enter the dinner time: ";
                cin >> dinner_time;
                temp.setDinnerTime(dinner_time);
                res = List->InsertAtLast(List, temp);
                if (res == 0)
                {
                    cout << "List is Full!" << endl;
                }
                else
                {
                    cout << endl
                         << "Animal with name " << name << " and with age " << age << " inserted successfully at last position !" << endl;
                }
            }
            break;
        }
        case 4:
        {
            if (List == NULL)
            {
                cout << "List is not created yet !" << endl;
            }
            else
            {
                int position;
                cout << "Enter the index you want to insert: ";
                cin >> position;
                if (position > (List->getCapacity()))
                {
                    cout << endl
                         << "sorry! Index out of range ! (capacity = " << List->getCapacity() << " )" << endl;
                }
                else
                {
                    int option_for_confirmation;
                    if (List->getAgeForCheckingAnimalExistence(position) != -1)
                    {
                        cout << endl<< "Animal already exists at the index.Do you want to replace it." << endl;
                        cout << endl<< "***************************************************************" << endl<< endl;
                        cout << "         Animal name : " << List->getNameForCheckingAnimalExistence(position) << endl;
                        cout << "         Animal Age  : " << List->getAgeForCheckingAnimalExistence(position) << endl<<endl<< endl;
                        cout << "********************************************************************"<< endl<< endl;
                        cout << "******************** Confirmation ****************************" << endl<< endl;
                        cout << "                       1.Yes                                  " << endl;
                        cout << "                       2.No                                   " << endl<< endl;
                        cout << "***************************************************************" << endl;

                        cout << "Enter your option: ";
                        cin >> option_for_confirmation;

                        switch (option_for_confirmation)
                        {
                            case 1:
                            {
                                char *name=new char[30];
                                int age, res;
                                float break_fast_time, dinner_time, lunch_time;
                                AnimalDetails temp; //static instance of 'AnimalDetails' class
                                temp.MemoryAllocationForName();
                                cout << "Enter the name of the animal: ";
                                cin >> name;
                                temp.setName(name);
                                age = calculateAge();
                                temp.setAge(age);
                                cout << endl
                                    << "Enter the break fast time: ";
                                cin >> break_fast_time;
                                temp.setBreakFastTime(break_fast_time);
                                cout << endl
                                    << "Enter the lunch time: ";
                                cin >> lunch_time;
                                temp.setLunchTime(lunch_time);
                                cout << endl
                                    << "Enter the dinner time: ";
                                cin >> dinner_time;
                                temp.setDinnerTime(dinner_time);
                                        
                                List->InsertAtSpecificPosition(List,position,temp,false);
                                cout << endl
                                    << "Animal with name " <<name << " replaced successfully at the " << position << " position !" << endl;
                                break;
                            }
                            case 2:
                            {
                                break;
                            }
                            default:
                            {
                                if (option_for_confirmation != 1 && option_for_confirmation != 2)
                                {
                                    cout << "Invalid input !" << endl;
                                }
                                break;
                            }
                        }
                    }
                    else
                    {
                        char *name=new char[30];
                        int age, res;
                        float break_fast_time, dinner_time, lunch_time;
                        AnimalDetails temp; //static instance of 'AnimalDetails' class
                        temp.MemoryAllocationForName();
                        cout << "Enter the name of the animal: ";
                        cin >> name;
                        temp.setName(name);
                        age = calculateAge();
                        temp.setAge(age);
                        cout << endl
                            << "Enter the break fast time: ";
                        cin >> break_fast_time;
                        temp.setBreakFastTime(break_fast_time);
                        cout << endl
                            << "Enter the lunch time: ";
                        cin >> lunch_time;
                        temp.setLunchTime(lunch_time);
                        cout << endl
                            << "Enter the dinner time: ";
                        cin >> dinner_time;
                        temp.setDinnerTime(dinner_time);
                                        
                        List->InsertAtSpecificPosition(List,position,temp,true);
                        cout << endl
                             << "Animal with name " <<name << " added successfully at the " << position << " position !" << endl;
                    }
                }
            }
            break;
        }
        case 5:
        {
            if (List == NULL)
            {
                cout << "List is not created yet !" << endl;
            }
            else
            {
                char *name;
                name=List->DeleteAtFirst(List);
                if(name == NULL)
                {
                    cout<<" List is empty !"<<endl;
                }
                else
                {
                    cout << "Animal with name " <<name << " removed successfully" << endl;
                }
            }
            break;
        }
        case 6:
        {
            if (List == NULL)
            {
                cout << "List is not created yet !" << endl;
            }
            else
            {
                char *name;
                name=List->DeleteAtLast(List);
                if(name == NULL)
                {
                    cout<<"List is empty !"<<endl;
                }
                else
                {
                    cout << "Animal with name " <<name << " removed successfully" << endl;
                }

            }
            break;
        }
        case 7:
        {
            if (List == NULL)
            {
                cout << "List is not created yet!" << endl;
            }
            else
            {
                if((List->getSize()) == 2)
                {
                    cout<<"Please choose the 5th option to remove the animal at 1st position and 6th option to remove the animal at last position !"<<endl;
                }
                else
                {
                                  
                    int position;
                    cout << "Enter the index you want to delete: ";
                    cin >> position;
                    cout<<endl;
                    if (position > (List->getCapacity()))
                    {
                        cout << endl
                            << "sorry! Index out of range ! (capacity = " << List->getCapacity()<< " )" << endl;
                    }
                    else if((position) > ((List->getSize())-1))
                    {
                        cout<<"There is no animal at the position "<<position<<endl;
                    }
                    else
                    {
                        char *name;
                        name=List->DeleteAtSpecificPosition(List, position);
                        if(name == NULL)
                        {
                            cout<<"List is empty !"<<endl;
                        }
                        else
                        {
                            cout << endl
                            << "Animal with name " <<name<< " at index " << position << " deleted successfully !" << endl;
                        }
                    
                    }
                    
                }
            }
            break;
        }
        case 8:
        {
            if (List == NULL)
            {
                cout << "List is not created yet !";
            }
            else
            {
                int res=List->Display(List);
                if(res == 0)
                {
                    cout<<"List is empty !"<<endl;
                }
            }
            break;
        }
        case 9:
        {
            if (List == NULL)
            {
                cout << "List is not created yet !" << endl;
            }
            else
            {
                char *temp = new char[30];
                cout << "Enter the name of the animal to search: ";
                cin >> temp;
                cout << endl;
                int res=List->SearchAnAnimal(List, temp);
                if(res == 0)
                {
                    cout<<"List is empty!"<<endl;
                }
                else if(res == 1)
                {
                    cout << endl
                        << "Animal with name " << temp << " is not exists in the list !" << endl
                        << endl;
                }
            }
            break;
        }
        case 10:
        {
            if (List == NULL)
            {
                cout << "List is not created yet !" << endl;
            }
            else
            {
                int res=List->Sorting(List);
                if(res == 0)
                {
                    cout<<"List is empty!"<<endl;
                }
                else
                {
                    cout<<"Sorted successfully !"<<endl;
                }
            }
            break;
        }
        case 11:
        {
            if (List == NULL)
            {
                cout << "List is not created yet!";
            }
            else
            {
                if((List->getSize()) == 2)
                {
                    cout<<"Please choose the 5th option to remove the animal at 1st position and 6th option to remove the animal at last position !"<<endl;
                }
                else
                {
                    char *name = new char[30];
                    cout << "Enter the name of the animal you want to remove :";
                    cin >> name;
                    int res=List->DeleteUsingAnimalName(List,name);
                    if(res == 0)
                    {
                        cout<<"List is empty!"<<endl;
                    }
                    else if(res == 1)
                    {
                        cout << endl
                            << "Animal with name " << name << " is not exists in the list !" << endl
                            << endl;
                    }
                    else
                    {
                        cout << endl
                            << "Animal with name " << name << " at index " << res<< " deleted successfully !" << endl;
                    }

                }

            }
            break;
        }
        default:
        {
            if (option_for_operations != 1 && option_for_operations != 2 && option_for_operations != 3 && option_for_operations != 4 && option_for_operations != 5 && option_for_operations != 6 && option_for_operations != 7 && option_for_operations != 8 && option_for_operations != 9 && option_for_operations != 10 && option_for_operations != 11 && option_for_operations != 12)
            {
                cout << "Invalid input !" << endl;
            }
            break;
        }
        }

    } while (option_for_operations != 12);
}
int calculateAge()
{
    cout << "\n********* Enter details for Age calculation *************** \n";

    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int current_date, current_month, current_year, birth_date, birth_month, birth_year, calculated_date, calculated_month, calculated_year;

    cout << "\n Enter the current date: ";
    cin >> current_date;
    cout << "\n Enter the current month: ";
    cin >> current_month;
    cout << "\n Enter the current year: ";
    cin >> current_year;
    cout << "\n Enter the birth date: ";
    cin >> birth_date;
    cout << "\n Enter the birth month: ";
    cin >> birth_month;
    cout << "\n Enter the birth year: ";
    cin >> birth_year;

    if (birth_date > current_date)
    {
        current_date = current_date + months[birth_month - 1];
        current_month = current_month - 1;
    }
    if (birth_month > current_month)
    {
        current_year = current_year - 1;
        current_month = current_month + 12;
    }

    calculated_date = current_date - birth_date;
    calculated_month = current_month - birth_month;
    calculated_year = current_year - birth_year;

    cout << endl
         << "*************************************************************" << endl;

    return calculated_year;
}