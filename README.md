# N-Queens Genetic Algorithm Solver

A C++ implementation of the classic N-Queens problem, solved using two distinct variants of Genetic Algorithms (GA). The project focuses on comparing different evolutionary strategies—specifically regarding selection and crossover operators—and includes a custom CLI visualizer that renders the chessboard state in real-time using ANSI terminal styling.

Developed as part of my cybersecurity portfolio, this project demonstrates proficiency in algorithmic design, C++ performance optimization, and the creation of clean, maintainable code.

---

## Technical Approach

### Genetic Algorithm Variants
I implemented and compared two evolutionary approaches to observe how different operators impact convergence:

* **GA v1 (Baseline):** Utilizes **Roulette Wheel selection** combined with **Order Crossover (OX1)**. This variant provides a baseline for evaluating the performance of the evolutionary process.
* **GA v2 (Optimized):** Employs **Tournament Selection**, **Partially Mapped Crossover (PMX)**, and **Inversion Mutation**. These techniques were specifically chosen to improve search efficiency and prevent premature convergence.

### CLI Visualization
To improve the interpretability of algorithmic results, I developed a custom visualizer. Using ANSI escape sequences, the terminal outputs a high-fidelity representation of the $N \times N$ board, complete with color-coded squares and distinct highlighting for queen placements.

---

## Project Architecture
* `src/genetic_v1.cpp` / `.h`: Core logic for the baseline evolutionary approach.
* `src/genetic_v2.cpp` / `.h`: Optimized logic utilizing tournament selection and PMX crossover.
* `src/fitness.cpp`: Implementation of the fitness function, focused on counting non-attacking queen pairs.
* `src/visualizer.cpp`: ANSI-based board rendering engine.

---

## Build Instructions
To compile and run the project, ensure you have a C++17 compatible compiler:

```bash
git clone [https://github.com/rcrzlbrd/n-queens-genetic.git](https://github.com/rcrzlbrd/n-queens-genetic.git)
cd n-queens-genetic
# Compilation
g++ -I./src src/*.cpp main.cpp -o nqueens
# Execution
./nqueens
```

## Key Learnings

* Evolutionary Optimization: Demonstrated the ability to benchmark and iterate on algorithmic operators to maximize search efficiency.

* Efficient Memory Management: Focused on writing performant C++ code by minimizing overhead within the fitness evaluation loops—a fundamental skill for developing robust and secure low-level tools.

* Algorithmic Complexity: Gained deeper insight into the search space limitations of NP-hard problems through practical application.

--- 

## Author

Ramiro Cruz Labrada — [GitHub](https://github.com/rcrzlbrd)