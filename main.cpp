#define STB_IMAGE_IMPLEMENTATION

#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <math.h>

#include <glew.h>
#include <glfw3.h>

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
//para probar el importer
//#include<assimp/Importer.hpp>

#include "Window.h"
#include "Mesh.h"
#include "Shader_light.h"
#include "Camera.h"
#include "Texture.h"
#include "Sphere.h"
#include"Model.h"
#include "Skybox.h"
#include "Tierra.h"

//Para iluminación
#include "CommonValues.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "Material.h"

//Archivos Juegos
#include "Hacha.h"
#include "Bateo.h"
#include "Dados.h"
#include "Dardos.h"
#include "Bolos.h"
#include "Topos.h"

//Archivo Ambientación
#include "Ambientacion.h"

//Archivo Comida
#include "Comida.h"

//Archivo NPCs
#include "NPCs.h"
#include "main.h"

const float toRadians = 3.14159265f / 180.0f;

//Variables para el ciclo de dia y de noche
bool esDeDia = true;
float intensidad = 0.5f;  //Inicia de día
float velocidad = 0.0005f; //Velocidad de cambio de luz //valor original: 0.00005

Window mainWindow;

//Listas
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;
std::vector<Model*> objetosAmbientacion;
std::vector<Model*> objetosDados;
std::vector<Model*> objetosBateo;
std::vector<Model*> objetosBolos;
std::vector<Model*> objetosDardos;
std::vector<Model*> objetosHacha;
std::vector<Model*> objetosTopos;
std::vector<Model*> objetosComida;
std::vector<Model*> personajesNPCs;

//Camaras 
Camera camera;
Camera aerialCamera;
Camera terceraPersonaCamera;
Camera camaraPuestos;

//Texturas
Texture brickTexture;
Texture dirtTexture;
Texture plainTexture;
Texture pisoTexture;
Texture tierraTexture;

//Variables para modelos del puesto de lanzamiento de hacha
Model Stand1;
Model Hacha;
Model Reja;

//Variables para modelos del puesto de jaula de bateo
Model Stand2;
Model bardaBateo;
Model objetivoBateo;
Model cartelBateo;
Model bate;

//Variables para modelos del puesto de lanzamiento de dados
Model Stand3;
Model mesaDados;
Model dadoMario;
Model hongoRojo;
Model hongoVerde;
Model cuadroMario;
Model cuadroToad;
Model cuadroBowser;
Model cuadroWario;

//Variables para modelos del puesto de lanzamiento de dardos
Model Stand4;
Model baseDardos;
Model globoDardos;
Model tablaDardos;
Model dardo;

//Variables para modelos del puesto de bolos
Model Stand5;
Model bolo;
Model bolaBoliche;
Model mesaBoliche;
Model cartelBoliche;

//Variables para modelos del puesto de golpea al topo
Model Stand6;
Model MesaTopos;
Model TuboTopos;
Model Pirania;

//Variables para modelos del ambientación
Model banca;
Model luminaria1;
Model luminaria2;
Model luminaria3;
Model arbol1;
Model arbol2;
Model arbol3;
Model bote1;
Model bote2;
Model plantaDecorativa;
Model estantePremios;
Model luminariaTecho;

//Variables para modelos del puestos comida
Model palomitas;
Model helados;
Model algodones;

//Variables para modelos de NPCs
Model woodstock;
Model peppermint;
Model charlie;
Model carrie;
Model teri;
Model bowser;
Model kingBoo;
Model donkeyKong;
Model wario;

//Variables para modelos de personajes principales
Model gumball;
Model yoshi;
Model snoopy;

//Skybox
Skybox skybox;

//Materiales
Material Material_brillante;
Material Material_opaco;

//Sphere cabeza = Sphere(0.5, 20, 20);
GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;
static double limitFPS = 1.0 / 60.0;

//Luz direccional
DirectionalLight mainLight;
//para declarar varias luces de tipo pointlight

PointLight pointLights[MAX_POINT_LIGHTS];
SpotLight spotLights[MAX_SPOT_LIGHTS];
SpotLight pointLightsOff[1];
int camaraAnterior = -1; // Para saber la cámara anterior
bool yaApagueEnPuestos = false; // Para saber si ya apagué en cámara puestos



//Vertex Shader
static const char* vShader = "shaders/shader_light.vert";

//Fragment Shader
static const char* fShader = "shaders/shader_light.frag";

