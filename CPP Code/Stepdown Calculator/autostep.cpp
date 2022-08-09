//A Routine for testing numbers for how many iterations they take to 'step down' to 1
//By Josh Miller 4-23-01

#include<iostream.h>
#include<fstream.h>
#include<iomanip.h>

int next_num(int n);
int RunPuzzle(int n);

void main()
{
	int num;
	int times;
	ofstream writer;
	int start;

	cout<<"Please input the starting number...\n";
	cin>>start;

//	cout<<"Commencing 100000 iterations...\n";

	writer.open("StepDown.txt");

//	writer<<"100,000 iterations starting at "<<start<<endl;
	writer<<"Special case returns...\n\n";

	for(num=start;num<10000000;num++)
	{
		times=RunPuzzle(num);
		if(times>=600)
		{
//			cout<<"***Could not be found within 600 trials***\n";
			writer<<num<<": ***Could not be found within 600 trials***\n";
		}
		else if(times>400)
		{
//			cout<<num<<": more then 400 tries: "<<times<<endl;
			writer<<num<<": more then 400 tries: "<<times<<endl;
		}
		else
		{
//			cout<<"It took "<<setw(5)<<times<<" iterations for "<<setw(10)<<num<<endl;
		}
	}

	writer.close();

	return;
}

int RunPuzzle(int n)
{
	int count=0;

	do
	{
		n=next_num(n);
		count++;

		if(count>=600)
			n=1;
	}
	while(n!=1);

	return count;
}

int next_num(int n)
{
	if(n%2==0)
		return n/2;

	return 3*n+1;
}

