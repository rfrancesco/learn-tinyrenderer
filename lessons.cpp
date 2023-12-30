#include "tgaimage.h"
#include "my_rendering_library.h"
#include "model.h"

/* Lesson 1: Draw a line */

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

void lesson1a() {
	TGAImage image(100, 100, TGAImage::RGB);

	line(13, 20, 80, 40, image, white); 
	line(20, 13, 40, 80, image, red); 
	line(80, 40, 13, 20, image, red);

	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output1a.tga");
}

void lesson1b(int argc, char **argv) {
	const int width  = 800;
	const int height = 800;
	Model *model;
	if (argc == 2)
		model = new Model(argv[1]);
	else
		model = new Model("obj/african_head.obj");

	TGAImage image(width, height, TGAImage::RGB);

	for (int i=0; i < model->nfaces(); i++)
	{
		std::vector<int> face = model->face(i);
		for (int j = 0; j < 3; j++)
		{
			Vec3f v0 = model->vert(face[j]);
			Vec3f v1 = model->vert(face[(j+1)%3]);
			Point p0 { (v0.x + 1.)*(width/2), (v0.y + 1.)*(height/2)};
			Point p1 { (v1.x + 1.)*(width/2), (v1.y + 1.)*(height/2)};
			line(p0,p1,image,white);
		}
	}

	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output1b.tga");
}



