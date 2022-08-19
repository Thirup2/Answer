SELECT prod_name, order_num
FROM Products
LEFT OUTER JOIN OrderItems ON Products.prod_id = OrderItems.prod_id
ORDER BY prod_name;