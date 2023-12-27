#include<iostream>
#include<string>
#include<math.h>
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
	int health=2000;
	int level=5;
	int damage=0;
}monster;

struct quest_2_boss // STORES INFORMATION ABOUT QUEST 2 BOSS WHICH IS THE KING
{
	int health;
	int level=5;
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
			character.hero_damage = 0;
		}
		else if (character.hero_choose == 2)
		{
			character.hero_name = "Magic Archer";
			character.hero_class = "Archer";
			character.hero_health = 1326;
			character.hero_experience_level = 0;
			character.hero_weapon = "Bow And Magic Arrow";
			character.hero_damage = 0;
		}
		else if (character.hero_choose == 3)
		{
			character.hero_name = "Prince";
			character.hero_class = "Knight";
			character.hero_health = 1087;
			character.hero_experience_level = 0;
			character.hero_weapon = "Spiked Club";
			character.hero_damage = 0;
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
}

// THIS FUNCTION STARTS THE QUEST BASED ON USER CHOICE
void quest_selection_function()
{
	char quest_choice;
	cout << "Application is an RPG Based game on which the character follows a storyline of different quests"
	<< ", in the quest hero gets to battle different monsters, defeating a boss or a monster increase the hero health, level and damage." << endl;
	cout << "\t \"You can Embark on different Quests." << endl
		<< "\t\nEach quest have different difficulty level." << endl;
	do {
		cout << "\n A.The forgotten Race.";
		cout << "\t B.Army of the king."; // ADD QUEST COUNTER FOR FINAL BOSS.
		cout << "\t C.The jury.";
		cout << "\t D.The king of dragons.";
		cout << "\t After completing any two quest you can fight the final boss";
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
			cout << "\t The forgotten Race." << endl;
			quest_1_function(quest_choice, monster);
			break;
		}
		case 'B':
		{
			cout << "\t Army of the king." << endl;
			quest_2_function(quest_choice, king);
			break;
		}
		case 'C':
		{
			cout << "\t The jury." << endl;
			quest_3_function(quest_choice, gunsmith);
			break;
		}
		case 'D':
		{
			cout << "\t The king of dragons." << endl;
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
	string quest_1_message = " This Quest was the battle in which the forgotten race namely"
		"the race of dragons which were thought to be extinct millions of years "
		"ago but our hero was not shocked to see them as he had battles with monsters "
		"and oher creatures but this time the hero was also frightened as the dragon was "
		"enormous and had a menacing aura due to which the hero was not feeling well.Still "
		"He fights for everyone and is determined to defeat the monster.Fight Starts";
	display_character(character);  
	srand((unsigned)time(NULL));       //This Boss Will be Easy as it is the first Quest
	cout << "\n\t The battle Has Started....ATTACK\n\n";
	while (monster.health >= 1 && character.hero_health >= 1)
	{
		
		cout << "\n\tHero attack: ";
		character.hero_damage = 90 + (rand() % 150);
		cout << character.hero_damage;
		monster.health = monster.health - character.hero_damage;
		cout << "\nMonster Attack: ";
		monster.damage = 59 + (rand() % 140);
		cout << monster.damage;
		character.hero_health = character.hero_health - monster.damage;
		continue;
	}
	if (monster.health <= 50)
	{

		cout << "\n\tYou killed The Boss with the final attack\n\tThe boss is defeated";
	}
	else if (character.hero_health < 100)
	{
		cout << "\nYou Died , \n\t The monster killed you.";
	}
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
}

// FUNCTION OF QUEST 3
void quest_3_function(char& quest_choice, struct quest_3_boss)
{
	string quest_3_message = " This Quest was the battle in which the forgotten race namely"
		"the race of dragons which were thought to be extinct millions of years "
		"ago but our hero was not shocked to see them as he had battles with monsters "
		"and oher creatures but this time the hero was also frightened as the dragon was "
		"enormous and had a menacing aura due to which the hero was not feeling well.Still "
		"He fights for everyone and is determined to defeat the monster.Fight Starts";
	display_character(character);
}

// FUNCTION OF QUEST 4
void quest_4_function(char& quest_choice, struct quest_4_boss)
{
	string quest_4_message = " This Quest was the battle in which the forgotten race namely"
		"the race of dragons which were thought to be extinct millions of years "
		"ago but our hero was not shocked to see them as he had battles with monsters "
		"and oher creatures but this time the hero was also frightened as the dragon was "
		"enormous and had a menacing aura due to which the hero was not feeling well.Still "
		"He fights for everyone and is determined to defeat the monster.Fight Starts";
	display_character(character);
}
