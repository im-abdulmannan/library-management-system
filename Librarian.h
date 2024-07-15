#pragma once

#include <string>
#include "User.h"

class Librarian
{
private:
    string password = "ADMIN_PASSWORD";

public:
    bool authenticateLibrarian();
    void addBook();
    void updateBook();
    void removeBook();
};
