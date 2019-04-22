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
	
	//请求登录接口登陆
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

	//打印用户token
    strcpy(token1, lr_eval_string("{Token}"));
    lr_output_message("token为：%s", token1);
    lr_output_message("usercode为：%s", lr_eval_string("{Usercode}"));
    lr_output_message("%s", "登陆成功");
    web_add_auto_header("token",  "{Token}");
	web_custom_request(token1,
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/getCompanyByUsercode/{Usercode}", 
		"Method=GET", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);
    web_custom_request("updateuser",
		"URL= https://g.t.dacube.cn/MESG-ADMIN/User/updateUser ", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"compid\":\"1\",\"createdata\":\"1541494436000\",\"easemobname\":\"115201811061611139ftrmgurx\",\"email\":\"{email}\",\"headimg\":\"https://oss.dacube.cn/mesg-admin/34e0a7e9-4e3a-4afc-9c93-75b24cd55660/u=3695931498,2381510501&fm=26&gp=0.jpg\",\"isuse\":\"1\",\"phone\":\"{account}\",\"token\":\"{Token}\",\"updatedata\":\"1541494436000\",\"usercode\":\"{Usercode}\",\"username\":\"{username}\"}",LAST);

//登陆全媒体资源库app
 	web_custom_request("loginapp", 
		"URL= https://g.t.dacube.cn/MESG-ADMIN/Application/user/appLogin", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"appid\":\"1002\",\"compid\":\"1\",\"loginType\":\"pc\",\"styleType\":\"\",\"usercode\":\"{Usercode}\"}",
		LAST);    
	return 0;
}
