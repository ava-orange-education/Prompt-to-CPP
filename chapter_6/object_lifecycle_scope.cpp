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
