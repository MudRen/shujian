// snedpasswd.c
// ��������

#include <ansi.h>
#include <net/dns.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <net/socket_errors.h>
#include <socket_err.h>
#include <mudlib.h>
#include <login.h>;

inherit F_DBASE;

nosave int my_socket,socket1,socket2;
nosave object me = 0, mail_ob = 0, linkob = 0;
nosave int status=0, connected = 0, Dest = 0;
nosave string smtp_ip="202.97.175.44 25";
nosave string smtp_domain="mymud.com";
nosave string sender="password@mymud.com";
nosave string rcpt,msg;

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "���뾫��");
}

void write_message(string);

int do_telnet(string arg)
{
        int err;

        if( connected ) socket_close(my_socket);
        my_socket = socket_create( STREAM, "in_read_callback","in_close_callback" );
        if ( my_socket < 0 ) {
//                tell_object(me, "�����׽���ʧ�ܡ�\n" );
                return 0;
        }
        err = socket_connect( my_socket, arg , "read_callback","write_callback" );
        if( err==EESUCCESS ) {
                write(HIW"\n���ڷ����ż�...\n"NOR);
                connected = 1;
                return 1;
        }
        write("�ʼ��������޷����ӡ�\n");
        return 0;
}

void close_socket()
{
        if( connected )  {
                if( socket_close(my_socket) ) connected = 0;
                my_socket = 0;
        }
}

void read_callback(int fd, mixed message)
{
        if (me && wizardp(me)) write(">> "+message);
        switch(status) {
        case 0:
                if(sscanf(message,"220%*s")) {
                        status++;
                        return;
                }
                break;
        case 1:
                if(sscanf(message,"250%*s")) {
                        status++;
                        write_message("MAIL FROM: <"+sender+">");
                        return;
                }
                break;
        case 2:
                if(rcpt&&sscanf(message,"250%*s")) {
                        status++;
                        write_message("RCPT TO: <"+rcpt+"> NOTIFY=NEVER");
                        return;
                }
                break;
        case 3:
                if(sscanf(message,"250%*s")) {
                        status++;
                        write_message("DATA");
                        return;
                }
                write("�ʼ���ַ�������飡\n");
                break;
        case 4:
                if(sscanf(message,"354%*s")) {
                        status++;
                        write_message(msg+"\n.\n");
                        return;
                }
                break;
        case 5:
                if(sscanf(message,"451%*s")) write("���ų������Ժ����ԡ�\n");
                else {
                        write("ע���ż��Ѿ���ȷ�����ˡ�\n");
                        if( linkob ) destruct(linkob);
                        mail_ob = 0;
                }
                
                break;                          
        }
        if(status!=5 || !sscanf(message,"250%*s")) write("���ų���\n");
        status=0;
        write_message("QUIT");
        close_socket();
	if (linkob) destruct(linkob);
}

void write_callback(int fd)
{
        write_message("HELO " +smtp_domain );
}

void write_message(string arg)
{
        if( !arg ) arg="";
        if (me && wizardp(me)) write("<< "+arg+"\n");
        socket_write(my_socket, arg+"\n");
}

string seed = "1AaBb2CcDd3EeFf4GgHh5IiJj6KkLl7MmNn8OoPp9QqRr0SsTtUuVvWwXxYyZz";

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

private string change_passwd(object ob)
{
        string pass;
        
        if( !ob ) return 0;
        pass = make_password();        
        ob->set("password",crypt(pass,"$1$ShuJian"));
        if( ob->query("newpassword") )
                ob->set("newpassword", crypt(pass,"$1$ShuJian"));
        write("���"+ ob->query("name")+ "(" + ob->query("id") + ")�������Ѿ����ģ������ż��ɹ���\n");
        return pass;
}

