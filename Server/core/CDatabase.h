#ifndef CDATABASE_H
#define CDATABASE_H

#include <QObject>
#include <postgresql/libpq-fe.h>

class CDatabase : public QObject
{
	Q_OBJECT
public:
	explicit CDatabase(QObject *parent = 0);
	
	bool isOpen();
	bool isClosed();	
	
	bool open(QString dbname);
	void close();
	
	void setHost(QString value) { _dbhost = value; }
	QString host() { return _dbhost; }
	
	void setPassword(QString value) { _dbpass = value; }
	QString password() { return _dbpass; }
	
	void setUser(QString value) { _dbuser = value; }
	QString user() { return _dbuser; }
	
	void setPort(QString value) { _dbport = value; }
	QString port() { return _dbport; }
	
signals:
	
public slots:
	
private:
	PGconn *_db;
	QString _dbhost, _dbpass, _dbuser, _dbport;
};

#endif // CDATABASE_H
