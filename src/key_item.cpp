#include "key_item.h"

#include "qcolor.h"
#include "qpainter.h"
#include "qpainterpath.h"
#include "qstyleoption.h"

KeyItem::KeyItem(const int x, const int y, const QString& str)
    : m_x(x), m_y(y), m_str(str) {
  this->setX(x);
  this->setY(y);
  setFlags(ItemIsSelectable | ItemIsMovable);
  setAcceptHoverEvents(true);
}

KeyItem::~KeyItem() {}

QRectF KeyItem::boundingRect() const { return QRectF(0, 0, 40, 40); }

QPainterPath KeyItem::shape() const {
  QPainterPath path;
  path.addRect(0, 0, 35, 35);
  return path;
}

void KeyItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                    QWidget* widget) {
  QColor fill_color =
      (option->state & QStyle::State_Selected) ? m_color.darker(150) : m_color;
  if (option->state & QStyle::State_MouseOver) {
    fill_color = m_color.lighter(150);
  }
  painter->fillRect(QRectF(0, 0, 40, 40), fill_color);
  const qreal lod =
      option->levelOfDetailFromTransform(painter->worldTransform());
  if (lod < 0.2) {
    if (lod < 0.125) {
      painter->fillRect(QRectF(0, 0, 40, 40), fill_color);
      return;
    }
    QBrush b = painter->brush();
    painter->setBrush(fill_color);
    painter->drawRect(5, 5, 35, 35);
    painter->setBrush(b);
    return;
  }

  // QPen old_pen = painter->pen();
  // QPen pen = old_pen;
  // int width = 0;
  // if (option->state & QStyle::State_Selected) {
  //   width += 2;
  // }
  // pen.setWidth(width);
  // QBrush b = painter->brush();
  // painter->setBrush(QBrush(
  //     fill_color.darker(option->state & QStyle::State_Sunken ? 120 : 100)));
  // painter->drawRect(10, 10, 60, 60);
  // painter->setBrush(b);
  if (lod >= 1) {
    painter->setPen(QPen(Qt::gray, 1));
    painter->drawText(15, 25, m_str);
  }
  int x = this->x();
  int y = this->y();
}

void KeyItem::mousePressEvent(QGraphicsSceneMouseEvent* e) {
  QGraphicsItem::mousePressEvent(e);
  update();
}

void KeyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* e) {
  QGraphicsItem::mouseReleaseEvent(e);
  update();
}

void KeyItem::mouseMoveEvent(QGraphicsSceneMouseEvent* e) {
  QGraphicsItem::mouseMoveEvent(e);
  update();
}
