/**
 * Created by Kalpathi Subramanian, 1/30/18
 * krs@uncc.edu
 */

#include "Bridges.h"
#include <SLelement.h>
#include "fighter.h"
#include <iostream>
using namespace std;

using namespace bridges;

int main () {
    Bridges *bridges =  new Bridges(222, "scrmbld",
                                "347981115445");

	// create the linked list elements with
	// student data
	SLelement<Fighter> *el0 = new SLelement<Fighter>(
		Fighter("orc", 10, 5, 0.3, 7), "");
	SLelement<Fighter> *e11 = new SLelement<Fighter>(
		Fighter("pork", 10, 5, 0.3, 7), "");
	//  link the elements
	cout << e11->getValue() << endl;
	el0->setNext(e11);

	// iterate through the list and add visual attributes
	// to the elements; set the element color to the favorite
	// color and the link to the disliked color
	SLelement<Fighter> *currentElement = el0;
	while (currentElement != nullptr) {
		// color the node
		Fighter si = currentElement->getValue();
		currentElement->getVisualizer()->setColor("blue");

		if (currentElement->getNext() != nullptr) {

			// color the link
			currentElement->getLinkVisualizer(currentElement->getNext())->setColor("red");
			// adjust link thickness
			currentElement->getLinkVisualizer(currentElement->getNext())->setThickness(5.0);//75 percent thinner
		}

		// set the label to the student info (label created in
		// StudentInfo class
		currentElement->setLabel(si.get_name());

		currentElement = currentElement->getNext();
	}

	bridges->setDataStructure(el0);
	bridges->visualize();
}
