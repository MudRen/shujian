#include <ansi.h>

inherit ROOM;
#define SHIP_TO __DIR__"dukou2"

void create()
{
        set("short", "���Ķɿ�");
        set("long", @LONG
�����ǻƺӴ�ɿڣ���ͨ����ԭ�ıؾ�֮·�������Ļƺӽ�����Ʈ���ż�
ֻ�ᷫ���ɿڴ���ͣ��һ�Ҷɴ��������˿����ںʹ������ۼ�Ǯ��������ɴ�
��(yell)���ɹ��ƺӡ�
LONG);
	set("exits", ([
		"northwest" : __DIR__"huanghe_3",
        ]));
        set("outdoors", "����");
	setup();
}

void init()
{    
	add_action("do_yell", "yell"); 
	add_action("du_jiang", "duhe");                            
}

int do_yell(string arg)
{
	object room, me;
	me = this_player();

	if (arg == "boat") arg = "����";
	if (arg != "����") arg = "��";
	if (me->query("age") < 16  )
		message_vision("$Nʹ�����̵���������һ������" + arg + "��\n", me);
	else if (me->query("neili") > 500)
		message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ���˳�ȥ��\n", me);
	else
		message_vision("$N������������Хһ������" + arg + "����\n", me);
	if (arg == "����") {
		if( !(room = find_object(__DIR__"duchuan")) )
			room = load_object(__DIR__"duchuan");
		if( room = find_object(__DIR__"duchuan")) 
		if(!room->query("start")) 
			room->arrive();
		else message_vision("������ԶԶ����һ�������ȵȰ���������ˡ�������\n", me);
		return 1;
	}
	else
		message_vision("������ԶԶ����һ���������" + arg + "��������\n", me);
	return 1;
}

int valid_leave(object me, string dir)
{
	object ob, obj;
	obj = this_object();

	if(userp(me) && dir == "enter") {
		if(ob = present("silver_money", me)){                  
			message_vision("$N�ͳ�һ�������ݸ����ң�����Ծ���˶ɴ���\n\n", me); 
			me->set_temp("side", "dukou3");
			ob->add_amount(-1);
		}
		else if(ob = present("gold_money", me)){                  
			message_vision("$N���˰��죬�������ϰ�����ʣ�޼��ˣ�ֻ���ó�һ���ƽ�ݸ����ң�����Ծ���˶ɴ���\n\n", me); 
			me->set_temp("side", "dukou3");
			ob->add_amount(-1);
		}
		else return notify_fail("��������������ȴ�������ϴ���Ǯ�����ˡ�\n");   
	}
	return ::valid_leave(me, dir);
}

int du_jiang()
{
	object me = this_player();
	object room;
	int cost = 600;
        
	if( !(room = find_object(__DIR__"duchuan")) )
		room = load_object(__DIR__"duchuan");

	if (!living(me)) return 0;
        
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");
	if (me->query_skill("dodge") < 250)
		return notify_fail("�����Ϊ������\n");
	if (me->query("max_neili") < 3000)
		return notify_fail("���������Ϊ����������֧�֣���\n");
	if (me->query("neili") < 800)
		return notify_fail("������������ˣ�\n");
	if (me->query("jingli") < 1000)
		return notify_fail("��ľ��������ˣ�\n");

	if(me->query_encumbrance()/100 > me->query("neili") + cost)
		return notify_fail("�����ô�صİ�������·�������⣬��˵���ˣ�\n");

	if(query("exits/enter")) return notify_fail("�д������������Cool����\n");    
        
	if(!objectp(room = find_object(__DIR__"duchuan") )) return notify_fail("��⣬�����ˣ���֪ͨ��ʦ��\n");
            
	if((int)room->query("exits/out") ) return notify_fail("����̫���ˣ����û����;�����ĵط�����û����Խ��ȥ��\n"); 
        
	me->receive_damage("neili", 200);
	me->receive_damage("jingli", 100);
	tell_room(environment(me), HIC+me->name()+"���˽�������Ʒ�������ų���ƮƮ������Ծ�ɻƺӣ�\n" NOR, ({me}));
	write("��һ����Ϣ����׼�˺��жɴ�λ�ã�ʹ����һέ�ɽ����Ṧ��Ҫ��Խ�ƺӡ�\n");
	me->move(__DIR__"duchuan");
	me->start_busy(3);
	if(me->query_encumbrance()/100 > me->query("neili") + cost
	 || me->query("neili") < 700 || me->query("jingli") < 500){
		write("�㻹��������ȴ�������������ˡ�\n");
		tell_room(environment(me), HIC+me->name()+"����ƮƮ���Ӻ����Ϸ�Ծ������վ�ڴ��ϣ���ڴ�ڴ�������\n" NOR, ({me}));
		return 1;
	}
	tell_room(environment(me), HIC+me->name()+"����ƮƮ���Ӻ����Ϸ�Ծ�������ڴ���һ�㣬����Ծ����\n" NOR, ({me}));
	write("���ں��жɴ�������һ�㣬�����������򶫰���\n");
	me->move(SHIP_TO);
	tell_room(environment(me), HIC"ֻ��"+me->name()+"����ƮƮ�Ӷ԰�Ծ������̬���������ڰ��ߡ�\n"NOR, ({me}));
	me->add("neili", -200);
        me->add("jingli", -100);
	return 1;
}
