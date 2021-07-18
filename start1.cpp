//including all the necessary header files
#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include <ctime>


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
    Sleep(3000);
    cout<<"Below are rules for the quiz.\n\n\n";
    cout<<"\t\t\tRULES";
    cout<<"\n1. There Will Be Total 15 Question (5 Easy, 5 Medium, 5 Difficult)";
    cout<<"\n2. Total Marks For The Quiz - 60 (15 M for Easy, 20 M for Medium, 25 M for Hard)";
    cout<<"\n3. The Question Will Contains 4 Options & Only 1 Correct Option";
    cout<<"\n4. User Have To Respond To The Answer By Pressing Option Number (1 , 2 , 3 or 4)";
    cout<<"\n5. User Giving Response Other Than Option Number Will Give User 0 And Skips To Next Question";
    cout<<"\n\n\t\t\t All The Best "<<d1.fname<<" !!!\n\n";
    system("pause");
    
    
    //clearing the screen and displaying the quiz selection
    system("cls");   
    cout<<"\t\t\tQuiz Selection\n\n";
    cout<<"1. Computer Science Quiz (Contains Questions Related To Basics Of Computer Hardware & Programming Language)\n\n";
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

    string chc;
    if(choice == 1) 
    {   
        chc = "Computer Science";
    }
    if(choice == 2) 
    {
        chc = "Indian History";
    }          
    
    //saving current time and day
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    time_t start, end;

    //declaration of variables
    int no = 0;
    bool har = 0;
    int b = 0;
    int ans[5];
    float score = 0;
    
    int anshard[5] = {4,4,3,1,1}; //ans of hard questions
    int ansmedi[5] = {2,3,3,2,3}; //ans of medium questions
    int anseasy[5] = {1,3,2,3,4}; //ans of easy questions
    int ansin;
    
    int esc = 0, msc = 0, hsc = 0;
    int k = 0;
    int h = 0, i = 0 , j = 0, l = 0, ea = 0, q = 0; 
    float correct = 0;
    char ch; 
    string x[5], y[5], z[5];
    
    char s[100];
    ifstream medium; 
    ifstream easy; 
    ifstream hard;
    int e = 0, m = 0 , n = 0, main = 0;

    int h1, m1, s1;
    
    switch(choice)
    {
        //if the user selects CS Quiz
        case 1:   
        { 
            cout<<"\t\t\tWelcome To The Computer Science Quiz\n";
            cout<<"\nThe Next Screen Will Start The Quiz In 5 Seconds";
            Sleep(5000);
            system("cls");
            h1 = tPtr->tm_hour;
            m1 = tPtr->tm_min;
            s1 = tPtr->tm_sec;
            time(&start);
            while (main<=4)
            {
                medium.open("csqmedium.txt"); //opening medium questions file
                for(int i = 0 ; i <= 4 ; i++)
                {
                    getline(medium, x[i]); //reading the whole file
                    if(i==main)   //displaying the quesiton which we want
                    {
                        no++;
                        system("cls");   //clearing the screen
                        cout<<"Q - ";
                        cout<<no<<" "<<x[i]<<"\n";
                        cout<<"Please Select The Right Option (1,2,3,4) - ";
                        cin>>ansin;      //input the answer by user
                    }
                }
                if(ansin == ansmedi[main]) //check if the ans is right
                {
                    msc++;          //updating correct no of medium level question
                    correct++;      //updating the correct value
                    score+= 4;      //updating the score
                    q = main - ea;    //decreasing the value of main as our requirement
                    h++;
                    hard.open("csqhard.txt"); //opening the hard file
                    for(int j = 0; j <= 4 ; j++)
                    {
                        getline(hard,y[j]);  //reading the hard file
                        if(j==q)        //displaying the question which we want
                        {
                            no++;
                            system("cls");
                            cout<<"Q - ";
                            cout<<no<<" "<<y[j]<<"\n";
                            cout<<"Please Select The Right Option (1,2,3,4) - ";
                            cin>>ansin;
                            if(ansin==anshard[j])
                            {
                                hsc++;      //updating correct no of hard level question
                                correct++;
                                score += 5; //updating the score
                            }
                        }
                    } 
                }
                else        //if the ans of user is wrong
                {
                    ea++;     
                    l = main - h;     //decreasing the value of main as our requirement
                    easy.open("csqeasy.txt");
                    for(int k = 0; k<=4 ;k++)
                    {
                        getline(easy, z[k]); //reading the whole file
                        if(k==l)    //displaying the question which we want
                        {
                            no++;
                            system("cls");
                            cout<<"Q - ";
                            cout<<no<<" "<<z[k]<<"\n";
                            cout<<"Please Select The Right Option (1,2,3,4) - ";
                            cin>>ansin;
                            if(ansin ==anseasy[k])
                            {
                                esc++;      //updating correct no of easy level question
                                correct++;
                                score += 3; //updating the score
                            }
                        }
                    }
                }
                main++;
                if(main==5)     //displaying the question of easy and hard which are left after the completion of medium questions
                {
                    if(ea<=4 || h<=4)
                    {
                        while(ea<=4)
                        {
                            easy.open("csqeasy.txt");    //opening the file
                            for(int t = 0 ; t <= 4; t++)
                            {
                                getline(easy, z[t]);   //reading the whhole file
                                if(t==ea)              //displaying the remaning question
                                {
                                    no++;
                                    system("cls");
                                    cout<<"Q - ";
                                    cout<<no<<" "<<z[k]<<"\n";
                                    cout<<"Please Select The Right Option (1,2,3,4) - ";
                                    cin>>ansin;
                                    if(ansin==anseasy[t])  //updating the score if the ans is right;
                                    {
                                        esc++;      //updating correct no of easy level question
                                        correct++;
                                        score += 3;
                                    }
                                }
                            }
                            ea++;
                        }
                        if(ea==5)
                        {
                            while(h<=5)   //displaying the remaining questions of hard file
                            {
                                hard.open("csqhard.txt");
                                for(int u = 0; u <= 4 ; u++)
                                {
                                    getline(hard,y[u]);  //reading the hard file
                                    if(h == u)        //displaying the question which we want
                                    {
                                        no++;
                                        system("cls");
                                        cout<<"Q - ";
                                        cout<<no<<" "<<y[u]<<"\n";
                                        cout<<"Please Select The Right Option (1,2,3,4) - ";
                                        cin>>ansin;
                                        if(ansin==anshard[u])
                                        {
                                            hsc++;      //updating correct no of hard level question
                                            correct++;
                                            score += 5; //updating the score
                                        }
                                    }
                                }    
                                h++;
                                if(h==5)
                                {
                                    break;
                                }
                            }
                        }
                    }
                }          
            }
        }
        time(&end);
        break;

        //if the user selects IH QUIZ
        //exactly same as previous case , just the file is different
        case 2:   
        { 
            cout<<"\t\t\tWelcome To The Indian History Quiz\n";
            cout<<"\nThe Next Screen Will Start The Quiz In 5 Seconds";
            Sleep(5000);
            system("cls");
            h1 = tPtr->tm_hour;
            m1 = tPtr->tm_min;
            s1 = tPtr->tm_sec;
            time(&start);
            while (main<=4)
            {
                medium.open("ihqmedium.txt"); //opening medium questions file
                for(int i = 0 ; i <= 4 ; i++)
                {
                    getline(medium, x[i]); //reading the whole file
                    if(i==main)   //displaying the quesiton which we want
                    {
                        no++;
                        system("cls");   //clearing the screen
                        cout<<"Q = ";
                        cout<<no<<" "<<x[i]<<"\n";
                        cout<<"Please Select The Right Option (1,2,3,4) - ";
                        cin>>ansin;      //input the answer by user
                    }
                }
                if(ansin == ansmedi[main]) //check if the ans is right
                {
                    msc++;          //updating correct no of medium level question
                    correct++;      //updating the correct value
                    score+= 4;      //updating the score
                    q = main - ea;  //decreasing the value of main as our requirement
                    h++;
                    hard.open("ihqhard.txt"); //opening the hard file
                    for(int j = 0; j <= 4 ; j++)
                    {
                        getline(hard,y[j]);  //reading the hard file
                        if(j==q)        //displaying the question which we want
                        {
                            no++;
                            system("cls");
                            cout<<"Q - ";
                            cout<<no<<" "<<y[j]<<"\n";
                            cout<<"Please Select The Right Option (1,2,3,4) - ";
                            cin>>ansin;
                            if(ansin==anshard[j])
                            {
                                hsc++;      //updating correct no of hard level question
                                correct++;
                                score += 5; //updating the score
                            }
                        }
                    } 
                }
                else        //if the ans of user is wrong
                {
                    ea++;     
                    l = main - h;     //decreasing the value of main as our requirement
                    easy.open("ihqeasy.txt");
                    for(int k = 0; k<=4 ;k++)
                    {
                        getline(easy, z[k]); //reading the whole file
                        if(k==l)    //displaying the question which we want
                        {
                            no++;
                            system("cls");
                            cout<<"Q - ";
                            cout<<no<<" "<<z[k]<<"\n";
                            cout<<"Please Select The Right Option (1,2,3,4) - ";
                            cin>>ansin;
                            if(ansin ==anseasy[k])
                            {
                                esc++;      //updating correct no of easy level question
                                correct++;
                                score += 3; //updating the score
                            }
                        }
                    }
                }
                main++;
                if(main==5)     //displaying the question of easy and hard which are left after the completion of medium questions
                {
                    if(ea<=4 || h<=4)
                    {
                        while(ea<=4)
                        {
                            easy.open("ihqeasy.txt");    //opening the file
                            for(int t = 0 ; t <= 4; t++)
                            {
                                getline(easy, z[t]);   //reading the whhole file
                                if(t==ea)              //displaying the remaning question
                                {
                                    no++;
                                    system("cls");
                                    cout<<"Q - ";
                                    cout<<no<<" "<<z[k]<<"\n";
                                    cout<<"Please Select The Right Option (1,2,3,4) - ";
                                    cin>>ansin;
                                    if(ansin==anseasy[t])  //updating the score if the ans is right;
                                    {
                                        esc++;      //updating correct no of easy level question
                                        correct++;
                                        score += 3;
                                    }
                                }
                            }
                            ea++;
                        }
                        if(ea==5)
                        {
                            while(h<=5)   //displaying the remaining questions of hard file
                            {
                                hard.open("ihqhard.txt");
                                for(int u = 0; u <= 4 ; u++)
                                {
                                    getline(hard,y[u]);  //reading the hard file
                                    if(h == u)        //displaying the question which we want
                                    {
                                        no++;
                                        system("cls");
                                        cout<<"Q - ";
                                        cout<<no<<" "<<y[u]<<"\n";
                                        cout<<"Please Select The Right Option (1,2,3,4) - ";
                                        cin>>ansin;
                                        if(ansin==anshard[u])
                                        {
                                            hsc++;      //updating correct no of hard level question
                                            correct++;
                                            score += 5; //updating the score
                                        }
                                    }
                                }    
                                h++;
                                if(h==5)
                                {
                                    break;
                                }
                            }
                        }
                    }
                }       
            }
        }
        time(&end);
        break;
    }

    double time_taken = double(end - start);

    system("cls");
    cout<<"Thank You ! , Your Quiz Is Over. Please Wait While We Save Your Details And Later Show Your Scorecard.";
    Sleep(3000);
    system("cls");
    
    //saving details into a file
    ofstream of1("results.txt", ios::app);
    of1<<"\n\nName - "<<d1.fname<<" "<<d1.lname;
    of1<<"\nAge - "<<d1.age;
    of1<<"\nQuiz Selected - "<<chc;
    of1<<"\nDate Played - "<<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900;
    of1<<"\nTime Started The Quiz - "<<(tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec);
    of1<<"\nTime Completed The Test (In Secs) - "<<time_taken <<" secs";
    of1<<"\nScore (Out Of 60) - "<<score;
    of1<<"\nQuestions Correct (Out Of 15) - "<<correct<<endl;

    
    //displaying scorecard and addtional statistics
    cout<<R"(
                        ____                      ____              _ 
                       / ___|  ___ ___  _ __ ___ / ___|__ _ _ __ __| |
                        \___ \ / __/ _ \| '__/ _ \ |   / _` | '__/ _`|
                        ___) | (_| (_) | | |  __/ |__| (_| | | | (_| |
                       |____/ \___\___/|_|  \___|\____\__,_|_|  \__,_|
                                                )";
    

    cout<<"\n\t\tName - "<<d1.fname<<" "<<d1.lname;
    cout<<"\n\t\tAge - "<<d1.age;
    cout<<"\n\t\tQuiz Selected - "<<chc;
    cout<<"\n\t\tDate - "<<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900;
    cout<<"\n\t\tTime Completed The Test - "<<time_taken <<" secs";
    cout<<"\n\n";
    
    cout<<"\n\t\tYour Score  In The Exam - "<<score<<" Out Of 60";
    cout<<"\n\t\tYou Answered - "<<correct<<" Questions Correctly";
    cout<<"\n\t\tYou Answered - "<<15-correct<<" Question Wronged";
    cout<<"\n\t\tCorrect Question In : Easy -> "<<esc<<", Medium -> "<<msc<<" & Hard ->"<<hsc;
    cout<<"\n\n\n\n";
    
    
    cout<<
    R"(                                                                                                                                  
 _________________  ____   ____        ____  _____   ______    ____    ____         _____      _____        _____     ____   ____ 
/                 \|    | |    |  ____|\   \|\    \ |\     \  |    |  |    |       |\    \    /    /|  ____|\    \   |    | |    |
\______     ______/|    | |    | /    /\    \\\    \| \     \ |    |  |    |       | \    \  /    / | /     /\    \  |    | |    |
   \( /    /  )/   |    |_|    ||    |  |    |\|    \  \     ||    | /    //       |  \____\/    /  //     /  \    \ |    | |    |
    ' |   |   '    |    .-.    ||    |__|    | |     \  |    ||    |/ _ _//         \ |    /    /  /|     |    |    ||    | |    |
      |   |        |    | |    ||    .--.    | |      \ |    ||    |\    \'          \|___/    /  / |     |    |    ||    | |    |
     /   //        |    | |    ||    |  |    | |    |\ \|    ||    | \    \              /    /  /  |\     \  /    /||    | |    |
    /___//         |____| |____||____|  |____| |____||\_____/||____|  \____\            /____/  /   | \_____\/____/ ||\___\_|____|
   |`   |          |    | |    ||    |  |    | |    |/ \|   |||    |   |    |          |`    | /     \ |    ||    | /| |    |    |
   |____|          |____| |____||____|  |____| |____|   |___|/|____|   |____|          |_____|/       \|____||____|/  \|____|____|
     \(              \(     )/    \(      )/     \(       )/    \(       )/               )/             \(    )/        \(   )/  
      '               '     '      '      '       '       '      '       '                '               '    '          '   '   
                                                                                                                                  )";
    
    cout<<"\n\n";
    Sleep(5000);
    system("pause");
    system("cls");
    return 0;
}
