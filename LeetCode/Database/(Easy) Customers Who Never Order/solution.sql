# Write your MySQL query statement below
# select Name as Customers
# from Customers
# where Customers.id not in (select CustomerId from Orders);

# another solution using join
select Name as Customers
from Customers c
left join Orders o on c.id = o.CustomerID
where o.id is NULL;