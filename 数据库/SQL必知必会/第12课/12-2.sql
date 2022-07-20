SELECT cust_name,
       order_num,
       (SELECT SUM(item_price*quantity)
       FROM OrderItems
       WHERE Orders.order_num = OrderItems.order_num) AS OrderTotal
FROM Customers, Orders
WHERE Customers.cust_id = Orders.cust_id
ORDER BY cust_name, order_num;

SELECT cust_name, Orders.order_num, SUM(item_price*quantity) AS OrderTotal
FROM Customers, Orders, OrderItems
WHERE Customers.cust_id = Orders.cust_id AND Orders.order_num = OrderItems.order_num
GROUP BY cust_name, Orders.order_num
ORDER BY cust_name, order_num;