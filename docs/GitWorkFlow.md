## Work Flow
1. Clone repository.
2. Create new branch for work stream.
3. Develop feature.
    - Commit atomic changes.
    - Push to remote whenever you want. 
4. Pull from DEV branch.
    - Resolve conflicts, if any.
5. Push branch in its final state.
6. Create a Pull Request from branch to DEV.
7. Other developers review your changes.
    - Fix issues, if any.
8. Complete Pull Request.
9. Delete branch.

## Git Commands

**Clone Repository**
    
    git clone <repository> <local_path>

**Pull Changes From Current Branch**

    git pull origin

**Pull Changes From DEV Branch**

    git pull origin dev:<your_branch>

**Check For Changed Files**

    git status

**Add Changed Files**

    git add <file_path>

**Commit Changes**

    git commit -m "<commit_message>"

**Push Branch to GitHub**

    git push origin

**Check Current Branch**

    git branch

**Fetch Available Branches**

    git fetch

**Create New Branch**

    git checkout -b <branch_name>

**Change to Existing Branch**

    git checkout <branch_name>
