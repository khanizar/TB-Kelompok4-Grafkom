#include <GL/glut.h>
#include <gl/freeglut.h>

bool hidden = false;
float xrot =0;
float yrot =0;
float xdiff = 0;
float ydiff = 0;
bool mouseDown = false;
float BukaPintu = 0;

void ukur (int lebar,int tinggi){
	if(tinggi==0) tinggi = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90,lebar/tinggi,5,2000);
	glTranslatef(0,0,-300);
	glMatrixMode(GL_MODELVIEW);
}
void hiddenCarte();
void drawCartesius(){
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	//x lines
	glVertex3f(-1000.0, 0.0, 0.0);
	glVertex3f(1000.0, 0.0, 0.0);
	//y lines
	glVertex3f(0.0, -1000.0, 0.0);
	glVertex3f(0.0, 1000.0, 0.0);
	//z line
	glVertex3f(0.0, 0.0, -1000.0);
	glVertex3f(0.0, 0.0, 1000.0);
	glEnd();
}
void hiddenCarte(){
	if (hidden){  
		drawCartesius();
	}
}
void setupLighting() {
    glEnable(GL_LIGHTING); 
    glEnable(GL_LIGHT0);   
    glEnable(GL_COLOR_MATERIAL); 
    
    
    GLfloat lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f }; 
    GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f }; 
    GLfloat lightPosition[] = { 0.0f, 100.0f, 100.0f, 1.0f }; 

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

}
void awan(){
    glPushMatrix();
    glColor3ub(251,251,251);
    glTranslatef(0,220,-100);
    glScalef(2,2,2);
    glutSolidSphere(13,50,50);
    glPopMatrix();
    
    glPushMatrix();
    glColor3ub(251,251,251);
    glTranslatef(0,210,-100);
    glScalef(2,2.5,2);
    glutSolidSphere(12,50,50);
    glPopMatrix();
    
    glPushMatrix();
    glColor3ub(251,251,251);
    glTranslatef(-20,200,-100);
    glScalef(2,2.5,2);
    glutSolidSphere(10,50,50);
    glPopMatrix();
    
    glPushMatrix();
    glColor3ub(251,251,251);
    glTranslatef(20,200,-100);
    glScalef(2,2.5,2);
    glutSolidSphere(10,50,50);
    glPopMatrix();
    // awan kanan
    glPushMatrix();
    glColor3ub(251,251,251);
    glTranslatef(200,220,-100);
    glScalef(2,2,2);
    glutSolidSphere(13,50,50);
    glPopMatrix();
    
    glPushMatrix();
    glColor3ub(251,251,251);
    glTranslatef(200,210,-100);
    glScalef(2,2.5,2);
    glutSolidSphere(12,50,50);
    glPopMatrix();
    
    glPushMatrix();
    glColor3ub(251,251,251);
    glTranslatef(180,200,-100);
    glScalef(2,2.5,2);
    glutSolidSphere(10,50,50);
    glPopMatrix();
    
    glPushMatrix();
    glColor3ub(251,251,251);
    glTranslatef(220,200,-100);
    glScalef(2,2.5,2);
    glutSolidSphere(10,50,50);
    glPopMatrix();
    
    // awan kiri
    glPushMatrix();
    glColor3ub(251,251,251);
    glTranslatef(-200,220,-100);
    glScalef(2,2,2);
    glutSolidSphere(13,50,50);
    glPopMatrix();
    
    glPushMatrix();
    glColor3ub(251,251,251);
    glTranslatef(-200,210,-100);
    glScalef(2,2.5,2);
    glutSolidSphere(12,50,50);
    glPopMatrix();
    
    glPushMatrix();
    glColor3ub(251,251,251);
    glTranslatef(-180,200,-100);
    glScalef(2,2.5,2);
    glutSolidSphere(10,50,50);
    glPopMatrix();
    
    glPushMatrix();
    glColor3ub(251,251,251);
    glTranslatef(-220,200,-100);
    glScalef(2,2.5,2);
    glutSolidSphere(10,50,50);
    glPopMatrix();

}
 void matahari (){
    glPushMatrix();
    glColor3ub(255,235,0);
    glTranslatef(0,300,200);
    glutSolidSphere(30,10,10);
    glPopMatrix();

    setupLighting();
 }
