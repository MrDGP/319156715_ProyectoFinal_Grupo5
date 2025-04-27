#include "Topos.h"

void topos(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosTopos) {
	renderStand6(model, uniformModel, *objetosTopos[0], *objetosTopos[1], *objetosTopos[2], *objetosTopos[3], glm::vec3(50.0f, -1.42f, 140.0f));
}

void renderStand6(glm::mat4 model, GLuint uniformModel, Model &stand, Model &mesa, Model &tubo, Model &planta, glm::vec3 posicion) {
	glm::mat4 modelaux(1.0);
	glm::mat4 modelaux2(1.0);

	//Casa
	modelaux = glm::translate(modelaux, posicion);
	modelaux = glm::rotate(modelaux, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = modelaux;
	modelaux = glm::scale(modelaux, glm::vec3(2.5f, 2.5f, 2.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelaux));
	stand.RenderModel();

	//Mesa1
	model = glm::translate(model, glm::vec3(-20.0f, 0.0f, 15.0f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	mesa.RenderModel();
	//Tubo1.1
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo1.2
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.9f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo1.3
	model = glm::translate(model, glm::vec3(-2.5f, 1.2f, 1.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo1.4
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.2f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo1.5
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 4.4f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();

	//Mesa2
	model = modelaux;
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -25.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	mesa.RenderModel();
	//Tubo2.1
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo2.2
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.9f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo2.3
	model = glm::translate(model, glm::vec3(-2.5f, 1.2f, 1.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo2.4
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.2f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo2.5
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 4.4f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();

	//Mesa3
	model = modelaux;
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -50.0f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	mesa.RenderModel();
	//Tubo3.1
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo3.2
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.9f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo3.3
	model = glm::translate(model, glm::vec3(-2.5f, 1.2f, 1.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo3.4
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.2f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo3.5
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 4.4f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();

	//Mesa4
	model = modelaux;
	model = glm::translate(model, glm::vec3(38.0f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	mesa.RenderModel();
	//Tubo4.1
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo4.2
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.9f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo4.3
	model = glm::translate(model, glm::vec3(-2.5f, 1.2f, 1.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo4.4
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.2f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo4.5
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 4.4f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();

	//Mesa5
	model = modelaux;
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -25.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	mesa.RenderModel();
	//Tubo5.1
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo5.2
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.9f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo5.3
	model = glm::translate(model, glm::vec3(-2.5f, 1.2f, 1.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo5.4
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.2f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo5.5
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 4.4f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();

	//Mesa6
	model = modelaux;
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -50.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	mesa.RenderModel();
	//Tubo6.1
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo6.2
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.9f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo6.3
	model = glm::translate(model, glm::vec3(-2.5f, 1.2f, 1.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo6.4
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.2f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo6.5
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 4.4f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
}