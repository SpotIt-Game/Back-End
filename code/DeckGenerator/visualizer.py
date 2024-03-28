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
    

deck=[
'''
id: 116
-30.195161 13.295792
-12.869067 -71.582265
26.390211 24.846521
43.716304 -60.031536

id: 93
91.798978 48.479685
65.742521 75.151997
65.126666 22.423227
39.070208 49.095539

id: 74
148.862223 90.089059
95.269665 145.454785
117.290032 59.528013
63.697474 114.893739

id: 146
37.452609 107.233785
38.759177 168.708201
-37.039262 108.817024
-35.732693 170.291440

id: 140
-143.540497 98.346967
-109.152761 34.454299
-79.647829 132.734702
-45.260093 68.842035

id: 84
-58.712736 19.106807
-104.640921 8.728361
-50.928902 -15.339332
-96.857086 -25.717778

id: 144
-50.121866 -102.109946
-107.561812 -49.411980
-89.821000 -145.381372
-147.260946 -92.683406

id: 132
51.437500 -86.901973
-22.636580 -99.644385
64.179912 -160.976054
-9.894168 -173.718466

id: 111
171.899670 -13.240280
95.798300 9.347402
149.311988 -89.341649
73.210618 -66.753967
'''
]
for card in deck: show_graph(card)
