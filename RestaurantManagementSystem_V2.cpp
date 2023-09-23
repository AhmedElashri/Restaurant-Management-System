#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

//Constants
const int FOODSIZE = 5;
const int DRINKSIZE = 7;
const string ENDCODE = "end";
const string ORDERFINISHCODE = "fin";
const string EXITCODE = "exit";

//Functions

void displayFoodMenu(string fIdAndName[2][FOODSIZE], double fPrice[])
{
	cout << "\n\n" << left << setw(10) << "Food Id" << left << setw(30) << "Food" << left << setw(10) << "Food Price" << endl;
	for (int i = 0; i < FOODSIZE; i++)
		cout << left << setw(10) << fIdAndName[0][i] << left << setw(30) << fIdAndName[1][i] << left << setw(5) << fixed << setprecision(2) << fPrice[i] << " RM" << endl;
	cout << "\n";
}

void displayDrinkMenu(string dIdAndName[2][DRINKSIZE], double dPrice[])
{
	cout << "\n\n" << left << setw(10) << "Drink Id" << left << setw(30) << "Drink" << left << setw(10) << "Drink Price" << endl;
	for (int i = 0; i < DRINKSIZE; i++)
		cout << left << setw(10) << dIdAndName[0][i] << left << setw(30) << dIdAndName[1][i] << left << setw(5) << fixed << setprecision(2) << dPrice[i] << " RM" << endl;
	cout << "\n";
}

void menuSelection(string selectedMenu, string fIdAndName[2][FOODSIZE], double fPrice[], string dIdAndName[2][DRINKSIZE], double dPrice[])
{
	if (selectedMenu == "f")
	{
		displayFoodMenu(fIdAndName, fPrice);
	}
	else
	{
		if (selectedMenu == "d")
		{
			displayDrinkMenu(dIdAndName, dPrice);
		}
		else
		{
			if (selectedMenu != ENDCODE && selectedMenu != EXITCODE)
			{
				cout << "Invalid menu id, please enter a valid menu id." << endl;
			}
		}
	}
}

int quantityFix(string input) {
	string fixedq = "";
	bool zeroLocCheck = true;
	int output = 0;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[0] == '-' && input.length() != 1 && zeroLocCheck == true) {
			fixedq += "-";
			zeroLocCheck = false;
		}
			
		if (isdigit(input[i]))
			fixedq += input[i];
	}

	if (!(input[0] == '-' && input.length() == 1))
	{
		if (fixedq != "")
		{
			output = stoi(fixedq);
		}
	}
	else
	{
		output = 0;
	}
	return output;
}

void displayOrdered(int fOStorage[], int dOStorage[], string fIdAndName[2][FOODSIZE], string dIdAndName[2][DRINKSIZE], double fPrice[], double dPrice[]) {
	bool somethingWasOrdered = false;
	for (int i = 0; i < FOODSIZE; i++)
	{
		if (fOStorage[i] > 0)
		{
			if (somethingWasOrdered == false)
			{
				somethingWasOrdered = true;
				cout << "Current Ordered Items: " << endl;
			}
			cout << left << setw(5)<< fOStorage[i] << left << setw(20) << fIdAndName[1][i] << fixed << setprecision(2) << fPrice[i] * fOStorage[i] << " RM"<< endl;
		}
	}

	for (int i = 0; i < DRINKSIZE; i++)
	{
		if (dOStorage[i] > 0)
		{
			if (somethingWasOrdered == false)
			{
				somethingWasOrdered = true;
				cout << "Current Ordered Items: " << endl;
			}
			cout << left << setw(5) << dOStorage[i] << left << setw(20) << dIdAndName[1][i] << fixed << setprecision(2) << dPrice[i] * dOStorage[i] << " RM" << endl;
		}
	}
}

double displayFinishedOrder(int fOStorage[], int dOStorage[], string fIdAndName[2][FOODSIZE], string dIdAndName[2][DRINKSIZE], double fPrice[], double dPrice[]) {
	bool somethingWasOrdered = false;
	double total = 0.00;
	for (int i = 0; i < FOODSIZE; i++)
	{
		if (fOStorage[i] > 0)
		{
			if (somethingWasOrdered == false)
			{
				somethingWasOrdered = true;
				cout << "Ordered Items: " << endl;
			}
			cout << left << setw(5) << fOStorage[i] << left << setw(20) << fIdAndName[1][i] << fixed << setprecision(2) << fPrice[i] * fOStorage[i] << " RM" << endl;
			total += fOStorage[i] * fPrice[i];
		}
	}

	for (int i = 0; i < DRINKSIZE; i++)
	{
		if (dOStorage[i] > 0)
		{
			if (somethingWasOrdered == false)
			{
				somethingWasOrdered = true;
				cout << "Ordered Items: " << endl;
			}
			cout << left << setw(5) << dOStorage[i] << left << setw(20) << dIdAndName[1][i] << fixed << setprecision(2) << dPrice[i] * dOStorage[i] << " RM" << endl;
			total += dOStorage[i] * dPrice[i];
		}
	}


	cout << "The total is " << total << " RM" << endl;
	cout << "Press Enter To Continue Over To The Next Order..." << endl;

	cout << "\n\n\n\n";
	cin.ignore();
	return total;
}

