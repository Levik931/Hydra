//Levik Khachadoorian
//CS/IS 211
//Lab 6
#include <iostream>
#include <string>
#include "LinkedList.h" // ADT list operations

void displayList(ListInterface< string>* listPtr)
{
	// cout << "The list contains " <<  endl;
	for (int pos = 1; pos <= listPtr->getLength(); pos++)
	{
		//note the assert will catch any attempts at getting entries at invalid positions
		cout << listPtr->getEntry(pos) << " ";
	} // end for
	 cout <<  endl;
}  // end displayList

void copyConstructorTester()
{
	LinkedList< string> list;
	 string items[] = { "zero", "one", "two", "three", "four", "five" };
	for (int i = 0; i < 6; i++)
	{
		 cout << "Adding " << items[i] <<  endl;
		bool success = list.insert(1, items[i]);
		if (!success)
			 cout << "Failed to add " << items[i] << " to the list." <<  endl;
	}
	displayList(&list);

	LinkedList< string> copyOfList(list);
	 cout << "Copy of list: ";
	displayList(&copyOfList);

	 cout << "The copied list: ";
	displayList(&list);
}  // end copyConstructorTester

void listTester(ListInterface< string>* listPtr)
{
	 string data[] = { "one", "two", "three", "four", "five", "six" };
	 cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" <<  endl;
	for (int i = 0; i < 6; i++)
	{
		if (listPtr->insert(i + 1, data[i]))
		{
			cout << "Inserted " << listPtr->getEntry(i + 1) << " at position " << (i + 1) <<  endl;
		}
		else
		{
			cout << "Cannot insert " << data[i] << " at position " << (i + 1) << endl;
		}
	}  // end for

	displayList(listPtr);

	cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 0 (false)" <<  endl;
	cout << "getLength returns : " << listPtr->getLength() << "; should be 5" <<  endl;

	 //note the assert will catch any attempts at getting entries at invalid positions
	cout << "The entry at position 4 is " << listPtr->getEntry(4) << "; should be four" <<  endl;
	
	cout << "After replacing the entry at position 3 with XXX: ";
	
	 //note the assert will catch any attempts at replacing entries at invalid positions 
	listPtr->replace(3, "XXX");
	
	displayList(listPtr);

	cout << "remove(2): returns " << listPtr->remove(2) << "; should be 1 (true)" <<  endl;
	cout << "remove(1): returns " << listPtr->remove(1) << "; should be 1 (true)" <<  endl;
	cout << "remove(6): returns " << listPtr->remove(6) << "; should be 0 (false)" <<  endl;
	displayList(listPtr);

	cout << "clear: " <<  endl;
	listPtr->clear();
	cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" <<  endl;

	

} // end listTester

int main()
{
    auto start = chrono::high_resolution_clock::now();
    string theString;
    string name,name2,name3,name4;
    cout<<"Please enter 3 Strings to begin the fight: "<<endl;
    getline(cin, name); //O(1)
    getline(cin,name2); //O(1)
    getline(cin,name3); //O(1)
    
	ListInterface<string>* listPtr = new LinkedList< string>();
    listPtr->insert(1,name); //O(1)
    listPtr->insert(2,name2); //O(1)
    listPtr->insert(3,name3);//O(1)
    
    while(!listPtr->isEmpty()){ //O(n)
        
        theString=listPtr->getEntry(1); //O(1)
        listPtr->remove(1); //O(1)
        
        
       
        if(theString.size()>1) //O(n)  -> Overal O(n^2)
        {
    theString=theString.substr(1);//O(1)
    listPtr->insert(listPtr->getLength()+1, theString);//O(1)
    listPtr->insert(listPtr->getLength()+1, theString);//O(1)
        }
            
        displayList(listPtr);//O(1)
        
        }
    
    auto stop = chrono::high_resolution_clock::now();
    auto time = chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    cout<<"The time was: "<<time<<endl;
    cout<<endl;
    cout<<endl;

    
    //Computation unit is Assignments and overal time complexity is O(n^2) Quadratic
    // n chars in initial string
    //1 char :1153238417 NANO seconds
    //2 char :999009750 NANO seconds
    //3 char :2136618250 NANO seconds
    //4 char :2048122291 NANO seconds
    //5 char :1534072000 NANO seconds
   //10 char :3349799000 NANO seconds
   //11 char :6364997209 NANO seconds
   //12 char :18912036541 NANO seconds
   
    // NOW TESTING THE TIME CONSUMPTION FOR REMOVING THE LONGEST STRING FROM THE LIST
    // NOW TESTING THE TIME CONSUMPTION  FOR REMOVING THE LONGEST STRING FROM THE LIST
    ListInterface<string>* listPtrRemoving  = new LinkedList< string>();
    listPtrRemoving->insert(1,"Program"); //O(1)
    listPtrRemoving->insert(2,"Advanced"); //O(1)
    listPtrRemoving->insert(3,"Name");//O(1)
    listPtrRemoving->insert(4,"Linked"); //O(1)
    
    auto start1 = chrono::high_resolution_clock::now(); // time start to remove the longest
    
    double largest=listPtrRemoving->getEntry(1).length();
    int position=1;
    for(int i=2; i<listPtrRemoving->getLength()-1;i++)
    {
        if ( listPtrRemoving->getEntry(i).length() > largest)
        {
            position=i;
        }
     
    };

    listPtrRemoving->remove(position);
    auto stops = chrono::high_resolution_clock::now();
    auto time1 = chrono::duration_cast<std::chrono::nanoseconds>(stops - start1).count();
    cout<<endl;
    cout<<"The list after removidng the longest string:"<<endl;
    displayList(listPtrRemoving);
    cout<<"time consumed: "<<time1;
    cout<<endl;
    
    
    
    // NOW TESTING THE TIME CONSUMPTION  N FOR REMOVING THE SHORTEST STRING FROM THE LIST
    // NOW TESTING THE TIME CONSUMPTION  FOR REMOVING THE SHORTEST STRING FROM THE LIST
    
    ListInterface<string>* listPtrRemovingShortest  = new LinkedList< string>();
    listPtrRemovingShortest->insert(1,"AdvancedC++"); //O(1)
    listPtrRemovingShortest->insert(2,"Name"); //O(1)
    listPtrRemovingShortest->insert(3,"Program");//O(1)
    listPtrRemovingShortest->insert(4,"Linked"); //O(1)
    
    auto start2 = chrono::high_resolution_clock::now(); // time start to remove the longest
    
    double shortest=listPtrRemovingShortest->getEntry(1).length();
    int position1=1;
    for(int i=2; i<listPtrRemovingShortest->getLength()-1;i++)
    {
        if ( listPtrRemovingShortest->getEntry(i).length() < shortest)
        {
            position1=i;
        }
     
    };
    
    listPtrRemovingShortest->remove(position1);
    auto stop2 = chrono::high_resolution_clock::now();
    auto time3 = chrono::duration_cast<std::chrono::nanoseconds>(stop2 - start2).count();
    cout<<endl;
    cout<<"The list after removidng the Shorest string:"<<endl;
    displayList(listPtrRemovingShortest);
    cout<<"time consumed: "<<time3;
    cout<<endl;
    // Removing the shortest string take just a little bit less time than the longest one.
	return 0;
}  // end main

