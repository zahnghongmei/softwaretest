struct student
{
int num;
char name[10];
float score;
};

Action()
{   int i;
	struct student stu[2]={{1,"jack",100},{2,"tom",20}};
	for(i=0;i<2;i++)
	{
		lr_output_message("ѧ��Ϊ��%d",i+1);
		lr_output_message("����Ϊ��%s",stu[i].name);
		lr_output_message("����Ϊ��%f",stu[i].score);

	};
	


	web_url("login.jsp",
		"URL=http://4a.dacube.com.cn/samlidp/login.jsp",
		"Resource=0",
		"Referer=",
		LAST);	
return 0;

}
