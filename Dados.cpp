#include "Dados.h"

const float toRadians = 3.14159265f / 180.0f;

void dados(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosDados) {
	renderStand3(model, uniformModel, *objetosDados[0], glm::vec3(180.0f, -1.42f, -140.0f));
	//Mesa 1
	renderMesaDados(model, uniformModel, *objetosDados[1], glm::vec3(180.0f, -1.0f, -125.0f));
	renderDado(model, uniformModel, *objetosDados[2], glm::vec3(178.0f, 3.5f, -125.0f));
	renderDado(model, uniformModel, *objetosDados[2], glm::vec3(182.0f, 3.5f, -125.0f));
	renderHongo(model, uniformModel, *objetosDados[3], glm::vec3(180.0f, -1.0f, -115.0f), 180); //Hongo Rojo
	renderHongo(model, uniformModel, *objetosDados[4], glm::vec3(180.0f, -1.0f, -135.0f), 0); //Hongo Verde
	//Mesa 2
	renderMesaDados(model, uniformModel, *objetosDados[1], glm::vec3(180.0f, -1.0f, -160.0f));
	renderDado(model, uniformModel, *objetosDados[2], glm::vec3(178.0f, 3.5f, -160.0f));
	renderDado(model, uniformModel, *objetosDados[2], glm::vec3(182.0f, 3.5f, -160.0f));
	renderHongo(model, uniformModel, *objetosDados[3], glm::vec3(180.0f, -1.0f, -150.0f), 180); //Hongo Rojo
	renderHongo(model, uniformModel, *objetosDados[4], glm::vec3(180.0f, -1.0f, -170.0f), 0); //Hongo Verde

	renderCuadro(model, uniformModel, *objetosDados[5], glm::vec3(155.5f, 15.0f, -135.0f), 90);
	renderCuadro(model, uniformModel, *objetosDados[6], glm::vec3(155.5f, 15.0f, -165.0f), 90);
	renderCuadro(model, uniformModel, *objetosDados[7], glm::vec3(202.5f, 15.0f, -135.0f), -90);
	renderCuadro(model, uniformModel, *objetosDados[8], glm::vec3(202.5f, 15.0f, -165.0f), -90);
}

void renderStand3(glm::mat4 model, GLuint uniformModel, Model& stand, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	stand.RenderModel();
}

void renderMesaDados(glm::mat4 model, GLuint uniformModel, Model& mesa, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.2f, 1.2f, 1.2f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	mesa.RenderModel();
}

void renderDado(glm::mat4 model, GLuint uniformModel, Model& dado, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dado.RenderModel();
}

void renderHongo(glm::mat4 model, GLuint uniformModel, Model& hongo, glm::vec3 posicion, int grados) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(0.8f, 0.8f, 0.8f));
	model = glm::rotate(model, grados * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	hongo.RenderModel();
}


void renderCuadro(glm::mat4 model, GLuint uniformModel, Model& cuadro, glm::vec3 posicion, int grados) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	model = glm::rotate(model, grados * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	cuadro.RenderModel();
}