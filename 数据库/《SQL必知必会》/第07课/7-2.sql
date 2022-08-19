SELECT prod_id, prod_price, prod_price*0.9 AS sale_price
FROM Products
ORDER BY prod_id;
