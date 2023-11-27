""" Program that plots data from a .result file into a graph. """

import matplotlib.pyplot as plt

from typing import Dict, List

def plot(keys: List[int], values: List[int]) -> None:
    fig, ax = plt.subplots()
    ax.plot(keys, values)

def main() -> None:
    keys = []
    values = []

    with open(".results", "r") as f:
        for line in f:
            line = line.strip()
            key, value = line.split(",")
            keys.append(key)
            values.append(value)

    plot(keys, values)


if __name__ == "__main__":
    main()
