#include <GL/freeglut.h>

void desenha(void);
void desenhaLetraC();
void desenhaLetraH();
void desenhaLetraR();
void escutaTecla(unsigned char tecla, GLint x, GLint y);

GLfloat escalaVertical = 1;
GLfloat escalaHorizontal = 1;
GLfloat movimentoHorizontal = 0;
GLfloat rotacao = 0;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGBA );
    glutInitWindowSize(800, 600);
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
    
    gluOrtho2D(0, 12, 0, 12);

    glScalef(escalaHorizontal, escalaVertical, 0);

    glTranslatef(movimentoHorizontal, 0, 0);

    glRotatef(rotacao, 0, 0, 1);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    desenhaLetraC();
    desenhaLetraH();
    desenhaLetraR();

    glFlush();  
}

void escutaTecla(unsigned char tecla, GLint x, GLint y){
    switch (tecla){
        case '+':
            escalaHorizontal += 0.5;
            break;
        case '-':
            escalaHorizontal -= 0.5;
            break;
        case 'i':
            escalaVertical += 0.5;
            break;
        case 'k':
            escalaVertical -= 0.5;
            break;
        case 'g':
            movimentoHorizontal--;
            break;
        case 'h':
            movimentoHorizontal++;
            break;
        case 'n':
            rotacao++;
            break;
        case 'm':
            rotacao--;
            break;
        default:
            break;
    }
    desenha();
}

void desenhaLetraC(){
    glBegin(GL_LINE_STRIP);
        glVertex2f(3, 5);
        glVertex2f(2, 5);
        glVertex2f(1, 4);
        glVertex2f(1, 2);
        glVertex2f(2, 1);
        glVertex2f(3, 1);
    glEnd();
}

void desenhaLetraH(){
    glBegin(GL_LINES);
        glVertex2f(5, 1);
        glVertex2f(5, 5);
        glVertex2f(5, 3);
        glVertex2f(7, 3);
        glVertex2f(7, 1);
        glVertex2f(7, 5);
    glEnd();
}

void desenhaLetraR(){
    glBegin(GL_LINE_STRIP);
        glVertex2f(9, 1);
        glVertex2f(9, 5);
        glVertex2f(11, 5);
        glVertex2f(11, 3);
        glVertex2f(9, 3);
        glVertex2f(11, 1);
    glEnd();
}