#include <cmath>
#include <vector>
#include <math.h>

#include <glew.h>
#include <glfw3.h>

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>

#include "Mesh.h"
#include "Texture.h"
#include"Model.h"

void dados(glm::mat4 model, GLuint uniformModel, std::vector<Model*> objetosDados);
void renderStand3(glm::mat4 model, GLuint uniformModel, Model& stand, glm::vec3 posicion);
void renderMesaDados(glm::mat4 model, GLuint uniformModel, Model& mesa, glm::vec3 posicion);
void renderDado(glm::mat4 model, GLuint uniformModel, Model& dado, glm::vec3 posicion);
void renderHongo(glm::mat4 model, GLuint uniformModel, Model& hongo, glm::vec3 posicion, int grados);
void renderCuadro(glm::mat4 model, GLuint uniformModel, Model& cuadro, glm::vec3 posicion, int grados);