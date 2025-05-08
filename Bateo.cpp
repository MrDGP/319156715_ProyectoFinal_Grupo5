#include "Bateo.h"

// --- Variables para animación de bateo ---
static glm::vec3 posicionBola = glm::vec3(-70.0f, 10.0f, -175.0f);
const float VELOCIDAD_BOLA_ORIGINAL = 5.0f;
static float velocidadBola = VELOCIDAD_BOLA_ORIGINAL;//1.0f;
static float rotacionBat = 0.0f;
static float rotacionBola = 0.0f;
static bool batRegresando = false;
static bool bolaEnMovimiento = false;
static bool batGolpeando = false;
static bool bolaRegresando = false;
static float tiempoGolpe = 0.0f;


static float alturaBat = 0.0f;


void bateo(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosBateo) {
	renderStand2(model, uniformModel, *objetosBateo[0], glm::vec3(-80.0f, -1.42f, -140.0f));
	renderBardas(model, uniformModel, *objetosBateo[1], glm::vec3(-100.0f, 2.0f, -130.0f));
	renderbolaBateo(model, uniformModel, *objetosBateo[5], glm::vec3(-70.0f, 10.0f, -175.0f));
	renderCartelBateo(model, uniformModel, *objetosBateo[3], glm::vec3(-93.0f, 8.0f, -188.0f));
	renderBats(model, uniformModel, *objetosBateo[4], glm::vec3(-70.0f, 0.0f, -125.0f));
}

void renderStand2(glm::mat4 model, GLuint uniformModel, Model& stand, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	stand.RenderModel();
}

void renderBardas(glm::mat4 model, GLuint uniformModel, Model& bardaBateo, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(0.7f, 0.7f, 0.7f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	bardaBateo.RenderModel();

	model = glm::translate(model,glm::vec3(27.0f,0.0f,0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	bardaBateo.RenderModel();

	model = glm::translate(model, glm::vec3(27.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	bardaBateo.RenderModel();
}

void renderbolaBateo(glm::mat4 model, GLuint uniformModel, Model& objetivo, glm::vec3 posicion){ //(actualizado a bolaBateo)
	model = glm::mat4(1.0);
	model = glm::translate(model, posicionBola);
	model = glm::scale(model, glm::vec3(10.8f, 10.8f,10.8f));
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, glm::radians(rotacionBola), glm::vec3(0.0f,0.0f,1.0f)); // ← rotación para la cara
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetivo.RenderModel();

	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(-90.0f, 10.0f, -175.0f)); // posición fija decorativa
	model = glm::scale(model, glm::vec3(10.8f, 10.8f, 10.8f));
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetivo.RenderModel();
}

void renderCartelBateo(glm::mat4 model, GLuint uniformModel, Model& cartelBateo, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(6.5f, 4.0f, 4.5f));
	model = glm::rotate(model, glm::radians(270.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	cartelBateo.RenderModel();
}

void renderBats(glm::mat4 model, GLuint uniformModel, Model& bats, glm::vec3 posicion){
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion + glm::vec3(0.0f, alturaBat, 0.0f));
	model = glm::scale(model, glm::vec3(6.5f, 4.0f, 4.5f));
	model = glm::rotate(model, glm::radians(rotacionBat), glm::vec3(1.0f, 0.0f, 0.0f)); // animación de bat
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	bats.RenderModel();

	model = glm::mat4(1.0);
	model = glm::translate(model, posicion + glm::vec3(-20.0f, 0.0f, 0.0f)); // sin rotación ni animación
	model = glm::scale(model, glm::vec3(6.5f, 4.0f, 4.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	bats.RenderModel();
}

void actualizarBateo(float deltaTime) {
	if (bolaEnMovimiento && !batGolpeando) {
		posicionBola.z += velocidadBola * deltaTime;

		if (posicionBola.z >= -135.0f) {  // PUNTO DE IMPACTO
			batGolpeando = true;
			bolaEnMovimiento = false;
			tiempoGolpe = 0.0f;
		}

		// Levantar ligeramente el bate mientras la bola se acerca
		if (alturaBat < 4.0f)
			alturaBat += 2.0f * deltaTime;

	}

	// Subida del bat para golpear
	if (batGolpeando) {
		tiempoGolpe += deltaTime;

		if (rotacionBat < 60.0f)
			rotacionBat += 200.0f * deltaTime;

		if (tiempoGolpe >= 0.3f) {  // Después del golpe
			batGolpeando = false;
			batRegresando = true;

			bolaRegresando = true;
			velocidadBola = -VELOCIDAD_BOLA_ORIGINAL;
			rotacionBola = 180.0f;  // empieza rotada
		}
		

	}

	// Regreso del bat a su posición original
	if (batRegresando) {
		if (rotacionBat > 0.0f) {
			rotacionBat -= 200.0f * deltaTime;
			if (rotacionBat < 0.0f) rotacionBat = 0.0f;
		}
		else {
			batRegresando = false;
		}
		
		if (alturaBat > 0.0f) {
			alturaBat -= 2.0f * deltaTime;
			if (alturaBat < 0.0f) alturaBat = 0.0f;
		}

		

	}

	// Regreso de la bola y restauración de su rotación
	if (bolaRegresando) {
		posicionBola.z += velocidadBola * deltaTime;

		if (posicionBola.z <= -175.0f) {
			// Reseteo total para volver a lanzar
			bolaRegresando = false;
			batRegresando = false;
			bolaEnMovimiento = false;
			batGolpeando = false;

			velocidadBola = VELOCIDAD_BOLA_ORIGINAL;
			posicionBola = glm::vec3(-70.0f, 10.0f, -175.0f);
			rotacionBola = 0.0f;
			rotacionBat = 0.0f;
			tiempoGolpe = 0.0f;
			alturaBat = 0.0f;


		}

	}
}

void lanzarBateo() {
	if (!bolaEnMovimiento && !batGolpeando && !bolaRegresando && !batRegresando) {
		bolaEnMovimiento = true;
	}
}
