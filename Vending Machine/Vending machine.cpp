#include <iostream>

#include<stdio.h>

#include <string>

#include <iomanip>

#include <fstream>

#include "CokeMachine.h"

#include "CokeLib.h"

using namespace std;

//enum ACTION {OK, NOINVENTORY, NOCHANGE, INSUFFICIENTFUNDS, EXACTCHANGE};

int main(int argc, char *argv[])

{
    string OutputFileName, InputFileName;
    try
    {
            get_command_line_params(argc, argv, InputFileName , OutputFileName);
    }
    catch(invalid_argument& my)
    {
            cerr << "An exception occured: " << my.what() << endl;
            return 0;
    }
    //CokeMachine MyCokeMachine{"Aditya's Coke Machine", 50, 500, 100};
    vector <CokeMachine> SetOfCokeMachines;
    vector<string> ConstructorValues(4);
    ifstream CokeInputFile(InputFileName);
    if(CokeInputFile.is_open())
    {
            string CokeMachineLine;
            string temp;
            while(getline(CokeInputFile,CokeMachineLine))
            {
                    
                    if(ParseCokeLine(CokeMachineLine,ConstructorValues))
                    {
                           CokeMachine TempMachine(ConstructorValues[0], stoi(ConstructorValues[1]),stoi(ConstructorValues[2]),stoi(ConstructorValues[3]));

                           SetOfCokeMachines.push_back(TempMachine);
                    }

            }
            CokeInputFile.close();	

    }
    else
    {
        cout<<"Unable to open file."<<endl; 
        CokeInputFile.close();  
        return 0;     
    }



    int m,mp,index,i;

    do
    {
        int x=0, msize;

        cout<<"Pick a Coke Machine."<<endl<<endl;
        cout<<x<<". Exit"<<endl<<endl;
        for( i=x+1;i<=SetOfCokeMachines.size();i++)
        {
            cout << i << ". "<< SetOfCokeMachines[i-1].getMachineName() << endl << endl;
        }
        cout<<i<<". Add a new machine"<<endl<<endl<<"Enter choice"<<endl<<endl;
        msize=i;
        cin >> mp;
        if(mp==0)
        {
            ofstream CokeOutputFile{OutputFileName,ios::out};
            if(CokeOutputFile.is_open())
            {
                for(i=0;i< SetOfCokeMachines.size();i++)
                {
                    CokeOutputFile << CreateCokeOutputLine(SetOfCokeMachines[i]);
                }               
            }
            else
            {
                cout<<"Unable to open file."<<endl; 
                CokeOutputFile.close();  
       
            }
            CokeOutputFile.close(); 
            return 0;
   
        }

        else if ( mp>0 && mp < msize )
        {
            index = mp-1;
            m=-1;
    
	        do

            {

                //cout << SetOfCokeMachines[index] ;
                cout << endl << endl << endl << "0.   Walk away" << endl << endl << "1.   Buy a Coke" << endl << endl << "2.   Restock Machine" << endl << endl << "3.   Add change" << endl << endl;

	            cout << "4.   Display Machine Info" << endl << endl;	
		        cout << "5.   Update Machine Name" << endl << endl <<"6.   Update Coke Price" << endl << endl;
		        

	            cin >> m ;

	            if(m==0)

	            {

		            cout << "\n\nAre you sure you aren't really THIRSTY and need a Coke\n?";	

	            }

	            else if(m==1)

	            {

		            int a,action;

		            string b;

		            string chng;

		            bool poo;

		            cout << "\n\nInsert payment  " ;

		            cin >>a;

		            poo= SetOfCokeMachines[index].buyACoke(a, chng, action);

		        

		            if(poo)

                    {

            		    if(action==0)

            		    {

            			    cout << "\n\n\n Thank you for exact change" << endl << "Here's your Coke\n";

            		    }

            		    else if(action==4)

            		    {

            			   

            			    cout << "\n\n\n Here's your Coke and your change of " << chng << endl ;

            		    }

                    }

		            else 

                    {

                        if(action==3)

            		    {

            			    cout << "\nInsufficent payment...returning your payment\n";

            		    }

            		    else if(action==2)

            		    {

            			    cout << "\nUnable to give change at this time...returning your payment\n";

            		    }

                        else if(action==1)

                        {

                            cout << "Sorry! The machine is out of Coke..............\n ";

                        }

		           



                    }

		        

	            }

	            else if(m==2)

	            {

		            int d;

		            int e;

		            int m;

		            cout << "\nHow much product are you adding to the machine? \n";

		            cin >> d;

		            e= SetOfCokeMachines[index].getInventoryLevel();

		            m= SetOfCokeMachines[index].getMaxInventoryCapacity();

		            if(e<m)

		            {

			            bool t;

			            t = SetOfCokeMachines[index].incrementInventory(d);

			            if(t)

			            {

				            e= SetOfCokeMachines[index].getInventoryLevel();

				            cout << "\n\n\nYour machine has been restocked\n\n\nYour inventory level is now  " << e<<endl;

			            }

			            else

			            {

				            cout << "\n\n\nYou have exceeded your machine's max capacity\n\n\n Your inventory level is now 100\n";

			            }

			        

		            }

		            else

		            {

		            	cout << "\n\n\nYou have exceeded your machine's max capacity\n\n\n Your inventory level is now 100\n";

	            	}

	            }      

	            else if(m==4)

	            {

		            cout <<SetOfCokeMachines[index];
			        continue;

	            }

	            else if(m==3)

	            {
    
		            int addy;
                    string yy;

		            cout <<"How much change are you adding to the machine? ";

		            cin>> addy;



		            bool tt= SetOfCokeMachines[index].incrementChangeLevel(addy);

		            if(tt)

		            {

			            yy= SetOfCokeMachines[index].getChangeLevel();

			            cout <<"\n\n\nYour change has been updated\n\n\n\n\n Your change level is now " << yy<<endl;

		            }

		            else

		            {

			            cout << "\n\n\nYou have exceeded your machine's max change capacity\n\n\n\nYour change level is now " << yy<<endl;

		            }

		            
	            } 
		        else if(m==5)
		        {
			        string nname = "";
			        cout << "Enter a new machine name   ";
                    cin.ignore(50,'\n');

			        getline(cin,nname,'\n');
			        SetOfCokeMachines[index].setMachineName(nname);
			        cout <<"Machine name has been updated";
		        }
		        else if(m==6)
		        {
			        int nprice;
			        cout << "Enter a new Coke price   ";
			        cin >> nprice;
			        SetOfCokeMachines[index].setCokePrice(nprice);
			        cout << "Coke price has been updated";
		        }
			        
	        }while(m!= 0);
	    
            
        }

        else if(mp == msize)
        {
            CokeMachine temp;
			SetOfCokeMachines.push_back(temp);
			cout << "New machine added\n" <<endl;
            msize++;
            
        }

    } while(mp != 0);   
	
}   