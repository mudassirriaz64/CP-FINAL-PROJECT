#include<iostream>
#include<string>
#include<math.h>
#include<cstdlib>
using namespace std;

struct character_information // STORES INFORMATION ABOUT THE HERO OR CHARACTER
{
	char hero_choose = 0;
	string hero_name;
	string hero_class;
	int hero_experience_level = 0;
	int hero_health = 0;
	string hero_weapon;
	int hero_damage = 0;
}character;

struct quest_1_boss // STORES INFORMATION ABOUT QUEST 1 BOSS WHICH IS MONSTER
{
	int health = 2000;
	int level = 5;
	int damage = 0;
}monster;

struct quest_2_boss // STORES INFORMATION ABOUT QUEST 2 BOSS WHICH IS THE KING
{
	int health = 2450;
	int level = 5;
	int damage = 0;
}king;

struct quest_3_boss // STORES INFORMATION ABOUT QUEST 3 BOSS WHICH IS GUNSMITH
{
	int health = 2900;
	int damage = 0;
	int level = 10;
}gunsmith;

struct quest_4_boss // STORES INFORMATION ABOUT QUEST 4 BOSS WHICH IS A DRAGON
{
	int health=3350;
	int damage = 0;
	int level = 15;
}dragon;

struct final_boss
{
	int health = 4000;
	int damage = 0;
	int level = 20;
}the_witch;
// FUNCTIONS PROTOYPES OF ALL THE FUNCTIONS USED IN THE PROGRAM
void main_menu();
void game_loop();
void quest_selection_function(struct quest_1_boss,struct quest_2_boss, struct quest_3_boss,struct quest_4_boss, struct final_boss);
static void take_input_character(struct character_information);
void display_character(struct character_information);
void quest_1_function(struct quest_1_boss);
void quest_2_function(struct quest_2_boss);
void quest_3_function(struct quest_3_boss);
void quest_4_function(struct quest_4_boss);
void final_boss(struct final_boss);
// INT MAIN
int main()
{
	game_loop();
	return 0;
}
void game_loop()
{
	char playAgain;
	do 
	{
		main_menu();
		cout << "Do you want to play again? (Y/N): ";
		cin >> playAgain;
		if (tolower(playAgain) != 'y') 
		{
			system("cls");
			cout << "Exiting the game. Goodbye!" << endl;
			break;
		}
	} while (true);
}
//DISPLAYS THE MAIN MENU
void main_menu()
{
	char choice;
	cout << "\t\t\tMain Menu\n1.Start\n2.Exit\n";
	cout << "Enter your choice(1,2):";
	do
	{
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			system("cls");
			take_input_character(character);
			system("cls");
			quest_selection_function(monster , king , gunsmith, dragon, the_witch);
			break;
		}
		case '2':break;
		}
		if (choice != '1' && choice != '2')
			cout << "Invalid Selection, try again : ";
	} while (choice != '1' && choice != '2');
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
void quest_selection_function(struct quest_1_boss, struct quest_2_boss, struct quest_3_boss, struct quest_4_boss, struct final_boss)
{
	char quest_choice;
	
	cout << "\t \"You can Embark on different Quests." << endl
		<< "\t\nEach quest have different difficulty level." << endl;
	cout << "A.The forgotten Race." << endl;
	cout << "B.Army of the king." << endl; 
	cout << "C.The jury." << endl;
	cout << "D.The king of dragons." << endl;
	cout << "E.The Final Battle with the Witch" << endl;
	cout << "NOTE : If you select a quest you have already completed, your health points and damage will be calibrated" << endl;
	cout << "Enter the quest you want to play(you can only select the unlocked quests) (e.g. A,B):";
	do {
		cin >> quest_choice;
		if (islower(quest_choice))
		{
			quest_choice = toupper(quest_choice);
		}
		switch (quest_choice)
		{

		case 'A':
		{
			system("cls");
			cout << "\n\t The forgotten Race." << endl;
			quest_1_function(monster);
			break;
			
		}
		case 'B':
		{
			if (monster.health < 50)
			{
				system("cls");
				cout << "\t Army of the king." << endl;
				quest_2_function(king);
				break;
			}
			else
			{

				cout << "Complete quest 1 to unlock quest 2, select quest 1 again : ";
				do
				{
					cin >> quest_choice;
					if (islower(quest_choice))
					{
						quest_choice = toupper(quest_choice);
					}
					if (quest_choice == 'A')
					{
						system("cls");
						cout << "\n\t The forgotten Race." << endl;
						quest_1_function(monster);
					}
					else 
					cout << "Invalid Option, try again : ";
				} while (quest_choice != 'A' && quest_choice!='a');

			}
		}
		case 'C':
		{
			if (monster.health < 50 && king.health < 50)
			{
				system("cls");
				cout << "\t The jury." << endl;
				quest_3_function(gunsmith);
				break;
			}
			else
			{
				cout << "Complete quest 1 and 2 to unlock quest 3, try again : ";
				do
				{
					cin >> quest_choice;
					if (islower(quest_choice))
					{
						quest_choice = toupper(quest_choice);
					}
					if (quest_choice == 'B')
					{
						if (monster.health < 10)
						{
							system("cls");
							cout << "\t Army of the king." << endl;
							quest_2_function(king);
						}
						else
						{
							cout << "Quest 2 is not unlocked, complete quest 1 to play quest 2. Select quest : ";
							do
							{
								cin >> quest_choice;
								if (islower(quest_choice))
								{
									quest_choice = toupper(quest_choice);
								}
								if (quest_choice != 'A')
									cout << "Invalid Selection, try again : ";
								else if (quest_choice == 'A')
								{
									system("cls");
									cout << "The Forgotten Race" << endl;
									quest_1_function(monster);
								}
							} while (quest_choice!='a'&&quest_choice!='A');
						}
						
					}
					else if (quest_choice == 'A')
					{
						system("cls");
						cout << "\n\t The forgotten Race." << endl;
						quest_1_function(monster);
					}
					else
						cout << "Invalid Option, try again : ";
				} while (quest_choice != 'A'&&quest_choice != 'C');
			}
		}
		case 'D':
		{
			if (monster.health < 50 && king.health < 50 && gunsmith.health<50)
			{
				system("cls");
				cout << "\t The DRAGON KING." << endl;
				quest_4_function(dragon);
				break;
			}
			else
			{
				cout << "Complete quest 1,2 and 3 to unlock quest 4, try again : ";
				do
				{
					cin >> quest_choice;
					if (islower(quest_choice))
					{
						quest_choice = toupper(quest_choice);
					}
					if (quest_choice == 'B')
					{
						if (monster.health < 10)
						{
							system("cls");
							cout << "\t Army of the king." << endl;
							quest_2_function(king);
						}
						else
						{
							cout << "Quest 2 is not unlocked, complete quest 1 to play quest 2. Select quest : ";
							do
							{
								cin >> quest_choice;
								if (islower(quest_choice))
								{
									quest_choice = toupper(quest_choice);
								}
								if (quest_choice != 'A')
									cout << "Invalid Selection, try again : ";
								else if (quest_choice == 'A')
								{
									system("cls");
									cout << "The Forgotten Race" << endl;
									quest_1_function(monster);
								}
							} while (quest_choice != 'a' && quest_choice != 'A');
						}

					}
					else if (quest_choice == 'A')
					{
						system("cls");
						cout << "\n\t The forgotten Race." << endl;
						quest_1_function(monster);
					}
					else if (quest_choice == 'C')
					{
						if (monster.health < 10 && king.health < 10)
						{
							system("cls");
							cout << "\t The jury." << endl;
							quest_3_function(gunsmith);
							break;
						}
						else
						{
							cout << "Quest 3 is not unlocked, complete quest 1 and 2 to play quest 3. Select quest : ";
							do
							{
								cin >> quest_choice;
								if (islower(quest_choice))
								{
									quest_choice = toupper(quest_choice);
								}
								if (quest_choice != 'A' && quest_choice!='B')
									cout << "Invalid Selection, try again : ";
								else if (quest_choice == 'A')
								{
									system("cls");
									cout << "The Forgotten Race" << endl;
									quest_1_function(monster);
								}
								else if (quest_choice == 'B')
								{
									if (monster.health < 10)
									{
										system("cls");
										cout << "\t Army of the king." << endl;
										quest_2_function(king);
									}
									else
									{
										cout << "Quest 2 is not unlocked, complete quest 1 to play quest 2. Select quest : ";
										do
										{
											cin >> quest_choice;
											if (islower(quest_choice))
											{
												quest_choice = toupper(quest_choice);
											}
											if (quest_choice != 'A')
												cout << "Invalid Selection, try again : ";
											else if (quest_choice == 'A')
											{
												cout << "The Forgotten Race" << endl;
												quest_1_function(monster);
											}
										} while (quest_choice != 'a' && quest_choice != 'A');
									}
								}
							} while (quest_choice != 'A' && quest_choice != 'B');
						}
					}
					else
						cout << "Invalid Option, try again : ";
				} while (quest_choice != 'A' && quest_choice != 'C');
			}
		}
		case 'E':
		{
			if (monster.health < 50 && king.health < 50 && gunsmith.health < 50 && dragon.health<50)
			{
				system("cls");
				cout << "\t The FINAL BOSS." << endl;
				final_boss(the_witch);
				break;
			}
			else
			{
				cout << "Complete quest 1,2 and 3,4 to fight the witch, try again : ";
				do
				{
					cin >> quest_choice;
					if (islower(quest_choice))
					{
						quest_choice = toupper(quest_choice);
					}
					if (quest_choice == 'B')
					{
						if (monster.health < 10)
						{
							system("cls");
							cout << "\t Army of the king." << endl;
							quest_2_function(king);
						}
						else
						{
							cout << "Quest 2 is not unlocked, complete quest 1 to play quest 2. Select quest : ";
							do
							{
								cin >> quest_choice;
								if (islower(quest_choice))
								{
									quest_choice = toupper(quest_choice);
								}
								if (quest_choice != 'A')
									cout << "Invalid Selection, try again : ";
								else if (quest_choice == 'A')
								{
									system("cls");
									cout << "The Forgotten Race" << endl;
									quest_1_function(monster);
								}
							} while (quest_choice != 'a' && quest_choice != 'A');
						}

					}
					else if (quest_choice == 'A')
					{
						system("cls");
						cout << "\n\t The forgotten Race." << endl;
						quest_1_function(monster);
						break;
					}
					else if (quest_choice == 'C')
					{
						if (monster.health < 10 && king.health < 10)
						{
							system("cls");
							cout << "\t The jury." << endl;
							quest_3_function(gunsmith);
							break;
						}
						else
						{
							cout << "Quest 3 is not unlocked, complete quest 1 and 2 to play quest 3. Select quest : ";
							do
							{
								cin >> quest_choice;
								if (islower(quest_choice))
								{
									quest_choice = toupper(quest_choice);
								}
								if (quest_choice != 'A' && quest_choice != 'B')
									cout << "Invalid Selection, try again : ";
								else if (quest_choice == 'A')
								{
									cout << "The Forgotten Race" << endl;
									quest_1_function(monster);
								}
								else if (quest_choice == 'B')
								{
									if (monster.health < 10)
									{
										system("cls");
										cout << "\t Army of the king." << endl;
										quest_2_function(king);
									}
									else
									{
										cout << "Quest 2 is not unlocked, complete quest 1 to play quest 2. Select quest : ";
										do
										{
											cin >> quest_choice;
											if (islower(quest_choice))
											{
												quest_choice = toupper(quest_choice);
											}
											if (quest_choice != 'A')
												cout << "Invalid Selection, try again : ";
											else if (quest_choice == 'A')
											{
												system("cls");
												cout << "The Forgotten Race" << endl;
												quest_1_function(monster);
											}
										} while (quest_choice != 'a' && quest_choice != 'A');
									}
								}
							} while (quest_choice != 'A' && quest_choice != 'B');
						}
					}
					else if (quest_choice == 'D')
					{
						if (monster.health < 10 && king.health < 10 && gunsmith.health<10)
						{
							system("cls");
							cout << "\t The FINAL DRAGON." << endl;
							quest_4_function(dragon);
							break;
						}
						else
						{
							cout << "Quest 4 is not unlocked, complete quest 1,2 and 3 to play quest 4. Select quest : ";
							do
							{
								cin >> quest_choice;
								if (islower(quest_choice))
								{
									quest_choice = toupper(quest_choice);
								}
								if (quest_choice != 'A' && quest_choice != 'B' && quest_choice !='C' && quest_choice !='D')
									cout << "Invalid Selection, try again : ";
								else if (quest_choice == 'A')
								{
									system("cls");
									cout << "The Forgotten Race" << endl;
									quest_1_function(monster);
								}
								else if (quest_choice == 'B')
								{
									if (monster.health < 10)
									{
										system("cls");
										cout << "\t Army of the king." << endl;
										quest_2_function(king);
									}
									else
									{
										cout << "Quest 2 is not unlocked, complete quest 1 to play quest 2. Select quest : ";
										do
										{
											cin >> quest_choice;
											if (islower(quest_choice))
											{
												quest_choice = toupper(quest_choice);
											}
											if (quest_choice != 'A')
												cout << "Invalid Selection, try again : ";
											else if (quest_choice == 'A')
											{
												system("cls");
												cout << "The Forgotten Race" << endl;
												quest_1_function(monster);
											}
										} while (quest_choice != 'a' && quest_choice != 'A');
									}
								}
								else if (quest_choice == 'C')
								{
									if (monster.health < 10 && king.health < 10)
									{
										system("cls");
										cout << "\tThe Jury." << endl;
										quest_3_function(gunsmith);
									}
									else
									{
										cout << "Quest 3 is not unlocked, complete quest 1,2 to play quest 3. Select quest : ";
										do
										{
											cin >> quest_choice;
											if (islower(quest_choice))
											{
												quest_choice = toupper(quest_choice);
											}
											if (quest_choice != 'A' && quest_choice!='B')
												cout << "Invalid Selection, try again : ";
											else if (quest_choice == 'A')
											{
												system("cls");
												cout << "The Forgotten Race" << endl;
												quest_1_function(monster);
											}
											else if (quest_choice == 'B')
											{
												if (monster.health < 50)
												{
													system("cls");
													cout << "\t Army of the king." << endl;
													quest_2_function(king);
												}
												else
												{
													cout << "Quest 2 is not unlocked, play and complete quest 1 to play quest 2, select quest 1 : ";
													continue;
												}
											}
										} while (quest_choice != 'a' && quest_choice != 'A' && quest_choice!='B'&& quest_choice!='b');
									}
								}
							} while (quest_choice != 'A' && quest_choice != 'B');
						}
					}
					else
						cout << "Invalid Option, try again : ";
				} while (quest_choice != 'A' && quest_choice != 'C' && quest_choice !='D');
			}
		}
		default: cout << "Invalid quest selection, please select again : ";
		}// SCOPE OF SWITCH
	} while (quest_choice != 'A' && quest_choice != 'B' && quest_choice != 'C' && quest_choice != 'D');
}

