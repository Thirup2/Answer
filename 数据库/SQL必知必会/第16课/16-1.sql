UPDATE Vendors
SET vend_state = UPPER(vend_state)
WHERE vend_country = 'USA';

UPDATE Customers
SET cust_state = UPPER(cust_state)
WHERE cust_country = 'USA';