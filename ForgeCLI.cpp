
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
		else if (buildType == 2) {
			mainFile <<
				"#include <iostream>\n\n"
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
			std::cout << "Warning: Could not create README.md\n";
		}
		else {
			readmeFile << "# " << projectName << "\n\n";

			if (buildType == 1) {
				readmeFile << "A C++ console application generated using ForgeCLI.\n\n";
			}
			else if (buildType == 2) {
				readmeFile << "A C++ game prototype generated using ForgeCLI.\n\n";
			}
			else {
				readmeFile << "A C++ developer tool generated using ForgeCLI.\n\n";
			}

			readmeFile << "## Project Structure\n";
			readmeFile << "```\n";
			readmeFile << projectName << "/\n";
			readmeFile << "├── src/\n";
			readmeFile << "│   └── main.cpp\n";
			readmeFile << "├── include/\n";

			if (buildType == 2) {
				readmeFile << "├── assets/\n";
			}

			readmeFile << "├── README.md\n";
			readmeFile << "└── .gitignore\n";
			readmeFile << "```\n\n";

			readmeFile << "Generated with **ForgeCLI**.\n";

			readmeFile.close();
			std::cout << "Generated README.md successfully.\n";
		}

		//Generate .gitignore
		std::filesystem::path gitignorePath = projectPath / ".gitignore";
		std::ofstream gitignoreFile(gitignorePath);

		if (!gitignoreFile) {
			std::cout << "Warning: Could not create .gitignore\n";
		}
		else {
			gitignoreFile <<
				"# Build output\n"
				"build/\n"
				"*.exe\n"
				"*.out\n"
				"*.o\n\n"
				"# IDE files\n"
				".vs/\n"
				"*.vcxproj*\n"
				"*.sln\n\n"
				"# OS files\n"
				".DS_Store\n"
				"Thumbs.db\n";

			gitignoreFile.close();
			std::cout << "Generated .gitignore successfully.\n";
		}
		//git initialization
		char gitChoice;
		std::cout << "Initialize git repository? (y/n): ";
		std::cin >> gitChoice;

		if (gitChoice == 'y' || gitChoice == 'Y') {
			std::string command = "cd \"" + projectName + "\" && git init";
			system(command.c_str());
			std::cout << "Git repository initialized.\n";
		}
		else {
			std::cout << "Skipped git initialization.\n";
		}
		//Summary output
		std::cout << "\n==============================\n";
		std::cout << "ForgeCLI Complete!\n";
		std::cout << "================================\n";

		std::cout << "Project created: " << projectName << "\n";
		std::cout << "Project type: ";

		if (buildType == 1) {
			std::cout << "C++ Console Application\n";
		}
		else if (buildType == 2) {
			std::cout << "C++ Game Prototype\n";
		}
		else {
			std::cout << "C++ Developer Tool\n";
		}

		std::cout << "\nGenerated structure:\n";
		std::cout << projectName << "/\n";
		std::cout << "├── src/\n";
		std::cout << "│   └── main.cpp\n";
		std::cout << "├── include/\n";

		if (buildType == 2) {
			std::cout << "├── assets/\n";
		}

		std::cout << "├── README.md\n";
		std::cout << "└── .gitignore\n\n";

		std::cout << "Next steps:\n";
		std::cout << "- Open the project folder in your editor\n";
		std::cout << "- Start coding in src/main.cpp\n";
		std::cout << "- Initialize git if needed\n\n";

		std::cout << "Good luck!\n";

	return 0;
}