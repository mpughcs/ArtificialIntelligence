import math
import random


# fitness function
def objective_function(individual):
    x = individual["x"]
    y = individual["y"]
    return math.sin(math.sqrt(x ** 2 + y ** 2))

#sort population
def sort_population_by_fitness(population):
    return sorted(population, key=objective_function)


# ///////////////////////////////////////////////////////////////

def select_individual(sorted_population, fitness_sum):
    rand = random.uniform(0, fitness_sum)
    current_sum = 0
    for individual in sorted_population:
        current_sum += objective_function(individual)
        if current_sum > rand:
            return individual
    return sorted_population[-1]

   

# this function is used to crossover two individuals to produce a new individual
def crossover(individual_a, individual_b):
    next_x = (individual_a["x"] + individual_b["x"]) / 2
    next_y = (individual_a["y"] + individual_b["y"]) / 2
    return {"x": next_x, "y": next_y}
    




def mutate(individual):
    lower_boundary, upper_boundary = (-4, 4)

    mutation_rate = 0.05

    next_x=individual["x"]+ random.uniform(-mutation_rate, mutation_rate)
    next_x = min(max(next_x, lower_boundary), upper_boundary)

    next_y=individual["y"]+ random.uniform(-mutation_rate, mutation_rate)
    next_y = min(max(next_y, lower_boundary), upper_boundary)
    return {"x": next_x, "y": next_y}



# ///////////////////////////////////////////////////////////
# make next generation
def make_next_generation(previous_population):
    next_generation = []
    sorted_by_fitness_population = sort_population_by_fitness(previous_population)
    population_size = len(previous_population)
    fitness_sum = sum(objective_function(individual) for individual in population)

    for i in range(population_size):
        first_choice = select_individual(sorted_by_fitness_population, fitness_sum)
        second_choice = select_individual(sorted_by_fitness_population, fitness_sum)
    
        individual = crossover(first_choice, second_choice)
        individual = mutate(individual)
        next_generation.append(individual)

    return next_generation

#generate_population
import random

def generate_population(size, x_boundaries, y_boundaries):
    lower_x_boundary, upper_x_boundary = x_boundaries
    lower_y_boundary, upper_y_boundary = y_boundaries

    population = []
    for i in range(size):
        individual = {
            "x": random.uniform(lower_x_boundary, upper_x_boundary),
            "y": random.uniform(lower_y_boundary, upper_y_boundary),
        }
        population.append(individual)

    return population

generations = 10

population = generate_population(size=10, x_boundaries=(-4, 4), y_boundaries=(-4, 4))

i = 1
while True:
    
    if i == generations:
        break

    i += 1

    population = make_next_generation(population)

best_individual = sort_population_by_fitness(population)[-1]
print("\n🔬 FINAL RESULT")
print(best_individual, objective_function(best_individual))
