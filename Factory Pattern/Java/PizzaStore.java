package sandBox;

public class PizzaStore {
	
	SimplePizzaFactory factory; // <-- the factory could be replaced with the stategy design pattern.
	
	public PizzaStore(SimplePizzaFactory factory) {
		this.factory = factory;
	}
	
	public Pizza orderPizza(String type) {
		Pizza pizza;
		pizza = factory.createPizza(type);

		pizza.prepare();
		pizza.bake();
		pizza.box();
		pizza.cut();
		return pizza;
	}
	

}
