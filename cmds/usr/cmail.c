// cmail.c by stal@sj 2003.10.24

#include <ansi.h>
#include <login.h>

#define LOG_FILE       "/data/cmail"
#define OLD_DATA	   "/log/"

inherit ITEM;
inherit F_SAVE;

mapping *notes_csite;
mapping *notes_cmail;

int help(object);

void list_csite_simple(object me);
void list_csite_simple2(object me);
void list_cmail_simple(object me);
void list_cmail_simple2(object me);
void search_csite(object me,int i);
void search_cmail(object me,int i);
void cancel();
string str_result(mapping note);
string query_save_file();
int index_csite(string user);
int index_cmail(string user);


void create()
{
	seteuid(getuid());
	restore();
}

int main(object me, string arg)
{
	string s,user;
	int num;

	if (!arg || arg=="") 
                return help(me);

	if (arg=="-site") {
		list_csite_simple(me);
		return 1;
	}
	
	if (arg=="-site2") {
		list_csite_simple2(me);
		return 1;
	}	
	if (arg=="-mail") {
		list_cmail_simple(me);
		return 1;
	}
	
	if (arg=="-mail2") {
		list_cmail_simple2(me);
		return 1;
	}
	
	if (arg=="-a") {		
    	if ((int)me->query_temp("cmail/failed")>3) {
    		write (HIR"\n���ĳ�����ʧ�ܶ�Σ����ڰ�ȫ���ǣ�������ʱ��ֹʹ�ñ����ܡ�\n"NOR);
    		cancel();
    		return 1;
    	}
		
					
		write(HIG+"\nע�⣺��������Ҫ�����Щ��Ϊ����ԭ�����������ע����������,
�������ͼͨ�����ַ�ʽ��������ʺ�����,��ô���õĳͷ����Ƿǳ����أ�\n"
HIR"�뵣����ע�⣬һ�����������α֤���㽫�ܵ����ټ���40���ľ���ͷ���\n\n"NOR);
		
		write("��ӭʹ�ñ��򵼣��밴������Ҫ����ѡ��\n");
		write("1.���뽫��վIDת����վ\n");
		write("2.�������ע������\n");
		write("3.Ϊ������Ҹ���ע����������������������Ҫ 5M �ľ���ֵ��\n");
		write("4.��������Ҹ���ע�������������\n");
		write("0.�˳�\n");
		write("��ѡ��(0��4)��");
		
		input_to("input_start",1,me);
		
	
		return 1;
	}

	if (sscanf(arg,"-site -d %d",num)==1) {
		if ( wiz_level(me)<5 )
			return notify_fail("ֻ��assist�ſ���ɾ��תվ�����¼�� \n");
		if( !arrayp(notes_csite) || num < 1 || num > sizeof(notes_csite) )
			return notify_fail("û�������ŵ����ݡ�\n");
		num--;
		user = notes_csite[num]["id_old"] + "@" + notes_csite[num]["site_old"];		
		log_file( "static/CMAIL", sprintf("%s %s(%s)�ѹ���%s��תվ�����¼ɾ����\n", 
			ctime(time()), me->query("name"), me->query("id"), user));
		
		write("����Ҫɾ��"+ (num+1) + "�����ݣ��������£�\n");
		search_csite(me,num);
		notes_csite = notes_csite[0..num-1] + notes_csite[num+1..<1];
		write("ȷ��Ҫɾ���������롰y����");
		input_to("confirm",1);
		return 1;
		
	}

	if (sscanf(arg,"-site -r %d %s",num,s)==2) {
		if ( wiz_level(me)<4 )
			return notify_fail("ֻ��arch�ſ�����д�������� \n");
		if( !arrayp(notes_csite) || num < 1 || num > sizeof(notes_csite) )
			return notify_fail("û�������ŵ����ݡ�\n");
			
		if (strlen(s)< 4 || strlen(s)>44)
			return notify_fail("�������Ҫ��˵��������������������2-20֮�䡣 \n");
			
		num--;
		user = notes_csite[num]["id_old"] + "@" + notes_csite[num]["site_old"];		
		
		log_file( "static/CMAIL", sprintf("%s %s(%s)�Թ���%s��תվ�������˴𸴣�%s��\n", 
			ctime(time()), me->query("name"), me->query("id"), user,s));
			
		notes_csite[num]["result"]=s+"(by "+capitalize(me->query("id"))+")";
		
		write("����Ҫ��"+ (num+1) + "�����룺\n");
		search_csite(me,num);
		write("���Ĵ��ǣ�\n");
		write(HIR+s+"\n"NOR);
		write("ȷ�ϣ������롰y����");
		input_to("confirm",1);
		return 1;
		
	}
	
	if (sscanf(arg,"-mail -d %d",num)==1) {
		if ( wiz_level(me)<5 )
			return notify_fail("ֻ��assist�ſ���ɾ��������ļ�¼�� \n");
		if( !arrayp(notes_cmail) || num < 1 || num > sizeof(notes_cmail) )
			return notify_fail("û�������ŵ����ݡ�\n");
		num--;
		user = notes_cmail[num]["player"];		
		log_file( "static/CMAIL", sprintf("%s %s(%s)�ѹ���%s��������ļ�¼ɾ����\n", 
			ctime(time()), me->query("name"), me->query("id"), user));

		write("����Ҫɾ��"+ (num+1) + "�����ݣ��������£�\n");
		search_cmail(me,num);
		notes_cmail = notes_cmail[0..num-1] + notes_cmail[num+1..<1];
		write("ȷ��Ҫɾ���������롰y����");
		input_to("confirm",1);
		return 1;
		
	}
	
	if (sscanf(arg,"-mail -r %d %s",num,s)==2) {
		if ( wiz_level(me)<4 )
			return notify_fail("ֻ��arch�ſ�����д�������� \n");
		if( !arrayp(notes_cmail) || num < 1 || num > sizeof(notes_cmail) )
			return notify_fail("û�������ŵ����ݡ�\n");
			
		if (strlen(s)< 4 || strlen(s)>44)
			return notify_fail("�������Ҫ��˵��������������������2-20֮�䡣 \n");
			
		num--;
		user = notes_cmail[num]["player"];		
		
		log_file( "static/CMAIL", sprintf("%s %s(%s)�Թ���%s����������������˴𸴣�%s��\n", 
			ctime(time()), me->query("name"), me->query("id"), user,s));
			
		notes_cmail[num]["result"]= s + "(by " + me->query("id") +")" ;
		
		write("����Ҫ��"+ (num+1) + "�����룺\n");
		search_cmail(me,num);
		write("���Ĵ��ǣ�\n");
		write(HIR+s+"\n"NOR);
		write("ȷ�ϣ������롰y����");
		input_to("confirm",1);
		return 1;
		
	}
		
	if (sscanf(arg, "-site %d",num)==1) {
		search_csite(me,num-1);
		return 1;
	}
	
	if (sscanf(arg, "-site %s",user)==1) {
		search_csite(me,index_csite(user));
		return 1;
	}
	
	if (sscanf(arg, "-mail %d",num)==1) {
		search_cmail(me,num-1);
		return 1;
	}
	
	if (sscanf(arg, "-mail %s",user)==1) {
		search_cmail(me,index_cmail(user));
		return 1;
	}
	
	if (sscanf(arg,"-%s",s)>0) 
		return notify_fail("ָ���ʽ������ο�help cmail\n");
	
	
}

