#include<iostream>
#include<string>
#include<math.h>
#include<cstdlib>	 // USED IN RANDOM ATTACKS GENERATING
#include <thread>
#include <chrono>
#include<fstream>
using namespace std;
struct character_information // STORES INFORMATION ABOUT THE HERO OR CHARACTER
{
	string hero_choose = "0";
	string hero_name;
	string hero_class;
	int hero_experience_level = 0;
	int hero_health = 0;
	string hero_weapon;
	int hero_damage = 0;
	int level = 0;
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
	int health = 3350;
	int damage = 0;
	int level = 15;
}dragon;

struct final_boss // STORES INFORMATION ABOUT FINAL BOSS
{
	int health = 4000;
	int damage = 0;
	int level = 20;
}the_witch;

int high_score = 0;//Global Variable for high score

// FUNCTIONS PROTOYPES OF ALL THE FUNCTIONS USED IN THE PROGRAM
void main_menu();
void game_loop();
void quest_selection_function(struct quest_1_boss, struct quest_2_boss, struct quest_3_boss, struct quest_4_boss, struct final_boss);
static void take_input_character(struct character_information);
void display_character(struct character_information);
void quest_1_function(struct quest_1_boss);
void quest_2_function(struct quest_2_boss);
void quest_3_function(struct quest_3_boss);
void quest_4_function(struct quest_4_boss);
void final_boss(struct final_boss);
void delayprint(const string& text, int milliseconds);
void displayhighscore();
void savehighScore();
void readhighscore();
// INT MAIN
int main()
{
	// INT MAIN
	game_loop();
	return 0;
}
void game_loop() // THIS FUNCTION SHOWS MAIN MENU AND RUNS A LOOP UNTIL USER EXITS
{
	string playagain;
	do
	{
		main_menu();
		cout << "Do you want to play again? (Y/N): ";
		cin >> playagain;
		if (playagain != "y" && playagain != "Y")
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
	string choice;
	cout << "\t\t\tWelcome To Eldoria\n";
	cout << "Main Menu\n";
	cout << "1.Start\n";
	cout << "2.High Score\n";
	cout << "3.Exit\n";
	cout << "Enter your choice (1,2,3):";
	do {
		cin >> choice;
		if (cin.fail() || choice > "0" || choice < "3") //CIN.FAILS CHECKS IF THE INPUT IS CORRECT OR NOT(PRE BUILD FUNCTION)
		{
			cin.clear();
		}
		if (choice == "1")
		{
			system("cls");
			take_input_character(character);
			system("cls");
			quest_selection_function(monster, king, gunsmith, dragon, the_witch);
		}
		else if (choice == "2")
		{
			system("cls");
			displayhighscore();
			cout << "Press B to go back to main menu : ";
			do
			{
				cin >> choice;
				if (cin.fail() || character.hero_choose > "0" || character.hero_choose < "2")
				{
					cin.clear();
				}
				if (choice == "B" || choice == "b")
				{
					system("cls");
					main_menu();
					break;
				}
				else
				{
					cout << "Invalid Selection, Try again : ";
				}
			} while (choice != "B" && choice != "b");
		}
		else if (choice == "3")
		{
			break;
		}
		else if (choice != "1" && choice != "2" && choice != "3")
		{
			cout << "Invalid Selection, try again : ";
		}
	} while (choice !="1" && choice!="2");
}
// THIS FUNCTION SELECTS THE HERO AND OTHER INFORMATION RELATED TO HERO
static void take_input_character(struct character_information)
{
	cout << "You have to select hero from one of the following hero,(Each of the character has its own weapon and style)" << endl;
	cout << endl;
	cout << "1. Valkriye " << endl;
	cout << "Fights with an axe around her,Tough melee Fighter and deals area damage around her. " << endl;// Enter description of valkriye
	cout << "2. Magic Archer" << endl;
	cout << "Not quite a Wizard, nor an Archer - he shoots a magic arrow that passes through and damages all the enemies in its path." << endl; //Enter description of gaint
	cout << "3. Prince " << endl;
	cout << "The prince rides an horse and deals area damage and lets his spiked club do the talking for him." << endl;// Enter desciption of Hog Rider
	cout << endl;
	cout << "NOTE : Once character selected, it can only be changed after a quest completion";
	cout << endl;
	cout << endl;
	do 
	{
		cout << "Select your character(e,g 1,2,3) OR Press B to go back to main menu : ";
		cin >> character.hero_choose;
		if (cin.fail() || character.hero_choose > "0" || character.hero_choose < "4")
		{
			cin.clear();
		}
		if (character.hero_choose == "1")
		{
			character.hero_name = "Valkriye";
			character.hero_class = "Warrior";
			character.hero_health = 400;
			character.hero_experience_level = 0;
			character.hero_weapon = "Axe";
			character.hero_damage = 0;
			character.level = 0;
		}
		else if (character.hero_choose == "2")
		{
			character.hero_name = "Magic Archer";
			character.hero_class = "Rogue";
			character.hero_health = 400;
			character.hero_experience_level = 0;
			character.hero_weapon = "Bow And Magic Arrow";
			character.hero_damage = 0;
			character.level = 0;
		}
		else if (character.hero_choose == "3")
		{
			character.hero_name = "Prince";
			character.hero_class = "Wage";
			character.hero_health = 400;
			character.hero_experience_level = 0;
			character.hero_weapon = "Spiked Club";
			character.hero_damage = 0;
			character.level = 0;
		}
		else if (character.hero_choose == "B" || character.hero_choose == "b")
		{
			system("cls");
			main_menu();
			break;
		}
		else
		{
			cout << "Invalid choice, please try again." << endl;
		}
	} while (character.hero_choose != "1" && character.hero_choose != "2" && character.hero_choose != "3" && character.hero_choose != "B" && character.hero_choose != "b");
}

void display_character(struct character_information) // DISPLAY HERO OR CHARACTER INFORMATION
{
	cout << "Hero Name : " << character.hero_name << endl;
	cout << "Class : " << character.hero_class << endl;
	cout << "Health : " << character.hero_health << endl;
	cout << "Experience Level : " << character.hero_experience_level << endl;
	cout << "Weapon : " << character.hero_weapon << endl;
	cout << "Level : " << character.level << endl;
}

// THIS FUNCTION STARTS THE QUEST BASED ON USER CHOICE
void quest_selection_function(struct quest_1_boss, struct quest_2_boss, struct quest_3_boss, struct quest_4_boss, struct final_boss)
{
	string quest_choice;
	cout << endl;
	cout << endl;
	cout << "\tYou can Embark on different Quests.\n";
	cout << "\t\nEach quest have different difficulty level.\n";
	cout << "\n1.THE FORGOTTEN RACE.\n";
	cout << "2.ARMY OF THE KING.\n";
	cout << "3.THE JURY.\n";
	cout << "4.THE DRAGON KING.\n";
	cout << "5.THE FINAL WITCH.\n";
	cout << endl;
	cout << "NOTE : If you select a quest you have already completed, your health points and damage will be calibrated\n" << endl
		<< "Enter the quest you want to play(You can only select the unlocked quests) "
		<< "otherwise, it would not play the quest (e.g.1,2) OR Press B to go to main menu : ";
	do //THIS DO-WHILE CHECKS WHETHER THE FIRST INPUT IS CORRECT OR NOT.
	{
		cin >> quest_choice;
		if (cin.fail() || quest_choice > "0" || quest_choice < "2")
		{
			cin.clear();
		}
		if (quest_choice == "1")
		{
			system("cls");
			delayprint("\n\t\tTHE FORGOTTEN RACE", 75);
			cout << endl;
			quest_1_function(monster);
			break;
		}
		else if (quest_choice == "2")
		{
			if (monster.health < 50)
			{
				system("cls");
				cout << "\n\t\t ARMY OF THE KING" << endl;
				quest_2_function(king);
				break;
			}
			else
			{
				cout << "Complete quest 1 to unlock quest 2, select quest 1 again : ";
				do
				{
					cin >> quest_choice;
					if (cin.fail() || quest_choice > "0" || quest_choice < "3")
					{
						cin.clear();
					}
					if (quest_choice == "1")
					{
						system("cls");
						delayprint("\n\t\tTHE FORGOTTEN RACE", 75);
						cout << endl;
						quest_1_function(monster);
						break;
					}
					else
					{
						cout << "Invalid Option, try again : ";
					}
				} while (quest_choice != "1");

			}
		}
		else if (quest_choice == "3")
		{
			if (monster.health < 50 && king.health < 50)
			{
				system("cls");
				cout << "\n\t\t THE JURY" << endl;
				quest_3_function(gunsmith);
				break;
			}
			else
			{
				cout << "Complete quest 1 and 2 to unlock quest 3, try again : ";
				do
				{
					cin >> quest_choice;
					if (cin.fail() || quest_choice > "0" || quest_choice < "4")
					{
						cin.clear();
					}
					if (quest_choice == "2")
					{
						if (monster.health < 10)
						{
							system("cls");
							cout << "\n\t\t ARMY OF THE KING " << endl;
							quest_2_function(king);
							break;
						}
						else
						{
							cout << "Quest 2 is not unlocked, complete quest 1 to play quest 2. Select quest : ";
							do
							{
								cin >> quest_choice;
								if (cin.fail() || quest_choice > "0" || quest_choice < "2")
								{
									cin.clear();
								}
								if (quest_choice != "1")
									cout << "Invalid Selection, try again : ";
								else if (quest_choice == "1")
								{
									system("cls");
									delayprint("\n\t\tTHE FORGOTTEN RACE", 75);
									cout << endl;
									quest_1_function(monster);
									break;
								}
							} while (quest_choice != "1");
						}

					}
					else if (quest_choice == "1")
					{
						system("cls");
						delayprint("\n\t\tTHE FORGOTTEN RACE", 75);
						cout << endl;
						quest_1_function(monster);
						break;
					}
					else
						cout << "Invalid Option, try again : ";
				} while (quest_choice != "1" && quest_choice != "2");
			}
		}
		else if (quest_choice == "4")
		{
			if (monster.health < 50 && king.health < 50 && gunsmith.health < 50)
			{
				system("cls");
				cout << "\n\t\t The DRAGON KING" << endl;
				quest_4_function(dragon);
				break;
			}
			else
			{
				cout << "Complete quest 1,2 and 3 to unlock quest 4, try again : ";
				do
				{
					cin >> quest_choice;
					if (cin.fail() || quest_choice > "0" || quest_choice < "4")
					{
						cin.clear();
					}
					if (quest_choice == "2")
					{
						if (monster.health < 10)
						{
							system("cls");
							cout << "\n\t\t ARMY OF THE KING" << endl;
							break;
							quest_2_function(king);
						}
						else
						{
							cout << "Quest 2 is not unlocked, complete quest 1 to play quest 2. Select quest : ";
							do
							{
								cin >> quest_choice;
								if (cin.fail() || quest_choice > "0" || quest_choice < "2")
								{
									cin.clear();
								}
								if (quest_choice != "1")
									cout << "Invalid Selection, try again : ";
								else if (quest_choice == "1")
								{
									system("cls");
									delayprint("\n\t\tTHE FORGOTTEN RACE", 75);
									cout << endl;
									quest_1_function(monster);
								}
							} while (quest_choice != "1");
						}

					}
					else if (quest_choice == "1")
					{
						system("cls");
						delayprint("\n\t\tTHE FORGOTTEN RACE", 75);
						cout << endl;
						quest_1_function(monster);
						break;
					}
					else if (quest_choice == "3")
					{
						if (monster.health < 10 && king.health < 10)
						{
							system("cls");
							cout << "\n\t\t THE JURY" << endl;
							quest_3_function(gunsmith);
							break;
						}
						else
						{
							cout << "Quest 3 is not unlocked, complete quest 1 and 2 to play quest 3. Select quest : ";
							do
							{
								cin >> quest_choice;
								if (cin.fail() || quest_choice > "0" || quest_choice < "3")
								{
									cin.clear();
								}
								if (quest_choice != "1" && quest_choice != "2")
								{
									cout << "Invalid Selection, try again : ";
								}

								else if (quest_choice == "1")
								{
									system("cls");
									delayprint("\n\t\tTHE FORGOTTEN RACE", 75);
									cout << endl;
									quest_1_function(monster);
								}
								else if (quest_choice == "2")
								{
									if (monster.health < 10)
									{
										system("cls");
										cout << "\n\t\t ARMY OF THE KING" << endl;
										quest_2_function(king);
										break;
									}
									else
									{
										cout << "Quest 2 is not unlocked, complete quest 1 to play quest 2. Select quest : ";
										do
										{
											cin >> quest_choice;
											if (cin.fail() || quest_choice > "0" || quest_choice < "2")
											{
												cin.clear();
											}
											if (quest_choice != "1")
												cout << "Invalid Selection, try again : ";
											else if (quest_choice == "1")
											{
												system("cls");
												delayprint("\n\t\tTHE FORGOTTEN RACE", 75);
												cout << endl;
												quest_1_function(monster);
												break;
											}
										} while (quest_choice != "1");
									}
								}
							} while (quest_choice != "1" && quest_choice != "2");
						}
					}
					else
						cout << "Invalid Option, try again : ";
				} while (quest_choice != "1" && quest_choice != "2" && quest_choice != "3");
			}
		}
		else if(quest_choice=="5")
		{
			if (monster.health < 50 && king.health < 50 && gunsmith.health < 50 && dragon.health < 50)
			{
				system("cls");
				cout << "\n\t\t The FINAL BOSS" << endl;
				final_boss(the_witch);
				break;
			}
			else
			{
				cout << "Complete quest 1,2 and 3,4 to fight the witch, try again : ";
				do
				{
					cin >> quest_choice;
					if (cin.fail() || quest_choice > "0" || quest_choice < "5")
					{
						cin.clear();
					}
					if (quest_choice == "2")
					{
						if (monster.health < 10)
						{
							system("cls");
							cout << "\n\t\t ARMY OF THE KING" << endl;
							quest_2_function(king);
						}
						else
						{
							cout << "Quest 2 is not unlocked, complete quest 1 to play quest 2. Select quest : ";
							do
							{
								cin >> quest_choice;
								if (cin.fail() || quest_choice > "0" || quest_choice < "2")
								{
									cin.clear();
								}
								if (quest_choice != "1")
								{
									cout << "Invalid Selection, try again : ";
								}

								else if (quest_choice == "1")
								{
									system("cls");
									delayprint("\n\t\tTHE FORGOTTEN RACE", 75);
									cout << endl;
									quest_1_function(monster);
									break;
								}
							} while (quest_choice != "1");
						}

					}
					else if (quest_choice == "1")
					{
						system("cls");
						delayprint("\n\t\tTHE FORGOTTEN RACE", 75);
						cout << endl;
						quest_1_function(monster);
						break;
					}
					else if (quest_choice == "3")
					{
						if (monster.health < 10 && king.health < 10)
						{
							system("cls");
							cout << "\n\t\t THE JURY" << endl;
							quest_3_function(gunsmith);
							break;
						}
						else
						{
							cout << "Quest 3 is not unlocked, complete quest 1 and 2 to play quest 3. Select quest : ";
							do
							{
								cin >> quest_choice;
								if (cin.fail() || quest_choice > "0" || quest_choice < "3")
								{
									cin.clear();
								}
								if (quest_choice != "1" && quest_choice != "2")
									cout << "Invalid Selection, try again : ";
								else if (quest_choice == "1")
								{
									system("cls");
									delayprint("\n\t\tTHE FORGOTTEN RACE", 75);
									cout << endl;
									quest_1_function(monster);
									break;
								}
								else if (quest_choice == "2")
								{
									if (monster.health < 10)
									{
										system("cls");
										cout << "\n\t\t ARMY OF THE KING" << endl;
										quest_2_function(king);
										break;
									}
									else
									{
										cout << "Quest 2 is not unlocked, complete quest 1 to play quest 2. Select quest : ";
										do
										{
											cin >> quest_choice;
											if (cin.fail() || quest_choice > "0" || quest_choice < "2")
											{
												cin.clear();
											}
											if (quest_choice != "1")
											{
												cout << "Invalid Selection, try again : ";
											}
											else if (quest_choice == "1")
											{
												system("cls");
												delayprint("\n\t\tTHE FORGOTTEN RACE", 75);
												cout << endl;
												quest_1_function(monster);
												break;
											}
										} while (quest_choice != "1");
									}
								}
							} while (quest_choice != "1" && quest_choice != "2");
						}
					}
					else if (quest_choice == "4")
					{
						if (monster.health < 10 && king.health < 10 && gunsmith.health < 10)
						{
							system("cls");
							cout << "\n\t\t The FINAL DRAGON." << endl;
							quest_4_function(dragon);
							break;
						}
						else
						{
							cout << "Quest 4 is not unlocked, complete quest 1,2 and 3 to play quest 4. Select quest : ";
							do
							{
								cin >> quest_choice;
								if (cin.fail() || quest_choice > "0" || quest_choice < "2")
								{
									cin.clear();
								}
								if (quest_choice != "1" && quest_choice != "2" && quest_choice != "3" && quest_choice != "4")

								{
									cout << "Invalid Selection, try again : ";
								}
								else if (quest_choice == "1")
								{
									system("cls");
									delayprint("\n\t\tTHE FORGOTTEN RACE", 75);
									cout << endl;
									quest_1_function(monster);
									break;
								}
								else if (quest_choice == "2")
								{
									if (monster.health < 10)
									{
										system("cls");
										cout << "\n\t\t ARMY OF THE KING " << endl;
										quest_2_function(king);
										break;
									}
									else
									{
										cout << "Quest 2 is not unlocked, complete quest 1 to play quest 2. Select quest : ";
										do
										{
											cin >> quest_choice;
											if (cin.fail() || quest_choice > "0" || quest_choice < "3")
											{
												cin.clear();
											}
											if (quest_choice != "1")
											{
												cout << "Invalid Selection, try again : ";
											}
											else if (quest_choice == "1")
											{
												system("cls");
												delayprint("\n\t\tTHE FORGOTTEN RACE", 75);
												cout << endl;
												quest_1_function(monster);
												break;
											}
										} while (quest_choice != "1");
									}
								}
								else if (quest_choice == "3")
								{
									if (monster.health < 10 && king.health < 10)
									{
										system("cls");
										cout << "\n\t\t THE JURY" << endl;
										quest_3_function(gunsmith);
									}
									else
									{
										cout << "Quest 3 is not unlocked, complete quest 1,2 to play quest 3. Select quest : ";
										do
										{
											cin >> quest_choice;
											if (cin.fail() || quest_choice > "0" || quest_choice < "2")
											{
												cin.clear();
											}
											if (quest_choice != "1" && quest_choice!= "2")
											{
												cout << "Invalid Selection, try again : ";
											}
											else if (quest_choice == "1")
											{
												system("cls");
												delayprint("\n\t\tTHE FORGOTTEN RACE", 75);
												cout << endl;
												quest_1_function(monster);
											}
											else if (quest_choice == "2")
											{
												if (monster.health < 50)
												{
													system("cls");
													cout << "\n\t\t ARMY OF THE KING" << endl;
													quest_2_function(king);
													break;
												}
												else
												{
													cout << "Quest 2 is not unlocked, play and complete quest 1 to play quest 2, select quest 1 : ";
												}
											}
										} while (quest_choice != "1");
									}
								}
								else
								{
									cout << "Invalid Option, Try again : ";
								}
							} while (quest_choice != "1" && quest_choice != "2");
						}
					}
					else
					{
						cout << "Invalid Option, try again : ";
					}
				} while (quest_choice != "1" && quest_choice != "2" && quest_choice != "3" && quest_choice != "4");
			}
		}
		else if (quest_choice == "b" || quest_choice == "B")
		{
			system("cls");
			main_menu();
			break;
		}
		else
		{
			cout << "Invalid Option, try again : ";
		}
	} while (quest_choice != "1" && quest_choice != "2" && quest_choice != "3" && quest_choice != "4" && quest_choice !="b" && quest_choice != "B");
}

// FUNCTION OF QUEST 1
void quest_1_function(struct quest_1_boss)
{
	string try_again_choice = "0";
	string hero_attack_button;
	int current_score;
	cout << endl;
	display_character(character);
	cout << endl;
	cout << "Monster health = 600\n";
	cout << "Monster Level = 5 ";
	cout << endl;
	srand((unsigned)time(NULL));       //This Boss Will be Easy as it is the first Quest
	do
	{
		if (try_again_choice == "1")
		{
			system("cls");
		}
		delayprint("\n\t\tThe Battle has started\n", 100);
		cout << endl;
		monster.health = 600;
		character.hero_health = 400;
		while (monster.health >= 1 && character.hero_health >= 1)
		{
			delayprint("Hero turn.... Press A to Attack OR B to go back to MAIN MENU :  ", 70);
			do
			{
				cin >> hero_attack_button;
				if (cin.fail() || hero_attack_button > "0" || hero_attack_button < "B")
				{
					cin.clear();
				}
				cout << endl;
				if (hero_attack_button == "a" || hero_attack_button == "A")
				{
					if (character.hero_health < 10)
						break;
					else
					{
						character.hero_damage = 90 + (rand() % 170);
						delayprint("Hero is attacking...... Hero Damage : ", 70);
						cout << character.hero_damage;
					}
				}
				if (hero_attack_button == "B" || hero_attack_button == "b")
				{
					system("cls");
					main_menu();
					break;
				}
				if (hero_attack_button != "A" && hero_attack_button != "a" && hero_attack_button != "b" && hero_attack_button != "B")
				{
					cout << "Invalid Attack Button, Press A to Attack : ";
				}
			} while (hero_attack_button != "A" && hero_attack_button != "a");
			monster.health = monster.health - character.hero_damage;
			delayprint("\nMonster health = ", 70);
			cout << monster.health;
			cout << endl;
			cout << endl;
			if (monster.health < 10)
				break;
			delayprint("Monster Turn...... Monster is attacking... ", 70);
			monster.damage = 59 + (rand() % 140);
			delayprint("Monster Damage : ", 70);
			cout << monster.damage;
			character.hero_health = character.hero_health - monster.damage;
			delayprint("\nHero Health = ", 70);
			cout << character.hero_health;
			cout << endl;
			cout << endl;
			continue;
		}
		system("cls");
		if (monster.health < 50)
		{

			delayprint("\n\tYou killed The Monster with the final attack\n\tThe boss is defeated", 75);
			character.hero_health = 600;
			delayprint("\n\tYour Hero has been promoted to level 1. healthpoints and damage is increased, experience point reseted", 75);
			character.level = 1;
			cout << endl;
			current_score = 200 - monster.health;
			if (current_score > high_score)
			{
				high_score = current_score;
				ofstream outFile("highscore.txt");
				outFile << high_score;
				outFile.close();
				cout << "\nScore: " << high_score << endl;
				savehighScore();
			}
		}
		else if (character.hero_health < 50)
		{
			monster.health = 600;
			character.hero_health = 400;
			character.level = 0;
			delayprint("\n\tYou Died....The Monster killed you.\n", 75);
		}
		cout << "\nPress 1 to try again or 2 to go to quest selection menu or press 3 to main menu or press 4 to exit : ";
		do
		{
			cin >> try_again_choice;
			if (cin.fail() || try_again_choice > "0" || try_again_choice < "5")
			{
				cin.clear();
			}
			if (try_again_choice != "1" && try_again_choice != "2" && try_again_choice != "3" && try_again_choice != "4")
				cout << "Invalid Selection, select again : ";
		} while (try_again_choice != "1" && try_again_choice != "2" && try_again_choice != "3" && try_again_choice != "4");
		if (try_again_choice == "2")
		{
			system("cls");
			quest_selection_function(monster, king, gunsmith, dragon, the_witch);
		}
		else if (try_again_choice == "3")
		{
			system("cls");
			main_menu();
		}
		else if (try_again_choice == "4")
		{
			system("cls");
			exit;
		}
	} while (try_again_choice == "1");
}

// FUNCTION OF QUEST 2
void quest_2_function(struct quest_2_boss)
{
	string try_again_choice = "0";
	string hero_attack_button;
	int current_score;
	cout << endl;
	display_character(character);
	cout << endl;
	cout << "King Health = 800\n";
	cout << "King Level = 10 ";
	cout << endl;
	srand((unsigned)time(NULL));       //This Boss Will be Easy as it is the first Quest
	do
	{
		if (try_again_choice == "1")
		{
			system("cls");
		}
		delayprint("\n\t\tThe Battle has started\n", 100);
		cout << endl;
		king.health = 800;
		character.hero_health = 600;
		while (king.health >= 1 && character.hero_health >= 1)
		{
			delayprint("Hero turn.... Press A to Attack to B to Main Menu :  ", 70);
			do
			{
				cin >> hero_attack_button;
				if (cin.fail() || hero_attack_button > "0" || hero_attack_button < "B")
				{
					cin.clear();
				}
				cout << endl;
				cout << endl;
				if (hero_attack_button == "A" || hero_attack_button == "a")
				{
					if (character.hero_health < 50)
						break;
					else
					{
						character.hero_damage = 130 + (rand() % 170);
						delayprint("Hero is attacking...... Hero Damage : ", 70);
						cout << character.hero_damage;
					}
				}
				if (hero_attack_button == "B" || hero_attack_button == "b")
				{
					system("cls");
					main_menu();
					break;
				}
				if (hero_attack_button != "A" && hero_attack_button != "a")
				{
					cout << "Invalid Attack Button, Press A to Attack : ";
				}
				
			} while (hero_attack_button != "a" && hero_attack_button != "A");
			king.health = king.health - character.hero_damage;
			delayprint("\nMonster health = ", 70);
			cout << king.health;
			cout << endl;
			cout << endl;
			if (king.health < 50)
				break;
			delayprint("King Turn...... King is attacking... ", 70);
			king.damage = 89 + (rand() % 160);
			delayprint("King Damage : ", 70);
			cout << king.damage;
			character.hero_health = character.hero_health - king.damage;
			delayprint("\nHero Health = ", 70);
			cout << character.hero_health;
			cout << endl;
			cout << endl;
			continue;
		}
		system("cls");
		if (king.health < 50)
		{

			delayprint("\n\tYou killed The King with the final attack\n\tThe boss is defeated", 75);
			character.hero_health = 800;
			delayprint("\n\tYour Hero has been promoted to level 2. healthpoints and damage is increased, experience point reseted", 75);
			cout << endl;
			character.level = 2;
			current_score = 200 - king.health;
			if (current_score > high_score)
			{
				high_score = current_score;
				ofstream outFile("highscore.txt");
				outFile << high_score;
				outFile.close();
				cout << "\nScore: " << high_score << endl;
				savehighScore();
			}
		}
		else if (character.hero_health < 50)
		{
			king.health = 800;
			character.hero_health = 600;
			delayprint("\n\tYou Died....The King killed you.\n", 75);
			character.level = 1;
		}
		cout << "\nPress 1 to try again or 2 to go to quest selection menu or press 3 to main menu or press 4 to exit : ";
		do
		{
			cin >> try_again_choice;
			if (cin.fail() || try_again_choice > "0" || try_again_choice < "5")
			{
				cin.clear();
			}
			if (try_again_choice != "1" && try_again_choice != "2" && try_again_choice != "3" && try_again_choice != "4")
				cout << "Invalid Selection, select again : ";
		} while (try_again_choice != "1" && try_again_choice != "2" && try_again_choice != "3" && try_again_choice != "4");
		if (try_again_choice == "2")
		{
			system("cls");
			quest_selection_function(monster, king, gunsmith, dragon, the_witch);
		}
		else if (try_again_choice == "3")
		{
			system("cls");
			main_menu();
		}
		else if (try_again_choice == "4")
		{
			system("cls");
			exit;
		}
	} while (try_again_choice == "1");
}

// FUNCTION OF QUEST 3
void quest_3_function(struct quest_3_boss)
{
	string try_again_choice = "0";
	string hero_attack_button;
	int current_score;
	cout << endl;
	display_character(character);
	cout << endl;
	cout << "Gunsmith health = 1000\n";
	cout << "Gunsmith Level = 15 ";
	cout << endl;
	srand((unsigned)time(NULL));       //This Boss Will be Easy as it is the first Quest
	do
	{
		if (try_again_choice == "1")
		{
			system("cls");
		}
		delayprint("\n\t\tThe Battle has started\n", 100);
		cout << endl;
		gunsmith.health = 1000;
		character.hero_health = 800;
		while (gunsmith.health >= 1 && character.hero_health >= 1)
		{
			delayprint("Hero turn.... Press A to Attack OR B to Main Menu :  ", 70);
			do
			{
				cin >> hero_attack_button;
				if (cin.fail() || hero_attack_button > "0" || hero_attack_button < "B")
				{
					cin.clear();
				}
				cout << endl;
				if (hero_attack_button == "A" || hero_attack_button == "a")
				{
					if (character.hero_health < 50)
						break;
					else
					{
						character.hero_damage = 170 + (rand() % 200);
						delayprint("Hero is attacking...... Hero Damage : ", 70);
						cout << character.hero_damage;
					}
				}
				if (hero_attack_button == "B" || hero_attack_button == "b")
				{
					system("cls");
					main_menu();
					break;
				}
				if (hero_attack_button != "A" && hero_attack_button != "a")
				{
					cout << "Invalid Attack Button, Press A to Attack : ";
				}
			} while (hero_attack_button != "A" && hero_attack_button != "A");
			gunsmith.health = gunsmith.health - character.hero_damage;
			delayprint("\nGunsmith health = ", 70);
			cout << gunsmith.health;
			cout << endl;
			cout << endl;
			if (gunsmith.health < 50)
				break;
			delayprint("Gunsmith Turn...... Gunsmith is attacking... ", 70);
			gunsmith.damage = 119 + (rand() % 210);
			delayprint("Gunsmith Damage : ", 70);
			cout << gunsmith.damage;
			character.hero_health = character.hero_health - gunsmith.damage;
			delayprint("\nHero Health = ", 70);
			cout << character.hero_health;
			cout << endl;
			cout << endl;
			continue;
		}
		system("cls");
		if (gunsmith.health < 50)
		{

			delayprint("\n\tYou killed The Gunsmith with the final attack\n\tThe gunsmith is defeated", 75);
			character.hero_health = 1000;
			delayprint("\n\tYour Hero has been promoted to level 3. healthpoints and damage is increased, experience point reseted", 75);
			cout << endl;
			character.level = 3;
			current_score = 200 - gunsmith.health;
			if (current_score > high_score)
			{
				high_score = current_score;
				ofstream outFile("highscore.txt");
				outFile << high_score;
				outFile.close();
				cout << "\nScore: " << high_score << endl;
				savehighScore();
			}
		}
		else if (character.hero_health < 50)
		{
			gunsmith.health = 1000;
			character.hero_health = 800;
			delayprint("\n\tYou Died....The Gunsmith killed you.\n", 75);
			character.level = 2;
		}
		cout << "\nPress 1 to try again or 2 to go to quest selection menu or press 3 to main menu or press 4 to exit : ";
		do
		{
			cin >> try_again_choice;
			if (cin.fail() || try_again_choice > "0" || try_again_choice < "5")
			{
				cin.clear();
			}
			if (try_again_choice != "1" && try_again_choice != "2" && try_again_choice != "3" && try_again_choice != "4")
				cout << "Invalid Selection, select again : ";
		} while (try_again_choice != "1" && try_again_choice != "2" && try_again_choice != "3" && try_again_choice != "4");
		if (try_again_choice == "2")
		{
			system("cls");
			quest_selection_function(monster, king, gunsmith, dragon, the_witch);
		}
		else if (try_again_choice == "3")
		{
			system("cls");
			main_menu();
		}
		else if (try_again_choice == "4")
		{
			system("cls");
			exit;
		}
	} while (try_again_choice == "1");
}

// FUNCTION OF QUEST 4
void quest_4_function(struct quest_4_boss)
{
	string try_again_choice = "0";
	string hero_attack_button;
	int current_score;
	cout << endl;
	display_character(character);
	cout << endl;
	cout << "Dragon health = 1200\n";
	cout << "Dragon Level = 20 ";
	cout << endl;
	srand((unsigned)time(NULL));       //This Boss Will be Easy as it is the first Quest
	do
	{
		if (try_again_choice == "1")
		{
			system("cls");
		}
		delayprint("\n\t\tThe Battle has started\n", 100);
		cout << endl;
		dragon.health = 1200;
		character.hero_health = 1000;
		while (dragon.health >= 1 && character.hero_health >= 1)
		{
			delayprint("Hero turn.... Press A to Attack or B to MAIN MENU :  ", 70);
			do
			{
				cin >> hero_attack_button;
				if (cin.fail() || hero_attack_button > "0" || hero_attack_button < "B")
				{
					cin.clear();
				}
				cout << endl;
				if (hero_attack_button == "A" || hero_attack_button == "a")
				{
					if (character.hero_health < 50)
						break;
					else
					{
						character.hero_damage = 210 + (rand() % 210);
						delayprint("Hero is attacking...... Hero Damage : ", 70);
						cout << character.hero_damage;
					}
				}
				if (hero_attack_button == "B" || hero_attack_button == "b")
				{
					system("cls");
					main_menu();
					break;
				}
				if (hero_attack_button != "A" && hero_attack_button != "a")
				{
					cout << "Invalid Attack Button, Press A to Attack to Main Menu : ";
				}
			} while (hero_attack_button != "a" && hero_attack_button != "A");
			dragon.health = dragon.health - character.hero_damage;
			delayprint("\nDragon health = ", 70);
			cout << dragon.health;
			cout << endl;
			cout << endl;
			if (dragon.health < 50)
				break;
			delayprint("Dragon Turn...... Dragon is attacking... ", 70);
			dragon.damage = 149 + (rand() % 240);
			delayprint("Dragon Burn : ", 70);
			cout << dragon.damage;
			character.hero_health = character.hero_health - dragon.damage;
			delayprint("\nHero Health = ", 70);
			cout << character.hero_health;
			cout << endl;
			cout << endl;
			continue;
		}
		system("cls");
		if (dragon.health < 50)
		{

			delayprint("\n\tYou killed The Dragon with the final attack\n\tThe dragon is defeated", 75);
			character.hero_health = 1200;
			delayprint("\n\tYour Hero has been promoted to level 4. healthpoints and damage is increased, experience point reseted", 75);
			character.level = 4;
			current_score = 200 - dragon.health;
			if (current_score > high_score)
			{
				high_score = current_score;
				ofstream outFile("highscore.txt");
				outFile << high_score;
				outFile.close();
				cout << "\nScore: " << high_score << endl;
				savehighScore();
			}
			cout << endl;
		}
		else if (character.hero_health < 50)
		{
			dragon.health = 1200;
			character.hero_health = 1000;
			delayprint("\n\tYou Died....The Dragon Burned you.\n", 75);
			character.level = 3;
		}
		cout << "\nPress 1 to try again or 2 to go to quest selection menu or press 3 to main menu or press 4 to exit : ";
		do
		{
			cin >> try_again_choice;
			if (cin.fail() || try_again_choice > "0" || try_again_choice < "5")
			{
				cin.clear();
			}
			if (try_again_choice != "1" && try_again_choice != "2" && try_again_choice != "3" && try_again_choice != "4")
				cout << "Invalid Selection, select again : ";
		} while (try_again_choice != "1" && try_again_choice != "2" && try_again_choice != "3" && try_again_choice != "4");
		if (try_again_choice == "2")
		{
			system("cls");
			quest_selection_function(monster, king, gunsmith, dragon, the_witch);
		}
		else if (try_again_choice == "3")
		{
			system("cls");
			main_menu();
		}
		else if (try_again_choice == "4")
		{
			system("cls");
			exit;
		}
	} while (try_again_choice == "1");
}
void final_boss(struct final_boss)
{
	string try_again_choice = "0";
	string hero_attack_button;
	int current_score;
	cout << endl;
	display_character(character);
	cout << endl;
	cout << "The Witch health = 1500\n";
	cout << "The Witch Level = 27 ";
	cout << endl;
	srand((unsigned)time(NULL));       //This Boss Will be Easy as it is the first Quest
	do
	{
		if (try_again_choice == "1")
		{
			system("cls");
		}
		delayprint("\n\t\tThe Battle has started\n", 100);
		cout << endl;
		the_witch.health = 1500;
		character.hero_health = 1200;
		while (the_witch.health >= 1 && character.hero_health >= 1)
		{
			delayprint("Hero turn.... Press A to Attack OR B to Main Menu:  ", 70);
			do
			{
				cin >> hero_attack_button;
				if (cin.fail() || hero_attack_button > "0" || hero_attack_button < "B")
				{
					cin.clear();
				}
				cout << endl;
				if (hero_attack_button == "A" || hero_attack_button == "a")
				{
					if (character.hero_health < 50)
						break;
					else
					{
						character.hero_damage = 260 + (rand() % 280);
						delayprint("Hero is attacking...... Hero Damage : ", 70);
						cout << character.hero_damage;
					}
				}
				if (hero_attack_button == "B" || hero_attack_button == "b")
				{
					system("cls");
					main_menu();
					break;
				}
				if (hero_attack_button != "A" && hero_attack_button != "a")
				{
					cout << "Invalid Attack Button, Press A to Attack : ";
				}
			} while (hero_attack_button != "a" && hero_attack_button != "A");
			the_witch.health = the_witch.health - character.hero_damage;
			delayprint("\nWitch health = ", 70);
			cout << the_witch.health;
			cout << endl;
			cout << endl;
			if (the_witch.health < 50)
				break;
			delayprint("Witch Turn...... Monster is attacking... ", 70);
			the_witch.damage = 200 + (rand() % 290);
			delayprint("Witch Damage : ", 70);
			cout << the_witch.damage;
			character.hero_health = character.hero_health - the_witch.damage;
			delayprint("\nHero Health = ", 70);
			cout << character.hero_health;
			cout << endl;
			cout << endl;
			continue;
		}
		system("cls");
		if (the_witch.health < 50)
		{

			delayprint("\n\tYou killed The Witch with the final attack\n\tThe boss is defeated", 75);
			delayprint("\n\tYour Hero has completed the game", 75);
			cout << endl;
			current_score = 200 - the_witch.health;
			if (current_score > high_score)
			{
				high_score = current_score;
				ofstream outFile("highscore.txt");
				outFile << high_score;
				outFile.close();
				cout << "\nScore: " << high_score << endl;
				savehighScore();
			}
		}
		else if (character.hero_health < 50)
		{
			the_witch.health = 1500;
			character.hero_health = 1200;
			delayprint("\n\tYou Died....The Witch made you a statue with her magic.\n", 75);
		}
		cout << "\nPress 1 to try again or 2 to go to quest selection menu or press 3 to main menu or press 4 to exit : ";
		do
		{
			cin >> try_again_choice;
			if (cin.fail() || try_again_choice > "0" || try_again_choice < "5")
			{
				cin.clear();
			}
			if (try_again_choice != "1" && try_again_choice != "2" && try_again_choice != "3" && try_again_choice != "4")
				cout << "Invalid Selection, select again : ";
		} while (try_again_choice != "1" && try_again_choice != "2" && try_again_choice != "3" && try_again_choice != "4");
		if (try_again_choice == "2")
		{
			system("cls");
			quest_selection_function(monster, king, gunsmith, dragon, the_witch);
		}
		else if (try_again_choice == "3")
		{
			system("cls");
			main_menu();
		}
		else if (try_again_choice == "4")
		{
			system("cls");
			exit;
		}
	} while (try_again_choice == "1");
}
//FUNCTION TO PRINT THE TEXT WITH A LITTLE DELAY
void delayprint(const string& text, int milliseconds)
{
	for (char ch : text)
	{
		cout << ch << flush; // Flush is a manipulator that ensures that the text is displayed immediatly without any buffer.
		this_thread::sleep_for(chrono::milliseconds(milliseconds)); // Pre-build function to introduce delay
	}
}

void readhighscore()
{
	ifstream inFile("highscore.txt");
	if (inFile.is_open())
	{
		inFile >> high_score;
		inFile.close();
	}
}
void savehighScore()
{
	ofstream outFile("highscore.txt");
	if (outFile.is_open())
	{
		outFile << high_score;
		outFile.close();
	}
}
void displayhighscore()
{
	readhighscore();
	cout << "High Score: " << high_score << endl;
}