/*
standard template library 8
algorithm

알고리즘 라이브러리를 통해 복잡한 작업들을 수행할 수 있다.
알고리즘에 정의되어 있는 여러가지 함수들로 작업을 수행하게 되는데, 이 때
함수들은 크게 두 개 형태를 가지고 있다.

1.
template <typename Iter>
void do_something(Iter begin, Iter end);

 반복자의 시작점과 끝점 바로 뒤를 받음

2.
template <typename Iter, typename Pred>
void do_something(Iter begin, Iter end, Pred pred)

반복자는 동일하게 받고, '특정 조건'을 추가인자로 받음
이 때 '특정 조건'을 Predicate(서술자) 라고 부르며, Pred 에는 보통 bool을 리턴하는
Functor(함수 객체)를 전달하게 된다.

보통은 서술자가 있는 형태인 듯 하다.

std::algorithm 에 정의된 편리한 알고리즘

- 정렬: sort, stable_sort, partial_sort
- 제거: remove, remove_if
- 람다 함수
- 원소 수정: transform
- 원소 탐색: find, find_if, any_of, all_of
*/