void input_start(string arg,object me)
{
	switch(arg) {
		case "1":
			write ("����ʼ��дתվ���뵥��\n");
			write (HIG"\n���������ڽ���վ����δתվ��IDת����վ��������׼ȷ��дID��ע��\n"NOR);
			write (HIG"���䣬��ʦ��ʵ��Ϊ��ת�����ݡ��������վID��ע�������Ѿ�����\n"NOR);
			write (HIG"ʹ��,����תվ�ɹ����ٴ�ʹ�ñ����������ע�����䡣\n"NOR);
			write ("\n��������վ����(sd��sy��cq��hb)��");
			input_to("input_site",1,me);
			return;
		case "2":
			write ("����ʼ��д�����������뵥��\n");
			write (HIG"\n���뷶Χ������������ʧ��ID ��(ע�⣺���ID����������ұ��ܲ��ƣ�\n"NOR);
			write (HIG"�����Ը���)����������������λIP��ַ������ͬ��5M�������Ϊ�� \n"NOR);
			write (HIG"����������ʦ��ʵ������Ϣ��ʵ�󣬽�Ϊ������ע�����䡣������д����\n"NOR);
			write (HIG"�䣬ֻ�����Լ�����ʦ���Կ�����\n"NOR);
			write ("\n��������Ҫ���������ID��");
			input_to("input_user",1,me);
			return;
		case "3":
			write ("����ʼ��д����֤���顣\n");
			write (HIR"\n��ȷ�����������Ķ���Ŀɿ��ԡ����������ܻ���Ϊ��α֤���ܵ����ټ���40%����ֵ�ĳͷ���\n"NOR);
			write ("\n��������Ҫ���������ID��");
			input_to("input_prove",1,me);
			return;
		case "4":
			write ("����ʼ��д����˵���顣\n");
			write (HIG"\n�������Ϊĳ�������������������⣬��ٱ���������ʦ���κ��˶�������\n"NOR);
			write (HIG"���ľٱ����ݡ�\n"NOR);
			write ("\n�����������������ʵ��������ID��");
			input_to("input_doubt_id",1,me);
			return;
		case "0":
			cancel();
			return;
		default:
			write ("û�����ѡ�������ѡ��");
			input_to("input_start",1,me);
			return;
	}
	
}

