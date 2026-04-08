# Bouffalant
![Bouffalant](https://www.pokemon.com/static-assets/content-assets/cms2/img/pokedex/full/626.png)

A personal repository for practicing Data Structures & Algorithms problems across multiple programming languages.

## Goals

This repository exists for two main reasons:

- Practice Data Structures & Algorithms.
- Explore and learn programming languages through the implementation of the same problems and approaches.

Problems are currently sourced from:

- LeetCode
- Codeforces

Implementations are maintained in:

- C++23
- Java 25
- Rust (stable)

## Naming Convention

Problems follow a platform-prefixed naming convention.

Examples:

- LC0843GuessTheWord
- CF1552FTelepanting

Where:

- LC denotes LeetCode.
- CF denotes Codeforces.
- Numeric identifiers are zero-padded when appropriate.
- Language-specific filename conventions are applied automatically by repository tooling.

Examples:

- C++  : LC0843GuessTheWord.cpp
- Java : LC0843GuessTheWord.java
- Rust : lc0843_guess_the_word.rs

## Repository Structure

```
.
├── cpp/
│   ├── include/
│   ├── src/
│   └── test/
├── java/
│   └── src/
│       ├── main/java/
│       └── test/java/
├── rust/
│   └── src/
├── githooks/
├── scripts/
└── README.md
```

Within each language, solutions are grouped by source:

- leetcode/
- codeforces/

## Testing

Every solution includes automated tests.

Frameworks:

| Language | Framework  |
|----------|------------|
|C++	   | GoogleTest |
|Java      | JUnit 5    |
|Rust      | cargo test |

Run all tests:

```
scripts/test
```

Run all tests for a language:

```
scripts/test cpp
scripts/test java
scripts/test rust
```

Run tests for a source:

```
scripts/test cpp lc
scripts/test java cf
```

Run a specific problem:

```
scripts/test cpp lc LC0843GuessTheWord
scripts/test java cf CF1552FTelepanting
scripts/test rust lc lc0843_guess_the_word
```

## Problem Generation

New problems can be scaffolded automatically.

Examples:

```
scripts/generate cpp lc "843 Guess the Word"
scripts/generate java lc "843 Guess the Word"
scripts/generate rust cf "1552F Telepanting"
```

Generation creates the appropriate source files, test files, and language-specific boilerplate while applying repository naming conventions automatically.

## Git Hooks

Repository hooks can be installed with:

```
scripts/install_hooks
```

This configures Git to use the repository-managed hooks located in:

githooks/


## Commit Workflow

The repository includes a helper script for validating a problem before committing.

Example:

```
scripts/commit cpp leetcode "843 Guess the Word"
```

The script:

- Runs the relevant test suite.
- Stages repository changes.
- Displays the generated commit message.
- Prompts for confirmation.
- Creates the commit.

Generated commit messages follow the format:

```
[ C++ | LeetCode ] 843 Guess the Word
```

## Design Principles

Solutions should:

- Be accepted by the target platform.
- Respect expected complexity constraints.
- Prioritize readability after correctness and efficiency.
- Include tests.
- Use modern language features when they improve clarity.
- Remain maintainable and easy to revisit in the future.

When implementing the same problem in multiple languages, the goal is generally to preserve the same underlying algorithmic approach while allowing each language to use its natural idioms and conventions.

## Development Environment

Current development environment:

- GCC 15
- CMake 4.2
- Java 25
- Maven 3.9
- Rust 1.93

Development is primarily performed on WSL, though the repository uses standard tooling and should remain portable across Linux, macOS, and Windows.
