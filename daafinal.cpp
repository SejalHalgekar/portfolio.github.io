#include <iostream>// To use input and output functionalities (cin, cout)
#include <string>// To use string type
#include <vector> // To use the vector container (dynamic array)
#include <queue>  // To use the queue container (FIFO)
#include <fstream> // To handle file I/O (read/write to files)
#include <sstream>// To use string streams (for converting between strings and other types)
// For input/output manipulations (e.g., setting precision)
#include <iomanip>
 // For working with dates and times
#include <ctime>
 // To use hash maps (unordered associative containers)
#include <unordered_map>
 // To use map containers (ordered associative containers)
#include <map>
// To use double-ended queue (deque)
#include <deque>
// To use algorithms like sort, etc.
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <set>
#include <utility>
using namespace std;
// Define the structure of a food item node
//create node for food
//string foodName
//  quantity;
// price;
// serial;

struct FoodNode
{
    string foodName;
    int quantity;
    float price;
    int serial;
    FoodNode* next;


    FoodNode(int serial, const string& foodName, int quantity, float price)


        : serial(serial), foodName(foodName), quantity(quantity), price(price), next(nullptr) {}
};

    // Constructor to initialize a FoodNode object

class FoodManagementSystem
 {
private:

    FoodNode* head;

    float totalMoney;

    string username;

    string password;

    deque<string> orderQueue;

    unordered_map<string, vector<string>> customers;


public:

    //hoiding food managment system

    //FoodManagementSystem() : head, totalMoney

    FoodManagementSystem() : head(nullptr), totalMoney(0) {}




void foodinsert(int serial, const string& foodName, int quantity, float price)
{ cout << "Executing dummy function 1\n";

        FoodNode* newNode = new FoodNode(serial, foodName, quantity, price);

        if (!head)



        {


            head = newNode;

        }

         else


        {


            FoodNode* temp = head;

            while (temp->next)



            {

                temp = temp->next;

            }

            temp->next = newNode;
        }
}

// Function to delete a food item by serial number

    void deletFoo(int serial)

     {

        if (!head)

            {
 // If the head matches the serial, delete the head node

            cout << "Food list is empty.\n";


            return;

        }



        if (head->serial == serial)

            {

            FoodNode* temp = head;

            head = head->next;


            delete temp;

            cout << "Food item deleted successfully.\n";

            return;

        }

    // Function to update food quantity by serial number


        FoodNode* temp = head;

        while (temp->next && temp->next->serial != serial)


            {

            temp = temp->next;

        }



        if (temp->next && temp->next->serial == serial)

            {

            FoodNode* toDelete = temp->next;

            temp->next = temp->next->next;


            delete toDelete;

            cout << "Food item deleted successfully.\n";

        }

        else

            {


            cout << "Food item not found.\n";

        }
    }
   // Function to update food quantity by serial number

    void updatFoo(int serial, int newQuantity)

     {

        FoodNode* temp = head;

        while (temp && temp->serial != serial)


            {

            temp = temp->next;

        }

 // Update the quantity

        if (temp)

            {

            temp->quantity = newQuantity;

            cout << "Food quantity updated successfully.\n";

        }

        else

            {

            cout << "Food item not found.\n";

        }
    }

  // Function to place an order for a food item

    void plaeOrde(int serial, int orderQuantity)

     {

        FoodNode* temp = head;
        while (temp && temp->serial != serial)


            {

            temp = temp->next;

        }



        if (!temp)

            {

            cout << "Food item not found.\n";

            return;

        }

// Update the quantity after order

        if (orderQuantity > temp->quantity)
            {

            cout << "Not enough stock available.\n";


            return;

        }


  // Add order to queue

        temp->quantity -= orderQuantity;

        totalMoney += temp->price * orderQuantity;


        orderQueue.push_back(temp->foodName + " x" + to_string(orderQuantity));



        cout << "Order placed successfully. Total Price: $"
             << fixed << setprecision(2) << temp->price * orderQuantity << "\n";
    }



    // Function to display the total money earned today

    void displaTotalCas()


     {

        cout << "Total Cash Today: $" << fixed << setprecision(2) << totalMoney << "\n";

    }

     // Function to display the list of all food items

    void displFoodLis()

    {

        cout << "Food List:\n";
        FoodNode* temp = head;


        while (temp)

            {

            cout << temp->serial << " - " << temp->foodName << " - "

                 << temp->quantity << " - $" << fixed << setprecision(2) << temp->price << "\n";

            temp = temp->next;

        }


    }

   // Function to search food by name

    void searchFoodBNam(const string& name)

    {

        bool found = false;

        FoodNode* temp = head;
    // Function to sort the food list by price

        while (temp)

            {

            if (temp->foodName == name)

            {
                cout << "Found: " << temp->serial << " - " << temp->foodName << " - "


                     << temp->quantity << " - $" << fixed << setprecision(2) << temp->price << "\n";

                found = true;

                break;

            }

            temp = temp->next;


        }

        if (!found)

        {

            cout << "Food item with name " << name << " not found.\n";

        }
    }


 void sortFoodBPric(bool ascending = true)

     {

        vector<FoodNode*> foodList;

        FoodNode* temp = head;

        while (temp)


            {
            foodList.push_back(temp);


            temp = temp->next;

        }



        if (ascending)


            {


            sort(foodList.begin(), foodList.end(), [](FoodNode* a, FoodNode* b) {

                return a->price < b->price;
            });


        }

        else
            {


            sort(foodList.begin(), foodList.end(), [](FoodNode* a, FoodNode* b) {

                return a->price > b->price;

            });

        }




        cout << "Food List Sorted by Price:\n";

        for (auto& node : foodList)

            {


            cout << node->serial << " - " << node->foodName << " - "

                 << node->quantity << " - $" << fixed << setprecision(2) << node->price << "\n";


        }
    }


   // Function to log in with the username and password

    bool logi(const string& user, const string& pass)
     {


        return (user == username && pass == password);

    }


   // Function to create a new account (sign up)

    void signU()

    {

        string newUsername, newPassword;


        cout << "Enter new username: ";

        cin >> newUsername;

        cout << "Enter new password: ";

        cin >> newPassword;

        username = newUsername;

        password = newPassword;

        cout << "Account created successfully.\n";

    }
    // Function to exit the program


    void exitProgra()


    {

        cout << "Exiting Food Management System...\n";


    }

    // Function to back up food data to a file


    void backuDat()

    {

        string fileName = "backup.txt";

        ofstream outFile(fileName);
        if (!outFile)

            {

            cout << "Error creating backup file.\n";


            return;

        }




        outFile << "Total Cash Today: $" << fixed << setprecision(2) << totalMoney << "\n";

        outFile << "Food List:\n";


        FoodNode* temp = head;

        while (temp)

            {

            outFile << temp->serial << " - " << temp->foodName << " - "

                    << temp->quantity << " - $" << fixed << setprecision(2) << temp->price << "\n";

            temp = temp->next;

        }




        cout << "Backup created successfully.\n";
    }



    // Function to view the orders queue



    //creating  function for inserting food

    void insertFood(int serial, const string& foodName, int quantity, float price)

     {
// Create a new food
        FoodNode* newNode = new FoodNode(serial, foodName, quantity, price);

        if (!head)

 // If the list is empty, set head to new nodenode

        {


            head = newNode;

        }

         else

 // Otherwise, traverse to the end and insert
        {



            FoodNode* temp = head;

            while (temp->next)



            {

                temp = temp->next;

            }

            temp->next = newNode;
        }

    }

// Constructor to initialize the system

 // Function to delete a food item by serial number

    void deleteFood(int serial)

     {

        if (!head)

            {
 // If the head matches the serial, delete the head node

            cout << "Food list is empty.\n";


            return;

        }



        if (head->serial == serial)

            {

            FoodNode* temp = head;

            head = head->next;


            delete temp;

            cout << "Food item deleted successfully.\n";

            return;

        }

    // Function to update food quantity by serial number


        FoodNode* temp = head;

        while (temp->next && temp->next->serial != serial)


            {

            temp = temp->next;

        }



        if (temp->next && temp->next->serial == serial)

            {

            FoodNode* toDelete = temp->next;

            temp->next = temp->next->next;


            delete toDelete;

            cout << "Food item deleted successfully.\n";

        }

        else

            {


            cout << "Food item not found.\n";

        }
    }



    // Function to update food quantity by serial number

    void updateFood(int serial, int newQuantity)

     {

        FoodNode* temp = head;

        while (temp && temp->serial != serial)


            {

            temp = temp->next;

        }

 // Update the quantity

        if (temp)

            {

            temp->quantity = newQuantity;

            cout << "Food quantity updated successfully.\n";

        }

        else

            {

            cout << "Food item not found.\n";

        }
    }




    // Function to place an order for a food item

    void placeOrder(int serial, int orderQuantity)

     {

        FoodNode* temp = head;
        while (temp && temp->serial != serial)


            {

            temp = temp->next;

        }



        if (!temp)

            {

            cout << "Food item not found.\n";

            return;

        }

// Update the quantity after order

        if (orderQuantity > temp->quantity)
            {

            cout << "Not enough stock available.\n";


            return;

        }


  // Add order to queue

        temp->quantity -= orderQuantity;

        totalMoney += temp->price * orderQuantity;


        orderQueue.push_back(temp->foodName + " x" + to_string(orderQuantity));



        cout << "Order placed successfully. Total Price: $"
             << fixed << setprecision(2) << temp->price * orderQuantity << "\n";
    }



    // Function to display the total money earned today

    void displayTotalCash()


     {

        cout << "Total Cash Today: $" << fixed << setprecision(2) << totalMoney << "\n";

    }

    // Function to display the list of all food items

    void displayFoodList()

    {

        cout << "Food List:\n";
        FoodNode* temp = head;


        while (temp)

            {

            cout << temp->serial << " - " << temp->foodName << " - "

                 << temp->quantity << " - $" << fixed << setprecision(2) << temp->price << "\n";

            temp = temp->next;

        }


    }


    // Function to search food by name

    void searchFoodByName(const string& name)

    {

        bool found = false;

        FoodNode* temp = head;
    // Function to sort the food list by price

        while (temp)

            {

            if (temp->foodName == name)

            {
                cout << "Found: " << temp->serial << " - " << temp->foodName << " - "


                     << temp->quantity << " - $" << fixed << setprecision(2) << temp->price << "\n";

                found = true;

                break;

            }

            temp = temp->next;


        }

        if (!found)

        {

            cout << "Food item with name " << name << " not found.\n";

        }
    }




    void sortFoodByPrice(bool ascending = true)

     {

        vector<FoodNode*> foodList;

        FoodNode* temp = head;

        while (temp)


            {
            foodList.push_back(temp);


            temp = temp->next;

        }



        if (ascending)


            {


            sort(foodList.begin(), foodList.end(), [](FoodNode* a, FoodNode* b) {

                return a->price < b->price;
            });


        }

        else
            {


            sort(foodList.begin(), foodList.end(), [](FoodNode* a, FoodNode* b) {

                return a->price > b->price;

            });

        }




        cout << "Food List Sorted by Price:\n";

        for (auto& node : foodList)

            {


            cout << node->serial << " - " << node->foodName << " - "

                 << node->quantity << " - $" << fixed << setprecision(2) << node->price << "\n";


        }
    }





    // Function to log in with the username and password

    bool login(const string& user, const string& pass)
     {


        return (user == username && pass == password);

    }


    // Function to create a new account (sign up)

    void signUp()

    {

        string newUsername, newPassword;


        cout << "Enter new username: ";

        cin >> newUsername;

        cout << "Enter new password: ";

        cin >> newPassword;

        username = newUsername;

        password = newPassword;

        cout << "Account created successfully.\n";

    }

    // Function to sign in with existing username and password

    void signIn()


     {

        string userInputUser, userInputPass;

        bool validUser = false;


        while (!validUser)
            {


            cout << "Enter username: ";

            cin >> userInputUser;

            cout << "Enter password: ";

            cin >> userInputPass;



            if (login(userInputUser, userInputPass))


                {

                validUser = true;

            }

            else

                {

                cout << "Invalid username or password. Try again.\n";

            }
        }


    }


    // Function to exit the program


void exitProgram() {
    cout << "Exiting Food Management System...\n";
    system("exit");  // or use exit(0)
}


    // Function to back up food data to a file


    void backupData()

    {

        string fileName = "backup.txt";

        ofstream outFile(fileName);
        if (!outFile)

            {

            cout << "Error creating backup file.\n";


            return;

        }





        outFile << "Total Cash Today: $" << fixed << setprecision(2) << totalMoney << "\n";
        outFile << "Food List:\n";


        FoodNode* temp = head;
        while (temp)

            {

            outFile << temp->serial << " - " << temp->foodName << " - "

                    << temp->quantity << " - $" << fixed << setprecision(2) << temp->price << "\n";

            temp = temp->next;

        }




        cout << "Backup created successfully.\n";
    }



    // Function to view the orders queue


    void viewOrdersQueue()

     {

        cout << "Orders Queue:\n";
        for (const auto& order : orderQueue)


            {
            cout << order << "\n";


        }

    }

    // Function to requeue the first order (move it to the end of the queue)

    void requeue()


     {

        if (!orderQueue.empty())

            {

            string order = orderQueue.front();

            orderQueue.pop_front();


            orderQueue.push_back(order);

            cout << "Order requeued: " << order << "\n";

        }

        else

            {

            cout << "No orders in the queue to requeue.\n";

        }

    }


    // Function to manage customer orders


    void customerManagement()

     {


        string customerName;

        cout << "Enter customer name: ";

        cin >> customerName;



        if (customers.find(customerName) == customers.end())


            {

            customers[customerName] = vector<string>();

            cout << "New customer created.\n";
        }




        cout << "Customer Orders:\n";

        for (const auto& order : customers[customerName])

            {

            cout << order << "\n";
        }


    // Destructor to clean up the memory


        string foodName;

        int quantity;

        cout << "Enter food name to order: ";

        cin >> foodName;

        cout << "Enter quantity: ";


        cin >> quantity;



        customers[customerName].push_back(foodName + " x" + to_string(quantity));

        cout << "Order added for customer: " << customerName << "\n";
    }

    // Destructor to clean up the memory



    ~FoodManagementSystem()

    {

        while (head)
            {

            FoodNode* temp = head;

            head = head->next;

            delete temp;

        }

    }



    // Function to display the title
    void displayTitle()

     {

        cout << "Food Management System\n";


    }

    //creating  function for inserting food

    void instFood(int serial, const string& foodName, int quantity, float price)

     {
// Create a new food
        FoodNode* newNode = new FoodNode(serial, foodName, quantity, price);

        if (!head)

 // If the list is empty, set head to new nodenode

        {


            head = newNode;

        }

         else

 // Otherwise, traverse to the end and insert
        {



            FoodNode* temp = head;

            while (temp->next)



            {

                temp = temp->next;

            }

            temp->next = newNode;
        }

    }

// Constructor to initialize the system

 // Function to delete a food item by serial number

    void deletfood(int serial)

     {

        if (!head)

            {
 // If the head matches the serial, delete the head node

            cout << "Food list is empty.\n";


            return;

        }



        if (head->serial == serial)

            {

            FoodNode* temp = head;

            head = head->next;


            delete temp;

            cout << "Food item deleted successfully.\n";

            return;

        }

    // Function to update food quantity by serial number


        FoodNode* temp = head;

        while (temp->next && temp->next->serial != serial)


            {

            temp = temp->next;

        }



        if (temp->next && temp->next->serial == serial)

            {

            FoodNode* toDelete = temp->next;

            temp->next = temp->next->next;


            delete toDelete;

            cout << "Food item deleted successfully.\n";

        }

        else

            {


            cout << "Food item not found.\n";

        }
    }



    // Function to update food quantity by serial number

    void uateFood(int serial, int newQuantity)

     {

        FoodNode* temp = head;

        while (temp && temp->serial != serial)


            {

            temp = temp->next;

        }

 // Update the quantity

        if (temp)

            {

            temp->quantity = newQuantity;

            cout << "Food quantity updated successfully.\n";

        }

        else

            {

            cout << "Food item not found.\n";

        }
    }




    // Function to place an order for a food item

    void pleOrder(int serial, int orderQuantity)

     {

        FoodNode* temp = head;
        while (temp && temp->serial != serial)


            {

            temp = temp->next;

        }



        if (!temp)

            {

            cout << "Food item not found.\n";

            return;

        }

// Update the quantity after order

        if (orderQuantity > temp->quantity)
            {

            cout << "Not enough stock available.\n";


            return;

        }


  // Add order to queue

        temp->quantity -= orderQuantity;

        totalMoney += temp->price * orderQuantity;


        orderQueue.push_back(temp->foodName + " x" + to_string(orderQuantity));



        cout << "Order placed successfully. Total Price: $"
             << fixed << setprecision(2) << temp->price * orderQuantity << "\n";
    }



    // Function to display the total money earned today

    void dilayTotalCash()


     {

        cout << "Total Cash Today: $" << fixed << setprecision(2) << totalMoney << "\n";

    }

    // Function to display the list of all food items

    void displayFoodList1()

    {

        cout << "Food List:\n";
        FoodNode* temp = head;


        while (temp)

            {

            cout << temp->serial << " - " << temp->foodName << " - "

                 << temp->quantity << " - $" << fixed << setprecision(2) << temp->price << "\n";

            temp = temp->next;

        }


    }


    // Function to search food by name

    void searchFoodByName1(const string& name)

    {

        bool found = false;

        FoodNode* temp = head;
    // Function to sort the food list by price

        while (temp)

            {

            if (temp->foodName == name)

            {
                cout << "Found: " << temp->serial << " - " << temp->foodName << " - "


                     << temp->quantity << " - $" << fixed << setprecision(2) << temp->price << "\n";

                found = true;

                break;

            }

            temp = temp->next;


        }

        if (!found)

        {

            cout << "Food item with name " << name << " not found.\n";

        }
    }




    void sortFoodByPrice1(bool ascending = true)

     {

        vector<FoodNode*> foodList;

        FoodNode* temp = head;

        while (temp)


            {
            foodList.push_back(temp);


            temp = temp->next;

        }



        if (ascending)


            {


            sort(foodList.begin(), foodList.end(), [](FoodNode* a, FoodNode* b) {

                return a->price < b->price;
            });


        }

        else
            {


            sort(foodList.begin(), foodList.end(), [](FoodNode* a, FoodNode* b) {

                return a->price > b->price;

            });

        }




        cout << "Food List Sorted by Price:\n";

        for (auto& node : foodList)

            {


            cout << node->serial << " - " << node->foodName << " - "

                 << node->quantity << " - $" << fixed << setprecision(2) << node->price << "\n";


        }
    }





    // Function to log in with the username and password

    bool login1(const string& user, const string& pass)
     {


        return (user == username && pass == password);

    }


    // Function to create a new account (sign up)

    void signUp1()

    {

        string newUsername, newPassword;


        cout << "Enter new username: ";

        cin >> newUsername;

        cout << "Enter new password: ";

        cin >> newPassword;

        username = newUsername;

        password = newPassword;

        cout << "Account created successfully.\n";

    }

    // Function to sign in with existing username and password

    void signIn1()


     {

        string userInputUser, userInputPass;

        bool validUser = false;


        while (!validUser)
            {


            cout << "Enter username: ";

            cin >> userInputUser;

            cout << "Enter password: ";

            cin >> userInputPass;



            if (login(userInputUser, userInputPass))


                {

                validUser = true;

            }

            else

                {

                cout << "Invalid username or password. Try again.\n";

            }
        }


    }


    // Function to exit the program


    void exitProgram1()


    {

        cout << "Exiting Food Management System...\n";


    }

    // Function to back up food data to a file


    void backupData1()

    {

        string fileName = "backup.txt";

        ofstream outFile(fileName);
        if (!outFile)

            {

            cout << "Error creating backup file.\n";


            return;

        }





        outFile << "Total Cash Today: $" << fixed << setprecision(2) << totalMoney << "\n";
        outFile << "Food List:\n";


        FoodNode* temp = head;
        while (temp)

            {

            outFile << temp->serial << " - " << temp->foodName << " - "

                    << temp->quantity << " - $" << fixed << setprecision(2) << temp->price << "\n";

            temp = temp->next;

        }




        cout << "Backup created successfully.\n";
    }



    // Function to view the orders queue


    void viewOrdersQueue1()

     {

        cout << "Orders Queue:\n";
        for (const auto& order : orderQueue)


            {
            cout << order << "\n";


        }

    }

    // Function to requeue the first order (move it to the end of the queue)

    void requeue1()


     {

        if (!orderQueue.empty())

            {

            string order = orderQueue.front();

            orderQueue.pop_front();


            orderQueue.push_back(order);

            cout << "Order requeued: " << order << "\n";

        }

        else

            {

            cout << "No orders in the queue to requeue.\n";

        }

    }


    // Function to manage customer orders


    void customerManagement1()

     {


        string customerName;

        cout << "Enter customer name: ";

        cin >> customerName;



        if (customers.find(customerName) == customers.end())


            {

            customers[customerName] = vector<string>();

            cout << "New customer created.\n";
        }




        cout << "Customer Orders:\n";

        for (const auto& order : customers[customerName])

            {

            cout << order << "\n";
        }


    // Destructor to clean up the memory


        string foodName;

        int quantity;

        cout << "Enter food name to order: ";

        cin >> foodName;

        cout << "Enter quantity: ";


        cin >> quantity;



        customers[customerName].push_back(foodName + " x" + to_string(quantity));

        cout << "Order added for customer: " << customerName << "\n";
    }

    // Destructor to clean up the memory



    FoodManagementSystem11()

    {

        while (head)
            {

            FoodNode* temp = head;

            head = head->next;

            delete temp;

        }

    }



    // Function to display the title
    void displayTitle1()

     {

        cout << "Food Management System\n";


    }

    // Function to update food quantity by serial number

    void uateFood2(int serial, int newQuantity)

     {

        FoodNode* temp = head;

        while (temp && temp->serial != serial)


            {

            temp = temp->next;

        }

 // Update the quantity

        if (temp)

            {

            temp->quantity = newQuantity;

            cout << "Food quantity updated successfully.\n";

        }

        else

            {

            cout << "Food item not found.\n";

        }
    }




    // Function to place an order for a food item

    void pleOrder2(int serial, int orderQuantity)

     {

        FoodNode* temp = head;
        while (temp && temp->serial != serial)


            {

            temp = temp->next;

        }



        if (!temp)

            {

            cout << "Food item not found.\n";

            return;

        }

// Update the quantity after order

        if (orderQuantity > temp->quantity)
            {

            cout << "Not enough stock available.\n";


            return;

        }


  // Add order to queue

        temp->quantity -= orderQuantity;

        totalMoney += temp->price * orderQuantity;


        orderQueue.push_back(temp->foodName + " x" + to_string(orderQuantity));



        cout << "Order placed successfully. Total Price: $"
             << fixed << setprecision(2) << temp->price * orderQuantity << "\n";
    }



    // Function to display the total money earned today

    void dilayTotalCash2()


     {

        cout << "Total Cash Today: $" << fixed << setprecision(2) << totalMoney << "\n";

    }

    // Function to display the list of all food items

    void displayFoodList12()

    {

        cout << "Food List:\n";
        FoodNode* temp = head;


        while (temp)

            {

            cout << temp->serial << " - " << temp->foodName << " - "

                 << temp->quantity << " - $" << fixed << setprecision(2) << temp->price << "\n";

            temp = temp->next;

        }


    }


    // Function to search food by name

    void searchFoodByName2(const string& name)

    {

        bool found = false;

        FoodNode* temp = head;
    // Function to sort the food list by price

        while (temp)

            {

            if (temp->foodName == name)

            {
                cout << "Found: " << temp->serial << " - " << temp->foodName << " - "


                     << temp->quantity << " - $" << fixed << setprecision(2) << temp->price << "\n";

                found = true;

                break;

            }

            temp = temp->next;


        }

        if (!found)

        {

            cout << "Food item with name " << name << " not found.\n";

        }
    }


    void sortFoodByPrice2(bool ascending = true)

     {

        vector<FoodNode*> foodList;

        FoodNode* temp = head;

        while (temp)


            {
            foodList.push_back(temp);


            temp = temp->next;

        }



        if (ascending)


            {


            sort(foodList.begin(), foodList.end(), [](FoodNode* a, FoodNode* b) {

                return a->price < b->price;
            });


        }

        else
            {


            sort(foodList.begin(), foodList.end(), [](FoodNode* a, FoodNode* b) {

                return a->price > b->price;

            });

        }


        cout << "Food List Sorted by Price:\n";

        for (auto& node : foodList)

            {


            cout << node->serial << " - " << node->foodName << " - "

                 << node->quantity << " - $" << fixed << setprecision(2) << node->price << "\n";


        }
    }





    // Function to log in with the username and password

    bool login2(const string& user, const string& pass)
     {


        return (user == username && pass == password);

    }


    // Function to create a new account (sign up)

    void signUp2()

    {

        string newUsername, newPassword;


        cout << "Enter new username: ";

        cin >> newUsername;

        cout << "Enter new password: ";

        cin >> newPassword;

        username = newUsername;

        password = newPassword;

        cout << "Account created successfully.\n";

    }

    // Function to sign in with existing username and password

    void signIn2()


     {

        string userInputUser, userInputPass;

        bool validUser = false;


        while (!validUser)
            {


            cout << "Enter username: ";

            cin >> userInputUser;

            cout << "Enter password: ";

            cin >> userInputPass;



            if (login(userInputUser, userInputPass))


                {

                validUser = true;

            }

            else

                {

                cout << "Invalid username or password. Try again.\n";

            }
        }


    }


    // Function to exit the program


    void exitProgram2()


    {

        cout << "Exiting Food Management System...\n";


    }

    // Function to back up food data to a file


    void backupData2()

    {

        string fileName = "backup.txt";

        ofstream outFile(fileName);
        if (!outFile)

            {

            cout << "Error creating backup file.\n";


            return;

        }





        outFile << "Total Cash Today: $" << fixed << setprecision(2) << totalMoney << "\n";
        outFile << "Food List:\n";


        FoodNode* temp = head;
        while (temp)

            {

            outFile << temp->serial << " - " << temp->foodName << " - "

                    << temp->quantity << " - $" << fixed << setprecision(2) << temp->price << "\n";

            temp = temp->next;

        }




        cout << "Backup created successfully.\n";
    }



    // Function to view the orders queue


    void viewOrdersQueue2()

     {

        cout << "Orders Queue:\n";
        for (const auto& order : orderQueue)


            {
            cout << order << "\n";


        }

    }

    // Function to requeue the first order (move it to the end of the queue)

    void requeue2()


     {

        if (!orderQueue.empty())

            {

            string order = orderQueue.front();

            orderQueue.pop_front();


            orderQueue.push_back(order);

            cout << "Order requeued: " << order << "\n";

        }

        else

            {

            cout << "No orders in the queue to requeue.\n";

        }

    }


    // Function to manage customer orders


    void customerManagement2()

     {


        string customerName;

        cout << "Enter customer name: ";

        cin >> customerName;



        if (customers.find(customerName) == customers.end())


            {

            customers[customerName] = vector<string>();

            cout << "New customer created.\n";
        }




        cout << "Customer Orders:\n";

        for (const auto& order : customers[customerName])

            {

            cout << order << "\n";
        }


    // Destructor to clean up the memory


        string foodName;

        int quantity;

        cout << "Enter food name to order: ";

        cin >> foodName;

        cout << "Enter quantity: ";


        cin >> quantity;



        customers[customerName].push_back(foodName + " x" + to_string(quantity));

        cout << "Order added for customer: " << customerName << "\n";
    }

    // Destructor to clean up the memory



    FoodManagementSystem2()

    {

        while (head)
            {

            FoodNode* temp = head;

            head = head->next;

            delete temp;

        }

    }



    // Function to display the title
    void displayTitle2()

     {

        cout << "Food Management System\n";


    }

};


