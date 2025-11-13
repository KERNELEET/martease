<h1 align="center">MartEase - CLI Shopping Platform (C++ Based) </h1>

<p align="center">
  <img width="604" height="306" alt="image" src="https://github.com/user-attachments/assets/a294758c-7395-49f1-891b-d9e50e342d73" />
</p>

**MartEase** is a **Command-Line Interface (CLI)** based shopping system built in **C++**, designed to simulate the functionality of a real-world supermarket.  
It allows both **admins** and **customers** to interact with a digital shopping environment efficiently through a simple console interface.

Developed as part of the **Data Structures & Algorithms (DSA) Lab Project**, this system showcases practical applications of **linked lists, arrays, and sorting/searching algorithms**.

---

## 🛍️ Project Summary

- **Admins** can add, remove, update, and view products in the inventory.  
- **Customers** can browse products, add items to their cart, and proceed to checkout.  
- Products are divided into multiple **categories** such as:  
  - 🥦 Vegetables  
  - 🍎 Fruits  
  - 💻 Electronics  

---

## 🧱 Features

- 🧑‍💼 **Admin Login System**  
- 🗃️ **Inventory Management (Add / Update / Remove)**  
- 🛒 **Shopping Cart with Linked List Implementation**  
- 📦 **Categorized Product Display**  
- 🔍 **Product Search by Name or Category**  
- 💰 **Checkout and Billing Summary**  
- 💾 **Persistent Data (Simulated through arrays)**  
- 🎯 **Input Validation and Error Handling**

---

## 🧩 Example Inventory Structure

```cpp
struct Item {
    int itemID;
    string name;
    double price;
    int quantity;
};

// Example Products
Item products[] = {
    {101, "Apple", 2.99, 50},
    {202, "Laptop", 55000, 10},
    {303, "Tomato", 1.50, 60}
};

```

## 📁 Project Structure

```
martease/
├── ConsoleApplication1
├── README.md

```
---

## ⚙️ How to Run

### 1. Compile the Program
Make sure you have g++ installed.
In your terminal or VS Code, run:

```
g++ main.cpp -o MartEase

```

### 2. Execute the Program
```bash
./MartEase
```
---

## 🧠 Skills Demonstrated

- Object-Oriented Programming in C++
- Data Structures: Arrays, Linked Lists
- Searching and Sorting Algorithms
- File Handling and Modular Programming
- Menu-driven Console Design
- Error Handling and Input Validation

---

## 🖥️ Output Preview

```
--------------------------------------
      Welcome to MartEase
--------------------------------------
1. Admin Login
2. Customer Menu
3. Exit
--------------------------------------
Enter your choice: 1
```


---

## 📚 System Modules

| Module             | Description                                            |
| ------------------ | ------------------------------------------------------ |
| `Admin Module`     | Handles adding, removing, and updating inventory items |
| `Customer Module`  | Enables browsing, adding items to cart, and purchasing |
| `Inventory System` | Maintains all product data in structured arrays        |
| `Cart System`      | Uses linked lists for item management                  |
| `Search & Sort`    | Implements linear search and bubble sort               |

---

## 🧾 Flowchart

<p align="center">
  <img width="620" height="324" alt="image" src="https://github.com/user-attachments/assets/02b47510-a3a1-4da5-9a7a-8243f7da1dfe" />
</p>

---

## 🏁 Conclusion

The MartEase Project demonstrates how core Data Structure and Algorithm concepts can be applied to build a practical retail management system.
By combining modular design, algorithmic logic, and user interactivity, MartEase provides both educational and functional value in a real-world simulation.

---

## 👤 Author

**Ahmed Hussain**  

---





