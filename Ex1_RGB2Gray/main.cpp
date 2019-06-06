#include "Image/ImageProcessor.h"
#include "Image/ByteImage.h"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout<<("ERROR: you must specify path to input image!\n");
		return 1;
	}

	CByteImage image;
	// load image
	if (!image.LoadFromFile(argv[1]))
	{
		printf("error: could not open input file\n");
		return 1;
	}

	CByteImage gray_image(image.width, image.height, CByteImage::eGrayScale);
	ImageProcessor::ConvertImage(&image, &gray_image);

	gray_image.SaveToFile("gray.bmp");
	std::cout<<("output written to file 'gray.bmp'\n");

	return 0;
}
