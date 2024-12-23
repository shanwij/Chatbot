# A simple chatbot written in c++

The bot is an interactive question-and-answer system that allows users to ask questions and receive responses. It operates as follows:

# Answering Known Questions:

If the bot knows the answer to a user's question, it immediately provides the answer.

# Learning New Questions:

- If the bot does not know the answer:
- It prompts the user to provide an answer.
- The new question-and-answer pair is stored in the bot's memory for future use.

# Persistent Learning:

- The bot saves all new questions and answers to a file, ensuring that knowledge is retained even after the program is closed.
- This design enables the bot to continuously expand its knowledge base while interacting with users.

# To run
- g++ main.cpp question.cpp bot.cpp -o main
- main.exe


