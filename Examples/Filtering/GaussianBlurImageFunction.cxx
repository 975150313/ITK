#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkGaussianBlurImageFunction.h"
#include "itkImageRegionIterator.h"

int main( int argc, char * argv[] )
{
  if( argc < 5 ) {
    std::cerr << "Usage: " << std::endl;
    std::cerr << argv[0] << "  inputImageFile  outputImageFile sigma maxKernelWidth" << std::endl;
    return 1;
  }

  typedef itk::Image< float, 2 >   ImageType;
  typedef itk::ImageFileReader< ImageType >  ReaderType;
  typedef itk::ImageRegionIterator< ImageType > IteratorType;
  typedef itk::ImageRegionConstIterator< ImageType > ConstIteratorType;

  ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName( argv[1] );
  reader->Update();

  const ImageType * inputImage = reader->GetOutput();

  ImageType::RegionType region = inputImage->GetBufferedRegion();

  ConstIteratorType it( inputImage, region );

  ImageType::Pointer output = ImageType::New();

  output->SetRegions( region );
  output->SetOrigin(  inputImage->GetOrigin()  );
  output->SetSpacing( inputImage->GetSpacing() );
  output->Allocate();

  IteratorType out( output, region );

  typedef itk::GaussianBlurImageFunction< ImageType > GFunctionType;
  GFunctionType::Pointer gaussianFunction = GFunctionType::New();
  gaussianFunction->SetInputImage( inputImage );

  GFunctionType::ErrorArrayType setError;
  setError.Fill( 0.01 );
  gaussianFunction->SetMaximumError( setError );
  gaussianFunction->SetSigma( atof( argv[3] ) );
  gaussianFunction->SetMaximumKernelWidth( atoi( argv[4] ) );

  it.GoToBegin();
  out.GoToBegin();
  while (!it.IsAtEnd()) {
      out.Set( gaussianFunction->EvaluateAtIndex(it.GetIndex() ) );
      ++it;
      ++out;
  }

  typedef itk::ImageFileWriter < ImageType > WriterType;
  WriterType::Pointer writer = WriterType::New();
  writer->SetFileName(argv[2]);
  writer->SetInput(output);
  writer->Update();

  return 0;
}

