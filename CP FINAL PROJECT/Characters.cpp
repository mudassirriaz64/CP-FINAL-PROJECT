#include<iostream>
#include<string>
using namespace std;

struct character_information // STORES INFORMATION ABOUT THE HERO OR CHARACTER
{
	int hero_choose = 0;
	string hero_name;
	string hero_class;
	int hero_experience_level = 0;
	int hero_health = 0;
	string hero_weapon;
	int hero_damage;
}character;

struct quest_1_boss // STORES INFORMATION ABOUT QUEST 1 BOSS WHICH IS MONSTER
{
	int health;
	int damage;
	int level;
}monster;

struct quest_2_boss // STORES INFORMATION ABOUT QUEST 2 BOSS WHICH IS THE KING
{
	int health;
	int damage;
	int level;
}king;

struct quest_3_boss // STORES INFORMATION ABOUT QUEST 3 BOSS WHICH IS GUNSMITH
{
	int health;
	int damage;
	int level;
}gunsmith;

struct quest_4_boss // STORES INFORMATION ABOUT QUEST 4 BOSS WHICH IS A DRAGON
{
	int health;
	int damage;
	int level;
}dragon;

// FUNCTIONS PROTOYPES OF ALL THE FUNCTIONS USED IN THE PROGRAM
void quest_selection_function();
static void take_input_character(struct character_information);
void display_character(struct character_information);
void quest_1_function(char& quest_choice, struct quest_1_boss);
void quest_2_function(char& quest_choice, struct quest_2_boss); 
void quest_3_function(char& quest_choice, struct quest_3_boss); 
void quest_4_function(char& quest_choice, struct quest_4_boss); 

// INT MAIN
int main()
{
	cout << "\t \t \t welcome to the game" << endl;
	take_input_character(character);
	quest_selection_function();
	return 0;
}

// THIS FUNCTION SELECTS THE HERO AND OTHER INFORMATION RELATED TO HERO
static void take_input_character(struct character_information)
{
	cout << "You have to select hero from one of the following hero,Each of the character has its own weapone and style)" << endl;
	cout << "1. Valkriye " << endl;
	cout << "Fights with an axe around her,Tough melee Fighter and deals area damage around her " << endl;// Enter description of valkriye
	cout << "2. Magic Archer" << endl;
	cout << "Not quite a Wizard, nor an Archer - he shoots a magic arrow that passes through and damages all the enemies in its path" << endl; //Enter description of gaint
	cout << "3. Prince " << endl;
	cout << "The prince rides an horse and deals area damage and lets his spiked club do the talking for him" << endl;// Enter desciption of Hog Rider
	do {
		cout << "Select your character(e,g 1,2,3) : ";
		cin >> character.hero_choose;
		if (character.hero_choose == 1)
		{
			character.hero_name = "Valkriye";
			character.hero_class = "Fighter";
			character.hero_health = 1584;
			character.hero_experience_level = 0;
			character.hero_weapon = "Axe";
			character.hero_damage = 221;
		}
		else if (character.hero_choose == 2)
		{
			character.hero_name = "Magic Archer";
			character.hero_class = "Archer";
			character.hero_health = 1326;
			character.hero_experience_level = 0;
			character.hero_weapon = "Bow And Magic Arrow";
			character.hero_damage = 134;
		}
		else if (character.hero_choose == 3)
		{
			character.hero_name = "Prince";
			character.hero_class = "Knight";
			character.hero_health = 1087;
			character.hero_experience_level = 0;
			character.hero_weapon = "Spiked Club";
			character.hero_damage = 170;
		}
		else
		{
			cout << "Invalid choice, please try again." << endl;
		}
	} while (character.hero_choose != 1 && character.hero_choose != 2 && character.hero_choose != 3);
}

void display_character(struct character_information) // DISPLAY HERO OR CHARACTER INFORMATION
{
	cout << "Hero Name : " << character.hero_name << endl;
	cout << "Class : " << character.hero_class << endl;
	cout << "Health : " << character.hero_health << endl;
	cout << "Experience Level : " << character.hero_experience_level << endl;
	cout << "Weapon : " << character.hero_weapon << endl;
	cout << "Damage : " << character.hero_damage << endl;
}

// THIS FUNCTION STARTS THE QUEST BASED ON USER CHOICE
void quest_selection_function()
{
	char quest_choice;
	cout << "\t \"You can Embark on different Quests.\"\n" << endl
		<< "\t\nEach quest have three types of difficulty level\n";
	cout << "\nYou can select the quest and then the difficulty level on which you want to play.\n";
	do {
		cout << "\n A.The forgotten Race.";
		cout << "\t B.Army of the king.";
		cout << "\t C.The jury.";
		cout << "\t D.The king of dragons.";
		cout << "\nEnter the quest you want to play (e.g. A,B): ";
		cin >> quest_choice;
		if (islower(quest_choice))
		{
			quest_choice = toupper(quest_choice);
		}
		switch (quest_choice)
		{

		case 'A':
		{
			cout << "\t The forgotten Race.";
			quest_1_function(quest_choice, monster);
			break;
		}
		case 'B':
		{
			cout << "\t Army of the king.";
			quest_2_function(quest_choice, king);
			break;
		}
		case 'C':
		{
			cout << "\t The jury.";
			quest_3_function(quest_choice, gunsmith);
			break;
		}
		case 'D':
		{
			cout << "\t The king of dragons.";
			quest_4_function(quest_choice, dragon);
			break;
		}
		default: cout << "Invalid Selection, please select again : ";
		}
	} while (quest_choice != 'A' && quest_choice != 'B' && quest_choice != 'C' && quest_choice != 'D');
}

