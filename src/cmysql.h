/*
	Copyright (C) 2003-2005 Daniel Muller, dan at verliba dot cz
	Copyright (C) 2006-2014 Verlihub Project, devs at verlihub-project dot org

	Verlihub is free software; You can redistribute it
	and modify it under the terms of the GNU General
	Public License as published by the Free Software
	Foundation, either version 3 of the license, or at
	your option any later version.

	Verlihub is distributed in the hope that it will be
	useful, but without any warranty, without even the
	implied warranty of merchantability or fitness for
	a particular purpose. See the GNU General Public
	License for more details.

	Please see http://www.gnu.org/licenses/ for a copy
	of the GNU General Public License.
*/

#ifndef CMYSQL_H
#define CMYSQL_H
#if ! defined _WIN32
//#include <mysql/mysql.h>
#else
typedef unsigned int SOCKET;
#endif
#include <mysql.h>
#include "cobj.h"

namespace nVerliHub {
/**
   Mysql utilities
   Contains classes that encapsulate mysql structures,  and ease their usage
*/
	namespace nMySQL {

/**
a class encapsulating operations with mysql conenction

@author Daniel Muller
*/
class cMySQL : public cObj
{
	friend class cQuery;
	public:
		cMySQL();
		cMySQL(string&host,string&user,string&pass,string&data);
		~cMySQL();
		void Init();
		bool Connect(string &host, string &user, string &passwd, string &db);
		string GetDBName()
		{
			return mDBName;
		}
		public: void Error(int level, string text);

	private:
		string mDBName;
		MYSQL *mDBHandle;
};
	}; // namespace nMySQL
}; // namespace nVerliHub
#endif