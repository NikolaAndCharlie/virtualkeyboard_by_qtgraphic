#include "qwidget.h"

class View;
class QGraphicsScene;
class MainWidget : public QWidget {
  Q_OBJECT
 public:
  MainWidget();
  ~MainWidget();

 private:
  void SetUI();
  View* m_view;
  QGraphicsScene* m_scene;
};