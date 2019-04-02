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
		lr_output_message("学号为：%d",i+1);
		lr_output_message("姓名为：%s",stu[i].name);
		lr_output_message("分数为：%f",stu[i].score);

	};
	


	web_url("login.jsp",
		"URL=http://4a.dacube.com.cn/samlidp/login.jsp",
		"TargetFrame=http://4a.dacube.com.cn/samlidp/login.jsphttp://4a.dacube.com.cn/samlidp/login.jsp",
		"Resource=0",
		"Referer=",
		LAST);	
return 0;

}
