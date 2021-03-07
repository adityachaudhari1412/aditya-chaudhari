//Aditya Chaudhari 1001747134



#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

#define Dices     5
#define Faces     6
#define Rolls 	  3
#define TestRolls 23



using namespace std;

string TestRollDice(vector<int> &dice);

void RollDice(vector <int> &Dice)
{
	int i{};
	int j{};
	for(i = Dice.size(); i<Dices; i++)
	{

		j = rand() % Faces + 1;
		Dice.push_back(j);
		
	}
}
void PrintRoll(vector <int> Dice)
{
	cout << "You rolled" << endl;
	for(int it: Dice)
	{
		cout << setw(2) << it;
	}
	cout << "\n" << endl;
}
void FillHowMany(vector <int> Dice , vector <int> &howMuch)
{
	for(int &r: howMuch)
	{
		r= 0;
	}
	for (auto s : Dice)
	{
		howMuch[s-1]++;
	}
}
void PickDice(vector <int> &Dice)
{
	char Remove;
	int i = 0;
	while(i<Dice.size())
	{
		cout << "Keep " << Dice[i] << "? " <<endl;
		cin >> Remove;
		Remove = toupper(Remove);
		if(Remove == 'N')
		{
			Dice.erase(Dice.begin()+i);
			i--;
		}
		i++;
	}
}
int main(int argc,char *argv[])
{
        bool Test{};
	int ofAKind{}, FullHouse{}, TwoPair{}, CPPSlam{}, LargeStraight{}, SmallStraight{};
	char Roll{};
	vector <int> howMuch(Faces);
	vector <int> Dice;
	int a = 0;
	int b{};
	string my{};
	string myCheck{};
	int Pcount{}; 
	int Fcount{};
	
	srand(time(0));
	string line{};

	b = Rolls;

	if (argc==2)
	{
            line = argv[1];

            if (line == "TEST")
            {
                    Test = 1;
            }

	}

	if(Test == 1)
	{
            b = TestRolls;
            Roll = 'Y';
	}
	else
	{
            b = Rolls;
	}

	while(Roll != 'N' && a < b)
	{
		if(Test == 1)
		{
			my = TestRollDice(Dice);
		}
		else
		{
			RollDice(Dice);
		}
		PrintRoll(Dice);
		FillHowMany(Dice,howMuch);

		for(int i=0; i< Faces; i++)
		{
			if(howMuch[i] == 3)
			{
				FullHouse +=  3;
			}
			if(howMuch[i] == 2)
			{
				FullHouse += 2;
				TwoPair++;
			}
			if(howMuch[i] == 5)
			{
				CPPSlam++;
			}
			if(howMuch[i] == 1)
			{
				LargeStraight++;
			}
			else if(howMuch[i] == 0 && LargeStraight>0 && LargeStraight < 5)
			{
				LargeStraight =0;
			}
			if(howMuch[i]>=1)
			{
				SmallStraight++;
			}
			else if(howMuch[i] == 0 && SmallStraight >0 && SmallStraight<4)
			{
				SmallStraight = 0;
			}
			if(howMuch[i] == 4)
			{
				ofAKind = 4;
			}
			if(howMuch[i] == 3)
			{
				ofAKind = 3;
			}
		}
		if(LargeStraight == 5)
		{
			cout << "Large Straight\n" <<endl;
			myCheck = "Large Straight";
		}
		else if(SmallStraight >= 4)
		{
			cout << "Small Straight\n" << endl;
			myCheck = "Small Straight";

		}
		else if(FullHouse == 5)
		{
			cout << "Full House\n" <<endl;
			myCheck = "Full House";
		}
		else if(CPPSlam == 1)
		{
			cout << "C++Slam!\n" << endl;
			myCheck = "C++Slam!";
		}
		else if(ofAKind == 4)
		{
			cout << "Four of a Kind\n" << endl; 
			myCheck = "Four of a Kind";
		}
		else if(ofAKind == 3)
		{
			cout << "Three of a Kind\n"<< endl;
			myCheck = "Three of a Kind";
		}
		else if(TwoPair == 2)
		{
			cout << "Two Pair\n" << endl;
			myCheck = "Two Pair";
		}
		else
		{
			cout << "You have nothing\n" << endl;
			myCheck = "You have nothing";
		}

	
		if(myCheck == my)
		{
			Pcount++;
			cout << "Test passed" << endl;
		}
		else
		{
			Fcount++;
			cout << "Test failed" << endl;
		}
		LargeStraight = 0;
		SmallStraight =0;
		FullHouse = 0;
		CPPSlam = 0;
		ofAKind = 0;
		TwoPair = 0;


		if (Test == 0)
		{	 
			cout << "Do you want to reroll? " << endl;
			cin >> Roll;
			Roll = toupper(Roll);

			if(Roll == 'Y')
			{
				cout << "Pick which dice to roll. Answer Y at that prompt to keep the die\n" << endl;
				PickDice(Dice);
			}
		}
		a++;
	}
	cout << "Out of 23 tests " <<Pcount << " passed and " <<Fcount << " failed"<<endl;
	return 0;
}
