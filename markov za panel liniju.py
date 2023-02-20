import numpy as np
import matplotlib.pyplot as plt

def state_matrix(num_states):
   
    return np.zeros((num_states, num_states))

def transition_matrix(num_states, efficiency, buffer_capacity):
  
    T = np.zeros((num_states, num_states))
    T[0][0] = 1 - efficiency
    T[0][1] = efficiency
    T[1][1] = 1 - (1 / buffer_capacity)
    T[1][0] = 1 / buffer_capacity
    return T


num_machines = int(input("Unesi broj strojeva u panel liniji: "))


efficiencies = []
buffer_capacities = []


for i in range(num_machines):
    efficiency = float(input("Unesi korisnost stroja {}: ".format(i+1)))
    efficiencies.append(efficiency)
    buffer_capacity = int(input("Buffer capacity stroja {}: ".format(i+1)))
    buffer_capacities.append(buffer_capacity)


machine_states = []
machine_transitions = []
for i in range(num_machines):
    machine_states.append(state_matrix(2))
    machine_transitions.append(transition_matrix(2, efficiencies[i], buffer_capacities[i]))


machine_state_vectors = []
for i in range(num_machines):
    state_vector = np.array([1, 0]) 
    machine_state_vectors.append(state_vector)


num_steps = int(input("Unesi broj vremenskih koraka : "))


for t in range(num_steps):
    for i in range(num_machines):
        machine_state_vectors[i] = np.dot(machine_state_vectors[i], machine_transitions[i])


for i in range(num_machines):
    plt.bar(['off', 'on'], machine_state_vectors[i])
    plt.title("Stroj {}".format(i+1))
    plt.show()


for i in range(num_machines):
    print("Konačne vjerojatnosti stanja stroja10 {}: {}".format(i+1, machine_state_vectors[i]))
