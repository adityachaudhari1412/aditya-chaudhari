//Aditya Chaudhari 1001747134
#include <iostream>
#include "Test.cpp"
#include <vector>
#include<cstring>
#include <stdbool.h>
#define NDICE 5
#define facesperdice 6
#define noofrolls 3
#define testrolls 23
int norerolls = 5;
bool reroll;

using namespace std;


void RollDice(vector<int> &dice)
{
    int r, i;
    for(i=0;i<norerolls;i++)
    {
        r=rand() % 6 + 1;
        dice.push_back(r);
    }
}
void PrintRoll(vector<int> &dice)
{
    int i;
    cout << "You rolled " ;
    for (auto i : dice) 
        cout << i << ' ';
        
    cout << endl << endl; 
}
void FillHowMany(vector<int> &dice, vector<int> &HowManyFaces)
{

    for(auto i : dice)
    {
        switch(i)
        {
            case 1:
                HowManyFaces[0]++;
                break;
            case 2:
                HowManyFaces[1]++;
                break;
            case 3:
                HowManyFaces[2]++;
                break;
            case 4:
                HowManyFaces[3]++;
                break;
            case 5:
                HowManyFaces[4]++;
                break;
            case 6:
                HowManyFaces[5]++;
                break;
        }
    }

}
void PickDice(vector<int> &dice)
{
    string a, temp;
    vector<int> flags (5);
    cout << "\n\nDo you want to reroll ?  " ;
    cin >> a;
    norerolls = 0;
    if(a=="y"|| a=="Y")
    {
        
        cout << "\n\nPick which dice to reroll. Answer Y at the prompt to keep that die." << endl << endl;
        
        for(int i=0;i<5;i++)
        {
            cout << "keep " << dice[i] << "?";
            cin >> temp;
            if(temp=="n"|| temp=="N")
			{
				//dice.erase(dice.begin() + i);
                flags[i] = 1;
				norerolls++;
			}
                
			
        }
        if( norerolls > 0 )
        {
            for(int j=4; j >=0; j--)
            {
                if(flags[j] == 1)
                {
                    dice.erase(dice.begin() + j);                
                }
            }   
            //PrintRoll(dice);   
        }

	
    }
    else
    {
        reroll = 0;
    }
}
int main(int argc, char *argv[])
{
    int ofAKind=0;
    int FullHouse=0;
    int TwoPair=0;
    int CPPSlam=0;
    int LargeStraight=0;
    int SmallStraight=0;
    int dicerollcount=0;
    vector<int> dice;

    reroll = 1;
    

    vector<int>HowManyFaces (6);
   
    
	if(strcmp(argv[1], "TEST") == 0)
	{
        string out;
        int count = 0;
        cout<<"\n......TESTING.......\n";
        for(int i = 0; i< 23; i++)
        {
		    out = TestRollDice(dice);
            PrintRoll(dice);
		    cout<<"\n"<< out<<"\n";
            if( !out.empty() )
            {
                count++;
                cout<<"Test Passed\n";
            }
            
		     
        }
        cout<<"Out of 23 tests,"<<count<<" passed "<<23-count<<" tests failed.";
        return 0;
		
	}
    while(dicerollcount < 3)
    {
        RollDice(dice);
        PrintRoll(dice);
        FillHowMany(dice,HowManyFaces);
        for(auto i : HowManyFaces)
        {
            switch(i)
            {
                case 0:
                    if(LargeStraight > 0 && LargeStraight < 5)
                        LargeStraight = 0;
                    if(SmallStraight > 0 && SmallStraight < 4)
                        SmallStraight = 0;
                    break;
                case 1:
                    LargeStraight++;
                    SmallStraight++;
                    break;
                    
                case 2:
                    FullHouse += 2;
                    TwoPair++;
                    SmallStraight++;
                    break;
                case 3:
                    FullHouse += 3;
                    ofAKind = 3;
                    SmallStraight++;
                    break;
                case 4:
                    ofAKind = 4;
                    SmallStraight++;
                    break;
                case 5:
                    CPPSlam++;
                    SmallStraight++;
                    break;
                    
            }        
        }
		if(LargeStraight==5)
			cout << "\nLarge Straight" << endl;
		else if(SmallStraight>= 4)
			cout << "Small Straight" << endl;
		else if(FullHouse==5)
			cout << "Full House" << endl;
		else if(CPPSlam==1)
			cout << "C++Slam!" << endl;
		else if(ofAKind==4)
			cout << "Four of a Kind" << endl;
		else if(ofAKind==3)
			cout << "Three of a Kind" << endl;
		else if(TwoPair == 2)
			cout << "Two pair" << endl;
		else
			cout << "You have nothing\n" << endl;
		PickDice(dice);
		if(reroll == 0)
		{
			return 0;
		}
		else
		{
			dicerollcount++;
		}
        
        
    }

    return 0;

}
    
    

