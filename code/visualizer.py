import matplotlib.pyplot as plt
from matplotlib.patches import Circle


with open('out', 'r') as file:
    input_str = file.read()



# Split the input text into blocks based on the 'id:' label
point_blocks = input_str.strip().split('id:')[1:]



# Set up Matplotlib figure and axes
plt.figure(figsize=(8, 6))
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Points')




# Draw a circle centered at (0, 0) with a radius of 150
circle = Circle((0, 0), 150, edgecolor='black', facecolor='white')
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
