
#include <iostream>
#include <filesystem>
#include <fstream>
#include <limits>
#include <string>

int main() {
	//Introduction
	std::cout << "==============================\n";
	std::cout << "           ForgeCLI           \n";
	std::cout << "==============================\n";
	//Choose Build Type
	std::cout << "What are you building today?\n";
	std::cout << "1) C++ Console Application\n";
	std::cout << "2) C++ Game Protoype\n";
	std::cout << "3) C++ Developer Tool\n";
	std::cout << "Select an option (1-3): ";

	int buildType;
	std::cin >> buildType;

	while (buildType < 1 || buildType > 3) {
		std::cout << "Invalid choice> Please Select 1,2 or 3: \n";
		std::cin >> buildType;
	}
		if (buildType == 1) {
			std::cout << "C++ Console Application\n";
		}
		else if (buildType == 2) {
			std::cout << " C++ Game Protoype\n";
		}
		else {
			std::cout << "C++ Developer Tool\n";
		}

		//Project Name
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		bool hasProjectName = false;
		std::string projectName;
		
		while (!hasProjectName) {
			std::cout << "Enter a project name: ";
			std::getline(std::cin, projectName);

			if (!projectName.empty()) {
				hasProjectName = true;
			}
			else {
				std::cout << "Project name cannot be empty\n";
			}
		}


	return 0;
}