void input_doubt_id(string arg,object me)
{
	int i=0;
	string doubt,ip;
	mapping note;
	if (strlen(arg)<3) {
		cancel();
		return;
	}

	if (index_cmail(arg)<0) {
		write ("û���˶����ID���������������롣\n");
		cancel();
		return;
	}
	
	note = notes_cmail[index_cmail(arg)];
	if (note["result"]!="applying" && note["result"]!="waiting") {
		write("��ʦ�Ѿ�������������˴𸴣�����sos˵���������ɡ�\n");
		cancel();
		return;
   	}
	
	doubt = "doubt"+i;
	ip = "ip_doubt"+i;
	while (note[doubt]) {
		i++;
		doubt = "doubt"+i;
		ip = "ip_doubt"+i;
	}
	
	note[doubt]=me->query("id");
	note[ip]=query_ip_number(me);
	
	write ("����4��40���ּ�����Ҫ��˵�����Ļ��ɣ�\n");
	input_to("input_doubt",1,note,i);
	return;
}

void input_doubt(string arg,mapping note,int i)
{
	string content = "content" +i;
	
	if (strlen(arg)< 8 || strlen(arg)>44) {
		write("����������4-20֮��,���������룺 \n");
		input_to("input_doubt",1,note,i);
		return;
	}
		
	note[content] = arg;
	
	write ("���Թ���"HIR+capitalize(note["user"])+NOR"����������������������ʣ�\n");
	write (HIR+arg+"\n"NOR);
	write ("\nȷ��������Ϣ���������롰y����");
	input_to("confirm",1);
	return;
}

