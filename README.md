# Algorithm

###### 알고리즘을 공부하는데 유용한 정보

---

#### 1. c++ 자료형 범위

|         구분         |    자료형     |                            크기                             |                        범위                        |
| :------------------: | :-----------: | :---------------------------------------------------------: | :------------------------------------------------: |
|        기본형        |     void      |                              –                              |                         –                          |
|        문자형        | (signed) char |                           1 byte                            |                     -128 ~ 127                     |
|    unsigned char     |    1 byte     |                           0 ~ 255                           |                                                    |
|       wchar_t        |    2 byte     |                         0 ~ 65,535                          |                                                    |
|        정수형        |     bool      |                           1 byte                            |                       0 ~ 1                        |
| (signed) short (int) |    2 byte     |                      -32,768 ~ 32,767                       |                                                    |
| unsigned short (int) |    4 byte     |                         0 ~ 65,535                          |                                                    |
|     (signed) int     |    4 byte     |               -2,147,483,648 ~ 2,147,483,647                |                                                    |
|     unsigned int     |    4 byte     |                      0 ~ 4,294,967,295                      |                                                    |
| (signed) long (int)  |    4 byte     |               -2,147,483,648 ~ 2,147,483,647                |                                                    |
| unsigned long (int)  |    4 byte     |                      0 ~ 4,294,967,295                      |                                                    |
|        __int8        |    1 byte     |                         -128 ~ 127                          |                                                    |
|       __int16        |    2 byte     |                      -32,768 ~ 32,767                       |                                                    |
|       __int32        |    4 byte     |               -2,147,483,648 ~ 2,147,483,647                |                                                    |
|       __int64        |    8 byte     |   -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807    |                                                    |
|        실수형        |     float     |                           4 byte                            | 3.4E-38(-3.4*10^38) ~ 3.4E+38(3.4*10^38) (7digits) |
|    (long) double     |    8 byte     | 1.79E-308(-1.79*10^308) ~ 1.79E+308(1.79*10^308) (15digits) |                                                    |

---

#### 2.  STL 정렬된 컨테이너의 검색 알고리즘

##### 1. binary_search()

`binary_search()` 함수는 리턴값이 bool인 함수여서 원소가 컨테이너에 있는지 확인하는 용도로 사용. 확인만 하려는 경우에 반복자(iterator) 비교가 필요 없어서 간단하게 사용할 수 있음.

~~~c++
// 컨테이너 정의
static const int arr[] = { 1, 2, 2, 2, 3, 3, 4, 5, 7, 7 };
typedef std::vector<int> IntVector;
IntVector v(arr, arr + sizeof(arr) / sizeof(arr[0]));

// 원소 출력
std::cout << "elements in container" << std::endl;
std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
std::cout << std::endl;

// 검색
std::cout << "# binary_search : 3 - " <<
    (std::binary_search(v.begin(), v.end(), 3) ? "true" : "false") << std::endl;
std::cout << "# binary_search : 6 - " <<
    (std::binary_search(v.begin(), v.end(), 6) ? "true" : "false") << std::endl;
~~~

##### 2. lower_bound(), upper_bound()

`lower_bound()`와 `upper_bound()`는 컨테이너의 정렬 상태를 깨지 않고 원소를 삽입할 수 있는 위치를 찾아주는 함수임.

검색은 binary search로 이루어짐.

~~~c++
// container element : 1 2 2 2 3 3 4 5 7 7
// lower_bound : 3
IntVector::iterator upperIter = std::lower_bound(v.begin(), v.end(), 3);
std::cout << "# lower_bound : 3, value : " << *upperIter <<
     ", index : " << std::distance(v.begin(), upperIter) << std::endl;
 // => 결과 : "# lower_bound : 3, value : 3, index : 4"

// upper_bound : 3
IntVector::iterator lowerIter = std::upper_bound(v.begin(), v.end(), 3);
std::cout << "# upper_bound : 3, value : " << *lowerIter <<
     ", index : " << std::distance(v.begin(), lowerIter) << std::endl;
 // => 결과 : "# upper_bound : 3, value : 4, index : 6"

// lower_bound에 6 삽입
v.insert(std::lower_bound(v.begin(), v.end(), 6), 6);

// container element : 1 2 2 2 3 3 4 5 6 7 7
~~~

##### 3. equal_range()

`equal_range()`는 `lower_bound()`, `upper_bound()` 결과를 쌍으로 던져준다.

~~~c++
// container element : 1 2 2 2 3 3 4 5 7 7
// equal_range : 3
typedef std::pair<IntVector::iterator, IntVector::iterator> IterPair;

IterPair iterPair = std::equal_range(v.begin(), v.end(), 3);
std::cout << "@ equal_range : 3 - *first : " << *iterPair.first <<
    ", *second : " << *iterPair.second << std::endl;
// 결과 : "@ equal_range : 3 - *first : 3, *second : 4

std::cout << "@ equal_range : # of 3 : " <<
    std::distance(iterPair.first, iterPair.second) << std::endl;

// equal_range : 6
iterPair = std::equal_range(v.begin(), v.end(), 6);
std::cout << "@ equal_range : # of 6 : " <<
    std::distance(iterPair.first, iterPair.second) << std::endl;
~~~

