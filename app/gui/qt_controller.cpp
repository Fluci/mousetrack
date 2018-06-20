/// \file
/// Maintainer: Luzian Hug
///
///

#include "qt_controller.h"

#include <QApplication>
#include <QPushButton>
#include <boost/log/trivial.hpp>

namespace MouseTrack {

int QtController::main(int argc, char *argv[], op::variables_map &) {

  // set up application
  QApplication app(argc, argv);
  // show a button in a window

  pipeline().addObserver(this);

  _window = std::make_unique<MainWindow>();
  _window->show();
  // start pipeline
  pipeline().start();

  // start run loop
  int returnCode = app.exec();

  pipeline().join();

  return returnCode;
}

void QtController::newFrameWindow(FrameNumber f,
                                  std::shared_ptr<const FrameWindow> window) {
  _window->setFrameNumber(f);
  _window->setFrameWindow(window);
}

void QtController::newPointCloud(FrameNumber,
                                 std::shared_ptr<const PointCloud> cloud) {
  _window->setPointCloud(cloud);
}

void QtController::newClusters(
    FrameNumber, std::shared_ptr<const std::vector<Cluster>> clusters) {
  _window->setClusters(clusters);
}

} // namespace MouseTrack
