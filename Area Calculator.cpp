/***************************************************************
Purpose: 
The purpose of this program is to provide a multi-area calcultor that provides 
a calculation for the area of the specific shapes:triangle,trapezoid,ellipse,and circle
using the user input and implementing an error message is invalid value is inputed
***************************************************************/
#include <iostream>
#include <iomanip>
#include<math.h>

using namespace std;

int main ()
{
	//this obtians the users choice form the calculator menu 
	cout<<left<<"Area Calculator"<<endl;
	cout<<"\n1. Calculate the area of a circle"<<endl<<"2. Calculate the area of a triangle"<<endl<<"3. Calculate the area of a trapezoid"<<endl<<"4. Calculate the area of an ellipse"<<endl;

	cout<<fixed<<setprecision(3);
	int choice;
	
	cout<<"\nEnter your choice (1-4):";
	cin>> choice;
	
	if ((choice<1)||(choice>4))   //establishes the error message for any other imput that isnt 1-4
	{
		cout<<choice<<" is an invalid choice from the menu";
	}
	
	else if (choice==1) ////first choice is made into an if statemtn for circle calculator 
	{
	
	
	int r;
	float areaC;
	const float PI=3.14159;
	
	cout<<"\nWhat is the radius of the circle? ";
	cin>>r;
	
	if (r<0)  //case if user enters any radous below 0
	{
		cout<<r<<" is an invalid value. It must be greater than 0. Try again: ";
		cin>>r;	//obtains the users corrected radius value
	}
	
	areaC=PI*(pow(r,2)); //obtains the formula for circle area and math.h is used for power
	
	cout<<"\nThe area of a circle with a radius "<<r<< " is "<< areaC<<endl; ///displays the answer for the area 
	}
	
	
	
	else if (choice==2) ////calculator for triangle area 
	{
		int lengthT,heightT;
		float areaT;
		
		cout<<"\nWhat is the length of the triangle base? ";
		
		cin>>lengthT;
		
		if (lengthT<0)  //case if user inputs an invalid value 
		{
		
		cout<<lengthT<<" is an invalid value. It must be greater than 0. Try again: ";
		cin>>lengthT;
		}
		
		
		cout<<"\nWhat is the height of the triangle base? ";
		cin>>heightT;
		
		
		if (heightT<0)
		{
		cout<<heightT<<" is an invalid value. It must be greater than 0. Try again: ";
		cin>>heightT;	
			
		} 
		
		areaT= (.5)*heightT*lengthT; //formula for area of a triangle
		
		cout<<"The area of a triangle with a base of  "<<lengthT<<" and height of "<<heightT<<" is "<<areaT;
		
	}
	
	
	else if (choice==3) //calculator for trapizoid 
	{
		int lengthTR1,lengthTR2,heightTR;
		float areaTR;
		
		cout<<"\nWhat is the length of the top of the trapezoid? ";
		cin>>lengthTR1;   //establishes first varibale if user inputs valid value
		
		if (lengthTR1<0)
		{
			cout<<lengthTR1<<" is an invalid value. It must be greater than 0. Try again: ";
			cin>>lengthTR1; //establishes first valie after user inputs valid value
		}
		
		cout<<"\nWhat is the length of the bottom of the trapezoid? ";
		cin>>lengthTR2;  //establishes second lenght value for formula of trapazoid 
		
		
		if (lengthTR2<0)
		{
			cout<<lengthTR2<<" is an invalid value. It must be greater than 0. Try again: ";
			cin>>lengthTR2;  //establishes second length value once user inputs valid value
			
		}
		
		cout<<"\nWhat is the height of the trapezoid? ";
		cin>>heightTR; //established heigh varibale for trapazoid area formula
		
		if (heightTR<0)
		{
			cout<<heightTR<<" is an invalid value. It must be greater than 0. Try again: ";
			cin>>heightTR;
		}
		
		areaTR=(.5)*(lengthTR1*lengthTR2)*heightTR;
		
		cout<<"\nThe area of a trapezoid with a top length of "<<lengthTR1<<", bottom length of "<<lengthTR2<<", and height of "<<heightTR<<" is "<<areaTR;
		
	}
	
	
	else if (choice==4)   //calculator for elipses
	{
		int miniA,majorA;
		float areaE;	
		const float PI=3.14159;   //pi is established as a constant interger 
		
		
		cout<<"\nWhat is the length of the semi-major axis of the ellipse? ";
		cin>>majorA;
		
		if (majorA<0)   //case for invaldi number
		{
			cout<<majorA<<" is an invalid value. It must be greater than 0. Try again: ";
			cin>>majorA;   //establishes majorA variable after first invalid attempt at value
		}
		
		cout<<"\nWhat is the length of the semi-minor axis of the ellipse? ";
		cin>>miniA; ///establishd second variable needed to retain area of elipse 
		
		if (miniA<0)  // case for invalid number for variable "miniA"
		{
			cout<<miniA<<" is an invalid value. It must be greater than 0. Try again: ";
			cin>>miniA;
		}
		
		areaE=PI*(miniA*majorA);  //formula for area of ellipse
		
		cout<<"\nThe area of an ellipse with a semi-major axis length of "<<majorA<<" and semi-minor axis length of "<<miniA<<" is "<<areaE;
	}
	
}