void input_prove(string arg,object me)
{
	mapping note;
	int i;
	string prove,ip;
	if (strlen(arg)<3) {
		cancel();
		return;
	}
	if (me->query("combat_exp") < 5000000) {
		write ("��ľ���ֵ����5000000�����ܽ��е�����\n");
		cancel();
		return;
	}
		
	
	if (index_cmail(arg)<0) {
		write ("û���˶����ID���������������롣\n");
		cancel();
		return;
	}
	
	note = notes_cmail[index_cmail(arg)];
	if (note["result"]!="applying") {
		write("���ID�ĵ��������Ѿ��㹻�ˡ�\n");
		cancel();
		return;
	}
	
	if (wiz_level(me)<6 && note["ip_proposer"]==query_ip_number(me)) {
		write("������������һ�𣬲��ܵ�����\n");
		cancel();
		return;
	}		
		
	for (i=1;i<=4;i++) {
		prove = "prove"+i;
		ip = "ip_prove"+i;
		if (!note[prove]) {
			note[prove]=me->query("id");
			note[ip]=query_ip_number(me);
			break;
		} else if (wiz_level(me)<6 && note[prove]==me->query("id")) {
			write( "���Ѿ�Ϊ���ID���������ˡ�\n");
			cancel();
			return;
		} else if (wiz_level(me)<6 && note[ip]==query_ip_number(me)) {
			write( "IP��ַ�ظ���������������\n");
			cancel();
			return;
		}
	}
	if (i==4) {
		note["result"]="waiting";
		note["time"]=time();
	}
	
	write ("������Ϊ"HIR+capitalize(arg)+NOR"����������������\n");
	write (HIR"ע�⣬һ�����������α֤������ͼʹ�õ�����ȡ�����ʺţ��㽫�ܵ����ټ���40���ľ���ͷ���\n"NOR);
	write("ȷ��������Ϣ��ȷ�������롰y�������س�������������");	
	input_to("confirm",1);
	return;
}

void confirm(string arg)
{
	if (arg!="y") {
		cancel();
		return;
	}

    save();
    write(HIW"���Ĳ����Ѿ��ɹ���\n"NOR);
    return;	
	
}

void input_user(string arg,object me)
{
	mapping note =allocate_mapping(8);

	object *online_list,ob;	
	int i;
	
	if (strlen(arg)<3) {
		cancel();
		return;
	}
	
	if (arg==note["proposer"]) {
		write("���Լ���ʧ����Ϲ���ڣ�\n");
		cancel();
		return;
	}
	if ("/cmds/usr/blacklist"->is_black(arg))
        {
                write(arg + " �Ǻ������е�������������������,��ȴ���ʦ��������\n");
                return;
        }
    if (index_cmail(arg)>=0) {
    	if (notes_cmail[index_cmail(arg)]["result"]=="waiting" || notes_cmail[index_cmail(arg)]["result"]=="applying") {
    		write("\n�Ѿ����˶����ID����˸�����������룬��ʦ��ǰ�����ظ����롣\n");
    		cancel();
    		return;
    	}
	}
	
	online_list = filter_array(children(USER_OB), (: userp($1) && environment($1) :));
	i = sizeof(online_list)-1;
	while(i>=0) {
		if (online_list[i]->query("id")==arg)
			break;
		else
			i--;
	}
	if (i>=0) {
		write("��������������أ���ûŪ��ɣ�\n");
		cancel();
		return;
	}
    ob = LOGIN_D->find_body(arg);
    if (!ob) {
		if( file_size(DATA_DIR + "login/" + arg[0..0] + "/" + arg + SAVE_EXTENSION)<0 ) {
            write("û����λʹ���ߡ�\n");
            cancel();
            return;
        }
		ob = new(LOGIN_OB);
		ob->set("id",arg);
		if( !ob->restore() ) {
			destruct(ob);
			write("û�������ҡ�\n");
			cancel();
			return;
		}
	}
	
    if (time()-ob->query("last_on")<1296000) {
    	destruct(ob);
    	write("�������ʮ����֮�ڵ�¼������������������䡣\n");
    	cancel();
    	return;
    }
    if( wiz_level(ob->query("id"))){
         destruct(ob);
         write("��������������������\n");
         cancel();
         return;                       
    }
	note["proposer"] = me->query("id");
	note["time"] = time();
	note["ip_proposer"] = query_ip_number(me);
	note["user"] = arg;
	note["result"] = "applying";
    write("�������µ�ע�����䣺");
    input_to("input_mbox_new",1,note);
    return;
}

