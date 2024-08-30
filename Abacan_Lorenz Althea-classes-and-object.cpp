#include <iostream>
#include <iomanip>
using namespace std;

//This code is made by ABACAN, Lorenz Althea
//Goal: Making a mini library

/*Declare of the Mini Library*/
class BookFunctions
{

    private:
    int year;
    string title;
    string author;

    public:
    void AddBookFunction();


    string BookTitle()
    {
        return title;
    }
    string BookAuthor()
    {
        return author;
    }
    int BookYear()
    {
        return year;
    };
};

void DisplayBookFunction(int max);
BookFunctions book[100];

void SearchBookFunction(int max)
{
        string target;
        bool found = false;
        int location;

        cout<<"Enter a book to search: "<<endl;
        getline(cin,target); 
            for(int x = 0; x <= max; x++)
            {
                if (book[x].BookTitle()== target)
                {
                    found = true;
                    location = x;
                }
                else
                    found = false;
            }

            if(found == true)
            {
                cout<<"Book Found!\n";
                cout<<"Title: "<<book[location].BookTitle()<<endl;
                cout<<"Author: "<<book[location].BookAuthor()<<endl;
                cout<<"Year: "<<book[location].BookYear()<<endl;
            }
}

void MenuOptions()
{
    
    int NumSelection,max=-1;
    bool leave = false;

    do
    {
    cout<<" Enter No. here: ";
    cin>>NumSelection;
    cin.ignore();

    switch(NumSelection)
    {
    case 1:
        max++;
        book[max].AddBookFunction();
        break;

    case 2:
        for(int x = 0; x < max; x++)
        {
        DisplayBookFunction(max);
        }
        break;

    case 3:
        SearchBookFunction(max);
        cout<<endl;        
        break;
    case 4:
        
        char quit;
        cout<<"Are you sure you want to exit? [Y or N]\n";
        cin>>quit;
			do
            {
				if(quit == 'Y' || quit == 'y')
                {
				    leave = true;
				    cout<<"Leaving Program...";
				}
				    			
				else if(quit == 'N' || quit == 'n')
				    leave = false;
                    
				    			
				else
                {
				    cout<<"Invalid input..."<<endl
				    <<"Are you sure you want to leave the program? [Y/N]: ";
				    cin>>quit;
                }
			}while(quit != 'Y' && quit != 'y' && quit != 'N' && quit != 'n');
						cout<<endl;
        break;
    default:
        cout<<"Please pick a Number "<<endl;
        break;
    } 
    }while (NumSelection!=4 || !leave);
}

void BookFunctions::AddBookFunction()
{
        cout<<"Enter Title: \n";
        getline(cin, title);
        cout<<"Enter Author: \n";
        getline(cin, author);
        cout<<"Enter Year: \n";
        cin>>year;

        cout<<"Book has added successfully!"<<endl;
}
    
void DisplayBookFunction(int max)
    {
        cout<<setw(30)<<"Title"<<setw(30)<<"Author"<<setw(30)<<"Year"<<endl;
        for (int y = 0; y<= max; y++)
        {
        cout<<setw(30)<<book[y].BookTitle()<<setw(30)<<book[y].BookAuthor()<<setw(30)<<book[y].BookYear()<<endl;
        }
        
    }

int main()
{
    cout<<"\n =============== M E N U =============== \n";
    cout<<"1 - Add Book"<<endl;
    cout<<"2 - Display Book"<<endl;
    cout<<"3 - Search Book"<<endl;
    cout<<"4 - Exit";
    cout<<"\n ======================================= \n";

    MenuOptions();
return 0;
}