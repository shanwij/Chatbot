#include "bot.h"
#include "question.h"
#include <iostream>
#include <cctype>  // for tolower()

int main()
{
    bot botInstance;
    bool loop = true;
    std::string userInput;

    while (loop) {
        std::cout << "Hello! What would you like to ask me today?" << std::endl;
        std::getline(std::cin, userInput);

        // Convert user input to lowercase
        for (char& c : userInput) {
            c = std::tolower(c);
        }

        if (botInstance.isQuestion(userInput)) {
            if (botInstance.check(userInput)) {
                botInstance.reply(userInput);
            } else {
                botInstance.storeNewQuestion(userInput);
            }
        } else {
            std::cout << "Oops! Your question seems incomplete. Remember, correct questions should end with a '?'." << std::endl;
        }

        std::cout << "Press Enter to continue..." << std::endl;
        std::cin.get();  // Wait for user to press Enter
        system("cls");  // Clear screen (optional, works in Windows)
    }

    return 0;
}