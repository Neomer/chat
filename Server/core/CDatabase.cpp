#include "CDatabase.h"

CDatabase::CDatabase(QObject *parent) : 
	QObject(parent),
	_dbhost("127.0.0.1"),
	_dbuser("postgres"),
	_dbpass(""),
	_dbport("5432"),
	_db(0)
{
	
}

bool CDatabase::isOpen() 
{ 
	return _db != 0; 
}

bool CDatabase::isClosed() 
{ 
	return _db == 0; 
}

bool CDatabase::open(QString dbname)
{
	if (isOpen())
	{
		
	}
	_db = PQsetdbLogin(
					_dbhost.toLatin1().constData(),
					_dbport.toLatin1().constData(),
					"",
					"",
					dbname.toLatin1().constData(),
					_dbuser.toLatin1().constData(),
					_dbpass.toLatin1().constData()
				);
}

void CDatabase::close()
{
	if (isOpen())
	{
		PQfinish(_db);
		_db = 0;
	}
}


