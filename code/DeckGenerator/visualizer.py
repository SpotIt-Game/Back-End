import matplotlib.pyplot as plt
from matplotlib.patches import Circle


def show_graph(input_str):
    plt.figure(figsize=(8, 6))
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.title('Points')

    circle = Circle((0, 0), 200, edgecolor='black', facecolor='white')
    plt.gca().add_patch(circle)

    point_blocks = input_str.strip().split('id:')[1:]

    for block in point_blocks:
        lines = block.strip().split('\n')
        points = [list(map(float, line.split())) for line in lines[1:]]
        points = [[point[0], point[1]] for point in points]  # We only need X and Y coordinates
        points = list(zip(*points))
        plt.plot(points[0], points[1], marker='o', label=f'ID: {lines[0]}')

    plt.legend()
    plt.grid(True)
    plt.show(block=False) 

    plt.pause(5)
    plt.close()


#decks=[[],[],[]]

#for deck in decks:
#    for card in deck: show_graph(card)
    

deck=[]
for card in deck: show_graph(card)
