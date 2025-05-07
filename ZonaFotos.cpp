#include "ZonaFotos.h"

const float toRadians = 3.14159265f / 180.0f;

//Variables para animación de Snoopy
static float vuelaSnoopy = 0.0f;
static float velocidadSnoopy = 0.0f;
static float amplitud = 0.0f;
static float snoopyY = 0.0f;
static float snoopyZ = 0.0f;

static float movOffsetSnoopy = 0.1f;
static float movSnoopy = 0.0f;
static bool avanzaSnoopy = true;

//variables para animacionde Gumball;
static float angulovaria = 0.0f;
static float tiempoGumball = 0.0f;
static float movGumball = 0.0f;
static bool avanzaGumball = true;
float anguloExtremidadesG = 0.0f;
static float rotacionContinuaGumball = 0.0f;


//Variables para animación de Woodstock
float vuelaWoodstock = 0.0f;

void zonaFotos(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosZonaFotos, float deltaTime) {

	glm::mat4 modelaux(1.0);
	angulovaria += 0.5f * deltaTime;
	
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
//--------------------------------------------------------------------------------------------------------------------------
	// Acumulador de tiempo
	tiempoGumball += deltaTime;

	anguloExtremidadesG += 0.05f * deltaTime;

	// Movimiento de ida y vuelta en eje Z
	float distanciaMax = 10.0f;
	float tiempoViaje = 4.0f;  // segundos en ir de -distanciaMax a +distanciaMax
	float velocidad = (0.05f * distanciaMax / tiempoViaje) * deltaTime;

	if (avanzaGumball) {
		movGumball += velocidad;
		if (movGumball >= distanciaMax) avanzaGumball = false;
	}
	else {
		movGumball -= velocidad;
		if (movGumball <= -distanciaMax) avanzaGumball = true;
	}

	// Aumentar rotación continuaa
	rotacionContinuaGumball += 5.0f * deltaTime;  // 60 grados por segundo
	if (rotacionContinuaGumball >= 360.0f)
		rotacionContinuaGumball -= 360.0f;


	// Salto vertical
	float desplazamientoY = fabs(1.2f * sin(anguloExtremidadesG * 1.5f));

	// Animaciones visibles
	float anguloBrazos = glm::radians(40.0f * sin(anguloExtremidadesG * 4.0f));
	float anguloPiernas = glm::radians(15.0f * sin(anguloExtremidadesG * 4.0f));
	float anguloCola = glm::radians(60.0f * sin(anguloExtremidadesG * 5.0f));
	float giroDireccion = avanzaGumball ? 0.0f : 180.0f;

	if (movGumball > 10.0f)
		movGumball = 10.0f;
	if (movGumball < -10.0f)
		movGumball = -10.0f;

	
	//Gumball cuerpo
	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(107.0f, 6.2f+desplazamientoY, 25.0f+movGumball));
	model = glm::rotate(model, glm::radians(rotacionContinuaGumball + giroDireccion), glm::vec3(0, 1, 0));
	model = glm::scale(model, glm::vec3(1.3f, 1.3f, 1.3f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[1]->RenderModel();


	//Gumball pierna Derecha
	modelaux = model;
	model = glm::translate(model, glm::vec3(-0.314f, -3.252f, 0.0f));
	model = glm::rotate(model, anguloPiernas, glm::vec3(0.0f, 0.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[8]->RenderModel();
	model = modelaux;

	//Gumball pierna Izquierda
	modelaux = model;
	model = glm::translate(model, glm::vec3(0.337f, -3.2876f, 0.0f));
	model = glm::rotate(model, -anguloPiernas, glm::vec3(0.0f, 0.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[9]->RenderModel();
	model = modelaux;

	//Gumball brazo Derecho
	modelaux = model;
	model = glm::translate(model, glm::vec3(-0.3137f,-1.3153f,-0.2214f));
	model = glm::rotate(model,-40*toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, -anguloBrazos, glm::vec3(0.0f, 0.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[6]->RenderModel();
	model = modelaux;

	//Gumball brazo Izquierdo
	modelaux = model;
	model = glm::translate(model, glm::vec3(0.545f,-1.2657f, -0.087f));
	model = glm::rotate(model, -40 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, anguloBrazos, glm::vec3(0.0f, 0.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[7]->RenderModel();
	model = modelaux;

	//Gumball cola
	modelaux = model;
	model = glm::translate(model, glm::vec3(0.1394f, -2.9372f, -0.756f));
	model = glm::rotate(model, anguloCola, glm::vec3(0.0f, 1.0f, 0.0f));  // eje Y (lado a lado)
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[10]->RenderModel();
	model = modelaux;

//------------------------------------------------------------------------------------------------------------------

	//Yoshi
	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(105.0f, -0.9f, -25.0f));
	model = glm::scale(model, glm::vec3(7.0f, 7.0f, 7.0f));
	model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[2]->RenderModel();

	//--------------------------------------------------------------------------------------------------------------------
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