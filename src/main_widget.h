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
  void ReadKeyText();
  View* m_view;
  QGraphicsScene* m_scene;
 private slots:
  void GetItemClickedString(const QString&);
};