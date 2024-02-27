#include "key_item.h"

#include "qpainter.h"
#include "qstyleoption.h"
#include "qcolor.h"
#include "qpainterpath.h"
#include "qpainter.h"

KeyItem::KeyItem(const int x, const int y, const QString& str)
    : m_x(x), m_y(y), m_str(str) {}

KeyItem::~KeyItem() {}

QRectF KeyItem::boundingRect() const { return QRectF(0, 0, 80, 80); }

QPainterPath KeyItem::shape() const {
  QPainterPath path;
  path.addRect(10, 10, 60, 60);
  return path;
}

void KeyItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                    QWidget* widget) {
  QColor fill_color =
      (option->state & QStyle::State_Selected) ? m_color.darker(150) : m_color;
  if (option->state & QStyle::State_MouseOver) {
    fill_color = m_color.lighter(150);
  }
  const qreal lod =
      option->levelOfDetailFromTransform(painter->worldTransform());
  if (lod < 0.2) {
    if (lod < 0.125) {
      painter->fillRect(QRectF(0, 0, 80, 80), fill_color);
      return;
    }
    QBrush b = painter->brush();
    painter->setBrush(fill_color);
    painter->drawRect(10, 10, 60, 60);
    painter->setBrush(b);
    return;
  }

  QPen old_pen = painter->pen();
  QPen pen = old_pen;
  int width = 0;
  if (option->state & QStyle::State_Selected) {
    width += 2;
  }
  pen.setWidth(width);
  QBrush b = painter->brush();
  painter->setBrush(QBrush(
      fill_color.darker(option->state & QStyle::State_Sunken ? 120 : 100)));
  painter->drawRect(10, 10, 60, 60);
  painter->setBrush(b);
  if (lod > 1) {
    painter->setPen(QPen(Qt::gray, 1));
    painter->drawText(25, 25, m_str);
  }
}

void KeyItem::mousePressEvent(QGraphicsSceneMouseEvent* e) {}

void KeyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* e) {}

void KeyItem::mouseMoveEvent(QGraphicsSceneMouseEvent* e) {}
