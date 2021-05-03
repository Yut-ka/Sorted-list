#pragma once
#include <string>
#include <iostream>

const int ARRAY_SIZE = 10;

struct Stat_List_int {
public:
	int Array[ARRAY_SIZE];
	int cout;
	Stat_List_int() {
		memset(Array, -1, ARRAY_SIZE);
		cout = 0;
	}
};

struct Stat_List_string {
public:
	std::string Array[ARRAY_SIZE];
	int cout;
	Stat_List_string() {
		memset(Array, -1, ARRAY_SIZE);
		cout = 0;
	}
};

	int Push(Stat_List_int* list, int inf) {
		if (list->cout == ARRAY_SIZE) return 0;
		else if(list->cout != 0){
			int t = 0;
			for (int i = 0; i < list->cout; i++) {
				if (list->Array[i] > inf) {
					t = i; break;
				}
				t++;
			}
			for (int i = list->cout-1; i >= t; i--) {
				list->Array[i+1] = list->Array[i];
			}
			list->Array[t] = inf;
			list->cout++;
			return 1;
		}
		else { list->Array[0] = inf; list->cout++; return 1; }
	}
	int Delete(Stat_List_int* list, int t) {
		if (t < list->cout && t >= 0) {
			if (list->cout == 0) return 2;
			list->cout--;
			for (int i = t; i < list->cout; i++) {
				list->Array[i] = list->Array[i + 1];
			}
			return 1;
		}
		return 0;
	}
	int Get(Stat_List_int* list, int inf) {
		for (int i = 0; i < list->cout; i++) {
			if (list->Array[i] == inf) return i;
		}
		return -1;
	}
	std::string Show(Stat_List_int* list) {
		std::string str;
		for (int i = 0; i < list->cout; i++) {
			str += " || " + std::to_string(list->Array[i]) + " || ";
		}
		return str;
	}

	int compare(std::string s1, std::string s2) {
		int size;
		if (s1.length() < s2.length()) return 0;
		if (s1.length() > s2.length()) {size = s2.length(); return 1;}
		else { size = s1.length(); }
		for (int i = 0; i < size; i++) {
			if ((char)s1[i] < (char)s2[i]) return 0;
			else if ((char)s1[i] > (char)s2[i]) return 1;
		}
		return 0;
	}

	int Push(Stat_List_string* list, std::string inf) {
		if (list->cout == ARRAY_SIZE) return 0;
		else if (list->cout != 0) {
			int t = 0;
			for (int i = 0; i < list->cout; i++) {
				if (compare(list->Array[i],inf)) {
					t = i; break;
				}
				t++;
			}
			for (int i = list->cout - 1; i >= t; i--) {
				list->Array[i + 1] = list->Array[i];
			}
			list->Array[t] = inf;
			list->cout++;
			return 1;
		}
		else { list->Array[0] = inf; list->cout++; return 1; }
	}
	int Delete(Stat_List_string* list, int t) {
		if (t < list->cout && t >= 0) {
			if (list->cout == 0) return 2;
			list->cout--;
			for (int i = t; i < list->cout; i++) {
				list->Array[i] = list->Array[i + 1];
			}
			return 1;
		}
		return 0;
	}
	int Get(Stat_List_string* list, std::string inf) {
		for (int i = 0; i < list->cout; i++) {
			if (list->Array[i] == inf) return i;
		}
		return -1;
	}
	std::string Show(Stat_List_string* list) {
		std::string str;
		for (int i = 0; i < list->cout; i++) {
			str += " || " + list->Array[i] + " || ";
		}
		return str;
	}

/*struct Stat_List_int {
public:
	int Array[ARRAY_SIZE];
	int cout;
	Stat_List_int() {
		memset(Array, -1, ARRAY_SIZE);
		cout = 0;
	}
	int Push_after(int t, int inf) {
		if (Array[t] != -1 && t >= 0) {
			if (cout == ARRAY_SIZE) return 2;
			for (int i = cout; i > t + 1; --i) {
				Array[i] = Array[i-1];
			}
			Array[t + 1] = inf;
			cout++;
			return 1;
		}
		return 0;
	}
	int Push_before(int t, int inf) {
		if (Array[t-1] != -1 && t >= 0) {
			if (cout == ARRAY_SIZE) return 2;
			for (int i = cout; i > t; --i) {
				Array[i] = Array[i-1];
			}
			Array[t] = inf;
			cout++;
			return 1;
		}
		return 0;
	}
	int Delete(int t) {
		if (t < cout) {
			if (cout == 0) return 2;
			--cout;
			for (int i = t; i < cout; i++) {
				Array[i] = Array[i + 1];
			}
			return 1;
		}
		return 0;
	}
	int Get(int inf) {
		for (int i = 0; i < cout; i++) {
			if (Array[i] == inf) return i;
		}
		return -1;
	}
	std::string Show() {
		std::string str;
		for (int i = 0; i < cout; i++) {
			str += " || " + std::to_string(Array[i]) + " || ";
		}
		return str;
	}
};*/

