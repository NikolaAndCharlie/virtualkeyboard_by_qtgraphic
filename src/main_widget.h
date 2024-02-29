#include "qwidget.h"

class View;
class QGraphicsScene;
class QLineEdit;
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

  bool m_cap_clicked;
  
  QLineEdit* m_test_line_edit;
  void GetCapsStr();
 private slots:
  void GetItemClickedString(const QString&);
  void PushButtonClicked();
};