//cpasswd.c by XiaoYao
// Modify by snowman@SJ 01/05/1999.

#include <login.h>;

int main(object me, string arg)
{
object ob,link_ob;
string id,password;

seteuid(ROOT_UID); // add by Yuj@SJ 1999-6-2
if( me != this_player(1) ) return 0;

if( wiz_level(me) < 5 )
return notify_fail("ֻ�� admin �� assist ������������\n");

if(!arg||sscanf(arg,"%s %s",id,password)!=2)
return notify_fail("�÷��� cpasswd <ID> <������> \n�˲���������������棬������ȵ��������\n");

ob = LOGIN_D->find_body(id);
if(!ob){
ob = new(LOGIN_OB);
ob->set("id",id);
if( !ob->restore() ) {
destruct(ob);
return notify_fail("û�������ҡ�\n");
} else {    
ob->set("password",crypt(password, "$1$ShuJian"));
write("���" + ob->query("id") + "("+ob->query("name")+ ")�������Ѿ�����Ϊ��"+password+"��\n");
log_file( "changepw.log", sprintf("%s %s(%s)�޸���%s(%s)������\n", ctime(time()), me->query("name"), me->query("id"),
 ob->query("name"), ob->query("id")));
ob->save();
destruct(ob);
return 1;
}
}

link_ob=ob->query_temp("link_ob");
if(link_ob) {
link_ob->set("password",crypt(password,"$1$ShuJian"));
link_ob->save();
write("���" + ob->query("id") + "("+ob->query("name") + ")�������Ѿ�����Ϊ��"+password+"��\n");
log_file( "changepw.log", sprintf("%s %s(%s)�޸���%s(%s)�����롣\n", ctime(time()), me->query("name"), me->query("id"),
 ob->query("name"), ob->query("id")));
return 1;
}
else
return notify_fail("�����޷������޸ġ�\n");
return 1;
}


int help(object me)
{
write(@HELP
ָ���ʽ : cpasswd ID ������

���ָ������޸���ҵ����룬�����ʹ�á�

HELP
    );
    return 1;
}

