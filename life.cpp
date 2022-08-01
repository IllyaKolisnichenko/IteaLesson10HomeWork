#include <iostream>
#include <string>
#include <map>
class Life {
public:
	void setName(std::string name)
	{
		name_ = name;
	}
	std::string getName()
	{
		return name_;
	}
	

	std::string name_;
};
class Bacteria : public Life {
public:
	Bacteria() {
		name_ = "Bacteria";
	}

	enum dangerousBacteria
	{
		ClostridiumBotulinum,
		EscherichiaColi,
		SalmonellaTyphi,
		VibrioCholerae,
		ClostridiumCetani,
		AspergillusFumigatus,
	};
	std::map< dangerousBacteria, std::string > dangerous_Bacteria
	{   {ClostridiumBotulinum, "Clostridium Botulinum"},
		{EscherichiaColi, "Escherichia Coli"},
		{SalmonellaTyphi, "Salmonella Typhi"},
		{VibrioCholerae, "Vibrio Cholerae"},
		{ClostridiumCetani, "Clostridium Cetani"},
		{AspergillusFumigatus, "Aspergillus Fumigatus"},
	};
}; 
class Insects : public Life {
public:
	Insects()
	{
		name_ = "Insects";
	}
	enum dangerousInsects
	{
		TsetseFly,
		PeacockEyeCaterpillar,
		Centipede,
		AntHarvester,
		BulletAnt,
		Lice
	};
	std::map< dangerousInsects, std::string > dangerous_Insects
	{   {TsetseFly, "Tsetse Fly"},
		{PeacockEyeCaterpillar, "Peacock Eye Caterpillar"},
		{Centipede, "Centipede"},
		{AntHarvester, "Ant Harvester"},
		{BulletAnt, "Bullet Ant"},
		{Lice, "Lice"},
	};
};
class Human : public Life {
public:
	Human() {
		name_ = "Human";
	}
	enum popularJob
	{
		Designer,
		Architect,
		Fireman,
		Engineer,
		Pilot,
		Surgeon,
	};
	std::map< popularJob, std::string > popular_Job
	{   {Designer, "Designer"},
		{Architect, "Architect"},
		{Fireman, "Fireman"},
		{Engineer, "Engineer"},
		{Pilot, "Pilot"},
		{Surgeon, "Surgeon"},
	};
};
void AI()
{
	srand(time(nullptr));
	Bacteria bacteria;
	Insects insects;
	Human human;
	char choice;
	int random{ rand() % 6 };
	std::cout << "menu" << std::endl
		<< "1. " << bacteria.getName() << std::endl
		<< "2. " << insects.getName() << std::endl
		<< "3. " << human.getName() << std::endl
		<< "Choice(1,2,3): " << std::endl;
	std::cin >> choice;
	if (choice == '1')
	{
		auto itBacteria = bacteria.dangerous_Bacteria.find(static_cast<Bacteria::dangerousBacteria>(random));
		bacteria.setName(itBacteria->second);
		std::cout << "dangerous bacteria" << std::endl << std::endl
			<< "One of the dangerous bacteria is " << bacteria.getName() << std::endl;
	}
	if (choice == '2')
	{
		auto itBacteria = bacteria.dangerous_Bacteria.find(static_cast<Bacteria::dangerousBacteria>(random));
		bacteria.setName(itBacteria->second);
		std::cout << "dangerous bacteria" << std::endl << std::endl
			<< "One of the dangerous bacteria is " << bacteria.getName() << std::endl;
	}
	if (choice == '3')
	{
		auto itHuman = human.popular_Job.find(static_cast<Human::popularJob>(random));
		human.setName(itHuman->second);
		std::cout << "popular jobs of humans" << std::endl << std::endl
			<< "One of the popular job is " << human.getName() << std::endl;
	}
}
int main()
{
	char var;
	std::cout << "1. continue" << std::endl << "2. end" << std::endl;
	std::cin >> var;
	while (true)
	{
		
		if (var == '1')
		{
			AI();
			std::cout << "1. continue" << std::endl << "2. end" << std::endl;
			std::cin >> var;
		}
		if (var == '2')
		{
			return 0;
		}
	}
	return 0;
}