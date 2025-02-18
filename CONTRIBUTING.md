# Smart File Organizer (C)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Issues](https://img.shields.io/github/issues/Shadabdullah/SmartFileOrganizer.svg)](https://github.com/Shadabdullah/SmartFileOrganizer/issues)
[![Contributors](https://img.shields.io/github/contributors/Shadabdullah/SmartFileOrganizer.svg)](https://github.com/Shadabdullah/SmartFileOrganizer/graphs/contributors)


---

## 💡 Contributing to Smart File Organizer

We welcome contributions to make this project even better! Here's how you can get involved:

### 📌 How to Contribute
- 🐛 **Report Bugs**: If you encounter any issues, please open a [new issue](https://github.com/Shadabdullah/SmartFileOrganizer/issues) on GitHub.
- 🚀 **Submit Feature Requests**: Got an idea for a feature or enhancement? Feel free to open a [feature request](https://github.com/Shadabdullah/SmartFileOrganizer/issues).
- 🔧 **Submit Code Changes**:  
   1. **Fork the repository**: Click the "Fork" button at the top right of this page.  
   2. **Clone your fork**:  
      ```sh
      git clone https://github.com/your-username/SmartFileOrganizer.git
      cd SmartFileOrganizer
      ```
   3. **Create a new branch**:  
      ```sh
      git checkout -b feature/my-feature
      ```
   4. **Make your changes**:  
      - Add new features, fix bugs, or improve documentation.  
   5. **Commit your changes**:  
      ```sh
      git commit -m "Your descriptive commit message"
      ```
   6. **Push your changes**:  
      ```sh
      git push origin feature/my-feature
      ```
   7. **Create a Pull Request**: Go to the repository and click "New Pull Request" to submit your changes for review.

### 📏 Coding Standards
- Follow the **C99 standard** for consistent, portable C code.
- Use **descriptive and meaningful names** for functions and variables.
- **Ensure memory safety**: Use tools like [Valgrind](http://valgrind.org/) to check for memory leaks and invalid memory access.
- Stick to the existing **code style** as much as possible to maintain consistency.

### 📂 Code Structure
- `src/main.c` → CLI entry point.
- `src/file_ops.c` → Handles file detection and movement.
- `src/backup.c` → Manages backup and restore functionality.
- `src/daemon.c` → Implements real-time directory monitoring.
- `src/utils.c` → Contains helper functions and utilities.
- `include/` → Header files for modular design.

### 🛠 Development Setup

To set up your development environment:

```sh
git clone https://github.com/Shadabdullah/SmartFileOrganizer.git
cd SmartFileOrganizer
make
```

### 🔄 Syncing Your Fork
To stay up to date with the main repository, regularly sync your fork with the following:

```sh
git remote add upstream https://github.com/Shadabdullah/SmartFileOrganizer.git
git fetch upstream
git checkout main
git merge upstream/main
git push origin main
```


## **1. Writing the Best Commits**

### **a. Commit Messages: Best Practices**
A good commit message communicates **what** was changed and **why** it was changed. Follow these guidelines:

1. **Use a Clear and Concise Subject Line**:
   - Limit the subject line to 50 characters.
   - Use the imperative mood (e.g., "Add", "Fix", "Update", "Remove").
   - Example: `Fix file search bug in dark mode`

2. **Add a Detailed Body (if needed)**:
   - Use the body to explain **why** the change was made and **how** it works.
   - Wrap the body at 72 characters per line.
   - Example:
     ```
     Fix file search bug in dark mode

     The file search functionality was not working in dark mode due to a CSS
     issue. This commit fixes the contrast issue by updating the text color
     in the search bar.
     ```

3. **Reference Issues or Tickets**:
   - If the commit is related to an issue or ticket, reference it in the commit message.
   - Example: `Fix file search bug in dark mode (closes #123)`

4. **Follow a Consistent Format**:
   - Use a consistent format across the project. For example:
     ```
     <type>: <subject>
     <BLANK LINE>
     <body>
     ```
     - `<type>`: `feat`, `fix`, `docs`, `style`, `refactor`, `test`, `chore`, etc.
     - Example:
       ```
       feat: add file tagging functionality

       This commit adds the ability to tag files with custom labels. Users can
       now organize files more efficiently using tags.
       ```

---

### **b. Atomic Commits**
- **One Change per Commit**: Each commit should represent a single logical change. Avoid bundling multiple unrelated changes into one commit.
- **Small and Focused**: Keep commits small and focused. This makes it easier to review and revert changes if needed.

---

### **c. Use Branches for Features**
- Create a new branch for each feature or bug fix. For example:
  ```
  git checkout -b feature/file-tagging
  ```
- Commit your changes to this branch before creating a PR.

---

## **2. Writing the Best Pull Requests (PRs)**

### **a. PR Title**
- Use a clear and descriptive title that summarizes the changes.
- Example: `Add file tagging functionality`

---

### **b. PR Description**
The PR description is your opportunity to explain the changes in detail. Follow this structure:

1. **What**:
   - Briefly describe what the PR does.
   - Example: "This PR adds the ability to tag files with custom labels."

2. **Why**:
   - Explain why the change is necessary.
   - Example: "This feature will help users organize files more efficiently."

3. **How**:
   - Provide details about how the change was implemented.
   - Example: "The tagging functionality is implemented using a new `Tag` model and a UI component for adding/removing tags."


4. **Testing**:
   - Mention how the changes were tested.
   - Example: "I tested this feature by tagging files and verifying that the tags persist across sessions."

5. **Related Issues**:
   - Reference any related issues or tickets.
   - Example: "Closes #123"

---

### **c. Keep PRs Small and Focused**
- **Single Responsibility**: Each PR should address a single feature, bug fix, or improvement.
- **Avoid Large PRs**: Large PRs are harder to review. Break them into smaller, manageable PRs if possible.

---

### **d. Review Your Own PR**
- Before requesting a review, go through your own PR:
  - Check for typos, formatting issues, or unnecessary changes.
  - Ensure the code follows the project's style guide.
  - Verify that all tests pass.

---

### **e. Request Reviews**
- Assign reviewers who are familiar with the part of the codebase you’ve changed.
- Provide context to reviewers by mentioning specific files or changes that need attention.

---

### **f. Respond to Feedback**
- Be open to feedback and address comments promptly.
- If you make changes based on feedback, push new commits to the same branch. The PR will update automatically.

---


### **d. Use Templates**
- Create PR and commit message templates to standardize communication.
- Example PR template:
  ```markdown
  ### What
  [Brief description of the changes]

  ### Why
  [Explain why the changes are necessary]

  ### How
  [Describe how the changes were implemented]

  ### Screenshots
  [Add screenshots or GIFs if applicable]

  ### Testing
  [Describe how the changes were tested]

  ### Related Issues
  [Reference related issues or tickets]
  ```

---

## **4. Example Workflow**

### **a. Writing a Commit**
1. Make changes to your code.
2. Stage the changes:
   ```
   git add .
   ```
3. Write a commit message:
   ```
   git commit -m "feat: add file tagging functionality

   This commit adds the ability to tag files with custom labels. Users can
   now organize files more efficiently using tags."
   ```

### **b. Creating a PR**
1. Push your branch to GitHub:
   ```
   git push origin feature/file-tagging
   ```
2. Open a PR on GitHub with a clear title and description.
3. Request reviews from team members.
4. Address feedback and push new commits if needed.
5. Once approved, merge the PR into the main branch.

---

By following these guidelines, you’ll write clear, meaningful commits and PRs that make collaboration easier and improve the overall quality of your project.



## 📝 License
This project is licensed under the [MIT License](LICENSE).
```

