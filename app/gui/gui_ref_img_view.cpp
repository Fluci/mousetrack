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

  setFixedSize(2 * 752, 2 * 480);
  _gridGroupBox = new QGroupBox(this);
  for (size_t i = _images.size(); i < 4; ++i) {
    _images.push_back(new QLabel(this));
  }
  _gridLayout = new QGridLayout;
  _gridGroupBox->setLayout(_gridLayout);
  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addWidget(_gridGroupBox);
  setLayout(mainLayout);
}

QImage toQImage(const PictureDRGB &pic) {
  QImage image(pic.r.cols(), pic.r.rows(), QImage::Format_RGB888);
  for (int x = 0; x < pic.r.cols(); x++) {
    for (int y = 0; y < pic.r.rows(); y++) {
      int r = 255 * pic.r(y, x);
      int g = 255 * pic.g(y, x);
      int b = 255 * pic.b(y, x);
      image.setPixel(pic.r.cols() - x - 1, y, qRgb(r, g, b));
    }
  }
  return image;
}

QImage toQImage(const PictureD &pic) {
  QImage image(pic.cols(), pic.rows(), QImage::Format_Grayscale8);
  for (int x = 0; x < pic.cols(); x++) {
    for (int y = 0; y < pic.rows(); y++) {
      int i = 255 * pic(y, x);
      image.setPixel(pic.cols() - x - 1, y, qRgb(i, i, i));
    }
  }

  return image;
}

void GUIRefImgView::draw(const std::vector<PictureD> &frames) {
  if (frames.empty()) {
    BOOST_LOG_TRIVIAL(warning) << "Passed empty Frame vector to GUI";
    return;
  }
  std::vector<QImage> pics;
  for (const auto &pic : frames) {
    pics.push_back(toQImage(pic));
  }

  draw(pics);
}

void GUIRefImgView::draw(const std::vector<PictureDRGB> &frames) {
  if (frames.empty()) {
    BOOST_LOG_TRIVIAL(warning) << "Passed empty Frame vector to GUI";
    return;
  }
  std::vector<QImage> pics;
  for (const auto &pic : frames) {
    pics.push_back(toQImage(pic));
  }

  draw(pics);
}

void GUIRefImgView::draw(const std::vector<QImage> &images) {
  if (_images.size() != images.size()) {
    // wont work -> other thread
    BOOST_LOG_TRIVIAL(debug) << "Adjusting image count to " << images.size();
    for (size_t i = _images.size(); i < images.size(); ++i) {
      _images.push_back(new QLabel(this));
    }
    _images.resize(images.size());
  }

  for (size_t i = 0; i < images.size(); ++i) {
    auto &image = images[i];
    _images[i]->setFixedSize(image.width(), image.height());
    _images[i]->setPixmap(QPixmap::fromImage(std::move(image)));
  }

  for (size_t i = 0; i < images.size(); ++i) {
    _gridLayout->addWidget(_images[i], i / 2, i % 2);
  }
}

} // namespace MouseTrack
