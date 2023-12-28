#include<iostream>
#include<string>
#include<math.h>
using namespace std;

struct character_information // STORES INFORMATION ABOUT THE HERO OR CHARACTER
{
	char hero_choose = 0;
	string hero_name;
	string hero_class;
	int hero_experience_level = 0;
	int hero_health = 0;
	string hero_weapon;
	int hero_damage=0;
}character;

struct quest_1_boss // STORES INFORMATION ABOUT QUEST 1 BOSS WHICH IS MONSTER
{
	int health=2000;
	int level=5;
	int damage=0;
}monster;

struct quest_2_boss // STORES INFORMATION ABOUT QUEST 2 BOSS WHICH IS THE KING
{
	int health=2450;
	int level=5;
	int damage = 0;
}king;

struct quest_3_boss // STORES INFORMATION ABOUT QUEST 3 BOSS WHICH IS GUNSMITH
{
	int health= 2900;
	int damage=0;
	int level=10;
}gunsmith;

struct quest_4_boss // STORES INFORMATION ABOUT QUEST 4 BOSS WHICH IS A DRAGON
{
	int health;
	int damage=0;
	int level=15;
}dragon;

// FUNCTIONS PROTOYPES OF ALL THE FUNCTIONS USED IN THE PROGRAM
void main_menu();
void game_loop();
void quest_selection_function();
static void take_input_character(struct character_information);
void display_character(struct character_information);
void quest_1_function(char& quest_choice, struct quest_1_boss, bool &quest_1);
void quest_2_function(char& quest_choice, struct quest_2_boss, bool &quest_2); 
void quest_3_function(char& quest_choice, struct quest_3_boss, bool &quest_3); 
void quest_4_function(char& quest_choice, struct quest_4_boss, bool &quest_4); 

// INT MAIN
int main()
{
	game_loop();
	return 0;
}
void game_loop()
{
	char playAgain;
	do {
		main_menu();
		cout << "Do you want to play again? (Y/N): ";
		cin >> playAgain;
		if (tolower(playAgain) != 'y') {
			cout << "Exiting the game. Goodbye!" << endl;
			break;
		}
	} while (true);
}
//DISPLAYS THE MAIN MENU
void main_menu()
{
	int choice;
	cout << "\t\t\tMain Menu\n1.Start\n2.Exit\n";
	cout << "Enter your choice(1,2):";
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			take_input_character(character);
			quest_selection_function();
		}
		case 2:break;
		}
		if (choice != 1 && choice != 2)
			cout << "Invalid Selection, try again : ";
	} while (choice != 1 && choice!=2);
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

		if (character.hero_choose == '1')
		{
			character.hero_name = "Valkriye";
			character.hero_class = "Fighter";
			character.hero_health = 1584;
			character.hero_experience_level = 0;
			character.hero_weapon = "Axe";
			character.hero_damage = 0;
		}
		else if (character.hero_choose == '2')
		{
			character.hero_name = "Magic Archer";
			character.hero_class = "Archer";
			character.hero_health = 1584;
			character.hero_experience_level = 0;
			character.hero_weapon = "Bow And Magic Arrow";
			character.hero_damage = 0;
		}
		else if (character.hero_choose == '3')
		{
			character.hero_name = "Prince";
			character.hero_class = "Knight";
			character.hero_health = 1584;
			character.hero_experience_level = 0;
			character.hero_weapon = "Spiked Club";
			character.hero_damage = 0;
		}
		else
		{
			cout << "Invalid choice, please try again." << endl;
		}
	} while (character.hero_choose != '1' && character.hero_choose != '2' && character.hero_choose != '3');
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
	bool quest_1=false, quest_2=false, quest_3=false, quest_4=false;
	cout << "Application is an RPG Based game on which the character follows a storyline of different quests"
	<< ", in the quest hero gets to battle different monsters, defeating a boss or a monster increase the hero health, level and damage." << endl;
	cout << "\t \"You can Embark on different Quests." << endl
		<< "\t\nEach quest have different difficulty level." << endl;
	do {
		cout << "A.The forgotten Race." << endl;
		cout << "B.Army of the king." << endl; // ADD QUEST COUNTER FOR FINAL BOSS.
		cout << "C.The jury." << endl;
		cout << "D.The king of dragons." << endl;
		cout << "After completing any two quest you can fight the final boss" << endl;
		cout << "Enter the quest you want to play (e.g. A,B):";
		cin >> quest_choice;
		if (islower(quest_choice))
		{
			quest_choice = toupper(quest_choice);
		}
		switch (quest_choice)
		{

		case 'A':
		{
			cout << "\n\t The forgotten Race." << endl;
			quest_1_function(quest_choice, monster, quest_1);
			break;
		}
		case 'B':
		{
			cout << "\t Army of the king." << endl;
			quest_2_function(quest_choice, king, quest_2);
			break;
		}
		case 'C':
		{
			cout << "\t The jury." << endl;
			quest_3_function(quest_choice, gunsmith, quest_3);
			break;
		}
		case 'D':
		{
			cout << "\t The king of dragons." << endl;
			quest_4_function(quest_choice, dragon, quest_4);
			break;
		}
		//case 'E':
		//{
		//	if(quest_1==true&&quest_2==true)
		//		//FINAL BOSS FUNCTION CALL
		//}
		default: cout << "Invalid Selection, please select again : ";
		}
	} while (quest_choice != 'A' && quest_choice != 'B' && quest_choice != 'C' && quest_choice != 'D');
}

