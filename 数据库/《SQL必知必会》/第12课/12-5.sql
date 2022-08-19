SELECT cust_name, SUM(item_price*quantity) AS total_price
FROM Customers, OrderItems, Orders
WHERE Customers.cust_id = Orders.cust_id
AND Orders.order_num = OrderItems.order_num
GROUP BY Customers.cust_id
HAVING SUM(item_price*quantity) >= 1000
ORDER BY cust_name;

SELECT cust_name, SUM(item_price*quantity) AS total_price
FROM Customers
INNER JOIN Orders ON Customers.cust_id = Orders.cust_id
INNER JOIN OrderItems ON Orders.order_num = OrderItems.order_num
GROUP BY Customers.cust_id
HAVING SUM(item_price*quantity) >= 1000
ORDER BY cust_name;