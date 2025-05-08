#include "Dados.h"

const float toRadians = 3.14159265f / 180.0f;
// Parámetros de animación
static glm::vec3 posDado1 = glm::vec3(178.0f, 3.5f, -125.0f);
static glm::vec3 posDado2 = glm::vec3(182.0f, 3.5f, -125.0f);
static glm::vec3 rotDado1 = glm::vec3(0.0f);
static glm::vec3 rotDado2 = glm::vec3(0.0f);
static float velY = 12.0f;
static int rebotes = 5;
static bool dadosLanzados = false;
static bool dadosCayendo = false;




void dados(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosDados) {
	renderStand3(model, uniformModel, *objetosDados[0], glm::vec3(180.0f, -1.42f, -140.0f));
	//Mesa 1
	renderMesaDados(model, uniformModel, *objetosDados[1], glm::vec3(180.0f, -1.0f, -125.0f));
	renderDado(model, uniformModel, *objetosDados[2],posDado1,rotDado1);
	renderDado(model, uniformModel, *objetosDados[2],posDado2,rotDado2);
	renderHongo(model, uniformModel, *objetosDados[3], glm::vec3(180.0f, -1.0f, -115.0f), 180); //Hongo Rojo
	renderHongo(model, uniformModel, *objetosDados[4], glm::vec3(180.0f, -1.0f, -135.0f), 0); //Hongo Verde
	//Mesa 2
	renderMesaDados(model, uniformModel, *objetosDados[1], glm::vec3(180.0f, -1.0f, -160.0f));
	//renderDado(model, uniformModel, *objetosDados[2], glm::vec3(178.0f, 3.5f, -160.0f));
	//renderDado(model, uniformModel, *objetosDados[2], glm::vec3(182.0f, 3.5f, -160.0f));
	renderHongo(model, uniformModel, *objetosDados[3], glm::vec3(180.0f, -1.0f, -150.0f), 180); //Hongo Rojo
	renderHongo(model, uniformModel, *objetosDados[4], glm::vec3(180.0f, -1.0f, -170.0f), 0); //Hongo Verde

	renderCuadro(model, uniformModel, *objetosDados[5], glm::vec3(155.5f, 15.0f, -135.0f), 90);
	renderCuadro(model, uniformModel, *objetosDados[6], glm::vec3(155.5f, 15.0f, -165.0f), 90);
	renderCuadro(model, uniformModel, *objetosDados[7], glm::vec3(202.5f, 15.0f, -135.0f), -90);
	renderCuadro(model, uniformModel, *objetosDados[8], glm::vec3(202.5f, 15.0f, -165.0f), -90);
}

void renderStand3(glm::mat4 model, GLuint uniformModel, Model& stand, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	stand.RenderModel();
}

void renderMesaDados(glm::mat4 model, GLuint uniformModel, Model& mesa, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.2f, 1.2f, 1.2f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	mesa.RenderModel();
}

void renderDado(glm::mat4 model, GLuint uniformModel, Model& dado, glm::vec3 posicion,glm::vec3 rotacion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
	model = glm::rotate(model, glm::radians(rotacion.x), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::radians(rotacion.y), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, glm::radians(rotacion.z), glm::vec3(0.0f, 0.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dado.RenderModel();
}

void renderHongo(glm::mat4 model, GLuint uniformModel, Model& hongo, glm::vec3 posicion, int grados) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(0.8f, 0.8f, 0.8f));
	model = glm::rotate(model, grados * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	hongo.RenderModel();
}


void renderCuadro(glm::mat4 model, GLuint uniformModel, Model& cuadro, glm::vec3 posicion, int grados) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	model = glm::rotate(model, grados * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	cuadro.RenderModel();
}

void actualizarDados(float deltaTime) {
	if (!dadosLanzados) return;

	// Aplicar gravedad y animación vertical
	if (rebotes > 0) {
		posDado1.y += velY * deltaTime;
		posDado2.y += velY * deltaTime;

		// Rotación continua
		rotDado1 += glm::vec3(100.0f, 130.0f, 80.0f) * deltaTime;
		rotDado2 += glm::vec3(90.0f, 150.0f, 70.0f) * deltaTime;

		// Impacto con mesa
		if (posDado1.y <= 3.5f) {
			posDado1.y = 3.5f;
			posDado2.y = 3.5f;
			velY *= -0.6f; // rebote con pérdida de energía
			rebotes--;
		}

		// Gravedad descendente
		velY -= 15.0f * deltaTime;
	}
	else {
		// Reset
		posDado1 = glm::vec3(178.0f, 3.5f, -125.0f);
		posDado2 = glm::vec3(182.0f, 3.5f, -125.0f);
		rotDado1 = glm::vec3(0.0f);
		rotDado2 = glm::vec3(0.0f);
		velY = 12.0f;
		rebotes = 3;
		dadosLanzados = false;
	}
}

void lanzarDados() {
	if (!dadosLanzados) {
		dadosLanzados = true;
		dadosCayendo = true;
	}
}
