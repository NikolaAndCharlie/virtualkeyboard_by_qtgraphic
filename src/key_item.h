#include "qgraphicsitem.h"
#include "qgraphicssceneevent.h"
#include "qobject.h"
#include "qstyleoption.h"

class QColor;
class QPainterPath;
class QPainter;
class KeyItem : public QObject, public QGraphicsItem {
  Q_OBJECT
 public:
  explicit KeyItem(const int x, const int y, const QString& str);
  ~KeyItem();

  QRectF boundingRect() const override;
  QPainterPath shape() const override;
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* item,
             QWidget* widget) override;
  QString GetStr() { return m_str; };
  void SetStr(const QString& str);

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* e) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent* e) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent* e) override;
  void hoverEnterEvent(QGraphicsSceneHoverEvent* e) override;
  void hoverLeaveEvent(QGraphicsSceneHoverEvent* e) override;
 signals:
  void Clicked(const QString&);

 private:
  int m_x;
  int m_y;
  QColor m_color;
  QString m_str;
};