// FUNCTION OF QUEST 1
void quest_1_function(char& quest_choice, struct quest_1_boss)
{
	int difficulty;
	string quest_1_message = " This Quest was the battle in which the forgotten race namely"
		"the race of dragons which were thought to be extinct millions of years "
		"ago but our hero was not shocked to see them as he had battles with monsters "
		"and oher creatures but this time the hero was also frightened as the dragon was "
		"enormous and had a menacing aura due to which the hero was not feeling well.Still "
		"He fights for everyone and is determined to defeat the monster.Fight Starts";
	display_character(character);
	cout << "\nSelect The difficulty on which you want to play it.\n(1).Easy\n(2).Medium\n(3).Hard\nchoose e.g(1,2):";
	do
	{
		cin >> difficulty;
		if (difficulty == 1)
		{
			cout << "\nYour difficulty level is Easy.";
			cout << "\nThe quest will Start soon. ";
			cout << "\n\n Attackrand()";
		}
		else if (difficulty == 2)
		{
			cout << "\nYour difficulty level is Medium.";
		}
		else if (difficulty == 3)
		{
			cout << "\nYour difficulty level is Hard.";
		}
		else
		{
			cout << "Invalid Selection, please select again";
		}

	} while (difficulty != 1 && difficulty != 2 && difficulty != 3);
}

// FUNCTION OF QUEST 2
void quest_2_function(char& quest_choice, struct quest_2_boss)
{
	int difficulty;
	string quest_2_message = " This Quest was the battle in which the forgotten race namely"
		"the race of dragons which were thought to be extinct millions of years "
		"ago but our hero was not shocked to see them as he had battles with monsters "
		"and oher creatures but this time the hero was also frightened as the dragon was "
		"enormous and had a menacing aura due to which the hero was not feeling well.Still "
		"He fights for everyone and is determined to defeat the monster.Fight Starts";
	display_character(character);
	cout << "\nSelect The difficulty on which you want to play it.\n(1).Easy\n(2).Medium\n(3).Hard\nchoose e.g(1,2):";
	do
	{
		cin >> difficulty;
		if (difficulty == 1)
		{
			cout << "\nYour difficulty level is Easy.";
			cout << "\nThe quest will Start soon. ";
			cout << "\n\n Attackrand()";
		}
		else if (difficulty == 2)
		{
			cout << "\nYour difficulty level is Medium.";
		}
		else if (difficulty == 3)
		{
			cout << "\nYour difficulty level is Hard.";
		}
		else
		{
			cout << "Invalid Selection, please select again";
		}

	} while (difficulty != 1 && difficulty != 2 && difficulty != 3);
}

// FUNCTION OF QUEST 3
void quest_3_function(char& quest_choice, struct quest_3_boss)
{
	int difficulty;
	string quest_3_message = " This Quest was the battle in which the forgotten race namely"
		"the race of dragons which were thought to be extinct millions of years "
		"ago but our hero was not shocked to see them as he had battles with monsters "
		"and oher creatures but this time the hero was also frightened as the dragon was "
		"enormous and had a menacing aura due to which the hero was not feeling well.Still "
		"He fights for everyone and is determined to defeat the monster.Fight Starts";
	display_character(character);
	cout << "\nSelect The difficulty on which you want to play it.\n(1).Easy\n(2).Medium\n(3).Hard\nchoose e.g(1,2):";
	do
	{
		cin >> difficulty;
		if (difficulty == 1)
		{
			cout << "\nYour difficulty level is Easy.";
			cout << "\nThe quest will Start soon. ";
			cout << "\n\n Attackrand()";
		}
		else if (difficulty == 2)
		{
			cout << "\nYour difficulty level is Medium.";
		}
		else if (difficulty == 3)
		{
			cout << "\nYour difficulty level is Hard.";
		}
		else
		{
			cout << "Invalid Selection, please select again";
		}

	} while (difficulty!=1 && difficulty!=2 && difficulty!=3);
	
}

// FUNCTION OF QUEST 4
void quest_4_function(char& quest_choice, struct quest_4_boss)
{
	int difficulty;
	string quest_4_message = " This Quest was the battle in which the forgotten race namely"
		"the race of dragons which were thought to be extinct millions of years "
		"ago but our hero was not shocked to see them as he had battles with monsters "
		"and oher creatures but this time the hero was also frightened as the dragon was "
		"enormous and had a menacing aura due to which the hero was not feeling well.Still "
		"He fights for everyone and is determined to defeat the monster.Fight Starts";
	display_character(character);
	cout << "\nSelect The difficulty on which you want to play it.\n(1).Easy\n(2).Medium\n(3).Hard\nchoose e.g(1,2):";
	do
	{
		cin >> difficulty;
		if (difficulty == 1)
		{
			cout << "\nYour difficulty level is Easy.";
			cout << "\nThe quest will Start soon. ";
			cout << "\n\n Attackrand()";
		}
		else if (difficulty == 2)
		{
			cout << "\nYour difficulty level is Medium.";
		}
		else if (difficulty == 3)
		{
			cout << "\nYour difficulty level is Hard.";
		}
		else
		{
			cout << "Invalid Selection, please select again";
		}

	} while (difficulty != 1 && difficulty != 2 && difficulty != 3);
}
