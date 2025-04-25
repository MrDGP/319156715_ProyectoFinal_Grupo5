#include "Hacha.h"

void hacha(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosHacha) {
	renderStand1(model, uniformModel, *objetosHacha[0], glm::vec3(180.0f, -1.42f, 140.0f));
}

void renderStand1(glm::mat4 model, GLuint uniformModel, Model& stand, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	stand.RenderModel();
}