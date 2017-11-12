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

Mesh _mesh;
ShaderProgram _shaderProgram;
Transform _transform;
Transform _transform2;
Camera _camera;
Texture2D _texture;
Texture2D _texture2;
Texture2D _texture3;

void Initialize()
{
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


	std::vector<unsigned int> indices;
	indices.push_back(0); indices.push_back(1); indices.push_back(2);
	indices.push_back(0); indices.push_back(2); indices.push_back(3);
	//Cara Derecha
	indices.push_back(4); indices.push_back(5); indices.push_back(6);
	indices.push_back(4); indices.push_back(6); indices.push_back(7);
	//Cara Izquierda
	indices.push_back(8); indices.push_back(9); indices.push_back(10);
	indices.push_back(8); indices.push_back(10); indices.push_back(11);
	//Cara Atras
	indices.push_back(12); indices.push_back(13); indices.push_back(14);
	indices.push_back(12); indices.push_back(14); indices.push_back(15);
	//Cara Arriba
	indices.push_back(16); indices.push_back(17); indices.push_back(18);
	indices.push_back(16); indices.push_back(18); indices.push_back(19);
	//Cara Abajo
	indices.push_back(20); indices.push_back(21); indices.push_back(22);
	indices.push_back(20); indices.push_back(22); indices.push_back(23);

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

	_transform2.SetPosition(0.0f, -12.0f, 0.0f);
	_transform2.SetScale(10.0f, 2.0f, 10.0f);

	//_camera.SetOrthographic(1.0f, 1.0f); Esto convierte la cámara en 2D
}

void GameLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpiamos el buffer de control y el de profundidad. Siempre hacerlo al inicio del frame

	_camera.SetPosition(0.0f, 0.0f, 25.0f);

	_transform.Rotate(0.01f, 0.01f, 0.01f, true);

	_shaderProgram.Activate();

	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix());
	glm::vec3 newCamera = _camera.GetPosition();
	_shaderProgram.SetUniformf("cameraPosition", newCamera);
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix());
	
	glActiveTexture(GL_TEXTURE0);
	_texture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_texture2.Bind();
	
	_mesh.Draw(GL_TRIANGLES);

	glActiveTexture(GL_TEXTURE1);
	_texture2.Unbind();
	glActiveTexture(GL_TEXTURE0);
	_texture.Unbind(); //Geometría 1
	

	_shaderProgram.SetUniformMatrix("normalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform2.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform2.GetModelMatrix());
	_shaderProgram.SetUniformf("cameraPosition", newCamera);
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform2.GetModelMatrix());
	
	glActiveTexture(GL_TEXTURE0);
	_texture3.Bind();
	
	_mesh.Draw(GL_TRIANGLES);

	glActiveTexture(GL_TEXTURE0);
	_texture3.Unbind(); //Geometría 2
	

	_shaderProgram.Deactivate();

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