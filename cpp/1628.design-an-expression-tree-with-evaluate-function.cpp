/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    // define your fields here
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree representing it as a Node.
 */
class NodeTree: public Node{
	public:
	  NodeTree *left, *right;
	  string val;
	  NodeTree(string value):val(value){};
	  int evaluate() const override{
		  if(val == "*")return left->evaluate()*right->evaluate();
		  else if(val == "/")return left->evaluate()/right->evaluate();
		  else if(val == "+")return left->evaluate()+right->evaluate();
		  else if(val == "-")return left->evaluate()-right->evaluate();
		  else return stoi(val);
	  }
};
class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
       	   vector<NodeTree *> stack; 
	   unordered_set<string> isOperator = {"/","*","-","+"};
	   for(auto item:postfix){
		   if(isOperator.count(item)){
			   auto nodeRight = stack.back(); stack.pop_back();
			   auto nodeLeft = stack.back(); stack.pop_back();
			   NodeTree * current = new NodeTree(item);
			   current->left = nodeLeft;
			   current->right = nodeRight;
			   stack.push_back(current);

		   }else{
			   NodeTree * current = new NodeTree(item);
			   stack.push_back(current);
		   }
	   }
	   return stack.back();
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
