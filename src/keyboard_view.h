#include "qframe.h"
#include "qgraphicsview.h"

class View;

class GraphicsView : public QGraphicsView {
  Q_OBJECT
 public:
  GraphicsView(View* v) : QGraphicsView(), m_view(v), m_scale(1.0) {}

 protected:
  void wheelEvent(QWheelEvent*) override;

 private:
  double m_scale;
  View* m_view;
};

class View : public QFrame {
  Q_OBJECT
 public:
  explicit View(const QString& name, QWidget* parent = nullptr);
  QGraphicsView* view() const;

 public slots:
  void ZoomIn();
  void ZoomOut();
protected:
  void wheelEvent(QWheelEvent*e) override;
 private slots:
  void ResetView();

 private:
  void SetUpMatrix();
  GraphicsView* m_graphic_view;
};
