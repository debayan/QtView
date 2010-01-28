#ifndef DROPAREA_H
#define DROPAREA_H
#include <QtGui/QGraphicsView>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <math.h>


class DropArea : public QGraphicsView
{
	Q_OBJECT
public:
	DropArea();

public slots:
	void rotateView(qreal degrees);
	void translateView(qreal xPixels, qreal yPixels);
	void scaleView(qreal scaleFactor);
	void clearView();

protected:
	void dragEnterEvent(QDragEnterEvent *event);
	void dragLeaveEvent(QDragLeaveEvent *event);
	void dragMoveEvent(QDragMoveEvent *event);
	void dropEvent(QDropEvent *event);
	void updateSceneWithText(QString messageOnEvent);
	void updateSceneWithImage();
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);
	void wheelEvent(QWheelEvent *event);
private:
	QPixmap image;
	bool isCtrlPressed;
	QGraphicsScene *scene;
	QGraphicsTextItem *messageItem;
	QGraphicsPixmapItem *pixmapItem;
};

#endif
