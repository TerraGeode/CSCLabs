-- Felecia Gonzalez

-- 1
select city
from customer
select city where country = 'France' and city in (select city, count(customernum) from customer group by city having count(customernum) = 1)
order by city;

-- 2
select concat(contactLastName, ', ', contactFirstName) as "Contact Name"
from customers
where city like 'San%'
order by contactLastName, contactFirstName;

-- 3
select concat('$', cast(sum(amount) as char(10))) as 'Grand Total'
from payments;

-- 4
select distinct productVendor
from products join orderdetails on orderdetails.productCode = products.productCode
where priceEach >= 2.5*buyPrice
order by productVendor;

-- 5
select emp.firstName as 'First Name', emp.lastName as 'Last Name', sup.firstName as 'Sup First', sup.lastName as 'Sup last'
from employees emp join employees sup on emp.reportsTo = sup.employeeNumber
where emp.employeeNumber in (select distinct reportsTo from employees)
order by emp.lastName, emp.firstName;

--6
select customerName
from customers left join orders on customers.customerNumber = orders.customerNumber
where status not in ('Shipped', 'Resolved', 'On Hold', 'Disputed', 'In Process')
order by customerName;

-- 7
select count(orderNumber)
from orders
where customerNumber = 141 and datediff(day, orderDate, shippedDate) < 5;

-- 8
select customerName
from customers join orders on customers.customerNumber = orders.customerNumber join orderdetails on orders.orderNumber = orderdetails.orderNumber