//graph repesantation
// Graph class representing locations in Mumbai

class Graph


 {
private:


    unordered_map<string, unordered_map<string, int>> adjacencyList;


public:

    void addEdge(const string& src, const string& dest, int weight)

     {

        adjacencyList[src][dest] = weight;

        adjacencyList[dest][src] = weight;

    }

// Function to perform BFS traversal starting from a node
// Add unvisited neighbors to the queue


    void bfs(const string& start)
     {
// Map to track visited nodes

        cout << "BFS Traversal starting from " << start << ":\n";

        unordered_map<string, bool> visited;
  // Queue to hold the nodes for BFS

        queue<string> q;

// Add the start node to the queue
// Mark the start node as visited

        visited[start] = true;

// Mark the start node as visited

        q.push(start);



        while (!q.empty()) {

            string current = q.front();
// Print the current node

            cout << current << "\n";
// Remove the node from the queue
            q.pop();


// Add unvisited neighbors to the queue

            for (const auto& neighbor : adjacencyList[current])

             {
                if (!visited[neighbor.first])


                    {

                    visited[neighbor.first] = true;

                    q.push(neighbor.first);

                }

            }
        }

    }

    // Function to perform DFS traversal (implementation incomplete in your code)



    void dfs(const string& start)

     {

        cout << "DFS Traversal starting from " << start << ":\n";

        unordered_map<string, bool> visited;

        // DFS implementation goes here (not included)


    }

};
struct FoodItem {

