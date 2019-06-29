import networkx as nx
import matplotlib.pyplot as plt
#Closeness Centrality
G=nx.Graph()
nodes = nx.read_adjlist("nodes.txt")
G.add_nodes_from(nodes.nodes())
G = nx.read_edgelist("edges.txt", create_using =nx.MultiGraph(), nodetype = int,data=[('weight',int)])
d = dict(nx.closeness_centrality(G))
nx.draw(G, nodelist=d.keys(), node_size=[v * 5000 for v in d.values()],with_labels=True)
plt.show()
