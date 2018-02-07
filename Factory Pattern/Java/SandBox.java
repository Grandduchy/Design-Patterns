package sandBox;



public class SandBox {
	public static void main(String[] args) {
		
		
	}
}










/* Builder pattern tries to eliminate the problem of

Pizza orderPizza(String type) {
	Pizza pizza;
	// --------------------------------
	// with each addition or removal of a class, we must initialize 
	// a new implementation each time which changes.
	if (type.equals(“cheese”)) {
		pizza = new CheesePizza();
	} else if (type.equals(“greek”) {
		pizza = new GreekPizza();
	} else if (type.equals(“pepperoni”) {
		pizza = new PepperoniPizza();
	} else if (type.equals(“clam”) {
		pizza = new ClamPizza();
	} else if (type.equals(“veggie”) {
		pizza = new VeggiePizza();
	}
	// --------------------------------
	
	// this stays the same so its ok
	pizza.prepare();
	pizza.bake();
	pizza.cut();
	pizza.box();
	return pizza;
}


*/