/***************************************************************
CSCI 240         Program 10    Spring 2022

Programmer: Juviny Noriega

Section: 002

TA:VENKATI


Date Due: 5/5/22

Purpose: the purpose of this code is to For this assignment, modify 
the Player class from Program 8. The modifications include making some 
changes to some of the existing methods and adding a few new methods.
***************************************************************/



#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

/******************************************
class declaration for a hockey player
******************************************/
class Player
{
	public:
		Player();   //default constructor
		Player( const char[], int, int, int );   //constructor 2
		Player(int);//consturctor 3 
		
		void printPlayer();
		
		void setName( const char[] );  //two set methods
		void setNumber( int );
		
		void changeGoals( int );
		void changeAssists( int );
		
		char * getName();   //four get methods
		int getNumber();
		int getGoals();
		int getAssists();
		
		//new methods
		
		void setGoals(int);
		void setAssists(int);
		void setPlayer(const char[],int,int,int);
		
	private:                 //private members for a Player object
		char name[50];
		int number;
		int goals;
		int assists;
};

/******************************************
main routine/driver code
******************************************/
int main()
{
	cout<<"\nThe first Player object";
	
	Player ply1("Juviny Noriega", 52, 15, 13);  //declares player one
	ply1.printPlayer();
	
	ply1.setName("");
	ply1.setGoals(-18);
	ply1.setAssists(-42);
	
	ply1.printPlayer();
	

	cout<<"\nThe second Player object";
	Player ply2;
	ply2.printPlayer();    //declares the contructor for player 2
	
	ply2.setPlayer("Seth Jones",4, 5,44);
	ply2.printPlayer();
	
	


	
	cout<<"\nThe third Player object";
	Player ply3("Patrick Kane",88,23,60);    //declaration of player 3 class
	ply3.printPlayer();
	


	ply3.changeGoals(-8);     //tries to change goal count by a negative 
	ply3.changeAssists(-2);    //tries to change the assist count by a negative 
	ply3.printPlayer();        //displauys error messages due to the negative numbers


	
	ply3.changeGoals(1);
	ply3.changeAssists(2);     //succesfuully change goals and assists 
	ply3.printPlayer();
	

	cout<<"\nThe fourth Player object";
	Player ply4("Alex Debrincat",12,39,28);    //declaration of player 4 class
	ply4.printPlayer();
	
	

	cout<<"\nThe fifth Player object";
	Player ply5("Calvin de Haan " ,44,4,4);
	cout<<"\n"<<ply5.getName()<<" wears sweater number "<<ply5.getNumber()<<" and has scored "<<ply5.getGoals()<<" goals";    //prints only the name,number and goals instead utlizing print function to print class
	
	cout<<"\n\n";
	cout<<"\nThe sixth Player object";
	Player ply6("Dylan Strome", 17,20,23);
	cout<<"\nPLayer number "<<ply6.getNumber()<<" has earned "<<ply5.getAssists()<<" assists";   //prints solely the number and assists
	
	
	cout<<"\n\n";
	cout<<"\nthe seventh Player object";
	Player ply7(19); //new constructor
	ply7.printPlayer();
}  //end main routine


Player::Player()
{
	strcpy(name, "None");
	number=0;
	goals=0;
	assists=0;
	//default constructor
}


