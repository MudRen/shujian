// getpasswd.c
//�������ͨ���Լ��趨��������ʾ�����Լ�ԭע�������ַ�����µ�����

inherit F_CLEAN_UP;
inherit F_DBASE;

#include <ansi.h>
#include <mudlib.h>
#include <login.h>
private int mysql = 0;
int help(object);
int check_state(object);
private void send_mail(string, object);

string seed = "1AaBb2CcDd3EeFf4GgHh5IiJj6KkLl7MmNn8OoPp9QqRr0SsTtUuVvWwXxYyZz";
string pass;

nosave object target_ob = 0;
nosave object link_ob = 0;

void create()
{
        seteuid(getuid());
}

string make_password()
{
        int i = 8, j;
        string id = "";

        while (i--) {
                j = random(62);
                id += seed[j..j];
        }
        return id;
}



int main(object me, string arg)
{
        
        if( me != this_player(1) ) return 0;

        if (!arg || arg=="") 
                return help(me);

        //if(!wizardp(me) && me->query("id")!="guest")    
                
                
        if ("/cmds/usr/blacklist"->is_black(arg))
        {
                write(arg + " �Ǻ������е�������ָܻ�����,��ȴ���ʦ��������\n");
                return 1;
        }
        if (arg == me->query("id"))
        {
                write(arg + " ���������Լ���\n");
                return 1;
        }
        if (me->query_temp("getpasswd/mail") > 3)
        {
                write("ϵͳ��⵽������������������ַ����ʱ��ֹʹ�ø����\n");
                return 1;
                
        }
        if (me->query_temp("getpasswd/answer") > 2)
        {
                write("ϵͳ��⵽�����������������𰸣���ʱ��ֹʹ�ø����\n");
                return 1;
        }
                
        write(HIG"
����Լ����������ʺŵ������ע�����䣬��ָ���һ�������Լ���ĳ���ʺ�
���齣��Ϸ�е����룬����ȷ�����ʺ��ڳ�������û�е�½�������������ȷ
�ش���ʺŵ�ע�����䣬��ôϵͳ�ᷢ�����뵽���ʺŵ�ע�����䡣

������ʺ��Ѿ��������Ᵽ������ô��������ش���ȷ����ſ��Է������롣
\n\n"NOR);

        
        target_ob = LOGIN_D->find_body(arg);
        
        if(target_ob && !interactive(target_ob))
        	return notify_fail(target_ob->query("name") +"("+target_ob->query("id")+")Ŀǰ������Ϸ�У������ʲô��\n"); 
        
        if(!target_ob || !interactive(target_ob))
        {
                link_ob = new(LOGIN_OB);
                link_ob->set("id",arg);
                if( !link_ob->restore() ) 
                {
                        destruct(link_ob);
                        return notify_fail("û�������ҡ�\n");
                }
                if( wiz_level(link_ob->query("id")))
                {
                        write("��������������������\n");
                        destruct(link_ob);
                        return 1;                       
                }
                if (!check_state(link_ob))
                {
                        write(link_ob->query("name") +"("+link_ob->query("id")+")����������ڵ�½����Ϸ����������ȡ���롣\n");
                        destruct(link_ob);
                        return 1;
                }
                else
                {
                        write(link_ob->query("name") +"("+link_ob->query("id")+")�ĵ�ǰ�����������Լ��һ�����������\n");
                        write("������"+link_ob->query("name") +"("+link_ob->query("id")+")�ĵ�ǰע�����䣺");
                        input_to("check_mail", 1, link_ob);                     
                }
                return 1;
        }
        
        if( wiz_level(target_ob->query("id")))
                return notify_fail("��������������������\n");
        else
                return notify_fail(target_ob->query("name") +"("+target_ob->query("id")+")Ŀǰ������Ϸ�У������ʲô��\n");
}

private void check_mail(string mail, object ob)
{
	object me = this_player();
	// Modified by mxzhao 2004/04/11
	mixed ret;
	//mixed rows,*res;
	// End
	
	string right_mail = ob->query("email");
	
	if (!stringp(mail) || sscanf(mail, "%*s@%*s.%*s") != 3)
	{
		write("\n�����ԣ���������ʼ���ַ��ʽ���ԣ�\n");
		destruct(ob);
		return;
	}
	
	if (right_mail != mail)
	{
		write("\n�Բ���������������ַ����"+ob->query("name")+"("+ob->query("id")+")��ע�������ַ��\n");
		write("��ע�⣬ϵͳ�Ѿ���¼���ĳ�����Ϊ��\n");
		me->add_temp("getpasswd/mail",1);
		log_file("static/GETPASSWD", sprintf("%s %s ��ͼ���� %s ��ע�����䡣 \n", ctime(time()),this_player()->query("id"),ob->query("id")));             
		destruct(ob);   
		return;
	}
	
	// Modified by mxzhao 2004/04/11
	ret = dbquery("select Question, Answer from Users "
		"where U_Username=\""+ob->query("id")+"\"");

	if (!ret)
	{
		write(HIY"���ݿ�����ʧ�ܡ�\n"NOR);
		return;
	}
	
	if (sizeof(ret) == 0 
		|| ret[0][0] == "")
	{
		write("\n���Եȣ�ϵͳ׼������������ע������"+ mail +"��\n");    
		send_mail(mail ,ob);
		return;
	}

	if (sizeof(ret) != 1)
	{
		write("���ݿ����������⣬���������Ա��ϵ��\n");
		return;
	}

	write(HIG"\n���ʺ�����������ʹ𰸱�����"
		"��ֻ�лش���ȷ��������𰸺�ſ��Է��ŵ�ע�����䡣\n");
	write(HIW"\n��ش�"YEL + ret[0][0] + NOR);
	write(HIW"\n��  ����"NOR);

	input_to("get_answer", ob, ret[0][1], mail);

	/*
	if ( !intp(mysql = db_connect("localhost","mud","root")) ) 
	{
		write("\n�������ݿ�ʧ�ܡ����Ժ����ԡ�\n");
		return;
	}
	rows = db_exec(mysql, "select Question, Answer from " + INTERMUD_MUD_NAME + "_Users where U_Username=\""+ob->query("id")+"\"");
	write ("select Question,Answer from " + INTERMUD_MUD_NAME + "Users where U_Username=\""+ob->query("id")+"\"");
	if (!rows){
		write("\n���Եȣ�ϵͳ׼������������ע������"+ mail +"��\n");
		send_mail(mail ,ob);
		return;	
	}
	if (stringp(rows)) 
	{
		write("\n��ѯ���ݿ�ʧ�ܡ�\n");
		if (wizardp(ob)) write(HIR"���ݿ�ṹ�������⡣\n"HIR);
		db_close(mysql);
		return;
	}
	res = db_fetch(mysql, 1);
	db_close(mysql);
	if( res[0] != "")
	{
		write(HIG"\n
			���ʺ�����������ʹ𰸱�������ֻ�лش���ȷ��������𰸺�ſ��Է��ŵ�ע�����䡣\n");
			write(HIW"\n��ش�"YEL+res[0]+NOR);
		write(HIW"\n��  ����"NOR);
		input_to("get_answer", ob ,res [1], mail);
	}
	else
	{
		write("\n���Եȣ�ϵͳ׼������������ע������"+ mail +"��\n");    
		send_mail(mail ,ob);
		return;
	}
	*/
	// End
}

private void get_answer(string answer, object ob,string e_answer, string mail)
{
        if (answer != e_answer ) {
                write("\n�Բ������ش�Ĵ𰸴�������ϸ���Ǻ����³��ԣ�\n");
                write("��ע�⣬ϵͳ�Ѿ���¼���ĳ�����Ϊ��\n");
                this_player()->add_temp("getpasswd/answer",1);
                log_file("static/GETPASSWD", sprintf("%s ��ͼ���� %s ������𰸡� \n", this_player()->query("id"),ob->query("id")));             
                destruct(ob);
                return;
        }
        write(HIG"\n����ȷ��\n");
        write("���Եȣ�ϵͳ׼������������ע������"+mail+"��\n");    
        send_mail(mail ,ob);
        return;
}
private string change_passwd(object ob)
{
        if( !ob ) return 0;
        pass = make_password();
        ob->set("password",crypt(pass,"$1$ShuJian"));
        if( ob->query("newpassword") ){
                ob->set("newpassword", crypt(pass,"$1$ShuJian"));
        }
        if (PASSWD_D->set_passwd(ob->query("id"), crypt(pass, "$1$ShuJian"))) 
        	write(HIW"���"+ ob->query("name")+ "(" + ob->query("id") + ")�������Ѿ����ġ�\n"NOR);
        else
        	write(HIW"ϵͳ�Զ��޸����"+ ob->query("name")+ "(" + ob->query("id") + ")���޸�ʧ�ܣ��뱨�濪����Ա��"NOR);
        return pass;
}
private void send_mail(string mail, object ob)
{
        string msg;
        change_passwd(ob);
        ob->save();
        
        msg =   ""+ob->query("name")+"("+ob->query("id")+")" + "���ã�\n"+
                "��ӭ����"+CHINESE_MUD_NAME+"��\n"+
                "Ӧ��Ҫ�����������Ѿ�����������ע�����䡣\n"+
                "��ر��Զ���¼���ܣ�ʹ�������ṩ�������¼��\n"+
                "\n"+
                ""+pass+ "\n"+
                "\n"+
                "�ô������¼�ɹ��󣬽������� passwd ָ������������롣\n"+
                "�������ڽ�����Ϸ��ʹ�á�help passwd��ָ���������Ϣ��\n"+
                ctime(time());  
        
        write("��ʼ����֪ͨ�ż���"+ ob->query("name")+ "(" + ob->query("id") + ")��ǰ���䡣\n");
        SMTP_D->send_mail(this_player(),mail,""+CHINESE_MUD_NAME+"����Զ��һ������ż�",msg);       
        
        log_file("static/GETPASSWD", sprintf("%s ���� %s ������ע�����䡣 \n", this_player()->query("id"),ob->query("id")));
        destruct(ob);          

}

private int check_state(object ob)
{
        int day = 7;
        int ttime = 86400 * day;
        
        if (ttime < time() - ob->query("last_on"))
                return 1;
        else
                return 0;
}


int help(object me)
{
        write(@HELP
ָ���ʽ : getpasswd [���ID�ʺ�]

���ָ�����ͨ��ע��������߸�������ʹ����·��͵�½���롣

����Լ����������ʺŵ������ע�����䣬��ָ���һ�������Լ���ĳ���ʺ�
���齣��Ϸ�е����룬����ȷ�����ʺ��ڳ�������û�е�½�������������ȷ
�ش���ʺŵ�ע�����䣬��ôϵͳ�ᷢ�����뵽���ʺŵ�ע�����䡣

������ʺ��Ѿ��������Ᵽ������ô��������ش���ȷ����ſ��Է������롣

HELP
);
        return 1;
}