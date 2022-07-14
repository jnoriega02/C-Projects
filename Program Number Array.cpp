/***************************************************************

Purpose: The pruose of this program is succesfully demonstrate the use of arrays 
by building two arrays based on random numbersand a text file that was 
used to generate these arrays. The programmer must show knoledge 
on the creation of arrays and show how to correctly 
use an input file.
***************************************************************/



#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>



using namespace std;

double randDouble();

int  buildRandom(double[]);

void print( string, double[], int );

void sort( double[], int );

int buildFile( double [] );  //these are the prototypes for each function


const double LOWER=1;
const double UPPER=750;
const int MINNUMA=25;
const int MAXNUMA=150;
const int MAXNUML=10; //establishes the constant variables for the program

int main()
{
	int size1,size2;
	cout<<fixed<<setprecision(3);  //sets decimal value to 3 
	
	double array1[MAXNUMA];
	double array2[MAXNUMA]; //creates both arrays with the intial maximun of 750
	
	
	
	srand(88);    //sets the seed value to 88
	
	
	size1= buildRandom(array1);  //calls buildtandom function to build first array of random numbers 
								
	
	cout<<"There are "<<size1<<" values in the first array";
	
	print("Random Values",array1,size1);   //succesfull prints the titel and displays the made array
	
	cout<<"\n";
	
	sort(array1,size1); //succesulfy sorts the array
	
	print("Sorted Values",array1,size1);
	
	
	
	
	size2=buildFile(array2);  //implemts the buildfile function whihc extracts double variables 
							  // from the txt file and places them into array 2
	
	cout<<"\n\nThere are "<<size2<<" values in the second array";

	
	print("File Values",array2,size2);
	
	cout<<"\n";
	
	sort(array2,size2);  //succesfully sorts list2
	
	print("Sorted File Values",array2,size2);  //prints sorted list
	
	
}



/***************************************************************
Function: BuildRandom

Use: This function implements a certain number of random values between
a range depending on the arrays max

Arguments:  double arr[]- a double array that will have values added 

Returns: an interger number that represents the number of variables in the array

***************************************************************/


int  buildRandom(double arr[])
{
	int randcount;
	
	randcount= MINNUMA+(rand()%(MAXNUMA-MINNUMA+1));
	
	for  (int i=0;i<=randcount;i++)
	{
		arr[i]=randDouble(); //for every aspect of the array randdouble is ran through 
	}
	
	
	return randcount;  //returns the number of numbers created 
	
}


/***************************************************************
Function: randDouble

Use: This function outputs a random double value within the min and max ranges given

Returns: the random value bewteen the ranges

***************************************************************/
double randDouble()
{
	double value;
	
	value= LOWER +( rand() / (RAND_MAX/(UPPER-LOWER)));   //establishes range for rnadom number range
	return value;
}


/*************************************************************
Function: print 

Use: This function prints the title and array . It also forms a new line every 10 values

Arguments:  string title- string title that is printed for the list 
			double array[]-array that is printed 
			 int numberofvalues-interger that is used to know the number of values being printed to form new line
			 
			 
Returns: printed title and array in set format

***************************************************************/

void print( string title, double array[], int numberofValues )
{
	cout<<"\n\n"<<left<<title;  //prints title 
	
	int line=0;
	
	cout<<"\n\n"<<"     ";
	for (int i=0;i<numberofValues;i++)   //sets a loop where it goes up until max amount of numbers
										 // in array
	{

		cout<<setw(10)<<array[i]<<setw(6);
		
		line++;
		
		
		if (line==MAXNUML)   //makes new line after 10 numbers are printed
		{
			cout<<"\n";
			line=0;
		}

	}
	
	
	
	
	
}

/***************************************************************
Function: sort

Use: to take an array and reorganize the postion according to value 

Arguments:  double array[]- a double array tbat will be sorted					   
           
           int numberofvalues- interger value that reoresents number of values in array

Returns: the sorted array

***************************************************************/


void sort( double array[], int numberofValues)
{
	int begin,end;
	
	begin=0;
	end=numberofValues;
	
	while (begin<end)
	{
		int low;
		low=begin;
		int I=begin+1;
		
		while (I < end)
		{
			if (array[I]>array[low])
			{
				low=I;  //again switches a number from the array if of greater value 
				
			}
			I=I+1;
		}
		double temp;
		
		temp=array[low];
		
		array[low]=array[begin]; //makes the switch so that the values can swap places in the array
		
		array[begin]=temp;
		
		
		

		
		
		begin=begin+1;
		
	}

}
/***************************************************************
Function: buildFile

Use: This function takes numbers from a text file and converts them into double variables 
	 and then places them into  a list

Arguments:  double array- array used to input values from file
					   
Returns: a list with the information from the txt file

***************************************************************/



int buildFile( double array[] )
{
	
	int sub=0; //sets the subscript nmber to 0
	double value;
	
	ifstream infile; 

	infile.open( "Program7file.txt");
	
	if( infile.fail() )       //if the input file failed to open
  		{
  		cout << "Program7file.txt input file did not open" << endl;
  		exit(-1);                //stop execution of the program immediately
  	
  		}
	
	while (infile>>value)
	{
		array[sub]=value;
		sub++;  //establishes every value from txt file as an number in array
	
	}
  		
  		
  		infile.close(); //closes the file
  		
  		return sub;  //returns the last sub number which gives the correct amount of numbers in array2
	


}

	
	
