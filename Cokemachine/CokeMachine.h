//Aditya Chaudhari 1001747134
#ifndef _COKEMACHINE_H_
#define _COKEMACHINE_H_

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstdlib>

/*enum Action
{
	OK=1, NOINVENTORY, NOCHANGE, INSUFFICIENTFUNDS, EXACTCHANGE
};*/
class CokeMachine
{
	public :
		CokeMachine(std::string name, int cost, int change, int inventory )
		{
			machineName= name;
			changeLevel= change;
			CokePrice= cost;
			inventoryLevel= inventory;
		}
		std::string getMachineName()
		{
			std::string n = machineName;
            		return n;
		}
		bool buyACoke(int payment, std::string &change, int &action)
		{
			if(inventoryLevel>0)
			{
				if(payment==50)
				{
					action = 0;
					inventoryLevel--;
					return true;
				}
				else if(payment>50)
				{
					int c = payment-50 ;
					if(c<changeLevel)
					{
						changeLevel= changeLevel-c;
						change= displayMoney(c);
						action= 4;
						inventoryLevel--;
						return true;
					}
					else
					{
						action=2;
						return false;
					}
				}
				else
				{
					action=3;
					return false;
				}
			}
			else
			{
				action=1;
				return false;
			}
		
		}
		int getInventoryLevel()
		{
			return inventoryLevel;
			
		}
		int getMaxInventoryCapacity()
		{
			return maxInventoryCapacity;
			
		}
		bool incrementInventory(int amountToAdd)
		{
			if((inventoryLevel + amountToAdd) <= maxInventoryCapacity)
			{
				inventoryLevel = inventoryLevel + amountToAdd;
				return true;
			}
			else
				return false;
		
		}
		std::string getChangeLevel()
		{
		    return displayMoney(changeLevel);
		
		}
		bool incrementChangeLevel(int amountToAdd)
		{
			if((changeLevel + amountToAdd) <= maxChangeCapacity)
			{
				changeLevel = changeLevel + amountToAdd;
				return true;
			}
			else
				return false;
			
		
		}
		std::string getMaxChangeCapacity()
		{
			return displayMoney(maxChangeCapacity);
		
		}
		std::string getCokePrice()
		{
			
            return displayMoney(CokePrice);
		
		}
		std::string displayMoney(int amount)
		{
		
			std::string TMoney{};
			std::string Dollars(std::to_string(amount / 100));
			std::string Cents(std::to_string(amount % 100));

   			TMoney = "$" + Dollars + "." + (Cents.size() == 1 ? "0" : "") + Cents;

			return TMoney;
            
		}
	private :
		std::string machineName;
		int changeLevel;
		int maxChangeCapacity = 5000;
		int CokePrice;
		int inventoryLevel;
		int maxInventoryCapacity=100;
};
#endif