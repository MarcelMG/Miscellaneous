#include "Image/ImageProcessor.h"
#include "Image/ByteImage.h"
#include "Interfaces/ApplicationHandlerInterface.h"
#include "Interfaces/MainWindowInterface.h"
#include "gui/GUIFactory.h"
#include <iostream>
#include <algorithm>

// my RGB2HSV method
void RGB2HSV(uint8_t R, uint8_t G, uint8_t B, uint8_t* H, uint8_t* S, uint8_t* V){
	uint8_t maxVal = std::max({R, G, B});
	uint8_t minVal = std::min({R, G, B});
	*V = maxVal;
	uint8_t delta = maxVal - minVal;
	unsigned int H_tmp = 0;
	if(!delta){
		H_tmp = 0;
		S = 0;
	}else{
		*S = ( 255 * delta ) / maxVal;
		if(R == maxVal){
			H_tmp = ( 60 * ( G - B ) ) / delta;
		}else if(G == maxVal){
			H_tmp = 120 + ( 60 * ( B - R ) ) / delta;
		}else{
			H_tmp = 240 + ( 60 * ( R - G ) ) / delta;
		}
	}
	while( H_tmp < 0 ) H_tmp += 360;
	while( H_tmp > 360 ) H_tmp -= 360;
	*H = (uint8_t) ( ( H_tmp * 179 ) / 255 );
}	

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout<<("ERROR: you must specify path to input image!\n");
		return 1;
	}

	CByteImage RGBimage;
	// load image
	if (!RGBimage.LoadFromFile(argv[1]))
	{
		printf("error: could not open input file\n");
		return 1;
	}
	std::cout<<"processing...(this might take a while!)"<<std::endl;
	// my RGb2HSV method
	CByteImage HSVimage(RGBimage.width, RGBimage.height, CByteImage::eRGB24);
	uint8_t* RGBimage_ptr = RGBimage.pixels;
	uint8_t* HSVimage_ptr = HSVimage.pixels;
	unsigned int num_pixels = RGBimage.width * RGBimage.height;
	for( unsigned int i = 0; i < num_pixels; ++i ){
		uint8_t R, G, B;
		uint8_t* H;
		uint8_t* S;
		uint8_t* V;
		R = *RGBimage_ptr;
		++RGBimage_ptr;
		G = *RGBimage_ptr;
		++RGBimage_ptr;
		B = *RGBimage_ptr;
		++RGBimage_ptr;
		H = HSVimage_ptr;
		++HSVimage_ptr;
		S = HSVimage_ptr;
		++HSVimage_ptr;
		V = HSVimage_ptr;
		++HSVimage_ptr;
		RGB2HSV(R, G, B, H, S, V);
	}
	// end of my RGb2HSV method
	
	HSVimage.SaveToFile("HSV.bmp");
	std::cout<<("output written to file 'HSV.bmp'\n");
	
	// create an application handler
	CApplicationHandlerInterface *app = CreateApplicationHandler();
	app->Reset();
	// create a main window
	CMainWindowInterface *main_window = CreateMainWindow(0, 0, HSVimage.width, HSVimage.height, "Show Image");
	WIDGET_HANDLE image_widget = main_window->AddImage(0, 0, HSVimage.width, HSVimage.height);
	// make the window visible
	main_window->Show();
	// set the image to display in the window widget
	main_window->SetImage(image_widget, &HSVimage);
	// main loop
	while (!app->ProcessEventsAndGetExit())
	{
	}
	
	delete main_window;
	delete app;
	std::cout<<"goodbye!"<<std::endl;
	return 0;
}
