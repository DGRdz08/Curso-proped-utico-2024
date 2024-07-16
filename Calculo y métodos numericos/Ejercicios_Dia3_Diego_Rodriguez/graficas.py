import matplotlib.pyplot as plt

coordinates = [
    (0.5, -0.072023),
    (1.0, -0.250789),
    (1.5, -0.202480),
    (2.0, 0.027158),
    (2.5, 0.229590),
    (3.0, 0.223537),
    (3.5, 0.016803),
    (4.0, -0.202574),
    (4.5, -0.237366),
    (5.0, -0.058620),
    (5.5, 0.170759),
    (6.0, 0.243885),
    (6.5, 0.097179),
    (7.0, -0.135256),
    (7.5, -0.243219),
    (8.0, -0.131510),
    (8.5, 0.097231),
    (9.0, 0.235692),
    (9.5, 0.160814),
    (10.0, -0.057872)
]


x, y = zip(*coordinates)

plt.figure(figsize=(10, 5))
plt.plot(x, y, marker='o', linestyle='-', color='b')

plt.title('Coordenadas (x,y1)')
plt.xlabel('x')
plt.ylabel('y')
plt.grid(True)

plt.show()
