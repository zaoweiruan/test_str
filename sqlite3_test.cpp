/*
 * sqlite3_test.cpp
 *
 *  Created on: 2024年10月14日
 *      Author: dsm
 */
#include <iostream>
#include <sstream>
#include <sqlite3.h>
#include <iomanip>
using namespace std;
static int titleWith=16;
static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   if (*((bool*)data)) {
	   *((bool*)data)=false;
	   stringstream title;

	   for(i=0; i<argc; i++){
		   //title<<azColName[i]<<"\t";
		   title<<setw(titleWith) << setiosflags(ios::left) <<setfill(' ') << azColName[i];
	  }
   cout<< title.str()<<endl;
   }
   stringstream row;
   for(i=0; i<argc; i++){

	   row<<setw(titleWith) << setiosflags(ios::left) <<setfill(' ') <<(argv[i] ? argv[i] : " ");
   }
   cout<<row.str()<<endl;
   return 0;
}
int main(int argc, char* argv[])
{
	   sqlite3 *db;
	   char *zErrMsg = 0;
	   int rc;
	   //char *sql;
	   const char* data = "Callback function called";
	   bool titleflag=true;

   rc = sqlite3_open("E:/mvnworkspace/python/二期诊断接口轮询/broadband_users_t.db", &db);


   /* Execute SQL statement */
   string sql = "SELECT rowid,* from fttr_all_user limit 10";
   rc = sqlite3_exec(db, sql.c_str(), callback, (void*)&titleflag, &zErrMsg);
   if (!zErrMsg)
   {
	   cout<<zErrMsg<<endl;
	   sqlite3_free(zErrMsg);
	   return 1;
   }
   if( rc != SQLITE_OK ){
      cout<<"SQL error: "<<zErrMsg<<endl;
      sqlite3_free(zErrMsg);
   }else{
	   cout<<"Operation done successfully\n"<<endl;
   }
   sqlite3_close(db);
   return 0;

}




