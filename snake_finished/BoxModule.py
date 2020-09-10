from OpenGL.GL import*
from OpenGL.GLUT import*
from OpenGL.GLU import*

WHITE = 4
RED = 5
GREEN = 6

class Box:
    def __init__(self, x = 0 , y = 0):
        self.pos = [x, y]
        self.color = WHITE
        

    def drawBox(self):
        if self.color == WHITE :
            glColor3f(1,1,1)
        elif self.color == RED:
            glColor3f(1,0,0)
        else:
            glColor3f(0,1,0)

        glBegin(GL_QUADS)
        glVertex2f(self.pos[0], self.pos[1])
        glVertex2f(self.pos[0], self.pos[1] + 1)
        glVertex2f(self.pos[0] + 1, self.pos[1] + 1)
        glVertex2f(self.pos[0] + 1,self.pos[1])
        glEnd()
        
    def setColor(self, col):
        self.color = col

    def setPos(self, x , y):
        self.pos[0] = x
        self.pos[1] = y

        
