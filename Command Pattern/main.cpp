#include "Stock.h"
#include "BuyStock.h"
#include "SellStock.h"
#include "Broker.h"

int main() {
	Stock abcStock;

	BuyStock buyStock(abcStock);
	SellStock sellStock(abcStock);

	Broker broker;
	broker.takeOrder(&buyStock);
	broker.takeOrder(&sellStock);

	broker.placeOrders();
}