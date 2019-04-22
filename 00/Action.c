Action()
{
	char token1[36];
	int i;
	char a[2];
	int b;
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
    //选择企业登陆后更新用户信息
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

//登陆全媒体资源库app
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
	lr_output_message("mrp链接为：%s", lr_eval_string("{Mrp_link}"));
	web_url("open_mrp_web",
		"URL=https://mrp.t.dacube.cn/?token={Token}#/",
		"TargetFrame=",
		"Resource=0",
		"Referer=",
		"Snapshot=t19.inf", 
		LAST);

	
	for(i=0;i<3;i++)
	{
	b=itoa(i,a,10);	
	lr_save_string(a, "a1");
   web_custom_request("createfolder", 
		"URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/folder/add_folder", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"orgId\":\"1\",\"params\":{\"folder_detail\":\"\",\"folder_name\":\"test-{a1}\",\"id_parent\": null,\"id_repo\":\"repository-personal-1-article-e729e146-f249-42e1-960d-5c1f3f60bc9a\"},\"seed\":\"seed\",\"token\":\"{Token}\",\"userId\":\"{Usercode}\"}",
		LAST);
	}
	
	//新增一篇稿件
	web_custom_request("add_article", 
		"URL= https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/article/add_one", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"orgId\":\"1\",\"params\":{\"afinal\": false,\"author\":\"123\",\"content\":\"123<div>123</div>\",\"id_folder\":\"default-repository-personal-1-article-e729e146-f249-42e1-960d-5c1f3f60bc9a\",\"id_repo\":\"repository-personal-1-article-e729e146-f249-42e1-960d-5c1f3f60bc9a\",\"source\":\"11111123\",\"summary\":\"123123.\",\"time_create\":\"15026554545\",\"time_delete\":\"15026554545\",\"time_publish\":\"1555915777000\",\"time_update\":\"1502655454\",\"title\":\"456\",\"update_type\": false},\"seed\":\"seed\",\"token\":\"{Token}\",\"userId\":\"{Usercode}\"}",
		LAST);
	
  
	
 


			
   return 0;
}
