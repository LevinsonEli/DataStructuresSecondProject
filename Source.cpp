/**********************************/
/*  Targil 2 Mivne Netunim        */
/*	Eliyahu Levinson 336462346    */
/**********************************/

/* This program gets a n - size of array; an array of players: id - positive number,
   name - a string with two seperate words; a k - a positive number in range of ids.
   The program prints all the players that id < k in sorted way (from small) and
   number of comparison that algorithm did in 3 different ways:
   1. NaivePrint: gets all players that id < k to a sorted list and prints the list.
   2. BSTPrint: gets all the players to a binary search tree and prints all that id < k.
   3. PrintBySort: does a Quick Sort to the array and prints all players that id < k. */
/* Use the following template for input: 
   n
   id1 name lastName
   id2 name lastName
   ... ...   ...
   k
*/

#include <iostream>
#include "Player.h"
#include "SortedList.h"
#include "BST.h"
using namespace std;

/* This function gets an id and a name from keyboard and returns a player. */
Player * getPlayerFromKeyBoard();

/* This function get's a number of players as parameter and creates an array of 
   players that user inputed from keyboard. The function returns the array. */
Player ** getArrayOfPlayersFromKeyBoard(int n);

/* This function sorts the array of players by QuickSort and counts the number of comparisons. */
void sortArrayOfPlayers(Player ** arr, int left, int right, int & comparisonNum);

/* This function sets the 0s element of the array to his numericly correct place in the array.
   Also counts the number of comparisons. */
int Partition(Player ** arr, int left, int right, int & comparisonNum);

/* This function creates a sorted-list and put there k smallest elements of the array.
   Then the function prints the list and returns total number of comparisons. */
int NaivePrint(Player ** arr, int n, int k);

/* This function builds a binary search tree from the getted array and prints the first k
   elements in InOrder. Also returns the total number of comparisons. */
int BSTPrint(Player ** arr, int n, int k);

/* This function sorts the array by QuickSort, prints the first k elements and returns 
   the total number of comparison. */
int PrintBySort(Player ** arr, int n, int k);

int main()
{
	int n, k;
	cin >> n;
	if (n <= 0)
	{
		cout << "invalid input" << endl;
		exit(1);
	}
	cin.ignore(256, '\n');
	Player ** newArr = getArrayOfPlayersFromKeyBoard(n);
	cin >> k;
	if (k <= 0)
	{
		cout << "invalid input" << endl;
		exit(1);
	}

	cout << "NaivePrint: " << NaivePrint(newArr, n, k) << " comparisons" << endl << endl;
	cout << "BSTPrint: " << BSTPrint(newArr, n, k) << " comparisons" << endl << endl;
	cout << "PrintBySort: " << PrintBySort(newArr, n, k) << " comparisons" << endl << endl;

	system("pause");
	return 0;
}

Player * getPlayerFromKeyBoard()
{
	Player *newPlayer = new Player();
	string strInput;

	getline(cin, strInput);

	int indexOfFirstSpace = strInput.find(' ');
	if (indexOfFirstSpace == string::npos)			// if there is no a space in the string
		exit(1);
	string idStr = strInput.substr(0, indexOfFirstSpace);
	int id = stoi(idStr);
	string nameStr = strInput.substr(indexOfFirstSpace + 1);

	if (!newPlayer->setId(id))
		exit(1);
	if (!newPlayer->setName(nameStr))
		exit(1);

	return newPlayer;
}

Player ** getArrayOfPlayersFromKeyBoard(int n)
{
	Player ** newArr = new Player*[n];

	for (int i = 0; i < n; i++)
	{
		newArr[i] = getPlayerFromKeyBoard();
		for (int j = 0; j < i; j++)
		{
			if (newArr[i]->getId() == newArr[j]->getId())
				exit(1);
		}
	}

	return newArr;
}

void sortArrayOfPlayers(Player ** arr, int left, int right, int & comparisonNum)
{
	int pivot;

	if (left < right)
	{
		pivot = Partition(arr, left, right, comparisonNum);
		sortArrayOfPlayers(arr, left, pivot - 1, comparisonNum);
		sortArrayOfPlayers(arr, pivot + 1, right, comparisonNum);
	}
}

void swapTwoPlayers(Player * first, Player * second)
{
	Player * temp = new Player(second);
	second->setId(first->getId());
	second->setName(first->getName());
	first->setId(temp->getId());
	first->setName(temp->getName());
}
void swapTwoInts(int & first, int & second)
{
	first += second;
	second = first - second;
	first -= second;
}

int Partition(Player ** arr, int left, int right, int & comparisonNum)
{
	int pivot = left;
	int nonPivot = right;

	while (pivot != nonPivot)
	{
		comparisonNum++;
		if (arr[pivot]->getId() > arr[nonPivot]->getId())
		{
			if (nonPivot - pivot > 0)
			{
				swapTwoPlayers(arr[pivot], arr[nonPivot]);
				swapTwoInts(pivot, nonPivot);
			}
			nonPivot++;
		}
		else
		{
			if (pivot - nonPivot > 0)
			{
				swapTwoPlayers(arr[pivot], arr[nonPivot]);
				swapTwoInts(pivot, nonPivot);
			}
			nonPivot--;
		}
	}

	return pivot;
}

int NaivePrint(Player ** arr, int n, int k)
{
	SortedList * list = new SortedList();
	int comparisonNum = 0;

	for (int i = 0; i < n; i++)
		if (arr[i]->getId() < k)
		{
			comparisonNum++;
			list->Insert(arr[i], comparisonNum);
		}

	list->PrintList();

	return comparisonNum;
}

int BSTPrint(Player ** arr, int n, int k)
{
	BST * bst = new BST();
	int comparisonNum = 0;

	for (int i = 0; i < n; i++)
		bst->Insert(arr[i], comparisonNum);

	bst->PrintFirstElementsOfTree(k, comparisonNum);

	return comparisonNum;
}

int PrintBySort(Player ** arr, int n, int k)
{
	Player ** sortedArr = new Player *[n];
	int comparisonNum = 0;

	for (int i = 0; i < n; i++)
		sortedArr[i] = new Player(arr[i]);

	sortArrayOfPlayers(sortedArr, 0, n - 1, comparisonNum);
	int i = 0;

	while (i < n && sortedArr[i]->getId() < k)
	{
		comparisonNum++;
		cout << sortedArr[i]->getId() << " " << sortedArr[i]->getName() << endl;
		i++;
	}

	cout << "\nI = " << i << endl;

	return comparisonNum;
}