//Función de calculo de normales por promedio de vértices 
void calcAverageNormals(unsigned int* indices, unsigned int indiceCount, GLfloat* vertices, unsigned int verticeCount,
	unsigned int vLength, unsigned int normalOffset)
{
	for (size_t i = 0; i < indiceCount; i += 3)
	{
		unsigned int in0 = indices[i] * vLength;
		unsigned int in1 = indices[i + 1] * vLength;
		unsigned int in2 = indices[i + 2] * vLength;
		glm::vec3 v1(vertices[in1] - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1], vertices[in1 + 2] - vertices[in0 + 2]);
		glm::vec3 v2(vertices[in2] - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1], vertices[in2 + 2] - vertices[in0 + 2]);
		glm::vec3 normal = glm::cross(v1, v2);
		normal = glm::normalize(normal);

		in0 += normalOffset; in1 += normalOffset; in2 += normalOffset;
		vertices[in0] += normal.x; vertices[in0 + 1] += normal.y; vertices[in0 + 2] += normal.z;
		vertices[in1] += normal.x; vertices[in1 + 1] += normal.y; vertices[in1 + 2] += normal.z;
		vertices[in2] += normal.x; vertices[in2 + 1] += normal.y; vertices[in2 + 2] += normal.z;
	}

	for (size_t i = 0; i < verticeCount / vLength; i++)
	{
		unsigned int nOffset = i * vLength + normalOffset;
		glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
		vec = glm::normalize(vec);
		vertices[nOffset] = vec.x; vertices[nOffset + 1] = vec.y; vertices[nOffset + 2] = vec.z;
	}
}

void CreateObjects()
{
	unsigned int indices[] = {
		0, 3, 1,
		1, 3, 2,
		2, 3, 0,
		0, 1, 2
	};

	GLfloat vertices[] = {
		//	x      y      z			u	  v			nx	  ny    nz
			-1.0f, -1.0f, -0.6f,	0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
			0.0f, -1.0f, 1.0f,		0.5f, 0.0f,		0.0f, 0.0f, 0.0f,
			1.0f, -1.0f, -0.6f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,		0.5f, 1.0f,		0.0f, 0.0f, 0.0f
	};

	unsigned int floorIndices[] = {
		0, 2, 1,
		1, 2, 3
	};

	GLfloat floorVertices[] = {
		-10.0f, 0.0f, -10.0f,	0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, -10.0f,	10.0f, 0.0f,	0.0f, -1.0f, 0.0f,
		-10.0f, 0.0f, 10.0f,	0.0f, 10.0f,	0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, 10.0f,		10.0f, 10.0f,	0.0f, -1.0f, 0.0f
	};

	unsigned int vegetacionIndices[] = {
	   0, 1, 2,
	   0, 2, 3,
	   4,5,6,
	   4,6,7
	};

	GLfloat vegetacionVertices[] = {
		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.0f,		1.0f, 1.0f,		0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.0f,		0.0f, 1.0f,		0.0f, 0.0f, 0.0f,

		0.0f, -0.5f, -0.5f,		0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.0f, -0.5f, 0.5f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.5f,		1.0f, 1.0f,		0.0f, 0.0f, 0.0f,
		0.0f, 0.5f, -0.5f,		0.0f, 1.0f,		0.0f, 0.0f, 0.0f,
	};

	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 32, 12);
	meshList.push_back(obj1);

	Mesh* obj2 = new Mesh();
	obj2->CreateMesh(vertices, indices, 32, 12);
	meshList.push_back(obj2);

	Mesh* obj3 = new Mesh();
	obj3->CreateMesh(floorVertices, floorIndices, 32, 6);
	meshList.push_back(obj3);

	Mesh* obj4 = new Mesh();
	obj4->CreateMesh(vegetacionVertices, vegetacionIndices, 64, 12);
	meshList.push_back(obj4);

	calcAverageNormals(indices, 12, vertices, 32, 8, 5);

	calcAverageNormals(vegetacionIndices, 12, vegetacionVertices, 64, 8, 5);
}

