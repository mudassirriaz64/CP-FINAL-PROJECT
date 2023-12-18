#include<iostream>
#include<string>
using namespace std;

struct character_information // Will store information about character
{
		string character_name;
		string character_class;
		int experience_level=0;
	int character_health=0;
}character;

static void take_input_character(struct character_information)
{
	cout << "Enter character name : ";
	cin >> character.character_name;
	do {
		cout << "Choose Class : Wage, Rogue Or Warrior" << endl;
		cin >> character.character_class;
		if (character.character_class == "wage")
		{
			character.character_health = 120;
			character.experience_level = 3;
		}
		else if (character.character_class == "rogue")
		{
			character.character_health = 150;
			character.experience_level = 5;
		}
		else if (character.character_class == "warrior")
		{
			character.character_health = 200;
			character.experience_level = 9;
		}
		else
		{
			cout << "Invalid Class, please try again." << endl;
		}
	} while (character.character_class != "wage" && character.character_class != "rogue" && character.character_class != "warrior");
}
void display_character(struct character_information) //Display Character Information
{
	cout << "Character Name : " << character.character_name << endl;
	cout << "Character Class : " << character.character_class << endl;
	cout << "Character Health : " << character.character_health << endl;
	cout << "Character Experience Level : " << character.experience_level << endl;
}
int main()
{
	cout << "\t \t \t Welcome To The Game" << endl;
	take_input_character(character);
	display_character(character);
	return 0;
}
