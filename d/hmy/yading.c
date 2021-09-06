// /d/hmy/shiwu.c
#include <ansi.h>

#define	SHIP_TO	__DIR__"ryping"

inherit ROOM;

void create()
{
	set("short", HIW"�¶�"NOR);
	set("long", @LONG
�¶����а�����һ�޴�Ľ������̣����̵���һֻ����¨��lou)��������
���º�ľ�µ���Ҫ���ߡ��չ�Ӷ�������������ǰһ��������ľ޴���¥����
�ڻԻͣ�ɲ��׳�ۡ�
LONG
	);
	set("exits", ([ 
	  	"east" : __DIR__"pailou",
	]));
	set("item_desc",([
	  "lou" : "һ���޴����¨�����(yell)һ�������Թ�������(xiaya)��\n",
	]));
	set("outdoors", "��ľ��");
	setup();
}

void init()
{
	add_action("do_yell", "yell");
	add_action("do_zong", "zong");
}

int do_yell(string arg)
{
	object me = this_player();
	object room;
	
	if (!arg) return 0;

	if (arg == "xiaya") arg = "����";
	if (arg != "����") arg = "��";
	if (me->query("age") < 16  )
		message_vision("$Nʹ�����̵���������һ������" + arg + "��\n", me);
	else if (me->query("neili") > 500)
		message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ���˳�ȥ��\n", me);
	else
		message_vision("$N������������Хһ������" + arg + "����\n", me);
	if (arg == "����") {
		if( !(room = find_object(__DIR__"zhulou")))
			room = load_object(__DIR__"zhulou");
		if( room = find_object(__DIR__"zhulou")) 
			if(!room->query("start")) 
				room->arrive("yading");
			else
				message_vision("����ԶԶ����һ����������ȵȰ���������ˡ�������\n", me);
			return 1;
	}
	else
		message_vision("����ԶԶ����һ���������" + arg + "��������\n", me);
	return 1;
}

int valid_leave(object me, string dir)
{
	if(query("exits/enter") && dir == "enter")
		me->set_temp("side", "yading");
	return ::valid_leave(me, dir);
}

int do_zong()
{
        object me = this_player();
        object room;
        int cost = 1200;
        
        if( !(room = find_object(__DIR__"zhulou")) )
		room = load_object(__DIR__"zhulou");
        if (!living(me)) return 0;
        
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���أ�\n");
        if (me->query_skill("dodge") < 300)
                return notify_fail("�����Ϊ������\n");
        if (me->query("max_neili") < 4000)
                return notify_fail("���������Ϊ����������֧�֣���\n");
        if (me->query("neili") < 1500)
                return notify_fail("������������ˣ�\n");
        if (me->query("jingli") < 1000)
                return notify_fail("��ľ��������ˣ�\n");

        if (me->query_encumbrance()/100 > me->query("neili") + cost)
                return notify_fail("�����ô�صİ�������·�������⣬��˵���ˣ�\n");

        if (query("exits/enter"))
        	return notify_fail("����¨������ȥ�ɡ�\n");    
        
	if (!objectp(room = find_object(__DIR__"zhulou") ))
		return notify_fail("��⣬��¨�����ˣ���֪ͨ��ʦ��\n");
            
	if((int)room->query("exits/out"))
		return notify_fail("�ͱ�ʵ��̫���ˣ����û����;�����ĵط�����û��������ȥ��\n"); 

	me->receive_damage("neili", 600);
	me->receive_damage("jingli", 200);
	tell_room(environment(me), HIC+me->name()+"���˽�������Ʒ������һ�Σ��������´�ȥ��\n" NOR, ({me}));
	write("��һ����Ϣ����׼���¼���¨λ�ã�ʹ�������־�������Ҫ�������¡�\n");
	me->move(__DIR__"zhulou");
	me->start_busy(3);
	if(me->query_encumbrance()/100 > me->query("neili") + cost
	 || me->query("neili") < 800 || me->query("jingli") < 500) {
		write("�㻹��������ȴ�������������ˡ�\n");
		tell_room(environment(me), HIC+me->name()+"����ƮƮ�������Ϸ�Ծ������վ����¨�У���ڴ�ڴ�������\n" NOR, ({me}));
		return 1;
	}
	tell_room(environment(me), HIC+me->name()+"����ƮƮ�������Ϸ�Ծ����������¨��һ�㣬�������ݳ���\n" NOR, ({me}));
	write("�����¼���¨������һ�㣬�������������¡�\n");
	me->move(SHIP_TO);
	tell_room(environment(me), HIC"ֻ��"+me->name()+"����ƮƮ������Ծ������̬���������ڵ��ϡ�\n"NOR, ({me}));
	me->receive_damage("neili", 600);
	me->receive_damage("jingli", 200);
	return 1;
}
