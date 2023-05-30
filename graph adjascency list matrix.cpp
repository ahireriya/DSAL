#include<iostream>
#define MAX 30
using namespace std;

class node
{
    node *next;
    string city;
    int timeCost;
public:
    friend class graph;
    node()
    {
        next=NULL;
        city="";
        timeCost=-1;
    }
    node(string city,int weight)
    {
        next=NULL;
        this->city=city;
        timeCost=weight;
    }
};

class graph
{
    node *head[MAX];
    int n;
            
public:
	static int cnt;
	string vis[MAX];
	friend class que;
    graph(int num)
    {
        n=num;
        for(int i=0;i<n;i++)
            head[i]=NULL
    }
    void insert(string city1,string city2,int time);
    void readdata();
    int getindex(string s1);
    void bfs(string src);
    int visited(string city);
    void display();
};

int graph::cnt=0;
class que
{
    int f,r;
    public:
        string q[MAX];
    que()
    {
        f=r=-1;
    }
    int isQfull()
    {
        if(r==MAX-1)
            return 1;
        else
            return 0;
    }
    int isQempty()
    {
        if((f==-1)&& (r==-1))
            return 1;
        else
            return 0;
    }
    void add(string);
	int search(string);
    string del();
};

void que::add(string city)
{   
    if(isQfull())
        cout<<"\nSorry !! Queue is full....\n";
    else
    {
        if(f==-1)
        {
            f=r=0;
            q[r]=city;
        }
        else
        {
            r=r+1;
            q[r]=city;
        }
    }
}

string que::del()
{
	string city;
    if(isQempty())
        cout<<"\nSorry Q is empty...\n";
    else
    {
    	if(f==r)
    	{
		city=q[f];
    	f=r=-1;
        }
        else
        {
		
        city=q[f];
        f=f+1;
        }
       return city;
    }
}

int que::search(string city )
{
	if(r==-1 && f==-1)
	{
		return 0;		
	}
	else
	{
 		for(int i=f;i<=r;i++)
		{
			if(q[i]==city )
			return 1;
		}
		return 0;
   }
}

int graph:: visited(/* cnt,*/string city)
{
	for(int i=0;i<cnt;i++)
	{
		if(vis[i]==city)
			return 1;
	}
	return 0;
}

void graph::bfs(string src)
{   
    que qobj;
    node *start;
    string str;
      
    qobj.add(src);
   while(qobj.isQempty()==0)
   {   
        str=qobj.del();
        cout<<"\t"<<str;
        vis[cnt]=str;
        cnt++;
        int ind=getindex(str);
	    start=head[ind];
	    while(start->next!=NULL)
	    {
		    start=start->next;
		    if((!qobj.search(start->city))&&(!visited(start->city)))
		    qobj.add(start->city);
	    }
	} 
}

int graph::getindex(string s1)
{
    for(int i=0;i<n;i++)
    {
        if(head[i]->city==s1)
            return i;
    }
    return -1;
}

void graph::insert(string city1,string city2,int time)
{
    node *source;
    node *dest=new node(city2,time);
    int ind=getindex(city1);
    source=head[ind];
    while(source->next!=NULL)
        source=source->next;
        source->next=dest;
}

void graph::display()
{
    node *source;
    for(int i=0;i<n;i++)
    {
        source=head[i];
        while(source!=NULL)
        {
            cout<<source->city<<"("<<source->timeCost<<")""->";
            source=source->next;
        }
        cout<<"NULL"<<endl;
    }
}

void graph::readdata()
{
    string city1,city2,tmpcity;
    int fcost;
    int flight;
    cout<<"\nEnter City Details:\n";//number of vertices
    for(int i=0;i<n;i++)
    {
        head[i]=new node;
        cout<<"Enter name of city "<<i+1<<" ";
        cin>>head[i]->city;
    }
    cout<<"\nEnter Number of Flights to insert: ";//number of edges
    cin>>flight;
    for(int i=0;i<flight;i++)
    {
        cout<<"\nEnter Source:";
        cin>>city1;
        cout<<"Enter Destination:";
        cin>>city2;
        cout<<"Enter Time:";
        cin>>fcost;
        insert(city1,city2,fcost);
        insert(city2,city1,fcost);
    }
}

int main() {
    int number,choice;
	string city1;
    cout<<"\nEnter Number of Airport Stations:";
    cin>>number;
    graph g1(number);
    que q;
    do
    {
        cout<<"\n------Menu------"
            <<"\n1.Insert Flight detail"
            <<"\n2.Display"
            <<"\n3.BFS"
            <<"\n4.Exit"
            <<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                g1.readdata();
                break;
            case 2:
                cout <<"**Adjacency List**"<< endl;
                g1.display();
                break;                    
            case 3:     
                cout <<"Enter Staring City"<< endl;
                cin>>city1;
                cout<<"\n BFS Traversal of given graph is:\n";
                g1.bfs(city1);
                break;
            default:
                cout<<"\nWrong Choice";
        }
    }while(choice!=4);
    return 0;
}
