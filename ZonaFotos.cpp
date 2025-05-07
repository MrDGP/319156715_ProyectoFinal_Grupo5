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
static float movGumball = 0.0f;
static float offsetGumball = 0.05f; 
static bool avanzaGumball = true;


//variables para animacion de Yoshi;
static float angSaltoYoshi = 0.0f;
static float angBrazoYoshi = 0.0f;
static float angGiroYoshi = 0.0f;
static float angPatasYoshi = 0.0f;
static float movYoshi = 0.0f;
static float offsetYoshi = 0.08f;
static bool avanzaYoshi = true;
static float tiempoBrazo = 0.0f;
static bool movBrazo = false;

//Variables para animación de Woodstock
float vuelaWoodstock = 0.0f;

void zonaFotos(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosZonaFotos, float deltaTime) {

	glm::mat4 modelaux(1.0);
	angulovaria += 0.5f * deltaTime;

	//Casa con Snoopy

	vuelaSnoopy += 0.1f * deltaTime;

	if (vuelaSnoopy >= 360.0f) {
		vuelaSnoopy = 0.0f;
	}

	amplitud = 12.0;
	velocidadSnoopy = 0.3f;
	snoopyY = amplitud * sin(velocidadSnoopy * vuelaSnoopy);
	snoopyZ = amplitud * cos(velocidadSnoopy * vuelaSnoopy);

	//Ida y vuelta Snoopy

	if (movSnoopy > -100.0f && avanzaSnoopy == true) {
		movSnoopy -= movOffsetSnoopy;
	}
	else if (movSnoopy < -100.0f) {
		movSnoopy += movOffsetSnoopy;
		avanzaSnoopy = false;
	}
	else if (movSnoopy < 5.0f && avanzaSnoopy == false) {
		movSnoopy += movOffsetSnoopy;
	}
	else {
		movSnoopy -= movOffsetSnoopy;
		avanzaSnoopy = true;
	}

	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(100.0f + movSnoopy, 15.0f + snoopyY, 4.0f + snoopyZ));
	model = glm::scale(model, glm::vec3(50.0f, 40.0f, 50.0f));
	model = glm::rotate(model, -90 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	if (avanzaSnoopy == false) {
		model = glm::rotate(model, glm::radians(-180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	}
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[0]->RenderModel();
	//--------------------------------------------------------------------------------------------------------------------------

	float anguloPiernasg = glm::radians(30.0f * sin(glm::radians(angulovaria * 12.0f)));
	float anguloAleteo = glm::radians(45.0f * sin(glm::radians(angulovaria * 15.0f)));
	float anguloCola = glm::radians(40.0f * sin(glm::radians(angulovaria * 25.0f)));
	float desplazamientoSalto = fabs(1.8f * sin(glm::radians(angulovaria * 6.0f)));


	// Movimiento ida y vuelta de Gumball
	if (movGumball < 10.0f && avanzaGumball) {
		movGumball += offsetGumball;
	}
	else {
		avanzaGumball = false;
	}

	if (movGumball > -10.0f && !avanzaGumball) {
		movGumball -= offsetGumball;
	}
	else {
		avanzaGumball = true;
	}

	//Gumball cuerpo
	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(107.0f, 6.2f + desplazamientoSalto, 25.0f + movGumball));
	model = glm::scale(model, glm::vec3(1.3f, 1.3f, 1.3f));
	if (desplazamientoSalto > 0.1f) {
		// Gira en el aire con una rotación variable
		model = glm::rotate(model, glm::radians(angulovaria * 15.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	}

	if (!avanzaGumball) {
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	}
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[1]->RenderModel();


	//Gumball pierna Derecha
	modelaux = model;
	model = glm::translate(model, glm::vec3(-0.314f, -3.252f, 0.0f));
	//model = glm::rotate(model, anguloPiernasg, glm::vec3(1.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[8]->RenderModel();
	model = modelaux;

	//Gumball pierna Izquierda
	modelaux = model;
	model = glm::translate(model, glm::vec3(0.337f, -3.2876f, 0.0f));
	//model = glm::rotate(model, -anguloPiernasg, glm::vec3(1.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[9]->RenderModel();
	model = modelaux;

	//Gumball brazo Derecho
	modelaux = model;
	model = glm::translate(model, glm::vec3(-0.3137f, -1.3153f, -0.2214f));
	model = glm::rotate(model, -40 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, -anguloAleteo, glm::vec3(1.0f, 0.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[6]->RenderModel();
	model = modelaux;

	//Gumball brazo Izquierdo
	modelaux = model;
	model = glm::translate(model, glm::vec3(0.545f, -1.2657f, -0.087f));
	model = glm::rotate(model, -40 * toRadians, glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, anguloAleteo, glm::vec3(1.0f, 0.0f, 1.0f));
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
	float saltoYoshi = fabs(3.5f * sin(glm::radians(angSaltoYoshi * 2.5f)));
	angSaltoYoshi += 30.0f * deltaTime;
	angPatasYoshi = glm::radians(25.0f * sin(glm::radians(angSaltoYoshi * 8.0f)));
	// Movimiento horizontal
	if (movYoshi < 20.0f && avanzaYoshi) {
		movYoshi += offsetYoshi;
		if (movYoshi >= 20.0f && !movBrazo) {
			movBrazo = true;
			tiempoBrazo = 0.0f;
		}
	}
	else {
		avanzaYoshi = false;
	}

	if (movYoshi > -20.0f && !avanzaYoshi) {
		movYoshi -= offsetYoshi;
		if (movYoshi <= -20.0f && !movBrazo) {
			movBrazo = true;
			tiempoBrazo = 0.0f;
		}
	}
	else {
		avanzaYoshi = true;
	}

	if (movBrazo) {
		tiempoBrazo += deltaTime;

		if (movBrazo < 1.0f) {
			angBrazoYoshi = -180.0f * (tiempoBrazo / 1.0f);
			angGiroYoshi = 360.0f * (tiempoBrazo / 2.0f);
		}
		else if (tiempoBrazo < 2.0f) {
			angBrazoYoshi = -180.0f * (1.0f - (tiempoBrazo - 1.0f) / 1.0f);
			angGiroYoshi = 360.0f * (tiempoBrazo / 2.0f); 
		}
		else {
			angBrazoYoshi = 0.0f;
			angGiroYoshi = 0.0f;
			movBrazo = false;
		}
	}
	else {
		angBrazoYoshi = 0.0f;
		angGiroYoshi = 0.0f;
	}

	model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(105.0f + movYoshi, 6.8f + saltoYoshi, -25.0f));
	model = glm::scale(model, glm::vec3(7.0f, 7.0f, 7.0f));
	model = glm::rotate(model, glm::radians(90.0f + angGiroYoshi), glm::vec3(0.0f, 1.0f, 0.0f));
	modelaux = model;
	if (!avanzaYoshi) {
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	}
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[2]->RenderModel();

	//YoshiManoDerecha
	model = glm::translate(model, glm::vec3(-0.22f, 0.0f, 0.0f));
	modelaux = model;
	model = glm::rotate(model, glm::radians(angBrazoYoshi), glm::vec3(1.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[11]->RenderModel();
	//YoshiManoIzquierda
	model = modelaux;
	model = glm::translate(model, glm::vec3(0.431f, 0.005f, 0.0f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[12]->RenderModel();

	//YoshiPataDerecha
	model = modelaux;
	model = glm::translate(model, glm::vec3(-0.48f, -0.595f, -0.06f));
	modelaux = model;
	model = glm::rotate(model, angPatasYoshi, glm::vec3(1.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[13]->RenderModel();
	//YoshiPataIzquierda
	model = modelaux;
	model = glm::translate(model, glm::vec3(0.52f, 0.006f, 0.02f));
	model = glm::rotate(model, -angPatasYoshi, glm::vec3(1.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	objetosZonaFotos[14]->RenderModel();



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