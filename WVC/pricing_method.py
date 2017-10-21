
class Node:
    def __init__(self, nome, peso, vizinhos = []):
        self.nome = nome
        self.peso = peso
        self.vizinhos = vizinhos

    def __eq__(self, other):
        return self.nome == other.nome

class Edge:
    def __init__(self, nome, tight, x1, x2):
        self.nome = nome
        self.tight = tight
        self.x1 = x1
        self.x2 = x2
    
    def __eq__(self, other):
        return self.nome == other.nome

class Graph:
    def __init__(self):
        self.edges = []
        self.nodes = []

    def addEgdes(self, edges):
        for e in edges:
            if e not in self.edges:
                self.edges.append(e)
                if e.x1 not in self.nodes:
                    self.nodes.append(e.x1)
                if e.x2 not in self.nodes:
                    self.nodes.append(e.x2)
"""

def wcc(g):
    nodes, edges = g
    tiges = []
    for e in edges:
        x1, x2 = e
        if (x1 not in tiges and x2 not in tiges):

            tiges.append(x1)

"""
# a = Node(1,5,[])