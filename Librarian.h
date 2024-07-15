#pragma once

#include <string>

class Librarian
{
private:
    std::string password = "ADMIN_PASSWORD";

public:
    bool authenticateLibrarian();
    void addBook();
    void updateBook();
    void removeBook();
};
