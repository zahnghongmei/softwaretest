//info表示描述信息,content表示预期结果,real 表示服务器返回的真实结果 
int result;
char *code;
int write(int result,char V_testres[1024],char *info,char content[200],char real[200])
{

 if ( result==0 ) {
           strcpy(V_testres,"通过");
         }
       else {
       strcpy(V_testres,"失败");
         }
		 
	strcpy(t_result,"<tr><td>");
    //写入测试参数
    strcat(t_result,info);

    strcat(t_result,"</td>");

    strcat(t_result,"<td id='yq'>");
	//写入预期结果

    strcat(t_result,content);

    strcat(t_result,"</td>");

    strcat(t_result,"<td id='sj'>");
	//写入实际结果
    strcat(t_result,real);
    strcat(t_result,"</td>");
    strcat(t_result,"<td>");

    //写入测试是否通过

    strcat(t_result, V_testres);

    strcat(t_result,"</td></tr>"); 

    fputs(t_result,file);
    return 0;
}
   
Action()
{
       char token1[36];
       int i;
       char a[2];
       int b;
       char destString[1024];
       char dest1String[1024];
       char keywods[100];
//测试结果文本
       char V_testres[1024];
//定义返回结果是否正确变量
       int result;
//取得描述信息
       char *info=lr_eval_string ("{username}");
       char content[200];
       char real[200];
       char *temp;
//设置页面接收最大的字节数，该设置应大于服务器返回内容的大小
       web_set_max_html_param_len("20000");
//取得服务器返回内容
       web_reg_save_param("filecontent",
              "LB=",
              "RB=",
              "Search=Body",
                  LAST);
       web_set_sockets_option("SSL_VERSION", "TLS1.1");
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
       web_reg_find("Text/DIG/ALNUMIC=usercode",
       LAST); 
      

	  web_reg_save_param("code",
        "LB=\"code\":",
		"RB=\,\"result\"",
		LAST);

	  web_reg_save_param("phone",
		"LB=\"phone\":\"",
		"RB=\"",
		LAST);
	 
	
       //请求登录接口登陆 密码正确，用户名正确
       lr_start_transaction("login");
       web_custom_request("login_1", 
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
       strcpy(real,"code:");
       strcat(real,lr_eval_string("{code}"));
       strcat(real," phone:");
       strcat(real,lr_eval_string("{phone}"));
       strcpy(content,"code:200 phone:18200000000");
       code=lr_eval_string("{code}");
       if(atoi(code)!=200)
       {
       result=1;
       }
       else{
       result=strcmp(real,content);
       }
    write(result,V_testres,"用户名密码均正确接口验证",content,real);
    temp=lr_eval_string("{code}");
    lr_output_message("code为：%s", temp);
    lr_output_message("phone为：%s",lr_eval_string("{phone}"));
       //打印用户token
    strcpy(token1, lr_eval_string("{Token}"));
    lr_output_message("token为：%s", token1);
    lr_output_message("usercode为：%s", lr_eval_string("{Usercode}"));
    lr_output_message("%s", "登陆成功");
    
	  web_reg_save_param("code1",
        "LB=\"code\":",
		"RB=\,\"result\"",
		LAST);
     web_reg_save_param("msg",
        "LB=\"msg\":\"",
		"RB=\"",
		LAST);
    //登陆验证：用户名不存在
    web_custom_request("login_2", 
              "URL=https://g.t.dacube.cn/MESG-ADMIN/User/login", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t152.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
              "Body={\"phone\":\"18200000001\",\"userpwd\":\"{password}\"}", 
              LAST);
       
       strcpy(real,"code:");
       code=lr_eval_string("{code1}");
       strcat(real,lr_eval_string("{code1}"));
       strcpy(content,"code:不为200 msg:登录名不存在");
       //如果code不等于200，就打印msg。
       if(atoi(code)!=200)
       {
       	result=0;
        strcat(real," msg:");
        lr_convert_string_encoding(
              lr_eval_string("{msg}"),
              "utf-8",
              "GBK",     
              "enmsg"
              );
       strcat(real,lr_eval_string("{enmsg}"));
       }
       write(result,V_testres,"登陆用户名错误接口验证",content,real);
        
	  web_reg_save_param("code2",
        "LB=\"code\":",
		"RB=\,\"result\"",
		LAST);
     web_reg_save_param("msg2",
        "LB=\"msg\":\"",
		"RB=\"",
		LAST);
    
        //登陆验证：密码错误
    web_custom_request("login_3", 
              "URL=https://g.t.dacube.cn/MESG-ADMIN/User/login", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t152.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
              "Body={\"phone\":\"18200000000\",\"userpwd\":\"12345\"}", 
              LAST);
       
       strcpy(real,"code:");
       code=lr_eval_string("{code2}");
       strcat(real,lr_eval_string("{code2}"));
       strcpy(content,"code:不为200 msg:登录名与密码不匹配   ");
       //如果code不等于200，就打印msg。
       if(atoi(code)!=200)
       {
       	result=0;
        strcat(real," msg:");
        lr_convert_string_encoding(
              lr_eval_string("{msg2}"),
              "utf-8",
              "GBK",     
              "enmsg2"
              );
       strcat(real,lr_eval_string("{enmsg2}"));
       }
       write(result,V_testres,"登陆用户名错误接口验证",content,real);
       
       	       
	  web_reg_save_param("compname",
        "LB=\"compname\":\"",
		"RB=\"",
		"Ord=1",
		LAST);
        web_reg_save_param("companycode",
        "LB=\"code\":",
		"RB=\,\"result\"",
		LAST);
    //获取企业信息接口
       web_add_auto_header("token","{Token}");
       web_custom_request(token1,
              "URL=https://g.t.dacube.cn/MESG-ADMIN/User/getCompanyByUsercode/{Usercode}", 
              "Method=GET", 
              "Resource=0", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t16.inf", 
              "Mode=HTML", 
              LAST);
       lr_output_message("compname：%s", lr_eval_string("{compname}"));
       strcpy(real,"code:");
       code=lr_eval_string("{companycode}");
       strcat(real,lr_eval_string("{companycode}"));
       strcpy(content,"code:200 compname:耕云科技、一级子公司");
       //如果code不等于200，就打印msg。
       if(atoi(code)==200)
       {
       	result=0;
        strcat(real," compname:");
        lr_convert_string_encoding(
              lr_eval_string("{compname}"),
              "utf-8",
              "GBK",     
              "encompname"
              );
       strcat(real,lr_eval_string("{encompname}"));
       }
       write(result,V_testres,"获取企业信息接口验证",content,real);
       
       
       
       
       
       
       
       
       
    lr_start_transaction("updateuserinfo");
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
  lr_end_transaction("updateuserinfo", LR_AUTO);

//登陆全媒体资源库app
   lr_start_transaction("loginapp");
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
    lr_end_transaction("loginapp", LR_AUTO);

       lr_output_message("mrp链接为：%s", lr_eval_string("{Mrp_link}"));
       web_url("open_mrp_web",
              "URL=https://mrp.t.dacube.cn/?token={Token}#/",
              "TargetFrame=",
              "Resource=0",
              "Referer=",
              "Snapshot=t19.inf", 
              LAST);

       //测试在个人库新增三个文件夹
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
       lr_output_message("folderid为：%s", lr_eval_string("{Folderid}"));
       lr_output_message("folderid2为：%s", lr_eval_string("{Folderid2}"));
       }
       
       //测试在个人库删除一个文件夹
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
//测试修改文件夹的名字
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
//articlecontent表示稿件的内容       
       sprintf(
       destString,
        "{\"orgId\":\"1\",\"params\":{\"content\":\"%s\"},\"seed\":\"seed\",\"token\":\"%s\",\"userId\":\"%s\"}",
        lr_eval_string("{articlecontent}"),
        lr_eval_string("{Token}"),
        lr_eval_string("{Usercode}")
       );       
       lr_save_string(destString, "str_article_content");
       lr_output_message("destString before：%s", lr_eval_string("{str_article_content}"));
       lr_convert_string_encoding(
       lr_eval_string("{str_article_content}"),
          NULL,
          "utf-8",
          "Body"
       );
          
  //生成文章的关键词
  /*       web_custom_request("Getkeywords", 
              "URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/third_party/ai_checker/get_keywords", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t24.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
              "Body={\"orgId\":\"1\",\"params\":{\"content\":\"参加社区活动时却让他有些失落，他告诉社区的老人们，自己参与了十次原子弹试验，总是做第一个加工铀球的示范者，结果老人们都笑了：“老兄，不要吹牛了，搞原子弹的还住在我们这么破烂的地方？’”原公浦心里很难受，他想自己现在只有一个心愿，“住什么地方都好，只要有钱吃药”。\"},\"seed\":\"seed\",\"token\":\"{Token}\",\"userId\":\"{Usercode}\"}",
              LAST);
 */

lr_output_message("destString after ：%s", lr_eval_string("{Body}"));
 //lr_save_string(destString, "Body");
 web_custom_request("Getkeywords", 
              "URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/third_party/ai_checker/get_keywords", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t23.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
              "Body={Body}",
              LAST);
 //articlecontent表示稿件的内容       
 web_set_max_html_param_len("20");
       sprintf(
       dest1String,
              "{\"orgId\":\"1\",\"params\":{\"afinal\": false,\"author\":\"小张\",\"content\":\"参加社区活动时却让他有些失落，他告诉社区的老人们，自己参与了十次原子弹试验，总是做第一个加工铀球的示范者，结果老人们都笑了：“老兄，不要吹牛了，搞原子弹的还住在我们这么破烂的地方。\",\"id_folder\":\"default-repository-personal-1-article-e729e146-f249-42e1-960d-5c1f3f60bc9a\",\"id_repo\":\"repository-personal-1-article-e729e146-f249-42e1-960d-5c1f3f60bc9a\",\"source\":\"11111123\",\"summary\":\"参加社区活动时却让他有些失落，他告诉社区的老人们，自己参与了十次原子弹试验，总是做第一个加工铀球的示范者，结果老人们都笑了：“老兄，不要吹牛了，搞原子弹的还住在我们这么破烂的地方。\",\"title\":\"原公浦的现状\",\"update_type\": false},\"seed\":\"seed\",\"token\":\"%s\",\"userId\":\"%s\"}",
        lr_eval_string("{Token}"),
        lr_eval_string("{Usercode}")
       );       
       lr_save_string(dest1String, "str_article_content1");
    lr_output_message("destString before：%s", lr_eval_string("{str_article_content1}"));
       lr_convert_string_encoding(
          lr_eval_string("{str_article_content1}"),
          NULL,
          "utf-8",     
          "Body1"
       );
 //在个人库默认文件夹新增一篇稿件
       web_custom_request("add_article", 
              "URL= https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/article/add_one", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t24.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
        "Body={Body1}",
              LAST);                     
   return 0;
}