    string name;
    string category;
    int expiryDays;
    double quantity;
    string location; // Location of the food item (for donation or storage)
};

struct User {
    string username;
    string password;
    string role; // "donor" or "receiver"
    string contactInfo;
};

// Global Data
vector<User> users;

vector<FoodItem> donatedFood;
vector<FoodItem> storedFood;


vector<FoodItem> requestedFood;



// Function Prototypes

void displayLine();

void signUp();

bool signIn();
void mainMenu();

void giveMenu();


void takeMenu();

void storeMenu();

void addDonatedFood();

void requestFood();
void viewDonatedFood();


void viewRequestedFood();

void viewStoredFood();


void moveToStorage();




// Utility Functions
void displayLine() {


    cout << "-------------------------------------------------";

}



// Sign-Up Function
void signUp() {


    User newUser;
    cout << "Enter username: ";


    cin >> newUser.username;

    cout << "Enter password: ";

    cin >> newUser.password;

    cout << "Enter role (donor/receiver): ";

    cin >> newUser.role;

    cout << "Enter contact information: ";

    cin.ignore();

     // To ignore the newline from previous input

    getline(cin, newUser.contactInfo);



    users.push_back(newUser);


    cout << "User registered successfully!\n";
}




// Sign-In Function

bool signIn() {

    string username, password;

    bool found = false;



    do {

        displayLine();

        cout << "\nEnter username: \n";

        cin >> username;

        cout << "\nEnter password:\n ";


        cin >> password;


        for (const auto &user : users) {

            if (user.username == username && user.password == password) {


                found = true;

                break; // Exit the loop once user is found

            }

        }



        if (!found) {

            cout << "Invalid credentials. Please try again.\n";

        }
    } while (!found);




    if (found) {

        displayLine();


        cout << "Welcome, " << username << "!\n";

    }



    return found;
}




// Main Menu

void mainMenu() {

    int choice;

    bool running = true;




    while (running) {

        displayLine();

        cout << "Main Menu:\n";

        cout << "1. Give (Donors)\n";


        cout << "2. Take (Receivers)\n";

        cout << "3. Store\n";

        cout << "4. Exit\n";


        cout << "Enter your choice: ";

        cin >> choice;


        switch (choice) {


            case 1:

                giveMenu();

                break;

            case 2:

                takeMenu();

                break;

            case 3:

                storeMenu();

                break;

            case 4:

                running = false;

                cout << "Thank you for using Smart Food Management System. Goodbye!\n";

                break;

            default:


                cout << "Invalid choice. Try again.\n";

        }
    }

}




// Givers Menu (Donors)

void giveMenu() {

    int choice;


    bool running = true;



    while (running) {

        displayLine();

        cout << "Give Menu:\n";

        cout << "1. Add Food for Donation\n";

        cout << "2. View Donated Food\n";


        cout << "3. Move Food to Storage\n";

        cout << "4. Back to Main Menu\n";

        cout << "Enter your choice: ";

        cin >> choice;



        switch (choice) {

            case 1:

                addDonatedFood();

                break;


            case 2:

                viewDonatedFood();

                break;

            case 3:

                moveToStorage();


                break;

            case 4:

                running = false;

                break;

            default:

                cout << "Invalid choice. Try again.\n";

        }
    }

}





// Add Donated Food

void addDonatedFood() {

    FoodItem item;

    cout << "Enter food name: ";

    cin >> item.name;

    cout << "Enter category (e.g., Vegetable, Dairy): ";

    cin >> item.category;




    // Input validation for expiryDays

    do {

        cout << "Enter expiry days: ";

        cin >> item.expiryDays;

        if (item.expiryDays <= 0) {

            cout << "Expiry days must be greater than zero. Please try again.\n";

        }


    } while (item.expiryDays <= 0);


    // Input validation for quantity


    do {

        cout << "Enter quantity (kg): ";

        cin >> item.quantity;

        if (item.quantity <= 0) {

            cout << "Quantity must be greater than zero. Please try again.\n";

        }

    } while (item.quantity <= 0);




    cout << "Enter location (where it can be picked up): ";
    cin.ignore();  // To clear the input buffer


    getline(cin, item.location);


    donatedFood.push_back(item);


    cout << "Food item added for donation successfully!\n";
}




// View Donated Food


void viewDonatedFood() {

    displayLine();

    if (donatedFood.empty()) {

        cout << "No donated food items available.\n";

    } else {

        cout << "Donated Food Items:\n";
        cout << left << setw(5) << "Index"

             << setw(20) << "Name"

             << setw(15) << "Category"

             << setw(12) << "Expiry Days"

             << setw(10) << "Quantity"

             << setw(20) << "Location" << "\n";

        cout << "-------------------------------------------------------------\n";

        for (size_t i = 0; i < donatedFood.size(); ++i) {

            cout << left << setw(5) << i + 1

                 << setw(20) << donatedFood[i].name

                 << setw(15) << donatedFood[i].category

                 << setw(12) << donatedFood[i].expiryDays


                 << setw(10) << donatedFood[i].quantity

                 << setw(20) << donatedFood[i].location << "\n";

        }

    }

}



// Function to move donated food to storage


void moveToStorage() {

    if (donatedFood.empty()) {

        cout << "No donated food items to move to storage.\n";

        return;

    }

    size_t index;

    displayLine();

    cout << "Enter the index of the food item to move to storage: ";

    cin >> index;




    if (index > 0 && index <= donatedFood.size()) {
        storedFood.push_back(donatedFood[index - 1]);

        donatedFood.erase(donatedFood.begin() + index - 1);
        cout << "Food item moved to storage successfully!\n";


    } else {

        cout << "Invalid index. Try again.\n";

    }
}




// Receivers Menu

void takeMenu() {

    int choice;
    bool running = true;




    while (running) {

        displayLine();

        cout << "Take Menu:\n";

        cout << "1. Request Food\n";

        cout << "2. View Requested Food\n";

        cout << "3. Back to Main Menu\n";
        cout << "Enter your choice: ";


        cin >> choice;



        switch (choice) {
            case 1:

                requestFood();

                break;
            case 2:


                viewRequestedFood();

                break;

            case 3:

                running = false;

                break;

            default:

                cout << "Invalid choice. Try again.\n";

        }

    }
}




// Request Food

void requestFood() {

    FoodItem item;

    cout << "Enter food name: ";

    cin >> item.name;


    cout << "Enter category: ";

    cin >> item.category;



    // Input validation for quantity

    do {

        cout << "Enter quantity needed (kg): ";


        cin >> item.quantity;

        if (item.quantity <= 0) {

            cout << "Quantity must be greater than zero. Please try again.\n";


        }
    } while (item.quantity <= 0);




    cout << "Enter your location: ";

    cin.ignore();  // To clear the input buffer

    getline(cin, item.location);



    requestedFood.push_back(item);

    cout << "Food request added successfully!\n";
}




// View Requested Food

void viewRequestedFood() {

    displayLine();


    if (requestedFood.empty()) {


        cout << "No food requests available.\n";

    } else {


        cout << "Requested Food Items:\n";

        for (size_t i = 0; i < requestedFood.size(); ++i) {


            cout << i + 1 << ". Name: " << requestedFood[i].name

                 << ", Category: " << requestedFood[i].category

                 << ", Quantity: " << requestedFood[i].quantity << " kg"

                 << ", Location: " << requestedFood[i].location << "\n";


        }

    }

}



// Storage Menu
void storeMenu() {

    int choice;

    bool running = true;



    while (running) {

        displayLine();

        cout << "Storage Menu:\n";

        cout << "1. View Stored Food\n";


        cout << "2. Back to Main Menu\n";

        cout << "Enter your choice: ";
        cin >> choice;




        switch (choice) {

            case 1:

                viewStoredFood();

                break;

            case 2:

                running = false;

                break;

            default:

                cout << "Invalid choice. Try again.\n";

        }
    }

}





// View Stored Food

void viewStoredFood()

{


    displayLine();
    if (storedFood.empty()) {

        cout << "No food items in storage.\n";

    } else {

        cout << "Stored Food Items:\n";


        for (size_t i = 0; i < storedFood.size(); ++i) {

            cout << i + 1 << ". Name: " << storedFood[i].name

                 << ", Category: " << storedFood[i].category

                 << ", Expiry Days: " << storedFood[i].expiryDays


                 << ", Quantity: " << storedFood[i].quantity << " kg"
                 << ", Location: " << storedFood[i].location << "\n";


        }
    }

}

struct FoodItem1 {

    string name;

    string category;
    int expiryDays;


    double quantity;

