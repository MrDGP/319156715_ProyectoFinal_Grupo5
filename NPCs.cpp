#include "NPCs.h"

const float toRadians = 3.14159265f / 180.0f;

void NPCs(glm::mat4 model, GLuint uniformModel, std::vector<Model*> personajesNPCs) {
	//Juegos
	renderSnoopy(model, uniformModel, *personajesNPCs[0], glm::vec3(67.0f, -0.5f, 89.0f), 180); //Topos
	renderCarrie(model, uniformModel, *personajesNPCs[3], glm::vec3(-63.0f, 5.0f, 90.0f), 90); //Boliche
	renderBowser(model, uniformModel, *personajesNPCs[5], glm::vec3(198.0f, -0.6f, 89.0f), 180); //Hacha
	renderPeppermint(model, uniformModel, *personajesNPCs[1], glm::vec3(-65.0f, -1.0f, -90.0f), 0); //Bateo
	renderKingBoo(model, uniformModel, *personajesNPCs[6], glm::vec3(65.0f, -1.0f, -89.0f), 0); //Dardos
	renderTeri(model, uniformModel, *personajesNPCs[4], glm::vec3(195.0f, 8.0f, -88.0f), 0); //Dados
	//Comida
	renderWario(model, uniformModel, *personajesNPCs[8], glm::vec3(-220.0f, -1.0f, -60.0f), 90); //Palomitas
	renderDonkeyKong(model, uniformModel, *personajesNPCs[7], glm::vec3(-220.0f, -1.0f, 0.0f), 90); //Helados
	renderCharlie(model, uniformModel, *personajesNPCs[2], glm::vec3(-220.0f, -1.0f, 60.0f), 90); //Algodones de azúcar

	//Dentro de juegos
	renderSnoopy(model, uniformModel, *personajesNPCs[0], glm::vec3(-90.0f, -1.0f, -115.0f), 180); //Dentro de bateo
	renderKingBoo(model, uniformModel, *personajesNPCs[6], glm::vec3(180.0f, -0.6f, -150.0f), 180); //Dentro de dados
	renderTeri(model, uniformModel, *personajesNPCs[4], glm::vec3(190.0f, 8.0f, 115.0f), 0); //Dentro de hacha
	renderBowser(model, uniformModel, *personajesNPCs[5], glm::vec3(40.0f, 0.0f, -115.0f), 180); //Dentro de dardos 
	renderSnoopy(model, uniformModel, *personajesNPCs[0], glm::vec3(-69.0f, -0.5f, 140.0f), 0); //Dentro de bolos
	renderTeri(model, uniformModel, *personajesNPCs[4], glm::vec3(-88.0f, 8.0f, 140.0f), 0); //Dentro de bolos
	//Topos
	renderPeppermint(model, uniformModel, *personajesNPCs[1], glm::vec3(58.0f, -1.0f, 150.0f), 90);
	renderCarrie(model, uniformModel, *personajesNPCs[3], glm::vec3(58.0f, 5.0f, 125.0f), 0);
	renderWario(model, uniformModel, *personajesNPCs[8], glm::vec3(58.0f, -1.0f, 175.0f), 90);
	renderDonkeyKong(model, uniformModel, *personajesNPCs[7], glm::vec3(42.0f, -1.0f, 175.0f), -90);
	renderCharlie(model, uniformModel, *personajesNPCs[2], glm::vec3(42.0f, -1.0f, 150.0f), -90);
}



void renderSnoopy(glm::mat4 model, GLuint uniformModel, Model& snoopy, glm::vec3 posicion, int grados) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(22.0f, 22.0f, 22.0f));
	model = glm::rotate(model, grados * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	snoopy.RenderModel();
}

void renderPeppermint(glm::mat4 model, GLuint uniformModel, Model& peppermint, glm::vec3 posicion, int grados) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.2f, 1.2f, 1.2f));
	model = glm::rotate(model, grados * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	peppermint.RenderModel();
}

void renderCharlie(glm::mat4 model, GLuint uniformModel, Model& charlie, glm::vec3 posicion, int grados) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.2f, 1.2f, 1.2f));
	model = glm::rotate(model, grados * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	charlie.RenderModel();
}

void renderCarrie(glm::mat4 model, GLuint uniformModel, Model& carrie, glm::vec3 posicion, int grados) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	model = glm::rotate(model, grados * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	carrie.RenderModel();
}

void renderTeri(glm::mat4 model, GLuint uniformModel, Model& Teri, glm::vec3 posicion, int grados) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(0.8f, 0.8f, 0.8f));
	model = glm::rotate(model, grados * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	Teri.RenderModel();
}

void renderBowser(glm::mat4 model, GLuint uniformModel, Model& bowser, glm::vec3 posicion, int grados) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(3.5f, 3.5f, 3.5f));
	model = glm::rotate(model, grados * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	bowser.RenderModel();
}

void renderKingBoo(glm::mat4 model, GLuint uniformModel, Model& kingBoo, glm::vec3 posicion, int grados) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(7.0f, 7.0f, 7.0f));
	model = glm::rotate(model, grados * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	kingBoo.RenderModel();
}

void renderDonkeyKong(glm::mat4 model, GLuint uniformModel, Model& donkeyKong, glm::vec3 posicion, int grados) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(5.0f, 5.0f, 5.0f));
	model = glm::rotate(model, grados * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	donkeyKong.RenderModel();
}

void renderWario(glm::mat4 model, GLuint uniformModel, Model& wario, glm::vec3 posicion, int grados) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, glm::vec3(7.0f, 7.0f, 7.0f));
	model = glm::rotate(model, grados * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	wario.RenderModel();
}


//Renderizado de personajes principales  
//(Para utilizar un personaje distinto comenta el personaje actual y descomenta el que quieras usar)
////gumball
//model = glm::mat4(1.0);
//model = glm::translate(model, posicionModelo);
//model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
//model = glm::rotate(model, angulo, glm::vec3(0.0f, 1.0f, 0.0f));
//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
//gumball.RenderModel();

/*
//yoshi
model = glm::mat4(1.0);
model = glm::translate(model, posicionModelo);
model = glm::scale(model, glm::vec3(6.0f, 6.0f, 6.0f));
model = glm::rotate(model, angulo, glm::vec3(0.0f, 1.0f, 0.0f));
glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
yoshi.RenderModel();
*/