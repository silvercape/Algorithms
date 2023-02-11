import random


def generate_randint(scope):
    return random.randint(-(scope >> 1), scope >> 1)


def generate_rand_array(scope):
    rand_array = []
    for i in range(test_scope):
        rand_array.append(generate_randint(scope))
    rand_array.sort()
    return rand_array


test_scope = 100
find_target = generate_randint(test_scope)
arr = generate_rand_array(test_scope)

with open("./input", "w") as f:
    f.write(f"{test_scope} ")
    f.write(f"{find_target}\n")
    for i in range(test_scope):
        f.write(f"{arr[i]} ")
