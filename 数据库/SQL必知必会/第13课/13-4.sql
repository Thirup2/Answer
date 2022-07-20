SELECT prod_name, COUNT(order_num) AS num_ord
FROM Products
LEFT OUTER JOIN OrderItems ON Products.prod_id = OrderItems.prod_id
GROUP BY prod_name
ORDER BY prod_name;