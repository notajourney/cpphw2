/*
 * node.h
 *
 *  Created on: 21 במאי 2020
 *      Author: Ron Lavi
 */

#ifndef NODE_H_
#define NODE_H_

class node {
public:
	int val;
	int distance;
	node(int val):val(val),distance(-1){}
	virtual ~node(){}
	void set_distance(int dis) {distance= dis;}
};

#endif /* NODE_H_ */
