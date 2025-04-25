#include "Bolos.h"

void bolos(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosBolos) {
	GLfloat alturaPin = 0.1f;
	GLfloat alturaBola = 1.2f;

	renderStand5(model, uniformModel, *objetosBolos[0], glm::vec3(-80.0f, -1.42f, 140.0f));
	
	renderPines(model, uniformModel, *objetosBolos[1], glm::vec3(-69.0f, alturaPin,180.0f));
	renderPines(model, uniformModel, *objetosBolos[1], glm::vec3(-79.0f, alturaPin,180.0f));
	renderPines(model, uniformModel, *objetosBolos[1], glm::vec3(-89.0f, alturaPin,180.0f));
	
	renderBola(model, uniformModel, *objetosBolos[2], glm::vec3(-69.0f, alturaBola , 150.0f));
	renderBola(model, uniformModel, *objetosBolos[2], glm::vec3(-79.0f, alturaBola, 150.0f));
	renderBola(model, uniformModel, *objetosBolos[2], glm::vec3(-89.0f, alturaBola, 150.0f));

	renderCartelBoliche(model, uniformModel, *objetosBolos[3], glm::vec3(-69.0f, 8.0f, 189.0f));

	renderMesa(model, uniformModel, *objetosBolos[4], glm::vec3(-78.0f, 0.0f, 166.0f));
}

void renderStand5(glm::mat4 model, GLuint uniformModel, Model& stand, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	stand.RenderModel();
}

void renderPines(glm::mat4 model, GLuint uniformModel, Model& pin, glm::vec3 posicion) {
	//1
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();

	//2,1
	model = glm::translate(model, glm::vec3(0.5f,0.0f,1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();

	//2,2
	
	model = glm::translate(model, glm::vec3(-1.0f,0.0f,0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();

	//3,1
	model = glm::translate(model, glm::vec3(-0.5, 0.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();

	//3,2
	model = glm::translate(model, glm::vec3(1.0,0.0f,0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();

	//3,3
	model = glm::translate(model, glm::vec3(1.0, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();

	//4,1
	model = glm::translate(model, glm::vec3(0.5f ,0.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();

	//4,2
	model = glm::translate(model, glm::vec3(-1.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();

	//4,3
	model = glm::translate(model, glm::vec3(-1.0f,0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();

	//4,4
	model = glm::translate(model, glm::vec3(-1.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	pin.RenderModel();
}

void renderBola(glm::mat4 model, GLuint uniformModel, Model& bola,glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model,posicion);
	model = glm::scale(model, glm::vec3(9.5f, 9.5f, 9.5f));
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	bola.RenderModel();
}

void renderMesa(glm::mat4 model, GLuint uniformModel, Model& table, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(25.5f, 25.5f, 50.5f));
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	table.RenderModel();
}

void renderCartelBoliche(glm::mat4 model, GLuint uniformModel, Model& cartel, glm::vec3 position) {
	model = glm::mat4(1.0);
	model = glm::translate(model, position);
	model = glm::scale(model, glm::vec3(6.5f, 4.0f, 4.5f));
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	cartel.RenderModel();
}
