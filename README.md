# ♟️ Console Chess Engine (C++)

> A fully functional, terminal-based two-player Chess game built entirely in C++. This project demonstrates core Object-Oriented Programming (OOP) concepts including Inheritance, Polymorphism, and Encapsulation through a modular game engine architecture.

---

## 👥 The Development Team

Our engine was divided into three core modules, handled independently and merged into a master game loop using GitHub for version control.

| Team Member | Roll Number | Primary Role & Contributions |
| :--- | :--- | :--- |
| **Muhammad Husnain** | `25F-0616` | **Project Lead & Repository Manager:** Established the GitHub repository, managed version control, and implemented the mathematical movement validation for all individual chess pieces. |
| **Muhammad Saad** | `25F-0511` | **Core Architect & Integrator:** Developed the main `Board` engine and master game loop. Debugged the final build, resolved merge conflicts, and successfully integrated all team modules into the final executable. |
| **Muhammad Ali** | `25F-0605` | **Game Rules & Physics:** Developed the `GameRules` module, handling path-blocking detection, piece capturing, and checkmate conditions. |

---

## ⚙️ Technical Highlights

* **Polymorphism:** Utilized pure virtual functions (`isValidMove`) in the base class to allow the board to interact with pieces without knowing their specific type.
* **Dynamic Memory:** The 8x8 grid utilizes pointers to dynamically allocate and clean up pieces to prevent memory leaks during captures.
* **Modular Design:** Separation of concerns between geometry (can the piece move?), physics (is the path blocked?), and state (is the game over?).

---

## 🚀 How to Run the Game (Visual Studio)

**⚠️ CRITICAL:** This project requires specific linking in Visual Studio. Please follow these exact steps to avoid `LNK2019 Unresolved External Symbol` errors.

### Step 1: Clone the Repository
1. Open **Visual Studio**.
2. On the start window, click **Clone a repository**.
3. Paste the GitHub `.git` link for this repository into the location box.
4. Choose your local destination path and click **Clone**.

### Step 2: Link the Source Files (Required)
*Visual Studio does not automatically link cloned C++ files. You must do this manually for the game to compile.*
1. Look at the **Solution Explorer** panel on the right side of Visual Studio.
2. Right-click on **Source Files** (or the project name).
3. Go to **Add** ➔ **Existing Item...**
4. Navigate into your cloned project folder.
5. Highlight and select **ALL** `.cpp` and `.h` files manually.
6. Click **Add**.

### Step 3: Build & Play
1. Go to the top menu and click **Build** ➔ **Rebuild Solution**.
2. Once the build succeeds, press the green **Local Windows Debugger (Play)** button.
3. Input your moves using grid coordinates (e.g., `0 6 0 4` to move the pawn at column 0, row 6 up two spaces).