#include "Hacha.h"

static float avanceHacha = 0.0f;
static float rotacionHacha = 0.0f;
static float tiempoImpactoHacha = 0.0f;
static bool lanzandoHacha = false;
static bool impactoHacha = false;

void hacha(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosHacha) {
	renderStand(model, uniformModel, *objetosHacha[0], *objetosHacha[2], *objetosHacha[3], glm::vec3(180.0f, -1.42f, 140.0f));
	renderHachas(model, uniformModel, *objetosHacha[1], glm::vec3(190.0f, 4.7f, 125.0f));
	renderObjetivos(model, uniformModel, *objetosHacha[4], glm::vec3(192.0f, -1.0f, 160.0f));
}

void renderStand(glm::mat4 model, GLuint uniformModel, Model &stand, Model &reja, Model &tabla, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	glm::mat4 modelaux(1.0);

	//Casa
	model = glm::translate(model, posicion);
	model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	modelaux = model;
	model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	stand.RenderModel();

	//Tabla1
	model = modelaux;
	model = glm::translate(model, glm::vec3(-12.5f, 5.0f, 15.0f));
	model = glm::scale(model, glm::vec3(1.1f, 2.0f, 1.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tabla.RenderModel();
	//Tabla2
	model = modelaux;
	model = glm::translate(model, glm::vec3(11.5f, 5.0f, 15.0f));
	model = glm::scale(model, glm::vec3(1.0f, 2.0f, 1.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tabla.RenderModel();

	//Reja
	model = modelaux;
	model = glm::translate(model, glm::vec3(0.0f, 0.5f, -12.0f));
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(3.0f, 2.3f, 2.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	reja.RenderModel();
}

void renderHachas(glm::mat4 model, GLuint uniformModel, Model &hacha, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(1.0f, 0.5f, 0.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	hacha.RenderModel();

	if (lanzandoHacha) {
		if (!impactoHacha) {
			if (avanceHacha < 31.0f) {
				avanceHacha += 15.0f * 0.016f;
				rotacionHacha += 720.0f * 0.016f;
			}
			else {
				tiempoImpactoHacha += 0.016f;
				if (tiempoImpactoHacha >= 3.0f) {
					lanzandoHacha = false;
					impactoHacha = false;
					tiempoImpactoHacha = 0.0f;
					avanceHacha = 0.0f;
					rotacionHacha = 0.0f;
				}
				else {
					impactoHacha = true;
				}
			}
		}
		else {
			tiempoImpactoHacha += 0.016f;
			if (tiempoImpactoHacha >= 3.0f) {
				lanzandoHacha = false;
				impactoHacha = false;
				tiempoImpactoHacha = 0.0f;
				avanceHacha = 0.0f;
				rotacionHacha = 0.0f;
			}
		}
	}
	//Hacha animada
	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(167.0f, 4.7f, 125.0f));
	model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -avanceHacha));
	model = glm::rotate(model, glm::radians(-rotacionHacha), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.8f, 0.5f, 0.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	hacha.RenderModel();
}

void renderObjetivos(glm::mat4 model, GLuint uniformModel, Model& objetivo, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetivo.RenderModel();
	model = glm::translate(model, glm::vec3(-8.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetivo.RenderModel();
}

void lanzarHacha() {
	if (!lanzandoHacha) {
		lanzandoHacha = true;
		impactoHacha = false;
		tiempoImpactoHacha = 0.0f;
		avanceHacha = 0.0f;
		rotacionHacha = 0.0f;
	}
}