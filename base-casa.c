#include <GL/glut.h>
#include <math.h>

// Largura e altura da janela
GLfloat windowWidth;
GLfloat windowHeight;

//Desenha um quadrado de lado 1 centrado na origem
void desenhaQuadrado() {
    glBegin(GL_QUADS);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.5, 0.5);
    glEnd();
}

//Desenha um triângulo equilátero de lado 1 centrado na origem
void desenhaTriangulo() {
    glBegin(GL_TRIANGLES);
        glVertex2d(0.0, 0.5);
        glVertex2d(-0.5, -0.5);
        glVertex2d(0.5, -0.5);
    glEnd();
}

//Desenha um círculo de raio 1 centrado na origem
void desenhaCirculo() {
    glBegin(GL_POLYGON);
        for (int i = 0; i < 30; i++) {
            glVertex2f(cos(i), sin(i));
        }
    glEnd();
}

//Faz o cisalhamento de um objeto em relação ao eixo X
//Basta utilizar como uma das funções do OpenGL como glTranslatef, glRotatef, glScalef
void skewX(GLfloat angle) {
    GLfloat m[16] = {
        1, 0, 0, 0,
        tan(angle), 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0 ,1
    };
    glMultMatrixf(m);
}

//Faz o cisalhamento de um objeto em relação ao eixo Y
//Basta utilizar como uma das funções do OpenGL como glTranslatef, glRotatef, glScalef
void skewY(GLfloat angle) {
    GLfloat m[16] = {
        1, tan(angle), 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    glMultMatrixf(m);
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    // Piso
    glPushMatrix();
        glColor3f(0.0f, 0.6f, 0.0f);
        glTranslatef(windowWidth/2, 50, 0);
        glScalef(400, 100, 1);
        desenhaQuadrado();
    glPopMatrix();

    // Parede esquerda
    glPushMatrix();
        glColor3f(0.58f, 0.0f, 0.83f);
        glTranslatef(60, 150, 0);
        glScalef(80, 100, 1);
        desenhaQuadrado();
    glPopMatrix();

    // Porta
    glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.0f);
        glTranslatef(60, 125, 0);
        glScalef(20, 50, 1);
        desenhaQuadrado();
    glPopMatrix();

    // Telhado esquerdo 
    glPushMatrix();
        glColor3f(1.0f, 0.86f, 0.35f);
        glTranslatef(60, 230, 0);
        glScalef(80, 60, 1);
        desenhaTriangulo();
    glPopMatrix();

    // Janela circular
    glPushMatrix();
        glColor3f(0.0f, 1.0f, 0.0f);
        glTranslatef(60, 225, 0);
        glScalef(10, 10, 1);
        desenhaCirculo();
    glPopMatrix();

    // Parede direita
    glPushMatrix();
        glColor3f(0.93f, 0.57f, 0.13f);
        glTranslatef(200, 150, 0);
        glScalef(200, 100, 1);
        desenhaQuadrado();
    glPopMatrix();

    // Janelas
    float janelaX[] = {150, 230};
    for (int i = 0; i < 2; i++) {
        glPushMatrix();
            glColor3f(0.07f, 0.04f, 0.56f);
            glTranslatef(janelaX[i], 150, 0);
            glScalef(40, 40, 1);
            desenhaQuadrado();
        glPopMatrix();
    }

    // Telhado direito 
    glPushMatrix();
        glColor3f(0.5f, 0.8f, 1.0f);
        glTranslatef(180, 230, 0);
        glScalef(200, 60, 0);
        skewX(-0.200);
        desenhaQuadrado();
    glPopMatrix();

    // Chamine (parte de baixo)
    glPushMatrix();
        glColor3f(0.5f, 0.0f, 0.13f);
        glTranslatef(230, 260, 0);
        glScalef(20, 30, 1);
        desenhaQuadrado();
    glPopMatrix();

    // Chamine (parte de cima)
    glPushMatrix();
        glColor3f(0.5f, 0.0f, 0.13f);
        glTranslatef(230, 280, 0);
        glScalef(30, 10, 1);
        desenhaQuadrado();
    glPopMatrix();

    glutSwapBuffers();
}


// Inicializa parâmetros de rendering
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Evita a divisao por zero
    if(h == 0) h = 1;

    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de seleção (left, right, bottom, top)
    // Se a largura da janela, em pixels, for menor que a altura, a largura da viewport é fixada em 250 e a altura é escalada para o necessário
    if (w <= h)  {
        windowHeight = 300.0f*h/w;
                windowWidth = 300.0f;
    }
    else  {
    // Se a altura da janela, em pixels, for menor que a largura, a altura da viewport é fixada em 300 e a largura é escalada para o necessário
                windowWidth = 300.0f*w/h;
                windowHeight = 300.0f;
    }

    // As dimensões da janela vão de (0.0, 0.0) até (windowWidth, windowHeight), essas são as coordenadas da tela
    gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}

// Programa Principal
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Minha Casa");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    Inicializa();
    glutMainLoop();
    return 0;
}