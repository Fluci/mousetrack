/// \file
/// Maintainer: Luzian Hug
///
///

#pragma once
#include <QLabel>
#include <QPushButton>
#include <QWidget>

#include <memory>

#include "generic/frame_window.h"
#include "generic/types.h"
#include "gui_ref_img_view.h"

#include "generic/cluster.h"
#include "generic/point_cloud.h"

namespace MouseTrack {

class MainWindow : public QWidget {
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow(); // This is needed because of a Qt bug

  void setFrameNumber(FrameNumber f);
  void setFrameWindow(std::shared_ptr<const FrameWindow> frame_window);
  void setPointCloud(std::shared_ptr<const PointCloud> point_cloud);
  void setClusters(std::shared_ptr<const std::vector<Cluster>> clusters);

private:
  FrameNumber _frame_number;
  QLabel *_frame_number_label;
  std::shared_ptr<const FrameWindow> _frame_window;
  std::shared_ptr<const PointCloud> _point_cloud;
  std::shared_ptr<const std::vector<Cluster>> _clusters;
  GUIRefImgView *_ref_img_view;
};

} // namespace MouseTrack
