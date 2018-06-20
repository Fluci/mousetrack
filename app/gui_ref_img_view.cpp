/// \file
/// Maintainer: Luzian Hug
///
///

#include "gui_ref_img_view.h"

#include <QColor>
#include <QImage>
#include <QLabel>

#include <boost/log/trivial.hpp>

namespace MouseTrack {

GUIRefImgView::GUIRefImgView(QWidget *parent) : QWidget(parent) {

  setFixedSize(752, 480);
  _image = new QLabel(this);
}

void GUIRefImgView::draw(std::shared_ptr<const FrameWindow> f) {
  if (f == nullptr) {
    BOOST_LOG_TRIVIAL(warning) << "Passed empty Frame Window to GUI";
    return;
  }
  const PictureD &pic = f->frames()[0].referencePicture;
  QImage image(pic.cols(), pic.rows(), QImage::Format_Grayscale8);

  BOOST_LOG_TRIVIAL(debug) << "image width to display: " << image.width();

  for (int x = 0; x < pic.cols(); x++) {
    for (int y = 0; y < pic.rows(); y++) {
      int i = 255 * pic(y, x);
      image.setPixel(pic.cols() - x - 1, y, qRgb(i, i, i));
    }
  }
  _image->setFixedSize(image.width(), image.height());
  _image->setPixmap(QPixmap::fromImage(std::move(image)));
}

} // namespace MouseTrack
