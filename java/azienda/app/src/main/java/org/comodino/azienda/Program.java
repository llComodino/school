package org.comodino.azienda;

class Program {
  public static void main (String[] args) {

    Employee[] employees = new Employee[10];
    Manager manager = new Manager("Manager", "100100", "Sales", employees);

    Job job = new Job("xx-xx-xxxx", "xx-xx-xxxx", "description");

    String name = "";
    for (int i = 0; i < 10; i++) {
      name = name + i;
      employees[i] = new Employee(name, "id", job);
    }
  
    for (Employee em : employees) {
      System.out.println("Employee: " + em.toString());
    }

    System.out.println("Manager: " + manager.toString());

  }
}
