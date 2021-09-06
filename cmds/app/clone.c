// clone.c

#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string file)
{
	object obj;
	string err, msg;

	seteuid(geteuid(me));

	if (!file)
		file = me->query("cwf");
	if (!file)
		return notify_fail("��Ҫ����ʲô�����\n");

	file = resolve_path(me->query("cwd"), file);
	if (file[<2..<1] != ".c")
		file += ".c";
	me->set("cwf", file);

	if (file_size(file) < 0)
		return notify_fail("û���������(" + file + ")��\n");

	if (!load_object(file)) {
		err = catch(call_other(file, "???"));
		if (err) {
			write("����ʧ�ܣ�" + err + "\n");
			return 1;
		}
	}

	err = catch(obj = new(file));
	if (err) {
		write("����ʧ�ܣ�" + err + "\n");
		return 1;
	}

	obj->set("clone_by_wizard", 1);
	obj->set("clone_by_which_wizard", geteuid(me));
	obj->delete("treasure");
	if( !stringp(msg = me->query("env/msg_clone")) )
		msg = "ֻ��$N�������һָ�������$n��";

	if( !obj->is_character() && obj->move(me,1) && !obj->query("no_carry")) {
		write(obj->query("name") + "���Ƴɹ������������Ʒ����\n");
		message_vision(msg + "\n", me, obj);
		// log it
		if (geteuid(me) != "yuj")
		log_file("static/CLONE_OBJ",
			sprintf("%s(%s) clone %s(%s)\n",
				me->name(1), geteuid(me),
				obj->name(1), obj->query("id")
			), me
		);
/*
		shout( HIG "��ϵͳ�����棺" + me->query( "name" ) + "���һָ���������Ʒ��" + obj->query("name") + "��\n" NOR );
    		write( HIG "��ϵͳ�����棺" + me->query( "name" ) + "���һָ���������Ʒ��" + obj->query("name") + "��\n" NOR );
*/
		return 1;
	}
	if( obj->move(environment(me)) ) {
		write(obj->query("name") + "���Ƴɹ�������������䡣\n");
		message_vision(msg + "\n", me, obj);
		// log for clones
		if (geteuid(me) != "yuj")
		log_file("static/CLONE_OBJ",
			sprintf("%s(%s) clone %s(%s)(%s)\n",
				me->name(1), geteuid(me),
				obj->name(1), obj->query("id"), geteuid(obj)
			), me
		);
/*
		shout( HIG "��ϵͳ�����棺" + me->query( "name" ) + "���һָ���������Ʒ��" + obj->query("name") + "��\n" NOR );
    		write( HIG "��ϵͳ�����棺" + me->query( "name" ) + "���һָ���������Ʒ��" + obj->query("name") + "��\n" NOR );
*/

		return 1;
	}    
	destruct(obj);
	return notify_fail("�޷����Ʋ����ƶ������(" + file + ")��\n");
}

int help(object me)
{
	write(@HELP
ָ���ʽ : clone <����>

���ô�ָ��ɸ����κ����ƶ�֮�����
HELP
	);
	return 1;
}
