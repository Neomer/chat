#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <core/CDebug.h>
#include <core/CClient.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public CBusListener
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	
private slots:
	void sendMessage();
	void appendMessage(QString text);
	
private:
	Ui::MainWindow *ui;
	CClient *_client;
	
	// CBusListener interface
protected:
	void onBusEvent(CBusListener *sender, qint16 eventId, QVariant data);
};

#endif // MAINWINDOW_H
