SELECT cust_name, order_num
FROM Customers, Orders
WHERE Customers.cust_id = Orders.cust_id
ORDER BY cust_name, order_num;

SELECT cust_name, order_num
FROM Orders
INNER JOIN Customers ON Customers.cust_id = Orders.cust_id;
ORDER BY cust_name, order_num;