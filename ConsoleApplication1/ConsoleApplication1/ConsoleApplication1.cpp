#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
using namespace std;

// Color Set
void setConsoleColor(int textColor, int bgColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int colorAttribute = (bgColor << 4) | textColor; // Background color is in the higher nibble
	SetConsoleTextAttribute(hConsole, colorAttribute);
}

// Basic Structure Definitions

struct Item {
	int itemID;
	string name;
	double price;
	int quantity;
	string division;

	// Default constructor to ensure that values are initialized
	Item() : itemID(0), name(""), price(0.0), quantity(0), division("") {}
	Item(int id, string n, double p, int q, string div) : itemID(id), name(n), price(p), quantity(q), division(div) {}
};

struct CartItem {
	int itemID;
	int quantity;
	CartItem* next;

	CartItem() : itemID(0), quantity(0), next(nullptr) {}

	CartItem(int id, int qty) : itemID(id), quantity(qty), next(nullptr) {}
};

// Admin Functionality
class Admin {
private:
	Item inventory[100]; // Simple array for storing inventory items (size 100)
	int itemCount;

public:
	Admin() : itemCount(0) {
		// Predefine items with their details and division
		inventory[itemCount++] = Item(1, "Carrot", 0.50, 100, "Vegetables");
		inventory[itemCount++] = Item(2, "Tomato", 0.30, 150, "Vegetables");
		inventory[itemCount++] = Item(3, "Potato", 0.40, 200, "Vegetables");
		inventory[itemCount++] = Item(4, "Onion", 0.60, 120, "Vegetables");
		inventory[itemCount++] = Item(5, "Cucumber", 0.25, 90, "Vegetables");
		inventory[itemCount++] = Item(6, "Apple", 1.00, 200, "Fruits");
		inventory[itemCount++] = Item(7, "Banana", 0.80, 180, "Fruits");
		inventory[itemCount++] = Item(8, "Mango", 1.50, 80, "Fruits");
		inventory[itemCount++] = Item(9, "Grapes", 2.00, 150, "Fruits");
		inventory[itemCount++] = Item(10, "Orange", 1.20, 140, "Fruits");
		inventory[itemCount++] = Item(11, "Laptop", 1000.00, 10, "Electronics");
		inventory[itemCount++] = Item(12, "Smartphone", 500.00, 25, "Electronics");
		inventory[itemCount++] = Item(13, "Headphones", 100.00, 50, "Electronics");
		inventory[itemCount++] = Item(14, "Tablet", 350.00, 30, "Electronics");
		inventory[itemCount++] = Item(15, "Smartwatch", 150.00, 40, "Electronics");
		inventory[itemCount++] = Item(16, "Milk", 1.50, 200, "Dairy");
		inventory[itemCount++] = Item(17, "Cheese", 4.00, 100, "Dairy");
		inventory[itemCount++] = Item(18, "Yogurt", 2.50, 150, "Dairy");
		inventory[itemCount++] = Item(19, "Butter", 3.00, 80, "Dairy");
		inventory[itemCount++] = Item(20, "Eggs", 2.20, 200, "Dairy");
		inventory[itemCount++] = Item(21, "Chicken Breast", 5.00, 50, "Meat");
		inventory[itemCount++] = Item(22, "Beef Steak", 7.00, 30, "Meat");
		inventory[itemCount++] = Item(23, "Pork Chop", 6.00, 40, "Meat");
		inventory[itemCount++] = Item(24, "Sausage", 3.00, 60, "Meat");
		inventory[itemCount++] = Item(25, "Bacon", 4.50, 70, "Meat");
		inventory[itemCount++] = Item(26, "Coca Cola", 1.00, 200, "Beverages");
		inventory[itemCount++] = Item(27, "Pepsi", 0.90, 180, "Beverages");
		inventory[itemCount++] = Item(28, "Orange Juice", 2.00, 150, "Beverages");
		inventory[itemCount++] = Item(29, "Water", 0.50, 300, "Beverages");
		inventory[itemCount++] = Item(30, "Energy Drink", 2.50, 80, "Beverages");
		inventory[itemCount++] = Item(31, "Chips", 1.50, 200, "Snacks");
		inventory[itemCount++] = Item(32, "Cookies", 2.00, 100, "Snacks");
		inventory[itemCount++] = Item(33, "Chocolate Bar", 1.00, 150, "Snacks");
		inventory[itemCount++] = Item(34, "Popcorn", 1.20, 180, "Snacks");
		inventory[itemCount++] = Item(35, "Gummy Bears", 1.80, 120, "Snacks");
		inventory[itemCount++] = Item(36, "Toothpaste", 1.50, 250, "Health & Hygiene");
		inventory[itemCount++] = Item(37, "Shampoo", 3.00, 200, "Health & Hygiene");
		inventory[itemCount++] = Item(38, "Soap", 0.80, 300, "Health & Hygiene");
		inventory[itemCount++] = Item(39, "Deodorant", 2.00, 150, "Health & Hygiene");
		inventory[itemCount++] = Item(40, "Razor", 2.50, 100, "Health & Hygiene");
		inventory[itemCount++] = Item(41, "Toilet Paper", 0.60, 500, "Health & Hygiene");
		inventory[itemCount++] = Item(42, "Rice", 1.00, 200, "Grains");
		inventory[itemCount++] = Item(43, "Wheat Flour", 1.50, 300, "Grains");
		inventory[itemCount++] = Item(44, "Oats", 2.00, 100, "Grains");
		inventory[itemCount++] = Item(45, "Pasta", 1.80, 120, "Grains");
		inventory[itemCount++] = Item(46, "Bread", 1.20, 250, "Bakery");
		inventory[itemCount++] = Item(47, "Bagels", 1.50, 180, "Bakery");
		inventory[itemCount++] = Item(48, "Croissants", 2.50, 150, "Bakery");
		inventory[itemCount++] = Item(49, "Donuts", 1.80, 200, "Bakery");
		inventory[itemCount++] = Item(50, "Pizza", 4.00, 40, "Frozen Foods");
		inventory[itemCount++] = Item(51, "Frozen Vegetables", 2.00, 100, "Frozen Foods");
		inventory[itemCount++] = Item(52, "Ice Cream", 3.00, 60, "Frozen Foods");
		inventory[itemCount++] = Item(53, "Frozen Pizza", 5.00, 50, "Frozen Foods");
		inventory[itemCount++] = Item(54, "Fish Fillets", 6.00, 80, "Seafood");
		inventory[itemCount++] = Item(55, "Shrimp", 8.00, 70, "Seafood");
		inventory[itemCount++] = Item(56, "Salmon", 9.00, 40, "Seafood");
		inventory[itemCount++] = Item(57, "Tuna", 7.00, 50, "Seafood");
		inventory[itemCount++] = Item(58, "Cat Food", 2.00, 100, "Pet Supplies");
		inventory[itemCount++] = Item(59, "Dog Food", 2.50, 120, "Pet Supplies");
		inventory[itemCount++] = Item(60, "Fish Food", 1.50, 80, "Pet Supplies");
		inventory[itemCount++] = Item(61, "Bird Seed", 1.00, 150, "Pet Supplies");
		inventory[itemCount++] = Item(62, "Lawn Mower", 150.00, 15, "Garden Supplies");
		inventory[itemCount++] = Item(63, "Shovel", 20.00, 40, "Garden Supplies");
		inventory[itemCount++] = Item(64, "Fertilizer", 10.00, 50, "Garden Supplies");
		inventory[itemCount++] = Item(65, "Gardening Gloves", 5.00, 100, "Garden Supplies");
		inventory[itemCount++] = Item(66, "Air Freshener", 3.00, 150, "Home Supplies");
		inventory[itemCount++] = Item(67, "Cleaning Spray", 2.50, 200, "Home Supplies");
		inventory[itemCount++] = Item(68, "Broom", 4.00, 180, "Home Supplies");
		inventory[itemCount++] = Item(69, "Mop", 5.00, 100, "Home Supplies");
		inventory[itemCount++] = Item(70, "Trash Bags", 1.00, 250, "Home Supplies");
		inventory[itemCount++] = Item(71, "Sunglasses", 10.00, 50, "Accessories");
		inventory[itemCount++] = Item(72, "Wristwatch", 30.00, 75, "Accessories");
		inventory[itemCount++] = Item(73, "Backpack", 25.00, 100, "Accessories");
		inventory[itemCount++] = Item(74, "Wallet", 15.00, 120, "Accessories");
		inventory[itemCount++] = Item(75, "Umbrella", 5.00, 150, "Accessories");
		inventory[itemCount++] = Item(76, "T-shirt", 10.00, 200, "Clothing");
		inventory[itemCount++] = Item(77, "Jeans", 20.00, 150, "Clothing");
		inventory[itemCount++] = Item(78, "Jacket", 40.00, 80, "Clothing");
		inventory[itemCount++] = Item(79, "Sneakers", 30.00, 60, "Clothing");
		inventory[itemCount++] = Item(80, "Hat", 12.00, 100, "Clothing");

	}

