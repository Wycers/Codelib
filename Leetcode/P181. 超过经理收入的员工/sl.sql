SELECT e1.`Name` AS Employee FROM employee e1 inner JOIN employee e2
ON e1.ManagerId = e2.Id AND e1.Salary > e2.Salary;