#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 100
#define MAXL 25
 
typedef struct {
    char book_title[MAXL], author[MAXL];
}BookAuthor;
 
typedef struct {
    char book_title[MAXL];
    int selling, date;
}BookSelling;
 
typedef struct {
    char book_title[MAXL], author[MAXL];
    int selling, date;
}BookInfo;
 
typedef struct {
    int num; // the number of BookInfo
    BookInfo books[MAXN];
}BookInfoList;

int CMP(const void *a, const void *b){
	BookInfo *c = (BookInfo *)a;
	BookInfo *d = (BookInfo *)b;

	int ret = strcmp(c->book_title, d->book_title);
	if( ret )
		return ret;
	else
		return c->date - d->date;
}
 
BookInfoList merge(int N, int M, BookAuthor authorArr[], BookSelling sellingArr[]){
	BookInfoList list;
	list.num = 0;

	for(int i = 0;i < M;i++){
		BookSelling tmp = sellingArr[i];

		int correspond;
		for(correspond = 0; strcmp(tmp.book_title, authorArr[correspond].book_title) && correspond < N; correspond++ );

		if(correspond < N){
			BookInfo append;
			strcpy(append.book_title, tmp.book_title);
			strcpy(append.author, authorArr[correspond].author);
			append.selling = tmp.selling;
			append.date = tmp.date;

			list.books[ list.num++ ] = append;
		}
	}

	qsort(list.books, list.num, sizeof(BookInfo), CMP);

	return list;
}

int main(){
    int N, M;
    BookAuthor authorArr[MAXN];
    BookSelling sellingArr[MAXN];
 
    assert(scanf("%d %d", &N, &M) == 2);
    for(int i = 0; i < N; i++)
        assert(scanf("%s %s", authorArr[i].book_title,
                              authorArr[i].author) == 2);
 
    for(int i = 0; i < M; i++)
        assert(scanf("%s %d %d", sellingArr[i].book_title,
                                 &sellingArr[i].selling,
                                 &sellingArr[i].date) == 3);
 
    BookInfoList result = merge(N, M, authorArr, sellingArr);
 
    for(int i = 0; i < result.num; i++)
        printf("%s %s %d %d\n", result.books[i].book_title,
                                result.books[i].author,
                                result.books[i].date, result.books[i].selling);
 
    return 0;
}