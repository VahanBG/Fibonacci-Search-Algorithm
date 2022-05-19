#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<forward_list>
#include<set>
#include<map>
#include<stack>


//List print
///void PrintList(std::list< int > & lst){
   // for(auto i = lst.begin() ; i != lst.end() ; ++i){
     //   std::cout<<*i<<std::endl;
//    }
//}
int main()
{    

    //VECTOR // պարապած դինամիկ զանգված
    //std::vector<int> myVector;
    //myVector.push_back(5555);
    
    
    // LIST        Երկկողմանի կապակցված դիմիկ ցուցակ դինամիկ տվյալների կառուցված, որտեղ արագ ջնջվում և մտցվում է էլեմենտը
  //  std::list<int> myList = {15,6,979,99};
   // myList.push_back(555);// ավելացնւմ է վերջից
    //myList.push_front(11);//ավելացնւմ է դիմացի ելեմենտը փոխելով այն
    //std::list<int>::iterator it = myList.begin();
    //PrintList(myList);
    //std::cout<<*it<<std::endl;
    //myList.sort();// դասվորում է էլեմենտները փոքրից մեծ
    //myList.pop_back;//ջնջում է վերջին էլէմենտը
    //myList.pop_front; // ջնջում է դիմացի էլէմենտը
    //myList.size(); //Էլեմենտների քնակ
    //myList.reverse();// շրջում է էլէմենտների դասավորվածությունը
    //myList.clear();//ջնջում է էլեմենտները
    // myList.unique();//ջնջում է իրար կողք գտնվող նույն էլէմենտները
    //myList.insert(it, 111 );//երկու արգումենտ, մեկը ցուցիչ իտերատոր , մյուսը հենց ելեմենտը որը պիտի դնենք
    //myList.erase( it , 444);// նույն պրինցիպով ինչ ինսեռտ
     // std::advance(it , 3 );//չենք կարա it + 3 գրենք, միայն ++, դրա համար այս ֆունկցիան է
     //myList.remove( it , 15) ; //եթե լինի կջնջի
      //myList.assign( 3 , 555);//նախ ջնջում է , հետո առաջին արգումենտ քանակնէ թե քանի հատ լցնի երկրորդ էլեմենտը
     //myList.assign( myList2.begin() , myList2.end()); //list2- @ copy kani list-i mech
//    PrintList(myList);
    //for(auto i = myList.begin() ; i != myList.end() ; i ++){
      //  std::cout<<*i <<std::endl;
    //}

   // FORWORD_LIST  միակողմանի կապակցված ցուցակ,կարող ենք ավելացնել և պակասացնել միայն ցուցակի դիմացից
   //std::forward_list<int> fl= {5,6,4};
   //fl.push_front(4);
  // std::forward_list<int>::iterator it = fl.begin();
   //it ++ ; ok e
   //it -- ; chi kareli
   //fl.insert_after( it , 9999) ; //տնւմ է 9999 ֊ ը it- ից հետո
   //fl.erase_after( it ) ; //ջնջում է հաջորդ էլեմենտը
   //կարանք վերջից insert -ով
  // fl.before_begin();//անում ենք որ առաջին էլեմենտին կարանաք կպնենք
   //for(auto el :fl){
     //  std::cout<<el<<std::endl;
   //}

   // ARRAY //ի տարբերություն վեկտորի , սա ստատիկ զանգված է []
   //std::array<int,4> arr = {1,94,77,9} ;//առաջին արգումենտը տիպն է , երկրորդը քանակը զանգվածի
   //arr.fill( -1 );//լցնում է զանգվածը -1 երով ;
   //arr.front(); //տալիս է առաջին էլեմենտը
   //arr.back();//տալիս է վրջին էլեմենտը

// deque // երկկողմանի կապակցված ցուցակ [] //հիբրիդ է վեկտորի և լիստի երկկապակցված ցուցակի
//std::deque<int> dq = {1,9,94};
//dq.push_back(); //վեկտորը չունի
//dq.push_front();//վեկտորը չունի
// SET /MULTISET  //երկուայակն բինար ծառ //դասավորված //չի կարում նույն արժեքով ելեմենտ պահի//չի կարող փոխել ինչ որ մեկի արժեքը
//std::set<int> mySet={5,35,45,11,86};
//auto it = mySet.find(10);//ման է գալի մեր ուզած էլեմենտը
//int value = 5 ;
//if(mySet.find(value) != mySet.end()){
  //  std::cout<<" tiv@ gtnvel e"<<endl;
//}
//else{
  //  std::cout<<" tiv@ chi gtnvel"<<std::endl;
//}
//mySet.erase(value);//ջնջում է եթե կա //վերադարձնում է եթե գթնի "1" , եթե չգտավ "0"
//mySet.insert(111);//եթեայն ավելացնում է վերադարձնում է "1",եթե գոյություն ունի "0"իտեռատորը ցույց կտա այդ էլեմենտի վրա
//for(auto &item : mySet){
  //  std::cout<<item<<std::endl;
//}

//for(int i = 0 ; i < 20 ; i ++){//կլցնի 0- 9 և դասավորված աճող
  //  mySet.insert(rand() % 10);
//}


//multiset
//std::multiset<int> myMultiset = {0,1,1,66,15,48,99};//էլի բինար ծառ է բայց կարանք նույն արժեքով մի քանի էլեմենտ լինի
 //auto it1 = myMultiset.lower_bound(1);//վերադարցնում է իտերատորը քթնված
 //auto it2 = myMultiset.upper_bound(1);// վերադարցնում է քթնվածի հաջորդ էլեմենտը.
 //auto a = myMultiset.equal_range(1);//վերադարցնում է միջակայքի թվեր, կվերադարցնի 1 եվ 15


// map/multimap //նույն պրինցիպով ինչ "set" , ուղակի այն պահում է զուգ էլելմենտներ, ինչ տիպի որ նշենք []
//std::pair<int, std::string> p ( 3 , "hello");//առաջին էլ․֊ը համարվում է բանալի, ըստ որի կազմվում է ծառը
//std::cout<<p.first<<std::endl;
//std::cout<<p.second<<std::endl;
///myMap.insert(std::make_pair(1 , "car"));//նույնն է
//myMap.insert(pair<int,std::string>(2 ,"car"));նույնն է
//myMap.emplace(3 , "monitor");//ավելի հարմար է
//auto it = myMap.find(22);//վերադարձնում է իտերատորը//եթե չի գտնում myMap.end()
//if(it != myMap.end()){ //ստուգում ա կա արդյոք 
//std::cout<<it->second<<std::endl;
//}
//else{
  //  std::cout<<"tiv@ chi gtnve";
//}
//եթե ուզում ենք ավելացնենք էլեմենտ որը կա, մեզ կվերադարցնի այն էլեմենտը որը կա , և ֆալս
//std::cout<<myMap[3];//կտպի 3֊ի զուգին "hello";
//myMap[3] = "vahan";//կարանք արժեքավորենք
//myMap.at(3) = "hiiii0";
//multimap// տարբերույունը որ կարող ենք նույն բանալիով երկու փոփոխական պահենք//չի կատարվում [] .at
//std::multimap<std::string , int> myMultimap;

////stack //ադապտոռ
std::stack<int> st;
st.push(2); //էլեմենտները դասավորվում են այն հաջորդականությամբ ինչ որ հայտարաում ենք
st.push(43);//սկզբից սարքում է կոպին, հետո այդ կոպին տեղափոխում է 
st.push(3);
st.emplace(9);//ավելի արագ է կոպի չի սարքում
//st.top();//վերադարձնում է վերջին էլեմենտը
//st.pop();//կջնջվի վերջին մուտք եղածը
std::cout<<st.top()<<std::endl;



return 0;
}