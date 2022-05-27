import pandas as pd
import matplotlib.pyplot as plt
import sys
import os

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python visualisation.py data_folder")
        sys.exit(1)
    data_folder = sys.argv[1]
    for file in os.listdir(data_folder):
        if file.endswith(".csv"):
            df = pd.read_csv(f"{data_folder}/{file}")
            for col in df.columns.values[1:]:
                plt.plot(df.iloc[:, 0].values, df[col].values, label=col)
            plt.xlim(1, df.iloc[:, 0].values[-1])
            plt.xlabel("Xlabel")
            plt.ylabel("Ylabel")
            plt.legend(loc='best')
            plt.savefig(f"{data_folder}/{file}.pdf", dpi=600)
            plt.close()
            print(f"{file} ploted")
    sys.exit(0)
