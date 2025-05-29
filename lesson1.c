#include <GL/glut.h>
#include <math.h>

#define MAX_ANGLE_RADIANS 6.1

float angle = 45.0;
float cameraHeight = 1.0;
float zoom = 25.0;


void drawCircle3D(float cx, float cy, float cz, float r, int num_segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * M_PI * (float)i / (float)num_segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex3f(x + cx, y + cy, cz);
    }
    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); 

    gluLookAt(5.0 * cos(angle), cameraHeight, 5.0 * sin(angle),
    -0.15, 0.25, -0.15,   
    0.0, 1.0, 0.0);


    // Chao
    glColor3f(0.0f, 0.6f, 0.0f); 
    glBegin(GL_QUADS);
        glVertex3f(-2.0f, 0.0f, -2.0f);
        glVertex3f(2.0f, 0.0f, -2.0f);
        glVertex3f(2.0f, 0.0f, 2.0f);
        glVertex3f(-2.0f, 0.0f, 2.0f);
    glEnd();


    // Parede esquerda
    glColor3f(0.58f, 0.0f, 0.83f); 
    glBegin(GL_QUADS);
        glVertex3f(-0.8f, 0.0f, 0.0f);
        glVertex3f(-0.5f, 0.0f, 0.0f);
        glVertex3f(-0.5f, 0.5f, 0.0f);
        glVertex3f(-0.8f, 0.5f, 0.0f);
    glEnd();

    // Porta
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(-0.68f, 0.0f, 0.01f);
        glVertex3f(-0.58f, 0.0f, 0.01f);
        glVertex3f(-0.58f, 0.25f, 0.01f);
        glVertex3f(-0.68f, 0.25f, 0.01f);
    glEnd();

    // Telhado esquerdo
    glColor3f(1.0f, 0.86f, 0.35f);
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.65f, 0.8f, 0.0f);
        glVertex3f(-0.5f, 0.5f, 0.0f);
        glVertex3f(-0.8f, 0.5f, 0.0f);
    glEnd();

    // Janela circular
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCircle3D(-0.65f, 0.63f,0.01f, 0.035f, 50);

    // Telhado direito
    glColor3f(0.5f, 0.8f, 1.0f);
    glBegin(GL_QUADS);
        glVertex3f(-0.5f, 0.5f, 0.0f);
        glVertex3f(0.5f, 0.5f, 0.0f);
        glVertex3f(0.4f, 0.8f, 0.0f);
        glVertex3f(-0.65f, 0.8f, 0.0f);
    glEnd();
 
    // Parede direita     glColor3f(0.6f, 1.0f, 0.9f);
    glColor3f(0.93f, 0.57f, 0.13f);
    glBegin(GL_QUADS);
        glVertex3f(-0.5f, 0.0f, 0.0f);
        glVertex3f(0.5f, 0.0f, 0.0f);
        glVertex3f(0.5f, 0.5f, 0.0f);
        glVertex3f(-0.5f, 0.5f, 0.0f);
    glEnd();

    // Janelas
    glColor3f(0.07f, 0.04f, 0.56f);
    glBegin(GL_QUADS);
        glVertex3f(-0.35f, 0.15f, 0.01f);
        glVertex3f(-0.2f, 0.15f, 0.01f);
        glVertex3f(-0.2f, 0.3f, 0.01f);
        glVertex3f(-0.35f, 0.3f, 0.01f);

        glVertex3f(-0.05f, 0.15f, 0.01f);
        glVertex3f(0.1f, 0.15f, 0.01f);
        glVertex3f(0.1f, 0.3f, 0.01f);
        glVertex3f(-0.05f, 0.3f, 0.01f);
    glEnd();

    glColor3f(0.07f, 0.04f, 0.56f);
    glBegin(GL_QUADS);
        glVertex3f(-0.35f, 0.15f, -0.01f);
        glVertex3f(-0.2f, 0.15f, -0.01f);
        glVertex3f(-0.2f, 0.3f, -0.01f);
        glVertex3f(-0.35f, 0.3f, -0.01f);

        glVertex3f(-0.05f, 0.15f, -0.01f);
        glVertex3f(0.1f, 0.15f, -0.01f);
        glVertex3f(0.1f, 0.3f, -0.01f);
        glVertex3f(-0.05f, 0.3f, -0.01f);
    glEnd();


    // Chamine
        // Parte de baixo
    glColor3f(0.5f, 0.0f, 0.13f); 
    glBegin(GL_QUADS);
        glVertex3f(-0.2f, 0.75f, 0.01f);
        glVertex3f(-0.1f, 0.75f, 0.01f);
        glVertex3f(-0.1f, 0.85f, 0.01f);
        glVertex3f(-0.2f, 0.85f, 0.01f);
    glEnd();

        // Parte de cima 
    glColor3f(0.5f, 0.0f, 0.13f); 
    glBegin(GL_QUADS);
        glVertex3f(-0.22f, 0.85f, 0.01f);
        glVertex3f(-0.08f, 0.85f, 0.01f);
        glVertex3f(-0.08f, 0.90f, 0.01f);
        glVertex3f(-0.22f, 0.90f, 0.01f);
    glEnd();
    

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // fundo preto
    glEnable(GL_DEPTH_TEST);
    gluOrtho2D(-1, 1, -1, 1);
}

void updateProjection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(zoom, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            angle += 0.01f;
            break;
        case 'd':
            angle -= 0.01f;
            break;
        case 'w':
            cameraHeight += 0.02f;
            break;
        case 's':
            cameraHeight -= 0.02f;
            break;
        case 'z':
            zoom = fmax(zoom - 5.0, 5.0);
            updateProjection();
            break;
        case 'x':
            zoom = fmin(zoom + 5.0, 175.0);
            updateProjection();
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH); 
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Casinha");
    init();
    updateProjection(); 
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
