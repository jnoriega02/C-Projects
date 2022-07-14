/***************************************************************
Purpose: The purpose of this program is to create a 2 player game that succesfully subtracts 
		 the number of chips player 1 or 2 chooses to take. The last player to take the last
		 chips wins the game.

***************************************************************/

#include <iostream>
#include <iomanip>


using namespace std;

int main () 
{
	cout<<"Rules:  The game starts with a pile of chips. Each player may only take at"<< endl;
    cout<<"\tmost half of the chips. The player that gets the last chip wins.";
    cout<<"\n\tGood luck!"; //prints basic format of prorgam needed 
	
	
	int schip,max,subtract;   //declares interger variables used in while statement 
    string player1,player2,currentplayer,oppplayer;   //declares string variables
    
    
    cout<<"\n\nPlayer 1 what is your name? ";
    cin>>player1;
    
    cout<<"\nPlayer 2 what is your name? ";
    cin>>player2;
    
    currentplayer= player1; //sets currentplayer intially to player 1
    
    oppplayer=player2;
    
    cout<<"\nWhat is the number of chips? ";
    cin>>schip;    //declares number of initial chips 
	cout<<endl;
    
    
    while (schip>0)
    {
		int rem;  //this variable is used to test whether a number is odd or even
		
		rem= schip%2;  //divides for remainder 
		
    	if (rem==0)   
    	{
    		max=schip/2;  //sets max case for even numbers 
		}
		
		else
		{
			max=(schip/2)+1;  //sets max case for odd numbers
		}

		cout<<endl<<currentplayer<<" how many of the remaining "<<schip<<" chips would you like (min: 1 -- max: "<<max<<")? ";  
		cin>>subtract; //intializes the varibale called subtract which is the number that is used to subtract from chip count
		
			while (subtract<1 || subtract>max)    //This processs is used to start the error message for incorrect value 
				{
					cout<<"\t*** "<<subtract<<" is invalid. Try again (min: 1 -- max: "<<max<<" ) ? ";
					cin>>subtract;//if use inputs correct valiue then will exit while and move on
				}
			
		
		if (currentplayer==player1)   //allows for a switch in the currentplayer variablr for next run
		{
			currentplayer=player2;
		}

		else 
		{
			currentplayer=player1;
			
		}
		
		if (oppplayer==player2)  // this goes in reverse to what the currentplayer module is 
								// in order to display the correct winner is at the end of the program 
		{
			oppplayer=player1;
		}

		else 
		{
			oppplayer=player2;
			
		}
		
		schip=schip-subtract;   //subtracts the number of chips the user chose from chip coiunt adnd makes it the new varibale
								//interger
		
	}	
	
	cout<<"\nCongratulations "<<oppplayer<<" ! You won the game!";  // displayers the correct winner

}


