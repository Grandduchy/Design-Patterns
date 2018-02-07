package sandBox;

public class SimplePizzaFactory {

	// This entire class could be erased and the function put statically in Pizza.
	// However this erases mobility, as later if you have different styles depending on the factory (cheese, sauce, vegtables)
	// then you would have a very long function for each different type and variations
	// It would be better for this class to be abstract and have many different types of factories that each
	// pizza store could call dependent on the interface of the method.
	// The book goes much more in depth, however this is the basic principle of this design pattern
	public Pizza createPizza(String type) { // <- function is also called a Factory function
		Pizza pizza = null;
		if (type.equals("Cheese")) {
			pizza = new CheesePizza();
		}
		else if (type.equals("Pepperoni")) {
			pizza = new PepperoniPizza();
		}
		return pizza;
	}

}


class CheesePizza implements Pizza {

	@Override
	public void prepare() {}

	@Override
	public void bake() {}

	@Override
	public void cut() {}

	@Override
	public void box() {}
	
}

class PepperoniPizza implements Pizza {

	@Override
	public void prepare() {}

	@Override
	public void bake() {}

	@Override
	public void cut() {}

	@Override
	public void box() {}
	
}