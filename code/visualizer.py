import matplotlib.pyplot as plt
from matplotlib.patches import Circle

input_str = """
id: 1
-10.000000 -2.384000
10.000000 -2.384000
-10.000000 2.384000
10.000000 2.384000

id: 7
90.036320 -10.000000
109.963680 -10.000000
90.036320 10.000000
109.963680 10.000000

id: 9
-60.000000 76.602540
-40.000000 76.602540
-60.000000 96.602540
-40.000000 96.602540

id: 10
-60.000000 -96.602540
-40.000000 -96.602540
-60.000000 -76.602540
-40.000000 -76.602540
"""




# Split the input text into blocks based on the 'id:' label
point_blocks = input_str.strip().split('id:')[1:]



# Set up Matplotlib figure and axes
plt.figure(figsize=(8, 6))
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Points')




# Draw a circle centered at (0, 0) with a radius of 150
circle = Circle((0, 0), 150, edgecolor='black', facecolor='none')
plt.gca().add_patch(circle)




# Iterate over the point blocks and plot them
for block in point_blocks:
    lines = block.strip().split('\n')
    points = [list(map(float, line.split())) for line in lines[1:]]
    points = [[point[0], point[1]] for point in points]  # We only need X and Y coordinates
    points = list(zip(*points))
    plt.plot(points[0], points[1], marker='o', label=f'ID: {lines[0]}')

plt.legend()
plt.grid(True)
plt.show()
