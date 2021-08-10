#include <GL/glut.h>
#include <GL/glut.h>

// ��������
float latAngle = 0.0; // ����
float longAngle = 0.0; // �浵
float Xangle = 0.0, Yangle = 25.0, Zangle = -5.0; // x, y, z�� ����
int isAnimate = 0; // �ִϸ��̼� ����
int animationPeriod = 100; // =�ִϸ��̼� �ӵ�
// ��
float armsan = 0;
float armsan2 = 0;
int sarmsan = 0;
int sarmsan2 = 0;
// �ٸ�
float legsan = 0;
float legsan2 = 0;
int slegsan = 0;
int slegsan2 = 0;
// ��,�ٸ��� ��,�� �κ� �����̴� ����
int Aangle = 0; // ��,�ٸ� �� �κ�
int Langle = 0; // ��,�ٸ� �� �κ�

void MyLightInit() {
	GLfloat light0_ambient[] = { 0.5, 0.4, 0.3, 1.0 };  //0�� ���� Ư�� 
	GLfloat light0_diffuse[] = { 0.8, 0.7, 0.6, 1.0 };
	GLfloat light0_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat light1_ambient[] = { 0.3, 0.4, 0.5, 1.0 };  //1�� ���� Ư�� 
	GLfloat light1_diffuse[] = { 0.7, 0.6, 0.8, 1.0 };
	GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat material_ambient[] = { 0.4, 0.4, 0.4, 1.0 }; //��ü Ư��
	GLfloat material_diffuse[] = { 0.9, 0.9, 0.9, 1.0 };
	GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat material_shininess[] = { 25.0 };


	glShadeModel(GL_SMOOTH); //���� ���̵�  
	glEnable(GL_DEPTH_TEST); //���� ���� Ȱ��ȭ
	glEnable(GL_LIGHTING);  //���� Ȱ��ȭ

	// ����0 Ȱ��ȭ
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
	// ����1 Ȱ��ȭ
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light0_specular);
}
// Draw
void drawScene(void)
{
	GLfloat LightPosition0[] = { 1.5, 0.0, 0,0, 1.0 };	//0�� ������ġ
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition0);	//��ġ�� ����
	GLfloat LightPosition1[] = { 0,0, 1.5, 0.0, 1.0 };	//1�� ������ġ
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);	//��ġ�� ����
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 20.0, -50.0);
	// Rotate scene.
	glRotatef(Zangle, 0.0, 0.0, 1.0);
	glRotatef(Yangle, 0.0, 1.0, 0.0);
	glRotatef(Xangle, 1.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);

	glutSolidSphere(5, 10, 10);//�Ӹ�
	glColor3f(0, 1, 0);

	glPushMatrix();//����
	glTranslatef(0, -15, 0);
	glScalef(1, 2, 1);
	glutSolidCube(10);
	glPopMatrix();

	// ������
	glPushMatrix();
	glTranslatef(7, -7, 0);
	glColor3f(1, 0, 1);
	glutSolidSphere(2, 10, 10); // ���
	glRotatef(-60, 0, 0, 1);
	glRotatef(armsan, 0, 1, 0);
	glColor3f(0, 0, 0);
	glTranslatef(5.75, 0, 0);
	glPushMatrix();
	glScalef(1.5, 0.5, 1);
	glutSolidCube(5); // ���
	glPopMatrix();
	glColor3f(1, 0, 1);
	glTranslatef(5.75, 0, 0);
	glutSolidSphere(2, 10, 10); // �Ȳ�ġ
	glRotatef(-60, 0, 1, 0);
	glRotatef(armsan2, 0, 1, 0);
	glColor3f(0, 0, 0);
	glTranslatef(5.75, 0, 0);
	glPushMatrix();
	glScalef(1.5, 0.5, 1);
	glutSolidCube(5); // �ϴ�
	glPopMatrix();
	glPopMatrix();

	// ����
	glPushMatrix();
	glColor3f(1, 0, 1);
	glTranslatef(-7, -7, 0);
	glutSolidSphere(2, 10, 10); // ���
	glRotatef(60, 0, 0, 1);
	glRotatef(armsan, 0, 1, 0);
	glColor3f(0, 0, 0);
	glTranslatef(-5.75, 0, 0);
	glPushMatrix();
	glScalef(1.5, 0.5, 1);
	glutSolidCube(5); // ���
	glPopMatrix();
	glColor3f(1, 0, 1);
	glTranslatef(-5.75, 0, 0);
	glutSolidSphere(2, 10, 10); // �Ȳ�ġ
	glRotatef(60, 0, 1, 0);
	glRotatef(armsan2, 0, 1, 0);
	glColor3f(0, 0, 0);
	glTranslatef(-5.75, 0, 0);
	glPushMatrix();
	glScalef(1.5, 0.5, 1);
	glutSolidCube(5); // �ϴ�
	glPopMatrix();
	glPopMatrix();

	// �����ٸ�
	glPushMatrix();
	glColor3f(1, 0, 1);
	glTranslatef(2.5, -27, 0);
	glutSolidSphere(2, 10, 10); // ���
	glRotatef(10, 0, 0, 1);
	glRotatef(-20, 1, 0, 0);
	glRotated(legsan, -1, 0, 0);
	glColor3f(0, 0, 0);
	glTranslatef(0, -5.75, 0);
	glPushMatrix();
	glScalef(0.5, 1.5, 1);
	glutSolidCube(5); // �����
	glPopMatrix();
	glColor3f(1, 0, 1);
	glTranslatef(0, -5.75, 0);
	glutSolidSphere(2, 10, 10); // ����
	glRotatef(20, 1, 0, 0);
	glRotatef(legsan2, 1, 0, 0);
	glColor3f(0, 0, 0);
	glTranslatef(0, -5.75, 0);
	glPushMatrix();
	glScalef(0.5, 1.5, 1);
	glutSolidCube(5); // ���Ƹ�
	glPopMatrix();
	glPopMatrix();

	//���� �ٸ�
	glPushMatrix();
	glColor3f(1, 0, 1);
	glTranslatef(-2.5, -27, 0);
	glutSolidSphere(2, 10, 10); // ���
	glRotatef(-10, 0, 0, 1);
	glRotatef(-20, 1, 0, 0);
	glRotated(legsan, 1, 0, 0);
	glColor3f(0, 0, 0);
	glTranslatef(0, -5.75, 0);
	glPushMatrix();
	glScalef(0.5, 1.5, 1);
	glutSolidCube(5); // �����
	glPopMatrix();
	glColor3f(1, 0, 1);
	glTranslatef(0, -5.75, 0);
	glutSolidSphere(2, 10, 10); // ����
	glRotatef(20, 1, 0, 0);
	glRotatef(legsan2, 1, 0, 0);
	glColor3f(0, 0, 0);
	glTranslatef(0, -5.75, 0);
	glPushMatrix();
	glScalef(0.5, 1.5, 1);
	glutSolidCube(5); // ���Ƹ�
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}

