Action()
{
   

	char token1[36];	
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
    
     web_add_header("token", 
				   "{Token}");
	web_custom_request(token1,
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/getCompanyByUsercode/{Usercode}", 
		"Method=GET", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);
    
    

	return 0;
}