void input_mbox_new(string arg,mapping note)
{
	string s;
    if (strlen(arg)<3) {
    	cancel();
    	return;
    }
    	
    if (sscanf(arg,"%s@%s.%s",s,s,s)<3) {
    	write("\n�����ʽ������������򰴻س���������");
    	input_to("input_mbox_new",1,note);
    	return;
    }
    
    note["mbox"] = arg;
	write ("���������뽫"HIR+capitalize(note["user"])+NOR"��ע���������Ϊ��"HIR+arg+NOR"\n");
	write("ȷ��������Ϣ��ȷ�������롰y����");	
    input_to("confirm_apply",1,note);
    return;	
}		

void confirm_apply(string arg,mapping note)
{
	if (arg!="y") {
		cancel();
		return;
	}
		
    if( !pointerp(notes_cmail) || !sizeof(notes_cmail) )
	    notes_cmail = ({ note });
    else
        notes_cmail += ({ note });
    
    save();
    write(HIW"���������Ѿ�������\n"NOR);
    return;	
}

void cancel()
{
	write(HIW"�������˱��β�����\n"NOR);
	restore();
	return;
}
void input_site(string arg,object me)
{
	mapping note =allocate_mapping(8);

	if (strlen(arg)<2) {
		cancel();
		return;
	}
	
    if ( arg!="hb" && arg!="sd" && arg!="sy" && arg!="cq") {
            write("û�����վ�㣬��������򰴻س���������");
            input_to("input_site",1,me);
            return;
    }

	note["proposer"] = me->query("id");
	note["time"] = time();
	note["ip_proposer"] = query_ip_number(me);   
    note["site_old"] = arg;
    write("�������û�ID��");
    input_to("input_oid",1,note,me);
    return;		
}

void input_oid(string arg,mapping note,object me)
{
	string file,site,str;
	if (strlen(arg)<3) {
		cancel();
		return;
	}
	
	site = note["site_old"];	
	file  = OLD_DATA + site + "/data/login/"+ arg[0..0] +"/"+ arg + SAVE_EXTENSION;	
    if (file_size(file) <= 0) {
        write("\n"+capitalize(arg) +"@"+site+"�����ڣ���������򰴻س���������");
        input_to("input_oid",1,note);
        return;
    }
    
    if (index_csite(arg)>=0)
    	if (notes_csite[index_csite(arg)]["result"]=="waiting") {
    		write("\n�Ѿ����˶����ID�����תվ���룬��ʦ��ǰ�����ظ����롣\n");
    		restore();
    		return;
    	}
    
    str = read_file(file,2);
    
        
    if (sscanf(str,"%*semail%*s:%s,%*s",str) != 4) {
    	write ("\n���ID��������û��ע��������Ϣ������"HIY"sos"NOR"����ʦ������\n");
    	cancel();
    	return;
    }   	
    str = replace_string(str,"\"","");
    note["id_old"] = arg;
    write("\n������"+capitalize(arg)+"@"+site+"��ע�����䣺");
    input_to("input_mbox",1,note,str);
    return;
}

void input_mbox(string arg,mapping note,string mbox)
{
	string s;
	object me = this_player();
    if (strlen(arg)<3) {
    	cancel();
    	return;
    }
    	
    if (sscanf(arg,"%s@%s.%s",s,s,s)<3) {
    	write("\n�����ʽ������������򰴻س���������");
    	input_to("input_mbox",1,note);
    	return;
    }

    if (arg!=mbox) {
   	
   	me->add_temp("cmail/failed",1);
    	if ((int)me->query_temp("cmail/failed")>3) {
    		write (HIR"\n���ĳ�����ʧ�ܶ�Σ����ڰ�ȫ���ǣ�������ʱ��ֹʹ�ñ����ܡ�\n"
    			"ע�⣬������Ϊ�Ѿ���ϵͳ��¼!\n"NOR);
			log_file( "static/CMAIL", sprintf("%s %s(%s)��%s��ע�������γ��Ծ���ʧ�ܡ�\n", 
				ctime(time()), me->query("name"), me->query("id"),note["id_old"]+"@"+note["site_old"]));
    		cancel();
    		return;
    	}
    	write ("\n������������䣬�������ID��ע�����䡣\n���������룺");
    	input_to("input_mbox",1,note,mbox,me);
    	return;
    }
    
    note["mbox"] = arg;
    write("\n��������ID��");
    input_to("input_nid",1,note);
    return;
}

