#include "Dardos.h"

float animacionDardo = 0.0f;
bool lanzandoDardo = false;
bool globoImpactado = false;
bool dardoDetenido = false;
float escalaGlobo = 1.0f;
float tiempoImpactoDardo = 0.0f;

void dardos(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosDardos) {
	renderStand4(model, uniformModel, *objetosDardos[0], *objetosDardos[3], *objetosDardos[5], *objetosDardos[6], glm::vec3(50.0f, -1.42f, -140.0f));
	renderDardos(model, uniformModel, *objetosDardos[4], glm::vec3(49.0f, 4.2f, -125.0f));
	renderGlobos(model, uniformModel, *objetosDardos[1], *objetosDardos[2], glm::vec3(39.0f, 6.58f, -160.0f));
}

void renderStand4(glm::mat4 model, GLuint uniformModel, Model& stand, Model& tabla, Model& cuadro1, Model& cuadro2, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	glm::mat4 modelaux(1.0);

	//Casa
	model = glm::translate(model, posicion);
	modelaux = model;
	model = glm::scale(model, glm::vec3(2.5f, 2.5f, 2.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	stand.RenderModel();

	//Tabla
	model = modelaux;
	model = glm::translate(model, glm::vec3(-1.0f, 5.0f, 15.0f));
	model = glm::scale(model, glm::vec3(2.1f, 2.0f, 1.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tabla.RenderModel();

	//Cuadro1
	model = modelaux;
	model = glm::translate(model, glm::vec3(-24.8f, 8.0f, -3.0f));
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(2.0f, 2.0f, 1.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	cuadro1.RenderModel();
	//Cuadro2
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 47.6f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	cuadro2.RenderModel();
}

void renderDardos(glm::mat4 model, GLuint uniformModel, Model& dardo, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -4.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -4.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -4.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, -4.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 20.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 4.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 4.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 4.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 4.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
	//Dardo animado
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 6.0f));
	model = glm::translate(model, glm::vec3(animacionDardo * 14.0f, animacionDardo * 0.5f, 0.0f));
	model = glm::rotate(model, glm::radians(animacionDardo * 360.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	dardo.RenderModel();
}

void renderGlobos(glm::mat4 model, GLuint uniformModel, Model& base, Model& globo, glm::vec3 posicion) {
	model = glm::mat4(1.0);
	glm::mat4 modelaux(1.0);
	glm::mat4 modelaux2(1.0);
	//Base1
	model = glm::translate(model, posicion);
	modelaux = model;
	modelaux2 = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	base.RenderModel();
	//Globo1.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(-2.5f, 5.5f, -1.0f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo1.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo1.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo1.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo1.5
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo2.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(0.7f, -1.5f, 0.1f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo2.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo2.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo2.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(-0.7f, -1.5f, 0.1f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.5
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo4.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(0.7f, -1.5f, 0.1f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo4.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo4.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo4.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(-0.7f, -1.5f, 0.1f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.5
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();

	//Base2
	model = modelaux2;
	model = glm::translate(model, glm::vec3(20.0f, 0.0f, 0.0f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	base.RenderModel();
	//Globo1.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(-2.5f, 5.5f, -1.0f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo1.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo1.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo1.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo1.5
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo2.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(0.7f, -1.5f, 0.1f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo2.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo2.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo2.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(-0.7f, -1.5f, 0.1f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo3.5
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo4.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(0.7f, -1.5f, 0.1f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo4.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo4.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo4.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.1
	model = modelaux;
	model = glm::translate(model, glm::vec3(-0.7f, -1.5f, 0.1f));
	modelaux = model;
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.2
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.3
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.4
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
	//Globo5.5 (animado)
	model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.0f));
	model = glm::scale(model, glm::vec3(escalaGlobo));
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	globo.RenderModel();
}

void lanzarDardo() {
	if (!lanzandoDardo) {
		lanzandoDardo = true;
		animacionDardo = 0.0f;
		globoImpactado = false;
		dardoDetenido = false;
		escalaGlobo = 1.0f;
	}
}

void actualizarDardos(float deltaTime) {
	if (lanzandoDardo) {
		if (!dardoDetenido) {
			animacionDardo += deltaTime;
		}
		if (animacionDardo >= 5.0f && !globoImpactado) {
			globoImpactado = true;
			tiempoImpactoDardo = 0.0f;
			dardoDetenido = true;
		}
		if (globoImpactado) {
			tiempoImpactoDardo += deltaTime;
			escalaGlobo = glm::max(0.0f, 1.0f - tiempoImpactoDardo);
			if (tiempoImpactoDardo >= 3.0f) {
				lanzandoDardo = false;
				animacionDardo = 0.0f;
				escalaGlobo = 1.0f;
			}
		}
	}
}