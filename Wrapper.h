#pragma once

#include "Blueprint.h"

namespace Wrapper {

	void drawCircle(Vertex vertex, int radius = 5);
	void drawListCircle(std::vector<Vertex> vertexs, int radius = 5);

	void drawLine(inputData data);

	Axis getClick(int _delay = 300);

}