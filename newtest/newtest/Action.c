//info��ʾ������Ϣ,content��ʾԤ�ڽ��,real ��ʾ���������ص���ʵ��� 
int result;
char *code;
int write(int result,char V_testres[1024],char *info,char content[200],char real[200])
{

 if ( result==0 ) {
           strcpy(V_testres,"ͨ��");
         }
       else {
       strcpy(V_testres,"ʧ��");
         }
		 
	strcpy(t_result,"<tr><td>");
    //д����Բ���
    strcat(t_result,info);

    strcat(t_result,"</td>");

    strcat(t_result,"<td id='yq'>");
	//д��Ԥ�ڽ��

    strcat(t_result,content);

    strcat(t_result,"</td>");

    strcat(t_result,"<td id='sj'>");
	//д��ʵ�ʽ��
    strcat(t_result,real);
    strcat(t_result,"</td>");
    strcat(t_result,"<td>");

    //д������Ƿ�ͨ��

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
//���Խ���ı�
       char V_testres[1024];
//���巵�ؽ���Ƿ���ȷ����
       int result;
//ȡ��������Ϣ
       char *info=lr_eval_string ("{username}");
       char content[200];
       char real[200];
       char *temp;
//����ҳ����������ֽ�����������Ӧ���ڷ������������ݵĴ�С
       web_set_max_html_param_len("20000");
//ȡ�÷�������������
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
	 
	
       //�����¼�ӿڵ�½ ������ȷ���û�����ȷ
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
    write(result,V_testres,"�û����������ȷ�ӿ���֤",content,real);
    temp=lr_eval_string("{code}");
    lr_output_message("codeΪ��%s", temp);
    lr_output_message("phoneΪ��%s",lr_eval_string("{phone}"));
       //��ӡ�û�token
    strcpy(token1, lr_eval_string("{Token}"));
    lr_output_message("tokenΪ��%s", token1);
    lr_output_message("usercodeΪ��%s", lr_eval_string("{Usercode}"));
    lr_output_message("%s", "��½�ɹ�");
    
	  web_reg_save_param("code1",
        "LB=\"code\":",
		"RB=\,\"result\"",
		LAST);
     web_reg_save_param("msg",
        "LB=\"msg\":\"",
		"RB=\"",
		LAST);
    //��½��֤���û���������
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
       strcpy(content,"code:��Ϊ200 msg:��¼��������");
       //���code������200���ʹ�ӡmsg��
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
       write(result,V_testres,"��½�û�������ӿ���֤",content,real);
        
	  web_reg_save_param("code2",
        "LB=\"code\":",
		"RB=\,\"result\"",
		LAST);
     web_reg_save_param("msg2",
        "LB=\"msg\":\"",
		"RB=\"",
		LAST);
    
        //��½��֤���������
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
       strcpy(content,"code:��Ϊ200 msg:��¼�������벻ƥ��   ");
       //���code������200���ʹ�ӡmsg��
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
       write(result,V_testres,"��½�û�������ӿ���֤",content,real);
       
       	       
	  web_reg_save_param("compname",
        "LB=\"compname\":\"",
		"RB=\"",
		"Ord=1",
		LAST);
        web_reg_save_param("companycode",
        "LB=\"code\":",
		"RB=\,\"result\"",
		LAST);
    //��ȡ��ҵ��Ϣ�ӿ�
       web_add_auto_header("token","{Token}");
       web_custom_request(token1,
              "URL=https://g.t.dacube.cn/MESG-ADMIN/User/getCompanyByUsercode/{Usercode}", 
              "Method=GET", 
              "Resource=0", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t16.inf", 
              "Mode=HTML", 
              LAST);
       lr_output_message("compname��%s", lr_eval_string("{compname}"));
       strcpy(real,"code:");
       code=lr_eval_string("{companycode}");
       strcat(real,lr_eval_string("{companycode}"));
       strcpy(content,"code:200 compname:���ƿƼ�");
       //���code������200���ʹ�ӡmsg��
       if(atoi(code)==200)
       {
       	if(strcmp(lr_eval_string("{compname}"),"���ƿƼ�")){
       		result=0;
       	}
       	else{
       	result=1;
       	}
        strcat(real," compname:");
        lr_convert_string_encoding(
              lr_eval_string("{compname}"),
              "utf-8",
              "GBK",     
              "encompname"
              );
       strcat(real,lr_eval_string("{encompname}"));
       }
       write(result,V_testres,"��ȡ��ҵ��Ϣ�ӿ���֤",content,real);
       
       
       
      web_reg_save_param("compid",
        "LB=\"compid\":\"",
		"RB=\"",
		"Ord=1",
		LAST);
        web_reg_save_param("updatecode",
        "LB=\"code\":",
		"RB=\,\"result\"",
		LAST);  
    lr_start_transaction("updateuserinfo");
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
  lr_end_transaction("updateuserinfo", LR_AUTO);
       strcpy(real,"code:");
       code=lr_eval_string("{updatecode}");
       strcat(real,code);
       strcpy(content,"code:200 comid:1");
       //���code������200���ʹ�ӡmsg��
       if(atoi(code)==200)
       {
       		result=0;
       }
       	else{
       	result=1;
       	}
        strcat(real," comid:");
        lr_convert_string_encoding(
              lr_eval_string("{comid}"),
              "utf-8",
              "GBK",     
              "encomid"
              );
       strcat(real,lr_eval_string("{encomid}"));
       
       write(result,V_testres,"��ȡ��ҵ��Ϣ�ӿ���֤",content,real);
       

//��½ȫý����Դ��app
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
//articlecontent��ʾ���������       
       sprintf(
       destString,
        "{\"orgId\":\"1\",\"params\":{\"content\":\"%s\"},\"seed\":\"seed\",\"token\":\"%s\",\"userId\":\"%s\"}",
        lr_eval_string("{articlecontent}"),
        lr_eval_string("{Token}"),
        lr_eval_string("{Usercode}")
       );       
       lr_save_string(destString, "str_article_content");
       lr_output_message("destString before��%s", lr_eval_string("{str_article_content}"));
       lr_convert_string_encoding(
       lr_eval_string("{str_article_content}"),
          NULL,
          "utf-8",
          "Body"
       );
          
  //�������µĹؼ���
  /*       web_custom_request("Getkeywords", 
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
              "Snapshot=t23.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
              "Body={Body}",
              LAST);
 //articlecontent��ʾ���������       
 web_set_max_html_param_len("20");
       sprintf(
       dest1String,
              "{\"orgId\":\"1\",\"params\":{\"afinal\": false,\"author\":\"С��\",\"content\":\"�μ������ʱȴ������Щʧ�䣬�����������������ǣ��Լ�������ʮ��ԭ�ӵ����飬��������һ���ӹ������ʾ���ߣ���������Ƕ�Ц�ˣ������֣���Ҫ��ţ�ˣ���ԭ�ӵ��Ļ�ס��������ô���õĵط���\",\"id_folder\":\"default-repository-personal-1-article-e729e146-f249-42e1-960d-5c1f3f60bc9a\",\"id_repo\":\"repository-personal-1-article-e729e146-f249-42e1-960d-5c1f3f60bc9a\",\"source\":\"11111123\",\"summary\":\"�μ������ʱȴ������Щʧ�䣬�����������������ǣ��Լ�������ʮ��ԭ�ӵ����飬��������һ���ӹ������ʾ���ߣ���������Ƕ�Ц�ˣ������֣���Ҫ��ţ�ˣ���ԭ�ӵ��Ļ�ס��������ô���õĵط���\",\"title\":\"ԭ���ֵ���״\",\"update_type\": false},\"seed\":\"seed\",\"token\":\"%s\",\"userId\":\"%s\"}",
        lr_eval_string("{Token}"),
        lr_eval_string("{Usercode}")
       );       
       lr_save_string(dest1String, "str_article_content1");
    lr_output_message("destString before��%s", lr_eval_string("{str_article_content1}"));
       lr_convert_string_encoding(
          lr_eval_string("{str_article_content1}"),
          NULL,
          "utf-8",     
          "Body1"
       );
 //�ڸ��˿�Ĭ���ļ�������һƪ���
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




