#include "Bolos.h"


// --- Variables internas ---
static glm::vec3 posicionBola = glm::vec3(-79.0f, 1.2f, 150.0f);
static bool bolaEnMovimiento = false;
static float velocidadBola = 2.0f;

static bool pinesDerribados = false;
static float alturaPin = 0.1f;
static float alturaBola = 1.2f;
static float rotacionBola = 0.0f;
static float anguloAnimacion = 0.0f;
static std::vector<float> angulosCaida = {
	90.0f, 65.0f, 110.0f, 75.0f, 105.0f,
	60.0f, 120.0f, 70.0f, 100.0f, 85.0f
};





void bolos(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosBolos) {
	GLfloat alturaPin = 0.1f;
	GLfloat alturaBola = 1.2f;

	renderStand5(model, uniformModel, *objetosBolos[0], glm::vec3(-80.0f, -1.42f, 140.0f));
	
	renderPines(model, uniformModel, *objetosBolos[1], glm::vec3(-69.0f, alturaPin,175.0f),0.0f);
	renderPines(model, uniformModel, *objetosBolos[1], glm::vec3(-79.0f, alturaPin,175.0f),anguloAnimacion);
	renderPines(model, uniformModel, *objetosBolos[1], glm::vec3(-89.0f, alturaPin,175.0f),0.0f);
	
	renderBola(model, uniformModel, *objetosBolos[2], glm::vec3(-69.0f, alturaBola, 150.0f),false);
	renderBola(model, uniformModel, *objetosBolos[2], posicionBola,true);
	renderBola(model, uniformModel, *objetosBolos[2], glm::vec3(-89.0f, alturaBola, 150.0f),false);

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

void renderPines(glm::mat4 model, GLuint uniformModel, Model& pin, glm::vec3 base,float anguloAnimado) {
	// Formación triangular ajustada y más compacta
	std::vector<glm::vec3> posiciones = {
		base,                                                   // fila 1
		base + glm::vec3(-0.5f, 0.0f, 0.8f),                    // fila 2
		base + glm::vec3(0.5f, 0.0f, 0.8f),

		base + glm::vec3(-1.0f, 0.0f, 1.6f),                    // fila 3
		base + glm::vec3(0.0f, 0.0f, 1.6f),
		base + glm::vec3(1.0f, 0.0f, 1.6f),

		base + glm::vec3(-1.5f, 0.0f, 2.4f),                    // fila 4
		base + glm::vec3(-0.5f, 0.0f, 2.4f),
		base + glm::vec3(0.5f, 0.0f, 2.4f),
		base + glm::vec3(1.5f, 0.0f, 2.4f)
	};

	for (int i = 0; i < posiciones.size(); ++i) {
		float anguloReal = glm::min(anguloAnimado, angulosCaida[i]);

		model = glm::mat4(1.0f);
		model = glm::translate(model, posiciones[i]);

		// Alternar eje de caída
		glm::vec3 eje;
		if (i % 3 == 0)
			eje = glm::vec3(1, 0, 0);
		else if (i % 3 == 1)
			eje = glm::vec3(0, 0, 1);
		else
			eje = glm::normalize(glm::vec3(1, 0, 1));  // diagonal
		model = glm::rotate(model, glm::radians(anguloReal), eje);
		model = glm::scale(model, glm::vec3(2.0f));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		pin.RenderModel();
	}	
}

void renderBola(glm::mat4 model, GLuint uniformModel, Model& bola,glm::vec3 posicion,bool animada) {
	model = glm::mat4(1.0);
	model = glm::translate(model,posicion);
	model = glm::scale(model, glm::vec3(9.5f, 9.5f, 9.5f));
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	if (animada) {
		model = glm::rotate(model, glm::radians(rotacionBola), glm::vec3(0.0f, 1.0f, 0.0f)); // rotación sobre eje X
	}
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

void actualizarBolos(float deltaTime) {
	if (bolaEnMovimiento && !pinesDerribados) {
		posicionBola.z += velocidadBola * deltaTime;
		rotacionBola += 360.0f * deltaTime;
		if (posicionBola.z >= 180.0f) {
			pinesDerribados = true;
			bolaEnMovimiento = false;
		}
	}
	if (pinesDerribados && anguloAnimacion < 100.0f) {
		anguloAnimacion += 100.0f * deltaTime;
	}

	
	static float tiempoDesdeCaida = 0.0f;

	if (pinesDerribados && anguloAnimacion >= 100.0f) {
		tiempoDesdeCaida += deltaTime;

		if (tiempoDesdeCaida >= 2.0f) {
			posicionBola = glm::vec3(-79.0f, 1.2f, 150.0f);
			rotacionBola = 0.0f;
			anguloAnimacion = 0.0f;  // reseteo para repetir animación
			bolaEnMovimiento = false;
			pinesDerribados = false;
			tiempoDesdeCaida = 0.0f;
		}

	}
}

void lanzarBola() {
	bolaEnMovimiento = true;
}