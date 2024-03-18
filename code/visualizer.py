import matplotlib.pyplot as plt
from matplotlib.patches import Circle

input_str = """
id: 15
-63.965568 -46.508228
46.508228 -63.965568
-46.508228 63.965568
63.965568 46.508228

id: 2
138.363329 -21.344534
114.952758 34.167142
107.958070 -34.167142
84.547499 21.344534

id: 5
-43.076477 133.047367
-93.611434 104.100429
-14.129540 82.512411
-64.664496 53.565473

id: 1
-66.253159 -123.330933
-31.953447 -74.930500
-77.791822 -115.153881
-43.492110 -66.753449
"""




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
