// say.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string tmp;

    if( userp(me) || wiz_level(me) || wizardp(me))
		if(getuid(me)!="ciwei") message("wizard", CYN +"("+capitalize(me->query("id"))+")"NOR, environment(me), me);
	if (!arg) {
		write("����������ز�֪����˵Щʲô��\n");
		message("sound", me->name() + "��������ز�֪����˵Щʲô��\n", environment(me), me);
		return 1;
	}
	while (sscanf(arg, "%s"+NOR+"%s", arg, tmp)) arg += CSI+"0m"+ CYN + tmp;
	while (arg != "" && arg[<1]=='\n') arg = arg[0..<2];
	if( (int)me->query("qi") < (int)me->query("max_qi") / 4 ) {
		arg = replace_string(arg, " ", " ... ") + " ...";
		write( CYN "������������˵������" + arg + "��\n" NOR);
		if(getuid(me)!="ciwei") message("sound", CYN + me->name() + "����������˵������" +  arg + "��\n" NOR, environment(me), me);
		else message("sound", CYN"��" +  arg + "��\n" NOR, environment(me), me);
	} 
	else {
		write( CYN "��˵������" + arg + "��\n" NOR);
		if(getuid(me)!="ciwei") message("sound", CYN + me->name() + "˵������" +  arg + "��\n" NOR, environment(me), me);
		else message("sound", CYN"��" +  arg + "��\n" NOR, environment(me), me);
	}

	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ: say <ѶϢ>
 
˵�������и�����ͬһ��������˶���������˵�Ļ���
 
ע: ��ָ����� ' ȡ��.
 
HELP
	);
	return 1;
}
