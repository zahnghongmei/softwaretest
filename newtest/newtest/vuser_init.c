long file;
char t_result[1024];
vuser_init()
{
	//��ȡϵͳʱ��
	lr_save_datetime("%Y%m%d%H%M",DATE_NOW,"now_date");
	strcpy(t_result,"E://TEST/result/mrp_test");
	strcat(t_result,lr_eval_string("_{now_date}"));
	//strcat(t_result,vusernum);
	strcat(t_result,".html");
	//���ɲ��򿪲��Խ���ļ�
	file=fopen(t_result,"at+");
	//д������ļ�ͷ��html��Ϣ
	strcpy(t_result,"<html><table width='80%' height='1200px' cellspacing='1' cellpadding='7' bgcolor='#cccccc' border='0' align='center' style='font-size:22px;font-family:serif;'> <caption>ȫý����Դ����Խ������</caption> <tr bgcolor='#e9faff'><td align='center'>����</td><td align='center'>Ԥ�ڽ��</td></td><td align='center'>ʵ�ʽ��</td></td><td align='center'>Y/N</td></tr>");
	fputs(t_result,file);
	return 0;	
}
