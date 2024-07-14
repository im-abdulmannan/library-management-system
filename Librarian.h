#pragma once

#include <string>
#include "User.h"

class Librarian
{
private:
    string password = "ADMIN_PASSWORD";
    bool authenticateLibrarian();

public:
    void addBook();
    void updateBook();
    void removeBook();
};