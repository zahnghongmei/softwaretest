Action()
{
	char token1[36];	
	web_set_sockets_option("SSL_VERSION", "TLS1.1");
	lr_think_time(6);		
	web_reg_save_param("Token",
		"LB=token",
		"RB=",
		"SaveOffset=3",
		"SaveLen=36",
		LAST);
	web_custom_request("login_2", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/login", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"phone\":\"18200000000\",\"userpwd\":\"1234567\"}", 
		LAST);
	//将字符串赋值给变量
     strcpy(token1, lr_eval_string("{Token}"));
     lr_output_message("token为：%s", token1);
   web_set_user("18200000000",
		lr_decrypt("{Token}"),
		"https://g.t.dacube.cn/MESG-ADMIN:443");
	
	web_custom_request(token1, 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/getCompanyByUsercode/{Token}", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);
    

	return 0;
}
