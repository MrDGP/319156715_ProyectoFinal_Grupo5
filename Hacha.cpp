#include "Hacha.h"

void hacha(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosHacha) {
	renderStand(model, uniformModel, *objetosHacha[0], *objetosHacha[1], *objetosHacha[2], *objetosHacha[3], *objetosHacha[4], glm::vec3(180.0f, -1.42f, 140.0f));
}

void renderStand(glm::mat4 model, GLuint uniformModel, Model &stand, Model &hacha, Model &reja, Model &tabla, Model &objetivo, glm::vec3 posicion) {
	glm::mat4 modelaux(1.0);
	glm::mat4 modelaux2(1.0);

	//Casa
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	modelaux = model;
	model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	stand.RenderModel();

	//Tabla1
	model = modelaux;
	model = glm::translate(model, glm::vec3(-12.5f, 5.0f, 15.0f));
	modelaux2 = model;
	model = glm::scale(model, glm::vec3(1.1f, 2.0f, 1.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tabla.RenderModel();
	model = modelaux2;
	model = glm::translate(model, glm::vec3(0.0f, 0.5f, 0.0f));
	model = glm::rotate(model, glm::radians(270.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(1.0f, 0.5f, 0.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	hacha.RenderModel();
	//Tabla2
	model = modelaux;
	model = glm::translate(model, glm::vec3(11.5f, 5.0f, 15.0f));
	modelaux2 = model;
	model = glm::scale(model, glm::vec3(1.0f, 2.0f, 1.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tabla.RenderModel();
	model = modelaux2;
	model = glm::translate(model, glm::vec3(0.0f, 0.5f, 0.0f));
	model = glm::rotate(model, glm::radians(270.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(0.8f, 0.5f, 0.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	hacha.RenderModel();

	//Reja
	model = modelaux;
	model = glm::translate(model, glm::vec3(0.0f, 0.5f, -12.0f));
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(3.0f, 2.3f, 2.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	reja.RenderModel();

	//Objetivos
	model = modelaux;
	model = glm::translate(model, glm::vec3(-12.0f, 0.0f, -20.0f));
	model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
	model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetivo.RenderModel();
	model = glm::translate(model, glm::vec3(-8.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetivo.RenderModel();
}