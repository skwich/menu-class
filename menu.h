#pragma once
#include "Header.h"

class TrainerMenu
{
private:
	//enums
	std::map<std::string, unsigned int> virtualkey
	{
		{"NUM0", VK_NUMPAD0},
		{"NUM1", VK_NUMPAD1},
		{"NUM2", VK_NUMPAD2},
		{"NUM3", VK_NUMPAD3},
		{"NUM4", VK_NUMPAD4},
		{"NUM5", VK_NUMPAD5},
		{"NUM6", VK_NUMPAD6},
		{"NUM7", VK_NUMPAD7},
		{"NUM8", VK_NUMPAD8},
		{"NUM9", VK_NUMPAD9},
	};

	//statements
	bool gameStatus = false;
	std::string gameName = "GAME_NOT_FOUND";
	std::vector<std::string> featuresName;
	std::vector<void*> features;
	std::vector<std::string> featuresKey;
	std::vector<bool> featuresStatus;

public:
	//functions
	void updateMenu(DWORD &game, const wchar_t* procName);
	void drawMenu();
	void addFeature(std::string funcName, void* func, std::string funcKey);
	TrainerMenu(const std::string procName);
	TrainerMenu(const std::string procName, DWORD game);
};