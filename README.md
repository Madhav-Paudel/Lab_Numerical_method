# Numerical Methods Laboratory in C

![Numerical Methods](https://img.shields.io/badge/Numerical-Methods-blue)
![Language](https://img.shields.io/badge/Language-C-green)
![License](https://img.shields.io/badge/License-MIT-red)

A comprehensive collection of numerical methods implementations in C, covering various mathematical and engineering problem-solving techniques. This repository contains implementations of fundamental numerical algorithms structured across seven laboratory sessions.

## 📚 Table of Contents

- [Overview](#overview)
- [Laboratory Content](#laboratory-content)
- [Prerequisites](#prerequisites)
- [Getting Started](#getting-started)
- [Project Structure](#project-structure)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## 🎯 Overview

This repository contains implementations of various numerical methods commonly used in scientific computing and engineering applications. Each laboratory session focuses on different aspects of numerical computation, from root finding to solving differential equations.

## 💻 Laboratory Content

### Lab 1: Root Finding Methods
- Bisection Method
- Fixed Point Iteration Method
- Newton-Raphson Method
- Secant Method

### Lab 2: Interpolation and Curve Fitting
- Lagrange's Interpolation Method
- Newton's Divided Difference
- Linear Regression (Straight Line Fitting)

### Lab 3: Linear Algebra
- Naive Gauss Elimination Method
- Gauss-Jordan Method
- Doolittle LU Decomposition
- Jacobi Iteration Method
- Gauss-Seidel Method
- Power Method (Eigenvalue and Eigenvector)

### Lab 4: Numerical Differentiation
- Forward Difference Method
- Backward Difference Method
- Divided Difference Polynomial

### Lab 5: Numerical Integration
- Romberg Integration
- Simpson's 3/8 Rule
- Simpson's 1/3 Rule
- Trapezoidal Rule

### Lab 6: Ordinary Differential Equations
- Euler Method
- Heun's Method
- Runge-Kutta Method
- Taylor Series Method

### Lab 7: Partial Differential Equations
- Elliptic PDE using Finite Difference Method
- Poisson Equation using Finite Difference Method

## 🔧 Prerequisites

- GCC Compiler
- Basic understanding of C programming
- Knowledge of numerical methods concepts

## 🚀 Getting Started

1. Clone the repository:
```bash
git clone https://github.com/Madhav-Paudel/Lab_Numerical_method.git
```

2. Navigate to the project directory:
```bash
cd Lab_Numerical_method
```

3. Choose a lab directory and compile the desired program:
```bash
cd Lab1
gcc bisection_method.c -o bisection
```

4. Run the executable:
```bash
./bisection
```

## 📁 Project Structure

```
Lab_Numerical_method/
├── Lab1/
│   ├── bisection_method.c
│   ├── fixed_point.c
│   ├── newton_raphson.c
│   └── secant_method.c
├── Lab2/
├── Lab3/
├── Lab4/
├── Lab5/
├── Lab6/
├── Lab7/
└── README.md
```

## 💡 Usage

Each program is designed to be interactive and user-friendly. When you run a program, it will:
1. Prompt for necessary inputs
2. Display intermediate steps (where applicable)
3. Show the final result
4. Provide error handling for invalid inputs

Example usage of Bisection Method:
```c
Enter the function (e.g., x^2 - 4):
Enter the interval [a, b]:
Enter the tolerance:
```

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Created by [Madhav Paudel](https://github.com/Madhav-Paudel) - Feel free to connect!