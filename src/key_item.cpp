#include "key_item.h"

#include "qcolor.h"
#include "qpainter.h"
#include "qpainterpath.h"
#include "qstyleoption.h"
static const int width = 50;
static const int height = 50;
KeyItem::KeyItem(const int x, const int y, const QString& str)
    : m_x(x), m_y(y), m_str(str), m_scale(1.0) {
  this->setX(x);
  this->setY(y);
  m_color.setRgb(156, 229, 134);
  setFlags(ItemIsSelectable | ItemIsMovable);
  setAcceptHoverEvents(true);
}

KeyItem::~KeyItem() {}

QRectF KeyItem::boundingRect() const {
  QRectF rect(0, 0, width, height);
  if (m_str == "Enter") {
    rect.setHeight(height * 2);
  }
  return rect;
}

QPainterPath KeyItem::shape() const {
  QPainterPath path;
  if (m_str == "Enter") {
    path.addRect(0, 0, width - 10, height * 2 - 20);
  } else {
    path.addRect(0, 0, width - 10, height - 10);
  }
  return path;
}

void KeyItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                    QWidget* widget) {
  QColor fill_color = m_color;
  if (option->state & QStyle::State_Selected) {
    //  fill_color = m_color.lighter(150);
  } else if (option->state & QStyle::State_MouseOver) {
    fill_color = m_color.darker(150);
  }
  if (m_str == "Enter") {
    painter->fillRect(QRectF(0, 0, width - 5, height * 2 - 5), fill_color);
  } else {
    painter->fillRect(QRectF(0, 0, width - 5, height - 5), fill_color);
  }

  const qreal lod =
      option->levelOfDetailFromTransform(painter->worldTransform());
  if (lod < 0.2) {
    if (lod < 0.125) {
      painter->fillRect(QRectF(0, 0, width, height), fill_color);
      return;
    }
    QBrush b = painter->brush();
    painter->setBrush(fill_color);
    painter->drawRect(5, 5, width, height);
    painter->setBrush(b);
    return;
  }

  if (lod >= 1) {
    QFontMetrics metrics(painter->font());
    QRectF text_rect = metrics.boundingRect(m_str);
    QPointF center = boundingRect().center();
    QPointF text_pos(center.x() - text_rect.width() / 2,
                     center.y() - text_rect.y() / 2);
    painter->setPen(QPen(Qt::gray, 1));
    painter->drawText(text_pos, m_str);
  }
  int x = this->x();
  int y = this->y();
}

void KeyItem::SetStr(const QString& str) {
  m_str = str;
  update();
}

void KeyItem::Zoom(const double scale) {
  QTransform transform;
  transform.scale(scale, scale);
  this->setTransform(transform);
  update();
}

void KeyItem::mousePressEvent(QGraphicsSceneMouseEvent* e) {
  QGraphicsItem::mousePressEvent(e);
  m_color = m_color.lighter(200);
  emit Clicked(m_str);
  update();
}

void KeyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* e) {
  QGraphicsItem::mouseReleaseEvent(e);
  m_color = m_color.darker(200);
  update();
}

void KeyItem::mouseMoveEvent(QGraphicsSceneMouseEvent* e) {
  QGraphicsItem::mouseMoveEvent(e);
  update();
}

void KeyItem::hoverEnterEvent(QGraphicsSceneHoverEvent* e) {
  m_color.setRgb(156, 229, 200);
  update();
}

void KeyItem::hoverLeaveEvent(QGraphicsSceneHoverEvent* e) {
  m_color.setRgb(156, 229, 134);
  update();
}

void KeyItem::wheelEvent(QGraphicsSceneWheelEvent* e) {
  QTransform transform;
  if (e->delta() > 0) {
    m_scale += 0.1;
  } else {
    m_scale -= 0.1;
  }
  transform.scale(m_scale, m_scale);
  this->setTransform(transform);
  QGraphicsItem::wheelEvent(e);
  update();
}
