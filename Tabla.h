#pragma once
using namespace System::Drawing;
class Tabla
{
protected:
	int x, y;
	int ancho, alto;
	int F, C;
public:
	Tabla() {
		x = 20;		y = 20;
		ancho = 200;		alto = 50;
	}

	void DibujarTabla(Graphics^ g, Bitmap^ bmpTabla, int F, int C) {

		Rectangle region = Rectangle(0, 0, ancho, alto);
		
		for (int i = 0; i < F;i++)
		{
			for (int k = 0; k < C; k++)
			{
				g->DrawImage(bmpTabla, x + (ancho - 2) * k , y + (alto - 2) * i, region, GraphicsUnit::Pixel);
			}
		}
	}
};