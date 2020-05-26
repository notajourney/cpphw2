/*
 * Graph.h
 *
 *  Created on: 21 במאי 2020
 *      Author: Ron Lavi
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include <iostream>
#include<vector>
#include "edge.h"
#include "node.h"
#include <algorithm>
#include <queue>
using namespace std;

class Graph {
	vector<node> nodes;
	vector<edge> edges;

public:
	Graph();
	virtual ~Graph();

	void add_node(node x) {
		if (node_exist(x)) {
			cout << x.val << " already exists" << endl;
			return;
		}

		this->nodes.push_back(x);

	}

	void add_edge(int src, int dest) {

		if (src == dest) {
			cout << "no self edges" << endl;
			return;
		}

		edge e { src, dest };
		if (node_exist(src) && node_exist(dest) && !edge_exist(e))

		{
			edges.push_back(e);
			return;
		}

		cout << "edge: " << "(" << src << "," << dest << ")"
				<< " already exists or not valid" << endl;
	}

	bool node_exist(node other) {
		bool exists = false;
		auto foo = [&](node vec_node)->void {
			if(vec_node.val == other.val) exists=true;
		};
		for_each(nodes.begin(), nodes.end(), foo);
		return exists;
	}

	bool edge_exist(edge e) {
		bool exists = false;
		auto foo =
				[&](edge vec_edge)->void {
					if(vec_edge.dest == e.dest && vec_edge.src == e.src) exists=true;
				};
		for_each(edges.begin(), edges.end(), foo);
		return exists;
	}

	vector<node> find_adjacent(node s) {

		vector<node> s_adj;
		auto foo = [&](edge vec_edge) {
			if(vec_edge.src == s.val)
			{
				s_adj.push_back(node(vec_edge.dest));
			}
		};
		for_each(edges.begin(), edges.end(), foo);
		return s_adj;

	}

	void print_node(node x) {

		cout << "Node: " << x.val << "||--> ";
		auto foo = [&](edge vec_edge)->void {
			if(vec_edge.src == x.val)
			{
				cout<<vec_edge.dest<<" ";
			}

		};
		for_each(edges.begin(), edges.end(), foo);

	}

	void print() {
		auto foo = [&](node x) {print_node(x);cout<<endl;};

		for_each(nodes.begin(), nodes.end(), foo);
	}

	node& get_node (node x){//node x: argument node

		if(!node_exist(x))

			cout<<"Error (get node) node: "<<x.val
					<<" does not exist"<<endl;


		node* n_ptr=NULL;
		auto foo = [&](node& n){ //node n: iterator node
			if(x.val==n.val)
			{
				n_ptr = &n;
			}
		};
		for_each(nodes.begin(), nodes.end(), foo);
		node&  n_ref=*(n_ptr);
		return  n_ref;

	}
	void BFS(node s) {

		auto foo = [&](node x) {x.set_distance(-1);};
		for_each(nodes.begin(), nodes.end(), foo);
		node& ss = get_node(s);
		ss.set_distance(0);
		vector<node> adj;
		queue<node> q;
		q.push(ss);

		while (q.size() != 0) {
			node& cur_node = get_node(q.front());
			q.pop();
			adj = find_adjacent(cur_node);

			auto update_if = [&](node adj){

				node& vec_adj = get_node(adj);
				if(vec_adj.distance == -1)
				{
					vec_adj.set_distance(1+cur_node.distance);
					q.push(vec_adj);
				}
			};



			for_each(adj.begin(), adj.end(), update_if);

		}

	}

	void print_BFS() {
		auto print = [&](node x) {
			cout<<"Node: "<<x.val<<" distance: "<<x.distance<<endl;
		};
		for_each(nodes.begin(), nodes.end(), print);
	}

};

#endif /* GRAPH_H_ */
