// Write By Yanyang@SJ 2001.10.3
// Room: /d/changan/wenquan.c

inherit ROOM;

void create()
{
	set("short", "��Ȫ");
	set("long", @LONG
�ߵ����һ���������ڵİ���������Χס�����Ѿ���������Ȫ�ߡ�Ȫ
����ˮ�̲��������쳣�峺��ˮ���������ơ��ഫ�ڴ���Ȫԡ�󣬰׷���ڣ�
���ϻ�ͯ������������������Ŀ��ԡ��
LONG
        );
	set("outdoors", "����");
	set("exits", ([
		"west" : __DIR__"baishulin2",
	]));

	set("incity",1);
	setup();
}

void init()
{
	add_action("do_wash","wash");
}

int do_wash()
{
	object me=this_player();
	object weapon = me->query_temp("weapon");
	object *inv;
	int i;
        
	if(!living(me) ) return 0;
	if(me->query_temp("do_wash") > 0) return notify_fail("���Ѿ�����Ȫ���ˣ�\n");
	if ( me->query("gender") == "����" ) {
		tell_object(me, "��һ������ү������Щ�����ʲô��\n");
		return 1;
	}
	if (me->is_busy() || me->is_fighting()) 
		return notify_fail("����æ���ģ�\n");

	if((me->query_encumbrance()*20) > me->query_max_encumbrance()) 
		return notify_fail("�����ϵĶ���̫���ˣ�\n");

	if (weapon) 
		return notify_fail("��Ҫ��ô���Ű���ϴ�軹����������\n");

	inv= all_inventory(me);
	i = sizeof(inv);
	while (i--)
	if( inv[i]->query("equipped") && (! inv[i]->query_autoload() && inv[i]->query("id") != "lingpai"))
		return notify_fail("���ϴ����·���ôϴ�裿\n"); 

	message_vision("ֻ������ͨ��һ����$N�Ѿ���������Ȫ�\n",me);
	if(me->query("jingli") < 50) {
		write("������о�Ȫˮ��ù��̣���æ�������˳�����\n",me);
		me->unconcious();
		return 1;
	}
	me->add("jingli", -100);
	me->set_temp("do_wash",1);
	call_out("over_wash", 10, me);     
	return 1;
}

void over_wash(object me)
{
	if(!me) return;
	if( me && environment(me) == this_object()) {
		message_vision("$N�ݹ�����Ĵ���Ȫ�����˳�����\n", me);
		if (me->query_skill("beauty", 1) > 120)
			me->improve_skill("beauty", random(me->query("con"))*2);
		me->delete_temp("do_wash",1);
	}
	return;
}
