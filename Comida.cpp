#include "Comida.h"

const float toRadians = 3.14159265f / 180.0f;

void comida(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosComida) {
	
	//Puesto Palomitas
	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(-205.0f, -1.0f, -60.0f));
	model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
	model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosComida[0]->RenderModel();

	//Puesto Helados
	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(-205.0f, -1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
	model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosComida[1]->RenderModel();

	//Puesto Algodones
	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(-205.0f, -1.0f, 60.0f));
	model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
	model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosComida[2]->RenderModel();
}
