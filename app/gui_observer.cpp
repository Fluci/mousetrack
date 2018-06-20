/// \file
/// Maintainer: Felice Serena
///
///

#include "gui_observer.h"

namespace MouseTrack {

GUIObserver::GUIObserver(MainWindow *window) { _window = window; }

void GUIObserver::pipelineStarted() {
  // empty
}

void GUIObserver::pipelineTerminated() {
  // empty
}

void GUIObserver::newClusterChains(
    std::shared_ptr<const std::vector<ClusterChain>>) {
  // empty
}

void GUIObserver::frameStart(FrameNumber) {
  // empty
}

void GUIObserver::frameEnd(FrameNumber) {
  // empty
}

void GUIObserver::startFrameWindow(FrameNumber) {
  // empty
}

void GUIObserver::newFrameWindow(FrameNumber f,
                                 std::shared_ptr<const FrameWindow> window) {
  _window->setFrameNumber(f);
  _window->setFrameWindow(window);
}

void GUIObserver::startFrameWindowFiltering(FrameNumber) {
  // empty
}

void GUIObserver::newFilteredFrameWindow(
    FrameNumber, std::shared_ptr<const FrameWindow>) {
  // empty
}

void GUIObserver::startRegistration(FrameNumber) {
  // empty
}

void GUIObserver::newRawPointCloud(FrameNumber,
                                   std::shared_ptr<const PointCloud>) {
  // empty
}

void GUIObserver::startPointCloudFiltering(FrameNumber) {
  // empty
}

void GUIObserver::newFilteredPointCloud(
    FrameNumber, std::shared_ptr<const PointCloud>) {
  // empty
}

void GUIObserver::startClustering(FrameNumber) {
  // empty
}

void GUIObserver::newClusters(
    FrameNumber, std::shared_ptr<const std::vector<Cluster>>) {
  // empty
}

void GUIObserver::startDescripting(FrameNumber) {
  // empty
}

void GUIObserver::newDescriptors(
    FrameNumber,
    std::shared_ptr<const std::vector<std::shared_ptr<const ClusterDescriptor>>>
    ) {
  // empty
}

void GUIObserver::startMatching(FrameNumber) {
  // empty
}

void GUIObserver::newMatches(FrameNumber,
                             std::shared_ptr<const std::vector<long>>) {
  // empty
}

void GUIObserver::startControlPoints(FrameNumber) {
  // empty
}

void GUIObserver::newControlPoints(
    FrameNumber,
    std::shared_ptr<const std::vector<Eigen::Vector3d>>) {
  // empty
}

} // namespace MouseTrack
