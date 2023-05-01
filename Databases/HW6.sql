-- Felecia Gonzalez

-- 1
select distinct lastName as "last names"
from employees
order by lastName;

-- 2
select city, state
from offices
where country = 'USA'
order by postalCode;

-- 3
select count(customerNumber) as "Forein  Customers with $10,000+ Credit Limit"
from customers
where not(country = 'USA') and creditLimit > 10000;

-- 4
select customerName as "Customer"
from customers
where state in ('CA', 'MA')
order by state, customerName;

-- 5
select count(customerNumber) as "Customers with a rep named Mike, Michael, Mihael, or Miguel."
from customers
where contactFirstName in('Mike', 'Michael', 'Mihael', 'Miguel');

-- 6
select concat('$', cast(avg(creditLimit) as char(8))) as "Average Credit Limit"
from customers
where creditLimit is not null;

-- 7