	// Getter functions
	Item* getInventory() {
		return inventory;
	}

	int getItemCount() const {
		return itemCount;
	}

	void addItemToInventory(int id, const string& name, double price, int quantity, const string& division) {
		for (int i = 0; i < itemCount; i++) {
			if (inventory[i].itemID == id) {
				cout << "Item ID already exists." << endl;
				return;
			}
		}
		inventory[itemCount++] = Item(id, name, price, quantity, division); // Using the parameterized constructor
		cout << "Item added successfully." << endl;
	}

	void removeItemFromInventory(int id) {
		for (int i = 0; i < itemCount; i++) {
			if (inventory[i].itemID == id) {
				for (int j = i; j < itemCount - 1; j++) {
					inventory[j] = inventory[j + 1];
				}
				itemCount--;
				cout << "Item removed successfully." << endl;
				return;
			}
		}
		cout << "Item not found." << endl;
	}

	void updateItemInInventory(int id, const string& name, double price, int quantity, const string& division) {
		for (int i = 0; i < itemCount; i++) {
			if (inventory[i].itemID == id) {
				inventory[i].name = name;
				inventory[i].price = price;
				inventory[i].quantity = quantity;
				inventory[i].division = division;
				cout << "Item updated successfully." << endl;
				return;
			}
		}
		cout << "Item not found." << endl;
	}

