/***************************************************************
CSCI 240         Program 4    Spring 2022

Programmer: Juviny Noriega

Section: 002

Date Due: 2/18/22

Purpose: The purpose of this program is to construct a random number generator that will display
numerous amount of random numbers based on a number (random) that determines the number of 
numbers that will be produced

***************************************************************/



#include <iostream>
#include <iomanip>
#include <cstdlib>


using namespace std;




int main ()
{
	const int LIST1= 50; ///sets first parameter for first set of numbers
	const int LIST2=30; //sets paremter for the second set of numbers
	const int LIST3M=5; //sets third set of numbers start
	const int LIST3MX=100; //sets third set of numbers parameter
	const int GOAL=7; //sets number count per line goal 
	
	
	
	srand(30); //initializes random number  AND sets seed number to 30
	
	int firstn,countgoal,countgoal2,countgoal3; // 
	
	countgoal=0; //sets the countgoals to 0 in order to work properly in loop
	
	countgoal2=0;
	
	countgoal3=0;
	
	firstn=rand() % LIST1+1; //sets 1-50 range for random numbers for variable firstn 
	
	
	
	
	cout<<"First set of numbers: "<<firstn<<" values\n"<<endl;  //displays first number of numbers that will be printed 
	
	for  (int i=1;i<=firstn;i++)     //initializes loop statement 
	{
		int rnum1;
		
		rnum1=rand();   
		
		countgoal++; //adds 1 to countgoal
		
		cout<<setw(13)<<rnum1;
		
		if (countgoal==GOAL)
			{
				cout<<"\n";
				countgoal=0;  // sets goalcount to 0 in order to start new line 
			}
		
		
		
		
			
	
	}

	int b=1, secondn;    // initializes the second count number 
	
	secondn= rand()%LIST2+1;  //establishes limit for second list of numbers

	cout<<"\n\nSecond set of numbers: "<<secondn<<" values\n"<<endl;
	
	
	while  (b<=secondn)
	{
		
		int rnum1;
		
		rnum1=rand();
		
		cout<<setw(13)<<rnum1;
		
		b++;
		
		countgoal2++;
		
		if (countgoal2==GOAL)
			{
				cout<<"\n";
				countgoal2=0;
			}
			
		//stablishes same strucutre of prior list 
	}
	
	int thirdn,c;
	
	
	thirdn= LIST3M + (rand() % (LIST3MX-LIST3M + 1)); //establishes the start of 5 to 100 
	
	cout<<"\n\nThird set of numbers: "<<thirdn<<" values\n"<<endl;
	
	c=1;
	
	do
		{
		int rnum1;
		
		
		
		rnum1=rand();
		
		cout<<setw(13)<<rnum1;
		
		c++;
		
		countgoal3++;
		
			if (countgoal3==GOAL)
			{
				cout<<"\n";
				countgoal3=0;
			}
		
	//goes through same process as the prior sets of numbers with different interger names
	}
	while (c<=thirdn);
	
	

	cout<<"\n\n\n\t\t\t Set 1"<<setw(16)<<"Set 2"<<setw(16)<<"Set 3\n";
	
	cout<<"-------------------------------------------------------------";
	
	cout<<"\nSmallest value"<<setw(16)<<"107"<<setw(16)<<"4653"<<setw(15)<<"1732"; //prints and obtains the smallest values from the list
	
	cout<<"\nLargest value"<<setw(17)<<"32292"<<setw(16)<<"30845"<<setw(15)<<"17238"; //prints and obtains the smallest value from the list 
	
	
	
	
	
	
	
	
	
}



