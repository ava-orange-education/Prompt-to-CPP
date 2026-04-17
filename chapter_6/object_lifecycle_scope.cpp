/*
 * Copyright (C) 2026
 * Author: Vivek Bhadra
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
// object_lifecycle_scope.cpp
// This file demonstrates the lifecycle of objects in C++ using constructors and destructors.
// It shows how objects can be created and destroyed automatically when they go out of scope.
// The example includes a class that simulates a database connection, showing how resources are managed.
#include <iostream>
#include <string>

class DatabaseConnection
{
  private:
    std::string dbName;

  public:
    // Constructor
    DatabaseConnection(const std::string &name) : dbName(name)
    {
        std::cout << "[ctor] Connecting to database: " << dbName << "\n";
    }

    // Destructor
    ~DatabaseConnection()
    {
        std::cout << "[dtor] Disconnecting from database: " << dbName << "\n";
    }

    void query(const std::string &sql)
    {
        std::cout << "Executing query on " << dbName << ": " << sql << "\n";
    }
};

int main()
{
    std::cout << "Program start\n";

    {
        DatabaseConnection conn1("MainDB");
        conn1.query("SELECT * FROM users");

        {
            DatabaseConnection conn2("AnalyticsDB");
            conn2.query("SELECT COUNT(*) FROM visits");
        } // conn2 goes out of scope here — destructor runs

    } // conn1 goes out of scope here — destructor runs

    std::cout << "Program end\n";
    return 0;
}
