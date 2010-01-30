#ifndef DROPSITEWINDOW_H
#define DROPSITEWINDOW_H

#include <QWidget>
#include <QFileDialog>
#include "dropArea.h"
#include "ui_imageViewer.h"

class QDialogButtonBox;
class QLabel;
class QPushButton;
class QVBoxLayout;
class Ui_Form;


class DropSiteWindow : public QWidget, public Ui_Form
{
	Q_OBJECT
public:
	DropSiteWindow(const QApplication &);
private slots:
	void zoomInView()
	{
		dropArea->scaleView(1.2);
	}
	void zoomOutView()
	{
		dropArea->scaleView(0.8);
	}
	void panLeftView()
	{
		dropArea->translateView(-5, 0);
	}
	void panRightView()
	{
		dropArea->translateView(5, 0);
	}
	void panUpView()
	{
		dropArea->translateView(0, 5);
	}
	void panDownView()
	{
		dropArea->translateView(0, -5);
	}
	void rotateAntiClockwiseView()
	{
		dropArea->rotateView(-5);
	}
	void rotateClockWiseView()
	{
		dropArea->rotateView(5);
	}
	void openFile()
	{
		QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "~", tr("Image Files (*.png *.jpg *.bmp)"));
		dropArea->openFile(fileName);
	}
private:
	QPushButton *zoomIn;
	QPushButton *zoomOut;
	QPushButton *panLeft;
	QPushButton *panRight;
	QPushButton *panUp;
	QPushButton *panDown;
	QPushButton *rotateAntiClockwise;
	QPushButton *rotateClockWise;
	QPushButton *quit;
	QPushButton *clear;
	QLabel *abstractLabel;
	DropArea *dropArea;
	QVBoxLayout *mainLayout;
};

#endif