Player::Player( const char playerName[], int sweaterNum, int goalsScored, int assistEarned)
{
	strcpy(name, playerName) ;  //call functions in the constructor 
	number=sweaterNum;
	goals=goalsScored;
	assists=assistEarned;
	
	
	
}
/***************************************************************
Function: initialNumber

Use: this function takes names,goals,assists

Arguments:  initialNumber-takes number of player

Returns: nothing

***************************************************************/
Player::Player (int initialNumber)
{
	number=initialNumber;

	cout<<"\nwhat is player number "<<initialNumber<<" name? ";
	
	cin.getline( name , 49 );
	
	cout<<"\nHow many goals have been scored? ";
	cin>>goals;
	
	cout<<"\nHow many assists have been earned? ";
	cin>>assists;
	

}
/***************************************************************
Function: setName

Use: This function sets the private name variable to a public variable

Arguments:  playerName-a string variabel that equals the private name variable 

Returns: nothing

***************************************************************/
void Player::setName(const char playerName [])
{
	string null="";
	strcmp("",playerName);
	if (playerName == null)
	{
		cout<<"\nError in setName. the new name cannot be empty";
	
	}
	if (playerName != null)
	{
		strcpy(name,playerName);
	}
	
}
/***************************************************************
Function: setNumber

Use: sets the private number interger intro a public interger

Arguments:  playerName- interger variable that is set to the private variable "number" 

Returns: nothing

***************************************************************/
void Player:: setNumber (int newNumber)
{
    number=newNumber;
}
/***************************************************************
Function: getName

Use: returns the name variable

Arguments:  none

Returns: the private name variable

***************************************************************/
char * Player::getName()
{
	return name;
}
/***************************************************************
Function: getNumber

Use: This function returns the private number variable

Arguments:  nothing

Returns: the functions returns the number variable

***************************************************************/
int Player::getNumber()
{
	return number;
}
/***************************************************************
Function: getGoals

Use: This function returns the private number variable

Arguments:  none

Returns: the interger goal variable

***************************************************************/
int Player::getGoals()
{
	return goals;
}
/***************************************************************
Function: getAssists

Use: this funciton return the interger assists 

Arguments:  none

Returns: the integer assist variable

***************************************************************/
int Player::getAssists()
{
	return assists;
}
/***************************************************************
Function: changeGoals

Use: This function implements an if statement in which if the goal count is desired to be changed 
it must be equal to or greater than 0 which will then add the desired amount to the previous goal count, Otherwise an error message 
will be displayed.

Arguments:  goalscored- integer that represents the number that is desired to change the goal count by 


Returns: nothing

***************************************************************/
void Player::changeGoals(int goalsScored)
{
	
	
	if (goalsScored>=0)
	{

		goals=goalsScored+getGoals();
		
	}
	
	else
	{
		cout<< "\n\nError. Number of goals cannot be less than 0";
		
	}
	
}
/***************************************************************
Function: changeAssists

Use: This function implements an if statement in which if the assits count is desired to be changed 
it must be equal to or greater than 0 which will then add the desired amount to the previous assist count, Otherwise an erorr message 
will be displayed.


Arguments:  assistEarned-integer that represents the number that is desired to change the assist count by 

Returns: nothing

***************************************************************/
void Player::changeAssists(int assistsEarned)
{
	
	if (assistsEarned>=0)
	{
		assists=assistsEarned+getAssists();
		
		
	}
	else 
	{
		cout<< "\nError. Number of assists cannot be less than 0\n\n";
	}
	
}
/***************************************************************
Function: printPlayer

Use: This function prints the name , goals ,number, assists, and points in a set format 

Arguments:  none

Returns: none

***************************************************************/
void Player::printPlayer()
{
	
	int points;
	points=goals+assists;
	cout<<"\n"<<name<<setw(5)<<"#"<<number;
	
	cout<<"\nGoals: "<<goals<<setw(15)<<" Assists: "<<assists<<setw(15)<<" Points: "<<points<<"\n\n";
}

/***************************************************************
Function: setgoals

Use: This function sets goal and trows an error message

Arguments:  newgoals- finds new goals that is desired 

Returns: nothing

***************************************************************/
void Player::setGoals(int newGoals)
{
	if (newGoals>=0)
	{
		goals=newGoals;
	}
	else if (newGoals<0)
	{
		cout<<"\nError in setGoals. The # of goals scored cannot be negative";
	}
}
/***************************************************************
Function: setasssits

Use: This function replaces asssist value 

Arguments:  newassists- new number of assists

Returns: none

***************************************************************/
void Player::setAssists(int newAssists) 
{
	if (newAssists>=0)
	{
		assists=newAssists;
	}
	else if (newAssists<0)
	{
		cout<<"\nError in setAssists . The # of goals scored cannot be negative";
		cout<<"\n";
	}
	
}
/***************************************************************
Function: setplayer

Use: sets new player parameters

Arguments:  none

Returns: none

***************************************************************/
void Player::setPlayer(const char newName[],int newNumber,int newGoals, int newAssists)
{
	setName(newName);
	setNumber(newNumber);
	setGoals(newGoals);
	setAssists(newAssists);
	
}

