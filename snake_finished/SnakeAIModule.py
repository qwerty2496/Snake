from SnakeModule import *

class SnakeAI:
    def __init__(self):
        self.population = 500
        self.Gen = 0

        self.best = Snake()
        self.meanFit = 0

        self.GenFitness = list()
        self.Pyramid = list()
        self.GenSnakes = list()
        for i in range(self.population):
            snake = Snake()
            self.GenSnakes.append(snake)
 
    def Roulette(self):
        if self.GenFitness:
            pie = np.array(self.GenFitness)
            a = np.argsort(pie)
            self.best = self.GenSnakes[a[-1]]
            group1 = a[-2:]
            group2 = a[-4:-2]
            group3 = a[-8:-4]
            group4 = a[-12:-8]
            group5 = a[-14:-12]

            self.Pyramid = [group1, group2, group3, group4, group5]
    def Spin(self):
        a = np.random.choice(self.Pyramid, p = [0.45, 0.25, 0.15, 0.1, 0.05])
        return np.random.choice(a, size = 2, replace = False)
    def GenG(self):
        self.Roulette() 
        
        NewGen = list()
        for i in range(self.population):
            a = self.Spin()
            indexF = a[0]
            indexM = a[1]
            
            F = self.GenSnakes[indexF]
            M = self.GenSnakes[indexM]
            offspring = F.crossover(M)
            NewGen.append(offspring)

        self.GenSnakes = NewGen

    def Learn(self, addGen):
        for i in range(addGen):
            self.Gen += 1
            for entity in self.GenSnakes:
                while not entity.dead:
                    entity.update()

                entity.calFitness()
                self.GenFitness.append(entity.fitness)
            self.meanFit = sum(self.GenFitness) / self.population
            self.GenG()
            self.GenFitness.clear()
            self.WriteFile()

    def WriteFile(self):
        brain = self.best.brain.network
        itemlist = np.array(self.best.Item_lst)
        np.transpose(itemlist)

        f0 = open('/content/drive/My Drive/Colab Notebooks/Snake/replay.txt', 'a')
        f0.write(str(self.Gen))
        f0.write("\n")
        f0.close()
        f0 = open('/content/drive/My Drive/Colab Notebooks/Snake/replay.txt', 'ab')
        np.savetxt(f0, (brain[0]), fmt = '%1.3f', delimiter = ' ', newline = "\n", header = 'input')
        np.savetxt(f0, (brain[1]), fmt = '%1.3f', delimiter = ' ', newline = "\n", header = 'hidden')
        np.savetxt(f0, (brain[2]), fmt = '%1.3f', delimiter = ' ', newline = "\n", header = 'output')
        np.savetxt(f0, itemlist, fmt = '%d', delimiter = ' ', newline = '\n', header = "itemlist")
        f0.close()

        f1 = open('/content/drive/My Drive/Colab Notebooks/Snake/latest.txt', 'wb')
        np.savetxt(f1, np.array([self.Gen]), fmt = '%d', newline = '\n', header = 'Gen')
        np.savetxt(f1, (brain[0]), fmt = '%1.3f', delimiter = ' ', newline = "\n", header = 'input')
        np.savetxt(f1, (brain[1]), fmt = '%1.3f', delimiter = ' ', newline = "\n", header = 'hidden')
        np.savetxt(f1, (brain[2]), fmt = '%1.3f', delimiter = ' ', newline = "\n", header = 'output')
        f1.close()
"""     
def LoadFile():
"""
def draw(snake):
    snake.draw()
    glColor3f(0,0,0)
    glBegin(GL_LINES)
    for i in range(2, 41):
        glVertex2f(1, i)
        glVertex2f(41, i)
        glVertex2f(i, 1)
        glVertex2f(i, 41)
    glEnd()

    glColor3f(0.5, 0.5, 0.5)
    glBegin(GL_LINES)
    glVertex2f(1,1)
    glVertex2f(41,1)
    glVertex2f(1,1)
    glVertex2f(1,41)
    glVertex2f(1,41)
    glVertex2f(41,41)
    glVertex2f(41,1)
    glVertex2f(41,41)
    glEnd()
