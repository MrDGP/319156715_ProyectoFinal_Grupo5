#include "Ambientacion.h"

void ambientacion(glm::mat4 model, GLuint uniformModel, std::vector<Model> objetosAmbientacion) {
	renderBanca(model, uniformModel, objetosAmbientacion[0], glm::vec3(0.0f, -1.02f, 0.0f));
	renderLuminaria1(model, uniformModel, objetosAmbientacion[1], glm::vec3(10.0f, -1.02f, 0.0f));
	renderLuminaria2(model, uniformModel, objetosAmbientacion[2], glm::vec3(20.0f, -1.02f, 0.0f));
	renderLuminaria3(model, uniformModel, objetosAmbientacion[3], glm::vec3(30.0f, -1.02f, 0.0f));
	renderArbol1(model, uniformModel, objetosAmbientacion[4], glm::vec3(-10.0f, -1.02f, 0.0f));
	renderArbol2(model, uniformModel, objetosAmbientacion[5], glm::vec3(-20.0f, -1.02f, 0.0f));
	renderArbol3(model, uniformModel, objetosAmbientacion[6], glm::vec3(-30.0f, -1.02f, 0.0f));
	renderBote1(model, uniformModel, objetosAmbientacion[7], glm::vec3(10.0f, -1.02f, 10.0f));
	renderBote2(model, uniformModel, objetosAmbientacion[8], glm::vec3(20.0f, -1.02f, 10.0f));
}

void renderBanca(glm::mat4 model, GLuint uniformModel, Model banca, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	banca.RenderModel();
}

void renderLuminaria1(glm::mat4 model, GLuint uniformModel, Model luminaria1, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	luminaria1.RenderModel();
}

void renderLuminaria2(glm::mat4 model, GLuint uniformModel, Model luminaria2, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	luminaria2.RenderModel();
}

void renderLuminaria3(glm::mat4 model, GLuint uniformModel, Model luminaria3, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	luminaria3.RenderModel();
}

void renderArbol1(glm::mat4 model, GLuint uniformModel, Model arbol1, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	arbol1.RenderModel();
}

void renderArbol2(glm::mat4 model, GLuint uniformModel, Model arbol2, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	arbol2.RenderModel();
}

void renderArbol3(glm::mat4 model, GLuint uniformModel, Model arbol3, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	arbol3.RenderModel();
}

void renderBote1(glm::mat4 model, GLuint uniformModel, Model bote1, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(10.0f, 10.0f, 10.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	bote1.RenderModel();
}

void renderBote2(glm::mat4 model, GLuint uniformModel, Model bote2, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(10.0f, 10.0f, 10.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	bote2.RenderModel();
}

