#pragma once
#include <vector>
#include <iostream>


struct AdjacencyMatrix {
	int x;
	int y;
};

struct Location {
	int x;
	int y;
};

struct Axis {
	int x;
	int y;
};

struct Vertex {
	int x;
	int y;
	int id;
};

struct Line {
	int start;
	int end;
};

struct inputData {
	int nPoint;
	std::vector<std::vector<int>> point;
	std::vector<Line> Lines;
	std::vector<Vertex> Vertexs;
};



