Mersenne Numbers

This repository is dedicated to exploring and working with **Mersenne numbers** – numbers of the form **2ⁿ - 1**. Whether you're interested in generating these numbers, testing for Mersenne primes, or simply learning more about their unique properties, this project provides a clean, easy-to-use codebase to help you get started.

---

Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

---

Overview

Mersenne numbers, expressed as **Mₙ = 2ⁿ - 1**, have intrigued mathematicians for centuries, especially when it comes to identifying **Mersenne primes** (Mersenne numbers that are prime). This repository includes implementations and tools for:

- Generating Mersenne numbers for given values of *n*
- Checking if a Mersenne number is prime
- Exploring properties and patterns within the sequence

This project is intended for both educational purposes and as a starting point for deeper mathematical explorations.

---

Features

- **Generation:** Compute Mersenne numbers for any positive integer *n*.
- **Primality Testing:** Check if a given Mersenne number is prime using optimized algorithms.
- **Examples & Documentation:** Clear examples and comments to help you understand how the code works.
- **Modular Design:** Easy to extend and integrate with other mathematical tools or projects.

---

Getting Started

Prerequisites

- **Python 3.7+** – Ensure you have a recent version of Python installed.
- Additional Python libraries may be required; check the [requirements.txt](requirements.txt) file (if available) for dependencies.

Installation

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/Dilyannn/Mersenne-numbers.git
   cd Mersenne-numbers
   ```

2. **(Optional) Create a Virtual Environment:**

   ```bash
   python -m venv venv
   source venv/bin/activate  # On Windows: venv\Scriptsctivate
   ```

3. **Install Dependencies:**

   If there is a requirements file, run:

   ```bash
   pip install -r requirements.txt
   ```

---

Usage

The repository is designed to be both a library and a standalone tool.

- **As a Library:** Import the functions in your own Python scripts.

  ```python
  from mersenne import generate_mersenne, is_mersenne_prime

  n = 5
  m = generate_mersenne(n)
  print(f"Mersenne number for n = {n} is {m}")

  if is_mersenne_prime(m):
      print(f"{m} is a Mersenne prime!")
  else:
      print(f"{m} is not a Mersenne prime.")
  ```

- **Command Line Interface:** If a CLI is provided, you can run:

  ```bash
  python mersenne.py --n 5
  ```

  This will generate the Mersenne number for the given value of *n* and indicate if it is prime.

---

Examples

Below are a couple of quick examples:

1. **Generate a Mersenne number:**

   ```bash
   python mersenne.py --generate 10
   ```

   This command calculates the 10th Mersenne number.

2. **Check for Mersenne prime:**

   ```bash
   python mersenne.py --check 31
   ```

   This command checks if 31 (which is 2⁵ - 1) is a Mersenne prime.

Feel free to explore the code and modify it for your needs.

---

Contributing

Contributions are welcome! If you’d like to suggest improvements, report issues, or add new features, please follow these steps:

1. Fork the repository.
2. Create a new branch: `git checkout -b feature/YourFeature`.
3. Commit your changes: `git commit -m 'Add some feature'`.
4. Push to the branch: `git push origin feature/YourFeature`.
5. Open a pull request.

Be sure to follow the existing coding style and include tests for any new functionality.

---

License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

Acknowledgments

- **Mersenne Numbers & Primes:** Special thanks to the mathematical community for their continuous exploration of prime numbers.
- **Open Source Contributors:** A big shout-out to all the developers and mathematicians whose open source contributions make projects like this possible.

Happy computing!