/***************************************************************
CSCI 240         Program 6    Spring 2022

Programmer: Juviny Noriega

Section: 002

Date Due: 3/20/22

Purpose: The pruose of this program is the demostrate the proper use fo functions 
by creating a program which uses a variety of functions that calculates,grades, grade points,
and GPA
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int getInterger(string);

double calcGPA( int, int );

string findgLevel( int );  

string gString( string);

int pickPoints( string);



int main ()
{
	cout<<fixed<<setprecision(2);  //allows for the fixed number of GPA to be 3 digit
	int studentID,screds,spoints,tpoints,tcreds;  
	string iglevel;
	string newgLevel;
	string Cinfo;
	double fGPA,tGPA;
	
	studentID=getInterger("Enter the student's ID number: ");  //runs the first function
	screds=getInterger("Enter credit hours at start of semester: ");
	spoints=getInterger("Enter the grade points at start of semester: ");
	
	cout<<"\n\n";
	fGPA=calcGPA(spoints,screds); //calculates the GPA at begining of year 
	
	iglevel= findgLevel(screds);
	
	
	tpoints=spoints;
	
	tcreds=screds;
	
	tGPA=fGPA;
	
	Cinfo=gString("Is there more course information (y or n): "); 
	

	while (Cinfo=="y"||Cinfo=="Y")   // start of loop 
	{
		cout<<"\n";
		
		int addp,addh,pforcourse;
		
		addh=getInterger("Enter the credit hours for the course: ");  // ask for information on course
		addp=pickPoints ("Enter the grade for the course: ");

		pforcourse=addh*addp;
				
		tcreds=tcreds+addh;     //changes the total credits everytime loops run through
		
		tpoints=tpoints+pforcourse;    //changes total points 
		
		tGPA=calcGPA(tpoints,tcreds);    //utlizes the calcGPA function in order to calculate new GPA
		
		newgLevel=findgLevel(tcreds);     //utilizes newglevel function to find grade level
		
		
		cout<<"\n";
		Cinfo=gString("Is there more course information (y or n): "); 


	}
	
	
	cout<<left<<"\nStudent: "<<studentID;   //displays te intended format of the message of information to user 
	
	cout<<left<<"\nGrade Level: "<<iglevel<<setw(15)<<"  Credit: "<<screds<<setw(10)<<"   Points: "<<spoints<<setw(10)<<"   GPA: "<<fGPA<<endl;
	
	if (fGPA>tGPA)    //only displays second line of informaiton if information is  different
	{
		
		cout<<left<<"\nGrade Level: "<<newgLevel<<setw(15)<<"  Credit: "<<tcreds<<setw(10)<<"   Points: "<<tpoints<<setw(10)<<"   GPA: "<<tGPA<<endl;
		
	}
	
}




	int getInterger ( string prompt)
{
	int userInt;   
	
	
	cout<<prompt;
	cin>>userInt;  
	
	while (userInt<=0)
	{
		cout<<"*** "<<userInt<< " is invalid. Try again: ";
		cin>>userInt;
	}
	return userInt;
}

/***************************************************************
Function: calcGPA

Use: This function calculates a grade point average

Arguments:  nPoints- an integer that represents the number of course
                       points
					   
           nCredits - an integer that represents the number of credits

Returns: the calculated grade point average

***************************************************************/


double calcGPA( int nPoints, int nCredits )
{
	double GPA;
	
	GPA=double(nPoints)/nCredits; //formula for GPA
	
	return GPA;
}

/***************************************************************
Function: findglevel

Use: This function  calculates the students grade level 

Arguments: credits - an integer that represents the number of credit hours


Returns: the calculated grade level based on the number of credit hours

Notes: none
***************************************************************/

string findgLevel( int credits )  // to find the frade level
{
	if (credits>=0 && credits<=30)  //cascadinf if stateemtn sets a range of 
									//number of hours to be set for each grade level
	{
		return "Freshman";
	}
	else if (credits>=31 && credits <= 60)
	{
		return "Sophomore";
	}
	else if (credits>=61  && credits <= 90)
	{
		return "Junior";
	}
	else if (credits>=91)
	{
		return "Senior";
	}
	
}



/***************************************************************
Function: gString

Use: takes tring user input and oncerts it into string variable

Arguments: prompt- the string prompt that is entered by the user

Returns: the string variable 

***************************************************************/



string gString( string prompt )
{
	string answer1;
	
	cout<<prompt;
	cin>>answer1;    
	
	return answer1;
	

}
/***************************************************************
Function: pickPoints

Use: This function assigns a point for a certain grade level that is entered

Arguments: letter- the strong letter that user enters 

Returns: the interger that is assigned to the string letter inputted by the 
user 

***************************************************************/

int pickPoints( string letter )
{
	string grade;
	
	cout<<letter;
	cin>>grade;
	
	if (grade=="A" or grade=="a")   //assigns points to certain letter grade
	{
		return 4;
	}
	else if (grade=="B" or "b")
	{
		return 3;
	}
	else if (grade=="C" or "c")
	{
		return 2;
	}
	else if (grade=="D" or "d")
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

