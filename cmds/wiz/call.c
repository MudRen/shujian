// call.c
// Modified by snowman@SJ 28/11/2000
// call xxx->query ����ʽ����log

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string objname, func, param, euid, reason;
	object obj;
	mixed *args, result;
	mapping note;
	int i;

	if (arg) {
		if( sscanf(arg, "-%s %s", euid, arg)==2 ) {
			if( (string)SECURITY_D->get_status(me) != "(admin)" )
				return notify_fail("�㲻���趨�Լ��� euid��\n");
			seteuid(euid);
		}
		else
			seteuid( geteuid(this_player(1)));

		if (sscanf(arg, "%s->%s(%s) because %s", objname, func, param, reason) != 4) {
			arg += NOR;
			if (sscanf(arg, "%s->%s(%s)" NOR, objname, func, param) != 3)
				return notify_fail("ָ���ʽ��call <���>-><����>( <����>, ... )\n");
		}
	} else
		return notify_fail("ָ���ʽ��call <���>-><����>( <����>, ... )\n");

	obj = present(objname, environment(me));
	if (!obj)
		obj = present(objname, me);
	if (!obj)
		obj = LOGIN_D->find_body(objname);
	if (!obj || !me->visible(obj))
		obj = find_object(resolve_path(me->query("cwd"), objname));
	if (!obj && objname=="me")
		obj = me;
	if (!obj)
		return notify_fail("�Ҳ���ָ���������\n");

	if (SECURITY_D->get_status(me) == "(apprentice)" && obj!=me)
		return notify_fail("��û��ֱ�Ӻ����������ĺ�����Ȩ����\n");

	if (wiz_level(me) < wiz_level(obj))
		return notify_fail("��û��ֱ�Ӻ����������ĺ�����Ȩ����\n");
	if (userp(obj) && (wiz_level(me) < wiz_level("(admin)")) ){
		if (obj->query("no_call") )
			return notify_fail("����������ֹ�˱�call��Ȩ����\n");

		if (obj != me && !wizardp(obj)
		&& strsrch(func, "query") < 0
		&& strsrch(func, "temp") < 0
		&& strsrch(func, "setup") < 0) {
			if (!reason)
				return notify_fail("ָ���ʽ��call <���>-><����>( <����>, ... ) because ԭ��\n");
		
		note = (["title":"��CALL��¼��CALL���"+obj->name(1) + "("+ capitalize(obj->query("id"))+")�ļ�¼",
			"author":me->query("name") + "(" + getuid(me) + ")",
			"time":0,
			"msg":0,
			]);	
			
      "/clone/board/wizto_b"->done_post(me,note,"��CALL��¼��" + sprintf("%s(%s) call %s(%s)->%s(%s) because %s\n",
                                        me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param, reason));
		
			log_file("static/CALL_PLAYER",
				sprintf("%s(%s) call %s(%s)->%s(%s) because %s\n",
					me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param, reason
				), me, ({ obj })
			);
		}
	} else if (strsrch(func, "query") < 0 && !master()->valid_write(base_name(obj), me, "set"))
		return notify_fail("��û��ֱ�Ӻ����������ĺ�����Ȩ����\n");

	args = explode(param, ",");

	tell_object(me, sprintf("%O->%s(%s) = ", obj, func, implode(args, ",")));

	for(i=0; i<sizeof(args); i++) {
		// This removes preceeding blanks and trailing blanks.
		parse_command(args[i], environment(me), "%s", args[i]);
		if( sscanf(args[i], "%d", args[i]) ) continue;
		if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
		//args[i] = restore_variable(args[i]);
	}

	args = ({ func }) + args;

	result = call_other(obj, args);
//	for(i=1; i<sizeof(args); i++)
//		args[i] = sprintf("%O",args[i]);
	tell_object(me, sprintf("%O\n", result));
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : call <���>-><����>(<����>, ...... )

����<���>���<����>���������<����>.

��ֹ���ݲ��� balance,SJ_Credit,combat_exp
HELP
    );
    return 1;
}
