// Created by snowman@SJ 01/05/1999.
// Modified by snowman@SJ 26/08/2000.
// Modified by Looklove@SJ 28/08/2000
// Modified by Looklove@SJ 05/07/2001 �Ż����̣�Ϊ����ȫ���������������ͬʱ֪ͨԭʼ���䡣
// �������������log�ļ�����Ϊ/log/nosave/change_mailbox
// ���ע�� ֻ�� bbb ���Ҳ����޸� 2003.4.11 River@SJ

#include <ansi.h>
#include <mudlib.h>
#include <login.h>;

inherit F_DBASE;

int help(object me);
nosave object mail_ob = 0, linkob = 0;
nosave string pass, msg, msg2;

void create()
{
	seteuid(getuid());
	set("channel_id", "���뾫��");
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

string change_passwd(object ob)
{
	if( !ob ) return 0;
	pass = make_password();
	ob->set("password",crypt(pass,"$1$ShuJian"));
	if( ob->query("newpassword") )
		ob->set("newpassword", crypt(pass,"$1$ShuJian"));
	write(HIW"���"+ ob->query("name")+ "(" + ob->query("id") + ")�������Ѿ����ġ�\n"NOR);
	return pass;
}

string *vip_email = ({
	"mymud.com",
	"shujian.com",
	"shujian.net",
	"liu.net.cn",
	"bao.net.cn",
});

int main(object me, string dest)
{
	int Dest;
	string id, wiz_status, mail, box;

	if( me != this_player(1) ) return 0;



	if( !dest )
		return help(me);

	Dest = 0;
	seteuid(ROOT_UID);

	if( sscanf(dest, "%s %s", id, mail) != 2 )
		id = dest;
	if ("/cmds/usr/blacklist"->is_black(id))
		return notify_fail(id + " �Ǻ������е�������ܸ������롣\n");
	mail_ob = LOGIN_D->find_body(id);

	if( !mail_ob || !interactive(mail_ob) ){
		linkob = new(LOGIN_OB);
		linkob->set("id",id);
		if( !linkob->restore() ) {
			destruct(linkob);
			return notify_fail("û�������ҡ�\n");
		} else {
			wiz_status = SECURITY_D->get_status(linkob);
			if (wiz_status == "(admin)" && SECURITY_D->get_status(me) != "(admin)"){
				destruct(linkob);
				return notify_fail("�㲻���Ը��� Admin �����롣\n");
			}
			if (!stringp(mail)) mail = linkob->query("email");
			if (!stringp(mail) || sscanf(mail, "%*s@%*s.%*s") != 3) {
				destruct(linkob);
				return notify_fail("�����ʼ���ַ���󣬲��ܸ������롣\n");
			}
			sscanf(mail, "%*s@%s", box);
			if (member_array(box, vip_email) != -1) {
				if ( geteuid(me) != "bbb" && geteuid(me) != "yuj") {
					destruct(linkob);
					return notify_fail("������Ϊ���ע�����䣬���������޸ġ�\n");
				}
			}
		}
	} else {
		wiz_status = SECURITY_D->get_status(mail_ob);
		if (wiz_status == "(admin)" && SECURITY_D->get_status(me) != "(admin)")
			return notify_fail("�㲻���Ը��� Admin �����롣\n");
		linkob = mail_ob->query_temp("link_ob");
		if( !linkob ) return notify_fail("���˵�Link_ob�����޷������޸ġ�\n");
		if( !stringp(mail) ){
			mail = linkob->query("email");
			if (!stringp(mail) || sscanf(mail, "%*s@%*s.%*s") != 3)
				return notify_fail("�����ʼ���ַ���󣬲��ܸ������롣\n");
			sscanf(mail, "%*s@%s", box );
			if (member_array(box, vip_email) != -1) {
				if ( geteuid(me) != "bbb" && geteuid(me) != "yuj")
					return notify_fail("������Ϊ���ע�����䣬���������޸ġ�\n");
			}
		}
		// Kick this player out afer changed his/her passwd.
		Dest = 1;
	}
	change_passwd(linkob);

	msg =   ""+linkob->query("name")+"("+linkob->query("id")+")" + "���ã�\n"+
		"��ӭ����"+CHINESE_MUD_NAME+"��\n"+
		"��ر��Զ���¼���ܣ�ʹ�������ṩ�������¼��\n"+
		"\n"+
		""+pass+ "\n"+
		"\n"+
		"�ô������¼�ɹ��󣬽������� passwd ָ������������롣\n"+
		"�������ڽ�����Ϸ���ʹ�á�help passwd��ָ��,��������Ϣ��\n"+
		ctime(time());

	msg2 =   ""+linkob->query("name")+"("+linkob->query("id")+")" + "���ã�\n"+
		"��ӭ����"+CHINESE_MUD_NAME+"��\n"+
		"Ӧ��Ҫ������ע���������� "+linkob->query("email")+" ����Ϊ "+mail+"��\n"+
		"��ر��Զ���¼���ܣ�ʹ�������ṩ�������¼��\n"+
		"\n"+
		""+pass+ "\n"+
		"\n"+
		"�ô������¼�ɹ��󣬽������� passwd ָ������������롣\n"+
		"�������ڽ�����Ϸ��ʹ�á�help passwd��ָ���������Ϣ��\n"+
		ctime(time());		

	//������ҵ�ע����Ϣ
	if ( linkob->query("email") != mail ){
		log_file("nosave/change_mailbox", sprintf("%s %s(%s)��%s(%s)��ע�������� %s ��Ϊ %s\n", ctime(time()),me->name(1),
			me->query("id"), linkob->query("name"), linkob->query("id"), linkob->query("email"), mail));
//		write("ϵͳ���ڷ���֪ͨ�ż���"+ linkob->query("name")+ "(" + linkob->query("id") + ")��ԭʼ���䡣\n");
//		SMTP_D->send_mail(me,linkob->query("email"),""+CHINESE_MUD_NAME+"�����޸�֪ͨ",msg2);
     	}
	else {
		log_file("nosave/sendpasswd", sprintf("%s %s(%s)�޸���%s(%s)������ send to %s\n", ctime(time()),me->name(1),
		 	me->query("id"), linkob->query("name"), linkob->query("id"), mail));
       	}

     	write("��ʼ����֪ͨ�ż���"+ linkob->query("name")+ "(" + linkob->query("id") + ")��ǰ���䡣\n");
     	SMTP_D->send_mail(me,mail,""+CHINESE_MUD_NAME+"ע���ż�",msg);

	linkob->set("email", mail);
	linkob->save();
	if( Dest ){
		mail_ob->save();
		tell_object(mail_ob, HIW"��ʦ�޸�������ע�����룬���˳������µ�¼��\n"NOR);
		write("���޸��˴��˵�ע�����룬����������Ϸ��\n");
		destruct(mail_ob);
	}
	destruct(linkob);
	return 1;
}

int help(object me)
{
	write(@HELP
	ָ���ʽ : sendpasswd ID [��email��ַ]  -> �������µ�ַ�����Զ��ı�ע��mail��ַ��
      	�� 	: sendpasswd ID	       -> ����ע��mail��ַ��

	���� 	sendpasswd snowman snowman@mymud.com
     		sendpasswd snowman

	���ָ������޸���ҵ����롣
	�޸�ע������Ĳ���������������棬��ȷ�����������ʹ�á�
	��ע��
	��������Ĳ�������ͬʱ��ԭʼע������͸��ĺ�����䷢���ż���

HELP
	);
	return 1;
}
                                                         
