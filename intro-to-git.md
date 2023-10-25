# Introduction to Git Version Control
## Checking Git Version
To check the Git version installed on your system, use the following command:

```bash
git --version
```

## Configuring User Information
To set your global Git user name and email, which will be used for all repositories on your computer, use the following commands:

```bash
git config --global user.name "name"
git config --global user.email "sara@email.com"
```

Note that using `--global` ensures these settings apply to all repositories on your system. To set username and email for a specific repository, you can omit `--global`.

Change `user.name` and `user.email` to match your own.

## Creating a New Git Repository
You can start a new project and initialize it as a Git repository:

```bash
mkdir myproject
cd myproject
git init
```

This will create a new Git repository in the "myproject" directory.

## Checking the Repository Status
To check the status of your Git repository and see which files have been modified, use:

```bash
git status
```
To check all the files and directories in the current directory, use either:
```bash
ls   #Prints it in one line
ls -l   #Prints it as a list
```
## Staging and Committing Changes
To commit your changes, you need to stage them first. Use the following commands:

```bash
git add <file>         # Stage specific file
git add .              # Stage all files in the directory
git commit -m "Message"  # Commit staged changes
```

To stage all changes and commit in one step, you can use:

```bash
git commit -a -m "Message"
```

However, it's ***generally recommended*** (i.e. don't do it) to stage your changes explicitly to review them before committing.

## Viewing Commit History
You can view the commit history of your repository using:

```bash
git log
```

## Getting Help
To get help with a specific Git command, you can use:

```bash
git command --help    # Replace command with any command you need help with
```

For a comprehensive list of Git commands and their documentation, use:

```bash
git help --all
```

## Branching and Merging
- `git branch`: List existing branches.
- `git checkout <branch>`: Switch to a different branch.
- `git checkout -b <new-branch>`: Create and switch to a new branch.
- `git merge <branch>`: Merge changes from another branch into the current branch.
- `git branch -d <branch>`: Delete a branch (only if it's fully merged).

## Remote Repositories
- `git remote add origin <repository-url>`: Add a remote repository.
- `git push --set-upstream origin master`: Push the local repository to a remote repository.
- `git fetch origin`: Fetch changes from a remote repository.
- `git diff origin/master`: View the differences between local and remote branches.
- `git pull origin`: Pull changes from a remote repository.
- `git push origin`: Push changes to a remote repository.
- `git branch -a`: List all remote branches.

## GitHub Flow
GitHub Flow is a workflow for using Git and GitHub for collaborative software development. It typically involves creating branches, making changes, creating pull requests, and merging code. It's a popular process for open-source and team-based projects.

## GitHub-Specific Features and Commands
- `fork`: Fork is not a command, but a feature in GitHub that copies a repository. It can be useful when you want to contribute to someone else's project or start your own based on theirs.
- `git clone <repository-url>`: Clone a GitHub repository.
- `git revert HEAD`: Create a new commit that undoes the changes introduced by a previous commit.
- `git reset commithash`: Reset the current branch to a previous commit, discarding changes. Change commithash to be the first seven characters of the commit hash, which can be found in log.
- `git commit --amend`: Add changes to the previous commit message.

## .gitignore
Create a file named `.gitignore` to specify which files or directories should be ignored by Git. To create it, go to the root of the your local Git, and do:
```bash
touch .gitignore
```
In this case, we use a single .gitignore which applies to the entire repository. It is also possible to have additional .gitignore files in subdirectories. These only apply to files or folders within that directory.

| Pattern                | Explanation/Matches                                                                           | Examples                   |
|------------------------|--------------------------------------------------------------------------------------------|----------------------------|
|                        | Blank lines are ignored                                                                     |                            |
| `# text comment`       | Lines starting with # are ignored                                                           |                            |
| `name`                 | All *name* files, *name* folders, and files and folders in any *name* folder                     | /name.log                  |
| `name/`                | Ending with / specifies the pattern is for a folder. Matches all files and folders in any name folder | /name/file.txt     |
| `name.file`            | All files with the *name.file*                                                                | /name.file                 |
| `/name.file`           | Starting with / specifies the pattern matches only files in the root folder                | /name.file                 |
| `lib/name.file`        | Patterns specifying files in specific folders are always relative to the root (even if you do not start with / ) | /lib/name.file |
| `**/lib/name.file`     | Starting with ** before / specifies that it matches any folder in the repository. Not just on root. | /lib/name.file |
| `**/name`              | All *name* folders, and files and folders in any *name* folder                                   | /name/log.file             |
| `/lib/**/name`         | All *name* folders, and files and folders in any *name* folder within the lib folder            | /lib/name/log.file         |
| `*.file`               | All files with the *.file* extension                                                         | /name.file                 |
| `*name/`               | All folders ending with *name*                                                              | /lastname/log.file         |
| `name?.file`           | ? matches a **single** non-specific character                                                  | /names.file                |
| `name[a-z].file`       | [range] matches a **single** character in the specified range (in this case, a character in the range of a-z, and also be numeric.) | /names.file |
| `name[abc].file`       | [set] matches a **single** character in the specified set of characters (in this case either a, b, or c) | /namea.file |
| `name[!abc].file`      | [!set] matches a **single** character, **except** the ones specified in the set of characters (in this case a, b, or c) | /names.file |
| `*.file`               | All files with the *.file* extension                                                         | /name.file                 |
| `name/!name/secret.log`     | ! specifies a negation or exception. Matches all files and folders in any *name* folder, except name/secret.log | /name/file.txt |
| `*.file !name.file`               | ! specifies a negation or exception. All files with the *.file* extension, except name.file | /log.file                   |
| `*.file/!name/*.file junk.*`               | Adding new patterns after a negation will re-ignore a previous negated file. All files with the *.file* extension, except the ones in the *name* folder. Unless the file name is junk | /log.file |
## Git Security SSH
SSH is a secure shell network protocol that is used for network management, remote file transfer, and remote system access.

SSH uses a pair of SSH keys to establish an authenticated and encrypted secure network protocol. It allows for secure remote communication on unsecured open networks.

The "public" key is the one you share with the remote party. Think of this more as the lock.
The "private" key is the one you keep for yourself in a secure place. Think of this as the key to the lock.

To create the key, run:
```bash
ssh-keygen -t rsa -b 4096 -C "sara@email.com"
```
Change the email to use your own. You will then be prompted to save the key in a file and create a passphrase for an additional layer of security.

Now we add the SSH key pair to the SSH-Agent (using the same file location as above):
```bash
ssh-add /Users/user/.ssh/id_rsa
```
## GitHub Add SSH
Use the `clip <` command to copy the public key to the clipboard:
```bash
clip < /Users/user/.ssh/id_rsa.pub
```
Then add the SSH on GitHub in the Settings. Add the public SSH key to the GitHub.

Test the connection using:
```bash
ssh -T git@github.com
```
The last line of the output should contain your username on GitHub.