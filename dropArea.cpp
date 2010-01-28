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
}

void DropArea::dragEnterEvent(QDragEnterEvent *event)
{
	QString fileName = event->mimeData()->text();                            
    int length = fileName.size();                                            
    if (!fileName.isNull())                                                  
    {                                                                        
		fileName = fileName.trimmed();                                       
		fileName = fileName.right(length - 7); // file:// has 7 chars        
		QPixmap image(fileName);                                             
			if (image.isNull()) {                                            
				updateSceneWithText(tr("This does not seem to be a valid file"));
				event->acceptProposedAction();
				return;                                                      
			}
		updateSceneWithText(tr("Looks like an image. Drop it."));
		event->acceptProposedAction();
    }                                                                        
    else                                                                     
    {                                                                        
		updateSceneWithText(tr("The file name could not be read"));
    }          
}

void DropArea::updateSceneWithText(QString messageOnEvent)
{
	pixmapItem->hide();
	messageItem->setPlainText(messageOnEvent);
	messageItem->show();
}

void DropArea::updateSceneWithImage()
{
	pixmapItem->show();
	messageItem->hide();
	pixmapItem->setPixmap(image);
}

void DropArea::dragMoveEvent(QDragMoveEvent *event)
{
	event->acceptProposedAction(); 
}

void DropArea::dragLeaveEvent(QDragLeaveEvent *event)
{
	event->accept();
	updateSceneWithText(tr("This is the Drop Site"));
}

void DropArea::dropEvent(QDropEvent *event)
{
	QString fileName = event->mimeData()->text();
	int length = fileName.size();
	if (!fileName.isNull())
	{
		fileName = fileName.trimmed();
		fileName = fileName.right(length - 7); // file:// has 7 chars
		image.load(fileName);
			if (image.isNull()) {
				updateSceneWithText(tr("This does not seem to be a valid file"));
				return;
			}
		updateSceneWithImage();
		event->acceptProposedAction();
	}
	else
	{
		updateSceneWithText(tr("The file name could not be read"));
	}
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
	qDebug() << event->delta();
    scaleView(pow((double)2, -event->delta() / 240.0));
}

