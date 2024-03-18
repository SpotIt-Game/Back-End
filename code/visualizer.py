import matplotlib.pyplot as plt
from matplotlib.patches import Circle

input_str = """
id: 5
38.762978 -36.193003
36.193003 38.762978
-36.193003 -38.762978
-38.762978 36.193003

id: 2
128.858448 -17.190466
102.635342 31.553576
102.160007 -31.553576
75.936901 17.190466

id: 15
29.832917 120.912927
-22.752313 127.993531
22.752313 68.327696
-29.832917 75.408301

id: 17
-106.292070 -34.509658
-60.489283 -11.293130
-129.508598 11.293130
-83.705811 34.509658

id: 1
-31.996622 -125.245409
31.804945 -126.049424
-31.804945 -110.035116
31.996622 -110.839130
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