// FUNCTION OF QUEST 1
void quest_1_function(struct quest_1_boss)
{
	char try_again_choice ;
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
					cout << "Hero Attack : " << character.hero_damage;
				}
				if (hero_attack_button != 'A' && hero_attack_button != 'a')
					cout << "Invalid Attack Button, Press A to Attack : ";
			} while (hero_attack_button != 'A' && hero_attack_button != 'a');
			monster.health = monster.health - character.hero_damage;
			cout << "\nMonster Turn:" << endl;
			monster.damage = 59 + (rand() % 140);
			cout << "Monster Damage " << monster.damage;
			character.hero_health = character.hero_health - monster.damage;
			continue;
		}
		system("cls");
		if (monster.health <= 50)
		{

			cout << "\n\tYou killed The Boss with the final attack\n\tThe boss is defeated\n";
			character.hero_health = 2000;
			cout << "Your Hero has been promoted to level 1. healthpoints and damage is increased, expiernce point resetted;" << endl;
		}
		else if (character.hero_health < 100)
		{
			monster.health = 2000;
			character.hero_health = 1584;
			cout << "\nYou Died , \n\t The monster killed you.\n";
		}
		cout << "Press 1 to try again or 2 to go to quest selection menu or press 3 to main menu or press 4 to exit : ";
		do
		{
			cin >> try_again_choice;
			if (try_again_choice != '1' && try_again_choice != '2' && try_again_choice != '3' && try_again_choice != '4')
				cout << "Invalid Quest Selection, select again : ";
		} while (try_again_choice != '1' && try_again_choice != '2' && try_again_choice != '3' && try_again_choice != '4');
		if (try_again_choice == '2')
			system("cls");
			quest_selection_function(monster, king, gunsmith, dragon, the_witch);
		if (try_again_choice == '3')
			system("cls");
			main_menu();
		if (try_again_choice == '4')
			system("cls");
			exit;
	} while (try_again_choice == '1');
}

