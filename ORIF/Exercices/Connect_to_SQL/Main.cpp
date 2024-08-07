// Jocelin Thumelin
// 22.04.2024
// Une PME aimerait avoir une application de gestion de son personnel. Vous devez
// développer une application qui gère les horaires des différents employés et qui
// permettra de calculer le salaire en fonction des horaires mensuelles effectués.
// L’analyse des besoins de la PME est décrite comme suit :
// • Chaque employé pourra se logger sur l’application avec un email et un mot
// de passe afin d’y entrer une heure d’arrivée et son heure de départ (on ne
// tiendra pas compte des pauses).
// • Dépendamment du nombre d’heures effectuées, l’application pourra calculer
// et affichez le nombre d’heures effectué par jour, par semaine et par mois.
// • L’application pourra calculer et afficher le salaire brut de chaque employé par
// mois sachant qu’une heure de travail est fixée à 38 CHF
// • Il sera possible en fin d’année d’avoir la liste de tous les salaires annuels des
// employés
// Modélisez et concevez une base de données à accès restreinte pour
// répondre à la problématique de cette PME, puis développer une application
// que vous connecterez à votre base de données.
#include <iostream>
#include <stdlib.h>
#include <mysqlx/xdevapi.h>

// Connect to DB
#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_error.h>

#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/prepared_statement.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>


using namespace std;

// For demonstration only. Never save your password in the code!
const string server = "tcp://127.0.0.1:3306";
const string username = "root";
const string password = "";

int main() {
    cout << "\nLet's have MySQL count from 10 to 1...\n";

    try {
        sql::mysql::MySQL_Driver *driver;
        unique_ptr<sql::Connection> con;
        unique_ptr<sql::Statement> stmt;
        unique_ptr<sql::ResultSet> res;
        unique_ptr<sql::PreparedStatement> pstmt;

        /* Create a connection */
        driver = sql::mysql::get_mysql_driver_instance();
        con.reset(driver->connect(server, username, password));
        /* Connect to the MySQL test database */
        con->setSchema("test");

        stmt.reset(con->createStatement());
        stmt->execute("DROP TABLE IF EXISTS test");
        stmt->execute("CREATE TABLE test(id INT)");

        /* '?' is the supported placeholder syntax */
        pstmt.reset(con->prepareStatement("INSERT INTO test(id) VALUES (?)"));
        for (int i = 1; i <= 10; i++) {
            pstmt->setInt(1, i);
            pstmt->executeUpdate();
        }

        /* Select in ascending order */
        pstmt.reset(con->prepareStatement("SELECT id FROM test ORDER BY id ASC"));
        res.reset(pstmt->executeQuery());

        /* Fetch in reverse = descending order */
        res->afterLast();
        while (res->previous())
            cout << "\t... MySQL counts: " << res->getInt("id") << endl;

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        return EXIT_FAILURE;
    }

    cout << endl;
    return EXIT_SUCCESS;
}






