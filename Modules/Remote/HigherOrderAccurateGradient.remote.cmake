# Contact: Matt McCormick <matt.mccormick@kitware.com>
itk_fetch_module(HigherOrderAccurateGradient
  "This module contains a filter to compute higher order
  accurate numerical derivatives and gradients from an input scalar image.
  field from a displacement field image.
  Higher Order Accurate Derivative and Gradient Calculation in ITK
  http://www.insight-journal.org/browse/publication/775
  https://hdl.handle.net/10380/3231"
  GIT_REPOSITORY ${git_protocol}://github.com/InsightSoftwareConsortium/ITKHigherOrderAccurateGradient.git
  GIT_TAG 954b38c3cd3953fec3bee9f857eae9c0c08c0113
  )
