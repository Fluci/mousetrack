/// \file
/// Maintainer: Luzian Hug
///
///

#pragma once

#include "controller.h"
#include "main_window.h"

namespace MouseTrack {

class QtController : public Controller, public PipelineObserver {

public:
  virtual int main(int argc, char *argv[], op::variables_map &cli_options);
  virtual void newFrameWindow(FrameNumber f,
                              std::shared_ptr<const FrameWindow> window);

private:
  std::unique_ptr<MainWindow> _window;
};

} // namespace MouseTrack
