from BoxModule import *
from NeuronModule import *
from copy import copy
import random

direction= {"up":0,"right":1,"down":2,"left":3}

class Snake(Box):
    def __init__(self):
        self.brain = Neuron()
        self.body = [Box(20, 20), Box(20, 19), Box(20, 18)]
        self._dir_= direction["up"]
        self.vision = np.zeros(24)

        self.dead = False
        self.replay = False

        self.life = 200
        self.step = 0

        self.fitness = 0
        self.mut_rate = 0.05

        self.Item = Box()
        self.Item.setColor(RED)
        self.Item_lst = list()
        self.genItem()
    
    def snakewash(self,network, itemlist):
      self.brain = network
      self.Item_lst = itemlist
  

        

        
   

    def genItem(self):
        while True:
            a = 0
            x = random.randrange(1,41)
            y = random.randrange(1,41)

            for j in self.body:
                if (j.pos[0] == x) and (j.pos[1] == y):
                    a = 1
                    break

            if a == 0:
                break

        self.Item.setPos(x, y)
        self.Item_lst.append(copy(self.Item.pos))
        
    def wallCol(self, hx, hy):
        if (hx == 0 or hx == 41 or hy == 0 or hy == 41):
            return True
        return False
    def bodyCol(self, hx, hy):
        for j in self.body[1:]:
            if (hx == j.pos[0]) and (hy == j.pos[1]):
                return True
            return False
    def itemCol(self, hx, hy):
        if (hx == self.Item.pos[0]) and (hy == self.Item.pos[1]):
            return True
        return False

    def look_dir(self, x, y):
        found_i = False
        found_b = False
        hx = self.body[0].pos[0] + x
        hy = self.body[0].pos[1] + y
        ix = self.Item.pos[0]
        iy = self.Item.pos[1]

        dw, di, db = 0, 0, 0
        dis_w, dis_i, dis_b = 1, 1, 1
        while (not self.wallCol(hx, hy)):
            if not found_i:
                if (self.itemCol(hx, hy)):
                    found_i = True
                    di = 1

            if not found_b:
                if (self.bodyCol(hx, hy)):
                    found_b = True
                    db = 1/dis_b
                else:
                    dis_b += 1
            
            hx += x
            hy += y
            dis_w += 1
        
        dw = 1/dis_w

        return dw, di, db
    def look(self):
        d0, d1, d2 = self.look_dir(0, 1)
        self.vision[0] = d0
        self.vision[1] = d1
        self.vision[2] = d2
        d0, d1, d2 = self.look_dir(1, 1)
        self.vision[3] = d0
        self.vision[4] = d1
        self.vision[5] = d2
        d0, d1, d2 = self.look_dir(1, 0)
        self.vision[6] = d0
        self.vision[7] = d1
        self.vision[8] = d2
        d0, d1, d2 = self.look_dir(1, -1)
        self.vision[9] = d0
        self.vision[10] = d1
        self.vision[11] = d2
        d0, d1, d2 = self.look_dir(0, -1)
        self.vision[12] = d0
        self.vision[13] = d1
        self.vision[14] = d2
        d0, d1, d2 = self.look_dir(-1, -1)
        self.vision[15] = d0
        self.vision[16] = d1
        self.vision[17] = d2
        d0, d1, d2 = self.look_dir(-1, 0)
        self.vision[18] = d0
        self.vision[19] = d1
        self.vision[20] = d2
        d0, d1, d2 = self.look_dir(-1, 1)
        self.vision[21] = d0
        self.vision[22] = d1
        self.vision[23] = d2
    def think(self):
        decision = self.brain.output(self.vision)

        if decision == direction["up"]:
            if self._dir_ != direction["down"]:
                self._dir_ = direction["up"]
        elif decision == direction["down"]:
            if self._dir_ != direction["up"]:
                self._dir_ = direction["down"]
        elif decision == direction["left"]:
            if self._dir_ != direction["right"]:
                self._dir_ = direction["left"]
        else:
            if self._dir_ != direction["left"]:
               self._dir_ = direction["right"]
               
    def move(self):
        tempPosX=self.body[0].pos[0]
        tempPosY=self.body[0].pos[1]

        self.body[0].setColor(WHITE)
        if(self._dir_ == direction["up"]):
            tmp = Box(tempPosX,tempPosY+1)
            self.body.insert(0, tmp)
        elif(self._dir_ == direction["down"]):
            tmp = Box(tempPosX,tempPosY-1)
            self.body.insert(0, tmp)
        elif(self._dir_ == direction["left"]):
            tmp = Box(tempPosX-1,tempPosY)
            self.body.insert(0, tmp)
        else:
            tmp = Box(tempPosX+1,tempPosY)
            self.body.insert(0, tmp)
        self.body[0].setColor(GREEN)
        self.body.pop()
        
        self.life -= 1
        self.step += 1
        
    def eat(self):
        if self.life <= 400:
            self.life += 100
        else:
            self.life = 500

        self.genItem()

    def die(self):
        hx = self.body[0].pos[0]
        hy = self.body[0].pos[1]

        if(self.wallCol(hx, hy) or self.bodyCol(hx, hy) or self.life == 0):
            self.dead = True
        else:
            self.dead = False

    def update(self):
        hx = self.body[0].pos[0]
        hy = self.body[0].pos[1]
        if self.itemCol(hx, hy):
            self.eat()
            tail = Box(self.body[-1].pos[0], self.body[-1].pos[1])
            self.look()
            self.think()
            self.move()
            self.body.append(tail)
        else:
            self.look()
            self.think()
            self.move()

        self.die()

    def crossover(self, partner):
        child = Snake()
        child.brain = self.brain.crossover(partner.brain)
        child.brain.mutate(self.mut_rate)

        return child

    def calFitness(self):
        self.fitness = len(self.body) - 3

    def draw(self):
        self.Item.drawBox();
        for body in self.body:
            body.drawBox();