//Pearl Diver Game ver. 1.48
//By Josh Miller 
//2-22-01 - started Programming 
//          added pearl_check
//          added movement
//          added general main() code using movement and pearl_check
//2-26-01 - added stinger_check
//2-28-01 - debugging of stinger_check
//        - added stats
//        - added game_over
//3-5-01  - reworked the function stats for ascii visual interface
//        - added instructions
//3-6-01  - added sea_current
//        - added quest
//        - reworked visuals to make it slightly less boring.
//        - debugging
//        - added comments
//3-8-01  - minor last minute fixes.
// END PERAL DIVER 1.38
//3-13-01 - altered variables and probabilities to decrease difficulty


#include<iostream.h>
#include<stdlib.h>
#include<time.h>

void pearl_check(int &pearls);
void movement(int &depth);
void stinger_check(int &stings, int &oxygen, int depth);
void stats(int depth, int oxygen, int pearls, int stings);
void game_over(int stings, int pearls, int oxygen);
void instructions(char inst);
void sea_current(int &depth);
char quest();


int main()
{
	int pearls=0, depth=0;
	char direct='Q', inst, answer;
	int stings=10, oxygen=15;

//pearls=number of pearls, depth=player's depth, a multiple of 50
//direct=the direction input, inst=yes or no for instructions
//answer=yes or no for the Prince's request, stings=number of stings
//remaining, oxygen=amount of oxygen left.

//The following generates a title screen.
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"                   Welcome to PEARL DIVER\n";
	cout<<"                 The game of deep sea diving.\n";
	cout<<"                 Programming by Josh Miller\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"Would you like instructions? (Y/N)\n";
	cin>>inst;

//Checks if the player wants instructions, then runs quest, which adds
//a bit of character interaction by giving the player the option
//to not accept the quest.  The interation is mostly an excuse to
//pause the text of quest.  The test is outside the loop for the sake
//of ending the program if they say no.
	if((inst=='Y')||(inst=='y'))
		instructions(inst);

	answer=quest();
	if((answer=='N')||(answer=='n'))
		{
		cout<<"\nI'm sorry to hear that.  My wife will surely be";
		cout<<" dissapointed\n";
		return 0;
		}
	else
		{
		cout<<"\nThank you good sir.  I will have a guide take you";
		cout<<"to the Silver Sea immidiately!\n\n";
		}
//This is the main game section.  Anything useful actually takes place
//within this dowhile loop.
	do
	{
	stats(depth, oxygen, pearls, stings);

	movement(depth);

	if(depth==200)
		pearl_check(pearls);

	if(depth>0)
		sea_current(depth);

	if(depth==0)
		{
		cout << "\nFresh air fills your lungs as you break the water at the surface.\n";
		oxygen=15;
		}
	else 
	{
	  cout << "\nYour oxygen level has been depleated by one point.\n";
	  oxygen--;
	}

	stinger_check(stings, oxygen, depth);

	}
	while((pearls<5)&&(oxygen>0)&&(stings>0));

	game_over(stings, pearls, oxygen);

//This check is simply for users who run the program
//outside of the compiler so the end game text doesn't
//fly by too fast to read.

	cout<<"Done? (Y/N)";
	cin>>inst;

	return 0;
}

void pearl_check(int &pearls)
{
//This function checks for pearls when at the bottom of the sea.

srand(time(0));

	cout << "\nHaving reached the bottom, you search the sand for a pearl.";

if(7<=(rand()%10))
	{
   pearls++;
   cout << "\nFourtune smiles upon thee... ";
   cout << "Thou hast found a pearl!  You have " << pearls << " pearls.";
	}
else
	{
    cout<<"\nThe search for a pearl came up empty, try again in a new location.";
	}

return;
}

void movement(int &depth)
{
//This function is used to move the character within the game field area.

	int on_off=0;
	char direct;

	do
	{

	cout << "\nYour current depth is "<<depth<<" which direction would";
	cout<<" you like to swim?";
	cout << "\n (D)own  (U)p  (E)ast  (W)est.\n";
	cin >> direct;

	if(((direct=='U')||(direct=='u'))&&(depth!=0))
		{
		cout << "\nThe world becomes brighter as the surface approaches.";
		depth-=50;
		on_off=1;
		}
	else if(((direct=='U')||(direct=='u'))&&(depth==0))
		{
		cout << "\nYou are allready at the surface, try as you will, ";
		cout<<"you are unable to fly.";
		on_off=0;
		}
	else if(((direct=='D')||(direct=='d'))&&(depth!=200))
		{
		cout << "\nDarkness envolopes you as you head deeper into the depths.";
		depth+=50;
		on_off=1;
		}
	else if(((direct=='D')||(direct=='d'))&&(depth==200))
		{
		cout << "\nSorry, you are allready at the bottom.";
		on_off=0;
		}
	else if((direct=='E')||(direct=='e'))
		{
		cout << "\nYou swim to the East";
		on_off=1;
		}
	else if((direct=='W')||(direct=='w'))
		{
		cout << "\nYou swim to the West";
		on_off=1;
		}
	else 
		{
		cout << "\nInvalid Direction, please choose again.";
		on_off=0;
		}
	}
	while(on_off==0);

	return;
}