void input_nid(string arg,mapping note)
{
	string file;
	if (strlen(arg)<3) {		
		cancel();
		return;
	}
		
	file  = "/data/login/"+ arg[0..0] +"/"+ arg + SAVE_EXTENSION;			
    if (file_size(file) > 0) {
        write("\n���ID�Ѿ����������ʹ���ˣ���������򰴻س���������");
        input_to("input_nid",1,note);
        return;
    }
    
    note["id_new"] = arg;
    note["result"] = "waiting";
    write("\n����д�����뵥�������£�\n���û�����" + note["id_old"]);
    write("\n����վ�㣺" + note["site_old"]);
    write("\nע�����䣺" + note["mbox"]);
    write("\n���û�����" + note["id_new"]);
    write("\nȷ��������Ϣ���������롰y����");
    input_to("confirm_csite",1,note);
    return;
}

void confirm_csite(string arg,mapping note)
{
	if (arg!="y") {
		cancel();
		return;
	}
		
    if( !pointerp(notes_csite) || !sizeof(notes_csite) )
	    notes_csite = ({ note });
    else
        notes_csite += ({ note });
    
    save();
    write(HIW"���������Ѿ�������\n"NOR);
    return;
}
		
void list_csite_simple(object me)
{
	int i;
	string str;

	i = sizeof(notes_csite)-1;
	if( i < 0 ) {
		write("Ŀǰû��תվ�����¼��\n");
		return;
	} 
	str="תվ�����¼��\n";
	str += HIY + "�ԡ�������������������������������������������������������������������������\n" + NOR;
	while (i>=0) {
		str += sprintf("���%3d   ʱ�� %s     ID  %-13s   ״̬  %s\n",
			i+1,
			ctime(notes_csite[i]["time"])[4..15],
			capitalize(notes_csite[i]["id_old"]) + "@" + notes_csite[i]["site_old"],			
			str_result(notes_csite[i])
			);
		
		i--;
		
	}
	str += HIY + "�ԡ�������������������������������������������������������������������������\n" + NOR;
	me->start_more( str );	
}

void list_csite_simple2(object me)
{
	int i;
	string str;

	i = sizeof(notes_csite)-1;
	if( i < 0 ) {
		write("Ŀǰû��תվ�����¼��\n");
		return;
	} 
	str="תվ���뼴��Ҫ�����¼��\n";
	str += HIY + "�ԡ�������������������������������������������������������������������������\n" + NOR;
	while (i>=0) {
		if(notes_csite[i]["result"]=="waiting")
		{
			str += sprintf("���%3d   ʱ�� %s     ID  %-13s   ״̬  %s\n",
			i+1,
			ctime(notes_csite[i]["time"])[4..15],
			capitalize(notes_csite[i]["id_old"]) + "@" + notes_csite[i]["site_old"],			
			str_result(notes_csite[i])
			);
		}
		i--;
		
	}
	str += HIY + "�ԡ�������������������������������������������������������������������������\n" + NOR;
	me->start_more( str );	
}

void list_cmail_simple(object me)
{
	int i;
	string str;

	i = sizeof(notes_cmail)-1;
	if( i < 0 ) write("Ŀǰû���κ�������������¼��\n");
	else {
		str="������������¼��\n";
		str += HIY + "�ԡ�����������������������������������������������������������������������������\n" + NOR;
		while (i>=0) {
			str += sprintf("  ���%3d   ʱ�� %s   ��������ID %-9s   ״̬  %s\n",
				i+1,
				ctime(notes_cmail[i]["time"])[4..15],
				capitalize(notes_cmail[i]["user"]),			
				str_result(notes_cmail[i])
				);			
			i--;
		}
		str += HIY + "�ԡ�����������������������������������������������������������������������������\n" + NOR;
	}
	me->start_more( str );	
}

