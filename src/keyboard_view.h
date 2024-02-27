#include "qframe.h"
#include "qgraphicsview.h"

class View;

class GraphicsView : public QGraphicsView {
  Q_OBJECT
 public:
  GraphicsView(View* v) : QGraphicsView(), m_view(v) {}

 protected:
  void wheelEvent(QWheelEvent*) override;

 private:
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

 private slots:
  void ResetView();

 private:
  void SetUpMatrix();
  GraphicsView* m_graphic_view;
};
