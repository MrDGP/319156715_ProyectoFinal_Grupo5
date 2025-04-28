#include "ZonaFotos.h"

const float toRadians = 3.14159265f / 180.0f;

void zonaFotos(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosZonaFotos) {
	//Casa Snoopy
	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(100.0f, -1.0f, 5.0f));
	model = glm::scale(model, glm::vec3(50.0f, 40.0f, 50.0f));
	model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[0]->RenderModel();

	//Gumball
	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(107.0f, -0.9f, 23.0f));
	model = glm::scale(model, glm::vec3(1.3f, 1.3f, 1.3f));
	model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[1]->RenderModel();

	//Yoshi
	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(105.0f, -0.9f, -25.0f));
	model = glm::scale(model, glm::vec3(7.0f, 7.0f, 7.0f));
	model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[2]->RenderModel();

	//Snoopy Aviador
	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(104.0f, -1.0f, -13.0f));
	model = glm::scale(model, glm::vec3(28.0f, 28.0f, 28.0f));
	model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[3]->RenderModel();

	//Woodstock
	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(98.0f, 20.9f, 5.0f));
	model = glm::scale(model, glm::vec3(15.0f, 15.0f, 15.0f));
	model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[4]->RenderModel();
}