//GradeKeeper Test Files
//By Josh Miller
//3-22-01 - V 0.1 - Attempts to Copy a file.
//3-27-01 - V 0.2 - Reads in data imput for grade and crdit hours.
//3-38-01 - V 0.3 - Takes in and outputs class names

//TO ADD
//The ability to open an old file and add to it for future grade reports.

//http://www.scit.wlv.ac.uk/~cm1830/oop/lec10/sld005.htm

#include<iostream.h>
#include<fstream.h>
#include <string>

int main()
{
	char classname[7];
	double hours, total_hrs=0, points, total_points=0;
	char grade;
	ofstream writer;
//	ofstream writer2;
	int num_classes, count;
	double gpa;
//	ifstream reader;
//	int filesize;

	writer.setf(ios::fixed);
	writer.setf(ios::showpoint);
	writer.precision(1);

//	writer2.setf(ios::fixed);
//	writer2.setf(ios::showpoint);
//	writer2.precision(1);

	cout<<"How many classes will you be adding to the report?\n";
	cin>>num_classes;

	//BEGIN CREATE NEW FILE
	writer.open("graderep.dat");
//	writer2.open("graderep2.dat");
//	reader.open("graderep2.dat");

//	reader>>filesize;

	writer<<"Class   CrHrs     Grade     GrdPnts\n";

	for(count=0;count<num_classes;count++)
	{
	cout<<"What is the name of class "<<count+1<<"? (6 CHAR MAX)\n";
	cin>>classname;

	cout<<"How many credit hours?\n";
	cin>>hours;

	total_hrs+=hours;

	cout<<"What grade did you receive?\n";
	cin>>grade;

	if(grade=='A'||grade=='a')
		{
		grade='A';
		points=hours*4;
		}
	else if(grade=='B'||grade=='b')
		{
		grade='B';
		points=hours*3;
		}
	else if(grade=='C'||grade=='c')
		{
		grade='C';
		points=hours*2;
		}
	else if(grade=='D'||grade=='d')
		{
		grade='D';
		points=hours*1;
		}
	else
		{
		grade='F';
		points=0;
		}

	total_points+=points;

	writer<<classname<<"   "<<hours<<"        "<<grade<<"         "<<points<<endl;
//	writer2<<classname<<"   "<<hours<<"        "<<grade<<"         "<<points<<endl;
	}
	
	gpa=total_points/total_hrs;

	writer<<"          Total Grade Points "<<total_points<<endl;
	writer<<"          Total Credit Hours "<<total_hrs<<endl;
	writer<<"          Overall Total GPA  "<<gpa<<endl;

	writer.close();

	//END CREATE NEW FILE
	
	return 0;
} 

// POSSIBLE code for opening the old file for writing
//	ifstream reader;
//	ofstream writer2;
//
//	writer2.open("graderep2.dat");
//	reader.open("graderep.dat");
//	reader>>num_lines;
//
//	cout<<num_lines;
//
//	char oldcopy[34][500];
//
//	for(vert=0;vert<num_lines;vert++)
//		{
//		for(hori=0;hori<34;hori++)
//			reader>>oldcopy[hori][vert];
//			cout<<oldcopy[hori][vert];
//			writer2<<oldcopy[hori][vert];
//		}
//	
//	reader.close();
//	writer.close();