	void viewInventory() {
		cout << "\n----- INVENTORY -----\n";
		cout << left << setw(10) << "Item ID" << setw(30) << "Name" << setw(12) << "Price" << setw(12) << "Quantity" << setw(15) << "Division" << endl;
		cout << "-------------------------------------------------------------\n";
		for (int i = 0; i < itemCount; i++) {
			cout << left << setw(10) << inventory[i].itemID
				<< setw(30) << inventory[i].name
				<< setw(12) << fixed << setprecision(2) << inventory[i].price
				<< setw(12) << inventory[i].quantity
				<< setw(15) << inventory[i].division << endl;
		}
		cout << "-------------------------------------------------------------\n";
	}

	void displayDivisions() {
		cout << "Select Division:\n";
		cout << "1. Vegetables\n";
		cout << "2. Fruits\n";
		cout << "3. Electronics\n";
		cout << "4. Dairy\n";
		cout << "5. Meat\n";
		cout << "6. Beverages\n";
		cout << "7. Snacks\n";
		cout << "8. Health & Hygiene\n";
		cout << "9. Grains\n";
		cout << "10. Bakery\n";
		cout << "11. Frozen Foods\n";
		cout << "12. Seafood\n";
		cout << "13. Pet Supplies\n";
		cout << "14. Garden Supplies\n";
		cout << "15. Home Supplies\n";
		cout << "16. Accessories\n";
		cout << "17. Clothing\n";
		cout << "Enter choice: ";

	}

	void viewItemsInDivision(const string& division) {
		cout << "\n----- " << division << " ITEMS -----\n";
		cout << left << setw(10) << "Item ID" << setw(30) << "Name" << setw(12) << "Price" << setw(12) << "Quantity" << endl;
		cout << "-------------------------------------------------------------\n";
		bool found = false;
		for (int i = 0; i < itemCount; i++) {
			if (inventory[i].division == division) {
				found = true;
				cout << left << setw(10) << inventory[i].itemID
					<< setw(30) << inventory[i].name
					<< setw(12) << fixed << setprecision(2) << inventory[i].price
					<< setw(12) << inventory[i].quantity << endl;
			}
		}
		if (!found) {
			cout << "No items available in this division." << endl;
		}
		cout << "-------------------------------------------------------------\n";
	}

	bool adminLogin() {
		string username, password;
		cout << "Enter Admin Username: ";
		cin >> username;
		cout << "Enter Admin Password: ";
		cin >> password;
		// Simple admin credentials check
		if (username == "ahmed" && password == "4321") {
			return true;
		}
		cout << "Invalid credentials. Try again.\n";
		return false;
	}
};

// Customer Functionality
class Customer {
public:
	CartItem* cart;
	Admin* admin;

public:
	Customer(Admin* adminRef) : admin(adminRef), cart(nullptr) {}

