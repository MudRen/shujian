// Room: /d/tianshan/bzhanjian.c
// By Linux

inherit ROOM;
int do_drop(object me, object obj);
void create()
{
	set("short", "���ɽ�");
	set("long", @LONG
��ǰ��һ��ɽ������ɲ⡣���������ͱڵľ��Ǽ��������������ϵ�ľ
�����Ѳ�������������϶��⼸ö���������ܻ�ѩ�в��������ϵ��Ͻ�������
����Щ���ű������м���ɫ������������Ϳ�о綾, ɽ��������������������
�����£���������ȥ������·��
LONG);
	set("exits", ([
                "south" :__DIR__"shizhuyan",
        ]));       
	set("outdoors", "��ɽ");
	setup();	
}

void init()
{
	add_action("do_zhan", ({"zhan", "ge", "qie"}));
	add_action("do_jump", ({"jump", "tiao", "yue"}));
	add_action("do_ren", ({"ren", "diu", "diuqi","drop"}));
}

int do_zhan(string arg)
{
	object me,weapon;
	me=this_player();
	if (me->is_busy() || me->is_fighting())	return notify_fail("����æ���أ�\n");
	if( (!arg) || !((arg == "tielian") || (arg == "����") || (arg == "tieliang")))
		return notify_fail("��Ҫ��ʲô��\n"); 
	if( !objectp(weapon = me->query_temp("weapon")) )
		return notify_fail("����ü����������߲��ܿ���������\n");
	if (me->query_temp("��ɽ������"))
		return notify_fail("���������Ѿ�ն������\n");
	if( weapon->query("flag") != 4 )
		return notify_fail("��������������޷����У�����ܿ������������\n");
	message_vision("$N�ս�����"+weapon->name()+"�������������ѽ������ͱ�ʯ���еİ������ն����������������!\n", me);
	me->set_temp("��ɽ������",1);
	me->add_busy(2);
	return 1;
}

int do_jump(string arg)
{
	object me=this_player();
	object *inv;
	int i;

	if (me->is_busy() || me->is_fighting())	return notify_fail("����æ���أ�\n");
	if (!me->query_temp("��ɽ������"))
		return notify_fail("ʲô��\n");
	if (arg == "down") { 
        	message_vision( "$Nһ���������������¡�\n",me);
		me->move(__DIR__"yadi");
		me->set_temp("last_damage_from", "��������ˤ");
		me->unconcious();
		me->die();
		return 1;
	}
	if( (!arg) || !((arg == "duimian") || (arg == "����")))
		return notify_fail("��Ҫ��������ȥ��ɽ����\n");

	inv = filter_array(deep_inventory(me), (: userp :));
	if (sizeof(inv)) {
		message_vision("$Nһ��������������ɽ���ϣ�����һ��ʧ��......\n", me);
		me->unconcious();
		return 1;
	}

        if( (int)me->query_skill("dodge", 1) < 30 )
		return notify_fail("������Լ����Ṧ̫�����ȥ����������\n");
	
	message_vision("\n$N��������������һ����Ŷ����������˹�ȥ�����ڰ�գ�����һ�ǣ����μ�����׹,\n"+
			"ͻȻ$N�ֻ����������İ�����µ�������ȥ��ֻ��������š���������������$N\n"+
			"�ڿ������ɵ�һ���������Ѿ����ڶ������ϡ�\n\n",me);

	inv = deep_inventory(me);
	i= random(sizeof(inv));
	if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 80) {
		do_drop(me, inv[i]);
	}
	me->delete_temp("��ɽ������");
	me->add_busy(2);
	me->move(__DIR__"xcmen");
	tell_room(environment(me), me->name() + "�Ӷ���İ��ɽ����˹�����\n",me);
	return 1;
}

int do_drop(object me, object obj)
{
	mixed no_drop;
	if( no_drop = obj->query("no_drop")) return 1;
	if( obj->is_character())
		return 1;
	else {
		message_vision( sprintf("����$N�����������ȣ����ϵ�һ%s$n������ɽ������Ҳ�Ҳ������ˡ�\n", obj->query("unit")),me, obj );
		destruct(obj);
	}
	return 1;
}

int do_ren(string arg)
{
	object me=this_player();

	if (!me->query_temp("��ɽ������"))
		return notify_fail("ʲô��\n");

	if( (!arg) || !((arg == "tielian") || (arg == "����")))
		return notify_fail("��Ҫ��ʲô�������Լ�����ȥ��\n");

	message_vision("$N���������ڵ��ϡ�\n",me);
	me->delete_temp("��ɽ������");	
	return 1;
}

int valid_leave(object me,string dir)
{
	if ( me->query_temp("��ɽ������") && dir == "south" )
	return notify_fail("������������������ô�뿪��\n");
	return ::valid_leave(me, dir);
}
