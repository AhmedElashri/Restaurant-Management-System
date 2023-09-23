#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
using namespace std;

const int ENDCODE = 935115;
const int ENDORDER = 935;

int order[10] = { 0 };
int totalOrder[10] = { 0 };

void menu() {
	cout 
		<< "\tMenu Code     Food                          Price" << endl
		<< "\t    1         Chicken Sandwich              8.00 SAR" << endl
		<< "\t    2         Beef Sandwich                 9.00 SAR" << endl
		<< "\t    3         Tuna Sandwich                 10.00 SAR" << endl
		<< "\t    4         Coca Cola                     2.50 SAR" << endl
		<< "\t    5         Pepsi                         2.50 SAR" << endl
		<< "\t    6         Mirinda                       2.50 SAR" << endl
		<< "\t    7         Sprite                        2.50 SAR" << endl
		<< "\t    8         7up                           2.50 SAR" << endl
		<< "\t    9         Salad                         4.00 SAR" << endl
		<< "\t   10         Chocolate Cake                6.00 SAR" << endl;
}

int inputFix(string input) {
	string numbers = "";
	bool zeroCheck = true;
	int pchoice = 0;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[0] == '-' && zeroCheck == true && input.length() != 1) {
			numbers += "-";
			zeroCheck = false;
		}

		if (isdigit(input[i]))
			numbers += input[i];
	}
	if (!(input[0] == '-' && input.length() == 1))
	{
		if (numbers != "")
		{
			pchoice = stoi(numbers);
		}
	}
	else
	{
		pchoice = 0;
	}
	return pchoice;
}

void oList(int codes) {
	string fitem2;
	double price2 = 0.00;
	if (order[codes] != 0)
	{
	switch (codes)
	{
	case 0:
		fitem2 = "Chicken Sandwich";
		price2 = 8;
		break;
	case 1:
		fitem2 = "Beef Sandwich";
		price2 = 9;
		break;
	case 2:
		fitem2 = "Tuna Sandwich";
		price2 = 10;
		break;
	case 3:
		fitem2 = "Coca Cola";
		price2 = 2.50;
		break;
	case 4:
		fitem2 = "Pepsi";
		price2 = 2.5;
		break;
	case 5:
		fitem2 = "Mirinda";
		price2 = 2.5;
		break;
	case 6:
		fitem2 = "Sprite";
		price2 = 2.5;
		break;
	case 7:
		fitem2 = "7up";
		price2 = 2.5;
		break;
	case 8:
		fitem2 = "Salad";
		price2 = 4;
		break;
	case 9:
		fitem2 = "Chocolate Cake";
		price2 = 6;
		break;
	default:
		break;
	}

	cout << order[codes] << ' ' << fitem2 << ' ' << price2 * order[codes] << " SAR" << endl;
	}
}

void foList(int codes) {
	string fitem2;

	switch (codes)
	{
	case 0:
		fitem2 = "Chicken Sandwich";
		break;
	case 1:
		fitem2 = "Beef Sandwich   ";
		break;
	case 2:
		fitem2 = "Tuna Sandwich   ";
		break;
	case 3:
		fitem2 = "Coca Cola       ";
		break;
	case 4:
		fitem2 = "Pepsi           ";
		break;
	case 5:
		fitem2 = "Mirinda         ";
		break;
	case 6:
		fitem2 = "Sprite          ";
		break;
	case 7:
		fitem2 = "7up             ";
		break;
	case 8:
		fitem2 = "Salad           ";
		break;
	case 9:
		fitem2 = "Chocolate Cake  ";
		break;
	default:
		break;
	}

	if (totalOrder[codes] == 1)
	{
		cout << fitem2 << "\t" << "was Ordered " << totalOrder[codes] << " Time" << endl;
	}
	else
	{
		cout << fitem2 << "\t" << "was Ordered " << totalOrder[codes] << " Times" << endl;
	}
}

