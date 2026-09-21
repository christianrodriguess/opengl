#include <GL/freeglut.h>

void desenha(void);
void escutaTecla(unsigned char tecla, GLint x, GLint y);
void desenhaLetraC(float x, float y);
void desenhaLetraH(float x, float y);
void desenhaLetraR(float x, float y);
void desenhaLetraI(float x, float y);
void desenhaLetraS(float x, float y);
void desenhaLetraT(float x, float y);
void desenhaLetraA(float x, float y);
void desenhaLetraN(float x, float y);

GLfloat escala = 1;
GLfloat translacaoHorizontal = 0;
GLfloat translacaoVertical = 0;
GLfloat rotacao = 0;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Minha Janela OpenGL");

    glutKeyboardFunc(escutaTecla);
    glutDisplayFunc(desenha);

    glClearColor(0, 0, 1, 0);
    glutMainLoop();

    return 0;
}

void desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluOrtho2D(0, 32, 0, 32);

    glScalef(escala, escala, 0);

    glTranslatef(translacaoHorizontal, translacaoVertical, 0);

    glRotatef(rotacao, 0, 0, 1);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    desenhaLetraC(1, 1);
    desenhaLetraH(5, 1);
    desenhaLetraR(9, 1);
    desenhaLetraI(13, 1);
    desenhaLetraS(15, 1);
    desenhaLetraT(19, 1);
    desenhaLetraI(23, 1);
    desenhaLetraA(25, 1);
    desenhaLetraN(29, 1);

    glFlush();  
}

void escutaTecla(unsigned char tecla, GLint x, GLint y){
    switch (tecla){
        case '+':
            escala += 0.5;
            break;
        case '-':
            if(escala > 0.5){
                escala -= 0.5;
            }
            break;
        case 'a':
            translacaoHorizontal--;
            break;
        case 'd':
            translacaoHorizontal++;
            break;
        case 'w':
            translacaoVertical++;
            break;
        case 's':
            translacaoVertical--;
            break;
        case 'q':
            rotacao++;
            break;
        case 'e':
            rotacao--;
            break;
        default:
            break;
    }
    desenha();
}

void desenhaLetraC(float x, float y){
    glBegin(GL_LINE_STRIP);
        glVertex2f(x+2, y);
        glVertex2f(x+1, y);
        glVertex2f(x, y+1);
        glVertex2f(x, y+3);
        glVertex2f(x+1, y+4);
        glVertex2f(x+2, y+4);
    glEnd();
}

void desenhaLetraH(float x, float y){
    glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x, y+4);
        glVertex2f(x, y+2);
        glVertex2f(x+2, y+2);
        glVertex2f(x+2, y);
        glVertex2f(x+2, y+4);
    glEnd();
}

void desenhaLetraR(float x, float y){
    glBegin(GL_LINE_STRIP);
        glVertex2f(x, y);
        glVertex2f(x, y+4);
        glVertex2f(x+2, y+4);
        glVertex2f(x+2, y+2);
        glVertex2f(x, y+2);
        glVertex2f(x+2, y);
    glEnd();
}

void desenhaLetraI(float x, float y){
    glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x, y+4);
    glEnd();
}

void desenhaLetraS(float x, float y){
    glBegin(GL_LINE_STRIP);
        glVertex2f(x, y);
        glVertex2f(x+2, y);
        glVertex2f(x+2, y+2);
        glVertex2f(x, y+2);
        glVertex2f(x, y+4);
        glVertex2f(x+2, y+4);
    glEnd();
}

void desenhaLetraT(float x, float y){
    glBegin(GL_LINES);
        glVertex2f(x+1, y);
        glVertex2f(x+1, y+4);
        glVertex2f(x, y+4);
        glVertex2f(x+2, y+4);
    glEnd();
}

void desenhaLetraA(float x, float y){
    glBegin(GL_LINE_STRIP);
        glVertex2f(x, y);
        glVertex2f(x, y+4);
        glVertex2f(x+2, y+4);
        glVertex2f(x+2, y+2);
        glVertex2f(x, y+2);
        glVertex2f(x+2, y+2);
        glVertex2f(x+2, y);
    glEnd();
}

void desenhaLetraN(float x, float y){
    glBegin(GL_LINE_STRIP);
        glVertex2f(x, y);
        glVertex2f(x, y+4);
        glVertex2f(x+2, y);
        glVertex2f(x+2, y+4);
    glEnd();
}