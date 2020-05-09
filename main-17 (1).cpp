
#include <iostream>
#include<string>
using namespace std;

class linkedBST{ //this class will be an alphabetical Binary Search Tree, storing weight and name, using links rather than arrays
private:
    struct node{ //this struct will be used as the node in the BST
        string name; //this string variable will be used to store names in each node; names will be keys
        int weight; //this integer variable will hold the node person's weight
        node *lchild=NULL, *rchild=NULL; //each node will have a set of pointers for the left and right child which may be utilized when more nodes are added after
    };
    node *temp, *root=NULL; //temp and root pointers are used in order to traverse the tree and to keep record of the root of the tree, respectively
public:
    void add(string Newname, int Newweight){//add function will add a new person's name and weight to the tree, using their name as the key
        node *NewNode = new node; //creating a node pointer to a newly created node
        if (root==NULL){ //if the root of the tree is NULL, it means that the tree is empty. So if the tree is empty, the if-suite will execute
            root = NewNode;//the root pointer will then point to the new node if the tree is empty
            NewNode->name=Newname; //the new node's name variable will then be stored with the new name passed into the function
            NewNode->weight=Newweight; //the new node's weight variable will then be stored with the new person's weight passed into the function
        }
        else{ //this else-suite will then execute if the tree is NOT empty, meaning nodes already exist in the tree
            temp = root; //the temp pointer used in order to traverse the tree will be initialized to the root of the tree
            int n = 0; //this integer n will be used in order to compare the starting letters of each person's name. starts at n=0 to compare the [0] index of each person's name and will increase in size if the first letter is same
            while (true){//this while loop is utilized to iterate over the tree depending each person's name, in order to find a free position to input the new node
                if (Newname[n]<temp->name[n]){ //if the new person's name passed into the function is before the temp node's name alphabetically, this if-suite will execute
                    if (temp->lchild==NULL){ //if the left child of the temp node is empty, then the empty spot will be fulfilled by the new node being created. This if-suite will execute
                        temp->lchild=NewNode; //the temp's left child pointer will be assigned to the new node being created
                        NewNode->name=Newname; //the new node's name variable will then be stored with the new name passed into the function
                        NewNode->weight=Newweight;//the new node's weight variable will then be stored with the new person's weight passed into the function
                        break; //once the new node has been added to the tree, the while-loop will be terminated
                    }
                    else{ //this else-suite will execute if the left child pointer is not empty
                        temp=temp->lchild; //the temp pointer will traverse to its left and restart the while loop
                        n=0;
                    }
                }
                else if (Newname[n]>temp->name[n]){ //if the new person's name passed into the function is after the temp node's name alphabetically, this else-if-suite will execute
                    if (temp->rchild==NULL){//if the right child of the temp node is empty, then the empty spot will be fulfilled by the new node being created. This if-suite will execute
                        temp->rchild=NewNode;//the temp's right child pointer will be assigned to the new node being created
                        NewNode->name=Newname;//the new node's name variable will then be stored with the new name passed into the function
                        NewNode->weight=Newweight;//the new node's weight variable will then be stored with the new person's weight passed into the function
                        break;//once the new node has been added to the tree, the while-loop will be terminated
                    }
                    else{//this else-suite will execute if the right child pointer is not empty
                        temp=temp->rchild; //the temp pointer will traverse to its right and restart the while loop
                        n=0;
                    }
                }
                else if (Newname[n]==temp->name[n]){ //if the first letter matches, it will go down the name's next letter to compare
                    n++; //the increment will allow to compare the next character of the name
                }
                
            }
        }
        
    }
    
    void printpre(){ //this function prints the preordered tree and should be called from main
        cout<<"The tree preorder: "<<endl;
        preorder(root); //this function calls the preorder function, passing in the root of the tree
        cout<<endl<<endl;
    }
    void printin(){//this function prints the inordered tree and should be called from main
        cout<<"The tree inorder: "<<endl;
        inorder(root);//this function calls the inorder function, passing in the root of the tree
        cout<<endl<<endl;
    }
    void printpost(){//this function prints the postordered tree and should be called from main
        cout<<"The tree postorder: "<<endl;
        postorder(root); //this function calls the postorder function, passing in the root of the tree
        cout<<endl<<endl;
    }
    
