#include "key_item.h"
#include "keyboard_view.h"
#include "qapplication.h"
#include "qgraphicsscene.h"
#include "qwidget.h"
#include "qlayout.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  QWidget* w = new QWidget();

  QGraphicsScene* scene = new QGraphicsScene();
  View* view = new View("Main");
  KeyItem* item = new KeyItem(0, 0, "2");
  scene->setBackgroundBrush(QBrush(QColor(255, 0, 0)));
  scene->addItem(item);
  item->setPos(0, 0);
  view->view()->setScene(scene);

  QHBoxLayout* main_layout = new QHBoxLayout();
  main_layout->addWidget(view);
  w->setLayout(main_layout);
  w->show();
  return app.exec();
}