string lowercase(string input) {
	string lowerout = "";
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] >= 65 && input[i] <= 90)
		{
			input[i] += 32;
			lowerout += input[i];
		}
		else
			lowerout += input[i];
	}
	return lowerout;
}


int main() {
	/*Food Variables*/
	string foodIdAndName[2][FOODSIZE] = { { "" }, {"Chicken Sandwich", "Beef Sandwich", "Tuna Sandwich", "Fruit Salad", "Chocolate Cake"} };
	double foodPrice[FOODSIZE] = { 8.00, 9.00, 10.00, 4.00, 6.50 };
	/*Food Id Initialization*/
	for (int i = 0; i < FOODSIZE; i++)
	{
		foodIdAndName[0][i] = "f" + to_string(i + 1);
	}

	/*Drink Variables*/
	string drinkIdAndName[2][DRINKSIZE] = { { "" }, { "7up", "Mirinda", "Coca Cola", "Pepsi", "Sprite", "Coffee", "Tea"} };
	double drinkPrice[DRINKSIZE] = { 2.50, 2.50, 2.50, 2.50, 2.50, 4.00, 3.50 };
	/*Drink Id Initialization*/
	for (int i = 0; i < DRINKSIZE; i++)
	{
		drinkIdAndName[0][i] = "d" + to_string(i + 1);
	}

	/*Inputs*/
	string mChoice = "";
	string iChoice = "";
	string quantity = "";

	/*Storage Code*/
	int foodOrderStorage[FOODSIZE] = { 0 };
	int drinkOrderStorage[DRINKSIZE] = { 0 };
	int customer = 0;
	
	/*Outputs*/
	double overallTotal = 0.00;

	/*Other Used Variables*/
	bool orderBegining = true;
	int quantityFixed = 0;
	/*Code*/
	while (mChoice != EXITCODE)
	{
		while (mChoice != ENDCODE && mChoice != EXITCODE)
		{
			if (orderBegining == true) {
				orderBegining = false;
				cout << "Hello and welcome to Pri-Ad Diner!\n";
			}

			cout << "Enter \"f\" to view the food menu or enter \"d\" to view the drinks menu.\n"
				<< "When you are done with your order, please type \"" << ENDCODE << "\"" << endl;


			while (mChoice != "f" && mChoice != "d" && mChoice != EXITCODE && mChoice != ENDCODE && mChoice != "-") {
				getline(cin, mChoice);
				mChoice = lowercase(mChoice);
				menuSelection(mChoice, foodIdAndName, foodPrice, drinkIdAndName, drinkPrice);
			}


			int failCounter;
			bool failed;
			int storedLocation;
			while (iChoice != ORDERFINISHCODE && mChoice != ENDCODE && mChoice != EXITCODE)
			{
				failCounter = 0;
				failed = false;
				storedLocation = 0;

				if (mChoice == "f")
				{
					cout << "Enter the id of the food item you would like to order. \nIf you are done ordering from the food menu please type \"fin\"" << endl;
					getline(cin, iChoice, '\n');
					iChoice = lowercase(iChoice);

					if (iChoice != ORDERFINISHCODE)
					{
						for (int i = 0; i < FOODSIZE; i++)
						{
							if (iChoice == foodIdAndName[0][i])
							{
								cout << "\n\nCurrent selected item: " << foodIdAndName[1][i] << endl;
								storedLocation = i;
							}
							else
							{
								failCounter++;
								if (failCounter == FOODSIZE)
								{
									cout << "Invalid Id, Please try again." << endl;
									failed = true;
								}
							}
						}
						if (failed == false)
						{
							cout << "Enter the quantity you want for that item. Enter a negative number to remove from the item." << endl;
							getline(cin, quantity, '\n');
							quantityFixed = quantityFix(quantity);
							if (quantityFixed >= 1)
							{
								cout << "\nAdded " << quantityFixed << " of " << foodIdAndName[1][storedLocation] << " for " << foodPrice[storedLocation] * quantityFixed << " RM" << endl;
								foodOrderStorage[storedLocation] += quantityFixed;
							}
							else
							{
								if (quantityFixed >= -foodOrderStorage[storedLocation])
								{
									cout << "\nRemoved " << -quantityFixed << " of " << foodIdAndName[1][storedLocation] << endl;
									foodOrderStorage[storedLocation] += quantityFixed;
								}
								else
								{
									cout << "\n" << foodIdAndName[1][storedLocation] << " was reset to zero." << endl;
									foodOrderStorage[storedLocation] = 0;
								}
							}
						}
					}
					if (iChoice != ORDERFINISHCODE)
					{
						displayFoodMenu(foodIdAndName, foodPrice);
					}
				}
				else
				{
					if (mChoice == "d")
					{
						cout << "Enter the id of the drink you would like to order. \nIf you are done ordering from the drink menu please type \"fin\"" << endl;
						getline(cin, iChoice, '\n');
						iChoice = lowercase(iChoice);

						if (iChoice != ORDERFINISHCODE)
						{
							for (int i = 0; i < DRINKSIZE; i++)
							{
								if (iChoice == drinkIdAndName[0][i])
								{
									cout << "\n\nCurrent selected item: " << drinkIdAndName[1][i] << endl;
									storedLocation = i;
								}
								else
								{
									failCounter++;
									if (failCounter == DRINKSIZE)
									{
										cout << "Invalid Id, Please try again." << endl;
										failed = true;
									}
								}
							}
							if (failed == false)
							{
								cout << "Enter the quantity you want for that drink. Enter a negative number to remove from the item." << endl;
								getline(cin, quantity, '\n');
								quantityFixed = quantityFix(quantity);
								cout << "Ordered " << quantityFixed << " of " << drinkIdAndName[1][storedLocation] << " for " << drinkPrice[storedLocation] * quantityFixed << " RM" << endl;
								drinkOrderStorage[storedLocation] += quantityFixed;
							}
						}
						if (iChoice != ORDERFINISHCODE)
						{
							displayDrinkMenu(drinkIdAndName, drinkPrice);
						}
					}
				}
			}

			cout << "\n\n";
			if (mChoice != ENDCODE)
			{
				displayOrdered(foodOrderStorage, drinkOrderStorage, foodIdAndName, drinkIdAndName, foodPrice, drinkPrice);
			}
			cout << "\n\n";
			/*Hard Reset*/
			if (mChoice == ENDCODE) {
				if (iChoice != ORDERFINISHCODE)
				{
					overallTotal += displayFinishedOrder(foodOrderStorage, drinkOrderStorage, foodIdAndName, drinkIdAndName, foodPrice, drinkPrice);
				}
				customer++;
				ofstream saveWrite("SaveFile.txt", fstream::app);
				saveWrite << "\nCustomer #" << customer << " Ordered: " << endl;
				double totalSave = 0;
				for (int i = 0; i < FOODSIZE; i++)
				{
					if (foodOrderStorage[i] > 0)
					{
						saveWrite << left << setw(5) << foodOrderStorage[i] << left << setw(20) << foodIdAndName[1][i] << fixed << setprecision(2) << foodPrice[i] * foodOrderStorage[i] << " RM" << endl;
						totalSave += foodOrderStorage[i] * foodPrice[i];
					}
				}
				for (int i = 0; i < DRINKSIZE; i++)
				{
					if (drinkOrderStorage[i] > 0)
					{
						saveWrite << left << setw(5) << drinkOrderStorage[i] << left << setw(20) << drinkIdAndName[1][i] << fixed << setprecision(2) << drinkPrice[i] * drinkOrderStorage[i] << " RM" << endl;
						totalSave += drinkOrderStorage[i] * drinkPrice[i];
					}
				}
				saveWrite << "\nTotal is " << totalSave << " RM" << endl;
				saveWrite.close();
				if (mChoice != EXITCODE)
				{
					mChoice = "";
				}
				orderBegining = true;
				for (int i = 0; i < FOODSIZE; i++)
				{
					foodOrderStorage[i] = 0;
				}
				for (int i = 0; i < DRINKSIZE; i++)
				{
					drinkOrderStorage[i] = 0;
				}
			}
			/*Soft Reset*/

			if (mChoice != EXITCODE)
			{
				mChoice = "-";
			}
			if (mChoice == "-")
			{
				mChoice = "";
			}

			iChoice = "";
			
		}
	}
	cout << "\n\n\n\n";
	cout << "Total Number of Orders Today: " << customer << endl;
	cout << "Total Earnings Today: " << overallTotal << " RM" << endl;
}