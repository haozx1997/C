#include<bits/stdc++.h>

using namespace std;
char s[1001000];
int letssee[1001000];
int bbeg[30];
int bend[30];
int main() {
	int n,k;

	while(~scanf("%d%d",&n,&k)) {
		memset(bbeg,0,sizeof(bbeg));
		memset(bend,0,sizeof(bend));
		memset(letssee,0,sizeof(letssee));

		scanf("%s",s+1);
		for(int i = 1; i <= n; i++) {
			if(bbeg[s[i] - 'A'] == 0) {
				bbeg[s[i] - 'A'] = i;
				letssee[i] = 1;
				bend[s[i] - 'A'] = i;
			} else {
				bend[s[i] - 'A'] = max(bend[s[i] - 'A'],i);
			}

		}
		for(int i = 0; i < 26; i++ ) {
			letssee[bend[i]] += 2;
		}
		int need = 0;
		for(int i = 1; i <= n; i++) {
			if(letssee[i] == 1) {
				need += letssee[i];
				if(need>k) {
					break;
				}
			} else if(letssee[i] == 2) {
				need--;
			} else if(letssee[i] == 3) {
				need++;
				if(need>k) {
					break;
				}
				need--;
			}


		}

		if(need>k) 
		{
			printf("Yes\n");
		} else 
		{
			printf("No\n");
		}

	}

	/*

	5 1
	AABBB

	5 1
	ABABB

	26 1
	ABCDEFGHIJKLMNOPQRSTUVWXYZ
	27 1
	ABCDEFGHIJKLMNOPQRSTUVWXYZA
	


	*/


	return 0;
}


