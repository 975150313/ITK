/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif

#include <iostream>

#include "itkAggregateLabelMapFilter.txx"
#include "itkAreaClosingImageFilter.h"
#include "itkAreaOpeningImageFilter.h"
#include "itkAttributeKeepNObjectsLabelMapFilter.txx"
#include "itkAttributeLabelObject.h"
#include "itkAttributeMorphologyBaseImageFilter.txx"
#include "itkAttributeOpeningLabelMapFilter.txx"
#include "itkAttributePositionLabelMapFilter.txx"
#include "itkAttributeRelabelLabelMapFilter.txx"
#include "itkAttributeSelectionLabelMapFilter.txx"
#include "itkAttributeUniqueLabelMapFilter.txx"
#include "itkAutoCropLabelMapFilter.txx"
#include "itkAutumnColormapFunction.txx"
#include "itkBinaryClosingByReconstructionImageFilter.txx"
#include "itkBinaryContourImageFilter.txx"
#include "itkBinaryFillholeImageFilter.txx"
#include "itkBinaryGrindPeakImageFilter.txx"
#include "itkBinaryImageToLabelMapFilter.txx"
#include "itkBinaryImageToShapeLabelMapFilter.txx"
#include "itkBinaryImageToStatisticsLabelMapFilter.txx"
#include "itkBinaryMorphologicalClosingImageFilter.txx"
#include "itkBinaryMorphologicalOpeningImageFilter.txx"
#include "itkBinaryNotImageFilter.h"
#include "itkBinaryOpeningByReconstructionImageFilter.txx"
#include "itkBinaryReconstructionByDilationImageFilter.txx"
#include "itkBinaryReconstructionByErosionImageFilter.txx"
#include "itkBinaryReconstructionLabelMapFilter.txx"
#include "itkBinaryShapeKeepNObjectsImageFilter.txx"
#include "itkBinaryShapeOpeningImageFilter.txx"
#include "itkBinaryStatisticsKeepNObjectsImageFilter.txx"
#include "itkBinaryStatisticsOpeningImageFilter.txx"
#include "itkBlueColormapFunction.txx"
#include "itkBoxMeanImageFilter.txx"
#include "itkBoxSigmaImageFilter.txx"
#include "itkBoxUtilities.h"
#include "itkBruker2DSEQImageIO.h"
#include "itkBruker2DSEQImageIOFactory.h"
#include "itkBSplineControlPointImageFilter.txx"
#include "itkBSplineControlPointImageFunction.txx"
#include "itkBSplineDeformableTransformInitializer.txx"
#include "itkBSplineScatteredDataPointSetToImageFilter.txx"
#include "itkChangeLabelLabelMapFilter.txx"
#include "itkChangeRegionLabelMapFilter.txx"
#include "itkColormapFunction.h"
#include "itkComplexBSplineInterpolateImageFunction.txx"
#include "itkCompositeTransform.txx"
#include "itkConformalFlatteningMeshFilter.txx"
#include "itkConstrainedRegionBasedLevelSetFunctionSharedData.h"
#include "itkContourExtractor2DImageFilter.txx"
#include "itkConvolutionImageFilter.txx"
#include "itkCoolColormapFunction.txx"
#include "itkCopperColormapFunction.txx"
#include "itkCoxDeBoorBSplineKernelFunction.txx"
#include "itkCropLabelMapFilter.txx"
#include "itkCustomColormapFunction.txx"
#include "itkDeformationFieldTransform.txx"
#include "itkDiffeomorphicDemonsRegistrationFilter.txx"
#include "itkDirectFourierReconstructionImageToImageFilter.txx"
#include "itkDiscreteGaussianDerivativeImageFilter.txx"
#include "itkDiscreteGaussianDerivativeImageFunction.txx"
#include "itkDiscreteGradientMagnitudeGaussianImageFunction.txx"
#include "itkDiscreteHessianGaussianImageFunction.txx"
#include "itkESMDemonsRegistrationFunction.txx"
#include "itkExponentialDeformationFieldImageFilter.txx"
#include "itkFastApproximateRankImageFilter.h"
#include "itkFastSymmetricForcesDemonsRegistrationFilter.txx"
#include "itkGaborImageSource.txx"
#include "itkGaborKernelFunction.h"
#include "itkGaussianDerivativeOperator.txx"
#include "itkGenericUtilities.h"
#include "itkGeometryUtilities.h"
#include "itkGreenColormapFunction.txx"
#include "itkGreyColormapFunction.txx"
#include "itkGridForwardWarpImageFilter.txx"
#include "itkGridImageSource.txx"
#include "itkHessianToObjectnessMeasureImageFilter.txx"
#include "itkHotColormapFunction.txx"
#include "itkHSVColormapFunction.txx"
#include "itkImageKernelOperator.txx"
#include "itkImageToPathFilter.txx"
#include "itkInPlaceLabelMapFilter.txx"
#include "itkJetColormapFunction.txx"
#include "itkJPEG2000ImageIO.h"
#include "itkJPEG2000ImageIOFactory.h"
#include "itkKappaSigmaThresholdImageCalculator.txx"
#include "itkKappaSigmaThresholdImageFilter.txx"
#include "itkLabelGeometryImageFilter.txx"
#include "itkLabelImageToLabelMapFilter.txx"
#include "itkLabelImageToShapeLabelMapFilter.txx"
#include "itkLabelImageToStatisticsLabelMapFilter.txx"
#include "itkLabelMap.txx"
#include "itkLabelMapContourOverlayImageFilter.txx"
#include "itkLabelMapFilter.txx"
#include "itkLabelMapMaskImageFilter.txx"
#include "itkLabelMapOverlayImageFilter.txx"
#include "itkLabelMapToAttributeImageFilter.txx"
#include "itkLabelMapToBinaryImageFilter.txx"
#include "itkLabelMapToLabelImageFilter.txx"
#include "itkLabelMapToRGBImageFilter.txx"
#include "itkLabelMapUtilities.h"
#include "itkLabelObject.txx"
#include "itkLabelObjectAccessors.h"
#include "itkLabelObjectLine.txx"
#include "itkLabelObjectLineComparator.h"
#include "itkLabelOverlayFunctor.h"
#include "itkLabelOverlayImageFilter.txx"
#include "itkLabelSelectionLabelMapFilter.h"
#include "itkLabelShapeKeepNObjectsImageFilter.txx"
#include "itkLabelShapeOpeningImageFilter.txx"
#include "itkLabelStatisticsKeepNObjectsImageFilter.txx"
#include "itkLabelStatisticsOpeningImageFilter.txx"
#include "itkLabelToRGBFunctor.h"
#include "itkLabelToRGBImageFilter.txx"
#include "itkLabelUniqueLabelMapFilter.h"
#include "itkMagnitudeAndPhaseToComplexImageFilter.h"
#include "itkMaskedMovingHistogramImageFilter.txx"
#include "itkMaskedRankImageFilter.txx"
#include "itkMergeLabelMapFilter.txx"
#include "itkMiniPipelineSeparableImageFilter.txx"
#include "itkMorphologicalWatershedFromMarkersImageFilter.txx"
#include "itkMorphologicalWatershedImageFilter.txx"
#include "itkMRCHeaderObject.h"
#include "itkMRCImageIO.h"
#include "itkMRCImageIOFactory.h"
#include "itkMultiphaseDenseFiniteDifferenceImageFilter.txx"
#include "itkMultiphaseFiniteDifferenceImageFilter.txx"
#include "itkMultiphaseSparseFiniteDifferenceImageFilter.txx"
#include "itkMultiScaleHessianBasedMeasureImageFilter.txx"
#include "itkN4MRIBiasFieldCorrectionImageFilter.txx"
#include "itkNeuralNetworkFileReader.txx"
#include "itkNeuralNetworkFileWriter.txx"
#include "itkObjectByObjectLabelMapFilter.txx"
#include "itkObjectToObjectMetric.txx"
#include "itkOverUnderColormapFunction.txx"
#include "itkPadLabelMapFilter.txx"
#include "itkPhilipsPAR.h"
#include "itkPhilipsRECImageIO.h"
#include "itkPhilipsRECImageIOFactory.h"
#include "itkRankHistogram.h"
#include "itkRankImageFilter.txx"
#include "itkRedColormapFunction.txx"
#include "itkRegionalMaximaImageFilter.txx"
#include "itkRegionalMinimaImageFilter.txx"
#include "itkRegionBasedLevelSetFunction.txx"
#include "itkRegionBasedLevelSetFunctionData.txx"
#include "itkRegionBasedLevelSetFunctionSharedData.h"
#include "itkRegionFromReferenceLabelMapFilter.txx"
#include "itkRelabelLabelMapFilter.h"
#include "itkRobustAutomaticThresholdCalculator.txx"
#include "itkRobustAutomaticThresholdImageFilter.txx"
#include "itkScalarChanAndVeseDenseLevelSetImageFilter.txx"
#include "itkScalarChanAndVeseLevelSetFunction.txx"
#include "itkScalarChanAndVeseLevelSetFunctionData.h"
#include "itkScalarChanAndVeseSparseLevelSetImageFilter.txx"
#include "itkScalarRegionBasedLevelSetFunction.txx"
#include "itkScalarToRGBColormapImageFilter.txx"
#include "itkShapedFloodFilledFunctionConditionalConstIterator.txx"
#include "itkShapedFloodFilledImageFunctionConditionalConstIterator.txx"
#include "itkShapedFloodFilledImageFunctionConditionalIterator.h"
#include "itkShapeKeepNObjectsLabelMapFilter.txx"
#include "itkShapeLabelMapFilter.txx"
#include "itkShapeLabelObject.h"
#include "itkShapeLabelObjectAccessors.h"
#include "itkShapeOpeningLabelMapFilter.txx"
#include "itkShapePositionLabelMapFilter.txx"
#include "itkShapeRelabelImageFilter.txx"
#include "itkShapeRelabelLabelMapFilter.txx"
#include "itkShapeUniqueLabelMapFilter.txx"
#include "itkShiftScaleLabelMapFilter.txx"
#include "itkSliceBySliceImageFilter.txx"
#include "itkSpringColormapFunction.txx"
#include "itkStatisticsKeepNObjectsLabelMapFilter.txx"
#include "itkStatisticsLabelMapFilter.txx"
#include "itkStatisticsLabelObject.h"
#include "itkStatisticsLabelObjectAccessors.h"
#include "itkStatisticsOpeningLabelMapFilter.txx"
#include "itkStatisticsPositionLabelMapFilter.txx"
#include "itkStatisticsRelabelImageFilter.txx"
#include "itkStatisticsRelabelLabelMapFilter.txx"
#include "itkStatisticsUniqueLabelMapFilter.txx"
#include "itkStochasticFractalDimensionImageFilter.txx"
#include "itkSummerColormapFunction.txx"
#include "itkTransformToDeformationFieldSource.txx"
#include "itkUnconstrainedRegionBasedLevelSetFunctionSharedData.h"
#include "itkValuedRegionalExtremaImageFilter.txx"
#include "itkValuedRegionalMaximaImageFilter.h"
#include "itkValuedRegionalMinimaImageFilter.h"
#include "itkVectorCentralDifferenceImageFunction.txx"
#include "itkVectorLinearInterpolateNearestNeighborExtrapolateImageFunction.txx"
#include "itkVoxBoCUBImageIO.h"
#include "itkVoxBoCUBImageIOFactory.h"
#include "itkWarpHarmonicEnergyCalculator.txx"
#include "itkWinterColormapFunction.txx"

int itkReviewHeaderTest ( int , char * [] )
{
  return EXIT_SUCCESS;
}