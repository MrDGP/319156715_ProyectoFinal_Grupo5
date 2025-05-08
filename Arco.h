#include <stdio.h>
#include <string.h>
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
#include "Model.h"
#include "Material.h"

void arco(glm::mat4 model, GLuint uniformModel, GLuint uniformTextureOffset, std::vector<Model*> objetosArco, float deltaTime, Texture& letrero, std::vector<Mesh*> meshList);
void inicializarMensajeLetrero();