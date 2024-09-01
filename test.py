import example
import numpy as np

a = np.array([1, 2, 3, 4, 5], dtype=np.int32)
b = np.array([10, 20, 30, 40, 50], dtype=np.int32)

result = example.add(a, b)
print(result)