// FUNCTION OF QUEST 2
void quest_2_function(struct quest_2_boss)
{
	char try_again_choice;
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
		system("cls");
		if (king.health <= 50)
		{

			cout << "\n\tYou killed The Boss with the final attack\n\tThe boss is defeated\n";
			character.hero_health = 2450;
			cout << "Your Hero has been promoted to level 3. healthpoints and damage is increased;" << endl;
		}
		else if (character.hero_health < 100)
		{
			king.health = 2450;
			character.hero_health = 2000;
			cout << "\nYou Died , \n\t The king killed you.\n";
		}
		cout << "Press 1 to try again or 2 to go to quest selection menu or press 3 to main menu or press 4 to exit : ";
		do
		{
			cin >> try_again_choice;
			if (try_again_choice != '1' && try_again_choice != '2' && try_again_choice != '3' && try_again_choice != '4')
				cout << "Invalid Quest Selection, select again : ";
		} while (try_again_choice != '1' && try_again_choice != '2' && try_again_choice != '3' && try_again_choice != '4');
		if (try_again_choice == '2')
			system("cls");
			quest_selection_function(monster, king, gunsmith, dragon, the_witch);
		if (try_again_choice == '3')
			system("cls");
			main_menu();
		if (try_again_choice == '4')
			system("cls");
			exit;
	} while (try_again_choice == '1');
}