void list_cmail_simple2(object me)
{
	int i;
	string str;
	string str2 = "";

	i = sizeof(notes_cmail)-1;
	if( i < 0 ) write("Ŀǰû��������������޸ġ�\n");
	else {
		str="  ��ǰ��������������޸����룬��������������ʦ��ϵ����ֱ����(cmail -a)\n  ָ�������򵼵�����ϵͳ(��������ֻ����ʦ���Լ�)��\n";
		str += HIY + "�ԡ�����������������������������������������������������������������������������\n" + NOR;
		while (i>=0) {
			if(notes_cmail[i]["result"]=="waiting")
			{
			str += sprintf("  ���%3d   ʱ�� %s   ��������ID %-9s   ״̬  %s\n",
				i+1,
				ctime(notes_cmail[i]["time"])[4..15],
				capitalize(notes_cmail[i]["user"]),			
				str_result(notes_cmail[i])
				);
			}
			if(notes_cmail[i]["result"]=="applying")
			{
			str2 += sprintf("  ���%3d   ʱ�� %s   ��������ID %-9s   ״̬  %s\n",
				i+1,
				ctime(notes_cmail[i]["time"])[4..15],
				capitalize(notes_cmail[i]["user"]),			
				str_result(notes_cmail[i])
				);
			}
			
			i--;
		}
		str = str + str2;
		str += HIY + "�ԡ�����������������������������������������������������������������������������\n" + NOR;
		str += HIR"  ע:�������ɹ������ڻ��������ɣ���Ϸ����Ա�ᰴ��������Ҫ����в���\n"NOR;
		
	}
	write( str );	
}

string str_doubt(object me,mapping note)
{
	string str="";
	string doubt,ip,content;
	int i=0;
	
	if (!wizardp(me)) return "";
	
	doubt = "doubt"+i;
	ip = "ip_doubt"+i;
	content = "content"+i;
	while (note[doubt]) {
		str += note[doubt];
		str += "(" + note[ip] + ")";
		str += "��" + note[content] + "\n";		
		
		i++;
		doubt = "doubt"+i;
		ip = "ip_doubt"+i;
		content = "content"+i;
	}
	
	if (strlen(str)<1) {
		str = "��Ŀǰû����Ҷ��������������ɡ�\n";
	} else {
		str = "��������Ҷ��������������ɡ�\n" + str;
	}
	return str;
}

string str_result(mapping note)
{
	if (!note["result"]) return "�����������Ϣ";
	if (note["result"]=="applying") return HBBLU+HIR"�������δ��Ҫ��"NOR;
	if (note["result"]=="waiting") return HBRED+HIY"���ڵȴ���ʦ����"NOR;
	//return note["result"];
	return HBCYN+HIG"��ʦ�Ѿ��������"NOR;
}

string str_prove(object me,mapping note)
{
	string str="";
	string prove,ip;
	int i;
	for (i=1;i<=4;i++) {
		prove = "prove"+i;
		ip = "ip_prove"+i;
		if (!note[prove]) return str;
		str += " "+note[prove];
		if (wizardp(me)) str += "("+note[ip]+")";
	}
	return str;
}
	
int index_csite(string user)
{
	int i;
	if (!pointerp(notes_csite) || !sizeof(notes_csite)) return -1;
	i = sizeof(notes_csite)-1;
	while(i>=0) {
		if (notes_csite[i]["id_old"]==user) return i;
		i--;
	}
	return i;
}	
	
int index_cmail(string user)
{
	int i;
	if (!pointerp(notes_cmail) || !sizeof(notes_cmail)) return -1;
	i = sizeof(notes_cmail)-1;
	while(i>=0) {
		if (notes_cmail[i]["user"]==user) return i;
		i--;
	}
	return i;
}	


