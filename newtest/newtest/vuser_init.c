long file;
char t_result[1024];
vuser_init()
{
	//获取系统时间
	lr_save_datetime("%Y%m%d%H%M",DATE_NOW,"now_date");
	strcpy(t_result,"E://TEST/result/mrp_test");
	strcat(t_result,lr_eval_string("_{now_date}"));
	//strcat(t_result,vusernum);
	strcat(t_result,".html");
	//生成并打开测试结果文件
	file=fopen(t_result,"at+");
	//写入测试文件头部html信息
	strcpy(t_result,"<html><table width='80%' height='1200px' cellspacing='1' cellpadding='7' bgcolor='#cccccc' border='0' align='center' style='font-size:22px;font-family:serif;'> <caption>全媒体资源库测试结果报告</caption> <tr bgcolor='#e9faff'><td align='center'>描述</td><td align='center'>预期结果</td></td><td align='center'>实际结果</td></td><td align='center'>Y/N</td></tr>");
	fputs(t_result,file);
	return 0;	
}
