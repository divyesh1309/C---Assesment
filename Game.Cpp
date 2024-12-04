#include<iostream>
#include<stdlib.h>
#include<ctime>

using namespace std;

class game
{
    //this is private data members
private:
    int rounds;
    string name;
    int compScore=0;
    int userScore=0;

public:     // public metbods and constructors


// constructor take input from user
game()   //onstructor automatically call hota hai jab object create hota hai
{
    cout << " -----*-----*-----*-----*-----*-----*-----*-----*\n";
    cout << "                     NAME\n";  
    cout << " -----*-----*-----*-----*-----*-----*-----*-----*\n";
    cout << "Enter your name : ";
    cin >> name;
    cout << " -----*-----*-----*-----*-----*-----*-----*-----*\n";
    cout << "                    ROUNDS\n";
    cout << " -----*-----*-----*-----*-----*-----*-----*-----*\n";
    cout << name << " How Many Rounds You Want To Play?  : ";
    cin >> rounds;   
}


int compchoice()      //this is method function to create auto choice for computer using inbluid function
{
    srand(time(0));                          // here is we used time() function to seed in srand()
    int comchoice = rand() % 3 + 1;          // Randomly computer ke liye choice generate karta hai (Rock, Paper, Scissors)
    return comchoice;                        //this will return computer choice
}


void gameRounds()
{
    // using for loop becus Rounds run according to user input
    for (int i = 1; i <=rounds; i++)
    {    
        int userChoice;
        int compChoice;
        cout << "-----*-----*-----*-----*-----*-----*-----*-----*\n";
        cout << "                    GAME\n";
        cout << "-----*-----*-----*-----*-----*-----*-----*-----*\n";
        cout << "Round No : " << i <<"/" << rounds << endl <<endl; 
        cout << name <<"'s Score = "<< userScore <<endl; // for user score
        cout << "Computer's Score = "<< compScore << endl; // for computer score

        cout << "1) ROCK" << endl;
        cout << "2) PAPER" << endl;
        cout << "3) SCISSOR" << endl;

        cout << "-> Select Your Choice : ";
        cin >> userChoice;
        compChoice=compchoice();//here we calling commputer choice function and assign value to variable
        cout << "-> Computer Choice Is : " << compChoice << endl;

        //this if conditon runs to check score and add score accordingly

        if (userChoice==compChoice)      // if both are same choice so result is draw
        {
            cout << "\tDRAW\n\n";
        }
        else
        {
            if (userChoice == 1 && compChoice == 3)
            {
                userScore++;
            }
            else if (userChoice == 2 && compChoice == 1)
            {
                userScore++;
            }
            else if (userChoice == 3 && compChoice == 2)
            {
                userScore++;
            }
            else
            {
                compScore++;
            }
            
        }

    }
}

//Result function
void result()
{   
    //this if condition checks final score and show winner on screen
    if (userScore > compScore)
    {
        //if users final score is greater then computer score then user is winner
        cout << "-------Winner is " << name;
    }
    else if (userScore < compScore)
    {
        //if users final score is less them computer score then computer is winner
        cout << "-------Winner is Computer";
    }
    else
    {
        //else both are equal score then game is Draw .
        cout << "--------Game is Drawn";
    }
    
}
};


int main()
{
    //this object of class game.
    game g;

    g.gameRounds();       //here we are calling gameround function of class game
    g.result();          //Showing final result
    return 0;
}






