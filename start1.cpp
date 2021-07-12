//including all the necessary header files
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>

using namespace std;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void starline();
int main()
{   
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
    starline();
    starline();
    gotoxy(50,2);
    cout<<"Welcome To The Quiz\n";
    starline();
    starline();
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
    cout<<"\nYou Answered - "<<correct<<"Questions Correctly";
    cout<<"\nYou Answered - "<<30-correct<<"Question Wronged";
    return 0;
}

void starline()         //function definition
{
    for(int i = 0 ; i <=119; i++)
    {
        cout<<"*";
    } 
    cout<<"\n";
}