    void preorder(node* node1){ //this is the recursive function used to print the tree in preorder
        if (node1 == NULL){ //this if-suite will be executed if the traversing node does not exist--base case to the recursive function
            return;//return statement will unwind the recursion
        }
        cout<<node1->name<<"--"<<node1->weight<<", "; //since this function is preorder, it will visit the node first by printing the name and weight before traversing left and right afterwards
        preorder(node1->lchild); //it will proceed to traverse left into the tree by using recursion and calling itself
        preorder(node1->rchild); //finally, it will proceed to traverse right into the tree by using recursion and calling itself
    }
    
    void inorder(node* node1){//this is the recursive function used to print the tree inorder
        if (node1 == NULL){//this if-suite will be executed if the traversing node does not exist--base case to the recursive function
            return;//return statement will unwind the recursion
        }
        inorder(node1->lchild); //for inorder function, the function will traverse left first by using recursion and calling itself
        cout<<node1->name<<"--"<<node1->weight<<", "; //since this function is inorder, it will visit the node after traversing left
        inorder(node1->rchild);//for inorder function, the function will traverse right last by using recursion and calling itself
    }
    
    void postorder(node* node1){//this is the recursive function used to print the tree postorder
        if (node1 == NULL){//this if-suite will be executed if the traversing node does not exist--base case to the recursive function
            return;//return statement will unwind the recursion
        }
        postorder(node1->lchild);//for postorder function, the function will traverse left first by using recursion and calling itself
        postorder(node1->rchild);//for postorder function, the function will traverse right second by using recursion and calling itself
        cout<<node1->name<<"--"<<node1->weight<<", ";  //since this function is postorder, it will visit the node last
    }
    
    void printheight(){ //this function prints the height of the tree in a complete sentence and should be called from main
        cout<<"Height of tree: "<<height(root)<<endl<<endl; //this print statement calls the height function and passes the root of the tree into the recursive function
    }
    
    int height(node*node1){ //this recursive function calculates the height of the binary  search tree
        if(node1==NULL){ //this if-suite will be executed if the traversing node does not exist--base case to the recursive function
            return -1; //returns -1 indicating that the node does not exist and therefore has negative height
        }
        else{
            int leftheight=height(node1->lchild); //recursive call to itself in order to find the height of the left subtree
            int rightheight=height(node1->rchild);//recursive call to itself in order to find the height of the right subtree
            if (leftheight>=rightheight){ //if-suite will execute if the left subtree is taller or equal to the right
                return leftheight+1;//this return statement returns the value of the left subtree +1 in order to accumulate height
            }
            else{ //this else-suite will execute if the right subtree is taller
                return rightheight+1; //will return the value of the taller subtree +1 in order to accumulate height
            }
        }
    }
    
    void printleafcount(){ //void function used to print the number of leaves in the tree in a full sentence
        cout<<"Number of leaves in tree: "<<leafcount(root)<<endl<<endl; //this print statement calls the leaf count function and integrates the number into the sentence
    }
    
    int leafcount(node* node1){ //this is the function used to recursively calculate the number of leaves in the tree
        if(node1==NULL){ //this if-suite will be executed if the traversing node does not exist--base case to the recursive function
            return 0; //returns 0 indicating that this node is not a leaf
        }
        else if(node1->lchild==NULL && node1->rchild==NULL){ //this if-suite will be executed if the traversing node does not have children--another base case to the recursive function
            return 1; //returns 1 indicating that this node is a leaf
        }
        else{ //this else-suite will be used to if the temp node is neither a leaf nor a non-existent node
            int leftleaf= leafcount(node1->lchild); //recursively calls itself to find the number of leaves in the left subtree
            int rightleaf= leafcount(node1->rchild);//recursively calls itself to find the number of leaves in the right subtree
            return (leftleaf + rightleaf); //returns the total number of leaves in the left and right subtree combined
        }
    }
    
    void printmin(){ //this function prints the name and weight of the person with the lowest weight in the tree, in sentence form
        temp=root; //initializes the temp pointer to the root noode of the tree
        findmin(root); //passes the root node into the recursive find minimum weight function
        cout<<"Minimum weight in tree: "<<temp->name<<"--"<<temp->weight<<endl<<endl; //this print statement prints the person with the lowest weight's name and weight in sentence form
    }
    
