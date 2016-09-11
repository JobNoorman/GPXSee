#ifndef SCALEITEM_H
#define SCALEITEM_H

#include <QGraphicsItem>
#include "units.h"

class ScaleItem : public QGraphicsItem
{
public:
	ScaleItem(QGraphicsItem *parent = 0);

	QRectF boundingRect() const {return _boundingRect;}
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
	  QWidget *widget);

	void setZoom(int z);
	void setZoom(int z, qreal lat);
	void setUnits(enum Units units);

private:
	void updateBoundingRect();
	void computeScale();
	QString units() const;

	int _zoom;
	qreal _lat;
	qreal _width;
	qreal _length;
	Units _units;
	bool _scale;

	QRectF _boundingRect;
};

#endif // SCALEITEM_H