void myinit(void){
	glClearColor(0.0,0.3,1.0,0.7);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glPointSize(10.0);
	glLineWidth(7.0f);
	
}

        void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a': // Tombol 'a' untuk membuka pintu ke depan
            BukaPintu += 1.0;
           
            glutPostRedisplay();
            break;
        case 'd': // Tombol 'd' untuk menutup pintu
            BukaPintu += 1.0;
            glutPostRedisplay();
            break;
        case 'h':
			hidden = !hidden;
			break;
        case 27: // Tombol 'Esc' untuk keluar
            exit(0);
            break;
    }
}

void idle()
{
	if (!mouseDown)
{
	xrot += 0.3;
	yrot += 0.4;
}
	glutPostRedisplay();
}




void mouse(int button, int state,int x,int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
	mouseDown = true;
	xdiff = x - yrot;
	ydiff = -y + xrot;
}
	else
	mouseDown = false;
}


void mouseMotion(int x, int y)
{
	if (mouseDown)
{
	yrot = x - xdiff;
	xrot = y + ydiff;
	glutPostRedisplay();
}
}


void drawInvertedTrapezoidalPrismWithNormals(
    float bottomWidth, float topWidth, float height, float depth,
    float x, float y, float z,
    float r, float g, float b
) {
    glPushMatrix();

    // Set warna
    glColor3ub(r, g, b);

    // Pindahkan ke posisi yang diinginkan
    glTranslatef(x, y, z);

    // Mulai menggambar prisma trapesium
    glBegin(GL_QUADS);

    // Depan
    glNormal3f(0.0f, 0.0f, 1.0f); // Normal menghadap depan
    glVertex3f(-bottomWidth / 2, -height / 2, bottomWidth / 2); // Bawah kiri depan
    glVertex3f(bottomWidth / 2, -height / 2, bottomWidth / 2);  // Bawah kanan depan
    glVertex3f(topWidth / 2, height / 2, topWidth / 2);      // Atas kanan depan
    glVertex3f(-topWidth / 2, height / 2, topWidth / 2);     // Atas kiri depan

    // Belakang
    glNormal3f(0.0f, 0.0f, -1.0f); // Normal menghadap belakang
    glVertex3f(-bottomWidth / 2, -height / 2, -bottomWidth/ 2); // Bawah kiri belakang
    glVertex3f(-topWidth / 2, height / 2, -topWidth / 2);     // Atas kiri belakang
    glVertex3f(topWidth / 2, height / 2, -topWidth / 2);      // Atas kanan belakang
    glVertex3f(bottomWidth / 2, -height / 2, -bottomWidth/ 2);  // Bawah kanan belakang

    // Kanan
    glNormal3f(1.0f, 0.0f, 0.0f); // Normal menghadap kanan
    glVertex3f(bottomWidth / 2, -height / 2, bottomWidth / 2);  // Bawah kanan depan
    glVertex3f(bottomWidth / 2, -height / 2, -bottomWidth / 2); // Bawah kanan belakang
    glVertex3f(topWidth / 2, height / 2, -topWidth / 2);     // Atas kanan belakang
    glVertex3f(topWidth / 2, height / 2, topWidth / 2);      // Atas kanan depan

    // Kiri
    glNormal3f(-1.0f, 0.0f, 0.0f); // Normal menghadap kiri
    glVertex3f(-bottomWidth / 2, -height / 2, bottomWidth / 2);  // Bawah kiri depan
    glVertex3f(-topWidth / 2, height / 2, topWidth / 2);      // Atas kiri depan
    glVertex3f(-topWidth / 2, height / 2, -topWidth / 2);     // Atas kiri belakang
    glVertex3f(-bottomWidth / 2, -height / 2, -bottomWidth / 2); // Bawah kiri belakang

    // Atas
    glNormal3f(0.0f, 1.0f, 0.0f); // Normal menghadap atas
    glVertex3f(-topWidth / 2, height / 2, topWidth / 2);  // Atas kiri depan
    glVertex3f(topWidth / 2, height / 2, topWidth / 2);   // Atas kanan depan
    glVertex3f(topWidth / 2, height / 2, -topWidth / 2);  // Atas kanan belakang
    glVertex3f(-topWidth / 2, height / 2, -topWidth / 2); // Atas kiri belakang

    // Bawah
    glNormal3f(0.0f, -1.0f, 0.0f); // Normal menghadap bawah
    glVertex3f(-bottomWidth / 2, -height / 2, bottomWidth / 2);  // Bawah kiri depan
    glVertex3f(-bottomWidth / 2, -height / 2, -bottomWidth / 2); // Bawah kiri belakang
    glVertex3f(bottomWidth / 2, -height / 2, -bottomWidth / 2);  // Bawah kanan belakang
    glVertex3f(bottomWidth / 2, -height / 2, bottomWidth / 2);   // Bawah kanan depan

    glEnd();

    glPopMatrix();
}