    string location; // Location of the food item (for donation or storage)

};


struct User1 {


    string username;
    string password;


    string role; // "donor" or "receiver"

    string contactInfo;

};


// Global Data
vector<User1> users1;


vector<FoodItem1> donatedFood1;

vector<FoodItem1> storedFood1;

vector<FoodItem1> requestedFood1;


// Function Prototypes


void displayLine();
void signUp();


bool signIn();

void mainMenu();

void giveMenu();

void takeMenu();

void storeMenu();

void addDonatedFood();

void requestFood();

void viewDonatedFood();

void viewRequestedFood();

void viewStoredFood();


void moveToStorage();



// Utility Functions

void displayLine1() {

    cout << "-------------------------------------------------";

}



// Sign-Up Function


void signUp1() {

    User newUser;


    cout << "Enter username: ";

    cin >> newUser.username;

    cout << "Enter password: ";

    cin >> newUser.password;

    cout << "Enter role (donor/receiver): ";

    cin >> newUser.role;

    cout << "Enter contact information: ";

    cin.ignore();  // To ignore the newline from previous input

    getline(cin, newUser.contactInfo);



    users.push_back(newUser);

    cout << "User registered successfully!\n";

}



// Sign-In Function

bool signIn1() {

    string username, password;
    bool found = false;



    do {


        displayLine();
        cout << "Enter username: ";


        cin >> username;

        cout << "Enter password: ";

        cin >> password;



        for (const auto &user : users) {

            if (user.username == username && user.password == password) {
                found = true;

                break; // Exit the loop once user is found

            }
        }




        if (!found) {

            cout << "Invalid credentials. Please try again.\n";
        }
    } while (!found);



    if (found) {

        displayLine();

        cout << "Welcome, \n" << username << "!\n";

    }



    return found;
}





// Main Menu

void mainMenu1() {

    int choice;

    bool running = true;



    while (running) {

        displayLine();

        cout << "Main Menu:\n";

        cout << "1. Give (Donors)\n";

        cout << "2. Take (Receivers)\n";

        cout << "3. Store\n";

        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;



        switch (choice) {
            case 1:

                giveMenu();


                break;

            case 2:

                takeMenu();

                break;

            case 3:
                storeMenu();


                break;

            case 4:

                running = false;
                cout << "Thank you for using Smart Food Management System. Goodbye!\n";


                break;

            default:

                cout << "Invalid choice. Try again.\n";

        }
    }

}





// Givers Menu (Donors)

void giveMenu1() {
    int choice;


    bool running = true;



    while (running) {

        displayLine();

        cout << "Give Menu:\n";
        cout << "1. Add Food for Donation\n";

        cout << "2. View Donated Food\n";


        cout << "3. Move Food to Storage\n";
        cout << "4. Back to Main Menu\n";


        cout << "Enter your choice: ";
        cin >> choice;





        switch (choice) {

            case 1:

                addDonatedFood();

                break;
            case 2:

                viewDonatedFood();

                break;
            case 3:

                moveToStorage();


                break;

            case 4:


                running = false;
                break;


            default:

                cout << "Invalid choice. Try again.\n";

        }
    }

}




// Add Donated Food

void addDonatedFood1() {


    FoodItem item;

    cout << "Enter food name: ";

    cin >> item.name;

    cout << "Enter category (e.g., Vegetable, Dairy): ";

    cin >> item.category;




    // Input validation for expiryDays
    do {

        cout << "Enter expiry days: ";

        cin >> item.expiryDays;

        if (item.expiryDays <= 0) {


            cout << "Expiry days must be greater than zero. Please try again.\n";

        }

    } while (item.expiryDays <= 0);



    // Input validation for quantity

    do {

        cout << "Enter quantity (kg): ";

        cin >> item.quantity;

        if (item.quantity <= 0) {

            cout << "Quantity must be greater than zero. Please try again.\n";
        }


    } while (item.quantity <= 0);



    cout << "Enter location (where it can be picked up): ";

    cin.ignore();  // To clear the input buffer

    getline(cin, item.location);


    donatedFood.push_back(item);


    cout << "Food item added for donation successfully!\n";
}




// View Donated Food

void viewDonatedFood1() {

    displayLine();
    if (donatedFood.empty()) {


        cout << "No donated food items available.\n";

    } else {

        cout << "Donated Food Items:\n";

        cout << left << setw(5) << "Index"
             << setw(20) << "Name"

             << setw(15) << "Category"

             << setw(12) << "Expiry Days"


             << setw(10) << "Quantity"

             << setw(20) << "Location" << "\n";

        cout << "-------------------------------------------------------------\n";

        for (size_t i = 0; i < donatedFood.size(); ++i) {
            cout << left << setw(5) << i + 1

                 << setw(20) << donatedFood[i].name
                 << setw(15) << donatedFood[i].category


                 << setw(12) << donatedFood[i].expiryDays

                 << setw(10) << donatedFood[i].quantity

                 << setw(20) << donatedFood[i].location << "\n";

        }
    }

}



// Function to move donated food to storage

void moveToStorage1() {

    if (donatedFood.empty()) {

        cout << "No donated food items to move to storage.\n";

        return;

    }

    size_t index;


    displayLine();

    cout << "Enter the index of the food item to move to storage: ";

    cin >> index;



    if (index > 0 && index <= donatedFood.size()) {

        storedFood.push_back(donatedFood[index - 1]);

        donatedFood.erase(donatedFood.begin() + index - 1);

        cout << "Food item moved to storage successfully!\n";

    } else {

        cout << "Invalid index. Try again.\n";

    }
}






// Receivers Menu

void takeMenu1() {

    int choice;

    bool running = true;



    while (running) {
        displayLine();

        cout << "Take Menu:\n";


        cout << "1. Request Food\n";
        cout << "2. View Requested Food\n";

        cout << "3. Back to Main Menu\n";


        cout << "Enter your choice: ";

        cin >> choice;




        switch (choice) {

            case 1:

                requestFood();

                break;
            case 2:


                viewRequestedFood();

                break;

            case 3:

                running = false;

                break;

            default:


                cout << "Invalid choice. Try again.\n";

        }
    }

}




// Request Food

void requestFood1() {

    FoodItem item;


    cout << "Enter food name: ";

    cin >> item.name;

    cout << "Enter category: ";


    cin >> item.category;



    // Input validation for quantity

    do {


        cout << "Enter quantity needed (kg): ";

        cin >> item.quantity;


        if (item.quantity <= 0) {

            cout << "Quantity must be greater than zero. Please try again.\n";


        }

    } while (item.quantity <= 0);



    cout << "Enter your location: ";

    cin.ignore();  // To clear the input buffer

    getline(cin, item.location);




    requestedFood.push_back(item);

    cout << "Food request added successfully!\n";
}




// View Requested Food

void viewRequestedFood1() {

    displayLine();

    if (requestedFood.empty()) {

        cout << "No food requests available.\n";

    } else {


        cout << "Requested Food Items:\n";

        for (size_t i = 0; i < requestedFood.size(); ++i) {

            cout << i + 1 << ". Name: " << requestedFood[i].name

                 << ", Category: " << requestedFood[i].category

                 << ", Quantity: " << requestedFood[i].quantity << " kg"

                 << ", Location: " << requestedFood[i].location << "\n";

        }


    }

}



// Storage Menu

void storeMenu1() {


    int choice;

    bool running = true;



    while (running) {

        displayLine();

        cout << "Storage Menu:\n";
        cout << "1. View Stored Food\n";


        cout << "2. Back to Main Menu\n";
        cout << "Enter your choice: ";


        cin >> choice;



        switch (choice) {

            case 1:

                viewStoredFood();

                break;

            case 2:

                running = false;

                break;

            default:

                cout << "Invalid choice. Try again.\n";


        }
    }
}





// View Stored Food


void viewStoredFood1()
{

    displayLine();

    if (storedFood.empty()) {


        cout << "No food items in storage.\n";

    } else {

        cout << "Stored Food Items:\n";


        for (size_t i = 0; i < storedFood.size(); ++i) {

            cout << i + 1 << ". Name: " << storedFood[i].name

                 << ", Category: " << storedFood[i].category

                 << ", Expiry Days: " << storedFood[i].expiryDays

                 << ", Quantity: " << storedFood[i].quantity << " kg"

                 << ", Location: " << storedFood[i].location << "\n";
        }



    }

}

class Graph1 {
public:
    unordered_map<string, vector<pair<string, int>>> adjList;

    void addEdge(const string &u, const string &v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight); // For undirected graph
    }

    void removeEdge(const string &u, const string &v) {
        adjList[u].erase(remove_if(adjList[u].begin(), adjList[u].end(), [&](const pair<string, int> &p) { return p.first == v; }), adjList[u].end());
        adjList[v].erase(remove_if(adjList[v].begin(), adjList[v].end(), [&](const pair<string, int> &p) { return p.first == u; }), adjList[v].end());
    }

    void updateEdgeWeight(const string &u, const string &v, int newWeight) {
        for (auto &p : adjList[u]) {
            if (p.first == v) {
                p.second = newWeight;
                break;
            }
        }
        for (auto &p : adjList[v]) {
            if (p.first == u) {
                p.second = newWeight;
                break;
            }
        }
    }

    void printGraph() {
        for (const auto &node : adjList) {
            cout << node.first << " -> ";
            for (const auto &neighbor : node.second) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }

    void bfs(const string &start) {
        unordered_map<string, bool> visited;
        queue<string> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            string node = q.front();
            q.pop();
            cout << node << " ";

            for (const auto &neighbor : adjList[node]) {
                if (!visited[neighbor.first]) {
                    visited[neighbor.first] = true;
                    q.push(neighbor.first);
                }
            }
        }
        cout << endl;
    }

    void dfsUtil(const string &node, unordered_map<string, bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (const auto &neighbor : adjList[node]) {
            if (!visited[neighbor.first]) {
                dfsUtil(neighbor.first, visited);
            }
        }
    }

    void dfs(const string &start) {
        unordered_map<string, bool> visited;
        dfsUtil(start, visited);
        cout << endl;
    }

    void topologicalSortUtil(const string &node, unordered_map<string, bool> &visited, stack<string> &stk) {
        visited[node] = true;

        for (const auto &neighbor : adjList[node]) {
            if (!visited[neighbor.first]) {
                topologicalSortUtil(neighbor.first, visited, stk);
            }
        }

        stk.push(node);
    }

    void topologicalSort() {
        unordered_map<string, bool> visited;
        stack<string> stk;

        for (const auto &node : adjList) {
            if (!visited[node.first]) {
                topologicalSortUtil(node.first, visited, stk);
            }
        }

        while (!stk.empty()) {
            cout << stk.top() << " ";
            stk.pop();
        }
        cout << endl;
    }

    bool detectCycleUtil(const string &node, unordered_map<string, bool> &visited, const string &parent) {
        visited[node] = true;

        for (const auto &neighbor : adjList[node]) {
            if (!visited[neighbor.first]) {
                if (detectCycleUtil(neighbor.first, visited, node)) {
                    return true;
                }
            } else if (neighbor.first != parent) {
                return true;
            }
        }

        return false;
    }

    bool detectCycle() {
        unordered_map<string, bool> visited;

        for (const auto &node : adjList) {
            if (!visited[node.first]) {
                if (detectCycleUtil(node.first, visited, "")) {
                    return true;
                }
            }
        }

        return false;
    }

    void transposeGraph(unordered_map<string, vector<pair<string, int>>> &transpose) {
        for (const auto &node : adjList) {
            for (const auto &neighbor : node.second) {
                transpose[neighbor.first].emplace_back(node.first, neighbor.second);
            }
        }
    }

    void printTransposeGraph(const unordered_map<string, vector<pair<string, int>>> &transpose) {
        for (const auto &node : transpose) {
            cout << node.first << " -> ";
            for (const auto &neighbor : node.second) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }

    void countNodes() {
        cout << "Total Nodes: " << adjList.size() << endl;
    }

    void countEdges() {
        int edges = 0;
        for (const auto &node : adjList) {
            edges += node.second.size();
        }
        cout << "Total Edges: " << edges / 2 << endl; // Divide by 2 for undirected graph
    }

    bool isConnected(const string &start) {
        unordered_map<string, bool> visited;
        queue<string> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            string node = q.front();
            q.pop();

            for (const auto &neighbor : adjList[node]) {
                if (!visited[neighbor.first]) {
                    visited[neighbor.first] = true;
                    q.push(neighbor.first);
                }
            }
        }

        return visited.size() == adjList.size();
    }

    // Additional methods for finding all paths, shortest/longest paths, and finding bridges can be implemented here
};
class login
{

public:
    int loginsys();

};

