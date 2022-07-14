/***************************************************************
CSCI 240         Program 9   Spring 2022

Programmer: Juviny Noriega

Section: 002

TA:FATEMAH


Date Due: 4/30/22

Purpose: The purpose of this program is to demonstrate the use of class both provate and public use usinf cuntiosn pertaining to 
specificallly PARABOLAS. THE PROGRAM SUCESSFULY DEVLOPES THE USE OF FUNCTIONS AND DISPLAYS SPECIFICALLY THE USE OF REFERECNE WITHIN THE PRORGAM
***************************************************************/




#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include<cmath> 

using namespace std;

class parabola 
{
	public:
		parabola( double, double,double );   //constructor 
		
		double calcX();
		double calcY(); 
		
	
		
		
		double calcDiscrim();
		
		int calcRoots(double& root1, double &root2 );
		void printEquation();
		
		void printRoots();
		void printVertex();  
		void printConcavity();
		void print();
		
	private:                 //private members for a Player object
		double A;
		double B;
		double C;
		
		
};

/******************************************
main routine/driver code
******************************************/
int main ()
{
	
	parabola para1(1,4,-5); //MAKES THE PARABOLA
	
	parabola para2(-1,2,-1);    //MAKES THE PARABOLA 
	
	parabola para3(0,0,25);     
	
	parabola para4(-12,-2,3);
	
	parabola para5(2,5,-3);
	
	cout<<"\nThe first parabola";
	cout<<"\n\n";
	para1.print();   //CALLS THE PRINT FUNCTION
	
	cout<<"\n\n\nThe second parabola";
	cout<<"\n\n";
	
	para2.print();
	
	
	cout<<"\n\n\nThe third parabola";
	cout<<"\n\n";
	para3.print();
	
	
	cout<<"\n\n\nThe fourth parabola";
	cout<<"\n\n";
	para4.print();
	
	
	cout<<"\n\n\nThe fifth parabola";
	cout<<"\n\n";
	para5.print();
	
}
	

parabola::parabola( double A2, double B2, double C2)   //CONSTRUCTOR
{
	
	if (A2==0)
	{
		A2=1;
		cout<<"***Error: the a-coefficiant cannot be 0***";   //DISPLAYS ERROR MESSAGE
	}
	else 
	{
		A=A2;  //call functions in the constructor 
		
	}
	B=B2;
	C=C2;
}
/***************************************************************
Function: CALCX

Use: This function SETS THE X COORDINATE

Arguments:  NONE

Returns: A DOUBLE INTERGER NAMED X

***************************************************************/
double parabola::calcX()
{
	
	double X;
	
	X=-B/(2*A);   //SETS THE X COORDINARETE WITH FORMULA GIVEN
	
	return X;
	
}
/***************************************************************
Function: CALCY

Use: THE FUNCTION SETS THE Y COORDINATE

Arguments:  NONE

Returns: A DOUBLE VALUE OF X

***************************************************************/
double parabola::calcY()
{
	double Y;
	
	Y=A*calcX()*calcX()+B*calcX()+C;
	
	return Y;
	
}
/***************************************************************
Function: CALCDISCRIM

Use: CALCULATES THE DISCRIMANATE

Arguments:  NONE

Returns:  A DOUBLE VALUE KNOWN AS THE DISCRIMINANT

***************************************************************/
double parabola::calcDiscrim()     
{
	double decrim;
	
	decrim=B*B-4*A*C;
	
	return decrim;
}
/***************************************************************
Function: CALCROOTS

Use: This functION USES PRIOR CALCDISCRIM FUNCTION TO DETERMINE THE NUMBER OF ROOTS AND DISPLAY THE ACTUAL ROOTS

Arguments:  ROOT1 AND ROOT2

Returns: AN INTERGER SAYING HOW MANY ROOTS THERE ARE A DN DEPENDING ON THE INTERGER ROOT1 ROOT2 

***************************************************************/

int parabola::calcRoots (double& root1, double &root2 )
{
	double descriminant= calcDiscrim();
	
	if (descriminant>0)
	{
		root1=(-B+sqrt(calcDiscrim()))/(2*A);
		
		root2=(-B-sqrt(calcDiscrim()))/(2*A);
		
		return 2;
	}
	else if (descriminant==0)
	{
		root1=(-B+sqrt(calcDiscrim()))/(2*A);
		
		return 1;
	}
	else
	{
		return 0;
	}
}

/***************************************************************
Function: PRINTEQUATION

Use: This FUNCTION PRINTS THE EQUATION FOR THE PARABOLA 

Arguments:  NONE

Returns: THE PRINTED EQUATION

***************************************************************/
void parabola::printEquation()
{
	cout<<fixed<<setprecision(1);
	
	cout<<A<<"x^2 + "<<B<<" X + "<<C<<"= 0";
		
}	

/***************************************************************
Function: PRINTVERTEX

Use: This function PRINTS THE VERTEX IN A SET FORMAT USING PRIOR FUNCTIONS

Arguments:  NONE

Returns: VERTEX PRINTED IN THE FORM THAT WAS ASKED

***************************************************************/
void parabola::printVertex()
{
	double X,Y;
	X=calcX();
	Y=calcY();
	cout<<fixed<<setprecision(3)<<"Vertex: ("<<X<<","<<Y<<")";

}
/***************************************************************
Function: PRINT ROOTS

Use: This function PRINTS THE ROOTS AND PRINTS HOW MANTY ROOTS THERE ARE IN A SENTENCE

Arguments:  NONE

Returns: ROOT1 OR AND ROOT2 AND A SENTENCE DECLARING HOW MANY ROOTS 

***************************************************************/
void parabola::printRoots()
{
	int numRoots;
	double root1,root2;
	
	numRoots=calcRoots(root1,root2);
	
	cout<<fixed<<setprecision(3);
	 if (numRoots==1)
	{
		cout<<"There is one real root with X-Coordinate "<<root1<<" value";
	}
	else if (numRoots==2)
	{
		cout<<"There are two real roots with X-coordinates "<<root1<<" and "<<root2;
	}
	else //if (numRoots<=0)
	{
		cout<<"There are NO real roots";
		
	}
	
	
	
}
/***************************************************************
Function: PRINTCONCAVITY

Use: This function PRINTS WHIHC WAY THE PARABOLA OPENS

Arguments:  NONE 

Returns: A SENTENCE DETAILING WHIHC WAY THE PARABOLA OPENS

***************************************************************/

void parabola::printConcavity()
{
	if (A>0)
	{
		cout<<"the parabola opens UPWARD";
	}
	else if (A<0)
	{
		cout<<"the parabola opens DOWNWARD";
	}
}
/***************************************************************
Function: PRINT

Use: This function PRINTS ALL OF THE PRIOR FUNCTIONS MENTIONED IN A SET FORMAT

Arguments: NOTHING 

Returns: ALL PRIOR FUNCTIONS MENTIOED IN A SET FORMAT

***************************************************************/
void parabola::print()
{
	printEquation();
	cout<<"\n    ";
	printVertex();
	cout<<"\n    ";
	printConcavity();
	cout<<"\n   ";
	printRoots();
	
}


	
	


