#pragma once
#include <list>
#include <fstream>
#include <iostream>
#include <string>

#include "question.h"

class bot {
public:
    bot();                                      // Constructor to initialize the bot and load questions
    bool isQuestion(const std::string& input) const; // Check if the input ends with a '?'
    bool check(const std::string& input) const;      // Check if the question exists in the list
    void reply(const std::string& input) const;      // Reply with the answer to a question
    void storeNewQuestion(const std::string& input); // Store a new question-answer pair
    ~bot();                                     // Destructor

private:
    std::list<question> questionList;           // List to store questions and answers
};