typedef struct vehicle
{

    string drivername;
    string vehiclename;
    string vehicleid;
    string ownerName;
    string contactNumber;
    int timestay;
    bool isBicycle;
    bool isTwoWheeler;
    bool requiresCharging;
    string parkingslot;
    string type;
    int hoursParked;
}
vehicle;


int login ::loginsys()
{

    while (1)
    {

        cout << "\n\n\n\n\t\t\t\t---------->  VEHICLE PARKING MANAGEMENT SYSTEM  <----------" << endl;

        cout << "\n\n\n\t\t\t\t\t Hey there! Ready to manage your parking?";


            cout << "\nWelcome To Our Parking System \n\n";
            system("PAUSE");
            break;
        }


    return 1;
}
class ParkingManagement
{
public:

    void park(ParkingManagement);
    void vehicledetail();
    void addexpensedb(vehicle VEHICLE[], int);
    void expense();
    void removevehicle();
    void getfeedback();
    void selectParkingPlace(vehicle &v);
    void viewAllParkedVehicles();
    void editVehicleDetails();
    void searchParkingPlace();
    void viewAllFeedback();
    void generateReport();
    void addParkingSlot();
    void viewAllParkingSlots();
    void removeParkingSlot();
    void allocateParkingSlot();
    void viewParkingSlotDetails();
    void editParkingSlotDetails();
    void viewVehicleDetailsById();
    void editExpense();
    void deleteExpense();
    double getParkingFee();
    void listVehiclesByType();
    string getMostFrequentParkingSlot();
    void addVehicleHistory();
    void viewVehicleHistory();
    void sendReminderForPayment();
    void generateExpenseReport();
    bool viewParkingSlotAvailability();
    void findParkingSlotByID();
    void viewStatistics();
    void help();
    void emergencyAlert();
    void settings();
    void adminMode();
    void park();
    void initializeAvailableSlots();
    int checkAvailableSlots(string parkingPlace);
    void updateAvailableSlots(string parkingPlace, bool isParking);
    void searchByDriverName();
    void displayParkingRules();
    void notifyOverduePayment();
    void viewAllVehiclesNeedingCharging();

};

int count = 0;
vector<string> parkingslots =

{

    "Downtown Parking",
    "Central Park Garage",
    "City Hall Lot",
    "Mall Parking",
    "Airport Parking",
    "Train Station Parking",
    "Beach Parking",
    "Stadium Parking",
    "Library Parking",
    "Museum Parking",
    "Hospital Parking",
    "University Parking",
    "Shopping Center Parking",
    "Residential Area Parking",
    "Business District Parking",
    "Cinema Parking",
    "Zoo Parking",
    "Park and Ride",
    "Sports Complex Parking",
    "Convention Center Parking",
    "Hotel Parking",
    "Theater Parking",
    "Restaurant Parking",
    "Night Club Parking",
    "Market Parking",
    "Church Parking",
    "Temple Parking",
    "Mosque Parking",
    "School Parking",
    "College Parking",
    "Playground Parking",
    "Community Center Parking",
    "Fire Station Parking",
    "Police Station Parking",
    "Government Office Parking",
    "Bus Terminal Parking",
    "Taxi Stand Parking",
    "Ferry Terminal Parking",
    "Bridge Parking",
    "Tunnel Parking",
    "Court House Parking",
    "Post Office Parking",
    "Swimming Pool Parking",
    "Gym Parking",
    "Recreation Center Parking",
    "Amusement Park Parking",
    "Water Park Parking",
    "Casino Parking",
    "Race Track Parking",
    "Botanical Garden Parking"

};

  int totalSlots = sizeof(parkingslots) / sizeof(parkingslots[0]);

map<string, int> parkingFees =

{

    {"Downtown Parking", 20},
     {"Central Park Garage", 25},
     {"City Hall Lot", 15},
      {"Mall Parking", 30},
       {"Airport Parking", 50},
    {"Train Station Parking", 40},
    {"Beach Parking", 35},
    {"Stadium Parking", 45},
    {"Library Parking", 10},
     {"Museum Parking", 15},
    {"Hospital Parking", 25},
     {"University Parking", 20},
      {"Shopping Center Parking", 30},
      {"Residential Area Parking", 10},
    {"Business District Parking", 35},
    {"Cinema Parking", 25},
     {"Zoo Parking", 20},
     {"Park and Ride", 15},
      {"Sports Complex Parking", 40},
    {"Convention Center Parking", 35},
    {"Hotel Parking", 30},
    {"Theater Parking", 25},
     {"Restaurant Parking", 20},
      {"Night Club Parking", 30},
    {"Market Parking", 15},
     {"Church Parking", 10},
     {"Temple Parking", 10},
     {"Mosque Parking", 10},
     {"School Parking", 10},
      {"College Parking", 20},
    {"Playground Parking", 15},
     {"Community Center Parking", 10},
      {"Fire Station Parking", 5},
      {"Police Station Parking", 5},
    {"Government Office Parking", 25},
     {"Bus Terminal Parking", 20},
     {"Taxi Stand Parking", 15},
     {"Ferry Terminal Parking", 25},
    {"Bridge Parking", 20},
     {"Tunnel Parking", 20},
      {"Court House Parking", 25},
      {"Post Office Parking", 15},
       {"Swimming Pool Parking", 15},
    {"Gym Parking", 15},
    {"Recreation Center Parking", 15},
     {"Amusement Park Parking", 35},
      {"Water Park Parking", 35},
       {"Casino Parking", 50},
    {"Race Track Parking", 45},
     {"Botanical Garden Parking", 20}

};


map<string, int> chargingStationFees =

{

    {"Downtown Parking", 10},
     {"Central Park Garage", 15},
      {"City Hall Lot", 5},
      {"Mall Parking", 10},
       {"Airport Parking", 20},
    {"Train Station Parking", 15},
     {"Beach Parking", 10},
      {"Stadium Parking", 20},
      {"Library Parking", 5},
       {"Museum Parking", 5},
    {"Hospital Parking", 10},
     {"University Parking", 10},
     {"Shopping Center Parking", 10},
      {"Residential Area Parking", 5},
    {"Business District Parking", 10},
    {"Cinema Parking", 10},
     {"Zoo Parking", 10},
      {"Park and Ride", 5},
      {"Sports Complex Parking", 15},
    {"Convention Center Parking", 10},
     {"Hotel Parking", 10},
     {"Theater Parking", 10},
     {"Restaurant Parking", 10},
      {"Night Club Parking", 15},
    {"Market Parking", 5},
    {"Church Parking", 5},
     {"Temple Parking", 5},
      {"Mosque Parking", 5},
       {"School Parking", 5},
       {"College Parking", 10},
    {"Playground Parking", 5},
     {"Community Center Parking", 5},
      {"Fire Station Parking", 5},
      {"Police Station Parking", 5},
    {"Government Office Parking", 10},
     {"Bus Terminal Parking", 10},
     {"Taxi Stand Parking", 5},
     {"Ferry Terminal Parking", 15},
    {"Bridge Parking", 10},
     {"Tunnel Parking", 10},
     {"Court House Parking", 10},
      {"Post Office Parking", 5},
       {"Swimming Pool Parking", 5},
    {"Gym Parking", 5},
    {"Recreation Center Parking", 5},
     {"Amusement Park Parking", 15},
      {"Water Park Parking", 15},
      {"Casino Parking", 20},
    {"Race Track Parking", 20},
     {"Botanical Garden Parking", 10}

};


map<string, int> totalParkingSlots =

{
    {"Downtown Parking", 100},
    {"Central Park Garage", 150},
    {"City Hall Lot", 80},
    {"Mall Parking", 200},
    {"Airport Parking", 500},
    {"Train Station Parking", 300},
    {"Beach Parking", 120},
    {"Stadium Parking", 400},
    {"Library Parking", 50},
    {"Museum Parking", 75},
    {"Hospital Parking", 150},
    {"University Parking", 250},
    {"Shopping Center Parking", 300},
    {"Residential Area Parking", 100},
    {"Business District Parking", 200},
    {"Cinema Parking", 100},
    {"Zoo Parking", 150},
    {"Park and Ride", 200},
    {"Sports Complex Parking", 250},
    {"Convention Center Parking", 300},
    {"Hotel Parking", 150},
    {"Theater Parking", 100},
    {"Restaurant Parking", 80},
    {"Night Club Parking", 100},
    {"Market Parking", 120},
    {"Church Parking", 100},
    {"Temple Parking", 80},
    {"Mosque Parking", 80},
    {"School Parking", 100},
    {"College Parking", 200},
    {"Playground Parking", 50},
    {"Community Center Parking", 80},
    {"Fire Station Parking", 30},
    {"Police Station Parking", 40},
    {"Government Office Parking", 150},
    {"Bus Terminal Parking", 100},
    {"Taxi Stand Parking", 50},
    {"Ferry Terminal Parking", 100},
    {"Bridge Parking", 60},
    {"Tunnel Parking", 40},
    {"Court House Parking", 100},
    {"Post Office Parking", 50},
    {"Swimming Pool Parking", 80},
    {"Gym Parking", 60},
    {"Recreation Center Parking", 100},
    {"Amusement Park Parking", 300},
    {"Water Park Parking", 200},
    {"Casino Parking", 400},
    {"Race Track Parking", 300},
    {"Botanical Garden Parking", 100}
};


map<string, int> availableParkingSlots;


void ParkingManagement::initializeAvailableSlots()

 {
    for (const auto& slot : totalParkingSlots)

        {
        availableParkingSlots[slot.first] = slot.second;
    }
}
int ParkingManagement::checkAvailableSlots(string parkingPlace)

 {
    if (availableParkingSlots.find(parkingPlace) != availableParkingSlots.end())

        {

        return availableParkingSlots[parkingPlace];
    }

    return -1;
}


void ParkingManagement::updateAvailableSlots(string parkingPlace, bool isParking)

{
    if (availableParkingSlots.find(parkingPlace) != availableParkingSlots.end())

        {
        if (isParking)

        {
            if (availableParkingSlots[parkingPlace] > 0)

            {
                availableParkingSlots[parkingPlace]--;
            }
        }
        else
        {
            if (availableParkingSlots[parkingPlace] < totalParkingSlots[parkingPlace])

             {
                availableParkingSlots[parkingPlace]++;
            }
        }
    }
}

void ParkingManagement::selectParkingPlace(vehicle &v)

{
    int choice;
    cout << "Available Parking Places: " << endl;
    for (int i = 0; i < parkingslots.size(); ++i)
    {
        cout << i + 1 << ". " << parkingslots[i] << " (Fee: " << parkingFees[parkingslots[i]] << " per hour)" << endl;
    }
    cout << "Select a parking place by entering the corresponding number: ";
    cin >> choice;


    while (choice < 1 || choice > parkingslots.size())
    {
        cout << "Invalid choice. Please select a number between 1 and " << parkingslots.size() << ": ";
        cin >> choice;
    }

    v.parkingslot = parkingslots[choice - 1];

}

void ParkingManagement ::park(ParkingManagement obj)
{
    cout << "                        -------------> Vehicle Parking System <-------------" << endl
         << endl;

    ofstream out;

    vehicle VEHICLE[10];
    out.open("vehicleparkdb.txt", ios::app);

    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Enter Your Name : ";



    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Enter Your Vehicle Name : ";



    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Enter Your Vehicle Number Plate (You Can Enter A Unique Alphabet Sequence) (Remember It Well!) : ";

    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Enter Your Time Stay In Hours (Integer Only) : ";


    char vehicleType;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Is it a bicycle? (y/n): ";
    cin >> vehicleType;


    {

        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "Is it a two-wheeler? (y/n): ";
        cin >> vehicleType;

        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "Does it require charging? (y/n): ";
        cin >> vehicleType;

    }



    {

    }


    cout << "Vehicle Name : " << ""
        << ", Vehicle Id : " << "\n"
        << "Driver Name : " << ""
        << ", Vehicle Time Stay : "<<" " <<"hours\n"
        << "Is Bicycle: " <<  "Yes" << "No" << "\n"
        << "Is Two-Wheeler: " << "Yes" << "No" << "\n"
        << "Requires Charging: " <<  "Yes" << "No" << "\n"
        << "Parking Slot: " << "" << "\n";




    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Your Vehicle Is Parked Now!" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Press Enter Key To Return" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
}



void ParkingManagement ::vehicledetail()
{
    system("CLS");
    string detailid;
    string line;
    bool found = false;

    cout << "Enter the vehicle Id: ";
    getchar();
    getline(cin, detailid);
    cout << "---------------------------------------------------" << endl;

    ifstream in;
    in.open("vehicleparkdb.txt");
    while (getline(in, line))

        {
        if (line.find(detailid) != string::npos)

        {
            cout << "Vehicle Found!" << endl;
            cout << line << endl;
            getline(in, line);
            cout << line << endl;
            found = true;
            break;


        }
    }
    in.close();

    if (!found)

        {
        cout << "No vehicle found for the vehicle id: " << detailid << endl;
    }

    cout << "Press Enter Key To Return" << endl;
    getchar();
}



