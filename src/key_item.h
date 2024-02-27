#include "qgraphicsitem.h"
#include "qgraphicssceneevent.h"
#include "qobject.h"
#include "qstyleoption.h"

class QColor;
class QPainterPath;
class QPainter;
 class KeyItem : public QGraphicsItem {
 public:
  explicit KeyItem(const int x, const int y, const QString& str);
  ~KeyItem();

  QRectF boundingRect() const override;
  QPainterPath shape() const override;
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* item,
             QWidget* widget) override;

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* e) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent* e) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent* e) override;

 private:
  int m_x;
  int m_y;
  QColor m_color;
  QString m_str;
};