//objek
void tampilan(void){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(0,0,3,0,0,0,0,1,0);
glRotatef(xrot,1,0,0);
glRotatef(yrot,0,1,0);
glPushMatrix();
	
if(!hidden) drawCartesius();

matahari();
awan();

// alas atau tanah
glPushMatrix();
glColor3ub(101, 69, 32);
glScalef(5,0.2,5);
glTranslatef(0,-330,0);
glutSolidCube(60);
glPopMatrix();
//-------------------------------------
//tihang belakang kiri
glPushMatrix();
glColor3ub(181,191,206);
glScalef(0.8,2.5,0.8);
glTranslatef(-135,0,-140);
glutSolidCube(50);
glPopMatrix();
//atap menara belakang kiri

drawInvertedTrapezoidalPrismWithNormals(
    30, 60, 30, 30.0, //ukuran dan bentuk 
    -110, 65,-110, //titik koordinat
    181,191,206 //warna
);
//batas belakang kiri bagian kanan
glPushMatrix();
glScalef(1,1,8);
glColor3ub(215, 211, 191);
glTranslatef(-84,84,-14);
glutSolidCube(7);
glPopMatrix();
//batas belakang kiri bagian kiri
glPushMatrix();
glColor3ub(215, 211, 191);
glScalef(1,1,8);
glTranslatef(-136,84,-14);
glutSolidCube(7);
glPopMatrix();
//batas belakang kiri bagian belakang
glPushMatrix();
glColor3ub(215, 211, 191);
glScalef(8,1,1);
glTranslatef(-14,84,-84);
glutSolidCube(7);
glPopMatrix();
//batas belakang kiri bagian depan
glPushMatrix();
glColor3ub(215, 211, 191);
glScalef(8,1,1);
glTranslatef(-14,84,-136);
glutSolidCube(7);
glPopMatrix();
//anak kotak ujung depan kanan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(84,92,-135);
glutSolidCube(9);
glPopMatrix();
//anak kotak ujung belakang kanan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(84,92,-85);
glutSolidCube(9);
glPopMatrix();
//anak kotak ujung belakang kiri
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(136,92,-85);
glutSolidCube(9);
glPopMatrix();
//anak kotak ujung belakang kiri
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(136,92,-135);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah kiri
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(136,92,-102);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah kiri
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(136,92,-120);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah kanan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(84,92,-102);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah kanan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(84,92,-120);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah depan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(102,92,-135);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah depan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(120,92,-135);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah belakang
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(102,92,-84);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah belakang
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(120,92,-84);
glutSolidCube(9);
glPopMatrix();



//-------------------------------------

//tihang belakang kanan
glPushMatrix();
glColor3ub(181,191,206);
glScalef(0.8,2.5,0.8);
glTranslatef(140,0,-140);
glutSolidCube(50);
glPopMatrix();
//atapmenara belakang kanan
drawInvertedTrapezoidalPrismWithNormals(
    30, 60, 30, 30.0, //ukuran dan bentuk 
    110, 65,-110, //titik koordinat
    181,191,206 //warna
);
//batas depan kanan bagian kanan
glPushMatrix();
glScalef(1,1,8);
glColor3ub(215, 211, 191);
glTranslatef(84,84,-14);
glutSolidCube(7);
glPopMatrix();
//batas depan kanan bagian kiri
glPushMatrix();
glColor3ub(215, 211, 191);
glScalef(1,1,8);
glTranslatef(136,84,-14);
glutSolidCube(7);
glPopMatrix();
//batas depan kanan bagian belakang
glPushMatrix();
glColor3ub(215, 211, 191);
glScalef(8,1,1);
glTranslatef(14,84,-84);
glutSolidCube(7);
glPopMatrix();
//batas depan kanan bagian depan
glPushMatrix();
glColor3ub(215, 211, 191);
glScalef(8,1,1);
glTranslatef(14,84,-136);
glutSolidCube(7);
glPopMatrix();
//anak kotak ujung depan kanan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(84,92,135);
glutSolidCube(9);
glPopMatrix();
//anak kotak ujung belakang kanan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(84,92,85);
glutSolidCube(9);
glPopMatrix();
//anak kotak ujung belakang kiri
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(136,92,85);
glutSolidCube(9);
glPopMatrix();
//anak kotak ujung belakang kiri
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(136,92,135);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah kiri
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(136,92,102);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah kiri
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(136,92,120);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah kanan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(84,92,102);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah kanan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(84,92,120);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah depan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(102,92,135);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah depan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(120,92,135);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah belakang
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(102,92,84);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah belakang
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(120,92,84);
glutSolidCube(9);
glPopMatrix();

//-------------------------------------
//tempat raja/KING


// tembok atas
glPushMatrix();
glColor3ub(181,191,206);
glScalef(3,0.2,2);
glTranslatef(0,288,-34);
glutSolidCube(50);
glPopMatrix();
//tembok Belakang
glPushMatrix();
glColor3ub(181,191,206);
glScalef(3,2,0.4);
glTranslatef(0,7,-288);
glutSolidCube(50);
glPopMatrix();
//tiang bagian kiri
glPushMatrix();
glColor3ub(76, 88, 91);
glScalef(0.4,2.2,0.4);
glTranslatef(-170,0,-50);
glutSolidCube(50);
glPopMatrix();
//tiang bagian kanan
glPushMatrix();
glColor3ub(76, 88, 91);
glScalef(0.4,2.2,0.4);
glTranslatef(170,0,-50);
glutSolidCube(50);
glPopMatrix();
//tiang atasnya
glPushMatrix();
glColor3ub(76, 88, 91);
glScalef(2.5,0.3,0.4);
glTranslatef(0,165,-65);
glutSolidCube(50);
glPopMatrix();
//tembok kiri
glPushMatrix();
glColor3ub(244, 237, 211);
glScalef(0.2,2.5,2);
glTranslatef(-340,-2,-35);
glutSolidCube(50);
glPopMatrix();
//tembok kanan
glPushMatrix();
glColor3ub(244, 237, 211);
glScalef(0.2,2.5,2);
glTranslatef(340,-2,-35);
glutSolidCube(50);
glPopMatrix();
//tembok depan
glPushMatrix();
glColor3ub(76, 88, 91);
glScalef(2.5,2,0.2);
glTranslatef(0,-4,-160);
glutSolidCube(50);
glPopMatrix();
//pintu
glPushMatrix();
glColor3ub(139, 69, 19);
glScalef(1.5,2,0.2);
glTranslatef(0,-18,-103);
glutSolidCube(30);
glPopMatrix();
// motif pintu bulat
glPushMatrix();
glColor3ub(139, 69, 19); 
glScalef(1.8, 2, 0.3);   
glTranslatef(0, -7, -80);
glutSolidCylinder(12, 5, 50, 50); 
glPopMatrix();
// motif pintu bulat kecil
glPushMatrix();
glColor3ub(126, 153, 163); 
glScalef(1.8, 2, 0.3);   
glTranslatef(7, -12, -63);
glutSolidCylinder(2.8, 5, 50, 50); 
glPopMatrix();
//motip tembok kotak tengah
glPushMatrix();
glColor3ub(244, 237, 211);
glScalef(1.8,2,0.3);
glTranslatef(0,15,-90);
glutSolidCube(11);
glPopMatrix();
//motip pintu kotak kiri
glPushMatrix();
glColor3ub(244, 237, 211);
glScalef(1.8,2,0.3);
glTranslatef(-18,15,-90);
glutSolidCube(11);
glPopMatrix();
//motip pintu kotak kanan
glPushMatrix();
glColor3ub(244, 237, 211);
glScalef(1.8,2,0.3);
glTranslatef(18,15,-90);
glutSolidCube(11);
glPopMatrix();

//-------------------------------------


//tihang depan kiri
glPushMatrix();
glColor3ub(181,191,206);
glScalef(0.8,2.5,0.8);
glTranslatef(-140,0,140);
glutSolidCube(50);
glPopMatrix();
//atap depan kiri
drawInvertedTrapezoidalPrismWithNormals(
    30, 60, 30, 30.0, //ukuran dan bentuk 
    -110, 65,111, //titik koordinat
    181,191,206 //warna
);
//batas depan kiri bagian kanan
glPushMatrix();
glScalef(1,1,8);
glColor3ub(215, 211, 191);
glTranslatef(-84,84,14);
glutSolidCube(7);
glPopMatrix();
//batas depan kiri bagian kiri
glPushMatrix();
glColor3ub(215, 211, 191);
glScalef(1,1,8);
glTranslatef(-136,84,14);
glutSolidCube(7);
glPopMatrix();
//batas depan kiri bagian belakang
glPushMatrix();
glColor3ub(215, 211, 191);
glScalef(8,1,1);
glTranslatef(-14,84,84);
glutSolidCube(7);
glPopMatrix();
//batas depan kiri bagian depan
glPushMatrix();
glColor3ub(215, 211, 191);
glScalef(8,1,1);
glTranslatef(-14,84,136);
glutSolidCube(7);
glPopMatrix();
//anak kotak ujung depan kanan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-84,92,135);
glutSolidCube(9);
glPopMatrix();
//anak kotak ujung belakang kanan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-84,92,85);
glutSolidCube(9);
glPopMatrix();
//anak kotak ujung belakang kiri
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-136,92,85);
glutSolidCube(9);
glPopMatrix();
//anak kotak ujung belakang kiri
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-136,92,135);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah kiri
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-136,92,102);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah kiri
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-136,92,120);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah kanan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-84,92,102);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah kanan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-84,92,120);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah depan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-102,92,135);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah depan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-120,92,135);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah belakang
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-102,92,84);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah belakang
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-120,92,84);
glutSolidCube(9);
glPopMatrix();

