// ��������

inherit ROOM;
string look_sign();

void create()
{
	set("short", "������");
	set("long", @LONG
���ǻ������棬�ռ���С��ֻ��һ����λ�����ߵĴ���(window)���ú첼
���ţ��㲻�ƿ��Ļ������ѿ�������ľ��ֻ�ܸо����������ڱ�̧�ţ�ҡ
ҡ�λε����ţ��е����ˣ���Ҳ�����뿪(leave)��
LONG
	);

	set("item_desc",([
		"window" : (: look_sign :),
        ]));
	
	setup();
}

void init()
{
	add_action("do_leave", "leave");
}

string look_sign()
{
        object env, me = this_player();
        object who;
	string arg;

	if ( !arg = me->query("marry/id"))
		return "����ô������İ���\n";

	if ( ! who = find_player(arg))
		return "�ţ������ɷ����أ�\n";

	if ( me->is_busy())
		return "����æ���أ�\n";

        if(!( env = find_object(base_name(environment(who)))) )
        env = load_object(base_name(environment(who)));

        if(!random(5))
        	tell_room(env, "�㷢����һ˫�۾��ڽ�������͵͵������\n");
        return "/cmds/std/look"->look_room(me, env);
}

int do_leave()
{
	string arg;
	object who, me = this_player();
	
	if ( arg = me->query("marry/id")){ 
		if (! who = find_player(arg)) {
			tell_object(me,"��������ˣ�����վ���������뿪�˻��Ρ�\n");
			me->move("/d/city/yuelaoting");
			return 1;
		}
		return notify_fail("���ɷ��������أ������������ɡ�\n");
	}
	tell_object(me,"��������ˣ�����վ��������������������˳�ȥ��\n");
	me->move("/d/city/yuelaoting");
	return 1;
}
