// Room: /d/huashan/pubu.c
// Date: Look 99/03/25

inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", "�ٲ�"NOR);
        set("long", @LONG
������һ��Ͽ�ȣ�ÿ���꼾ɽ�鱬��ʱ���γ���һ��εΪ׳�۵��ٲ�����
˵�������������������������ɾ��������������ġ�������ȥ�ȿգ�ֻʣ��
���ȵ�ɽ�Ⱥͷ������µ��ٲ�(Pubu)��Ȫˮ��ɽ����к�������γ�һ��ˮ����
�ڵ��³��һ����̶(Tan)�������ǻ�ɽ��Ů�塣
LONG    );
        set("resource/water", 1);
        set("item_desc", ([
                "tan" : "����һ���ǳ����̶��������ԼԼ�����������̶�Ա�����С·��\n",
		"pubu" : "����һ�ɷ������µ��ٲ�������������ˮ����ϡ�и��������轣��\n
���㶨����ϸһ����������ֻ������ˮ�淴������Ӱ�Ӱ��ˡ�\n",
        ]) );
        set("exits", ([ 
        "east" : __DIR__"yunu",
        ]));
        set("objects",([
                __DIR__"npc/frog" : 1
        ]) );
        set("outdoors", "��ɽ" );
        set("coor/x",60);
  set("coor/y",30);
   set("coor/z",60);
   setup();
}
 
void init()
{
        add_action("do_jump","tiao");
        add_action("do_fill","fill");
//        add_action("do_wujian", "wujian");
}

int do_jump(string arg)
{
        object me;
        int new_jing;
        me = this_player();
        new_jing = random( me->query("max_jing")*3 );
        if ( new_jing > me->query("jing") ) new_jing = me->query("jing") + 1;
        if( !arg || arg=="" ) return 0;

        if(me->query_temp("ride_horse"))
            return notify_fail("�����������޷�չ������\n");

        if( (me->query("dex") < 30) && ((int)me->query_skill("dodge")<100) )
                return notify_fail("�㿴��һ�������ˮ̶�����ɵõ�����һ����\n");
        if( arg == "down") {
        if(me->query_skill("dodge", 1) < 140){ 
        tell_object(me, HIR"�㻹û���ļ�ѡ��λ��������С�Ľ�һ����ֻ����һ������ɽȪ����Ϯ�����㱻������ȥ��\n"NOR);
        message("vision", HIR"ֻ��" + me->query("name") + "��С�Ľ�һ�����������ٲ�����ɽȪ������ȥ��\n"NOR, environment(me), me);      
        me->add("jing", 0 - new_jing);        
        me->move(__DIR__"shentan");
        return 1;
        }
        else 
        message_vision(HIR"$Nѡ��λ������һ�����ڿ���һ���������������ٲ���\n"NOR,me);
        me->move(__DIR__"shentan");
        return 1;
	}
        if ( arg == "tan" ) {
        message_vision(HIY"$Nһ�й�����ǽ����֫ƽչ�͵ó�ˮ̶���¡�\n"NOR, me);
        me->move(__DIR__"shuitan");
        message_vision(RED"��ͨһ����$N����������ˮ����������һ�󷭹���������Ҫ���������๾�࣬����������һ����ˮ��\n"NOR, me);
        me->receive_damage("jingli", 20);
        me->set("water", me->max_water_capacity()+200);
        me->start_busy(4);
        return 1;
	}
}


int do_fill(string arg)
{
        object me = this_player();
//        object ob = this_object();
        object tong;
        tong = present("shui tong", me);
        if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���ģ�\n");

        if(!arg || arg =="" || arg !="shuitong")
        return notify_fail("��Ҫ��ʲô��\n");
        
        if(arg =="shuitong" && present("shui tong", me)) {      
        if( tong->query("water") == 1) {
        write("Ͱ���Ѿ�ʢ����ˮ��\n", me);
        return 1;}
        message_vision("���ˮͰ�ŵ��ٲ��£�������ˮ��\n", me);
        tong->set("water", 1);
        tong->set("weight", 240000);
        tong->set("long", "ˮͰ��ʢ����Ȫˮ��\n");
        return 1;
        }
} 


int do_wujian()
{
        object me = this_player();
	object weapon;

        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ء�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("�������޽��������轣��\n");
	if ( ((int)me->query_skill("sword",1) < 100) )
		return notify_fail("������Ծ�𣬰ν������ٲ���ȥ��ȴ��ɥ�ط��ָ����������ٲ���\n");
	if ( ((int)me->query_skill("sword",1) > 260) )
		return notify_fail("������Ծ�𣬰ν������ٲ���ȥ����к��ˮ��������ֿ���\n");
        message_vision("$N����Ծ�𣬰ν������ٲ���ȥ��������˸��ˮ�ηɽ���$N�Ի���������������\n", me);
        me->receive_damage("jing", 15 + random((int)me->query_skill("sword" , 1) / 4));
        me->receive_damage("jingli", 15 + random((int)me->query_skill("sword" , 1) / 4));
        me->receive_damage("neili", 15 + random((int)me->query_skill("sword" , 1) / 4));
        me->improve_skill("sword", (int)me->query("int")*3);
        me->start_busy(random(2));
        return 1;
}