// FUNCTION OF QUEST 1
void quest_1_function(char& quest_choice, struct quest_1_boss, bool &quest_1)
{
	int try_again_choice=0;
	char hero_attack_button;
	/*string quest_1_message = " This Quest was the battle in which the forgotten race namely"
		"the race of dragons which were thought to be extinct millions of years "
		"ago but our hero was not shocked to see them as he had battles with monsters "
		"and oher creatures but this time the hero was also frightened as the dragon was "
		"enormous and had a menacing aura due to which the hero was not feeling well.Still "
		"He fights for everyone and is determined to defeat the monster.Fight Starts";*/
	display_character(character);
	srand((unsigned)time(NULL));       //This Boss Will be Easy as it is the first Quest
	do
	{
		cout << "The Battle has started" << endl;
		monster.health = 2000;
		character.hero_health = 1584;
		while (monster.health >= 1 && character.hero_health >= 1)
		{

			cout << "\n\tHero turn:" << endl;
			cout << "Press A to Attack : ";
			do
			{
				cin >> hero_attack_button;
				if (hero_attack_button == 'A' || hero_attack_button == 'a')
				{
					character.hero_damage = 90 + (rand() % 150);
					cout << "Hero Attack : "<<character.hero_damage;
				}
				if (hero_attack_button != 'A' && hero_attack_button != 'a')
					cout << "Invalid Attack Button, Press A to Attack : ";
			} while (hero_attack_button != 'A' && hero_attack_button != 'a');
			monster.health = monster.health - character.hero_damage;
			cout << "\nMonster Turn:" << endl;
			monster.damage = 59 + (rand() % 140);
			cout << "Monster Damage "<<monster.damage;
			character.hero_health = character.hero_health - monster.damage;
			continue;
		}
		if (monster.health <= 50)
		{

			cout << "\n\tYou killed The Boss with the final attack\n\tThe boss is defeated\n";
			character.hero_health = 2000;
			quest_1 = true;
			cout << "Your Hero has been promoted to level 1. healthpoints and damage is increased, expiernce point resetted;" << endl;
		}
		else if (character.hero_health < 100)
		{
			quest_1 = false;
			monster.health = 2000;
			character.hero_health = 1584;
			cout << "\nYou Died , \n\t The monster killed you.\n";
		}
		cout << "Press 1 to try again or 2 to go to quest selection menu or press 3 to main menu or press 4 to exit : ";
		do
		{
			cin >> try_again_choice;
			if (try_again_choice != 1 && try_again_choice != 2 && try_again_choice!=3 && try_again_choice!=4)
				cout << "Invalid Selection, select again : ";
		} while (try_again_choice != 1 && try_again_choice != 2 && try_again_choice!=3 && try_again_choice != 4);
		if (try_again_choice == 2)
			quest_selection_function();
		if (try_again_choice == 3)
			main_menu();
		if(try_again_choice==4)
			exit;
	} while (try_again_choice==1);
}