void stinger_check(int &stings, int &oxygen, int depth)
{
//This function checks for Stinger Fish each round and responds appropriately.

	srand(time(0));

	int randm;

	randm=rand()%100;
	
	if(randm<=(depth*.1))
	{
	cout << "\nSuddenly, a Stinger Fish attacks you from behind!\n";
	oxygen--;
	stings--;
	cout << "The diving suit had been weakended and\n";
	cout << "one unit of oxygen has been lost in the struggle.\n";
	}
	else
		{
	   cout<<"\nLuckily, you have managed to avoid encountering any Stinger\n";
	   cout<<"Fish this round\n";
		}

	return;
}

void stats(int depth, int oxygen, int pearls, int stings)
{
//The following lines of code are used to give a visual
//representation of the player's stats.  For the sake 
//of simplicity, the end result (without all the ifs 
//and elses and copping for printing clarity)looks 
//something like this only a bit larger.
//Depth                THE SILVER SEA                    *=You
// 0 +~~~~~~~~~~~~~~~~~~~~~~~~*~~~~~~~~~~~~~~~~~~~~~~~~+--------+
//   |        >->                                      | STINGS |
//   |      >->                             <-<        |  LEFT  |
// 50+                                   <-<           |    5   |
//   |                                        <-<      |        |
//   |                                                 +--------+
//100+                                                 | PEARLS |
//   |               >->                               |  FOUND |
//   |     %    %                                      |    0   |
//150+    <    <                                       +--------+
//   |  %>< % / %                                      | O2 LEFT|
//   |     < /                                         |   10   |
//200+______|_____*___O__*______________**____*___*____+________+

cout<<"Depth                THE SILVER SEA                    *=You\n";

if(depth==0)
	{
	cout<<" 0 +~~~~~~~~~~~~~~~~~~~~~~~~*~~~~~~~~~~~~~~~~~~~~~~~~+";
	cout<<"--------+\n";
	}
else
	{
	cout<<" 0 +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+";
	cout<<"--------+\n";
	}

cout<<"   |        >->                                      |";
cout<<" STINGS |\n";
cout<<"   |      >->                             <-<        |";
cout<<"  LEFT  |\n";

if((depth==50)&&(stings<10))
	{
	cout<<" 50+                        *          <-<           |";
	cout<<"    "<< stings<<"   |\n";
	}
else if((depth==50)&&(stings>=10))
	{
	cout<<" 50+                        *          <-<           |";
	cout<<"   "<< stings<<"   |\n";
	}
else if(stings<10)
	{
	cout<<" 50+                                   <-<           |";
	cout<<"    "<< stings<<"   |\n";
	}
else
	{
	cout<<" 50+                                   <-<           |";
	cout<<"   "<< stings<<"   |\n";
	}


cout<<"   |                                        <-<      |";
cout<<"        |\n";
cout<<"   |                                                 +";
cout<<"--------+\n";

if(depth==100)
	{
	cout<<"100+                        *                        |";
	cout<<" PEARLS |\n";
	}
else
	{
	cout<<"100+                                                 |";
	cout<<" PEARLS |\n";
	}

cout<<"   |               >->                               |";
cout<<"  FOUND |\n";
cout<<"   |     %    %                                      |";
cout<<"    "<< pearls<<"   |\n";

if(depth==150)
	{
	cout<<"150+    <    <              *                        +";
	cout<<"--------+\n";
	}
else
	{
	cout<<"150+    <    <                                       +";
	cout<<"--------+\n";
	}

cout<<"   |  %>< % / %                                      | O2";
cout<<" LEFT|\n";

if(oxygen>=10)
	{
	cout<<"   |     < /                                         |";
	cout<<"   "<<oxygen<<"   |\n";
	}
else
	{
	cout<<"   |     < /                                         |";
	cout<<"    "<< oxygen<<"   |\n";
	}

if(depth==200)
	{
	cout<<"200+______|_____@___O__@____*_________@@____@___@____+";
	cout<<"________+\n";
	}
else
	{
	cout<<"200+______|_____@___O__@______________@@____@___@____+";
	cout<<"________+\n";
	}

	return;
}

