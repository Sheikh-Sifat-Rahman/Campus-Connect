# Campus Connect

**Campus Connect** is a console-based Student Management System built using the **C programming language**. It allows users to manage student records, search and filter data, and navigate various informational categories such as departments, clubs, and sports. It is designed for academic institutions aiming to streamline basic student data management.

---

## 🔧 Features

- 🔐 **Password-Protected Admin Mode**  
  Secure access to modify sensitive student data.

- 📁 **Student Record Management**
  - Add new students
  - Delete existing student records
  - Store data in CSV format (`CseDepartmentRecord.csv`)

- 🔍 **Search Functionality**
  - Search by **ID**
  - Search by **Name**
  - Filter by **Address**

- 🏛️ **Category-Based Filtering**
  - View students by **Department** (e.g., CSE)
  - View members of **Clubs** (e.g., BUPCPC, BUPRC)
  - View players by **Sports** (e.g., Cricket, Football, Volleyball, Handball)

- 📢 **Announcements (Planned Feature)**  
  Structure prepared for future addition of a bulletin system.

- 👨‍💼 **About Us**  
  Credits the contributors involved in the project.

---

## 📁 File Structure

- `Campus_Connect.c` — Main source code
- `CseDepartmentRecord.csv` — CSV file for storing student information
- `temp.csv` — Temporary file used during deletion operations
- *(Announcements feature uses `AnnouncementFile.csv`, not yet active)*
