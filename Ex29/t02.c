#include	<stdio.h>
/*
  コマンドラインからのパラメータを確認するプログラム
  ターミナルからコンパイルをできるようになったので、
	C++ではないけれど、確認のため作成しました。

	C/C++では、main()関数の引数として、
	コマンド入力時の情報を受け取ることができます。

	int  argc			:	パラメータの数を表します。数には、コマンド自体も入ります。
	char *argv[]	:	コマンド入力時の情報を、スペースで区切って、配列に格納しています。
									配列の最初は、プログラム起動時のコマンドです。
*/
int main(int argc,char *argv[]){
	int  i;

	printf("argc : %d\n",argc);

	for(i=0;i<argc;i++){
		printf("argv[%d] : %s\n",i,argv[i]);
	}

	return 0;
}
