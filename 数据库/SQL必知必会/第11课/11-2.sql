SELECT cust_id, order_date
FROM Orders
WHERE order_num IN (
    SELECT order_num
    FROM OrderItems
    WHERE prod_id='BR01')
ORDER BY order_date;
