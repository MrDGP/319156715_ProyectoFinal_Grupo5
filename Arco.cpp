#include "Arco.h"

const float toRadians = 3.14159265f / 180.0f;	

std::vector<glm::vec2> mensajeLetrero;
GLfloat tiempoLetrero = 0.0;
glm::vec2 toffset = glm::vec2(0.0f, 0.0f);
int posicionLetrero = 0;
int mensajeLetreroTamaño = 0;
float angulovaria = 0.0f;

//Animación puertas
float anguloPuerta = 0.0f;
bool abrirPuerta = true;
float velocidadPuerta = 0.0f;

void inicializarMensajeLetrero() {

	if (!mensajeLetrero.empty()) return;  //Si ya hay elementos, se salta las instrucción porque ya esta inicializado

	mensajeLetrero = {
		{0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f}, // Espacios
		{0.2f, 0.0f}, {0.4f, 0.0f}, {0.6f, 0.0f}, {0.8f, 0.0f}, {0.0f, -0.2f}, {0.2f, -0.2f}, {0.4f, -0.2f}, {0.6f, -0.2f}, // P, R, O, Y, E, C, T, O
		{0.0f, 0.0f}, // Espacio
		{0.8f, -0.2f}, {0.0f, -0.4f}, {0.2f, -0.4f}, {0.4f, -0.4f}, {0.6f, -0.4f}, {0.8f, -0.4f},// C, G, E, I, H, C
		{0.0f, 0.0f}, // Espacio
		{0.0f, -0.6f}, {0.2f, -0.6f}, {0.4f, -0.6f}, {0.6f, -0.6f}, {0.8f, -0.6f}, // F, E, R, I, A
		{0.0f, 0.0f}, {0.0f, 0.0f} // Espacios
	};

	mensajeLetreroTamaño = mensajeLetrero.size() - 1;
}

void arco(glm::mat4 model, GLuint uniformModel, GLuint uniformTextureOffset, std::vector<Model*> objetosArco, float deltaTime, Texture& letrero, std::vector<Mesh*> meshList) {

	inicializarMensajeLetrero();

	angulovaria += 0.5f * deltaTime;
	velocidadPuerta = 0.2f;

	if (abrirPuerta) {
		anguloPuerta += velocidadPuerta * deltaTime;
		if (anguloPuerta >= 90.0f) {
			anguloPuerta = 90.0f;
			abrirPuerta = false;
		}
	}
	else {
		anguloPuerta -= velocidadPuerta * deltaTime;
		if (anguloPuerta <= 0.0f) {
			anguloPuerta = 0.0f;
			abrirPuerta = true;
		}
	}

	glm::mat4 modelaux(1.0);

	//Arco
	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(260.0f, -1.0f, 0.0f));
	model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosArco[0]->RenderModel();

	//Puerta 1
	modelaux = model;
	model = glm::translate(model, glm::vec3(8.71f, 0.02f, -0.18f));
	model = glm::rotate(model, glm::radians(-anguloPuerta), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosArco[1]->RenderModel();
	model = modelaux;

	//Puerta 2
	modelaux = model;
	model = glm::translate(model, glm::vec3(-8.71f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::radians(anguloPuerta), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosArco[2]->RenderModel();
	model = modelaux;

	//Textura con movimiento para el letrero
	if (tiempoLetrero >= 40.0f) {
		posicionLetrero += 1;
		tiempoLetrero = 0.0f;
		if (posicionLetrero == mensajeLetreroTamaño) {
			posicionLetrero = 0;
		}
	}

	tiempoLetrero += deltaTime;

	toffset = mensajeLetrero[posicionLetrero];

	modelaux = model;
	model = glm::translate(model, glm::vec3(-2.7f, 7.3f, 1.6f));
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::scale(model, glm::vec3(1.8f, 1.0f, 1.0f));
	glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	letrero.UseTexture();
	meshList[4]->RenderMesh();

	if (posicionLetrero + 1 > mensajeLetreroTamaño) {
		toffset = mensajeLetrero[mensajeLetreroTamaño];
	}
	else {
		toffset = mensajeLetrero[posicionLetrero + 1];
	}
	model = glm::translate(model, glm::vec3(1.0f, 0.0f, 0.0f));
	glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	meshList[4]->RenderMesh();

	if (posicionLetrero + 2 > mensajeLetreroTamaño) {
		toffset = mensajeLetrero[mensajeLetreroTamaño];
	}
	else {
		toffset = mensajeLetrero[posicionLetrero + 2];
	}
	model = glm::translate(model, glm::vec3(1.0f, 0.0f, 0.0f));
	glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	meshList[4]->RenderMesh();

	if (posicionLetrero + 3 > mensajeLetreroTamaño) {
		toffset = mensajeLetrero[mensajeLetreroTamaño];
	}
	else {
		toffset = mensajeLetrero[posicionLetrero + 3];
	}
	model = glm::translate(model, glm::vec3(1.0f, 0.0f, 0.0f));
	glUniform2fv(uniformTextureOffset, 1, glm::value_ptr(toffset));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	meshList[4]->RenderMesh();

	glUniform2f(uniformTextureOffset, 0.0f, 0.0f);
}