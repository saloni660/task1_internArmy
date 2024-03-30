#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(0));       // the random number generator//
    int secretNumber = rand() % 100 + 1;          // Generate a random number between 1 and 100//
    // int secretNumber=16;
    int guess;
    int attemts=0;
    int maxAttempts=5;

    cout<<"Welcome to the Number Guessing game"<<endl;
    cout<<"I have selected a number between 1 and 50. you have to find number in "<<maxAttempts<<"attempts."<<endl;

    while(attemts<=maxAttempts){
        cout<<"Enter your Guessed number: ";
        cin>>guess;
        attemts++;

        if(guess==secretNumber){
            cout<<"Wow! You got the Number "<<secretNumber<<"correctly in "<<attemts<<"attempts."<<endl;
        }
        else if(guess<secretNumber){
            cout<<"Too low. Try Again."<<endl;
        }
        else{
            cout<<"Too high. Try Again."<<endl;
        }
    }

    if(attemts==maxAttempts){
        cout<<"You have run out of attempts. The correct number is "<<secretNumber<<endl;
    }



    return 0;
}