//-------------------------------------

//tihang depan kanan
glPushMatrix();
glColor3ub(181,191,206);
glScalef(0.8,2.5,0.8);
glTranslatef(140,0,140);
glutSolidCube(50);
glPopMatrix();
drawInvertedTrapezoidalPrismWithNormals(
    30, 60, 30, 30.0, //ukuran dan bentuk 
    110, 65,111, //titik koordinat
    181,191,206 //warna
);
//batas depan kanan bagian kanan
glPushMatrix();
glScalef(1,1,8);
glColor3ub(215, 211, 191);
glTranslatef(84,84,14);
glutSolidCube(7);
glPopMatrix();
//batas depan kanan bagian kiri
glPushMatrix();
glColor3ub(215, 211, 191);
glScalef(1,1,8);
glTranslatef(136,84,14);
glutSolidCube(7);
glPopMatrix();
//batas depan kanan bagian belakang
glPushMatrix();
glColor3ub(215, 211, 191);
glScalef(8,1,1);
glTranslatef(14,84,84);
glutSolidCube(7);
glPopMatrix();
//batas depan kanan bagian depan
glPushMatrix();
glColor3ub(215, 211, 191);
glScalef(8,1,1);
glTranslatef(14,84,136);
glutSolidCube(7);
glPopMatrix();
//anak kotak ujung depan kanan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-84,92,-135);
glutSolidCube(9);
glPopMatrix();
//anak kotak ujung belakang kanan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-84,92,-85);
glutSolidCube(9);
glPopMatrix();
//anak kotak ujung belakang kiri
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-136,92,-85);
glutSolidCube(9);
glPopMatrix();
//anak kotak ujung belakang kiri
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-136,92,-135);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah kiri
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-136,92,-102);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah kiri
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-136,92,-120);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah kanan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-84,92,-102);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah kanan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-84,92,-120);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah depan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-102,92,-135);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah depan
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-120,92,-135);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah belakang
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-102,92,-84);
glutSolidCube(9);
glPopMatrix();
//anak kotak Tengah belakang
glPushMatrix();
glColor3ub(181,191,206);
glTranslatef(-120,92,-84);
glutSolidCube(9);
glPopMatrix();