    void findmin(node* node1){//recursive function to find the minimum weight of all the people in the tree
        if (node1 == NULL){ //this if-suite will be executed if the traversing node does not exist--base case to the recursive function
            return; //unwinds the recursive function
        }
        else if(node1->weight<temp->weight){//if the recursive node's weight is less than the current temp node's weight, the else-if-suite will execute
            temp=node1; //the temp pointer will then be assigned to the new minimum recursive node
        }
        findmin(node1->lchild); //this function will traverse into the left subtree to find the lowest value via a recursive call
        findmin(node1->rchild);//this function will traverse into the right subtree to find the lowest value via a recursive call
    }
    
    void printfirstalpha(){ //this void function prints the first alphabetical name
        temp=root; //the temp pointer will be assigned to the root of the binary search tree
        while (true){ //this while-loop is used to iterate all the way to the left most node of the tree, indicating the first alphabetical name
            if(temp->lchild==NULL){ //the absence of a left child indicates that the node is the left most of the tree
                cout<<"First alphabetical name: "<<temp->name;//printing the first alphabetical name
                break; //terminates the while-loop
            }
            else{ //else-suite will execute if a left child exists
                temp=temp->lchild; //traverses to the left child of the node and then continues to loop
            }
        }
        cout<<endl<<endl;
    }
    
    
    void search(string name){ //this function searches the tree for a specific name and returns the person's name and weight
        temp=root; //the temp pointer will be initialized to the root node of the tree
        int n=0; //this integer n will be used in order to compare the starting letters of each person's name. starts at n=0 to compare the [0] index of each person's name and will increase in size if the first letter is same
        while (true){ //while-loop will iterate over the tree
            if(temp==NULL){ //if the temp pointer is NULL, it indicates that no match for the name was found
                break; //while-loop will be terminated when no mtch is found
            }
            else if (name[n]<temp->name[n]){//if the first character of the name passed into the function is before the first character of the temp node's name, the if-suite will terminate
                temp=temp->lchild; //the temp node traverses to the left
                n=0;//n resets to 0
            }
            else if (name[n]>temp->name[n]){//if the first character of the name passed into the function is after the first character of the temp node's name, the else-if-suite will execute
                temp=temp->rchild;//the temp node traverses to the right
                n=0;//n resets to 0
            }
            else if (name[n]==temp->name[n]){//if the first character of the name passed into the function is same as the first character of the temp node's name, the else-if-suite will execute
                if(name==temp->name){ //if the name string passed into the function is exactly the same to the temp node's string name, this if-suite will execute as the match is found
                    break; //the while-loop will terminate when a match is found
                }
                else{ //else-suite will execute if the name string passed into the function is not exactly the same to the temp node's string name
                    n++; //n will increment allowing for the next character in the name strings to be compared
                }
            }
        }
        if(temp==NULL){ //this if-suite will execute if the temp pointer is NULL, meaning that no match was found
            cout<<endl<<"NO MATCH EXISTS"; //print statement indicating no match
        }
        else{ //else-suite executed to print name and weight of the temp node
            cout<<endl<<"MATCH: "<<temp->name<<"--"<<temp->weight; //printing the name and weight of the found match
        }
        cout<<endl<<endl;
    }
};

int main(){ //main will be used to run and test the code
    linkedBST test; //creates a linkedBST object in order to begin building a binary search tree
    string name; //string variable is created in order to store names enetered by the user
    int weight, x; //weight and x variable are created. weight variable will be used to store user entered weights while x will be used to store values entered by user to continue or stop a loop
    for(int i=1; i<16; i++){//for-loop will loop 15 times in order to store and add 15 records in the binary search tree
        cout<<"Enter person #"<<i<<"'s name to be added into BST: "; //prompting the user to input i user's name
        getline(cin, name); //reading the user's name input into name variabe
        cout<<"Enter "<<name<<"'s "<<"weight: ";//prompting the user to input i user's weight value
        cin>>weight; //reading the user's weight input into weight variable
        test.add(name, weight); //calling the add function with the user's inputted name and weight in order to build the BST
        cin.ignore(); //to clear the input buffer of the new line
    }
    cout<<endl<<endl;
    test.printpre(); //calling the preorder print function in order to print the tree in preorder
    test.printin();//calling the inorder print function in order to print the tree inorder
    test.printpost();//calling the postorder print function in order to print the tree in postorder
    test.printheight(); // calling the tree height print function in order to print the tree's height
    test.printleafcount(); //calling printleafcount() in order to print the number of leaves in the tree
    test.printmin(); //calling printmin() in order to print the minimum weight of all the nodes in the tree
    test.printfirstalpha(); // calling printfirstalpha() in order to print the first alphabetical name in the tree
    
    while(true){ //while-loop used to continuously prompt the user to enter a name to search
        cout<<"Enter any number to search a name, -1 to quit: "; //prompting the user to enter any number to search and -1 to quit
        cin>>x; //storing the input into x
        cin.ignore(); //clearing the input buffer of a new line
        if (x==-1){ //if the user inputs -1 to quit, the if-suite will execute
            break; //the while-loop will terminate
        }
        cout<<"Enter name to search: "; //prompting the user to enter a name to search for in the tree
        getline(cin, name); //storing the user input into name
        test.search(name); //calling the search function using the user inputted name
    }
    
    
}


