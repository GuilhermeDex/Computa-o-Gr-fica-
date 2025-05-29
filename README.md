# COMPUTAÇÃO GRÁFICA
```c
#define AUTOR "Guilherme Francis"
#define DISCIPLINA "Computação Gráfica"
#define PROFESSOR "Daniel Madeira"
```

## 🏡 Casa 2D usando OpenGL

Utilizamos nesse projeto a biblioteca OpenGL para desenhar uma casa em 2D composta por formas geométricas básicas (quadrado, triângulo e círculo), aplicando transformações como translação, escala, cisalhamento (skew), e rotação.

---

## 🧱 Características

A casa tem as seguintes caracteristicas:

- Construção de uma casa usando apenas primitivas básicas.
- Transformações geométricas: glTranslatef, glScalef, glRotatef, skewX, skewY.
- Organização dos elementos com glPushMatrix() e glPopMatrix().


E além disso, os elementos desenhados são:

- Piso
- Parede com porta
- Telhado com janela circular
- Parede com janelas quadradas
- Telhado com cisalhamento
- Chaminé

---

## 🚀 Como compilar

### Pré-requisitos

- GCC da linguagem C instalado
- OpenGL: freeglut3 

```bash
make
./casinhaa
```
---


&nbsp;