// ���÷���
/*
	SMTP_D->send_mail(object sender, mixed email, string subject, string content);
	sender: ������
	email: ������ ��� ID����� object����¼ object �� email ��ַ
	subject: ����
	content: ����

*/
// olives ���� 2001-04-15@Beijing
// yuj@SJ ����װ�� 2001-04-16@Toronto

#include <ansi.h>
#include <mudlib.h>
#include <net/socket.h>

#define MAIL_NAME "admin@mymud.com"
#define PUBLIC_MUD_MAIL "master@mymud.com"
#define SMTP_SERVER "202.100.222.243"
#define SMTP_PORT "25"
#define SMTP_CLIENT_VERSION "LPC SMTP Client v1.0"
#define DOMAIN_NAME "mymud.com"
#define TIME_OUT 30

class email
{
	string address;	// �ռ��ߵ�ַ
	string body;	// ����
	int status;	// ״̬��
	int time_stamp;
	object user;
}

protected void time_out(int fd, int time_stamp);
protected void success_send(int fd);
protected void mail_error(int fd, string message);

protected mapping queue = ([]);
/* smtp server domain name & ip*/
protected string smtp_server = SMTP_SERVER " " SMTP_PORT;

void create()
{
	seteuid(getuid());
}

int send_mail(object user, mixed mail, string subject, string content)
{
	string msg;
	int s,err;
	class email newmail;

	if (geteuid(previous_object()) != ROOT_UID || !objectp(user))
		return 0;

	if (!stringp(content))
	{
		tell_object(user, "�ʼ�����Ϊ�ա�\n");
		return 0;
	}

	if (stringp(mail) && strsrch(mail, "@") < 0)
	{
		string tmp = mail;

		mail = new(LOGIN_OB);
		mail->set("id", tmp);
		mail->restore();
		tmp = mail->query("email");
		destruct(mail);
		mail = tmp;
	} else if (objectp(mail))
	{
		mixed tmp;

		if (stringp(tmp = mail->query("email")))
			mail = tmp;
		else if (objectp(tmp = mail->query_temp("link_ob")))
			mail = tmp->query("email");
	}
	if (!stringp(mail) || sscanf(mail, "%*s@%*s.%*s") != 3) {
		tell_object(user, "�ʼ���ַ����\n");
		return 0;
	}

	mail = lower_case(mail);
	// ������Ч������־
	content = replace_string(content, "\n.\n", "\n\n");
	if (!stringp(subject)) subject = CHINESE_MUD_NAME+"�ʼ�";

	msg = sprintf(
		"From: \"%s\" <%s>\n"
		"To: <%s>\n"
		"Subject: %s\n"
		"Date: %s\n"
		"X-Mailer: %s\n"
		"MIME-Version: 1.0\n\n"
		"%s\n"
		"http://www.mymud.com/",
		PUBLIC_MUD_MAIL, PUBLIC_MUD_MAIL,
		mail,
		subject,
		ctime(time()),
		SMTP_CLIENT_VERSION,
		content
	);
	newmail = new(class email);
	newmail->address = mail;
	newmail->body = msg;
	newmail->user = user;
	newmail->time_stamp = time();

	s = socket_create(STREAM, "read_callback", "close_callback");
	if(s<0)
	{
		tell_object(user, "�����׽��ַ�������\n");
		return 0;
	}

	queue += ([ s : newmail ]);
	err = socket_connect(s, smtp_server, "read_callback", "write_call_back");
	if (err != EESUCCESS)
	{
		tell_object(user, "���ӷ�������������\n");
		map_delete(queue, s);
		socket_close(s);
		return 0;
	}
	tell_object(user,"�ʼ������У����Ժ�\n");
	call_out("time_out", TIME_OUT, s, newmail->time_stamp);
	return 1;
}

protected void time_out(int fd, int s)
{
	class email mailmsg;
	object usr;

	if (undefinedp(queue[fd]))
		return;

	mailmsg = queue[fd];
	if (mailmsg->time_stamp != s)
		return;

	if (objectp(usr = mailmsg->user)){
		tell_object(usr, BLINK "���͹��̳�ʱ���������ٷ���һ�Ρ�\n" NOR);
		tell_object(usr, HIW "�����������������������뵽�齣�ٷ���̳��\n" NOR);
		tell_object(usr,HIW"��ַ��"+HIY+U+"http://bbs.mymud.com/forumdisplay.php?fid=28"NOR+HIW+"���ԣ�������Ա���ֹ����͡�\n"NOR);
	}
	map_delete(queue,fd);
	socket_close(fd);
}

protected void success_send(int fd)
{
	class email mailmsg;
	object usr;

	if(undefinedp(queue[fd]))
		return;

	mailmsg = queue[fd];
	if(objectp(usr = mailmsg->user))
		tell_object(usr, sprintf(HIW "�ż��Ѿ�������%s��\n" NOR, mailmsg->address));
	map_delete(queue, fd);
	socket_close(fd);
}

protected void mail_error(int fd, string message)
{
	class email mailmsg;
	object usr;

	if(undefinedp(queue[fd]))
		return;

	mailmsg = queue[fd];

	if (objectp(usr = mailmsg->user))
	{
		tell_object(usr, sprintf(BLINK "���͹����г����쳣����%s\n" NOR,
			message)
		);
	}

	map_delete(queue, fd);
	socket_close(fd);
}

protected void hello(int fd, string msg)
{
	if (!undefinedp(queue[fd]))
		socket_write(fd, msg);
}

protected void read_callback(int fd, string message)
{
	int rcode;
	class email mailmsg;

	if(undefinedp(queue[fd]))
	{
		socket_close(fd);
		return;
	}

	mailmsg = queue[fd];

	rcode = atoi(message[0..2]);

	if (!rcode || (rcode >= 500))
	{
		mail_error(fd, message);
		return;
	}
	switch (mailmsg->status++) {
		case 0 :
			if (rcode == 220)
			{
				call_out("hello", 1, fd, sprintf("HELO %s\n", DOMAIN_NAME));
				return;
			}
			break;
		case 1 :
			if (rcode == 250)
			{
				socket_write(fd, sprintf("MAIL FROM: %s\n", MAIL_NAME));
				return;
			}
			break;
		case 2 :
			if (rcode == 250)
			{
				socket_write(fd, sprintf("RCPT TO: <%s> NOTIFY=NEVER\n", mailmsg->address));
				return;
			}
			break;
		case 3 :
			if (rcode == 250)
			{
				socket_write(fd, "DATA\n");
				return;
			}
			break;
		case 4 :
			if (rcode == 354)
			{
				socket_write(fd, sprintf("%s\n.\n", mailmsg->body));
				return;
			}
			break;
		case 5 :
			if (rcode != 451)
			{
				socket_write(fd, "QUIT\n");
				return;
			}
			break;
		case 6 :
			if(rcode == 221)
			{
				success_send(fd);
				return;
			}
	}
	mail_error(fd,message);
}
