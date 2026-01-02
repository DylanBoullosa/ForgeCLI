
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
		//Create src/, include/, assets/
		std::filesystem::path projectPath = projectName;
		std::filesystem::create_directory(projectPath);

		std::filesystem::create_directory(projectPath / "src");
		std::filesystem::create_directory(projectPath / "include");

		if (buildType == 2) {
			std::filesystem::create_directory(projectPath / "assets");
		}
		std::cout << "Project structure created successfully\n";

		// Generate src/main.cpp
		std::filesystem::path mainCppPath = projectPath / "src" / "main.cpp";
		std::ofstream mainFile(mainCppPath);

		if (!mainFile) {
			std::cout << "Error: Could not create main.cpp\n";
			return 1;
		}
		//Console application	
		if (buildType == 1) {
			mainFile <<
				"#include <iostream>\n\n"
				"int main(){\n"
				"     std::cout << \"Hello from your C++ Console Application!\" << std::endl;\n "
				"     return 0;\n"
				"}\n";
		}

		//Game Prototype
		if (buildType == 2) {
			mainFile <<
				"include <iostream<\n\n"
				"void init();\n"
				"void gameLoop();\n"
				"void shutdown();\n\n"
				"int main() {\n"
				"    init();\n"
				"    gameLoop();\n"
				"    shutdown();\n"
				"    return 0;\n"
				"}\n\n"
				"void init() {\n"
				"    std::cout << \"Initializing game...\" << std::endl;\n"
				"}\n\n"
				"void gameLoop() {\n"
				"    std::cout << \"Running game loop...\" << std::endl;\n"
				"}\n\n"
				"void shutdown() {\n"
				"    std::cout << \"Shutting down game.\" << std::endl;\n"
				"}\n";
		}
		//Developer Tool
		else {
			mainFile <<
				"#include <iostream>\n\n"
				"int main(int argc, char* argv[]) {\n"
				"    std::cout << \"Developer tool started.\" << std::endl;\n"
				"    return 0;\n"
				"}\n";
		}

		mainFile.close();
		std::cout << "generate src/main.cpp successfully.\n";

		std::filesystem::path readmePath = projectPath / "README.md";
		std::ofstream readmeFile(readmePath);

		if (!readmeFile) {
			std::cout << "Error: Could not create README.md\n";
			return 1;
		}
		//Title
		readmeFile << "# " << projectName << "\n\n";

		//Description based on title
		if (buildType == 1) {
			readmeFile << "A C++ console application generated using ForgeCLI.\n\n";
			return 1;			
		}
		else if (buildType == 2) {
			readmeFile << "A C++ game prototype generated using ForgeCLI.\n\n";
		}
		else {
			readmeFile << "A C++ developer tool generated using ForgetCLI.\n\n";
		}

		//Structure section
		readmeFile << "## Project Structure\n";
		readmeFile << "```\n";
		readmeFile << projectName << "/\n";
		readmeFile << "├── src/\n";
		readmeFile << "│   └── main.cpp\n";
		readmeFile << "├── include/\n";

		if (buildType == 2) {
			readmeFile << "├── assets/\n";
		}
		readmeFile << "└── README.md\n";
		readmeFile << "```\n\n";

		//Footer
		readmeFile << "Generated with **ForgeCLI**.\n";

		readmeFile.close();
		std::cout << "Generated README.md successfully.\n";

	return 0;
}