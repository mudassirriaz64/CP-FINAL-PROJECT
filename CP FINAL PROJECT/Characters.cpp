//#include<iostream>
//#include<string>
//using namespace std;
//
//struct character_information // will store information about character
//{
//		int hero_choose=0;
//		string hero_name;
//		string hero_class;
//		int hero_experience_level=0;
//		int hero_health=0;
//		string hero_weapon;
//		int hero_damage;
//}character;
//
//static void take_input_character(struct character_information)
//{
//	cout << "You have to select hero from one of the following hero,Each of the character has its own weapone and style)" << endl;
//	cout << "1. Valkriye ";
//	cout<< "Fights with an axe around her,Tough melee Fighter and deals area damage around her " << endl;// Enter description of valkriye
//	cout << "2. Magic Archer"<< endl;
//	cout<<"Not quite a Wizard, nor an Archer - he shoots a magic arrow that passes through and damages all the enemies in its path"<<endl; //Enter description of gaint
//	cout << "3. Prince " << endl;
//	cout << "The prince rides an horse and deals area damage and lets his spiked club do the talking for him" << endl;// Enter desciption of Hog Rider
//	do {
//		cout << "Select your character(e,g 1,2,3) : ";
//		cin >> character.hero_choose;
//		if (character.hero_choose == 1)
//		{
//			character.hero_name = "Valkriye";
//			character.hero_class = "Fighter";
//			character.hero_health = 1584;
//			character.hero_experience_level = 0;
//			character.hero_weapon = "Axe";
//			character.hero_damage = 221;
//		}
//		else if (character.hero_choose == 2)
//		{
//			character.hero_name = "Magic Archer";
//			character.hero_class = "Archer";
//			character.hero_health = 1326;
//			character.hero_experience_level = 0;
//			character.hero_weapon = "Bow And Magic Arrow";
//			character.hero_damage = 134;
//		}
//		else if (character.hero_choose == 3)
//		{
//			character.hero_name = "Prince";
//			character.hero_class = "Knight";
//			character.hero_health = 1087;
//			character.hero_experience_level = 0;
//			character.hero_weapon = "Spiked Club";
//			character.hero_damage = 170;
//		}
//		else
//		{
//			cout << "Invalid choice, please try again." << endl;
//		}
//	} while (character.hero_choose != 1 && character.hero_choose != 2 && character.hero_choose != 3);
//}
//void display_character(struct character_information) //display character information
//{
//	cout << "Hero Name : " << character.hero_name << endl;
//	cout << "Class : " << character.hero_class << endl;
//	cout << "Health : " << character.hero_health << endl;
//	cout << "Experience Level : " << character.hero_experience_level << endl;
//	cout << "Weapon : " << character.hero_weapon << endl;
//	cout << "Damage : " << character.hero_damage << endl;
//	
//}
//int main()
//{
//	cout << "\t \t \t welcome to the game" << endl;
//	take_input_character(character);
//	display_character(character);
//	return 0;
//}
