/// \file
/// Maintainer: Luzian Hug
///
///

#include "main_window.h"

#include <QString>

#include <boost/log/trivial.hpp>

namespace MouseTrack {

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {

  // setFixedSize(2*640,480);

  _frame_number_label = new QLabel(this);

  _ref_img_view = new GUIRefImgView(this);
  setFrameNumber(0);
}

// This is needed because of a Qt bug
MainWindow::~MainWindow() {
  // empty
}

void MainWindow::setFrameNumber(FrameNumber f) {
  BOOST_LOG_TRIVIAL(debug) << "Updating Frame Number: " << f;
  _frame_number = f;
  _frame_number_label->setText("Frame Number: " + QString::number(f));
}

void MainWindow::setFrameWindow(
    std::shared_ptr<const FrameWindow> frame_window) {
  _frame_window = frame_window;
  const auto &frames = frame_window->frames();
  std::vector<PictureD> pics{frames.size()};
  for (size_t i = 0; i < frames.size(); ++i) {
    pics[i] = frames[i].referencePicture;
  }
  _ref_img_view->draw(pics);
  _point_cloud = nullptr;
  _clusters = nullptr;
}

void MainWindow::setPointCloud(std::shared_ptr<const PointCloud> point_cloud) {
  _point_cloud = point_cloud;
}

// note ccx/ccy need to be (ccx - X_shift) to work!!
// TODO: not used yet
/*Eigen::MatrixXd projectToFrame(Eigen::Matrix P, double focallength, double
ccx, double ccy, Eigen::MatrixXd projectionMatrix) { auto p4d = projectionMatrix
* P; Eigen::MatrixXd p2d{2, P.cols()}; p2d.row(0) = p4d.row(0); p2d.row(1) =
p4d.row(1); p2d = p2d.rowwise() / p4d.row(3) * focallength; p2d.row(0) += ccx;
  p2d.row(1) += ccy;
  return p2d;
}
*/
void MainWindow::setClusters(
    std::shared_ptr<const std::vector<Cluster>> clusters) {
  _clusters = clusters;
  return;
  Eigen::MatrixXd cogs{3 + 1, clusters->size()};
  cogs.row(3).setOnes();
  for (size_t i = 0; i < _clusters->size(); ++i) {
    // get 3D cog
    cogs.col(i) =
        (*_clusters)[i].center_of_gravity(*_point_cloud).block<3, 1>(0, 0);
  }
}

} // namespace MouseTrack
