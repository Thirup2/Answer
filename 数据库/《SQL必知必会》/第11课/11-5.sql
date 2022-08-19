SELECT prod_name, 
       (SELECT SUM(quantity)
       FROM OrderItems
       WHERE Products.prod_id=OrderItems.prod_id) AS quant_sold
FROM Products;
