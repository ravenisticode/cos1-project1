# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [ COS119 ]

- **[ Jason Montgomery ]**
- **[ October 4, 2026 ]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [ cls: Clear the Screen
- [ cd: Print the "Working Directory"
- [dir: List files and folders
- [ dir /a ]: List files and folders, including invisible files
- [ dir ]: List all files and folders, in human readable form
- [ cd ]: Change directory
- [ cd \ ]: Change directory, go to root directory
- [ cd %userprofile% ]: Change directory and go to user home directory
- [ cd . . ]: Change directory, go up one folder level
- [ cd . . \ . . ]: Change directory, go up two folder levels
- [ cd %userprofile%\Desktop ]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ It pasted the entire file path of the folder right into the line]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[ 1. 
Local version control LVC

- **How it works:** This is the simplest form of version control, where a developer tracks changes using a simple database stored **entirely on their local computer**.
- **The mechanism:** It automatically tracks file modifications over time, often by saving a history of patches (the differences between files) locally.
- **The drawback:** Everything is stored on one machine. If your hard drive crashes or the local database gets corrupted, your entire version history is lost. It is also incredibly difficult to collaborate with others..
- 
-2. Centralized Version Control Systems (CVCS)

- **How it works:** To allow collaboration, a **single central server** holds the entire history and database of all versioned files.
- **The mechanism:** Developers "check out" individual files from the central server, make changes, and commit them back to the server. Popular examples include **Subversion (SVN)** and **Perforce**.
- **The drawback:** The single central server represents a major single point of failure. If the server goes down for an hour, nobody can collaborate or save versioned changes during that time. If the central hard drive corrupts and backups haven't been kept, you lose the entire project's history.

3. Distributed Version Control Systems (DVCS)

- **How it works:** Instead of checking out just the latest snapshot of the files, developers **fully clone the entire repository**, including its complete historical data, onto their local machine.
- **The mechanism:** Every client acts as a full backup of the server. You can commit changes, create branches, and view history completely offline. When you connect to the internet, you sync your local repository with a hosting service (like **GitHub** or **GitLab**). The most prominent example is **Git**.
- **The advantage:** If the central server dies, any developer's local repository can be uploaded back to a new server to fully restore the project and its history. ]

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ git clone <repository_url>
 ]: Clone a repository
- [ git config --global user.name "Your Name"
 ]: Set-up a global user name
- [ git config --global user.email "your.email@example.com"
 ]: Set-up a global email address (to match my GitHub account email)
- [ git status
 ]: Shows the current state of your directory and staging area
- [ git add <file_name>
 ]: Add modified files to the next commit
- [ git commit -m "Your descriptive commit message"
]: Make a commit with a new message
- [ git log
 ]: Show my commit history
- [ git --help
 ]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

[ Generate a Personal Access Token (PAT) on GitHub

Before using the Terminal, you must obtain a token from your GitHub account:

1. Log into your account on the GitHub website.
2. Click your profile picture in the top-right corner and select **Settings**.
3. Scroll down the left sidebar and click **Developer settings**.
4. Click **Personal access tokens** and select **Fine-grained tokens** (GitHub's recommended method for enhanced security).
5. Click **Generate new token**.
6. Give your token a descriptive name, set an expiration date, and choose which repositories it can access (e.g., "All repositories").
7. Under **Permissions**, grant the token `Read and Write` access to **Repository contents** so you can push and pull code.
8. Click **Generate token** and **copy it immediately**. You will not be able to see it again once you leave the page. ]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [to tell git which files and folders to ignore]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [it is a hidden system file for MacOS and it created useless clutter should be ignored ]

- What other file or folder would you want to add to a .gitignore file and why?
  [any files with sensitive data, massive dependencies, and local environment files should be ignored for security reasons. also package managers should be ignored because of bloating the filesize.]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[ The most valuable tool I know of is geeksforgeeks.org
I still have yet to encounter anything I couldn't get answers for from there. They have everything you could ever ask about there.]

**Terminal Commands**  
geeksforgeeks.org

**Three Types of Version Control**  
geeksforgeeks.org

**Git Commands**  
geeksforgeeks.org

**Connecting to GitHub using Terminal**  
geeksforgeeks.org

**Using .gitignore and Why it's Important**  
geeksforgeeks.org
