#include "qapplication.h"
#include "main_widget.h"
int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  MainWidget w;
  w.show();

  return app.exec();
}