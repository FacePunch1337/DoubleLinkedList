#include "Header.h"

int main()
{

	List<int> list;
	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.Add(4);
	list.Print();
	list.DeleteData(3);
	list.Print();
	cout<<endl;
	system("pause");
	return 0;
}
