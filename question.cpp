#include "question.h"

question::question() : query(""), answer("") {}

question::question(const std::string& question, const std::string& answer)
    : query(question), answer(answer) {}

std::string question::m_getQuery() const
{
    return query;
}

std::string question::m_getAnswer() const
{
    return answer;
}

question::~question() {}