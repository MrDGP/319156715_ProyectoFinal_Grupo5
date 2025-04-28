#include "Arco.h"

const float toRadians = 3.14159265f / 180.0f;

void arco(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosArco) {
	glm::mat4 modelaux(1.0);

	//Arco
	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(260.0f, -1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
	model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosArco[0]->RenderModel();

	//Puerta Derecha
	modelaux = model;
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosArco[1]->RenderModel();
	model = modelaux;

	//Puerta Izquierda
	modelaux = model;
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosArco[2]->RenderModel();
	model = modelaux;

}