// PROGRAM OUTPUT LINE 245 TO 335
/*
 Enter person #1's name to be added into BST: Ryan
 Enter Ryan's weight: 140
 Enter person #2's name to be added into BST: Joe
 Enter Joe's weight: 420
 Enter person #3's name to be added into BST: Syed
 Enter Syed's weight: 500
 Enter person #4's name to be added into BST: Nick
 Enter Nick's weight: 200
 Enter person #5's name to be added into BST: Kate
 Enter Kate's weight: 150
 Enter person #6's name to be added into BST: Rex
 Enter Rex's weight: 155
 Enter person #7's name to be added into BST: Lorne
 Enter Lorne's weight: 239
 Enter person #8's name to be added into BST: Amy
 Enter Amy's weight: 105
 Enter person #9's name to be added into BST: Conan
 Enter Conan's weight: 205
 Enter person #10's name to be added into BST: Sam
 Enter Sam's weight: 160
 Enter person #11's name to be added into BST: Tre
 Enter Tre's weight: 100
 Enter person #12's name to be added into BST: Vivian
 Enter Vivian's weight: 666
 Enter person #13's name to be added into BST: Uriah
 Enter Uriah's weight: 197
 Enter person #14's name to be added into BST: Wendy
 Enter Wendy's weight: 400
 Enter person #15's name to be added into BST: Xavier
 Enter Xavier's weight: 170


 The tree preorder:
 Ryan--140, Joe--420, Amy--105, Conan--205, Nick--200, Kate--150, Lorne--239, Rex--155, Syed--500, Sam--160, Tre--100, Vivian--666, Uriah--197, Wendy--400, Xavier--170,

 The tree inorder:
 Amy--105, Conan--205, Joe--420, Kate--150, Lorne--239, Nick--200, Rex--155, Ryan--140, Sam--160, Syed--500, Tre--100, Uriah--197, Vivian--666, Wendy--400, Xavier--170,

 The tree postorder:
 Conan--205, Amy--105, Lorne--239, Kate--150, Rex--155, Nick--200, Joe--420, Sam--160, Uriah--197, Xavier--170, Wendy--400, Vivian--666, Tre--100, Syed--500, Ryan--140,

 Height of tree: 5

 Number of leaves in tree: 6

 Minimum weight in tree: Tre--100

 First alphabetical name: Amy

 Enter any number to search a name, -1 to quit: 5
 Enter name to search: John

 NO MATCH EXISTS

 Enter any number to search a name, -1 to quit: 7
 Enter name to search: Conando

 NO MATCH EXISTS

 Enter any number to search a name, -1 to quit: 0
 Enter name to search: Tre

 MATCH: Tre--100

 Enter any number to search a name, -1 to quit: 9
 Enter name to search: Lorne

 MATCH: Lorne--239

 Enter any number to search a name, -1 to quit: 0
 Enter name to search: Nick

 MATCH: Nick--200

 Enter any number to search a name, -1 to quit: 8
 Enter name to search: Samantha

 NO MATCH EXISTS

 Enter any number to search a name, -1 to quit: 6
 Enter name to search: Sam

 MATCH: Sam--160

 Enter any number to search a name, -1 to quit: 0
 Enter name to search: Ryan

 MATCH: Ryan--140

 Enter any number to search a name, -1 to quit: -1
 Program ended with exit code: 0
 
 */