// FUNCTION OF QUEST 3
void quest_3_function(struct quest_3_boss)
{
	char try_again_choice;
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
		system("cls");
		if (gunsmith.health <= 50)
		{

			cout << "\n\tYou killed The Boss with the final attack\n\tThe boss is defeated\n";
			character.hero_health = 2900;
			cout << "Your Hero has been promoted to level 3. healthpoints and damage is increased;" << endl;
		}
		else if (character.hero_health < 100)
		{
			gunsmith.health = 2900;
			character.hero_health = 2450;
			cout << "\nYou Died , \n\t The monster killed you.\n";
		}
		cout << "Press 1 to try again or 2 to go to quest selection menu or press 3 to main menu or press 4 to exit : ";
		do
		{
			cin >> try_again_choice;
			if (try_again_choice != '1' && try_again_choice != '2' && try_again_choice != '3' && try_again_choice != '4')
				cout << "Invalid Quest Selection, select again : ";
		} while (try_again_choice != '1' && try_again_choice != '2' && try_again_choice != '3' && try_again_choice != '4');
		if (try_again_choice == '2')
			system("cls");
			quest_selection_function(monster, king, gunsmith, dragon, the_witch);
		if (try_again_choice == '3')
			system("cls");
			main_menu();
		if (try_again_choice == '4')
			system("cls");
			exit;
	} while (try_again_choice == '1');
}

