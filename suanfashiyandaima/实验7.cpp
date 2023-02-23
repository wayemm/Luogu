#include<iostream>  
#include<functional>  
#include<queue>  
#include<vector>  
#include<cstring>
#include<cstdlib>
#define N 3
#define M 3
 
using namespace std;
//��۸񲻳���d����С������ÿ������ѡ��һ�� 
int d=4; 
int c[N][M]={1,2,3,3,2,1,2,2,2};//������Ʒ�ļ۸� 
int w[N][M]={1,2,3,3,2,1,2,2,2};//������Ʒ������
int min_c[N]={1,1,2},min_w[N]={1,1,2};//ÿ����Ʒ����С��������С��ֵ 
//int c[N][M]={1,4,5,6,2,1,4,5,1};//������Ʒ�ļ۸� 
//int w[N][M]={3,3,3,1,3,4,4,3,2};//������Ʒ������
//int min_c[N]={3,1,2},min_w[N]={1,1,1};//ÿ����Ʒ����С��������С��ֵ 
int index[N];//��¼���Ž����Ӧ��ѡ�� 
//������һ��ȫ�ֱ���bestw����¼��ǰ��õ�����Ҫ�����С������
//���ڵ㵱ǰ���������ޱ�bestw���ʱ������ڵ�Ͳ�����չ��
int bestw; 

struct node{
	// ����N����Ʒ��ѡȡ�����ѡ�˾���i(i=0,1,...,M-1).
	int f[N]; 
	//��ʾ��ǰѡ������һ�������ı��
	int end; 
	//���㵱ǰ���ܼ۸񣨸�����ȷ���Ĳ�����Ʒѡ�񷽰���	
	int csum; 	
	//�����ܹ��ﵽ���������ޣ�����ѡȡ���޵͵Ľ�����չ���Ը�ֵ�������ȼ���
	//�����ɵ�ǰ����������ʣ����Ʒ����С�����ͣ���ÿ��ʣ�������ѡ�۸���͵ģ�,
	//��������������ϵ���Сֵ����һ���ܴﵽ 
	double wmin;
	int wsum;//���㵱ǰ��ѡ���Ӧ�������������ܳ���d��
	bool operator < (const node &a) const {
        return wmin>a.wmin;//��Сֵ����
    }
};

void print(struct node p)
{
	int i;
	cout<<"��ǰ��ѡ���� "<<p.end+1<<" ̨���� ����Ӧ�Ļ������Ϊ ��";
	for(i=0;i<=p.end;i++)  
		cout<<p.f[i]+1<<' ';
	cout<<endl;
	cout<<"��ǰ������Ϊ : "<<p.wsum<<" , ��ǰ�ܼ۸�Ϊ ��"<<p.csum<<" , ��������Ϊ ��"<<p.wmin<<endl;
	cout<<endl;
}

int main()
{
	int i,j;
	int sumw,sumc;//��ֵ�����޺�����
	int summinw,summaxw;//�������������޺�����
	int miw,maw;//��������������ʱ����ʱ���� 
	int mct;//�����ֵ����ʱ����ʱ���� 
	node p,pp; //����ڵ㣬����һ������ʱѹ�����ȶ��� 
	priority_queue<node>que; //���ȶ��� 
	
	memset(pp.f,0,sizeof(pp.f));
	pp.end=-1; pp.csum=0;
	summinw=0;
	summaxw=0;
	//̰�ķ������������޺����� 
	for(i=0;i<N;i++)
	{
		miw=w[i][0];
		maw=w[i][0];
		for(j=1;j<M;j++)
		{
			if(w[i][j]<miw)
				miw=w[i][j];//ѡȡͬһ��Ʒ�̼��ṩ����С���� 
			if(w[i][j]>maw)
				maw=w[i][j];//ѡȡͬһ��Ʒ�̼��ṩ��������� 
		}
		summinw+=miw; //��С������� 
		summaxw+=maw; //���������� 
	}
	pp.wmin=summinw;  //����������ȥ��õ��������� 
	pp.wsum=0;  //��ǰ������ 
	bestw=summaxw;  //����ֵ����ֵ 
	que.push(pp);//����ʼ�ڵ�ppѹ�����ȶ���
	while(!que.empty())
	{ 
		//node�ĳ�Ա��f[6](��Ʒѡ�����), end(ѡ������һ����Ʒ),
		//csum(��ǰ��ֵ��),wmin(�������ޣ�������Ʒ��װ��),wsum(��ǰ������))
		pp=que.top();
		que.pop(); 
		for(i=0;i<M;i++)  //��ͬ���̾�����һ�� 
		{
			p=pp;  //ȡ����ǰҪ��չ�Ľڵ� 
			p.end+=1; //��ѡ��Ʒ��Χ��1 

			p.f[p.end]=i;//��ǰ��Ʒѡ���i������ 
			p.wsum=p.wsum+w[p.end][i];//��¼ѡ��i����Ʒ��������� 
			p.csum=p.csum+c[p.end][i];//��¼ѡ���i����Ʒ��ļ�ֵ�� 
			if(p.end==N-1) //��ǰ�ڵ��Ѿ�ѡ�������һ����Ʒ���޷���ѡ�� 
			{
				if(p.wsum<bestw&&p.csum<=d)  //�жϵ�ǰ�������Ƿ��С����ֵ�Ƿ�С�ڵ���d��������Ļ� 
				{
					bestw=p.wsum;  //��¼��ǰ����ֵ 
					for(j=0;j<N;j++)
						index[j]=p.f[j];	//��¼��Ʒѡ�����	
					print(p);			
					continue;
				}
			}			
			mct=p.csum;  //��¼��ǰѡ��󣬼�ֵ֮�͵����ޣ������Ʒÿ�ζ�ѡ������˵ģ� 
			for(j=p.end+1;j<N;j++)
				mct+=min_c[j];
			if(mct<=d)  //�۸�δ���Ļ������������δ���� 
			{
				p.wmin=p.wsum;  //��������ѡ���µ��������ޣ������Ʒÿ��ѡ������ģ� 
				for(j=p.end+1;j<N;j++)
					p.wmin+=min_w[j];
				if(p.wmin<=bestw)  //�������С��֮ǰ����ֵ�Ļ�����ӣ������Ľڵ���л�ø���ֵ�Ŀ��ܣ� 
				{
					que.push(p);
					print(p);
				}
			}
		}
	}
	cout<<bestw<<' ';
	for(i=0;i<N;i++)
		cout<<index[i]+1<<' ';
	cout<<endl;
}

