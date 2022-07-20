SELECT Vendors.vend_id, COUNT(prod_id) AS prod_cnt
FROM Vendors
LEFT OUTER JOIN Products ON Vendors.vend_id = Products.vend_id
GROUP BY Vendors.vend_id
ORDER BY Vendors.vend_id;