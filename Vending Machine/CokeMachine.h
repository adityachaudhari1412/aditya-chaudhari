#ifndef _COKEMACHINE_H_
#define _COKEMACHINE_H_

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cstdlib>
/*enum Action
{
	OK=1, NOINVENTORY, NOCHANGE, INSUFFICIENTFUNDS, EXACTCHANGE
};*/

class CokeMachine
{

        friend std::ostream& operator<<(std::ostream& output, CokeMachine& Wout);
        friend std::string CreateCokeOutputLine(CokeMachine& MyCokeMachine);        

	public :
		
		std::string getMachineName();

		bool buyACoke(int payment, std::string &change, int &action);

		int getInventoryLevel();

		int getMaxInventoryCapacity();

		bool incrementInventory(int amountToAdd);

		std::string getChangeLevel();

		bool incrementChangeLevel(int amountToAdd);

		std::string getMaxChangeCapacity();

		std::string getCokePrice();

		const std::string displayMoney(int amount);

        void setMachineName(std::string NewName);

        void setCokePrice(int newPrice);

		CokeMachine(std::string name="New Machine", int cost=50, int change=500, int inventory=100);

		~CokeMachine();
		
		
	private :
		std::string machineName;
		int changeLevel;
		int maxChangeCapacity = 5000;
		int CokePrice;
		int inventoryLevel;
		int maxInventoryCapacity=100;
};

#endif