#include <iostream>
#include<stdio.h>
#include <string>
#include <iomanip>
#include "CokeLib.h"
#include "CokeMachine.h"
		

CokeMachine :: CokeMachine(std::string name, int cost, int change, int inventory)
		{
			machineName= name;
			changeLevel= change;
			CokePrice= cost;
			inventoryLevel= inventory;
		}
CokeMachine ::	~CokeMachine()
		{
			std::cout <<"CokeMachine  " << machineName <<" has been destroyed" << std::endl;
		}
std::string CokeMachine ::  getMachineName()
{
	return machineName;
    
}
bool CokeMachine :: buyACoke(int payment, std::string &change, int &action)
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
int CokeMachine :: getInventoryLevel()
{
	return inventoryLevel;
	
}
int CokeMachine :: getMaxInventoryCapacity()
{
	return maxInventoryCapacity;
}
bool CokeMachine :: incrementInventory(int amountToAdd)
{
	if((inventoryLevel + amountToAdd) <= maxInventoryCapacity)
	{
		inventoryLevel = inventoryLevel + amountToAdd;
		return true;
	}
	else
		return false;

}
std::string CokeMachine :: getChangeLevel()
{
	return displayMoney(changeLevel);

}
bool CokeMachine :: incrementChangeLevel(int amountToAdd)
{
	if((changeLevel + amountToAdd) <= maxChangeCapacity)
	{
		changeLevel = changeLevel + amountToAdd;
		return true;
	}
	else
		return false;
	

}
std::string CokeMachine :: getMaxChangeCapacity()
{
	return displayMoney(maxChangeCapacity);

}
std::string CokeMachine :: getCokePrice()
{
	return displayMoney(CokePrice);

}
const std::string CokeMachine :: displayMoney(int amount)
{

	std::string TMoney{};
	std::string Dollars(std::to_string(amount / 100));
	std::string Cents(std::to_string(amount % 100));

	TMoney = "$" + Dollars + "." + (Cents.size() == 1 ? "0" : "") + Cents;

	return TMoney;
	
}
void CokeMachine :: setMachineName(std::string NewName)
{
	machineName=NewName;
	return;
}
void CokeMachine :: setCokePrice(int newPrice)
{
	CokePrice=newPrice;
	return;
}
std::ostream& operator<<(std::ostream& output, CokeMachine& Wout)
{
	
	output<< "\n\n\nMachine Name:" << Wout.machineName << "\nCurrent Inventory Level  " << Wout.getInventoryLevel()<<std:: endl <<std:: endl << "Max Inventory Capacity   " << Wout.getMaxInventoryCapacity() << std::endl<<  "\n\nCurrent Change Level   " << Wout.getChangeLevel() <<"\n\nMax Change Capacity is   " << Wout.getMaxChangeCapacity() << std::endl<< "\n\n\n Current Coke price is   " << Wout.getCokePrice() << std::endl;
	return output;
}

std::string CreateCokeOutputLine(CokeMachine& MyCokeMachine)
{
    std::ostringstream out_put;
    out_put << MyCokeMachine.machineName << "|" << MyCokeMachine.CokePrice << "|" << MyCokeMachine.changeLevel << "|" << MyCokeMachine.inventoryLevel;
    return out_put.str();
}