void game_over(int stings, int pearls, int oxygen)
{
//This function is used to generate the proper end game message to the user
//depending on the way they have been killed or if they complete the game
//by collecting 5 pearls.
	if(oxygen<=0)
		{
		cout << "\nYou have run out of oxygen and have drowned!!";
		cout << "\nMaybe next time you should return to the surface sooner.";
		cout << "\n\n                      GAME OVER\n\n";
		}
	
	if(stings<=0)
		{
		cout << "\nYou have been killed by Stinger Fish!!";
		cout << "\nThey feast ravenously upon your remians.";
		cout << "\n\n                      GAME OVER\n\n";
		}
	
	if(pearls==5)
		{
		cout << "\nCongratulations!";
		cout << "\nYou have found the five pearls the Prince needed, he is very";
		cout << "\ngrateful to you and rewards you well as promised. Your success";
		cout << "\nbrings you even more fame and you continue on to even more";
		cout << "\nwealth and glory.";
		cout << "\n                             FIN~\n\n";
		}

}

void instructions(char inst)
{
//This function generates the instructions if the layer so wishes to see them
//The question att he end actually has no effect and is simply used to pause
//The instructions so the user can read them.

cout<<"OBJECT\n";
cout<<"  The object of the game is to dive to the bottom of the sea and\n";
cout<<"retreive five pearls.\n";
cout<<"\n";
cout<<"THREATS\n";
cout<<"  There are two threats to your character in the game.  First is\n";
cout<<"running out of oxegen.  Being a mortal, your character is unable to\n";
cout<<"breathe while underwater and will drown if you remain under water\n";
cout<<"for too long.  Return to the surface to refill your air.\n";
cout<<"  The second threat is that of the poisonous Stinger Fish which\n";
cout<<"live in the sea.  They will attack anything they come across with\n";
cout<<"thier stingers.  Your diving suit can withstand up to 5 stings and\n";
cout<<"each time you are attacked you will loose 1 to your suit strength\n";
cout<<"and 1 to your oxegen.\n";
cout<<"HOW TO PLAY\n";
cout<<"  Guide your character to the bottom of the sea and search for\n";
cout<<"pearls on the bottom.  Pearls are ONLY found on the bottom of the\n";
cout<<"sea.  Be sure to leave enough oxegen to return to the surface.\n";
cout<<"Done? (Y/N)";
cin>>inst;
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\n";
}

void sea_current(int &depth)
{
//This function tests for sea currents.
	srand(time(0));

	int randm;
	
	randm=rand()%10;

	if(randm==7)
		{
		cout<<"\nThe current of the sea catches you and pulls you towards the";
		cout<<" surface.";
		depth-=50;
		}

	return;
}

char quest()
{
//The following is used to explain to the user what is going on in
//the game and to give some story.
	char answer;

cout<<"\n";
cout<<"\n";
cout<<"  Greetings traveler, it has come to my            SSSSS ~~~~~\n";
cout<<"attention that you are a deep sea diver.         SSSSSSSS~~\n";
cout<<"You see I, Prince Cardiff am in need of         SSSSSSS~~S   SSS\n";
cout<<"your service.  My dearly beloved wife,         SSSSS~~SSSSSSS\n";
cout<<"Lady Gabrielle, has been wishing to have      SSSSSSSSSSSSSSS\n";
cout<<"a string of pearls, and I am in dire need    SSSSSSSSSSSS~\n";
cout<<"of some pearls to give.  I wish ask you    SSSSSSSS@@~~~~~\n";
cout<<"to retrieve for me 5 of the magnificent         @@@//~~~~~~~\n";
cout<<"pearls found at the bottom of the Silver     S@@/////~~~S~~~~~\n";
cout<<"Sea. I can pay you well of course if you    SS@@SSSSS~~SSS~~S~\n";
cout<<"are successful, as I'm sure you will be    S@@SS@SSSS~~SSS~~SS~~\n";
cout<<"given your fame as a diver.  I realize     @@@@@@@@@@SSSSSSSSS\n";
cout<<"there are many perils lying deep within    ///@@SSS@////@SSSSSSS\n";
cout<<"the Silver Sea but I'm sure you are more   ///@@SSS@////S@SSSSSS\n";
cout<<"than capable to deal with them.  I'm sure   S@@@@SS@@@@@SS@@SSSS\n";
cout<<"you have dealt with sea currents before as  S@@@@SSSSSSSS@@@@SSS\n";
cout<<"they must be in every body of water, and    S@@@@@@~~~~~~@@@@SSS\n";
cout<<"surely there are beasts more foul than the  SSSSS@@SSSSSS@SSSSSS\n";
cout<<"Stinger Fish living other seas.  So I ask       SSSSSSSS     SS\n";
cout<<"you, will you embark on this mission for\n";
cout<<"me?  My dear wife would appreciate it. (Y/N)  PRINCE CARDIFF\n";                                   
cin>>answer;

return answer;
}

