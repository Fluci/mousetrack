/// \file
/// Maintainer: Luzian Hug
///
///

#pragma once

#include "controller.h"
#include "main_window.h"
#include "pipeline/pipeline_observer.h"

namespace MouseTrack {

class QtController : public Controller, public PipelineObserver {

public:
  virtual int main(int argc, char *argv[], op::variables_map &cli_options);
  virtual void newFrameWindow(FrameNumber f,
                              std::shared_ptr<const FrameWindow> window);
  virtual void newPointCloud(FrameNumber f,
                             std::shared_ptr<const PointCloud> cloud);
  virtual void
  newClusters(FrameNumber f,
              std::shared_ptr<const std::vector<Cluster>> clusters);

private:
  std::unique_ptr<MainWindow> _window;
};

} // namespace MouseTrack