int main() {

	string choice = "";
	bool firstRun = true;
	bool fRun = true;
	string fItem, enterNextOrder;
	double price = 0.00;
	double total = 0.00;
	double totalPayout = 0.00;
	int fchoice = 0;
	
	while (fchoice != ENDCODE)
	{
		while (fchoice != ENDORDER && fchoice != ENDCODE)
		{
			if (firstRun == true)
			{
				cout << "Write down the code of a item and press enter"
					<< " \nIf you want to remove an item write \"-\" before the item's code."
					<< " \nWhen you are done type \"935\"" << endl;
				firstRun = false;
			}

			if (fRun == true)
			{
				menu();
				fRun = false;
			}

			
			cin >> choice;
			fchoice = inputFix(choice);
			switch (fchoice)
			{
			case 1:
				fItem = "Chicken Sandwich";
				price = 8.00;
				order[fchoice - 1]++;
				totalOrder[fchoice - 1]++;
				break;
			case 2:
				fItem = "Beef Sandwich";
				price = 9.00;
				order[fchoice - 1]++;
				totalOrder[fchoice - 1]++;
				break;
			case 3:
				fItem = "Tuna Sandwich";
				price = 10.00;
				order[fchoice - 1]++;
				totalOrder[fchoice - 1]++;
				break;
			case 4:
				fItem = "Coca Cola";
				price = 2.50;
				order[fchoice - 1]++;
				totalOrder[fchoice - 1]++;
				break;
			case 5:
				fItem = "Pepsi";
				price = 2.50;
				order[fchoice - 1]++;
				totalOrder[fchoice - 1]++;
				break;
			case 6:
				fItem = "Mirinda";
				price = 2.50;
				order[fchoice - 1]++;
				totalOrder[fchoice - 1]++;
				break;
			case 7:
				fItem = "Sprite";
				price = 2.50;
				order[fchoice - 1]++;
				totalOrder[fchoice - 1]++;
				break;
			case 8:
				fItem = "7up";
				price = 2.50;
				order[fchoice - 1]++;
				totalOrder[fchoice - 1]++;
				break;
			case 9:
				fItem = "Salad";
				price = 4.00;
				order[fchoice - 1]++;
				totalOrder[fchoice - 1]++;
				break;
			case 10:
				fItem = "Chocolate Cake";
				price = 6.00;
				order[fchoice - 1]++;
				totalOrder[fchoice - 1]++;
				break;
			case -1:
				fItem = "Removed Chicken Sandwich";
				price = -8.00;
				if (order[fchoice * -1 - 1] > 0)
				{
					order[fchoice * -1 - 1]--;
					totalOrder[fchoice * -1 - 1]--;
				}
				else
				{
					cout << "Chicken Sandwich Is Already At Zero" << endl;
					price = 99;
				}
				break;
			case -2:
				fItem = "Removed Beef Sandwich";
				price = -9.00;
				if (order[fchoice * -1 - 1] > 0)
				{
					order[fchoice * -1 - 1]--;
					totalOrder[fchoice * -1 - 1]--;
				}
				else
				{
					cout << "Beef Sandich Is Already At Zero" << endl;
					price = 99;
				}
				break;
			case -3:
				fItem = "Removed Tuna Sandwich";
				price = -10.00;
				if (order[fchoice * -1 - 1] > 0)
				{
					order[fchoice * -1 - 1]--;
					totalOrder[fchoice * -1 - 1]--;
				}
				else
				{
					cout << "Tuna Sandwich Is Already At Zero" << endl;
					price = 99;
				}
				break;
			case -4:
				fItem = "Removed Coca Cola";
				price = -2.50;
				if (order[fchoice * -1 - 1] > 0)
				{
					order[fchoice * -1 - 1]--;
					totalOrder[fchoice * -1 - 1]--;
				}
				else
				{
					cout << "Coca Cola Is Already At Zero" << endl;
					price = 99;
				}
				break;
			case -5:
				fItem = "Removed Pepsi";
				price = -2.50;
				if (order[fchoice * -1 - 1] > 0)
				{
					order[fchoice * -1 - 1]--;
					totalOrder[fchoice * -1 - 1]--;
				}
				else
				{
					cout << "Pepsi is Already At Zero" << endl;
					price = 99;
				}
				break;
			case -6:
				fItem = "Removed Mirinda";
				price = -2.50;
				if (order[fchoice * -1 - 1] > 0)
				{
					order[fchoice * -1 - 1]--;
					totalOrder[fchoice * -1 - 1]--;
				}
				else
				{
					cout << "Mirinda Is Already At Zero" << endl;
					price = 99;
				}
				break;
			case -7:
				fItem = "Removed Sprite";
				price = -2.50;
				if (order[fchoice * -1 - 1] > 0)
				{
					order[fchoice * -1 - 1]--;
					totalOrder[fchoice * -1 - 1]--;
				}
				else
				{
					cout << "Sprite Is Already At Zero" << endl;
					price = 99;
				}
				break;
			case -8:
				fItem = "Removed 7up";
				price = -2.50;
				if (order[fchoice * -1 - 1] > 0)
				{
					order[fchoice * -1 - 1]--;
					totalOrder[fchoice * -1 - 1]--;
				}
				else
				{
					cout << "7up Is Already At Zero" << endl;
					price = 99;
				}
				break;
			case -9:
				fItem = "Removed Salad";
				price = -4.00;
				if (order[fchoice * -1 - 1] > 0)
				{
					order[fchoice * -1 - 1]--;
					totalOrder[fchoice * -1 - 1]--;
				}
				else
				{
					cout << "Salad Is Already At Zero" << endl;
					price = 99;
				}
				break;
			case -10:
				fItem = "Removed Chocolate Cake";
				price = -6.00;
				if (order[fchoice * -1 - 1] > 0)
				{
					order[fchoice * -1 - 1]--;
					totalOrder[fchoice * -1 - 1]--;
				}
				else
				{
					cout << "Chocolate Cake Is Already At Zero" << endl;
					price = 99;
				}
				break;
			case ENDORDER:
				fItem = "Order:";
				price = -1;
				break;
			case ENDCODE:
				fItem = "Order:";
				price = -1;
				break;
			default:
				fItem = "Wrong Code. Try Again";
				price = -1;
				break;
			}

			if (price != -1)
			{
				if (price != 99)
				{
					if (fchoice < 0)
					{
						fchoice *= -1;
					}
					cout << order[fchoice - 1] << ' ' << fItem << ' ' << price << endl;
				}
			}
			else
			{
				if (fchoice == ENDORDER)
				{
					cout << '\n' << fItem << endl;
				}
			}

		}
		total = (double)8 * order[0] + 9 * order[1] + 10 * order[2] + 2.5 * order[3] + 2.5 * order[4] + 2.5 * order[5] + 2.5 * order[6] + 2.5 * order[7] + 4 * order[8] + 6 * order[9];


		fRun = true;
		if (fchoice == 935)
		{
			for (int i = 0; i < 10; i++)
			{
				oList(i);
			}
			cout << "\nTotal is " << total << " SAR" << endl;

			cin.ignore();
			cout << "\n\nPress Enter to Get the next order ready." << endl;
			cin.ignore();
			fchoice = 0;
			for (int i = 0; i < 10; i++)
			{
				order[i] = 0;
			}
			totalPayout += total;
			total = 0;
		}
		else
		{
			if (fchoice == 935115)
			{
				cout << "\n\n\n\n\n\n";
				for (int i = 0; i < 10; i++)
				{
					foList(i);
				}
				cout << "Total Money Earned Today: " << totalPayout << endl;
			}
		}

	}
}