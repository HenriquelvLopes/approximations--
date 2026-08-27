import random
N = 10000000000
dentro = 0

for i in range (N):
    x = random.random()
    y = random.random()

    if (x * x + y * y <= 1):
            dentro += 1
pi = 4.0 * dentro / N;
print("Estimativa:", pi)