//tembok kiri
glPushMatrix();
glColor3ub(181,191,206);
glScalef(0.4,2,5);
glTranslatef(-280,-10,0);
glutSolidCube(50);
glPopMatrix();

//tembok kanan
glPushMatrix();
glColor3ub(181,191,206);
glScalef(0.4,2,5);
glTranslatef(280,-10,0);
glutSolidCube(50);
glPopMatrix();

//tembok Belakang
glPushMatrix();
glColor3ub(181,191,206);
glScalef(5,2,0.4);
glTranslatef(0,-10,-280);
glutSolidCube(50);
glPopMatrix();
//tembok depan kanan buat pintu
glPushMatrix();
glColor3ub(181,191,206);
glScalef(1.5,2,0.4);
glTranslatef(-55,-7,280);
glutSolidCube(50);
glPopMatrix();
//tembok depan kanan buat pintu
glPushMatrix();
glColor3ub(181,191,206);
glScalef(1.5,2,0.4);
glTranslatef(55,-7,280);
glutSolidCube(50);
glPopMatrix();
//tembok depan atas buat pintu
glPushMatrix();
glColor3ub(181,191,206);
glScalef(2.5,0.3,0.4);
glTranslatef(0,120,280);
glutSolidCube(50);
glPopMatrix();
//pintunya
glPushMatrix();
glColor3ub(139, 69, 19);
glRotatef(BukaPintu, 1.0, 0.0,0.0 );
glScalef(1.8,2,0.2);
glTranslatef(0,-7,530);
glutSolidCube(50);
glPopMatrix();
//motip pintu
//motip pintu kotak
glPushMatrix();
glColor3ub(76, 88, 91);
glRotatef(BukaPintu, 1.0, 0.0,0.0 );
glScalef(1.8,2,0.3);
glTranslatef(7,-7,370);
glutSolidCube(6);
glPopMatrix();
// motif pintu bulat
glPushMatrix();
glColor3ub(126, 153, 163); 
glRotatef(BukaPintu, 1.0, 0.0,0.0 );
glScalef(1.8, 2, 0.3);   
glTranslatef(7, -7, 370);
glutSolidCylinder(3, 5, 50, 50); 
glPopMatrix();
//motip pintu kotak
glPushMatrix();
glColor3ub(76, 88, 91);
glRotatef(BukaPintu, 1.0, 0.0,0.0 );
glScalef(1.8,2,0.3);
glTranslatef(-7,-7,370);
glutSolidCube(6);
glPopMatrix();
// motif pintu bulat
glPushMatrix();
glColor3ub(126, 153, 163); 
glRotatef(BukaPintu, 1.0, 0.0,0.0 );
glScalef(1.8, 2, 0.3);   
glTranslatef(-7, -7, 370);
glutSolidCylinder(3, 5, 50, 50); 
glPopMatrix();








glPushMatrix();
glPopMatrix();
glutSwapBuffers();
glutPostRedisplay();
}

int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowPosition(240,80);
glutInitWindowSize(750,600);
glutCreateWindow("KASTIL Kelompok 4");
myinit();
glutDisplayFunc(tampilan);
glutMouseFunc(mouse);
glutMotionFunc(mouseMotion);
 glutKeyboardFunc(keyboard);
glutReshapeFunc(ukur);
glutMainLoop();

}