// FUNCTION OF QUEST 2
void quest_2_function(char &quest_choice, struct quest_2_boss, bool &quest_2 )
{
	int try_again_choice;
	char hero_attack_button;
	/*string quest_2_message = " This Quest was the battle in which the forgotten race namely"
		"the race of dragons which were thought to be extinct millions of years "
		"ago but our hero was not shocked to see them as he had battles with monsters "
		"and oher creatures but this time the hero was also frightened as the dragon was "
		"enormous and had a menacing aura due to which the hero was not feeling well.Still "
		"He fights for everyone and is determined to defeat the monster.Fight Starts";*/
	display_character(character);
	srand((unsigned)time(NULL)); 
	//This Boss Will be MEDIUM as it is the first Quest
	do
	{
		cout << "The Battle has started" << endl;
		king.health = 2450;
		character.hero_health = 2000;
		while (king.health >= 1 && character.hero_health >= 1)
		{
			cout << "\n\tHero turn:" << endl;
			cout << "Press A to Attack : ";
			do
			{
				cin >> hero_attack_button;
				if (hero_attack_button == 'A' || hero_attack_button == 'a')
				{
					character.hero_damage = 130 + (rand() % 170);
					cout << "Hero Attack : " << character.hero_damage;
				}
				if (hero_attack_button != 'A' && hero_attack_button != 'a')
					cout << "Invalid Attack Button, Press A to Attack : ";
			} while (hero_attack_button != 'A' && hero_attack_button != 'a');
			king.health = king.health - character.hero_damage;
			cout << "\nKing Attack: ";
			king.damage = 89 + (rand() % 160);
			cout << king.damage;
			character.hero_health = character.hero_health - king.damage;
			continue;
		}
		if (king.health <= 50)
		{

			cout << "\n\tYou killed The Boss with the final attack\n\tThe boss is defeated\n";
			character.hero_health = 2450;
			quest_2 = true;
			cout << "Your Hero has been promoted to level 3. healthpoints and damage is increased;" << endl;
		}
		else if (character.hero_health < 100)
		{
			quest_2 = false;
			king.health = 2450;
			character.hero_health = 2000;
			cout << "\nYou Died , \n\t The king killed you.\n";
		}
		cout << "Press 1 to try again or 2 to go to quest selection menu or press 3 to main menu or press 4 to exit : ";
		do
		{
			cin >> try_again_choice;
			if (try_again_choice != 1 && try_again_choice != 2 && try_again_choice != 3 && try_again_choice != 4)
				cout << "Invalid Selection, select again : ";
		} while (try_again_choice != 1 && try_again_choice != 2 && try_again_choice != 3 && try_again_choice != 4);
		if (try_again_choice == 2)
			quest_selection_function();
		if (try_again_choice == 3)
			main_menu();
		if (try_again_choice == 4)
			exit;
	} while (try_again_choice == 1);
}

// FUNCTION OF QUEST 3
void quest_3_function(char& quest_choice, struct quest_3_boss, bool &quest_3)
{
	int try_again_choice;
	char hero_attack_button;
	/*string quest_3_message = " This Quest was the battle in which the forgotten race namely"
		"the race of dragons which were thought to be extinct millions of years "
		"ago but our hero was not shocked to see them as he had battles with monsters "
		"and oher creatures but this time the hero was also frightened as the dragon was "
		"enormous and had a menacing aura due to which the hero was not feeling well.Still "
		"He fights for everyone and is determined to defeat the monster.Fight Starts";*/
	display_character(character);
	srand((unsigned)time(NULL));       //This Boss Will be MEDIUM as it is the first Quest
	do
	{
		cout << "The Battle has started" << endl;
		gunsmith.health = 2900;
		character.hero_health = 2450;
		while (gunsmith.health >= 1 && character.hero_health >= 1)
		{
			cout << "\n\tHero turn:" << endl;
			cout << "Press A to Attack : ";
			do
			{
				cin >> hero_attack_button;
				if (hero_attack_button == 'A' || hero_attack_button == 'a')
				{
					character.hero_damage = 170 + (rand() % 190);
					cout << "Hero Attack : " << character.hero_damage;
				}
				if (hero_attack_button != 'A' && hero_attack_button != 'a')
					cout << "Invalid Attack Button, Press A to Attack : ";
			} while (hero_attack_button != 'A' && hero_attack_button != 'a');
			gunsmith.health = gunsmith.health - character.hero_damage;
			cout << "\nShot Damage: ";
			gunsmith.damage = 119 + (rand() % 200);
			cout << gunsmith.damage;
			character.hero_health = character.hero_health - gunsmith.damage;
			continue;
		}
		if (gunsmith.health <= 50)
		{

			cout << "\n\tYou killed The Boss with the final attack\n\tThe boss is defeated\n";
			character.hero_health = 2900;
			quest_3 = true;
			cout << "Your Hero has been promoted to level 3. healthpoints and damage is increased;" << endl;
		}
		else if (character.hero_health < 100)
		{
			quest_3 = false;
			gunsmith.health = 2900;
			character.hero_health = 2450;
			cout << "\nYou Died , \n\t The monster killed you.\n";
		}
		cout << "Press 1 to try again or 2 to go to quest selection menu or press 3 to main menu or press 4 to exit : ";
		do
		{
			cin >> try_again_choice;
			if (try_again_choice != 1 && try_again_choice != 2 && try_again_choice != 3 && try_again_choice != 4)
				cout << "Invalid Selection, select again : ";
		} while (try_again_choice != 1 && try_again_choice != 2 && try_again_choice != 3 && try_again_choice != 4);
		if (try_again_choice == 2)
			quest_selection_function();
		if (try_again_choice == 3)
			main_menu();
		if (try_again_choice == 4)
			exit;
	} while (try_again_choice == 1);
}