void ParkingManagement ::addexpensedb(vehicle VEHICLE[], int count)
{
    ofstream out;

    out.open("vehicleparkexpensedb.txt", ios::app);

    int rate;
    if (VEHICLE[count].isBicycle)

    {
        rate = 50;
    }
    else if (VEHICLE[count].isTwoWheeler)

    {
        rate = VEHICLE[count].requiresCharging ? 120 : 100;

    }
    else

    {
        rate = VEHICLE[count].requiresCharging ? 150 : 130;
    }

    int parkingFee = parkingFees[VEHICLE[count].parkingslot];
    int chargingFee = VEHICLE[count].requiresCharging ? chargingStationFees[VEHICLE[count].parkingslot] : 0;

    out << "Vehicle ID : " << VEHICLE[count].vehicleid << ", Vehicle Name : " << VEHICLE[count].vehiclename << "\n";
    out << "Driver Name : " << VEHICLE[count].drivername << ", Vehicle Time Stay : " << VEHICLE[count].timestay
        << " hours, Total Expense : " << VEHICLE[count].timestay * (rate + parkingFee + chargingFee) << " Rupees\n";
    out << "Parking Place : " << VEHICLE[count].parkingslot << "\n";

    out.close();
}


void ParkingManagement::expense()


 {

    system("CLS");
    string cexpenseid, line;
    int i = 0;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << endl;
    cout << "                        -------------> Vehicle Parking Expenses <-------------" << endl;
    cout << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

    cout << "Enter Your Vehicle Id : ";
    cin >> cexpenseid;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

    ifstream in;
    in.open("vehicleparkexpensedb.txt");
    while (in.eof() == 0)


        {

        getline(in, line);
        size_t found = line.find(cexpenseid);
        if (found != string::npos)

            {

            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            cout << "Your Vehicle Parking Expense Details Are : " << endl;
            cout << line;
            getline(in, line);
            cout << endl;
            cout << line << endl;
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;


            cout << "Select payment method: " << endl;
            cout << "1. Credit Card" << endl;
            cout << "2. Debit Card" << endl;
            cout << "3. Cash" << endl;
            cout << "4. Digital Wallet" << endl;

            int paymentChoice;
            cin >> paymentChoice;

            switch (paymentChoice)

            {
                case 1:
                    cout << "Payment via Credit Card selected." << endl;
                    break;
                case 2:
                    cout << "Payment via Debit Card selected." << endl;
                    break;
                case 3:
                    cout << "Payment via Cash selected." << endl;
                    break;
                case 4:
                    cout << "Payment via Digital Wallet selected." << endl;
                    break;
                default:
                    cout << "Invalid choice! Please select a valid payment method." << endl;
                    break;

            }

            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            cout << "Press Enter Key To Return" << endl;
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            break;


        }
    }

    in.close();

    if (i == 0)
        {
        cout << "Vehicle With VehicleID " << cexpenseid << " Not Found" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "TRY AGAIN! (Use Correct VehicleID)" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "Press Enter Key To Return" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;


    }
}


void ParkingManagement ::removevehicle()
{

    system("CLS");
    string rvehicleid;
    string line, nextline;

    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << endl;
    cout << "                        -------------> Vehicle Parking Check Out System <-------------"
         << endl;
    cout << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

    cout << "Enter Your Vehicle Id : ";
    cin >> rvehicleid;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

    ifstream in;
    ofstream out;
    in.open("vehicleparkdb.txt");
    out.open("temp.txt", ios::app);


    {

        getline(in, line);
        size_t found = line.find(rvehicleid);
        if (found != string::npos)

        {
            getline(in, line);
            getline(in, line);
        }

        out << line;
        out << endl;

    }

    in.close();
    out.close();

    remove("vehicleparkdb.txt");
    rename("temp.txt", "vehicleparkdb.txt");

    in.open("vehicleparkexpensedb.txt");
    out.open("tempexpense.txt", ios::app);
    while (in.eof() == 0)

    {
        getline(in, nextline);
        size_t found = nextline.find(rvehicleid);
        if (found != string::npos)

        {
            getline(in, nextline);
            getline(in, nextline);
        }

        out << nextline;
        out << endl;
    }

    in.close();
    out.close();

    remove("vehicleparkexpensedb.txt");
    rename("tempexpense.txt", "vehicleparkexpensedb.txt");

    cout << "Good Bye" << endl
         << "Thanks For Choosing Us!" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Press Enter Key To Return" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

}


void ParkingManagement ::getfeedback()
{

    system("CLS");
    string feedback;
    cout << "                        -------------> Feedback Form <-------------" << endl
         << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Enter your feedback: ";
    getchar();
    getline(cin, feedback);

    ofstream out;
    out.open("feedback.txt", ios::app);
    out << "Feedback: " << feedback << "\n";
    out.close();

    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Thank you for your feedback!" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Press Enter Key To Return" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

}



void ParkingManagement::viewAllParkedVehicles()
{

    system("CLS");
    ifstream in;
    string line;

    cout << "                        -------------> All Parked Vehicles <-------------" << endl
         << endl;

    in.open("vehicleparkdb.txt");

    if (!in)

    {
        cout << "No vehicles are parked at the moment." << endl;
    }

    else

    {
        while (getline(in, line))

        {
            cout << line << endl;
        }
    }

    in.close();
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Press Enter Key To Return" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
}


void ParkingManagement::editVehicleDetails()
{
    system("CLS");
    string editVehicleId, line, updatedDetail;
    cout << "                        -------------> Edit Vehicle Details <-------------" << endl
         << endl;

    cout << "Enter the Vehicle ID to edit: ";
    cin >> editVehicleId;

    ifstream in;
    ofstream out;
    bool found = false;

    in.open("vehicleparkdb.txt");
    out.open("temp.txt");

    while (getline(in, line))
    {
        if (line.find(editVehicleId) != string::npos)
        {
            found = true;
            cout << "Current details: " << line << endl;
            cout << "Enter new details: ";
            getchar();
            getline(cin, updatedDetail);
            out << updatedDetail << endl;

        }


        else
        {
            out << line << endl;
        }
    }

    in.close();
    out.close();

    remove("vehicleparkdb.txt");
    rename("temp.txt", "vehicleparkdb.txt");

    if (found)

    {
        cout << "Vehicle details updated successfully." << endl;
    }

    else

    {
        cout << "Vehicle ID not found." << endl;
    }

    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Press Enter Key To Return" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

}



