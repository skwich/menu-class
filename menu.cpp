#include "Header.h"

TrainerMenu::TrainerMenu(const std::string procName)
{
	SetConsoleTitleA(procName.c_str());
	this->gameName = procName;
}

TrainerMenu::TrainerMenu(const std::string procName, DWORD game) :TrainerMenu(procName)
{
	game != 0 ? this->gameStatus = true : this->gameStatus = false;
}

void TrainerMenu::addFeature(std::string funcName, void* func, std::string funcKey)
{
	this->featuresName.push_back(funcName);
	this->features.push_back(func);
	this->featuresKey.push_back(funcKey);
	this->featuresStatus.push_back(false);
}

void TrainerMenu::drawMenu()
{
//prepare
	system("cls");
	std::string mainLine = "\t";
	std::string umline = "";
	std::string line = "";

	mainLine += this->gameName;
	
	for (int i = 0; i < mainLine.size() + 16; i++)
		line += "=";

	umline += "Status: ";
	this->gameStatus ? umline += "Game is Ready" : umline += "Game Not Found";

//draw menu
	std::cout << line << std::endl;
	std::cout << mainLine << std::endl;
	std::cout << line << std::endl;
	std::cout << umline << std::endl << std::endl;
	for (int i = 0; i < this->features.size(); i++)
	{
		std::string str = "[" + this->featuresKey.at(i) + "]\t" + this->featuresName.at(i) + "  --> [" + (this->featuresStatus.at(i) ? "ON" : "OFF") + "] <--"; // [NUM0] AIMBOT --> [ON] <--
		std::cout << str << std::endl << std::endl;
	}
	std::cout << "[Insert]\tExit" << std::endl;
}

void TrainerMenu::updateMenu(DWORD& game, const wchar_t* procName)
{
	int pressKey = clock();
	int updTime = clock();

	while (!GetAsyncKeyState(VK_INSERT))
	{
		if (clock() - pressKey > 400)
		{
			if (this->gameStatus)
				for (int i = 0; i < this->features.size(); i++)
					if (GetAsyncKeyState(virtualkey[this->featuresKey.at(i)]))
					{
						pressKey = clock();
						this->featuresStatus.at(i) = true;
						this->features.at(i); // вызов функции
						drawMenu();
					}
		}
		else
		{
			if (clock() - updTime > 100)
				game = mem.getProcess(procName); game != 0 ? this->gameStatus = true : this->gameStatus = false; updTime = clock(); drawMenu();
		}
	}
}