Action()
{
	char token1[36];
	int i;
	char a[2];
	int b;
	char destString[1024 * 1024 * 1024];
	web_set_sockets_option("SSL_VERSION", "TLS1.1");
	lr_start_transaction("login index");
	web_url("web_url",
		"URL=https://center.t.dacube.cn/#/login/index",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		LAST);   
	lr_end_transaction("login index", LR_AUTO);
	lr_think_time(6);		
	web_reg_save_param("Token",
		"LB=token",
		"RB=",
		"SaveOffset=3",
		"SaveLen=36",
		LAST);
		web_reg_save_param("Usercode",
		"LB=\"usercode\":\"",
		"RB=\"",
		LAST);
	
	//�����¼�ӿڵ�½
	lr_start_transaction("login");
	web_custom_request("login_2", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/login", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"phone\":\"{account}\",\"userpwd\":\"{password}\"}", 
		LAST);
	lr_end_transaction("login", LR_AUTO);

	//��ӡ�û�token
    strcpy(token1, lr_eval_string("{Token}"));
    lr_output_message("tokenΪ��%s", token1);
    lr_output_message("usercodeΪ��%s", lr_eval_string("{Usercode}"));
    lr_output_message("%s", "��½�ɹ�");
    web_add_auto_header("token",  "{Token}");
	web_custom_request(token1,
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/getCompanyByUsercode/{Usercode}", 
		"Method=GET", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);
    //ѡ����ҵ��½������û���Ϣ
    web_custom_request("updateuser",
		"URL= https://g.t.dacube.cn/MESG-ADMIN/User/updateUser ", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"compid\":\"{comid}\",\"createdata\":\"1541494436000\",\"easemobname\":\"115201811061611139ftrmgurx\",\"email\":\"{email}\",\"headimg\":\"https://oss.dacube.cn/mesg-admin/34e0a7e9-4e3a-4afc-9c93-75b24cd55660/u=3695931498,2381510501&fm=26&gp=0.jpg\",\"isuse\":\"1\",\"phone\":\"{account}\",\"token\":\"{Token}\",\"updatedata\":\"1541494436000\",\"usercode\":\"{Usercode}\"}",
		LAST);

//��½ȫý����Դ��app
    web_reg_save_param("Mrp_link",
		"LB=\"redirect:",
		"RB=\"",
		LAST);
 	web_custom_request("loginapp", 
		"URL= https://g.t.dacube.cn/MESG-ADMIN/Application/user/appLogin", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"appid\":\"1002\",\"compid\":\"{comid}\",\"loginType\":\"pc\",\"styleType\":\"\",\"usercode\":\"{Usercode}\"}",
		LAST);
	lr_output_message("mrp����Ϊ��%s", lr_eval_string("{Mrp_link}"));
	web_url("open_mrp_web",
		"URL=https://mrp.t.dacube.cn/?token={Token}#/",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Snapshot=t19.inf", 
		LAST);

	//�����ڸ��˿����������ļ���
	for(i=0;i<3;i++)
	{
	b=itoa(i+1,a,10);	
	lr_save_string(a, "a1");
	if(i==1){
	web_reg_save_param("Folderid2",
		"LB=\"id\":\"",
		"RB=\"",
		LAST);
	}
	else{
	 web_reg_save_param("Folderid",
		"LB=\"id\":\"",
		"RB=\"",
		LAST);
	}
	
    web_custom_request("createfolder", 
		"URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/folder/add_folder", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"orgId\":\"1\",\"params\":{\"folder_detail\":\"\",\"folder_name\":\"t-{a1}\",\"id_parent\": null,\"id_repo\":\"repository-personal-1-article-e729e146-f249-42e1-960d-5c1f3f60bc9a\"},\"seed\":\"seed\",\"token\":\"{Token}\",\"userId\":\"{Usercode}\"}",
		LAST);
	lr_output_message("folderidΪ��%s", lr_eval_string("{Folderid}"));
	lr_output_message("folderid2Ϊ��%s", lr_eval_string("{Folderid2}"));
	}
	
	//�����ڸ��˿�ɾ��һ���ļ���
  web_custom_request("createfolder", 
		"URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/folder/delete_folder", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"orgId\":\"1\",\"params\":{\"id\":\"{Folderid}\"},\"seed\":\"seed\",\"token\":\"{Token}\",\"userId\":\"{Usercode}\"}",
		LAST);	
//�����޸��ļ��е�����
  web_custom_request("createfolder", 
		"URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/folder/delete_folder", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"orgId\":\"1\",\"params\":{\"id\":\"{Folderid2}\",\"name\":\"t-edit\",\"detail\":\"\"},\"seed\":\"seed\",\"token\":\"{Token}\",\"userId\":\"{Usercode}\"}",
		LAST);
		
	//�ڸ��˿�Ĭ���ļ�������һƪ���
	web_custom_request("add_article", 
		"URL= https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/article/add_one", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"orgId\":\"1\",\"params\":{\"afinal\": false,\"author\":\"123\",\"content\":\"123<div>123</div>\",\"id_folder\":\"default-repository-personal-1-article-e729e146-f249-42e1-960d-5c1f3f60bc9a\",\"id_repo\":\"repository-personal-1-article-e729e146-f249-42e1-960d-5c1f3f60bc9a\",\"source\":\"11111123\",\"summary\":\"123123.\",\"time_create\":\"15026554545\",\"time_delete\":\"15026554545\",\"time_publish\":\"1555915777000\",\"time_update\":\"1502655454\",\"title\":\"456\",\"update_type\": false},\"seed\":\"seed\",\"token\":\"{Token}\",\"userId\":\"{Usercode}\"}",
		LAST);
	
	sprintf(
	destString,
        "{\"orgId\":\"1\",\"params\":{\"content\":\"�μ������ʱȴ������Щʧ�䣬�����������������ǣ��Լ�������ʮ��ԭ�ӵ����飬��������һ���ӹ������ʾ���ߣ���������Ƕ�Ц�ˣ������֣���Ҫ��ţ�ˣ���ԭ�ӵ��Ļ�ס��������ô���õĵط�������ԭ������������ܣ������Լ�����ֻ��һ����Ը����סʲô�ط����ã�ֻҪ��Ǯ��ҩ����\"},\"seed\":\"seed\",\"token\":\"%s\",\"userId\":\"%s\"}",
        lr_eval_string("{Token}"),
        lr_eval_string("{Usercode}")
       );
	
	lr_save_string(destString, "str");
    lr_output_message("destString before��%s", lr_eval_string("{str}"));
	lr_convert_string_encoding(
	   lr_eval_string("{str}"),
	   NULL,
	   "utf-8",
	   "Body"
	);
	
    
  //�������µĹؼ���
  /*	web_custom_request("Getkeywords", 
		"URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/third_party/ai_checker/get_keywords", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"orgId\":\"1\",\"params\":{\"content\":\"�μ������ʱȴ������Щʧ�䣬�����������������ǣ��Լ�������ʮ��ԭ�ӵ����飬��������һ���ӹ������ʾ���ߣ���������Ƕ�Ц�ˣ������֣���Ҫ��ţ�ˣ���ԭ�ӵ��Ļ�ס��������ô���õĵط�������ԭ������������ܣ������Լ�����ֻ��һ����Ը����סʲô�ط����ã�ֻҪ��Ǯ��ҩ����\"},\"seed\":\"seed\",\"token\":\"{Token}\",\"userId\":\"{Usercode}\"}",
		LAST);
 */

lr_output_message("destString after ��%s", lr_eval_string("{Body}"));
 //lr_save_string(destString, "Body");
 web_custom_request("Getkeywords", 
		"URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/third_party/ai_checker/get_keywords", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={Body}",
		LAST);
			
   return 0;
}




