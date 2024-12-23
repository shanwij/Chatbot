#pragma once
#include "bot.h"
#include <fstream>
#include <iostream>

bot::bot()
{
    std::ifstream inputFile("QA.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::string tmpQ; // temporarily stores questions from text file
    std::string tmpA; // temporarily stores answers from text file

    while (std::getline(inputFile, tmpQ, ';') && std::getline(inputFile, tmpA)) {
        question questionObj(tmpQ, tmpA); // create a question object
        questionList.push_back(questionObj); // store the object in the list
    }

    inputFile.close();
}

bool bot::isQuestion(const std::string& input) const
{
    return !input.empty() && input.back() == '?';
}

bool bot::check(const std::string& input) const
{
    for (const auto& q : questionList) {
        if (input == q.m_getQuery()) {
            return true;
        }
    }
    return false;
}

void bot::reply(const std::string& input) const
{
    for (const auto& q : questionList) {
        if (input == q.m_getQuery()) {
            std::cout << q.m_getAnswer() << std::endl;
            return;
        }
    }
}

void bot::storeNewQuestion(const std::string& input)
{
    std::string tmp;
    std::cout << "That's an interesting question! Could you help me by providing the answer?" << std::endl << input << std::endl;
    std::getline(std::cin, tmp); // ask user to answer the question

    question new_query(input, tmp); // create new question-answer object
    questionList.push_back(new_query); // store it in the list

    std::ofstream outputFile("QA.txt", std::ios::app);
    if (outputFile.is_open()) {
        outputFile << "\n" << input << ";" << tmp;
        outputFile.close();
    } else {
        std::cerr << "Error, file didn't open." << std::endl;
    }
}

bot::~bot()
{
    // Destructor, no specific cleanup needed as std::list handles memory management automatically
}