void CrearDado()
{
	unsigned int cubo_indices[] = {
		// front
		0, 1, 2,
		2, 3, 0,

		// back
		8, 9, 10,
		10, 11, 8,

		// left
		12, 13, 14,
		14, 15, 12,
		// bottom
		16, 17, 18,
		18, 19, 16,
		// top
		20, 21, 22,
		22, 23, 20,

		// right
		4, 5, 6,
		6, 7, 4,

	};

	GLfloat cubo_vertices[] = {
		// front
		//x		y		z		S		T			NX		NY		NZ
		-0.5f, -0.5f,  0.5f,	0.26f,  0.34f,		0.0f,	0.0f,	-1.0f,	//0
		0.5f, -0.5f,  0.5f,		0.49f,	0.34f,		0.0f,	0.0f,	-1.0f,	//1
		0.5f,  0.5f,  0.5f,		0.49f,	0.66f,		0.0f,	0.0f,	-1.0f,	//2
		-0.5f,  0.5f,  0.5f,	0.26f,	0.66f,		0.0f,	0.0f,	-1.0f,	//3
		// right
		//x		y		z		S		T
		0.5f, -0.5f,  0.5f,	    0.0f,  0.0f,		-1.0f,	0.0f,	0.0f,
		0.5f, -0.5f,  -0.5f,	1.0f,	0.0f,		-1.0f,	0.0f,	0.0f,
		0.5f,  0.5f,  -0.5f,	1.0f,	1.0f,		-1.0f,	0.0f,	0.0f,
		0.5f,  0.5f,  0.5f,	    0.0f,	1.0f,		-1.0f,	0.0f,	0.0f,
		// back
		-0.5f, -0.5f, -0.5f,	0.0f,  0.0f,		0.0f,	0.0f,	1.0f,
		0.5f, -0.5f, -0.5f,		1.0f,	0.0f,		0.0f,	0.0f,	1.0f,
		0.5f,  0.5f, -0.5f,		1.0f,	1.0f,		0.0f,	0.0f,	1.0f,
		-0.5f,  0.5f, -0.5f,	0.0f,	1.0f,		0.0f,	0.0f,	1.0f,

		// left
		//x		y		z		S		T
		-0.5f, -0.5f,  -0.5f,	0.0f,  0.0f,		1.0f,	0.0f,	0.0f,
		-0.5f, -0.5f,  0.5f,	1.0f,	0.0f,		1.0f,	0.0f,	0.0f,
		-0.5f,  0.5f,  0.5f,	1.0f,	1.0f,		1.0f,	0.0f,	0.0f,
		-0.5f,  0.5f,  -0.5f,	0.0f,	1.0f,		1.0f,	0.0f,	0.0f,

		// bottom
		//x		y		z		S		T
		-0.5f, -0.5f,  0.5f,	0.0f,  0.0f,		0.0f,	1.0f,	0.0f,
		0.5f,  -0.5f,  0.5f,	1.0f,	0.0f,		0.0f,	1.0f,	0.0f,
		 0.5f,  -0.5f,  -0.5f,	1.0f,	1.0f,		0.0f,	1.0f,	0.0f,
		-0.5f, -0.5f,  -0.5f,	0.0f,	1.0f,		0.0f,	1.0f,	0.0f,

		//UP
		 //x		y		z		S		T
		 -0.5f, 0.5f,  0.5f,	0.0f,  0.0f,		0.0f,	-1.0f,	0.0f,
		 0.5f,  0.5f,  0.5f,	1.0f,	0.0f,		0.0f,	-1.0f,	0.0f,
		  0.5f, 0.5f,  -0.5f,	1.0f,	1.0f,		0.0f,	-1.0f,	0.0f,
		 -0.5f, 0.5f,  -0.5f,	0.0f,	1.0f,		0.0f,	-1.0f,	0.0f,
	};

	Mesh* dado = new Mesh();
	dado->CreateMesh(cubo_vertices, cubo_indices, 192, 36);
	meshList.push_back(dado);
}

void CreateShaders()
{
	Shader* shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);
}

