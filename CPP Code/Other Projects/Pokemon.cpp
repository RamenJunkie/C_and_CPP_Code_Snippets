//Pokemon Organizer
//By Josh Miller 4/9/01

#include<iostream.h>

double total_collection_value(double mons[]);
int mons_missing(double mons[]);
void initialize_mons(double mons[]);
void change_mon(double mons[]);

int main()
{
	double mons[151];
	int missing;
	char choice;
	int trigger=0;

	initialize_mons(mons);

	do
	{
	cout<<"\nWhat would you like to do?\n(M)issing Pokemon\n";
	cout<<"(A)dd a Pokemon\n(Q)uit\n";
	cin>>choice;
		
	if((choice=='M')||(choice=='m'))
		{
		missing=mons_missing(mons);
		cout<<"\nThere are "<<missing<<" Pokemon missing.\n";
		}
	else if((choice=='A')||(choice=='a'))
		change_mon(mons);
	else if((choice=='Q')||(choice=='q'))
		trigger=1;
	else
		cout<<"\nINVALID ENTRY\n";
	}
	while(trigger==0);

	return 0;
}

int mons_missing(double mons[])
{
	int total=0;
	int count;

	for(count=0;count<151;count++)
		{
		if(mons[count]==0)
			total++;
		}

	return total;
}

void initialize_mons(double mons[])
{
	int count;

	for(count=0;count<151;count++)
		mons[count]=0;

	return;
}

void change_mon(double mons[])
{
	int mon_num;
	int which;

	cout<<"\nWhich set would you like to check?\n";
	cout<<"1) 1-75\n2)76-150\n";
	cin>>which;

	if(which==1)
	{
	cout<<"1 Bulbasaur    16 Pidgey      31 Nidoqueen   46 Paras       61 Polywhirl\n";
	cout<<"2 Ivysaur      17 Pidgeotto   32 Niodoran M  47 Parasect    62 Poliwrath\n";
	cout<<"3 Venusaur     18 Pidgeot     33 Nidorino    48 Venonat     63 Abra\n";
	cout<<"4 Charmander   19 Rattata     34 Nidoking    49 Venomoth    64 Kadabra\n";
	cout<<"5 Charmeleon   20 Raticate    35 Clefairy    50 Diglett     65 Alakazam\n";
	cout<<"6 Charizard    21 Spearow     36 Clefable    51 Dugtrio     66 Machop\n";
	cout<<"7 Squirtle     22 Fearow      37 Vulpix      52 Meowth      67 Machoke\n";
	cout<<"8 Wartortle    23 Ekans       38 Ninetails   53 Persian     68 Machamp\n";
	cout<<"9 Blastoise    24 Arbok       39 Jigglypuff  54 Psyduck     69 Bellsprout\n";
	cout<<"10 Caterpie    25 Pikachu     40 Wigglytuff  55 Golduck     70 Weepinbell\n";
	cout<<"11 Metapod     26 Raichu      41 Zubat       56 Mankey      71 Victreebel\n";
	cout<<"12 Butterfree  27 Sandshrew   42 Golbat      57 Primeape    72 Tentacool\n";
	cout<<"13 Weedle      28 Sandslash   43 Oddish      58 Growlithe   73 Tentacruel\n";
	cout<<"14 Kakuna      29 Niodoran F  44 Gloom       59 Arcanine    74 Geodude\n";
	cout<<"15 Beedrill    30 Niodorina   45 Vileplume   60 Polywag     75 Graveler\n";
	}
	else
	{
	cout<<"76 Golem       91 Cloyster    106 Hitmonlee  121 Starmie    136 Flareon\n";
	cout<<"77 Ponyta      92 Gastly      107 Hitmonchan 122 Mr.Mime    137 Porygon\n";
	cout<<"78 Rapidish    93 Haunter     108 Lickitung  123 Scythr     138 Omanyte\n";
	cout<<"79 Slowpoke    94 Gengar      109 Koffing    124 Jinx       139 Omstar\n";
	cout<<"80 Slowbro     95 Onix        110 Weezing    125 Electabuzz 140 Kabuto\n";
	cout<<"81 Magnemite   96 Drowzee     111 Rhyhorn    126 Magmar     141 Kobutops\n";
	cout<<"82 Magneton    97 Hypno       112 Rhydon     127 Pinsir     142 Aerodactyl\n";
    cout<<"83 Farfetch'd  98 Krabby      113 Chancey    128 Tauros     143 Snorlax\n";
	cout<<"84 Doduo       99 Kingler     114 Tangela    129 Magikarp   144 Articuno\n";
	cout<<"85 Dodrio      100 Voltorb    115 Kangaskhan 130 Gyarados   145 Zapdos\n";
	cout<<"86 Seel        101 Electrode  116 Horsea     131 Lapras     146 Moltress\n";
	cout<<"87 Dewong      102 Exeggcute  117 Seadra     132 Ditto      147 Dratini\n";
	cout<<"88 Grimer      103 Exeggutor  118 Goldeen    133 Eevee      148 Dragonair\n";
	cout<<"89 Muk         104 Cubone     119 Seaking    134 Vaporeon   149 Dragonite\n";
	cout<<"90 Shelder     105 Marowak    120 Staryu     135 Jolteon    150 Mewtwo\n";
	}

	cout<<"\nWhich Pokemon would you like to add?(1-151)\n";
	cin>>mon_num;


	if((mon_num>=1)&&(mon_num<=151))
		{
		mons[mon_num-1]=1;
		}
	else
		cout<<"\nINVALID ENRTY\n";

	return;
}