// FUNCTION OF QUEST 4
void quest_4_function(char& quest_choice, struct quest_4_boss, bool &quest_4)
{
	int try_again_choice;
	char hero_attack_button;
	/*string quest_4_message = " This Quest was the battle in which the forgotten race namely"
		"the race of dragons which were thought to be extinct millions of years "
		"ago but our hero was not shocked to see them as he had battles with monsters "
		"and oher creatures but this time the hero was also frightened as the dragon was "
		"enormous and had a menacing aura due to which the hero was not feeling well.Still "
		"He fights for everyone and is determined to defeat the monster.Fight Starts";*/
	display_character(character);
	srand((unsigned)time(NULL));       //This Boss Will be MEDIUM as it is the first Quest
	do
	{
		cout << "The Battle has started" << endl;
		dragon.health = 3350;
		character.hero_health = 2900;
		while (dragon.health >= 1 && character.hero_health >= 1)
		{
			cout << "\n\tHero turn:" << endl;
			cout << "Press A to Attack : ";
			do
			{
				cin >> hero_attack_button;
				if (hero_attack_button == 'A' || hero_attack_button == 'a')
				{
					character.hero_damage = 210 + (rand() % 210);
					cout << "Hero Attack : " << character.hero_damage;
				}
				if (hero_attack_button != 'A' && hero_attack_button != 'a')
					cout << "Invalid Attack Button, Press A to Attack : ";
			} while (hero_attack_button != 'A' && hero_attack_button != 'a');
			dragon.health = dragon.health - character.hero_damage;
			cout << "\nDragon Attack: ";
			dragon.damage = 149 + (rand() % 240);
			cout << dragon.damage;
			character.hero_health = character.hero_health - dragon.damage;
			continue;
		}
		if (dragon.health <= 50)
		{

			cout << "\n\tYou killed The Boss with the final attack\n\tThe boss is defeated\n";
			character.hero_health = 3350;
			quest_4 = true;
			cout << "Your Hero has been promoted to level 3. healthpoints and damage is increased;" << endl;
		}
		else if (character.hero_health < 100)
		{
			quest_4 = false;
			dragon.health = 3350;
			character.hero_health = 2900;
			cout << "\nYou Died , \n\t The monster killed you.\n";
		}
		cout << "Press 1 to try again or 2 to go to quest selection menu or press 3 to main menu or press 4 to exit : ";
		do
		{
			cin >> try_again_choice;
			if (try_again_choice != 1 && try_again_choice != 2 && try_again_choice != 3 && try_again_choice != 4)
				cout << "Invalid Selection, select again : ";
		} while (try_again_choice != 1 && try_again_choice != 2 && try_again_choice != 3 && try_again_choice != 4);
		if (try_again_choice == 2)
			quest_selection_function();
		if (try_again_choice == 3)
			main_menu();
		if (try_again_choice == 4)
			exit;
	} while (try_again_choice == 1);
}