	void browseItems() {
		int choice;
		admin->displayDivisions();
		cin >> choice;
		switch (choice) {
		case 1:
			admin->viewItemsInDivision("Vegetables");
			break;
		case 2:
			admin->viewItemsInDivision("Fruits");
			break;
		case 3:
			admin->viewItemsInDivision("Electronics");
			break;
		case 4:
			admin->viewItemsInDivision("Dairy");
			break;
		case 5:
			admin->viewItemsInDivision("Meat");
			break;
		case 6:
			admin->viewItemsInDivision("Beverages");
			break;
		case 7:
			admin->viewItemsInDivision("Snacks");
			break;
		case 8:
			admin->viewItemsInDivision("Health & Hygiene");
			break;
		case 9:
			admin->viewItemsInDivision("Grains");
			break;
		case 10:
			admin->viewItemsInDivision("Bakery");
			break;
		case 11:
			admin->viewItemsInDivision("Frozen Foods");
			break;
		case 12:
			admin->viewItemsInDivision("Seafood");
			break;
		case 13:
			admin->viewItemsInDivision("Pet Supplies");
			break;
		case 14:
			admin->viewItemsInDivision("Garden Supplies");
			break;
		case 15:
			admin->viewItemsInDivision("Home Supplies");
			break;
		case 16:
			admin->viewItemsInDivision("Accessories");
			break;
		case 17:
			admin->viewItemsInDivision("Clothing");
			break;
		default:
			cout << "Invalid choice.\n";
		}

	}

	void searchItem(int id) {
		Item* inventory = admin->getInventory();
		for (int i = 0; i < admin->getItemCount(); i++) {
			if (inventory[i].itemID == id) {
				cout << "\n----- ITEM FOUND -----\n";
				cout << left << setw(10) << "Item ID" << setw(30) << "Name" << setw(12) << "Price" << setw(12) << "Quantity" << endl;
				cout << "-------------------------------------------------------------\n";
				cout << left << setw(10) << inventory[i].itemID
					<< setw(30) << inventory[i].name
					<< setw(12) << fixed << setprecision(2) << inventory[i].price
					<< setw(12) << inventory[i].quantity << endl;
				cout << "-------------------------------------------------------------\n";
				return;
			}
		}
		cout << "Item not found." << endl;
	}

	void addItemToCart(int id, int quantity) {
		Item* inventory = admin->getInventory();
		for (int i = 0; i < admin->getItemCount(); i++) {
			if (inventory[i].itemID == id) {
				if (inventory[i].quantity < quantity) {
					cout << "Not enough stock available." << endl;
					return;
				}
				CartItem* newCartItem = new CartItem(id, quantity);
				newCartItem->next = cart;
				cart = newCartItem;
				cout << "Item added to cart." << endl;
				return;
			}
		}
		cout << "Item not found." << endl;
	}

	void viewCart() {
		if (cart == nullptr) {
			cout << "Your cart is empty.\n";
			return;
		}

		//counitng hogi items in array
		int itemCount = 0;
		CartItem* current = cart;
		while (current != nullptr) {
			itemCount++;
			current = current->next;
		}

		CartItem* cartItems = new CartItem[itemCount];
		current = cart;
		for (int i = 0; i < itemCount; i++) {
			cartItems[i] = *current;
			current = current->next;
		}

		//idher ive used bubble sort
		for (int i = 0; i < itemCount - 1; i++) {
			for (int j = 0; j < itemCount - i - 1; j++) {
				if (cartItems[j].quantity < cartItems[j + 1].quantity) {
					CartItem temp = cartItems[j];
					cartItems[j] = cartItems[j + 1];
					cartItems[j + 1] = temp;
				}
			}
		}
		Item* inventory = admin->getInventory();
		cout << "\n----- CART -----\n";
		cout << left << setw(10) << "Item ID" << setw(30) << "Name" << setw(12) << "Quantity" << endl;
		cout << "-------------------------------------------------------------\n";
		for (int i = 0; i < itemCount; i++) {
			for (int j = 0; j < admin->getItemCount(); j++) {
				if (inventory[j].itemID == cartItems[i].itemID) {
					cout << left << setw(10) << inventory[j].itemID
						<< setw(30) << inventory[j].name
						<< setw(12) << cartItems[i].quantity << endl;
					break;
				}
			}
		}
		cout << "-------------------------------------------------------------\n";

		//not necessary but helps in memory allocation.
		delete[] cartItems;
	}


	void checkout() {
		double total = 0;
		CartItem* current = cart;
		while (current != nullptr) {
			Item* inventory = admin->getInventory();
			for (int i = 0; i < admin->getItemCount(); i++) {
				if (inventory[i].itemID == current->itemID) {
					total += inventory[i].price * current->quantity;
					break;
				}
			}
			current = current->next;
		}
		double tax = total * 0.05;
		double finalTotal = total + tax;
		cout << "\n----- CHECKOUT -----\n";
		cout << "Total: " << fixed << setprecision(2) << total << endl;
		cout << "Tax (5%): " << fixed << setprecision(2) << tax << endl;
		cout << "Final Total: " << fixed << setprecision(2) << finalTotal << endl;
		cout << "-------------------------------------------------------------\n";
	}

