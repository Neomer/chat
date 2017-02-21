#include <QCoreApplication>
#include "core/CDebug.h"
#include "core/CServer.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	
	dc;
	
	CServer srv(&a);
	srv.start();
	
	return a.exec();
}

