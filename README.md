# OOP C++ Group Project - Group 2

Welcome to the official repository for Group 2.

## Requirements & Contribution Guidelines
1. **Git Workflow**:   Clone this repository, create a separate branch for your assigned task, and open a Pull Request (PR) when your code is ready for review.
2. **No AI Assistance**:   All submitted code must be original and written by team members.
3. **Grading & Attendance**:   Contribution is measured by merged code and active participation. Unmerged work or AI-generated submissions will not be credited.
4. **Code Reviews**:   Merges will be reviewed and tested collectively during our scheduled group review days.


# 🚀 Team Collaboration & Git Workflow Guide

Welcome to the project! This guide outlines the complete step-by-step workflow everyone must follow when contributing code to this repository. Please follow these instructions carefully.

---

## 📋 Table of Contents
1. Initial Setup (One-Time Only)
2. Starting Work on a Task
3. Saving and Pushing Your Code
4. Creating a Pull Request (PR)
5. Updating Your Local Repo with main
6. Best Practices & Rules

---

## 1. Initial Setup (One-Time Only)

### Step A: Accept the Repository Invitation
Check your email or go to the repository page on GitHub and accept the collaboration invitation.

### Step B: Clone the Repository
Open your terminal or Git Bash, navigate to where you want the project folder to live, and run:

git clone <REPOSITORY_URL>
cd <REPOSITORY_FOLDER_NAME>

### Step C: Configure Your Git Identity
Set your name and email so commits are correctly attributed to you:

git config user.name "Your Full Name"
git config user.email "your.email@example.com"

---

## 2. Starting Work on a Task

⚠️ CRITICAL RULE: NEVER work directly on the main branch. Always create a separate feature branch for your work.

### Step A: Make sure your main branch is up to date
git checkout main
git pull origin main

### Step B: Create and switch to a new feature branch
Name your branch based on the feature or task assigned to you:

git checkout -b feature/<your-feature-name>

Examples:
- git checkout -b feature/librarian-dashboard
- git checkout -b feature/book-class
- git checkout -b fix/login-validation

---

## 3. Saving and Pushing Your Code

As you build your assigned module, save and commit your progress regularly with clear, descriptive commit messages.

### Step A: Check modified files
git status

### Step B: Stage modified/new files
To stage all changed files:
git add .

Or stage a specific file:
git add path/to/file.cpp

### Step C: Commit your changes
Write a brief, clear commit message explaining what you built or modified:
git commit -m "Add basic layout and function prototypes for librarian dashboard"

### Step D: Push your branch to GitHub
git push -u origin feature/<your-feature-name>

---

## 4. Creating a Pull Request (PR)

Once your assigned part is complete and working locally:

1. Open the project repository on GitHub.
2. Look for the banner near the top saying "feature/<your-feature-name> had recent pushes" and click the green Compare & pull request button.
   (If you don't see the banner, click on the Pull requests tab and click New pull request manually).
3. Fill out the PR details:
   - Title: Clear summary of what was added (e.g., Add Librarian Dashboard Functionality).
   - Description: List the changes made, new files added, or testing notes.
4. Click Create pull request.
5. Notify the repository owner so they can review your code and merge it into main.

---

## 5. Updating Your Local Repo with main

If other teammates have merged code into main while you were working on your feature, update your feature branch to keep everything synchronized:

1. Switch to main and pull the latest changes:
git checkout main
git pull origin main

2. Switch back to your feature branch:
git checkout feature/<your-feature-name>

3. Merge main into your feature branch:
git merge main

If Git flags merge conflicts, open the affected files in your code editor, resolve the conflicts, save, and then run:
git add .
git commit -m "Resolve merge conflicts with main"
git push origin feature/<your-feature-name>

---

## 6. Best Practices & Rules

- ❌ Do not commit directly to main. Always push to your own feature branch first.
- 💬 Write meaningful commit messages (e.g., Implement search algorithm instead of updated files).
- 🧹 Keep branches focused — work on one feature per branch.
- 🧪 Test your code before submitting a PR — verify that the project compiles and runs smoothly without breaking existing features.
