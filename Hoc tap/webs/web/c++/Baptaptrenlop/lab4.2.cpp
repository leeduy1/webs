#include <iostream>
using namespace std;

struct student {
	string id;
	string name;
	string class_1;
	float mMath;
	float mPhysical;
	student* pNext;
};

struct list {
	student *pHead;
	student *pTail;
};

void KTDSLKD (list &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

student *KTStudent (string id, string name, string class_1, float mMath, float mPhysical) {
	student *std = new student;
	std->id = id;
	std->name = name;
	std->class_1 = class_1;
	std->mMath = mMath;
	std->mPhysical = mPhysical;
	std->pNext = NULL;
}

void ThemVaoCuoi (list &l, student *std) {
	if(l.pHead == NULL) {
		l.pHead = l.pTail = std;
	} else {
		l.pTail->pNext = std;
		l.pTail = std;
	}
}
