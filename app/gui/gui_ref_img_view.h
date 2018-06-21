/// \file
/// Maintainer: Luzian Hug
///
///

#pragma once
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QWidget>

#include <memory>

#include "generic/frame_window.h"

namespace MouseTrack {

class GUIRefImgView : public QWidget {
  Q_OBJECT
public:
  explicit GUIRefImgView(QWidget *parent);
  void draw(const std::vector<PictureD> &frames);
  void draw(const std::vector<PictureDRGB> &frames);
  void draw(const std::vector<QImage> &image);

private:
  std::vector<QLabel *> _images;
  QGroupBox *_gridGroupBox;
  QGridLayout *_gridLayout;
};

} // namespace MouseTrack
