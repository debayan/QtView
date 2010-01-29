//#include "dropArea.h"
#include <QtGui>
#include "dropSiteWindow.h"
#include "dropArea.h"

DropSiteWindow::DropSiteWindow(const QApplication &app)
{
	dropArea = new DropArea;
	Ui_Form imageViewerUi;
	imageViewerUi.setupUi(this);

	connect( imageViewerUi.pushButton_5, SIGNAL(clicked()), this, SLOT(zoomInView()) );
    connect( imageViewerUi.pushButton, SIGNAL(clicked()), this, SLOT(zoomOutView()) );
    connect( imageViewerUi.pushButton_10, SIGNAL(clicked()), this, SLOT(panLeftView()) );
    connect( imageViewerUi.pushButton_8, SIGNAL(clicked()), this, SLOT(panRightView()) );
    connect( imageViewerUi.pushButton_3, SIGNAL(clicked()), this, SLOT(panUpView()) );
    connect( imageViewerUi.pushButton_7, SIGNAL(clicked()), this, SLOT(panDownView()) );
    connect( imageViewerUi.pushButton_4, SIGNAL(clicked()), this, SLOT(rotateAntiClockwiseView()) );
    connect( imageViewerUi.pushButton_6, SIGNAL(clicked()), this, SLOT(rotateClockWiseView()) );
    connect( imageViewerUi.pushButton_2, SIGNAL(clicked()), &app, SLOT(quit()));
    connect( imageViewerUi.pushButton_9, SIGNAL(clicked()), dropArea, SLOT(clearView()));

	
	abstractLabel = new QLabel(tr("Drop an Image below"));
	abstractLabel->setMaximumHeight(20);
	abstractLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	
	imageViewerUi.verticalLayout_2->addWidget(abstractLabel);
	imageViewerUi.verticalLayout_2->addWidget(dropArea);

	setWindowTitle(tr("Drop Site"));
    setMinimumSize(350, 500);
}

