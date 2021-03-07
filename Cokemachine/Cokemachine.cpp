//Aditya Chaudhari 1001747134
#include <iostream>
#include<stdio.h>
#include <string>
#include <iomanip>

#include "CokeMachine.h"
using namespace std;
//enum ACTION {OK, NOINVENTORY, NOCHANGE, INSUFFICIENTFUNDS, EXACTCHANGE};

int main(void)
{
	
	CokeMachine MyCokeMachine{"Aditya's Coke Machine", 50, 500, 100};
    int m;
	//ACTION act;

    while(m!= 0)
    {
        cout << "Aditya's Coke Machine" << endl << endl << endl << "0.   Walk away" << endl << endl << "1.   Buy a Coke" << endl << endl << "2.   Restock Machine" << endl << endl << "3.   Add change" << endl << endl;
	    cout << "4.   Display Machine Info" << endl << endl;	
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
		    cout << "\n\nInsert payment ";
		    cin >>a;
		    poo=MyCokeMachine.buyACoke(a, chng, action);
		
		    if(poo)
            {
    		    if(action==0)
    		    {
    			    cout << "\n\n\nThank you for exact change" << endl <<"Here's your Coke\n\n\n";
    		    }
    		    else if(action==4)
    		    {
    			    cout << "\n\n\nHere's your Coke and your change of " << chng<< endl << endl << endl ;
    		    }
            }
		    else 
            {
                if(action==3)
    		    {
    			    cout << "\nInsufficent payment...returning your payment\n\n\n";
    		    }
    		    else if(action==2)
    		    {
    			    cout << "\nUnable to give change at this time...returning your payment\n\n\n";
    		    }
                else if(action==1)
                {
                    cout << "Sorry! The machine is out of Coke..............\n\n\n\n ";
                }
		   

            }
		
	    }
	    else if(m==2)
	    {
		    int d;
		    int e;
		    int m;
		    cout << "\nHow much product are you adding to the machine? ";
		    cin >> d;
		    e= MyCokeMachine.getInventoryLevel();
		    m= MyCokeMachine.getMaxInventoryCapacity();
		    if(e<m)
		    {
			    bool t;
			    t = MyCokeMachine.incrementInventory(d);
			    if(t)
			    {
				    e= MyCokeMachine.getInventoryLevel();
				    cout << "\n\n\nYour machine has been restocked\n\n\nYour inventory level is now  " << e<<endl << endl << endl;
			    }
			    else
			    {
				    cout << "\n\n\nYou have exceeded your machine's max capacity\n\n\n Your inventory level is now 100\n\n\n";
			    }
			
		    }
		    else
		    {
		    	cout << "\n\n\nYou have exceeded your machine's max capacity\n\n\n Your inventory level is now 100\n\n\n\n";
	    	}
	    }      
	    else if(m==4)
	    {
		    int r= MyCokeMachine.getInventoryLevel();
		    int s= MyCokeMachine.getMaxInventoryCapacity();
		    cout << "\n\n\nCurrent Inventory Level " << r << endl << endl << "Max Inventory Capacity " << s << endl;
		    string t= MyCokeMachine.getChangeLevel();
		    string y= MyCokeMachine.getMaxChangeCapacity();
            cout.precision(2);
		    cout << "\n\nCurrent Change Level " << t <<"\n\nMax Change Capacity " << y <<"\n\n\n\n" << endl;
		    string z= MyCokeMachine.getCokePrice();
		    cout << "\n\n\nCurrent Coke price is " << z <<"\n\n\n\n\n\n"<< endl;
	    }
	    else if(m==3)
	    {
		    string yy= MyCokeMachine.getChangeLevel();
		    string o=  MyCokeMachine.getMaxChangeCapacity();
		    int addy;
		    cout <<"How much change are you adding to the machine? ";
		    cin>> addy;
		    if(yy < o)
		    {
			    bool tt= MyCokeMachine.incrementChangeLevel(addy);
			    if(tt)
			    {
				    yy= MyCokeMachine.getChangeLevel();
				    cout <<"\n\n\nYour change has been updated\n\n\n\n\n Your change level is now  " << yy <<"\n\n\n\n\n\n"<<endl;
			    }
			    else
			    {
				    cout << "\n\n\nYou have exceeded your machine's max change capacity\n\n\n\nYour change level is now  " << yy<<"\n\n\n\n"<<endl;
			    }
		    }
		    else
		    {
			    cout << "\n\n\nYou have exceeded your machine's max change capacity\n\n\n\nYour change level is now  " << yy<<"\n\n\n\n"<<endl;
		    }
	    }    
    } 
    return 0;  
}	