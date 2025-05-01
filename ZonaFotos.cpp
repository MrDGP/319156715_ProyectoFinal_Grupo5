#include "ZonaFotos.h"

const float toRadians = 3.14159265f / 180.0f;

//Variables para animación de Snoopy
float vuelaSnoopy = 0.0f;
float velocidadSnoopy = 0.0f;
float amplitud = 0.0f;
float snoopyY = 0.0f;
float snoopyZ = 0.0f;

float movOffsetSnoopy = 0.1f;
float movSnoopy = 0.0f;
bool avanzaSnoopy = true;

//Variables para animación de Woodstock
float vuelaWoodstock = 0.0f;

void zonaFotos(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosZonaFotos, float deltaTime) {

	glm::mat4 modelaux(1.0);

	//Casa con Snoopy

	vuelaSnoopy += 0.0007f * deltaTime;

	amplitud = 4.5;
	velocidadSnoopy = 0.2f;
	snoopyY = amplitud * sin(velocidadSnoopy * (vuelaSnoopy * 200));
	snoopyZ = amplitud * cos(velocidadSnoopy * (vuelaSnoopy * 200));

	//Ida y vuelta Snoopy

	if (movSnoopy > -100.0f && avanzaSnoopy == true) {
		movSnoopy -= movOffsetSnoopy * vuelaSnoopy;
	}
	else if (movSnoopy < -100.0f) {
		movSnoopy += movOffsetSnoopy * vuelaSnoopy;
		avanzaSnoopy = false;
	}
	else if (movSnoopy < 5.0f && avanzaSnoopy == false) {
		movSnoopy += movOffsetSnoopy * vuelaSnoopy;
	}
	else {
		movSnoopy -= movOffsetSnoopy * vuelaSnoopy;
		avanzaSnoopy = true;
	}

	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(100.0f + movSnoopy, 4.0f + snoopyY, 4.0f + snoopyZ));
	model = glm::scale(model, glm::vec3(50.0f, 40.0f, 50.0f));
	model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	if (avanzaSnoopy == false) {
		model = glm::rotate(model, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	}
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[0]->RenderModel();

	//Gumball
	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(107.0f, -0.9f, 25.0f));
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

	//Woodstock

	vuelaWoodstock += 1.0f * deltaTime;
	if (vuelaWoodstock >= 360.0f)
		vuelaWoodstock = 0.0f;

	//Cuerpo
	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(104.0f, 1.0f, -13.0f));
	model = glm::translate(model, glm::vec3(0.0f, sin(glm::radians(vuelaWoodstock * 5.0f)), 0.0f));
	model = glm::scale(model, glm::vec3(15.0f, 15.0f, 15.0f));
	model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[3]->RenderModel();

	modelaux = model;
	model = glm::translate(model, glm::vec3(0.0f, 0.1f, 0.0f));
	model = glm::rotate(model, sin(glm::radians(vuelaWoodstock * 5.0f)), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(1.5f, 1.5f, 1.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[4]->RenderModel();
	model = modelaux;

	modelaux = model;
	model = glm::translate(model, glm::vec3(0.0f, 0.1f, 0.0f));
	model = glm::rotate(model, -sin(glm::radians(vuelaWoodstock * 5.0f)), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(1.5f, 1.5f, 1.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[5]->RenderModel();
	model = modelaux;
}