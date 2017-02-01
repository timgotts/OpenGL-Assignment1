#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <GLM/GLM.hpp>
#include "Sweep.h"
#include <sstream>
#include <istream>
#include <vector>
#include <GL/glew.h>
#include <iterator>

class InputReader
{
public:
	InputReader(std::string file);
	~InputReader();
	std::vector<glm::vec3>* getProfileCurves();
	std::vector<glm::vec3>* getTrajectoryCurves();
	bool getTranslational() const { return translational; }
private:
	bool translational;
	std::ifstream input;
	//Sweep readTranslationalSweep(std::ifstream & input);
	//Sweep readRotationalSweep(std::ifstream & input);
	std::vector<glm::vec3>* profileCurves;
	std::vector<glm::vec3>* trajectoryCurves;
	void readTranslationalSweep();
	void readRotationalSweep();
	glm::vec3 parseLine(std::string line);
	std::vector<glm::vec3>* storePoints(int points, std::ifstream & input);
	int verticesSize;
	int indicesSize;
	GLfloat *vertices;
	GLuint *indices;
};
