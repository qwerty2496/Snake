import numpy as np

class Neuron:
    def __init__(self):
        self.node_i = 24
        self.node_h = 18
        self.node_o = 4

        self.network = list()
        self.network.append(np.random.uniform(-1, 1, size = (self.node_i, self.node_h)))
        self.network.append(np.random.uniform(-1, 1, size = (self.node_h, self.node_h)))
        self.network.append(np.random.uniform(-1, 1, size = (self.node_h, self.node_o)))

    def output(self, inputlayer):
        a = np.dot(inputlayer, self.network[0])
        z1 = ReLu(a)
        b = np.dot(z1, self.network[1])
        z2 = ReLu(b)
        c = np.dot(z2, self.network[2])
                
        indices = np.argsort(c)
        output = indices[3]

        return output

    def crossover(self, partner):
        child = Neuron()
        for i in range(3):
            child.network[i] = np.array(partner.network[i])
            row = self.network[i].shape[0]
            col = self.network[i].shape[1]

            div_row = np.random.randint(row)
            div_col = np.random.randint(col)

            for j in range(row):
                for k in range(col):
                    if((j < div_row) or ((j == div_row) and (k <= div_col))):
                        child.network[i][j][k] = partner.network[i][j][k]
        
        return child
        
    def mutate(self, rate):
        for i in range(3):
            row = self.network[i].shape[0]
            col = self.network[i].shape[1]
            for j in range(row):
                for k in range(col):
                    std = np.random.random()
                    if std < rate:
                       self.network[i][j][k] = np.random.uniform(-1, 1)


def ReLu(x):
    return np.maximum(0, x)