int main()
{
	mainWindow = Window(1366, 768); // 1280, 1024 or 1024, 768
	mainWindow.Initialise();

	CreateObjects();
	CrearDado();
	CreateShaders();

	//Camara libre
	camera = Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -60.0f, 0.0f, 0.3f, 0.5f);


	aerialCamera = Camera(glm::vec3(0.0f, 450.0f, 0.0f),  //Posición muy arriba
		glm::vec3(0.0f, 1.0f, 0.0f),                      //Vector Up
		-90.0f,                                           //Yaw
		-89.9f,                                           //Pitch casi vertical (evita ser -90 exacto)
		0.0f, 0.0f);                                      //Sin movimiento o rotación

	//Cámara tercera persona
	terceraPersonaCamera = Camera(glm::vec3(2.0f, 2.0f, 0.5f),  //Posición detrás del coche
		glm::vec3(0.0f, 1.0f, 0.0f),
		180.0f, 0.0f, 0.3f, 0.5f);                              //Sin movimiento

	//Cámara para puestos
	camaraPuestos = Camera(glm::vec3(-80.0f, 20.0f, -40.0f),   //Frente a un puesto
		glm::vec3(0.0f, 1.0f, 0.0f),
		270.0f, 0.0f, 0.0f, 0.0f);

	brickTexture = Texture("Textures/brick.png");
	brickTexture.LoadTextureA();
	dirtTexture = Texture("Textures/dirt.png");
	dirtTexture.LoadTextureA();
	plainTexture = Texture("Textures/plain.png");
	plainTexture.LoadTextureA();
	pisoTexture = Texture("Textures/pasto.png");
	pisoTexture.LoadTextureA();
	tierraTexture = Texture("Textures/tierra.jpg");
	tierraTexture.LoadTextureA();

	//Carga de modelos del puesto de lanzamiento de hacha
	Stand1 = Model();
	Stand1.LoadModel("Models/StandHacha.obj");
	Hacha = Model();
	Hacha.LoadModel("Models/Hacha.obj");
	Reja = Model();
	Reja.LoadModel("Models/Reja.obj");

	//Carga de modelos del puesto de jaula de bateo
	Stand2 = Model();
	Stand2.LoadModel("Models/StandBateo.obj");
	bardaBateo = Model();
	bardaBateo.LoadModel("Models/bardaBateo.obj");
	objetivoBateo = Model();
	objetivoBateo.LoadModel("Models/objetivoBateo.obj");
	cartelBateo = Model();
	cartelBateo.LoadModel("Models/cartelBateo.obj");
	bate = Model();
	bate.LoadModel("Models/bate.obj");

	//Carga de modelos del puesto de dados
	Stand3 = Model();
	Stand3.LoadModel("Models/StandDados.obj");
	mesaDados = Model();
	mesaDados.LoadModel("Models/mesaDados.obj");
	dadoMario = Model();
	dadoMario.LoadModel("Models/dado.obj");
	hongoRojo = Model();
	hongoRojo.LoadModel("Models/hongoRojo.obj");
	hongoVerde = Model();
	hongoVerde.LoadModel("Models/hongoVerde.obj");
	cuadroMario = Model();
	cuadroMario.LoadModel("Models/cuadroMario.obj");
	cuadroToad = Model();
	cuadroToad.LoadModel("Models/cuadroToad.obj");
	cuadroBowser = Model();
	cuadroBowser.LoadModel("Models/cuadroBowser.obj");
	cuadroWario = Model();
	cuadroWario.LoadModel("Models/cuadroWario.obj");

	//Carga de modelos del puesto de dardos
	Stand4 = Model();
	Stand4.LoadModel("Models/StandDardos.obj");
	baseDardos = Model();
	baseDardos.LoadModel("Models/BaseDardos.obj");
	globoDardos = Model();
	globoDardos.LoadModel("Models/GloboDardos.obj");
	tablaDardos = Model();
	tablaDardos.LoadModel("Models/TablaDardos.obj");
	dardo = Model();
	dardo.LoadModel("Models/Dardo.obj");

	//Carga de modelos del puesto de bolos
	Stand5 = Model();
	Stand5.LoadModel("Models/StandBolos.obj");
	bolo = Model();
	bolo.LoadModel("Models/bolo.obj");
	bolaBoliche = Model();
	bolaBoliche.LoadModel("Models/bolaBoliche.obj");
	cartelBoliche = Model();
	cartelBoliche.LoadModel("Models/cartelBoliche.obj");
	mesaBoliche = Model();
	mesaBoliche.LoadModel("Models/mesaBoliche.obj");

	//Carga de modelos del puesto de golpea al topo
	Stand6 = Model();
	Stand6.LoadModel("Models/StandTopos.obj");
	MesaTopos = Model();
	MesaTopos.LoadModel("Models/MesaTopos.obj");
	TuboTopos = Model();
	TuboTopos.LoadModel("Models/TuboTopos.obj");
	Pirania = Model();
	Pirania.LoadModel("Models/Pirania.obj");

	//Carga de modelos de ambientación
	banca = Model();
	banca.LoadModel("Models/banca.obj");
	luminaria1 = Model();
	luminaria1.LoadModel("Models/luminaria1.obj");
	luminaria2 = Model();
	luminaria2.LoadModel("Models/luminaria2.obj");
	luminaria3 = Model();
	luminaria3.LoadModel("Models/luminaria3.obj");
	arbol1 = Model();
	arbol1.LoadModel("Models/arbol1.obj");
	arbol2 = Model();
	arbol2.LoadModel("Models/arbol2.obj");
	arbol3 = Model();
	arbol3.LoadModel("Models/arbol3.obj");
	bote1 = Model();
	bote1.LoadModel("Models/bote1.obj");
	bote2 = Model();
	bote2.LoadModel("Models/bote2.obj");
	plantaDecorativa = Model();
	plantaDecorativa.LoadModel("Models/plantaDecorativa.obj");
	estantePremios = Model();
	estantePremios.LoadModel("Models/estantePremios.obj");
	luminariaTecho = Model();
	luminariaTecho.LoadModel("Models/luminariaTecho.obj");

	//Carga de modelos de comida
	palomitas = Model();
	palomitas.LoadModel("Models/palomitas.obj");
	helados = Model();
	helados.LoadModel("Models/helados.obj");
	algodones = Model();
	algodones.LoadModel("Models/algodones.obj");
	
	//Carga de modelos de NPCs
	woodstock = Model();
	woodstock.LoadModel("Models/Woodstock.obj");
	peppermint = Model();
	peppermint.LoadModel("Models/Peppermint.obj");
	charlie = Model();
	charlie.LoadModel("Models/Charlie.obj");

	//Carga de modelos de los personajes principales
	gumball = Model();
	gumball.LoadModel("Models/gumball.obj");
	yoshi = Model();
	yoshi.LoadModel("Models/yoshi.obj");
	snoopy = Model();
	snoopy.LoadModel("Models/snoopy.obj");

	//push_back de modelos del puesto de lanzamiento de hacha
	objetosHacha.push_back(&Stand1);
	objetosHacha.push_back(&Hacha);
	objetosHacha.push_back(&Reja);
	objetosHacha.push_back(&tablaDardos);
	objetosHacha.push_back(&objetivoBateo);

	//push_back de modelos del puesto de jaula de bateo
	objetosBateo.push_back(&Stand2);
	objetosBateo.push_back(&bardaBateo);
	objetosBateo.push_back(&objetivoBateo);
	objetosBateo.push_back(&cartelBateo);
	objetosBateo.push_back(&bate);

	//push_back de modelos del puesto de dados
	objetosDados.push_back(&Stand3);
	objetosDados.push_back(&mesaDados);
	objetosDados.push_back(&dadoMario);
	objetosDados.push_back(&hongoRojo);
	objetosDados.push_back(&hongoVerde);
	objetosDados.push_back(&cuadroMario);
	objetosDados.push_back(&cuadroToad);
	objetosDados.push_back(&cuadroBowser);
	objetosDados.push_back(&cuadroWario);

	//push_back de modelos del puesto de dardos
	objetosDardos.push_back(&Stand4);
	objetosDardos.push_back(&baseDardos);
	objetosDardos.push_back(&globoDardos);
	objetosDardos.push_back(&tablaDardos);
	objetosDardos.push_back(&dardo);

	//push_back de modelos del puesto de bolos
	objetosBolos.push_back(&Stand5);
	objetosBolos.push_back(&bolo);
	objetosBolos.push_back(&bolaBoliche);
	objetosBolos.push_back(&cartelBoliche);
	objetosBolos.push_back(&mesaBoliche);

	//push_back de modelos del puesto de golpea al topo
	objetosTopos.push_back(&Stand6);
	objetosTopos.push_back(&MesaTopos);
	objetosTopos.push_back(&TuboTopos);
	objetosTopos.push_back(&Pirania);

	//push_back de modelos de comida
	objetosComida.push_back(&palomitas);
	objetosComida.push_back(&helados);
	objetosComida.push_back(&algodones);

	//push_back de modelos de NPCs
	personajesNPCs.push_back(&woodstock);
	personajesNPCs.push_back(&peppermint);
	personajesNPCs.push_back(&charlie);

	//push_back de modelos de ambientación
	objetosAmbientacion.push_back(&banca);
	objetosAmbientacion.push_back(&luminaria1);
	objetosAmbientacion.push_back(&luminaria2);
	objetosAmbientacion.push_back(&luminaria3);
	objetosAmbientacion.push_back(&arbol1);
	objetosAmbientacion.push_back(&arbol2);
	objetosAmbientacion.push_back(&arbol3);
	objetosAmbientacion.push_back(&bote1);
	objetosAmbientacion.push_back(&bote2);
	objetosAmbientacion.push_back(&plantaDecorativa);
	objetosAmbientacion.push_back(&estantePremios);
	objetosAmbientacion.push_back(&luminariaTecho);

	//Skybox
	std::vector<std::string> skyboxFaces;

	skyboxFaces.push_back("Textures/Skybox/right.tga");
	skyboxFaces.push_back("Textures/Skybox/left.tga");
	skyboxFaces.push_back("Textures/Skybox/down.tga");
	skyboxFaces.push_back("Textures/Skybox/up.tga");
	skyboxFaces.push_back("Textures/Skybox/front.tga");
	skyboxFaces.push_back("Textures/Skybox/back.tga");

	skybox = Skybox(skyboxFaces);

	Material_brillante = Material(4.0f, 256);
	Material_opaco = Material(0.3f, 4);

	//Luz direccional, sólo 1 y siempre debe de existir 
	//Para la luz del sol
	//mainLight = DirectionalLight(1.0f, 1.0f, 1.0f,
	//	0.3f, 0.3f,
	//	0.0f, 0.0f, -1.0f);
	
	unsigned int pointLightCount = 0;  //Contador de luces puntuales

	//Empiezan luces de los postes
	
	pointLights[0] = PointLight(1.0f, 1.0f, 1.0f,   //luz primer poste
		2.0f, 0.5f,
		115.0f, 35.0f, -70.0f,
		1.0f,	0.022f,	0.0019f);
	pointLightCount++;

	pointLights[1] = PointLight(1.0f, 1.0f, 1.0f,   //luz segundo poste			115.0f, -1.0f, 77.0
		2.0f, 0.5f,
		115.0f, 35.0f, 70.0f,
		1.0f, 0.022f, 0.0019f);
	pointLightCount++;
	
	pointLights[2] = PointLight(1.0f, 1.0f, 1.0f,   //luz tercer poste			-15.0f, -1.0f, -77.0f
		2.0f, 0.5f,
		-15.0f, 35.0f, -70.0f,
		1.0f, 0.022f, 0.0019f);
	pointLightCount++;

	
	pointLights[3] = PointLight(1.0f, 1.0f, 1.0f,   //luz cuarto poste			-15.0f, -1.0f, 77.0f
		2.0f, 0.5f,
		-15.0f, 35.0f, 70.0f,
		1.0f, 0.022f, 0.0019f);
	pointLightCount++;

	pointLights[4] = PointLight(1.0f, 1.0f, 1.0f,   //luz cuarto poste			-145.0f, -1.0f, -77.0f
		2.0f, 0.5f,
		-145.0f, 35.0f, -70.0f,
		1.0f, 0.022f, 0.0019f);
	pointLightCount++;

	pointLights[5] = PointLight(1.0f, 1.0f, 1.0f,   //luz cuarto poste			-145.0f, -1.0f, 77.0
		2.0f, 0.5f,
		-145.0f, 35.0f, 70.0f,
		1.0f, 0.022f, 0.0019f);
	pointLightCount++;
	
	// Empiezan spotLights     hacha
	
	unsigned int spotLightCount = 0;
	spotLights[0] = SpotLight(1.0f, 1.0f, 1.0f,		//Luz bateo
		2.0f, 5.0f,		
		-80.2f, 50.3f, -140.0f,	//Posicion
		0.0f, -1.0f, 0.0f,		//A donde apunta			0.0f, 0.1f, 0.0f
		0.0f, 0.08f, 0.0f,		//coeficientes
		30.0f);					//rango(cono de luz)
	spotLightCount++;

	spotLights[1] = SpotLight(1.0f, 1.0f, 1.0f,		//Luz dardos
		2.0f, 5.0f,
		49.9f, 50.3f, -140.0f,
		0.0f, -1.0f, 0.0f,		
		0.0f, 0.08f, 0.0f,		
		30.0f);					
	spotLightCount++;

	spotLights[2] = SpotLight(1.0f, 1.0f, 1.0f,		//Luz dados
		2.0f, 5.0f,
		180.0f, 50.3f, -140.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, 0.08f, 0.0f,
		30.0f);
	spotLightCount++;

	spotLights[3] = SpotLight(1.0f, 1.0f, 1.0f,		//luz hacha
		2.0f, 5.0f,
		180.0f, 50.0f, 140.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, 0.08f, 0.0f,
		30.0f);
	spotLightCount++;

	spotLights[4] = SpotLight(1.0f, 1.0f, 1.0f,		//Luz topos
		2.0f, 5.0f,
		50.0f, 50.3f, 140.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, 0.08f, 0.0f,
		30.0f);
	spotLightCount++;

	spotLights[5] = SpotLight(1.0f, 1.0f, 1.0f,		//Luz bolos
		2.0f, 5.0f,
		-80.0f, 50.3f, 140.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, 0.08f, 0.0f,
		30.0f);
	spotLightCount++;

	GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0, uniformEyePosition = 0,
		uniformSpecularIntensity = 0, uniformShininess = 0;
	GLuint uniformColor = 0;
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 1000.0f);

	glm::mat4 model(1.0);
	glm::mat4 modelaux(1.0);
	glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::vec3 posicionModelo = glm::vec3(-90.0f, -1.0f, 0.0f); // posición inicial de Modelos

	//Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{
		GLfloat now = glfwGetTime();
		deltaTime = now - lastTime;
		deltaTime += (now - lastTime) / limitFPS;
		lastTime = now;

		//Recibir eventos del usuario
		glfwPollEvents();
		
		int camaraActual = mainWindow.getCamaraActiva();

		// --- Si estoy en cámara aérea, apagar luces SIEMPRE
		if (camaraActual == 1) {
			for (int i = 0; i < MAX_SPOT_LIGHTS; i++) {
				mainWindow.getLucesSpot()[i] = false;
			}
		}

		// --- Si CAMBIO a cámara puestos, apagar luces solo una vez
		if (camaraActual == 3 && camaraAnterior != 3) {
			for (int i = 0; i < MAX_SPOT_LIGHTS; i++) {
				mainWindow.getLucesSpot()[i] = false;
			}
			yaApagueEnPuestos = true;
		}

		// --- Si CAMBIO a otra cámara diferente de puestos, resetear la bandera
		if (camaraActual != 3) {
			yaApagueEnPuestos = false;
		}

		// Guardar la cámara actual para comparar en el siguiente frame
		camaraAnterior = camaraActual;


		//variables para control de camara y personajes
		glm::vec3 cameraPos = camera.getCameraPosition();
		glm::vec3 cameraDir = camera.getCameraDirection();
		float angulo = atan2(terceraPersonaCamera.getCameraDirection().x, terceraPersonaCamera.getCameraDirection().z);
		Camera* activeCamera;

		//Switch que controla la camara activa 
		switch (mainWindow.getCamaraActiva()) {
		case 0:
			activeCamera = &camera;
			break;
		case 1:
			activeCamera = &aerialCamera;
			break;

		case 2: {
			//Dirección que apunta la cámara (sin componente Y)
			glm::vec3 forward = glm::normalize(glm::vec3(terceraPersonaCamera.getCameraDirection().x, 0.0f, terceraPersonaCamera.getCameraDirection().z));

			//Offset detrás y arriba del modelo
			glm::vec3 camOffset = -forward * 23.0f + glm::vec3(0.0f, 10.5f, 0.0f);

			//Posición de la cámara = posición del modelo + offset
			glm::vec3 camPos = posicionModelo + camOffset;

			terceraPersonaCamera.setPosition(camPos);
			activeCamera = &terceraPersonaCamera;
			break;
		}
		case 3:
			activeCamera = &camaraPuestos;
			break;
		default:
			activeCamera = &camera; //cámara libre
			break;
		}

		GLfloat xChange = mainWindow.getXChange();
		GLfloat yChange = mainWindow.getYChange();

		//Switch para control de mouse en la camara activa
		switch (mainWindow.getCamaraActiva()) {
		case 0: camera.mouseControl(xChange, yChange); camera.keyControl(mainWindow.getsKeys(), deltaTime); break;
		case 1: aerialCamera.mouseControl(xChange, yChange); break;
		case 2:
			terceraPersonaCamera.mouseControl(xChange, yChange);
			glm::vec3 forward = glm::normalize(glm::vec3(terceraPersonaCamera.getCameraDirection().x, 0.0f, terceraPersonaCamera.getCameraDirection().z));
			glm::vec3 right = glm::normalize(glm::cross(forward, glm::vec3(0.0f, 1.0f, 0.0f)));
			if (mainWindow.getsKeys()[GLFW_KEY_W])
				posicionModelo += forward * deltaTime * 1.5f;
			if (mainWindow.getsKeys()[GLFW_KEY_S])
				posicionModelo -= forward * deltaTime * 1.5f;
			if (mainWindow.getsKeys()[GLFW_KEY_A])
				posicionModelo -= right * deltaTime * 1.5f;
			if (mainWindow.getsKeys()[GLFW_KEY_D])
				posicionModelo += right * deltaTime * 1.5f;
			break;
		case 3:
			camaraPuestos.mouseControl(xChange, yChange);

			// Caso para mover la cámara a diferentes puestos DEFAULT EN BATEO
			if (mainWindow.getsKeys()[GLFW_KEY_X]) {
				camaraPuestos.setYaw(-90.0f);
				camaraPuestos.setPosition(glm::vec3(-80.0f, 20.0f, -40.0f)); // Puesto 1(BATEO)
			}
			if (mainWindow.getsKeys()[GLFW_KEY_C]) {
				camaraPuestos.setYaw(-90.0f);
				camaraPuestos.setPosition(glm::vec3(50.0f, 20.0f, -40.0f)); // Puesto 1(DARDOS)
			}
			if (mainWindow.getsKeys()[GLFW_KEY_V]) {
				camaraPuestos.setYaw(-90.0f);
				camaraPuestos.setPosition(glm::vec3(180.0f, 20.0f, -40.0f));  // Puesto 2(DADOS)
			}
			if (mainWindow.getsKeys()[GLFW_KEY_B]) {
				camaraPuestos.setYaw(90.0f);
				camaraPuestos.setPosition(glm::vec3(180.0f, 20.0f, 40.0f));     // Puesto 3(HACHA)
			}
			if (mainWindow.getsKeys()[GLFW_KEY_N]) {
				camaraPuestos.setYaw(90.0f);
				camaraPuestos.setPosition(glm::vec3(50.0f, 20.0f, 40.0f));   // Puesto 4 (TOPOS)
			}
			if (mainWindow.getsKeys()[GLFW_KEY_M]) {
				camaraPuestos.setYaw(90.0f);
				camaraPuestos.setPosition(glm::vec3(-80.0f, 20.0f, 40.0f));   // Puesto 4 (BOLICHE)
			}
			break;
		}

		//Clear the window
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		skybox.DrawSkybox(camera.calculateViewMatrix(), projection);
		shaderList[0].UseShader();
		uniformModel = shaderList[0].GetModelLocation();
		uniformProjection = shaderList[0].GetProjectionLocation();
		uniformView = shaderList[0].GetViewLocation();
		uniformEyePosition = shaderList[0].GetEyePositionLocation();
		uniformColor = shaderList[0].getColorLocation();

		//Información en el shader de intensidad especular y brillo
		uniformSpecularIntensity = shaderList[0].GetSpecularIntensityLocation();
		uniformShininess = shaderList[0].GetShininessLocation();

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(activeCamera->calculateViewMatrix()));
		glUniform3f(uniformEyePosition,
			activeCamera->getCameraPosition().x,
			activeCamera->getCameraPosition().y,
			activeCamera->getCameraPosition().z);

		
		//Bloque para control de lamparas y cuales se envian al shader
		SpotLight spotLightsToSend[MAX_SPOT_LIGHTS];
		unsigned int activeSpotLights = 0;
		for (int i = 0; i < MAX_SPOT_LIGHTS; i++) {
			if (mainWindow.getLucesSpot()[i]) { // Solo enviar las luces que estén encendidas
				spotLightsToSend[activeSpotLights++] = spotLights[i];
			}
		}
		shaderList[0].SetSpotLights(spotLightsToSend, activeSpotLights);


		//Bloque para ciclo de día y de noche 
		if (esDeDia) {
			intensidad -= velocidad;
			if (intensidad <= 0.005f) {
				intensidad = 0.005f;  //Mínimo de noche
				esDeDia = false;
			}
		}
		else {
			intensidad += velocidad;
			if (intensidad >= 0.9f) {
				intensidad = 0.9f;  //Máximo de día
				esDeDia = true;
			}
		}
		mainLight = DirectionalLight(1.0f, 1.0f, 1.0f,  //Color
			intensidad * 0.3f,  //Intensidad ambiental (más baja)
			intensidad,  // Intensidad difusa (más fuerte)
			0.0f, -1.0f, 0.0f);  //Dirección
		shaderList[0].SetDirectionalLight(&mainLight);

		//Bloque para control de postes automaticos
		if (intensidad <= 0.09) {
			shaderList[0].SetPointLights(pointLights, pointLightCount);      // lámpara encendida
		}
		else if (intensidad >= 0.3){
			shaderList[0].SetPointLights(pointLightsOff, 0);  // lámpara apagada
		}

		//Piso
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(30.0f, 1.0f, 30.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));
		pisoTexture.UseTexture();
		Material_opaco.UseMaterial(uniformSpecularIntensity, uniformShininess);
		meshList[2]->RenderMesh();

		//Tierra
		tierra(model, uniformModel, tierraTexture, meshList);

		//Redenrizado del puesto de lanzamiento de hacha
		model = glm::mat4(1.0);
		hacha(model, uniformModel, objetosHacha);

		//Redenrizado del puesto de jaula de bateo
		bateo(model, uniformModel, objetosBateo);

		//Redenrizado del puesto de dados
		dados(model, uniformModel, objetosDados);

		//Redenrizado del puesto de dardos
		dardos(model, uniformModel, objetosDardos);

		////Redenrizado del puesto de bolos
		bolos(model, uniformModel, objetosBolos);

		//Redenrizado del puesto de golpea al topo
		topos(model, uniformModel, objetosTopos);
		
		////Redenrizado de ambientación
		ambientacion(model, uniformModel, objetosAmbientacion);

		//Redenrizado de comida
		comida(model, uniformModel, objetosComida);

		//Renderizado de NPCs
		NPCs(model, uniformModel, personajesNPCs);

		//Renderizado de personajes principales  
		//(Para utilizar un personaje distinto comenta el personaje actual y descomenta el que quieras usar)
		////gumball
		//model = glm::mat4(1.0);
		//model = glm::translate(model, posicionModelo);
		//model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
		//model = glm::rotate(model, angulo, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//gumball.RenderModel();
		
		////yoshi
		//model = glm::mat4(1.0);
		//model = glm::translate(model, posicionModelo);
		//model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
		//model = glm::rotate(model, angulo, glm::vec3(0.0f, 1.0f, 0.0f));
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//yoshi.RenderModel();
		
		//snoopy
		model = glm::mat4(1.0);
		model = glm::translate(model, posicionModelo);
		model = glm::scale(model, glm::vec3(22.0f, 22.0f, 22.0f));
		model = glm::rotate(model, angulo, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		snoopy.RenderModel();

		glUseProgram(0);
		mainWindow.swapBuffers();
	}
	return 0;
}