void ParkingManagement::searchParkingPlace()
{

    system("CLS");
    string searchPlace;
    cout << "                        -------------> Search Parking Place <-------------" << endl
         << endl;
    cout << "Enter the name of the parking place to search: ";
    getchar();
    getline(cin, searchPlace);

    bool found = false;

    cout << "Search Results: " << endl;
    for (const auto &place : parkingslots)

    {

        if (place.find(searchPlace) != string::npos)

        {
            cout << place << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No parking places found with that name." << endl;
    }

    else

    {
        cout<<"This parking place is there."<<endl;
    }

    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Press Enter Key To Return" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

}


void ParkingManagement::viewAllFeedback()

{

    system("CLS");
    ifstream in;
    string feedbackLine;

    cout << "                        -------------> All Feedback <-------------" << endl
         << endl;

    in.open("feedback.txt");

    if (!in)
    {
        cout << "No feedback available at the moment." << endl;
    }

    else

    {

        while (getline(in, feedbackLine))
        {
            cout << feedbackLine << endl;
        }
    }

    in.close();
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Press Enter Key To Return" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

}


void ParkingManagement::generateReport()

{

    system("CLS");
    ifstream in;
    string line;
    int totalIncome = 0;

    cout << "                        -------------> Parking Expense Report <-------------" << endl
         << endl;

    in.open("vehicleparkexpensedb.txt");

    if (!in)

    {
        cout << "No expense records found." << endl;
    }



    else
    {
        while (getline(in, line))
        {

            cout << line << endl;
            size_t pos = line.find("Total Expense : ");
            if (pos != string::npos)
            {

                int expense = stoi(line.substr(pos + 15));
                totalIncome += expense;
            }
        }
    }

    in.close();
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Total Income from Parking: " << totalIncome << " Rupees" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Press Enter Key To Return" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

}

void ParkingManagement::addParkingSlot()

 {
    system("CLS");
    string slotId, location;
    cout << "---------------------------------------------------\n";
    cout << "-------------> Add New Parking Slot <-------------\n";
    cout << "---------------------------------------------------\n";

    cout << "Enter Slot ID: ";
    cin >> slotId;
    cout << "Enter Slot Location: ";
    cin.ignore();
    getline(cin, location);


    ofstream out("parkingslots.txt", ios::app);
    out << "Slot ID: " << slotId << ", Location: " << location << ", Status: Available\n";
    out.close();

    cout << "Parking slot added successfully!\n";
    cout << "---------------------------------------------------\n";
    cout << "Press Enter Key To Return\n";
    getchar();

}

void ParkingManagement::viewAllParkingSlots()

 {

    system("CLS");
    cout << "---------------------------------------------------\n";
    cout << "-------------> View All Parking Slots <-------------\n";
    cout << "---------------------------------------------------\n";

    ifstream in("parkingslots.txt");
    string line;
    while (getline(in, line))

        {
        cout << line << endl;
    }
    in.close();

    cout << "---------------------------------------------------\n";
    cout << "Press Enter Key To Return\n";
    getchar();

}


void ParkingManagement::removeParkingSlot()

{

    system("CLS");
    string slotId, line;
    cout << "---------------------------------------------------\n";
    cout << "-------------> Remove Parking Slot <-------------\n";
    cout << "---------------------------------------------------\n";

    cout << "Enter Slot ID to remove: ";
    cin >> slotId;

    ifstream in("parkingslots.txt");
    ofstream out("temp.txt");
    bool found = false;

    while (getline(in, line))

        {
        if (line.find(slotId) != string::npos)
            {
            found = true;
            cout << "Removing: " << line << endl;
        }
    else
    {


            out << line << endl;
        }
    }

    in.close();
    out.close();

    remove("parkingslots.txt");
    rename("temp.txt", "parkingslots.txt");

    if (found)

        {
        cout << "Parking slot removed successfully!\n";
    }

    else

        {
        cout << "Slot ID not found.\n";
    }

    cout << "---------------------------------------------------\n";
    cout << "Press Enter Key To Return\n";
    getchar();

}



void ParkingManagement::allocateParkingSlot()


 {
    system("CLS");
    string slotId, vehicleId, line, updatedLine;
    cout << "---------------------------------------------------\n";
    cout << "-------------> Allocate Parking Slot <-------------\n";
    cout << "---------------------------------------------------\n";

    cout << "Enter Slot ID to allocate: ";
    cin >> slotId;
    cout << "Enter Vehicle ID: ";
    cin >> vehicleId;

    ifstream in("parkingslots.txt");
    ofstream out("temp.txt");
    bool found = false;

    while (getline(in, line))

        {
        if (line.find(slotId) != string::npos)

         {
            found = true;

            updatedLine = line + ", Vehicle ID: " + vehicleId;
            out << updatedLine << endl;
        }

        else
            {
            out << line << endl;
        }
    }

    in.close();
    out.close();

    remove("parkingslots.txt");
    rename("temp.txt", "parkingslots.txt");

    if (found)

        {
        cout << "Parking slot allocated successfully!\n";
    }
    else

        {
        cout << "Slot ID not found.\n";
    }

    cout << "---------------------------------------------------\n";
    cout << "Press Enter Key To Return\n";
    getchar();

}


void ParkingManagement::viewParkingSlotDetails()

 {
    system("CLS");
    string slotId, line;
    cout << "---------------------------------------------------\n";
    cout << "-------------> View Parking Slot Details <-------------\n";
    cout << "---------------------------------------------------\n";

    cout << "Enter Slot ID to view details: ";
    cin >> slotId;

    ifstream in("parkingslots.txt");
    bool found = false;

    while (getline(in, line))

        {
        if (line.find(slotId) != string::npos)
        {
            cout << "Details of Slot ID " << slotId << ":\n" << line << endl;
            found = true;
            break;
        }
    }

    in.close();

    if (!found)

        {
        cout << "Parking slot not found.\n";
    }

    cout << "---------------------------------------------------\n";
    cout << "Press Enter Key To Return\n";
    getchar();


}



void ParkingManagement::editParkingSlotDetails()

 {
    system("CLS");
    string slotId, line, updatedLine;
    cout << "---------------------------------------------------\n";
    cout << "-------------> Edit Parking Slot Details <-------------\n";
    cout << "---------------------------------------------------\n";

    cout << "Enter Slot ID to edit: ";
    cin >> slotId;

    ifstream in("parkingslots.txt");
    ofstream out("temp.txt");
    bool found = false;

    while (getline(in, line))

    {
        if (line.find(slotId) != string::npos)


            {
            found = true;
            cout << "Current details: " << line << endl;
            cout << "Enter new Slot Location: ";
            cin.ignore();
            getline(cin, updatedLine);
            out << "Slot ID: " << slotId << ", Location: " << updatedLine << ", Status: Available\n";
        }

        else


            {
            out << line << endl;
        }
    }

    in.close();
    out.close();

    remove("parkingslots.txt");
    rename("temp.txt", "parkingslots.txt");

    if (found)

        {
        cout << "Parking slot details updated successfully!\n";
    }

    else


        {
        cout << "Slot ID not found.\n";
    }

    cout << "---------------------------------------------------\n";
    cout << "Press Enter Key To Return\n";
    getchar();

}



void ParkingManagement::viewVehicleDetailsById()

{
    system("CLS");
    string line,vehicleid;
    cout << "---------------------------------------------------\n";
    cout << "-------------> View Vehicle Details By ID <-------------\n";
    cout << "---------------------------------------------------\n";

    cout << "Enter Vehicle ID to view details: ";
    cin >> vehicleid;

    ifstream in("vehicles.txt");
    bool found = false;

    while (getline(in, line))

        {
        if (line.find(vehicleid) != string::npos)
        {
            cout << "Details of Vehicle ID " << vehicleid << ":\n" << line << endl;
            found = true;
            break;
        }
    }

    in.close();

    if (!found)

        {
        cout << "Vehicle not found.\n";
    }

    cout << "---------------------------------------------------\n";
    cout << "Press Enter Key To Return\n";
    getchar();

}


void ParkingManagement::editExpense()

 {
    system("CLS");
    int expenseId;
    cout << "---------------------------------------------------\n";
    cout << "-------------> Edit Expense <-------------\n";
    cout << "---------------------------------------------------\n";

    ifstream in("expenses.txt");
    ofstream temp("temp_expenses.txt");
    string line;
    bool found = false;

    while (getline(in, line))

        {
        if (line.find(to_string(expenseId)) != string::npos)
         {
            found = true;
            cout << "Current details: " << line << endl;
            cout << "Enter new details for this expense: ";
            string newExpenseDetails;
            cin.ignore();
            getline(cin, newExpenseDetails);
            temp << newExpenseDetails << endl;
        }

    else

        {
            temp << line << endl;
        }
    }

    in.close();
    temp.close();

    if (found)

        {
        remove("expenses.txt");
        rename("temp_expenses.txt", "expenses.txt");
        cout << "Expense updated successfully.\n";
    }

    else


        {
        cout << "Expense not found.\n";
    }

    cout << "---------------------------------------------------\n";
    cout << "Press Enter Key To Return\n";
    getchar();
}


void ParkingManagement::deleteExpense()

 {
    system("CLS");
    int expenseId;
    cout << "---------------------------------------------------\n";
    cout << "-------------> Delete Expense <-------------\n";
    cout << "---------------------------------------------------\n";

    ifstream in("expenses.txt");
    ofstream temp("temp_expenses.txt");
    string line;
    bool found = false;

    while (getline(in, line))

        {
        if (line.find(to_string(expenseId)) == string::npos)
        {
            temp << line << endl;
        }
    else

        {
            found = true;
        }
    }

    in.close();
    temp.close();

    if (found)

        {
        remove("expenses.txt");
        rename("temp_expenses.txt", "expenses.txt");
        cout << "Expense deleted successfully.\n";
    }

    else

        {
        cout << "Expense not found.\n";
    }

    cout << "---------------------------------------------------\n";
    cout << "Press Enter Key To Return\n";
    getchar();

}



void ParkingManagement::listVehiclesByType()

{
    system("CLS");
    string line,vehicleType;
    cout << "---------------------------------------------------\n";
    cout << "-------------> List Vehicles By Type <-------------\n";
    cout << "---------------------------------------------------\n";

    cout << "Enter Vehicle Type to list: ";
    cin >> vehicleType;

    ifstream in("vehicles.txt");
    bool found = false;

    while (getline(in, line))

        {

        if (line.find(vehicleType) != string::npos)
         {

            cout << line << endl;
            found = true;
        }
    }

    in.close();

    if (!found)

        {

        cout << "No vehicles found for type: " << vehicleType << ".\n";
    }

    cout << "---------------------------------------------------\n";
    cout << "Press Enter Key To Return\n";
    getchar();
}

string ParkingManagement::getMostFrequentParkingSlot()

{
    ifstream in("parking_history.txt");
    string line;
    map<string, int> slotFrequency;
    string mostFrequentSlot;
    int maxCount = 0;

    while (getline(in, line))

        {

        stringstream ss(line);
        string slotId;
        ss >> slotId;

        slotFrequency[slotId]++;

        if (slotFrequency[slotId] > maxCount)

            {

            maxCount = slotFrequency[slotId];
            mostFrequentSlot = slotId;
        }
    }

    in.close();

    return mostFrequentSlot;
}


void ParkingManagement::addVehicleHistory()

 {

    ofstream out("vehicle_history.txt", ios::app);

    if (!out)

        {

        cout << "Failed to open vehicle_history.txt for writing.\n";
        return;
    }

    string vehicleid, history;
    cout << "Enter Vehicle ID: ";
    cin >> vehicleid;
    cin.ignore();

    cout << "Enter Vehicle History: ";
    getline(cin, history);


    out << vehicleid << ": " << history << endl;

    out.close();
    cout << "History added successfully.\n";
}


void ParkingManagement::viewVehicleHistory()

 {

    system("CLS");
    string line, vehicleid;
    cout << "---------------------------------------------------\n";
    cout << "-------------> View Vehicle History <-------------\n";
    cout << "---------------------------------------------------\n";

    cout << "Enter Vehicle ID to view history: ";
    cin >> vehicleid;

    ifstream in("vehicle_history.txt");

    if (!in)

        {
        cout << "Failed to open vehicle_history.txt.\n";
        return;
    }

    bool found = false;
    while (getline(in, line))

        {
        if (line.find(vehicleid) != string::npos)

         {
            cout << line << endl;
            found = true;
        }
    }

    in.close();

    if (!found)

        {

        cout << "No history found for Vehicle ID " << vehicleid << ".\n";
    }

    cout << "---------------------------------------------------\n";
    cout << "Press Enter Key To Return\n";
    getchar();

}


void ParkingManagement::sendReminderForPayment()

 {
    string vehicleid;
    cout << "---------------------------------------------------\n";
    cout << "-------------> Send Reminder For Payment <-------------\n";
    cout << "---------------------------------------------------\n";

    cout << "Reminder sent to the owner of vehicle ID: " << vehicleid << endl;
    cin>>vehicleid;
    cout<<"Reminder is sent to the owner of vehicle ID= "<<vehicleid<<endl;
    cout << "---------------------------------------------------\n";
    cin.ignore();
    cin.get();

}


void ParkingManagement::generateExpenseReport()

 {
    system("CLS");
    string line;
    cout << "---------------------------------------------------\n";
    cout << "-------------> Generate Expense Report <-------------\n";
    cout << "---------------------------------------------------\n";

    ifstream in("expenses.txt");

    double totalExpense = 0.0;
    while (getline(in, line))

        {
        stringstream ss(line);
        string word;
        double expenseAmount = 0.0;
        while (ss >> word)

         {

            expenseAmount = stod(word);
        }
        totalExpense += expenseAmount;
    }

    in.close();

    cout << "Total Expenses: $" << totalExpense << endl;
    cout << "---------------------------------------------------\n";
    cout << "Press Enter Key To Return\n";
    getchar();

}


bool ParkingManagement::viewParkingSlotAvailability()

 {

    ifstream in("parkingslots.txt");
    string line;
    int slotId;

    while (getline(in, line))

        {

        if (line.find(to_string(slotId)) != string::npos)

        {

            if (line.find("Available") != string::npos)

            {

                cout << "Slot ID " << slotId << " is available.\n";
                return true;

            }
    else

        {
                cout << "Slot ID " << slotId << " is not available.\n";
                return false;
            }
        }
    }

    in.close();
    cout << "Slot ID " << slotId << " not found.\n";
    return false;

}


void ParkingManagement::findParkingSlotByID()

 {

      int slotID;
        if (slotID >= 1 && slotID <= parkingslots.size())

            {

            cout << "Parking Slot for ID " << slotID << " is: " << parkingslots[slotID - 1] << endl;
        }

        else

            {
            cout << "Invalid Parking ID! Please enter a valid ID between 1 and " << parkingslots.size() << "." << endl;
        }
    }




void ParkingManagement::viewStatistics()

{
    cout << "---------------------------------------------------\n";
    cout << "-------------> View System Statistics <-------------\n";
    cout << "---------------------------------------------------\n";
    cout << "1. Total Vehicles Parked Today\n";
    cout << "2. Revenue Generated\n";
    cout << "3. Average Parking Time" << endl;
    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice)

     {
        case 1:
            cout << "---------------------------------------------------\n";
            cout << "Total Vehicles Parked Today: 50\n";
            cout << "---------------------------------------------------\n";
            break;
        case 2:
            cout << "---------------------------------------------------\n";
            cout << "Revenue Generated Today: $500\n";
            cout << "---------------------------------------------------\n";
            break;
        case 3:
            cout << "---------------------------------------------------\n";
            cout << "Average Parking Time: 2 hours\n";
            cout << "---------------------------------------------------\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
            break;

    }

    cout << "Press Enter Key To Return\n";
    getchar();

}



void ParkingManagement::help()

{
    cout << "---------------------------------------------------\n";
    cout << "---------------- Help & FAQs ------------------\n";
    cout << "---------------------------------------------------\n";
    cout << "1. How to park a vehicle\n";
    cout << "2. How to remove a vehicle\n";
    cout << "3. Contact support" << endl;
     int choice;
    cin >> choice;
    cin.ignore();

    switch (choice)

     {

        case 1:
            cout << "---------------------------------------------------\n";
            cout << "To park a vehicle, follow the steps:\n";
            cout << "1. Choose a slot.\n";
            cout << "2. Enter vehicle details.\n";
            cout << "3. Confirm reservation.\n";
            cout << "---------------------------------------------------\n";
            break;
        case 2:
            cout << "---------------------------------------------------\n";
            cout << "To remove a vehicle, please contact the management team with your vehicle details.\n";
            cout << "---------------------------------------------------\n";
            break;
        case 3:
            cout << "---------------------------------------------------\n";
            cout << "Contact support at support@parking.com or call 123-456-7890.\n";
            cout << "---------------------------------------------------\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
            break;

    }

    cout << "Press Enter Key To Return\n";
    getchar();

}



void ParkingManagement::emergencyAlert()

 {
    cout << "---------------------------------------------------\n";
    cout << "-------------> Emergency Alert <-------------\n";
    cout << "---------------------------------------------------\n";
    cout << "Emergency reported! Notifying security and management...\n";
    cout << "Emergency alert sent. Please stay calm.\n";
    cout << "---------------------------------------------------\n";
    cout << "Press Enter Key To Return\n";
    getchar();

}


void ParkingManagement::notifyOverduePayment()

{

    system("CLS");
    cout << "---------------------------------------------------\n";
    cout << "-------------> Notify Overdue Payment <-------------\n";
    cout << "---------------------------------------------------\n";


    int overdueThreshold = 24;
    string vehicleId;

    cout << "Enter Vehicle ID to check overdue payment: ";
    cin >> vehicleId;

    ifstream in("vehicle_payment_info.txt");
    bool found = false;
    string line;

    while (getline(in, line))

        {

        if (line.find(vehicleId) != string::npos)
        {


            cout << "\nReminder: Vehicle " << vehicleId << " has overdue payment!\n";
            found = true;
            break;

        }
    }

    in.close();

    if (!found)

        {

        cout << "\nPayment is up to date.\n";
    }

    cout << "---------------------------------------------------\n";
    cout << "Press Enter Key To Return\n";
    cin.ignore();
    cin.get();

}


void ParkingManagement::settings()

 {

    cout << "---------------------------------------------------\n";
    cout << "-------------------- System Settings ----------------\n";
    cout << "---------------------------------------------------\n";
    cout << "1. Change Language\n";
    cout << "2. Update Notification Preferences\n";
    cout << "3. Reset System" << endl;
    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice)

    {

        case 1:
            cout << "---------------------------------------------------\n";
            cout << "Language settings: English (default).\n";
            cout << "---------------------------------------------------\n";
            break;
        case 2:
            cout << "---------------------------------------------------\n";
            cout << "Notification preferences updated: Email and SMS notifications enabled.\n";
            cout << "---------------------------------------------------\n";
            break;
        case 3:
            cout << "---------------------------------------------------\n";
            cout << "System reset completed. All data erased.\n";
            cout << "---------------------------------------------------\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
            break;

    }

    cout << "Press Enter Key To Return\n";
    getchar();

}



