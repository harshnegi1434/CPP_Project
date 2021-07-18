//including all the necessary header files
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <windows.h>

using namespace std;

//creating a class which will take user details and will use for saving purpose
class details
{
    public:
    string fname, lname ;
    int age;
    details()
    {
        cout<<"\n\n";
        cout<<"\n\t\tEnter Your First Name - "; cin>>fname;
        cout<<"\n\t\tEnter Your Last Name  - "; cin>>lname;
        cout<<"\n\t\tEnter Your Age        - "; cin>>age; cout<<"\n";
        system("cls");
    }
};

int main()
{   
    //initiating the quiz with showing ascii art first
    cout<<
 R"( 

#####################################################################
#  _    _  ____  __    ___  _____  __  __  ____    ____  _____      #
# ( \/\/ )( ___)(  )  / __)(  _  )(  \/  )( ___)  (_  _)(  _  )     #
#  )    (  )__)  )(__( (__  )(_)(  )    (  )__)     )(   )(_)(      #
# (__/\__)(____)(____)\___)(_____)(_/\/\_)(____)   (__) (_____)     #
#                    _____  __  __  ____  ____                      #
#                   (  _  )(  )(  )(_  _)(_   )                     #
#                    )(_)(  )(__)(  _)(_  / /_                      #
#                   (___/\\(______)(____)(____)                     #
#                                                                   #
#####################################################################)";
    
    //taking details
    details d1;
    char btn;
    int choice;
    cout<<"Loading.............";
    Sleep(3000);

    //clearing the screen and displaying the rules of the quiz game
    system("cls");
    cout<<"\n\n";
    cout<<"Welcome , "<<d1.fname<<" "<<d1.lname<< "!!!\n";
    cout<<"This is a quiz taking program. Here, we will test your knowledge in 2 fields - Computer Science or Indian History (Your Choice).\n";
    cout<<"The dataset contains equal difficulty level questions (ranging from easy to medium) and will occur to user in non chronogical order.\n";
    Sleep(4000);
    cout<<"Below are rules for the quiz.\n\n\n";
    cout<<"\t\t\tRULES";
    cout<<"\n1. There Will Be Total 15 Question (5 Easy, 5 Medium, 5 Difficult)";
    cout<<"\n2. Total Marks For The Quiz - 60 (15 M for Easy, 20 M for Medium, 25 M for Hard)";
    cout<<"\n3. The Question Will Contains 4 Options & Only 1 Correct Option";
    cout<<"\n4. User Have To Respond To The Answer By Pressing Option Number (1 , 2 , 3 or 4)";
    cout<<"\n5. User Giving Response Other Than Option Number Will Give User 0 And Skips To Next Question";
    cout<<"\n\n\t\t\t All The Best "<<d1.fname<<" !!!";
    system("pause");
    
    
    //clearing the screen and displaying the quiz selection
    system("cls");   
    cout<<"\t\t\tQuiz Selection\n\n";
    cout<<"1. Computer Science Quiz (Contains Questions Related To Basics Of Computer Hardware & Programming Language\n\n";
    cout<<"2. Indian History Quiz   (Contains Questions Related To Ancient & Modern History Of India)";
    select:
    cout<<"\n\nChoice Of Quiz - "; cin>>choice;
    if(choice == 1)
    {
        cout<<"\nDear, "<<d1.fname<<", You Selected Computer Science Quiz. Now The Next Screen Will Start Your Quiz\n";
        system("pause");
        Sleep(3000);
        system("cls");
    }
    else if (choice  == 2)
    {
        cout<<"\nDear, "<<d1.fname<<", You Selected Indian History Quiz. Now The Next Screen Will Start Your Quiz\n";
        system("pause");
        Sleep(3000);
        system("cls");
    }
    else
    {
        cout<<"\nOh No!, Dear "<<d1.fname<<" , You Selected Wrong Option. Select The Option Again";
        goto select;
    }                                                                                                      

    int no=0;
    bool har = 0;
    int b = 0;
    int ans[10];
    float score = 0;
    int anshard[10] = {1,1,1,1,1,1,1,1,1,1}; //ans of hard questions
    int ansmedi[10] = {1,1,1,1,1,1,1,1,1,1}; //ans of medium questions
    int anseasy[10] = {1,1,1,1,1,1,1,1,1,1}; //ans of easy questions
    int ansin;
    int k = 0;
    int h = 0, i = 0 , j = 0, l = 0, ea = 0, q = 0; 
    float correct = 0;
    char ch;
    string x[10], y[10], z[10];
    
    char s[100];
    ifstream medium; 
    ifstream easy; 
    ifstream hard;
    int e = 0, m = 0 , n = 0, main = 0;
    cout<<"Welcome To The Quiz\n";
    cout<<"\nThe Rules\n"; //writing the rules
    o1:
    cout<<"\nPress 1 To Continue\n";
    cin>>ch;
    while (main<=9)
    {
        medium.open("qmedium.txt"); //opening medium questions file
        for(int i = 0 ; i <= 9 ; i++)
        {
            getline(medium,x[i]); //reading the whole file
            if(i==main)   //displaying the quesiton which we want
            {
                no++;
                system("cls");   //clearing the screen
                cout<<"Q = \n";
                cout<<"("<<no<<")"<<x[i]<<"\n";
                cout<<"Please Select The Right Option (1,2,3,4) - \n";
                cin>>ansin;      //input the answer by user
            }
            if(ansin == ansmedi[main]) //check if the ans is right
            {
                correct++;      //updating the correct value
                score+= 4;      //updating the score
                q = main - ea;    //decreasing the value of main as our requirement
                h++;
                hard.open("qhard.txt"); //opening the hard file
                for(int j = 0; j <= 9 ; j++)
                {
                    getline(hard,y[j]);  //reading the hard file
                }
                if(j==q)        //displaying the question which we want
                {
                    no++;
                    system("cls");
                    cout<<"Q - \n";
                    cout<<"("<<no<<")"<<y[j]<<"\n";
                    cout<<"Please Select The Right Option (1,2,3,4)\n";
                    cin>>ansin;
                    if(ansin==anshard[j])
                    {
                        correct++;
                        score += 5; //updating the score
                    }
                 }
            }
            else        //if the ans of user is wrong
            {
                ea++;     
                l = main - h;     //decreasing the value of main as our requirement
                easy.open("qeasy.txt");
                for(int k = 0; k<=9 ;k++)
                {
                    getline(easy, z[k]); //reading the whole file
                }
                if(k==l)    //displaying the question which we want
                {
                    no++;
                    system("cls");
                    cout<<"Q - \n";
                    cout<<"("<<no<<")"<<z[k]<<"\n";
                    cout<<"Please Select The Right Option (1,2,3,4)\n";
                    cin>>ansin;
                    if(ansin ==anseasy[k])
                    {
                        correct++;
                        score += 3; //updating the score
                    }
                }
            }
        }
        main++;
        if(main==10)     //displaying the question of easy and hard which are left after the completion of medium questions
        {
            if(ea<=9 || h<=9)
            {
                while(ea<=9)
                {
                    easy.open("qeasy.txt");    //opening the file
                    for(int t = 0 ; t <= 10; t++)
                    {
                        getline(easy, z[t]);   //reading the whhole file
                        if(t==ea)              //displaying the remaning question
                        {
                            no++;
                            system("cls");
                            cout<<"Q - \n";
                            cout<<"("<<no<<")"<<z[k]<<"\n";
                            cout<<"Please Select The Right Option (1,2,3,4)\n";
                            cin>>ansin;
                            if(ansin==anseasy[t])  //updating the score if the ans is right;
                            {
                                correct++;
                                score += 3;
                            }
                        }
                    }
                }
                ea++;
                if(ea==10)
                {
                    while(h<=10)   //displaying the remaining questions of hard file
                    {
                        hard.open("qhard.txt");
                        for(int u = 0; u <= 10 ; u++)
                        {
                            getline(hard,y[u]);  //reading the hard file
                            if(h == u)        //displaying the question which we want
                            {
                                no++;
                                system("cls");
                                cout<<"Q - \n";
                                cout<<"("<<no<<")"<<y[u]<<"\n";
                                cout<<"Please Select The Right Option (1,2,3,4)\n";
                                cin>>ansin;
                                if(ansin==anshard[u])
                                {
                                    correct++;
                                    score += 5; //updating the score
                                }
                            }
                        }    
                    }
                    h++;
                    if(h==10)
                    {
                        break;
                    }
                }
            }
        }
    }
    system("cls");
    cout<<"Your Score  In The Exam - "<<score<<" Out Of 120";
    cout<<"\nYou Answered - "<<correct<<" Questions Correctly";
    cout<<"\nYou Answered - "<<30-correct<<" Question Wronged";
    return 0;
}