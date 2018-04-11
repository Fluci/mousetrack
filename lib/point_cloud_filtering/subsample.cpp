/// \file
/// Maintainer: Felice Serena
///

#include "subsample.h"
#include "generic/random_sample.h"
#include <boost/log/trivial.hpp>


namespace MouseTrack {

SubSample::SubSample(int desiredMaxPoints) : _desiredMaxPoints(desiredMaxPoints) {
    // empty
}

PointCloud SubSample::operator()(const PointCloud& inCloud) const {
    PointCloud cloud = random_sample(inCloud, _desiredMaxPoints);
    auto min = cloud.min();
    auto max = cloud.max();

    BOOST_LOG_TRIVIAL(debug) << "Filtered point cloud to " << cloud.size() << " points, xyz-min: [" << min[0] << ", " << min[1] << ", " << min[2] << "], xyz-max: [" << max[0] << ", " << max[1] << ", " << max[2] << "]" << std::flush;
    return cloud;
}

} // MouseTrack
