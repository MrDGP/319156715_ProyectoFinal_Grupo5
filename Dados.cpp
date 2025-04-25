#include "Dados.h"

void dados(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosDados) {
	renderStand3(model, uniformModel, *objetosDados[0], glm::vec3(180.0f, -1.42f, -140.0f));
}

void renderStand3(glm::mat4 model, GLuint uniformModel, Model& stand, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	stand.RenderModel();
}
