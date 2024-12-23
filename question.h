#pragma once
#include <string>

class question {
public:
    question();                                        // Default constructor
    question(const std::string& question, const std::string& answer); // Parameterized constructor

    std::string m_getQuery() const;                    // Get the question text
    std::string m_getAnswer() const;                   // Get the answer text

    ~question();                                       // Destructor

private:
    std::string query;                                 // Stores the question
    std::string answer;                                // Stores the answer
};