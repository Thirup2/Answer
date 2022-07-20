SELECT cust_id, (SELECT SUM(item_price*quantity)
                 FROM OrderItems
                 WHERE Orders.order_num = OrderItems.order_num) AS total_ordered
FROM Orders
ORDER BY total_ordered DESC;
