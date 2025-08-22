#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>

int main() {
    try {
        sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();
        sql::Connection *con = driver->connect("tcp://127.0.0.1:3306", "root", "mysql123");
        con->setSchema("Testing");

        sql::PreparedStatement *pstmt = con->prepareStatement(
            "INSERT INTO Temp (id, name, login_status) VALUES (?, ?, ?)");
        pstmt->setInt(1, 4);
        pstmt->setString(2, "Diana");
        pstmt->setString(3, "Inserted Through C++");
        pstmt->execute();

        std::cout << "Inserted into database.\n";
        delete pstmt;
        delete con;
    } catch (sql::SQLException &e) {
        std::cerr << "SQL error: " << e.what() << std::endl;
    }
}