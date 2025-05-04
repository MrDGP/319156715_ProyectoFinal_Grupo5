#include "Topos.h"

float traslacionTopos[5] = { 0.0f };
float rotacionTopos[5] = { 0.0f };
bool toposSubiendo[5] = { true };
bool animacionActivaTopos[5] = { false };
int topoActual = 0;
float delayTopos = 0.3f;
float tiempoAcumulado = 0.0f;
float escalaTopo5 = 1.0f;
bool topo5Escalado = false;
float temporizadorTopo5 = 0.0f;

void topos(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosTopos) {
	renderStand6(model, uniformModel, *objetosTopos[0], *objetosTopos[4], glm::vec3(50.0f, -1.42f, 140.0f));
	renderMaquina(model, uniformModel, *objetosTopos[1], *objetosTopos[2], *objetosTopos[3], glm::vec3(70.0f, -1.42f, 125.0f));
	renderMaquina(model, uniformModel, *objetosTopos[1], *objetosTopos[2], *objetosTopos[3], glm::vec3(70.0f, -1.42f, 150.0f));
	renderMaquina(model, uniformModel, *objetosTopos[1], *objetosTopos[2], *objetosTopos[3], glm::vec3(70.0f, -1.42f, 175.0f));
	renderMaquina2(model, uniformModel, *objetosTopos[1], *objetosTopos[2], *objetosTopos[3], glm::vec3(32.0f, -1.42f, 175.0f));
	renderMaquina2(model, uniformModel, *objetosTopos[1], *objetosTopos[2], *objetosTopos[3], glm::vec3(32.0f, -1.42f, 150.0f));
	renderMaquina3(model, uniformModel, *objetosTopos[1], *objetosTopos[2], *objetosTopos[3], glm::vec3(32.0f, -1.42f, 125.0f));
}

void renderStand6(glm::mat4 model, GLuint uniformModel, Model& stand, Model& cuadro, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	glm::mat4 modelaux(1.0);

	//Casa
	model = glm::translate(model, posicion);
	model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	modelaux = model;
	model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	stand.RenderModel();

	//Cuadro
	model = modelaux;
	model = glm::translate(model, glm::vec3(0.0f, 15.0f, -45.0f));
	model = glm::scale(model, glm::vec3(1.5f, 1.5f, 1.0f));
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	cuadro.RenderModel();
}

void renderMaquina(glm::mat4 model, GLuint uniformModel, Model& mesa, Model& tubo, Model& planta, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	//Mesa
	model = glm::translate(model, posicion);
	model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	mesa.RenderModel();
	//Tubo1
	model = glm::translate(model, glm::vec3(1.75f, 5.5f, 1.4f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo2
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.9f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo3
	model = glm::translate(model, glm::vec3(-2.5f, 1.2f, 1.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo4
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.2f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo5
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 4.4f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
}

void renderMaquina2(glm::mat4 model, GLuint uniformModel, Model& mesa, Model& tubo, Model& planta, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	//Mesa
	model = glm::translate(model, posicion);
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	mesa.RenderModel();
	//Tubo1
	model = glm::translate(model, glm::vec3(1.75f, 5.5f, 1.4f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo2
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.9f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo3
	model = glm::translate(model, glm::vec3(-2.5f, 1.2f, 1.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo4
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.2f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
	//Tubo5
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 4.4f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tubo.RenderModel();
	planta.RenderModel();
}

void renderMaquina3(glm::mat4 model, GLuint uniformModel, Model& mesa, Model& tubo, Model& planta, glm::vec3 posicion) {
	glm::mat4 modelaux;
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	mesa.RenderModel();

	std::vector<glm::vec3> posiciones = {
		glm::vec3(1.75f, 5.5f, 1.4f),
		glm::vec3(0.0f, 0.0f, -2.9f),
		glm::vec3(-2.5f, 1.2f, 1.5f),
		glm::vec3(0.0f, 0.0f, -2.2f),
		glm::vec3(0.0f, 0.0f, 4.4f)
	};

	for (int i = 0; i < 5; i++) {
		model = glm::translate(model, posiciones[i]);
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		tubo.RenderModel();
		modelaux = model;
		model = glm::translate(model, glm::vec3(0.0f, traslacionTopos[i], 0.0f));
		model = glm::rotate(model, glm::radians(rotacionTopos[i]), glm::vec3(0.0f, 1.0f, 0.0f));
		if (i == 4) model = glm::scale(model, glm::vec3(escalaTopo5));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		planta.RenderModel();
		model = modelaux;
	}
}

void activarTopos() {
	for (int i = 0; i < 5; i++) {
		traslacionTopos[i] = 0.0f;
		rotacionTopos[i] = 0.0f;
		toposSubiendo[i] = true;
		animacionActivaTopos[i] = false;
	}
	escalaTopo5 = 1.0f;
	topo5Escalado = false;
	temporizadorTopo5 = 0.0f;
	topoActual = 0;
	tiempoAcumulado = 0.0f;
	animacionActivaTopos[0] = true;
}

void actualizarTopos(float deltaTime) {
	tiempoAcumulado += deltaTime;

	for (int i = 0; i < 5; i++) {
		if (animacionActivaTopos[i]) {
			rotacionTopos[i] += 5.0f;
			if (toposSubiendo[i]) {
				traslacionTopos[i] += 0.04f;
				if (traslacionTopos[i] >= 1.5f) {
					traslacionTopos[i] = 1.5f;
					toposSubiendo[i] = false;
				}
			}
			else {
				traslacionTopos[i] -= 0.04f;
				if (traslacionTopos[i] <= 0.0f) {
					traslacionTopos[i] = 0.0f;
					animacionActivaTopos[i] = false;
					rotacionTopos[i] = 0.0f;
					if (i == 4) topo5Escalado = true;
				}
			}
		}
	}

	if (topoActual < 4 && tiempoAcumulado >= delayTopos) {
		tiempoAcumulado = 0.0f;
		topoActual++;
		animacionActivaTopos[topoActual] = true;
	}

	if (topo5Escalado) {
		escalaTopo5 -= deltaTime * 2.0f;
		if (escalaTopo5 <= 0.0f) {
			escalaTopo5 = 0.0f;
			temporizadorTopo5 += deltaTime;
			if (temporizadorTopo5 >= 2.0f) {
				escalaTopo5 = 1.0f;
				topo5Escalado = false;
				temporizadorTopo5 = 0.0f;
			}
		}
	}
}