// �ȴٸ� �ִϸ��̼�
void animate(int value)
{
	if (sarmsan == 0) armsan += 1;
	else armsan -= 1;

	if (animationPeriod == 2) { // �޸��� ������ �� �� �ٸ� ����
		Aangle = 60;
		Langle = 30;
	}
	else { // �ȱ� ������ �� �� �ٸ� ����
		Aangle = 30;
		Langle = 10;
	}

	if (armsan >= Aangle) sarmsan = 1;
	else if (armsan <= (-1) * Aangle) sarmsan = 0;
	if (sarmsan2 == 0) armsan2 += 0.2;
	else armsan2 -= 0.2;
	if (armsan2 >= Langle) sarmsan2 = 1;
	else if (armsan2 <= -10) sarmsan2 = 0;

	if (slegsan == 0) legsan += 1;
	else legsan -= 1;
	if (legsan >= Aangle) slegsan = 1;
	else if (legsan <= (-1) * Aangle) slegsan = 0;
	if (slegsan2 == 0) legsan2 += 1;
	else legsan2 -= 1;
	if (legsan2 >= Langle) slegsan2 = 1;
	else if (legsan2 <= -10) slegsan2 = 0;
	glutTimerFunc(animationPeriod, animate, 1);
	glutPostRedisplay();
}

// �ִϸ��̼� �ʱ�ȭ
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);
}

// window ����� �޼ҵ�
void resize(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

// Ű���� �̺�Ʈ
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
		// x�� �̵�
	case 'x':
		Xangle += 5.0;
		if (Xangle > 360.0) Xangle -= 360.0;
		glutPostRedisplay();
		break;
	case 'X':
		Xangle -= 5.0;
		if (Xangle < 0.0) Xangle += 360.0;
		glutPostRedisplay();
		break;
		// y�� �̵�
	case 'y':
		Yangle += 5.0;
		if (Yangle > 360.0) Yangle -= 360.0;
		glutPostRedisplay();
		break;
	case 'Y':
		Yangle -= 5.0;
		if (Yangle < 0.0) Yangle += 360.0;
		glutPostRedisplay();
		break;
		// z�� �̵�
	case 'z':
		Zangle += 5.0;
		if (Zangle > 360.0) Zangle -= 360.0;
		glutPostRedisplay();
		break;
	case 'Z':
		Zangle -= 5.0;
		if (Zangle < 0.0) Zangle += 360.0;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

// ���� ��ư : �ٱ� , ������ ��ư : �ȱ�
void mouseInput(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) {
		Aangle = 60;
		Langle = 30;
		animationPeriod = 2; // �޸���
	}
	if (button == GLUT_RIGHT_BUTTON) {
		Aangle = 30;
		Langle = 10;
		animationPeriod = 10; // �ȱ�
	}
	glutPostRedisplay();
}

// ���� �Լ�
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // �ִϸ��̼� = ��������
	glutInitWindowSize(500, 500); // ������ ������
	glutInitWindowPosition(100, 100); // ������ ��ġ
	glutCreateWindow("�ȱ�/�޸���"); // ����
	setup(); // �ʱ�ȭ
	MyLightInit();
	glutDisplayFunc(drawScene); // ��� �׸���
	glutReshapeFunc(resize); // reshape �����Լ� resize()
	glutKeyboardFunc(keyInput); //  �̺�Ʈ ó�� �Լ� 
	glutMouseFunc(mouseInput); // �̺�Ʈó�� �Լ�
	glutTimerFunc(5, animate, 0); // �ִϸ��̼�
	glutMainLoop(); // ���� ����
	return 0;
}