// FUNCTION OF QUEST 4
void quest_4_function(struct quest_4_boss)
{
	char try_again_choice;
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
		system("cls");
		if (dragon.health <= 50)
		{

			cout << "\n\tYou killed The Boss with the final attack\n\tThe boss is defeated\n";
			character.hero_health = 3350;
			cout << "Your Hero has been promoted to level 3. healthpoints and damage is increased;" << endl;
		}
		else if (character.hero_health < 100)
		{
			dragon.health = 3350;
			character.hero_health = 2900;
			cout << "\nYou Died , \n\t The monster killed you.\n";
		}
		cout << "Press 1 to try again or 2 to go to quest selection menu or press 3 to main menu or press 4 to exit : ";
		do
		{
			cin >> try_again_choice;
			if (try_again_choice != '1' && try_again_choice != '2' && try_again_choice != '3' && try_again_choice != '4')
				cout << "Invalid Quest Selection, select again : ";
		} while (try_again_choice != '1' && try_again_choice != '2' && try_again_choice != '3' && try_again_choice != '4');
		if (try_again_choice == '2')
			system("cls");
			quest_selection_function(monster, king, gunsmith, dragon, the_witch);
		if (try_again_choice == '3')
			system("cls");
			main_menu();
		if (try_again_choice == '4')
			system("cls");
			exit;
	} while (try_again_choice == '1');
}
void final_boss(struct final_boss)
{
	char try_again_choice;
	char hero_attack_button;
	display_character(character);
	srand((unsigned)time(NULL));       //This Boss Will be MEDIUM as it is the first Quest
	do
	{
		cout << "The Battle has started" << endl;
		dragon.health = 4000;
		character.hero_health = 3350;
		while (dragon.health >= 1 && character.hero_health >= 1)
		{
			cout << "\n\tHero turn:" << endl;
			cout << "Press A to Attack : ";
			do
			{
				cin >> hero_attack_button;
				if (hero_attack_button == 'A' || hero_attack_button == 'a')
				{
					character.hero_damage = 260 + (rand() % 280);
					cout << "Hero Attack : " << character.hero_damage;
				}
				if (hero_attack_button != 'A' && hero_attack_button != 'a')
					cout << "Invalid Attack Button, Press A to Attack : ";
			} while (hero_attack_button != 'A' && hero_attack_button != 'a');
			the_witch.health = the_witch.health - character.hero_damage;
			cout << "\nWitch Magic: ";
			the_witch.damage = 190 + (rand() % 290);
			cout << the_witch.damage;
			character.hero_health = character.hero_health - the_witch.damage;
			continue;
		}
		system("cls");
		if (the_witch.health <= 50)
		{

			cout << "\n\tYou killed The Boss with the final attack\n\tThe boss is defeated\n";
			cout << "Your Hero has finished the game" << endl;
		}
		else if (character.hero_health < 100)
		{
			dragon.health = 4000;
			character.hero_health = 3350;
			cout << "\nYou Died , \n\t The evil witch made you a statue.\n";
		}
		cout << "Press 1 to try again or 2 to go to quest selection menu or press 3 to main menu or press 4 to exit : ";
		do
		{
			cin >> try_again_choice;
			if (try_again_choice != '1' && try_again_choice != '2' && try_again_choice != '3' && try_again_choice != '4')
				cout << "Invalid Quest Selection, select again : ";
		} while (try_again_choice != '1' && try_again_choice != '2' && try_again_choice != '3' && try_again_choice != '4');
		if (try_again_choice == '2')
		{
			system("cls");
			quest_selection_function(monster, king, gunsmith, dragon, the_witch);
		}
			if (try_again_choice == '3')
			{
				system("cls");
				main_menu();
			}
			if (try_again_choice == '4')
			{
				system("cls");
				exit;
			}
	} while (try_again_choice == '1');
}