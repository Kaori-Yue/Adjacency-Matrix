#include "Wrapper.h"
#include "graphics.h"
#include <algorithm>
#include <iostream>
#include <string>

void Wrapper::drawCircle(Vertex vertex, int radius) {
		settextstyle(4, 4, 1);
		//char* id = const_cast<char *>(std::to_string(v.id).c_str());
		std::string s = "v";
		s.append(std::to_string(vertex.id));
		//std::vector<char> id(s.begin(), s.end());

		outtextxy(vertex.x, vertex.y, &s[0]);

		setfillstyle(SOLID_FILL, COLOR(255, 0, 0));
		circle(vertex.x, vertex.y, radius);
		floodfill(vertex.x + 1, vertex.y + 1, WHITE);
}

void fillColor(int pattern, int color) {
	setfillstyle(pattern, color);
}

void Wrapper::drawListCircle(std::vector<Vertex> vertexs, int radius) {
	for (auto v : vertexs) {
		drawCircle(v, radius);
	}
}

bool compareId(Vertex v1, Vertex v2) {
	return v1.id < v2.id;
}

void Wrapper::drawLine(inputData data) {
	for (auto d : data.Vertexs) {
		std::cout << d.id << " | x:" << d.x << "y: " << d.y << "\n";
	}
	std::cout << "\n\n";
	std::sort(data.Vertexs.begin(), data.Vertexs.end(), compareId);
	for (auto d : data.Vertexs) {
		std::cout << d.id << " | x:" << d.x << "y: " << d.y << "\n";
	}

	std::cout << "\n" << "size: " << data.Vertexs.size() << "\n";
	for (auto l : data.Lines) {
		std::cout << "Line start: " << l.start << " Line end: " << l.end << "\n";
		
		auto v1 = data.Vertexs[l.start];
		auto v2 = data.Vertexs[l.end];
		line(v1.x, v1.y, v2.x, v2.y);
	}


}

Axis Wrapper::getClick(int _delay) {
	Axis click;
	while (!ismouseclick(WM_LBUTTONDOWN))
		delay(_delay);
	getmouseclick(WM_LBUTTONDOWN, click.x, click.y);
	return click;
}