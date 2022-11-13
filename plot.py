import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
import pandas as pd
from pylab import savefig


matrix = pd.read_csv('output_seq',delimiter=" ")
matrix = matrix.apply(pd.to_numeric)

#array = np.array(matrixDF)
svm = sns.heatmap(matrix)


plt.savefig('heatmap.png', dpi=400)

#plt.imshow(a, cmap='hot', interpolation='nearest')
#plt.show()