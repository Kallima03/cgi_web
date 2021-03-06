#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>
#include <mysql/mysql.h>
#include <ctime>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

class Database {  
  private:
	static Database* instance;
	MYSQL *connection;
	Database(); 
	void finish_with_error();
	void addLog(string str);
	int fd;
	time_t t;
  public:
	~Database();
	static Database* getInstance();
	bool dbCreateTable(string &);
	bool dbInsert(unordered_map<string,string> & data,string & table);
	bool dbQuery(string &,vector<vector<string> > &);
	bool dbQuery(string &,vector<unordered_map<string,string> > &);
	int dbQuery(string &);
//	int  dbAggrQuery(string &);
};
