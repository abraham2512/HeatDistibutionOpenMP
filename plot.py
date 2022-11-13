import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
import pandas as pd
from pylab import savefig

file_name = "output_"+"parallel"

matrix = pd.read_csv(file_name,delimiter=" ")
matrix = matrix.apply(pd.to_numeric)

svm = sns.heatmap(matrix)

plt.savefig(file_name+'.png', dpi=400)