private string do_auto(object me, string dest)
{
        string id, mail, wiz_status;
        
        if( mail_ob ) return "���ڰ������˵��������������Ժ�\n";
        
        if( me != this_player(1) ) return "�����֤ʧ�ܣ�\n";
        
        if (!do_telnet(smtp_ip)) {
                mail_ob = 0;
                return "do_telnet -> Error.\n";
        }
        Dest = 0;
        seteuid(ROOT_UID);
        
        id = dest;
        mail_ob = LOGIN_D->find_body(id);
        
        if( !mail_ob || !interactive(mail_ob) ){
                linkob = new(LOGIN_OB);
                linkob->set("id",id);
                if( !linkob->restore() ) {
                        mail_ob = 0;
                        destruct(linkob);
                        return "û�������ҡ�\n";
                } 
                else {         
                        wiz_status = SECURITY_D->get_status(linkob);
                        if( wiz_status == "(admin)" && SECURITY_D->get_status(me) != "(admin)" ){
                                mail_ob = 0;
                                destruct(linkob);
                                return "�㲻���Ը��� Admin �����롣\n";
                        }
                }
        }
        
        else{
                wiz_status = SECURITY_D->get_status(mail_ob);
                if( wiz_status == "(admin)" && SECURITY_D->get_status(me) != "(admin)" ){
                        mail_ob = 0;
                        return "�㲻���Ը��� Admin �����롣\n";
                }
                  
                linkob = mail_ob->query_temp("link_ob");
                if( !linkob ) {
                        mail_ob = 0;
                        return "���˵�Link_ob�����޷������޸ġ�\n";
                }
                
                if( !stringp(mail) ){
                        mail = linkob->query("email");
                        if( !stringp(mail) || sscanf(mail, "%*s@%*s.%*s") != 3 )
                                return "���˵ĵ����ʼ���ַ���󣬲��ܸ������롣\n";
                }
                // Kick this player out afer changed his/her passwd.
                Dest = 1;
        }

        if( !stringp(mail) ){
                mail = linkob->query("email");
                if( !stringp(mail) || sscanf(mail, "%*s@%*s.%*s") != 3 ){
                        mail_ob = 0;
			destruct(linkob);
                        return "���˵ĵ����ʼ���ַ���󣬲��ܸ������롣\n";
                }
        }
        rcpt = mail;
        status = 0;
        write("��ʼ��������ע�������������� "+ mail +" ...\n");
        //������ҵ�ע����Ϣ
        if ( linkob->query("email") != mail )
        	log_file("static/sendpasswd", sprintf("%s %s(%s)�޸���%s(%s)������ send to %s\n", ctime(time()),me->name(1),
                 me->query("id"), linkob->query("name"), linkob->query("id"), mail));

        msg=
                "SUBJECT: "+CHINESE_MUD_NAME+"ע���ż���\n"+
                "FROM: \""+"�������Ա@"+CHINESE_MUD_NAME+"\" <password@mymud.com>\n"+
                "TO: \""+linkob->query("name")+"("+linkob->query("id")+")"+"\" <"+dest+">\n"+
                "MIME-Version: 1.0\n"+
                "DATE: "+ctime(time())+"\n"+
                "X-MAILER: LPC SMTP Client v0.4\n\n\n"+
                linkob->query("name")+"("+linkob->query("id")+")" + " ���ã���ӭ����"+CHINESE_MUD_NAME+"��\n"+
                "��ر��Զ���¼���ܣ�ʹ�������ṩ�������¼��\n\n"+
                "���ע�������ǣ�"+ change_passwd(linkob) +"\n\n"+
                "�ô������¼�ɹ������� passwd ָ������������롣\n"+
                  "������ο� help passwd ��\n"+
                "��վ��ҳ��http://www.mymud.com\n"+
                ctime(time());

        linkob->set("email", mail);
        linkob->save();
        remove_call_out("fail");
        call_out("fail", 90, mail_ob);
        if( Dest ){
                mail_ob->save();
                tell_object(mail_ob, HIW"�����޸�������ע�����룬���˳������µ�¼��\n"NOR);
                tell_object(me, "���޸��˴��˵�ע�����룬����������Ϸ��\n");
                destruct(linkob);
                catch(destruct(mail_ob));
                if( mail_ob ) 
                	return "���޷������������ߡ�\n";
                CHANNEL_D->do_channel(this_object(), "sys", "������� -> "NOR + id + HIR" �˳���ϵͳ�����뷢���� "+mail+" ��");
        }
        else {
        	CHANNEL_D->do_channel(this_object(), "sys", "������� -> "NOR + id + HIR" ��������£������� "+mail+" ��");
	}
        return "������� "+ dest +" ����ɹ��������ż��Ѿ����� "+ mail +"��\n";
}

void fail(object ob)
{
        if (!ob || ob != mail_ob) return;
        close_socket();
        message_vision("����ע��ʧ�ܣ�\n", me);
        write("������ע�ᡣ\n");
        mail_ob = 0;
}


string *help()
{
	return ({"passwd [id]","���������뵽���ע��mail��ַ��"});
}
