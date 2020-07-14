	
	
	#include <iostream>
	#include <string>
	#include <vector>
	
	using namespace std;
	
	class New_shop{
			//string list_name;
			public:
	        	string list_name;
				bool done= false;
				vector<pair<string, int>> elements;
	        		vector<bool> status;
	
	
			        void edititem(int item){
		
	        			string newprod;
	            			int new_qt;
	            			for(int i=0; i< elements.size(); i++){
	                			if(i == item){
	                    				cout << "Enter the updated name: " << endl;
	                    				cin.ignore();
	                    				getline(cin, newprod);
	                    				elements[i-1].first = newprod;
	
	                    				cout << "Enter the updated quantity: " << endl;
				                	cin >> new_qt;
	                    				elements[i-1].second = new_qt;
	
				                }
	            			}
	
	        		}
	
				//adding elements
				void add(string str, int a){
	            			elements.push_back(make_pair(str, a));
				}
				//end of adding elements
	
	        		//delete item
	       			void delete_item(int id){
	            			for(int i=0; i< elements.size(); i++){
	                			elements.erase(elements.begin() + id-1);
	            			}
	        		}
	
	
				void printVect(){
	            			for (int i=0; i<elements.size(); i++)
	           			{
	        				// "first" and "second" are used to access
	        				// 1st and 2nd element of pair respectively
	               				 cout << elements[i].first << " "
	               				 << elements[i].second << endl;
	            			}
				}
	
	};
	
	
	//template<typename _Ty1, typename _Ty2>
	ostream& operator<<(ostream& cout, New_shop shop) {
	    for (int i=0; i<shop.elements.size(); i++){
	        cout << shop.elements[i].first << " " << shop.elements[i].second << endl;
	    }
	    return cout;
	}
	
	
	
	new_shopping(New_shop shop1, vector<New_shop> shop_list){
	
	    int number_prod;
		string str;
	
	    cin.ignore();
		cout<< " enter the list name "<< endl;
		getline(cin, str);
	
	        shop1.list_name = str;
		string a;
	        int b;
			
		cout <<" How many products "<< endl;
		cin>>number_prod;
		for(int i=0; i< number_prod; i++){
	        	cout << "Enter the "<< i+1<< " product: "<< endl;
	                cin.ignore();
	                getline(cin, a);
	                cout<<"Enter quantity " << endl;
	                cin >> b ;
	                shop1.add(a, b);
	                shop1.status.push_back(false);
	                cout << endl;
	
		}
	
	
	
		cout <<" Entered values: " << endl;
		shop1.printVect();
	
	
		shop_list.push_back(shop1);	
		//shop_list.push_back(status);
	
	
		int shop , shop_number;
		cout << "WHAT IS THE NEXT STEP " << endl;
		cout<< " 1 TO SEE LISTS" << endl;
		cout << " 2 TO CREATE NEW SHOPPING LIST " << endl;
		cin >> shop;
		
		switch(shop){
			case 1:
	    			for ( auto & val: shop_list){
					int idn = 0;
	                        	cout<<"ID:"<<idn +1 <<"  " << val.list_name<<"\n";
	
	                    		idn++;
	                    	}
	
	                    }
	
	                    cout << "ENTER THE LIST INDEX" << endl;
	                    cin>> shop_number;
	
	                    for(int i = 0; i < shop_list[shop_number-1].elements.size(); i++){
	                        cout << shop_list[shop_number-1].elements[i].first << " " << shop_list[shop_number-1].elements[i].second<<
	                        (shop_list[shop_number-1].status[i]? "✔":" ") << endl;
	                    }
	
	
	                    int edit;
	                    cout<<"Select: \n 1 TO ADD ITEMS \n 2 TO EDIT \n 3 TO MARK/UNMARK AS DONE \n 4 TO DELETE ITEM" << endl;
	                    cin>> edit;
	                    switch(edit){
	                         case 1:
	                             {
	                               string newpro;
	                             int newqt;
	                             cout <<  " ENTER NEW PRODUCT " << endl;
	                             cin.ignore();
	                             getline(cin, newpro);
	                             cout << " ENTER ITS QUANTITY " << endl;
	                             cin >> newqt;
	                            shop_list[shop_number-1].add(newpro, newqt);
	
	
	                            cout<< "Updated list is: " << endl;
	                            for(int i = 0; i < shop_list[shop_number-1].elements.size(); i++){
	                            cout << shop_list[shop_number-1].elements[i].first << " " << shop_list[shop_number-1].elements[i].second<<
	                            (shop_list[shop_number-1].status[i]? "✔":" ") << endl;
	                            }
	                            }
	
	                            break;
	                        case 2:
	                            //2 TO EDIT
	                              {
	                                    cout << "ENTER THE PRODUCT ID " << endl;
	                                int editInt;
	                                //cin.ignore();
	                                cin>> editInt;
	                                //getline(cin, editInt);
	                                shop_list[shop_number-1].edititem(editInt);
	
	                                 cout<< "Updated list is: " << endl;
	                                for(int i = 0; i < shop_list[shop_number-1].elements.size(); i++){
	                                    cout << shop_list[shop_number-1].elements[i].first << " " << shop_list[shop_number-1].elements[i].second<<
	                                    (shop_list[shop_number-1].status[i]?  "  'TAKEN' " : " ") << endl;
	                                    }
	                              }
	                                break;
	                        case 3:
	                            //mark as done
	                            {
	                                cout << "CHOOSE AN INDEX TO MARK/UNMARK AS DONE" << endl;
	                                int id =0;
	                                while(id < shop_list[shop_number-1].elements.size()){
	
	                                    cout <<"ID:"<< id+1 <<"  " << shop_list[shop_number-1].elements[id].first <<
	                                     " "<< shop_list[shop_number-1].elements[id].second<< endl;
	                                    cout << endl;
	                                    id++;
	                                }
	                                int done_el;
	                                cin>> done_el;
	                                //shop_list[shop_number-1].status[done_el-1]=1;
	                                if(shop_list[shop_number-1].status[done_el-1]==0){
	                                    shop_list[shop_number-1].status[done_el-1]=1;
	                                } else{
	                                    shop_list[shop_number-1].status[done_el-1]=0;
	                                }
	
	                                cout<< "Updated list is: " << endl;
	                                for(int i = 0; i < shop_list[shop_number-1].elements.size(); i++){
	                                    cout << shop_list[shop_number-1].elements[i].first << " " << shop_list[shop_number-1].elements[i].second<<
	                                    (shop_list[shop_number-1].status[i]?  "  'TAKEN' " : " ") << endl;
	                                    }
	
	                            }
	                            break;
	                        case 4:
	                            //delete element
	                            {
	
	                                for(int i = 0; i < shop_list[shop_number-1].elements.size(); i++){
	                                    cout << shop_list[shop_number-1].elements[i].first << " " << shop_list[shop_number-1].elements[i].second<<
	                                    (shop_list[shop_number-1].status[i]?  "  'TAKEN' " : " ") << endl;
	                                    }
	                                    cout << "Enter the ID to delete the item"<< endl;
	                                    int del;
	                                    cin>> del;
	                                    shop_list[shop_number-1].delete_item(del);
	
	                            cout <<"Updated elements"<< endl;
	                            for(int i = 0; i < shop_list[shop_number-1].elements.size(); i++){
	                                    cout <<"ID: ('"<<i+1<<"')" << shop_list[shop_number-1].elements[i].first << " " << shop_list[shop_number-1].elements[i].second<<
	                                    (shop_list[shop_number-1].status[i]? "  'TAKEN' "  : " ") << endl;
	                                    }
	
	                            }
	
	
	                    }
	
	
	                        break;
	
	
	
	
	
	
	
	case 2:
	
	int a =0;
	while(a<2){
	    new_shopping( shop1, shop_list);
	    a++;
	}
	break;
	}
	
	
	}
	
	
	
	
	
	
	
	void shopping_list(vector<New_shop> list_shop){
	
	                for ( auto & val: list_shop){
	                    { int idn = 0;
	                        cout<<"ID: "<<idn +1 <<"  " << val.list_name<<"\n";
	
	                    idn++;
	                    }
	
	
	
	                }
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	int main(){
	
		//vector<New_shop> all_shop;
	
		//vector<vector<pair<string, int>>> all_lists;
		vector<string>list_title; //is it useful?
		vector<pair<string, int>> items;
		vector<New_shop> shop_list;
	    New_shop shop1;
	
		int init_value;
	
		cout << "------MY SHOPPING LIST PLANNER-------"<<endl;
		cout <<"---------------------------------------- \n\n"<<endl;
		cout <<"PRESS '1\' TO ACCESS YOUR SHOPPING LIST"<< endl;
		cout << "OR '2\' TO CREATE A NEW SHOPPING LIST"<<endl;
	
	
	
		cin >> init_value;
	
	
		switch(init_value){
			case 1:
	
	        shopping_list(shop_list);
	
	
			case 2:
	            new_shopping(shop1, shop_list);
	
	
	   /* for(int i = 0; i < shop_list.size(); i++)
	{
	     cout << shop_list[i].first << ", " << shop_list[i].second << endl;
	}*/
	
	/*
	for(int i=0; i< shop_list.size(); i++){
	   cout << shop_list.at(i);
	}*/
	
	/*
	 for(int j =0; j< shop_list.size(); j++){
	        cout << shop_list.elements[i][j].first << " " << shop_list.elements[i][j].second << endl;
	    }*/
	
	
	
				//shop1.elements.push_back(elements);
	
				//all_lists.push_back(elements);
				//shop_list.push_back(shop1);
	
	//tst 2
	
	
	            break;
				//all_shops.push_back(shop1);
				//make sure to acess also other item;
		}
	
	
	
	
		return 0;
	}
	

