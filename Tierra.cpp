#include "Tierra.h"

void tierra(glm::mat4 model, GLuint uniformModel, Texture& tierra, std::vector<Mesh*> meshList) {
	
	//Caminos
	renderTierra(model, uniformModel, tierra, *meshList[4], glm::vec3(180.0f, -1.0f, 0.0f), glm::vec3(20.0f, 0.05f, 150.0f));
	renderTierra(model, uniformModel, tierra, *meshList[4], glm::vec3(225.0f, -1.0f, 0.0f), glm::vec3(70.0f, 0.05f, 20.0f));
	renderTierra(model, uniformModel, tierra, *meshList[4], glm::vec3(115.0f, -1.0f, -140.0f), glm::vec3(50.0f, 0.05f, 20.0f));
	renderTierra(model, uniformModel, tierra, *meshList[4], glm::vec3(115.0f, -1.0f, 140.0f), glm::vec3(50.0f, 0.05f, 20.0f));
	renderTierra(model, uniformModel, tierra, *meshList[4], glm::vec3(-15.0f, -1.0f, -140.0f), glm::vec3(50.0f, 0.05f, 20.0f));
	renderTierra(model, uniformModel, tierra, *meshList[4], glm::vec3(-15.0f, -1.0f, 140.0f), glm::vec3(50.0f, 0.05f, 20.0f));
	renderTierra(model, uniformModel, tierra, *meshList[4], glm::vec3(-170.0f, -1.0f, -140.0f), glm::vec3(100.0f, 0.05f, 20.0f));
	renderTierra(model, uniformModel, tierra, *meshList[4], glm::vec3(-170.0f, -1.0f, 140.0f), glm::vec3(100.0f, 0.05f, 20.0f));
	renderTierra(model, uniformModel, tierra, *meshList[4], glm::vec3(-210.0f, -1.0f, -120.0f), glm::vec3(20.0f, 0.05f, 20.0f));
	renderTierra(model, uniformModel, tierra, *meshList[4], glm::vec3(-210.0f, -1.0f, 120.0f), glm::vec3(20.0f, 0.05f, 20.0f));
	
	//Lanzamiento de hacha
	renderTierra(model, uniformModel, tierra, *meshList[4], glm::vec3(180.0f, -1.0f, 140.0f), glm::vec3(80.0f, 0.05f, 130.0f));

	//Jaula de bateo
	renderTierra(model, uniformModel, tierra, *meshList[4], glm::vec3(-80.0f, -1.0f, -140.0f), glm::vec3(80.0f, 0.05f, 130.0f));

	//Lanzamiento de dados
	renderTierra(model, uniformModel, tierra, *meshList[4], glm::vec3(180.0f, -1.0f, -140.0f), glm::vec3(80.0f, 0.05f, 130.0f));
	
	//Lanzamiento de dardos
	renderTierra(model, uniformModel, tierra, *meshList[4], glm::vec3(50.0f, -1.0f, -140.0f), glm::vec3(80.0f, 0.05f, 130.0f));
	
	//Bolos
	renderTierra(model, uniformModel, tierra, *meshList[4], glm::vec3(-80.0f, -1.0f, 140.0f), glm::vec3(80.0f, 0.05f, 130.0f));

	//Golpea al topo
	renderTierra(model, uniformModel, tierra, *meshList[4], glm::vec3(50.0f, -1.0f, 140.0f), glm::vec3(80.0f, 0.05f, 130.0f));

	//Área de comida
	renderTierra(model, uniformModel, tierra, *meshList[4], glm::vec3(-210.0f, -1.0f, 0.0f), glm::vec3(80.0f, 0.05f, 220.0f));
}

void renderTierra(glm::mat4 model, GLuint uniformModel, Texture& tierra, Mesh& piso, glm::vec3 posicion, glm::vec3 escala) {
	model = glm::mat4(1.0);
	model = glm::translate(model, posicion);
	model = glm::scale(model, escala);
	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
	tierra.UseTexture();
	piso.RenderMesh();
}