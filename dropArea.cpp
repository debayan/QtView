#include "dropArea.h"
#include <QDebug>
#include <QDragEnterEvent>
#include <QDragMoveEvent> 
#include <QDragLeaveEvent>
#include <QDropEvent>
#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>

DropArea::DropArea() :  isCtrlPressed(false)
{
	scene = new QGraphicsScene(this);
	setScene(scene);
	messageItem = scene->addText(tr("Drop an image here"));
	pixmapItem = new QGraphicsPixmapItem(0,scene);
	setTransformationAnchor(QGraphicsView::NoAnchor);
	setDragMode(QGraphicsView::ScrollHandDrag);
	pixmap = new QPixmap;
}

void DropArea::dragEnterEvent(QDragEnterEvent *event)
{
	QString fileName = event->mimeData()->text();
    thread = new Thread(this);
	connect( thread, SIGNAL(finished()), this, SLOT(imageLoadingStatus()) );

    updateSceneWithText(tr("Trying to determine if this a valid image...."));
    int length = fileName.size();
    if (!fileName.isNull())
    {
        fileName = fileName.trimmed();
        fileName = fileName.right(length - 9); // file:// has 7 chars
        thread->setFileName(fileName);
        thread->start();
    }
    else
    {
        updateSceneWithText(tr("The file name could not be read"));
    }
    event->acceptProposedAction();
}

void DropArea::dragMoveEvent(QDragMoveEvent *event)
{
	event->acceptProposedAction(); 
}

void DropArea::dragLeaveEvent(QDragLeaveEvent *event)
{
	thread->wait();
	delete thread;
	event->accept();
	updateSceneWithText(tr("This is the Drop Site"));
}

void DropArea::dropEvent(QDropEvent *event)
{
	if ( thread->isItAnImage() )
	{
		delete thread; 
		updateSceneWithImage(); 
	}
	event->acceptProposedAction();
}


void DropArea::updateSceneWithText(QString messageOnEvent)
{
	pixmapItem->hide();
	messageItem->setPlainText(messageOnEvent);
	messageItem->show();
}

void DropArea::updateSceneWithImage()
{
	resetTransform();
	messageItem->hide();
	pixmapItem->show();
	pixmapItem->setPixmap(*pixmap);
}

void DropArea::imageLoadingStatus()
{
	if ( thread->isItAnImage() )
	{
		updateSceneWithText(tr("Looks like a valid image. Drop it"));
		*pixmap = pixmap->fromImage(*thread->image);
		
	}
	else
	{
		updateSceneWithText(tr("Does not seem to be a valid image"));
	}
	delete thread->image;
}

void DropArea::keyPressEvent(QKeyEvent *event)
{
	switch( event->key() ){
	case( Qt::Key_Plus ):
		scaleView(1.2);
		break;

	case ( Qt::Key_Minus ):
		scaleView(0.8);
		break;
		
	case ( Qt::Key_Right ):
		 if ( isCtrlPressed )                                                   
        {
			rotateView(5);
            break;                                                             
        }
        else                                                                   
        {
			translateView(5, 0);
			break;
        }

	case ( Qt::Key_Left ):
		if ( isCtrlPressed )
        {
            rotateView(-5);
            break;
        }
        else
        {
			translateView(-5, 0);
            break;
        }
	
	 case ( Qt::Key_Up ):
        if ( isCtrlPressed )
        {
            scaleView(1.2); 
            break;
        }
        else
        {
			translateView(0, 5);
            break;
        }
		
		case ( Qt::Key_Down ):
		if ( isCtrlPressed )
		{
			scaleView(0.8); 
			break;
		}
		else
		{
			translateView(0, -5);
			break;
		}
		
	case ( Qt::Key_Control ):
		isCtrlPressed = true;
		break;
	}
}

void DropArea::rotateView(qreal degrees)
{
	setTransformationAnchor(QGraphicsView::AnchorViewCenter);
	rotate(degrees);
	setTransformationAnchor(QGraphicsView::NoAnchor);	
}

void DropArea::scaleView(qreal scaleFactor)
{
	scale( scaleFactor, scaleFactor );
}

void DropArea::translateView(qreal xPixels, qreal yPixels)
{
	translate( xPixels, yPixels );
}

void DropArea::clearView()
{
	resetTransform();
    updateSceneWithText(tr("Drop an image here"));
}

void DropArea::keyReleaseEvent(QKeyEvent *event)
{
	switch( event->key() ){
	case ( Qt::Key_Control ):
		isCtrlPressed = false;
		break;
	}
}

void DropArea::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2, -event->delta() / 240.0));
}

void Thread::setFileName(QString fileName)
{
	imageFileName = fileName;
}

Thread::Thread(DropArea *parent) : isImage(false)
{
	image = new QImage;
}

void Thread::run()
{
	bool didItLoad = image->load(imageFileName);
	if ( didItLoad )
	{ isImage = true; }
	else
	{ isImage = false; }
}

bool Thread::isItAnImage()
{
	if ( isImage ) return true;
	else
		return false;
}