	void processPayment() {
		// Clear the cart after payment
		CartItem* current = cart;
		while (current != nullptr) {
			CartItem* temp = current;
			current = current->next;
			delete temp; // Delete each item in the cart to prevent memory leaks
		}
		cart = nullptr; // Reset the cart to null as it's now empty
		cout << "Payment processed successfully.\n";
	}
};

// Main Program

int main() {
	setConsoleColor(3, 0);
	system("cls");
	Admin admin;
	Customer customer(&admin);
	int choice, itemID, quantity;
	double price;
	string name;

	cout << "\t\t\t *************************\n";
	cout << "\t\t\t * *\n";
	cout << "\t\t\t * Welcome to MartEase! *\n";
	cout << "\t\t\t * *\n";
	cout << "\t\t\t *************************\n";
	cout << endl;

	while (true) {
		cout << "\n";
		cout << "\t\t\t\t\t ============================\n";
		cout << "\t\t\t\t\t MartEase Menu\n";
		cout << "\t\t\t\t\t ============================\n";
		cout << "\t\t\t\t\t 1. Admin Login\n";
		cout << "\t\t\t\t\t 2. Customer Functions\n";
		cout << "\t\t\t\t\t 0. Exit\n";
		cout << "\t\t\t\t\t Enter choice: ";
		cin >> choice;

		if (choice == 1) {
			if (admin.adminLogin()) {
				int adminChoice;
				while (true) {
					cout << "\n--- Admin Menu ---\n";
					cout << "1. View Inventory\n";
					cout << "2. Add Item\n";
					cout << "3. Remove Item\n";
					cout << "4. Update Item\n";
					cout << "5. Dev Menu\n";
					cout << "0. Log out\n";
					cout << "Enter choice: ";
					cin >> adminChoice;

					if (adminChoice == 1) {
						admin.viewInventory();
					}
					else if (adminChoice == 2) {
						cout << "Enter item ID: ";
						cin >> itemID;
						cout << "Enter item name: ";
						cin.ignore(); // To discard newline
						getline(cin, name);
						cout << "Enter item price: ";
						cin >> price;
						cout << "Enter item quantity: ";
						cin >> quantity;
						admin.addItemToInventory(itemID, name, price, quantity, "Electronics"); // Or other divisions
					}
					else if (adminChoice == 3) {
						cout << "Enter item ID to remove: ";
						cin >> itemID;
						admin.removeItemFromInventory(itemID);
					}
					else if (adminChoice == 4) {
						cout << "Enter item ID to update: ";
						cin >> itemID;
						cout << "Enter new item name: ";
						cin.ignore(); // To discard newline
						getline(cin, name);
						cout << "Enter new item price: ";
						cin >> price;
						cout << "Enter new item quantity: ";
						cin >> quantity;
						admin.updateItemInInventory(itemID, name, price, quantity, "Electronics"); // Or other divisions
					}
					else if (adminChoice == 5) {
						cout << "Project Created By: \nAhmed Hussain \nArham Khan \nAnas Wahab" << endl;
					}
					else if (adminChoice == 0) {
						break;
					}
					else {
						cout << "Invalid choice.\n";
					}
				}
			}
		}
		else if (choice == 2) {
			while (true) {
				cout << "\n--- Customer Menu ---\n";
				cout << "1. Browse Items\n";
				cout << "2. Search Item\n";
				cout << "3. Add Item to Cart\n";
				cout << "4. View Cart\n";
				cout << "5. Checkout\n";
				cout << "6. Process Payment\n";
				cout << "0. Exit\n";
				cout << "Enter choice: ";
				cin >> choice;

				if (choice == 1) {
					customer.browseItems();
				}
				else if (choice == 2) {
					cout << "Enter item ID to search: ";
					cin >> itemID;
					customer.searchItem(itemID);
				}
				else if (choice == 3) {
					cout << "Enter item ID to add to cart: ";
					cin >> itemID;
					cout << "Enter quantity: ";
					cin >> quantity;
					customer.addItemToCart(itemID, quantity);
				}
				else if (choice == 4) {
					customer.viewCart();
				}
				else if (choice == 5) {
					customer.checkout();
				}
				else if (choice == 6) {
					customer.processPayment();
				}
				else if (choice == 0) {
					break;
				}
				else {
					cout << "Invalid choice.\n";
				}
			}
		}
		else if (choice == 0) {
			cout << "\n Thank you for visiting MartEase!! Hope To See You Again In Future <3\n";
			break;
		}
		else {
			cout << "Invalid choice.\n";
		}
	}

	return 0;
}

