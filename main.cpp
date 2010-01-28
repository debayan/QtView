#include <QApplication>
#include "dropSiteWindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	DropSiteWindow window(app);
	window.show();
	return app.exec();
}

