CREATE VIEW CustomersWithOrders AS
SELECT Customers.*
FROM Customers, Orders
WHERE Customers.cust_id = Orders.cust_id;

SELECT * FROM CustomersWithOrders;
