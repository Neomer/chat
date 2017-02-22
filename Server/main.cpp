#include <QCoreApplication>
#include "core/CDebug.h"
#include "core/CServer.h"
#include <core/CDatabase.h>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	
	dc;
	
	CDatabase db(&a);
	db.open("test");
	
	CServer srv(&a);
	srv.start();
	
	return a.exec();
}