void ParkingManagement::adminMode()

 {

    cout << "---------------------------------------------------\n";
    cout << "-------------> Admin Mode <-------------\n";
    cout << "---------------------------------------------------\n";
    cout << "Admin Options:\n";
    cout << "1. Reset System Logs\n";
    cout << "2. Manage Parking Slots" << endl;
     int choice;
    cin >> choice;
    cin.ignore();

    switch (choice)

     {


        case 1:
            cout << "---------------------------------------------------\n";
            cout << "System logs reset. All data cleared.\n";
            cout << "---------------------------------------------------\n";
            break;
        case 2:
            cout << "---------------------------------------------------\n";
            cout << "Managing parking slots...\n";
            cout << "---------------------------------------------------\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
            break;

    }

    cout << "Press Enter Key To Return\n";
    getchar();

}


void ParkingManagement::park()

{

    cout << "---------------------------------------------------\n";
    cout << "-------------> Vehicle Parking System <-------------\n";
    cout << "---------------------------------------------------\n";

    ofstream out;
    vehicle VEHICLE[10];
    out.open("vehicleparkdb.txt", ios::app);

    cout << "Enter Your Name: ";
    cin.ignore();

    cout << "Enter Your Vehicle Name: ";

    cout << "Enter Vehicle Registration Number: ";

    cout << "Enter Your Time Stay In Hours (Integer Only): ";


    cout << "Driver Name: " << ""<< "\n"
        << "Vehicle Name: " << "" << "\n"
        << "Vehicle ID: " << "" << "\n"
        << "Time Stay: " <<""<< " hours\n";

    cout << "Your Vehicle Has Been Parked!" << endl;
    out.close();

    cout << "---------------------------------------------------\n";
    cout << "Press Enter Key To Return\n";
    getchar();

}

void ParkingManagement::viewAllVehiclesNeedingCharging()

{

    system("CLS");
    cout << "---------------------------------------------------\n";
    cout << "-------------> View All Vehicles Needing Charging <-------------\n";
    cout << "---------------------------------------------------\n";

    ifstream in("vehicleparkdb.txt");
    if (!in)

        {

        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    bool found = false;


    while (getline(in, line))
        {

        if (line.find("Requires Charging: Yes") != string::npos) {
            cout << "\nVehicle requiring charging: \n";
            cout << line << endl;
            found = true;
        }
    }

    in.close();

    if (!found)

        {
        cout << "\nNo vehicles require charging at the moment.\n";
    }

    cout << "---------------------------------------------------\n";
    cout << "Press Enter Key To Return\n";
    cin.ignore();
    cin.get();

}

void ParkingManagement::searchByDriverName()

 {

    system("CLS");
    string driverName;
    string line;
    bool found = false;

    cout << "Enter the Driver's Name: ";
    getchar();
    getline(cin, driverName);
    cout << "---------------------------------------------------" << endl;

    ifstream in;
    in.open("vehicleparkdb.txt");
    while (getline(in, line))

        {

        if (line.find(driverName) != string::npos)

        {
            cout << "Vehicle Found!" << endl;
            cout << line << endl;
            getline(in, line);
            cout << line << endl;
            found = true;
            break;

        }
    }

    in.close();

    if (!found)

        {

        cout << "No vehicle found for the driver name: " << driverName << endl;
    }

    cout << "Press Enter Key To Return" << endl;
    getchar();

}


void ParkingManagement::displayParkingRules()

 {

    system("CLS");
    cout << "                        -------------> Parking Rules <-------------" << endl
         << endl;
    cout << "1. Each vehicle must be assigned a designated parking slot." << endl;
    cout << "2. Vehicles must adhere to the time limit specified." << endl;
    cout << "3. Different parking fees apply based on vehicle type." << endl;
    cout << "4. Payment must be made in advance or upon exiting." << endl;
    cout << "5. Check availability before arriving at the facility." << endl;
    cout << "6. Only roadworthy vehicles are allowed." << endl;
    cout << "7. Electric vehicles must use designated charging stations." << endl;
    cout << "8. Follow emergency protocols in case of emergencies." << endl;
    cout << "9. Feedback and complaints should be directed to management." << endl;
    cout << "10. The facility is monitored for security." << endl;
    cout << "11. Prohibited activities include smoking and unauthorized repairs." << endl;
    cout << "12. Maintenance may affect parking availability." << endl;
    cout << "13. Compliance with rules is mandatory." << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Press Enter Key To Return" << endl;
    cin.get();
    cin.ignore();


}


// Main driver program

int main()

{

    cout<<"\n**********************************************************************\n";

    cout<<"    \n                 SMART FOOD MANAGEMENT SYSTEM              \n  ";

    cout<<"\n***********************************************************************\n\n";


    int ch;

    do

// Main function to drive the program

        {

        cout << "Menu:\n";

        cout << "1. Food Management System\n";

        cout << "2. Graph Operations\n";


        cout << "3. modula 3\n";

        cout << "4. modul  4\n";

        cout << "5. Exit\n";


        cout << "Enter your choice: ";

        cin >> ch;




        switch (ch)

         {

        case 1:

            {

            FoodManagementSystem system;

                // Insert some sample food items

            system.insertFood(1, "rice", 23, 175.00);

            system.insertFood(2, "wheet", 13, 250.00);


            system.insertFood(3, "grains", 8, 475.00);



            int choice;

            do

                {

                cout << "Food Management Menu:\n";

                cout << "1. Display Food List\n";

                cout << "2. Add Food Item\n";


                cout << "3. Delete Food Item\n";

                cout << "4. Update Food Quantity\n";

                cout << "5. Place Order\n";

                cout << "6. Display Total Cash\n";

                cout << "7. Backup Data\n";

                cout << "8. View Orders Queue\n";


                cout << "9. Requeue Order\n";


                cout << "10. Search Food by Name\n";

                cout << "11. Sort Food by Price\n";
                cout << "12. Exit\n";

                cout << "Enter your choice: ";

                cin >> choice;



                switch (choice)



            {

                case 1:
                    // Insert some sample food items

                    system.displayFoodList();

                    break;

                case 2:




                {

                    int serial;

                    string foodName;

                    int quantity;


                    float price;

                    cout << "Enter Serial: ";

                    cin >> serial;

                    cin.ignore();


                    getline(cin, foodName);
                    cout << "Enter Quantity: ";


                    cin >> quantity;

                    cout << "Enter Price: ";


                    cin >> price;

                    system.insertFood(serial, foodName, quantity, price);


                    break;

                }


                case 3:



                {

                    int serial;

                    cout << "Enter Serial to Delete: ";

                    cin >> serial;

                    system.deleteFood(serial);


                    break;

                }

                case 4:


                {

                    int serial;


                    int newQuantity;

                    cout << "Enter Serial to Update: ";

                    cin >> serial;


                    cout << "Enter New Quantity: ";


                    cin >> newQuantity;

                    system.updateFood(serial, newQuantity);

                    break;

                }


                case 5:

                     {

                    int serial;


                    int orderQuantity;
                    cout << "Enter Serial to Order: ";


                    cin >> serial;


                    cout << "Enter Quantity: ";

                    cin >> orderQuantity;

                    system.placeOrder(serial, orderQuantity);

                    break;

                }


                case 6:

                    system.displayTotalCash();

                    break;
                case 7:


                    system.backupData();

                    break;


                case 8:

                    system.viewOrdersQueue();

                    break;


                case 9:

                    system.requeue();

                    break;
                case 10:


                     {

                    string foodName;


                    cout << "Enter food name to search: ";

                    cin >> foodName;

                    system.searchFoodByName(foodName);


                    break;

                }

                case 11:

                    system.sortFoodByPrice();


                    break;

                case 12:

                    cout << "Exiting Food Management System...\n";

                    break;

                default:


                    cout << "Invalid choice! Try again.\n";

                }

            }

            while (choice != 12);

            break;
        }



        case 2:




{
    Graph1 graph1;

    graph1.addEdge("COMMUNITY_KITCHEN", "CENTRAL_BUS_STAND", 10);


    graph1.addEdge("CENTRAL_BUS_STAND", "RAILWAY_STATION", 20);


    graph1.addEdge("RAILWAY_STATION", "GATEWAY_OF_INDIA", 30);

cout<<"\n";


    graph1.printGraph();



    graph1.addEdge("COMMUNITY_KITCHEN", "NEW_PLACE", 30);
    graph1.printGraph();

    graph1.removeEdge("COMMUNITY_KITCHEN", "NEW_PLACE");
    graph1.printGraph();

    graph1.updateEdgeWeight("COMMUNITY_KITCHEN", "CENTRAL_BUS_STAND", 15);
    graph1.printGraph();

    graph1.bfs("COMMUNITY_KITCHEN");
    graph1.dfs("COMMUNITY_KITCHEN");

    graph1.topologicalSort();

    if (graph1.detectCycle()) {
        cout << "Graph contains a cycle\n";
    } else {
        cout << "Graph doesn't contain a cycle\n";
    }

    graph1.countNodes();
    graph1.countEdges();

    if (graph1.isConnected("COMMUNITY_KITCHEN")) {
        cout << "Graph is connected\n";
    } else {
        cout << "Graph is not connected\n";
    }

    unordered_map<string, vector<pair<string, int>>> transpose;
    graph1.transposeGraph(transpose);
    graph1.printTransposeGraph(transpose);

    return 0;
}




        case 4:

{

            FoodManagementSystem system;


            system.displayTitle();




            int choice;


            while (true)




            {

                cout << "Food Management System2 \nMenu:\n";

                cout << "1. Display Food List\n";

                cout << "2. Add Food Item\n";

                cout << "3. Delete Food Item\n";

                cout << "4. Update Food Quantity\n";

                cout << "5. Place Order\n";

                cout << "6. Display Total Cash\n";

                cout << "7. Backup Data\n";

                cout << "8. Sign Out\n";

                cout << "9. Exit\n";

                cout << "Enter your choice: ";

                cin >> choice;


                switch (choice)

            {


                case 1:

                    system.displayFoodList();


                    break;

                case 2:



                {


                    int serial;

                    string foodName;

                    int quantity;

                    float price;

                    cout << "Enter Serial: ";

                    cin >> serial;

                    cin.ignore();

                    getline(cin, foodName);
                    cout << "Enter Quantity: ";

                    cin >> quantity;
                    cout << "Enter Price: ";


                    cin >> price;

                    system.insertFood(serial, foodName, quantity, price);

                    break;

                }

                case 3:

                    {

                    int serial;


                    cout << "Enter Serial to Delete: ";


                    cin >> serial;

                    system.deleteFood(serial);

                    break;

                }




                case 4:

                {

                    int serial;

                    int newQuantity;

                    cout << "Enter Serial to Update: ";

                    cin >> serial;

                    cout << "Enter New Quantity: ";

                    cin >> newQuantity;

                    system.updateFood(serial, newQuantity);

                    break;

                }


                case 5:

                {

                    int serial;

                    int orderQuantity;


                    cout << "Enter Serial to Order: ";

                    cin >> serial;

                    cout << "Enter Quantity: ";

                    cin >> orderQuantity;

                    system.placeOrder(serial, orderQuantity);

                    break;

                }

                case 6:

                    system.displayTotalCash();


                    break;

                case 7:


                    system.backupData();

                    break;


                case 8:

                    cout << "Sign Out...\n";

                    system.signUp();


                    break;

                case 9:

                    system.exitProgram();

                    break;
                default:


                    cout << "Invalid choice! Try again.\n";

                }
            }


            break;
        }


      case 3:

        {
    bool loggedIn = false;
    int mainChoice;

    cout << "\n--- Welcome to Smart Food Management System\n\n";

    while (!loggedIn)

    {

        displayLine();

        cout << "\n1. Sign Up\n";

        cout << "\n2. Sign In\n";

        cout << "\nEnter your choice:\n ";

        cin >> mainChoice;

        if (mainChoice == 1) {
            signUp();
        } else if (mainChoice == 2) {
            loggedIn = signIn();
        } else {
            cout << "\nInvalid choice. Try again.\n";
        }
    }

    mainMenu();

    return 0;
}
              break;


        case 5:


            cout << "Exiting the program...\n";

            break;


        default:

        cout << "Invalid choice! Try again.\n";


        }

    }
    while (ch != 5);

    return 0;
}

