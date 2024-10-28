#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio> // For remove()
#ifdef _WIN32
#define EXECUTABLE_NAME "player_code.exe"
#else
#define EXECUTABLE_NAME "./player_code"
#endif

using namespace std;

void checkCode(std::string playerCode)
{
    // Save the player's code to a file
    std::ofstream outFile("player_code.cpp");
    outFile << playerCode;
    outFile.close();

    // Compile the code
    int result = system("g++ player_code.cpp -o player_code");

    if (result != 0)
    {
        std::cout << "Syntax Error: Failed to compile the code.\n";
    }
    else
    {
        // Run the code to check for runtime errors
        result = system(EXECUTABLE_NAME);
        if (result != 0)
        {
            std::cout << "Runtime Error: Code did not run successfully.\n";
        }
        else
        {
            std::cout << "Code ran successfully. Well done!\n";
        }
    }
}

int main()
{
    remove(EXECUTABLE_NAME);
    std::string playerCode = R"(
    #include <iostream>
    int main() {
        int x = 10;
        std::cout << x << std::endl;
        return 0;
    }
    )";

    checkCode(playerCode);
    return 0;
}
