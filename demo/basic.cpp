//vector of pair
vector<pair<int,int>>v;
v.push_back(make_pair(x,y));
v.first;

//stack of pair
stack<pair<int,int>>s;
s.push({x,y});
s.first


// ------------------------set-------------------------------

//set use red black tree 0(logn) 
count fun is used to find occurence of the number
but in set all number are unique so if element is 
present then count=1 

s.insert(2);
// set<int,greater<int>>s;- for decreasing

auto it=s.find(7) ---it give an iterator

//erase function
1) erase(it,s.end()) -remove from iterator to end of the set
2) erase(val) -- remove val 0(n) 
3) erase(it) --pass iterator and remove the val but take 0(1)


ex- 5, 10, 20
//lower bound
auto it=s.lower_bound(5)---5
auto it=s.lower_bound(6)---greater than val -- 10
auto it=s.lower_bound(20)---greater than max val -- s.end


ex- 5, 10, 20
//upper bound
auto it=s.upper_bound(5)---10
auto it=s.upper_bound(6)---greater than val -- 10
auto it=s.upper_bound(20)---greater than max val -- s.end



// ------------------------map-----------------------------------------

//insertion
1)m[5]=10;
2)m.insert({5,10});

//accessing
m.first,m.second

//logic
ex- m.insert({5,11}) X not update
ex- m[5]=11 update

//logic-2

ex- cout<<m[6] - if this value is not present in the map then it will create the key,value pair in the map key-5 val- default(may be 0)
  



//difference between bool visited[]--- no need of & ,vector<bool>&visited-- need of &