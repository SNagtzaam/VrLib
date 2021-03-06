#include "Image.h"

#include "stb_image.h"
#include <iostream>

namespace vrlib
{
	Image::Image(const std::string &filename)
	{
		if (filename.substr(filename.size() - 4) == ".dds")
		{
			throw "cannot be loaded";

		}
		else
		{
			width = -1;
			height = -1;
			depth = -1;
			data = stbi_load(filename.c_str(), &width, &height, &depth, 4);
			if (!data)
			{
				const char* err = stbi_failure_reason();
				std::cout << "Error loading file " << filename << std::endl;
				std::cout << err << std::endl;
				return;
			}
		}
	}


	Image::~Image()
	{
		if (data)
			stbi_image_free(data);
		data = NULL;
	}

	void Image::unload()
	{
		if (data)
			stbi_image_free(data);
		data = NULL;
	}

}