/*
 * Helper.h
 *
 *  Created on: 22 במאי 2020
 *      Author: Ron Lavi
 */

#ifndef HELPER_H_
#define HELPER_H_

class Helper {
public:
	enum user_cmd {
		load, outbound, inbound, uniExpress, multiExpress, print, illegal
	};

	Helper() {

		cout<<"helper ctor"<<endl;

	}
	virtual ~Helper() {

	}

	void is_command(string input)
	{
		cout<<"crap";

	}

	void f(string s){
		cout<<"f"<<endl;
	}

};


#endif /* HELPER_H_ */
