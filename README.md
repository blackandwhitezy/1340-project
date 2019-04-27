 # 1340-project
1340 project stage 1

-Huang Hanting(3035534581)
-Zhong Yan(3035533989)

Idea 3: Cash register system

**Program Statement:** 

Shorten the grocery store waiting line for cashiers and maximize the profit.

**Program Setting:**

There is one line of customers with grocery waiting in line for the cashiers. The more the grocery one customer has, the time it takes to spend at the register will be longer. If the waiting time is longer than 15 minutes, the customers will leave without buying anything. Opening a new register costs an activation fee. 

**Program Feature:**
1. We will create a grocery file which includes grocery types, price and profit.
2. Read from grocery file: get input information: type of grocery and its profit, number of customers(at least 50 customers for testing).
3. For each customer the number of each product is randomly generated.
4. Calculate the processing time of one customer spent in the cashier, the time is proportional with the amount of grocery one customer has bought;
5. Calculate the profit each customer bring to the store.
6. Optimize the net profit by properly sequencing the customers. 
7. We will implement a new line if the porfit rest of the customers can bring is more than activation fee.
8. Optimize the number of cashier available due to the number of customers.

1340 project stage 2

***To compile the program. Use 'make Cash_Register_System' in Linux.***

**Notice: "Tab" in github Makefile doesn't work, it will be automatically converted to 8 space in Linux. You might need to change** **"space"s to "Tab" manully**
**Program Statement:**

The name of the program is "Cash_Register_System". It is built in a multi-file manner and equipped with a Makefile.
The core of this project is an algorithm sorting n customers who could occupy a cashier for different amount of time and bring diverse quantities of profit. We adopt the concept of 0-1 Knapsack Problem and realize it in the fucntions "arrange_line()" and "trace_line()" which sort and mark the customers chosen for the cashier repectively.


**Program Setting:**

We generate a long line of customers by the function "generate_random_customer()" with a user input of customer number not exceeding the limit of 500. We set the checking time for an item to 10 seconds, spill 15 minutes into 90 pieces which is recorded in the constant "TIME". We set the activation cost for a cashier to 250 based on reasonable matching to other parameters.

**Program Feature:**
1. We create a grocery file called *"goods.txt"* which includes grocery types and profit.
2. We read the grocery file and stored the profit and type of each grocery in "good[]" and "good_name[]". We distinguish diffenent goods with array index. We read number of customers in "main()" and stored it in "cus_no".
3. Function "generate_random_customers" generate the number of each product is for each customer grandomly. The customers created is stored in *"Raw_Customer.txt"*.
4 & 5. We define a structure called "customer" to store the number of items which is proportional to the checking time and profit of a customer. An array of customer type "line[]" stores the processing time of one customer spent in the cashier and the profit each customer bring to the store. The size of this array is defined by user input with the method of *dynamic programming*.
6. We use "arrange_line()" and "trace_line()" to fill a cashier and make the largest net profit. A while_loop in the "main()" checks recursively whether there is the nececity of opening a new chashier.  
7. The condition inside the while loop is to test if the porfit rest of the customers can bring is more than the activation fee.  A new line will be implemented if so.
8. After the while-loop, we can thus obtain the Optimal number of cashier. We *output* the cashier arrangement into *"Cashier_Arrangement.txt"* by "write_cashier_arrangement".