void search_csite(object me,int i)
{
	
	string str;
	if( !arrayp(notes_csite) || i < 0 || i > (sizeof(notes_csite) - 1) )
	{
		write("û�й�������תվ�����¼��\n");
		return;
	}

	str="תվ�����¼��\n";
	str += HIY + "�ԡ�������������������������������������������������������������������������\n" + NOR;
	str += sprintf("��� %d ʱ�� %s\n����ID��%s\n����ID��%s%s \n�������ˡ�%s \n��״  ̬��%s\n",
		i+1,
		ctime(notes_csite[i]["time"])[4..15],
		capitalize(notes_csite[i]["id_old"])+"@"+notes_csite[i]["site_old"],
		notes_csite[i]["id_new"],
		(wizardp(me)||me->query("id")==notes_csite[i]["proposer"])?"\n��ע�����䡿"+notes_csite[i]["mbox"]:"",
		notes_csite[i]["proposer"]+(wizardp(me)?"("+notes_csite[i]["ip_proposer"]+")":""),
		//str_result(notes_csite[i])
		notes_csite[i]["result"]
		);
	str += HIY + "�ԡ�������������������������������������������������������������������������\n" + NOR;	
	
	me->start_more( str );	
}

void search_cmail(object me,int i)
{
	
	string str;
	if( !arrayp(notes_cmail) || i < 0 || i > (sizeof(notes_cmail)-1) )
	{
		write("û�й��������ҵ�������������¼��\n");
		return;
	}

	str="������������¼��\n";
	str += HIY + "�ԡ�������������������������������������������������������������������������\n" + NOR;
	str += sprintf("��� %d ʱ�� %s\n�����ID��%s\n%s�������ˡ�%s \n�������ˡ�%s \n��״  ̬��%s\n%s",
				i+1,
				ctime(notes_cmail[i]["time"])[4..15],
				capitalize(notes_cmail[i]["user"]),
				(wizardp(me)||me->query("id")==notes_cmail[i]["proposer"])?"�������䡿"+notes_cmail[i]["mbox"]+"\n":"",
				notes_cmail[i]["proposer"]+(wizardp(me)?"("+notes_cmail[i]["ip_proposer"]+")":""),
				str_prove(me,notes_cmail[i]),
				//str_result(notes_cmail[i]),
				notes_cmail[i]["result"],
				str_doubt(me,notes_cmail[i])
			);
	str += HIY + "�ԡ�������������������������������������������������������������������������\n" + NOR;	
	
	me->start_more( str );	
}

string query_save_file()
{
	return LOG_FILE ;
}

int help(object me)
{
	if (!wiz_level(me) )
        write(@HELP
ָ���ʽ :
cmail -a                        ����������
cmail -mail [id|����]           �鿴���תվ�������¼
cmail -site [id|����]           �鿴��Ҹ�������������¼
cmail -mail2                    �鿴�������ɹ��ȴ���ʦ��������������¼
cmail -site2                    �鿴�������ɹ��ȴ���ʦ�����תվ�����¼

HELP);
    else 
        write(@HELP
ָ���ʽ :
cmail -a                              ����������
cmail -mail [id|����]                 �鿴���תվ�������¼
cmail -mail -d <����>                 ɾ��ָ����ŵ������������ (assist����)
cmail -mail -r <����> <������>      ��дָ���������Ĵ����� (arch����)
cmail -site [id|����]                 �鿴��Ҹ�������������¼
cmail -site -d <����>                 ɾ��ָ����ŵ�תվ�������� (assist����)
cmail -site -r <����> <������>      ��дָ���������Ĵ����� (arch����)
cmail -mail2                          �鿴�������ɹ��ȴ���ʦ��������������¼
cmail -site2                          �鿴�������ɹ��ȴ���ʦ�����תվ�����¼

��ʦ��������¼��/log/csite�С�

HELP);
	return 1;
}
