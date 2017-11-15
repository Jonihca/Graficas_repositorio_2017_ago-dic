/*********
Kevin Asaf Alvarez Villarruel A01376017
Isaac Hinojosa Padilla A01375843
Daniel Schacht Luna A01169574
******/

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include "Camera.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Texture2D.h"
#include "Dephtbuffer.h"

Mesh _mesh;
Mesh _palma;
Mesh _falanges;
ShaderProgram _shaderProgram;
Transform _dedoindice1;
Transform _dedomedio1;
Transform _dedoanular1;
Transform _dedopulgar1;
Transform _dedoindice2;
Transform _dedomedio2;
Transform _dedoanular2;
Transform _dedopulgar2;
Transform _piso;
Transform _palma1;

Camera _camera;
Texture2D _texture;
Texture2D _texture2;
Texture2D _texture3;
Depthbuffer _depth;
Camera _lightC;
ShaderProgram _shaderDepth;

float contador = 0.0f;
float contador2 = 0.0f;
float contador3 = 0.0;




void Initialize()
{
	//mesh_piso
	std::vector<glm::vec3> positions;
	//Cara Frente 
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f)); //0
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f)); //1
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f)); //2
	positions.push_back(glm::vec3(-3.0, 3.0f, 3.0f)); //3
	//Cara Derecha
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f)); //4
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f)); //5
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f)); //6
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f)); //7
	//Cara Izquierda 
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f)); //8
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f)); //9
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f)); //10
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f)); //11
	//Cara Atras 
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f)); //12
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f)); //13
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f)); //14
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f)); //15
	//Cara Arriba 
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f)); //16
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f)); //17
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f)); //18
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f)); //19
	//Cara Abajo
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f)); //20
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f)); //21
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f)); //22
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f)); //23


	std::vector<glm::vec3> colors;
	//Cara Frente 
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	//Cara Derecha
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	//Cara Izquierda 
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	//Cara Atras
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	//Cara Arriba
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	//Cara Abajo
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));

	std::vector<unsigned int> indices = { 0, 1, 2, 0, 2, 3,
										4, 5, 6, 4, 6, 7,
										8, 9, 10, 8, 10, 11,
										12,  13, 14, 12, 14, 15,
										16, 17, 18, 16, 18, 19,
										20, 21, 22, 20, 22, 23 };


	std::vector<glm::vec3>Normal;
	//Cara Frente 
	Normal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	//Cara Derecha 
	Normal.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	//Cara Izquierda 
	Normal.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	//Cara Atras
	Normal.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	//Cara Arriba 
	Normal.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	//Cara Abajo 
	Normal.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, -1.0f, 0.0f));

	std::vector<glm::vec2>TexCoords;
	//Cara Frente 
	TexCoords.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords.push_back(glm::vec2(1.0, 0.0f));
	TexCoords.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Derecha
	TexCoords.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords.push_back(glm::vec2(1.0, 0.0f));
	TexCoords.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Izquierda 
	TexCoords.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords.push_back(glm::vec2(1.0, 0.0f));
	TexCoords.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Atras 
	TexCoords.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords.push_back(glm::vec2(1.0, 0.0f));
	TexCoords.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Arriba 
	TexCoords.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords.push_back(glm::vec2(1.0, 0.0f));
	TexCoords.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Abajo
	TexCoords.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords.push_back(glm::vec2(1.0, 0.0f));
	TexCoords.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords.push_back(glm::vec2(0.0f, 1.0f));

	_mesh.CreateMesh(24);
	_mesh.SetIndices(indices, GL_STATIC_DRAW);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_mesh.SetNormalAttribute(Normal, GL_STATIC_DRAW, 2);
	_mesh.SetTexCoordAttribute(TexCoords, GL_STATIC_DRAW, 3);

	//mesh_palma_mano
	//mesh_piso
	std::vector<glm::vec3> positions2;
	//Cara Frente 
	positions2.push_back(glm::vec3(-3.0f, -0.2f, 2.0f)); //0
	positions2.push_back(glm::vec3(3.0f, -0.2f, 2.0f)); //1
	positions2.push_back(glm::vec3(3.0f, 0.2f, 2.0f)); //2
	positions2.push_back(glm::vec3(-3.0, 0.2f, 2.0f)); //3
	//Cara Derecha
	positions2.push_back(glm::vec3(3.0f, -0.2f, 2.0f)); //4
	positions2.push_back(glm::vec3(3.0f, -0.2f, -2.0f)); //5
	positions2.push_back(glm::vec3(3.0f, 0.2f, -2.0f)); //6
	positions2.push_back(glm::vec3(3.0f, 0.2f, 2.0f)); //7
	//Cara Izquierda 
	positions2.push_back(glm::vec3(-3.0f, -0.2f, -2.0f)); //8
	positions2.push_back(glm::vec3(-3.0f, -0.2f, 2.0f)); //9
	positions2.push_back(glm::vec3(-3.0f, 0.2f, 2.0f)); //10
	positions2.push_back(glm::vec3(-3.0f, 0.2f, -2.0f)); //11
	//Cara Atras 
	positions2.push_back(glm::vec3(3.0f, -0.2f, -2.0f)); //12
	positions2.push_back(glm::vec3(-3.0f, -0.2f, -2.0f)); //13
	positions2.push_back(glm::vec3(-3.0f, 0.2f, -2.0f)); //14
	positions2.push_back(glm::vec3(3.0f, 0.2f, -2.0f)); //15
													   //Cara Arriba 
	positions2.push_back(glm::vec3(-3.0f, 0.2f, 2.0f)); //16
	positions2.push_back(glm::vec3(3.0f, 0.2f, 2.0f)); //17
	positions2.push_back(glm::vec3(3.0f, 0.2f, -2.0f)); //18
	positions2.push_back(glm::vec3(-3.0f, 0.2f, -2.0f)); //19
														//Cara Abajo
	positions2.push_back(glm::vec3(-3.0f, -0.2f, -2.0f)); //20
	positions2.push_back(glm::vec3(3.0f, -0.2f, -2.0f)); //21
	positions2.push_back(glm::vec3(3.0f, -0.2f, 2.0f)); //22
	positions2.push_back(glm::vec3(-3.0f, -0.2f, 2.0f)); //23


	std::vector<glm::vec3> colors2;
	//Cara Frente 
	colors2.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors2.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors2.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors2.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	//Cara Derecha
	colors2.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors2.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors2.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors2.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	//Cara Izquierda 
	colors2.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors2.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors2.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors2.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	//Cara Atras
	colors2.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors2.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors2.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors2.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	//Cara Arriba
	colors2.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors2.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors2.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors2.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	//Cara Abajo
	colors2.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors2.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors2.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors2.push_back(glm::vec3(0.0f, 0.0f, 1.0f));

	std::vector<unsigned int> indices2 = { 0, 1, 2, 0, 2, 3,
		4, 5, 6, 4, 6, 7,
		8, 9, 10, 8, 10, 11,
		12,  13, 14, 12, 14, 15,
		16, 17, 18, 16, 18, 19,
		20, 21, 22, 20, 22, 23 };


	std::vector<glm::vec3>Normal2;
	//Cara Frente 
	Normal2.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	Normal2.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	Normal2.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	Normal2.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	//Cara Derecha 
	Normal2.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	Normal2.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	Normal2.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	Normal2.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	//Cara Izquierda 
	Normal2.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	Normal2.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	Normal2.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	Normal2.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	//Cara Atras
	Normal2.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	Normal2.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	Normal2.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	Normal2.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	//Cara Arriba 
	Normal2.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	Normal2.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	Normal2.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	Normal2.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	//Cara Abajo 
	Normal2.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	Normal2.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	Normal2.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	Normal2.push_back(glm::vec3(0.0f, -1.0f, 0.0f));

	std::vector<glm::vec2>TexCoords2;
	//Cara Frente 
	TexCoords2.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords2.push_back(glm::vec2(1.0, 0.0f));
	TexCoords2.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords2.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Derecha
	TexCoords2.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords2.push_back(glm::vec2(1.0, 0.0f));
	TexCoords2.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords2.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Izquierda 
	TexCoords2.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords2.push_back(glm::vec2(1.0, 0.0f));
	TexCoords2.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords2.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Atras 
	TexCoords2.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords2.push_back(glm::vec2(1.0, 0.0f));
	TexCoords2.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords2.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Arriba 
	TexCoords2.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords2.push_back(glm::vec2(1.0, 0.0f));
	TexCoords2.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords2.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Abajo
	TexCoords2.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords2.push_back(glm::vec2(1.0, 0.0f));
	TexCoords2.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords2.push_back(glm::vec2(0.0f, 1.0f));

	_palma.CreateMesh(24);
	_palma.SetIndices(indices2, GL_STATIC_DRAW);
	_palma.SetPositionAttribute(positions2, GL_STATIC_DRAW, 0);
	_palma.SetColorAttribute(colors2, GL_STATIC_DRAW, 1);
	_palma.SetNormalAttribute(Normal2, GL_STATIC_DRAW, 2);
	_palma.SetTexCoordAttribute(TexCoords2, GL_STATIC_DRAW, 3);

	//mesh_falange
	std::vector<glm::vec3> positions3;
	//Cara Frente 
	positions3.push_back(glm::vec3(-0.7f, -0.2f, 0.6f)); //0
	positions3.push_back(glm::vec3(0.7f, -0.2f, 0.6f)); //1
	positions3.push_back(glm::vec3(0.7f, 0.2f, 0.6f)); //2
	positions3.push_back(glm::vec3(-0.7, 0.2f, 0.6f)); //3
													   //Cara Derecha
	positions3.push_back(glm::vec3(0.7f, -0.2f, 0.6f)); //4
	positions3.push_back(glm::vec3(0.7f, -0.2f, -0.6f)); //5
	positions3.push_back(glm::vec3(0.7f, 0.2f, -0.6f)); //6
	positions3.push_back(glm::vec3(0.7f, 0.2f, 0.6f)); //7
													   //Cara Izquierda 
	positions3.push_back(glm::vec3(-0.7f, -0.2f, -0.6f)); //8
	positions3.push_back(glm::vec3(-0.7f, -0.2f, 0.6f)); //9
	positions3.push_back(glm::vec3(-0.7f, 0.2f, 0.6f)); //10
	positions3.push_back(glm::vec3(-0.7f, 0.2f, -0.6f)); //11
														 //Cara Atras 
	positions3.push_back(glm::vec3(0.7f, -0.2f, -0.6f)); //12
	positions3.push_back(glm::vec3(-0.7f, -0.2f, -0.6f)); //13
	positions3.push_back(glm::vec3(-0.7f, 0.2f, -0.6f)); //14
	positions3.push_back(glm::vec3(0.7f, 0.2f, -0.6f)); //15
														//Cara Arriba 
	positions3.push_back(glm::vec3(-0.7f, 0.2f, 0.6f)); //16
	positions3.push_back(glm::vec3(0.7f, 0.2f, 0.6f)); //17
	positions3.push_back(glm::vec3(0.7f, 0.2f, -0.6f)); //18
	positions3.push_back(glm::vec3(-0.7f, 0.2f, -0.6f)); //19
														 //Cara Abajo
	positions3.push_back(glm::vec3(-0.7f, -0.2f, -0.6f)); //20
	positions3.push_back(glm::vec3(0.7f, -0.2f, -0.6f)); //21
	positions3.push_back(glm::vec3(0.7f, -0.2f, 0.6f)); //22
	positions3.push_back(glm::vec3(-0.7f, -0.2f, 0.6f)); //23


	std::vector<glm::vec3> colors3;
	//Cara Frente 
	colors3.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors3.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors3.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors3.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	//Cara Derecha
	colors3.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors3.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors3.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors3.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	//Cara Izquierda 
	colors3.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors3.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors3.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors3.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	//Cara Atras
	colors3.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors3.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors3.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors3.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	//Cara Arriba
	colors3.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors3.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors3.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	colors3.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
	//Cara Abajo
	colors3.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors3.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors3.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors3.push_back(glm::vec3(0.0f, 0.0f, 1.0f));

	std::vector<unsigned int> indices3 = { 0, 1, 2, 0, 2, 3,
		4, 5, 6, 4, 6, 7,
		8, 9, 10, 8, 10, 11,
		12,  13, 14, 12, 14, 15,
		16, 17, 18, 16, 18, 19,
		20, 21, 22, 20, 22, 23 };


	std::vector<glm::vec3>Normal3;
	//Cara Frente 
	Normal3.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	Normal3.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	Normal3.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	Normal3.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	//Cara Derecha 
	Normal3.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	Normal3.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	Normal3.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	Normal3.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	//Cara Izquierda 
	Normal3.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	Normal3.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	Normal3.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	Normal3.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	//Cara Atras
	Normal3.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	Normal3.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	Normal3.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	Normal3.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	//Cara Arriba 
	Normal3.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	Normal3.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	Normal3.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	Normal3.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	//Cara Abajo 
	Normal3.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	Normal3.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	Normal3.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	Normal3.push_back(glm::vec3(0.0f, -1.0f, 0.0f));

	std::vector<glm::vec2>TexCoords3;
	//Cara Frente 
	TexCoords3.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords3.push_back(glm::vec2(1.0, 0.0f));
	TexCoords3.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords3.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Derecha
	TexCoords3.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords3.push_back(glm::vec2(1.0, 0.0f));
	TexCoords3.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords3.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Izquierda 
	TexCoords3.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords3.push_back(glm::vec2(1.0, 0.0f));
	TexCoords3.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords3.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Atras 
	TexCoords3.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords3.push_back(glm::vec2(1.0, 0.0f));
	TexCoords3.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords3.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Arriba 
	TexCoords3.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords3.push_back(glm::vec2(1.0, 0.0f));
	TexCoords3.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords3.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Abajo
	TexCoords3.push_back(glm::vec2(0.0f, 0.0f));
	TexCoords3.push_back(glm::vec2(1.0, 0.0f));
	TexCoords3.push_back(glm::vec2(1.0f, 1.0f));
	TexCoords3.push_back(glm::vec2(0.0f, 1.0f));

	_falanges.CreateMesh(24);
	_falanges.SetIndices(indices3, GL_STATIC_DRAW);
	_falanges.SetPositionAttribute(positions3, GL_STATIC_DRAW, 0);
	_falanges.SetColorAttribute(colors3, GL_STATIC_DRAW, 1);
	_falanges.SetNormalAttribute(Normal3, GL_STATIC_DRAW, 2);
	_falanges.SetTexCoordAttribute(TexCoords3, GL_STATIC_DRAW, 3);


	_depth.Create(2048);
	_lightC.SetPosition(-5.0f, 5.0f, 5.0f);
	_lightC.SetRotation(-30.0f, 0.0f, 0.0f);
	_lightC.SetOrthographic(20.0f, 1.0f);

	_shaderDepth.CreateProgram();
	_shaderDepth.AttachShader("Depth.vert", GL_VERTEX_SHADER);
	_shaderDepth.AttachShader("Depth.frag", GL_FRAGMENT_SHADER);
	_shaderDepth.SetAttribute(0, "VertexPosition");
	_shaderDepth.LinkProgram();

	//NORMAL
	_shaderProgram.CreateProgram();
	_shaderProgram.Activate();
	_shaderProgram.AttachShader("TextureMapping.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("TextureMapping.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.SetAttribute(2, "VertexNormal");
	_shaderProgram.SetAttribute(3, "VertexTexCoord");

	_shaderProgram.LinkProgram();
	_shaderProgram.Deactivate();

	_shaderProgram.Activate();
	_shaderProgram.SetUniformf("LightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	_shaderProgram.SetUniformf("LightPosition", glm::vec3(0.0f, 0.0f, 10.0f));
	_shaderProgram.SetUniformi("DiffuseTexture", 0);

	_shaderProgram.Deactivate();

	//COMBINADO
	_shaderProgram.CreateProgram();
	_shaderProgram.Activate();
	_shaderProgram.AttachShader("TextureMapping2.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("TextureMapping2.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.SetAttribute(2, "VertexNormal");
	_shaderProgram.SetAttribute(3, "VertexTexCoord");

	_shaderProgram.LinkProgram();
	_shaderProgram.Deactivate();

	_shaderProgram.Activate();
	_shaderProgram.SetUniformf("LightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	_shaderProgram.SetUniformf("LightPosition", glm::vec3(0.0f, 0.0f, 10.0f));
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("DiffuseTexture2", 1);
	_shaderProgram.Deactivate();


	_texture.LoadTexture("CAJA.jpg");
	_texture2.LoadTexture("KATAMARI.png");
	_texture3.LoadTexture("PISO.jpg");

	//dedoindice
	_dedoindice1.SetPosition(4.0f, 0.0f, 1.5f);

	//dedoindice2
	_dedoindice2.SetPosition(1.5f, 0.0f, 0.0f);

//dedomedio
	_dedomedio1.SetPosition(4.0f, 0.0f, 0.0f);

//dedomedio2
	_dedomedio2.SetPosition(1.5f, 0.0f, 0.0f);

//dedoanular
	_dedoanular1.SetPosition(4.0f, 0.0f, -1.5f);

//dedoanular2
	_dedoanular2.SetPosition(1.5f, 0.0f, 0.0f);

//dedopulgar
	_dedopulgar1.SetPosition(-2.5f, 0.0f, 3.0f);

//dedopulgar2
	_dedopulgar2.SetPosition(0.0f, 0.0f, 1.5f);
//piso
	_piso.SetPosition(0.0f, -12.0f, 0.0f);
	_piso.SetScale(10.0f, 2.0f, 10.0f);

//palma
	_palma1.SetPosition(0.0f, 0.0f, 5.0f);
	_palma1.Rotate(0.0f, 0.0f, 30.0f,true);
	
	//_camera.SetOrthographic(1.0f, 1.0f); Esto convierte la cámara en 2D
}

void GameLoop()
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpiamos el buffer de control y el de profundidad. Siempre hacerlo al inicio del frame


	_camera.SetPosition(0.0f, 0.0f, 25.0f);
	_dedoindice1.Rotate(0.0f, 0.0f, 1.0f,true);
	_dedoindice2.Rotate(0.0f, 0.0f, 1.0f, true);
	_palma1.Rotate(0.02f, 0.02f, 0.02f, true);



	/*_transform.Rotate(0.04f, 0.04f, 0.04f, true);
	
	
	
	float radio = 5.0f;
	float angulo = glm::radians(contador);
	float x = radio*(glm::cos(angulo));
	float y = radio*(glm::sin(angulo));
	float z = 0;
	
	_dedoindice1.SetRotation(x, 0.0f, 0.0f);
	_dedomedio1.SetRotation(x, 0.0f, 0.0f);
	_dedoanular1.SetRotation(x, 0.0f, 0.0f);
	_dedopulgar1.SetRotation(x, 0.0f, 0.0f);
	_dedoindice2.SetRotation(x, 0.0f, 0.0f);
	_dedomedio2.SetRotation(x, 0.0f, 0.0f);
	_dedoanular2.SetRotation(0.0f, 0.0f, z);
	_dedopulgar2.SetRotation(0.0f, 0.0f, z);
	contador = contador + 0.05f;
	*/
	/*
	float rotacion = 0.5f + contador2;
	
		if (rotacion <= 1.0f & contador3 == 0.0f) {
		
			_dedoindice1.SetRotation(rotacion, 0.0f, 0.0f);
			_dedomedio1.SetRotation(rotacion, 0.0f, 0.0f);
			_dedoanular1.SetRotation(rotacion, 0.0f, 0.0f);
			_dedopulgar1.SetRotation(rotacion, 0.0f, 0.0f);
			_dedoindice2.SetRotation(rotacion, 0.0f, 0.0f);
			_dedomedio2.SetRotation(rotacion, 0.0f, 0.0f);
			_dedoanular2.SetRotation(0.0f, 0.0f, rotacion);
			_dedopulgar2.SetRotation(0.0f, 0.0f, rotacion);
			
		contador2 = contador2 + 0.005f;
		
	}
	else if (rotacion >= 1.0f & contador3 == 0.0f) {
		contador3 = 1.0f;
	
	}
	else if (rotacion >= 0.25f & contador3 == 1.0f) {
		_dedoindice1.SetRotation(rotacion, 0.0f, 0.0f);
		_dedomedio1.SetRotation(rotacion, 0.0f, 0.0f);
		_dedoanular1.SetRotation(rotacion, 0.0f, 0.0f);
		_dedopulgar1.SetRotation(rotacion, 0.0f, 0.0f);
		_dedoindice2.SetRotation(rotacion, 0.0f, 0.0f);
		_dedomedio2.SetRotation(rotacion, 0.0f, 0.0f);
		_dedoanular2.SetRotation(0.0f, 0.0f, rotacion);
		_dedopulgar2.SetRotation(0.0f, 0.0f, rotacion);


		contador2 = contador2 - 0.005f;
	
	}
	else if (rotacion <= 0.25f & contador3 == 1.0f) {
		contador3 = 0.0f;
		
	}

	*/


	//PRIMER RENDER 
	_depth.Bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_shaderDepth.Activate();

	//dedoindice
	_shaderDepth.SetUniformMatrix("mvpMatrix", _lightC.GetViewProjection()* (_palma1.GetModelMatrix()*_dedoindice1.GetModelMatrix()));
	_falanges.Draw(GL_TRIANGLES);

	//dedoindice2
	_shaderDepth.SetUniformMatrix("mvpMatrix", _lightC.GetViewProjection()* (_palma1.GetModelMatrix()*_dedoindice1.GetModelMatrix()*_dedoindice2.GetModelMatrix()));
	_falanges.Draw(GL_TRIANGLES);


	//dedomedio
	_shaderDepth.SetUniformMatrix("mvpMatrix", _lightC.GetViewProjection()* (_palma1.GetModelMatrix()*_dedomedio1.GetModelMatrix()));
	_falanges.Draw(GL_TRIANGLES);


	//dedomedio2
	_shaderDepth.SetUniformMatrix("mvpMatrix", _lightC.GetViewProjection()* (_palma1.GetModelMatrix()*_dedomedio2.GetModelMatrix()));
	_falanges.Draw(GL_TRIANGLES);
	
	//dedoanular
	_shaderDepth.SetUniformMatrix("mvpMatrix", _lightC.GetViewProjection()* (_palma1.GetModelMatrix()*_dedoanular1.GetModelMatrix()));
	_falanges.Draw(GL_TRIANGLES);

	//dedoanular2
	_shaderDepth.SetUniformMatrix("mvpMatrix", _lightC.GetViewProjection()* (_palma1.GetModelMatrix()*_dedoanular2.GetModelMatrix()));
	_falanges.Draw(GL_TRIANGLES);

	//dedopulgar
	_shaderDepth.SetUniformMatrix("mvpMatrix", _lightC.GetViewProjection()* (_palma1.GetModelMatrix()*_dedopulgar1.GetModelMatrix()));
	_falanges.Draw(GL_TRIANGLES);

	//dedopulgar2
	_shaderDepth.SetUniformMatrix("mvpMatrix", _lightC.GetViewProjection()* (_palma1.GetModelMatrix()*_dedopulgar2.GetModelMatrix()));
	_falanges.Draw(GL_TRIANGLES);

	//Piso
	_shaderDepth.SetUniformMatrix("mvpMatrix", _lightC.GetViewProjection()* _piso.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);
   
	//palma
	_shaderDepth.SetUniformMatrix("mvpMatrix", _lightC.GetViewProjection()* _palma1.GetModelMatrix());
	_palma.Draw(GL_TRIANGLES);

	

	
	_shaderDepth.Deactivate();
	_depth.Unbind();
	glViewport(0, 0, 400, 400);
	

	//SEGUNDO RENDER 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//dedoindice1
	_shaderProgram.Activate();

	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_dedoindice1.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()*(_palma1.GetModelMatrix()*_dedoindice1.GetModelMatrix()));
	glm::vec3 newCameraindice = _camera.GetPosition();
	_shaderProgram.SetUniformf("cameraPosition", newCameraindice);
	_shaderProgram.SetUniformMatrix("ModelMatrix", _dedoindice1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightC.GetViewProjection());
	
	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_texture2.Bind();

	_falanges.Draw(GL_TRIANGLES);

	glActiveTexture(GL_TEXTURE1);
	_texture2.Unbind();
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind();

	//dedoindice2
	_shaderProgram.Activate();

	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_dedoindice2.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()*(_palma1.GetModelMatrix()*_dedoindice1.GetModelMatrix()*_dedoindice2.GetModelMatrix()));
	glm::vec3 newCameraindice2 = _camera.GetPosition();
	_shaderProgram.SetUniformf("cameraPosition", newCameraindice2);
	_shaderProgram.SetUniformMatrix("ModelMatrix", _dedoindice2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightC.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_texture2.Bind();

	_falanges.Draw(GL_TRIANGLES);

	glActiveTexture(GL_TEXTURE1);
	_texture2.Unbind();
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind();



	//dedomedio1
	_shaderProgram.Activate();

	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_dedomedio1.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()*(_palma1.GetModelMatrix()*_dedomedio1.GetModelMatrix()));
	glm::vec3 newCameramedio = _camera.GetPosition();
	_shaderProgram.SetUniformf("cameraPosition", newCameramedio);
	_shaderProgram.SetUniformMatrix("ModelMatrix", _dedomedio1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightC.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_texture2.Bind();

	_falanges.Draw(GL_TRIANGLES);

	glActiveTexture(GL_TEXTURE1);
	_texture2.Unbind();
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind();

	//dedomedio2
	_shaderProgram.Activate();

	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_dedomedio1.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()*(_palma1.GetModelMatrix()*_dedomedio1.GetModelMatrix()*_dedomedio2.GetModelMatrix()));
	glm::vec3 newCameramedio2 = _camera.GetPosition();
	_shaderProgram.SetUniformf("cameraPosition", newCameramedio2);
	_shaderProgram.SetUniformMatrix("ModelMatrix", _dedomedio2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightC.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_texture2.Bind();

	_falanges.Draw(GL_TRIANGLES);

	glActiveTexture(GL_TEXTURE1);
	_texture2.Unbind();
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind();

	//dedoanular1
	_shaderProgram.Activate();

	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_dedoanular1.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()*(_palma1.GetModelMatrix()*_dedoanular1.GetModelMatrix()));
	glm::vec3 newCameraanular = _camera.GetPosition();
	_shaderProgram.SetUniformf("cameraPosition", newCameraanular);
	_shaderProgram.SetUniformMatrix("ModelMatrix", _dedoanular1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightC.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_texture2.Bind();

	_falanges.Draw(GL_TRIANGLES);

	glActiveTexture(GL_TEXTURE1);
	_texture2.Unbind();
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind();

	//anular2
	_shaderProgram.Activate();

	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_dedoanular2.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()*(_palma1.GetModelMatrix()*_dedoanular1.GetModelMatrix()*_dedoanular2.GetModelMatrix()));
	glm::vec3 newCameraanular2 = _camera.GetPosition();
	_shaderProgram.SetUniformf("cameraPosition", newCameraanular2);
	_shaderProgram.SetUniformMatrix("ModelMatrix", _dedoanular2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightC.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_texture2.Bind();

	_falanges.Draw(GL_TRIANGLES);

	glActiveTexture(GL_TEXTURE1);
	_texture2.Unbind();
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind();

	//dedopulgar1
	_shaderProgram.Activate();

	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_dedopulgar1.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()*(_palma1.GetModelMatrix()*_dedopulgar1.GetModelMatrix()));
	glm::vec3 newCamerapulgar1 = _camera.GetPosition();
	_shaderProgram.SetUniformf("cameraPosition", newCamerapulgar1);
	_shaderProgram.SetUniformMatrix("ModelMatrix", _dedopulgar1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightC.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_texture2.Bind();

	_falanges.Draw(GL_TRIANGLES);

	glActiveTexture(GL_TEXTURE1);
	_texture2.Unbind();
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind();

	//pulgar2
	_shaderProgram.Activate();

	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_dedopulgar1.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()*(_palma1.GetModelMatrix()*_dedopulgar1.GetModelMatrix()*_dedopulgar2.GetModelMatrix()));
	glm::vec3 newCamerapulgar2 = _camera.GetPosition();
	_shaderProgram.SetUniformf("cameraPosition", newCamerapulgar2);
	_shaderProgram.SetUniformMatrix("ModelMatrix", _dedopulgar1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightC.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_texture2.Bind();

	_falanges.Draw(GL_TRIANGLES);

	glActiveTexture(GL_TEXTURE1);
	_texture2.Unbind();
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind();

	//PISO
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_piso.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _piso.GetModelMatrix());
	glm::vec3 newCamerapiso = _camera.GetPosition();
	_shaderProgram.SetUniformf("cameraPosition", newCamerapiso);
	_shaderProgram.SetUniformMatrix("ModelMatrix", _piso.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightC.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_texture3.Bind();
	glActiveTexture(GL_TEXTURE1);
	_depth.BindDepthMap();

	_mesh.Draw(GL_TRIANGLES);
	
	
	glActiveTexture(GL_TEXTURE0);
	_texture3.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_depth.UnbindDepthMap();

	_shaderProgram.Deactivate();


	//palma
	_shaderProgram.Activate();

	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_palma1.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _palma1.GetModelMatrix());
	glm::vec3 newCamerapalma= _camera.GetPosition();
	_shaderProgram.SetUniformf("cameraPosition", newCamerapalma);
	_shaderProgram.SetUniformMatrix("ModelMatrix", _palma1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("LightVPMatrix", _lightC.GetViewProjection());

	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_texture2.Bind();

	_palma.Draw(GL_TRIANGLES);

	glActiveTexture(GL_TEXTURE1);
	_texture2.Unbind();
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind();
	

	glutSwapBuffers(); //Cuando terminamos de renderear cambiamos los buffers 
}


void Idle()
{
	glutPostRedisplay();
}

void ReshapeWindow(int width, int height)
{
	glViewport(0, 0, width, height);
}

int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	glutInitContextVersion(4, 5);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Hello World GL");
	glutDisplayFunc(GameLoop);
	glutReshapeFunc(ReshapeWindow);
	glutIdleFunc(Idle);
	glewInit();

	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	std::cout << glGetString(GL_VERSION) << std::endl;

	ilInit();
	ilEnable(IL_ORIGIN_SET);
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

	Initialize();
	glutMainLoop();

	return 0;
}