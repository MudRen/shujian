// Room: /d/emei/qingyinge.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIW "������" NOR);
	set("long", @LONG
�����Ƕ���ɽ�������󡣴˸�λ��ţ�����£����а����������к�������
����֮ˮ�������������¡������й����������ֿ�������������������˫��
�š���������������һ���׸ߵĺں�ɫ��ʯ��Ȼͦ��������ţ�ģ���֮Ϊ��ţ
��ʯ�����ű�����һʯ��(shibei)���ɴ������ϣ������Ǻ�����ջ������·��
����������ȥ�з��¡�
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([
  "northwest" : __DIR__"bailongdong",
  "southwest" : __DIR__"heilongjiangzd",
  "southeast" : __DIR__"zhongfengsi",
]));
	set("objects",([
		CLASS_D("emei") + "/jing-xian" : 1,
		"/d/emei/npc/dizi" : 1,
]));
	set("item_desc", ([
  "shibei" : "ʯ������һʫԻ��

��������������\t\t�� Ȼ �� �� �� �� ����

              \t\t�� �� �� �� �� �� �١�

��������������\t\t�� �� ˫ Ϫ һ �� ����

              \t\t�� �� �� ˮ �� ţ �ġ�


\t   ����ǡ�����ʮ��ʫ����רӽ�⡰˫����������ʫ\n",
]));
	setup();
}
void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "tiao");
}
int do_jump(string arg)
{
	object me = this_player();

	if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
	return notify_fail("����æ���ģ�\n");

	if(!arg || arg == "" || arg != "ţ��ʯ")
	return notify_fail("��Ҫ��ʲô��\n");
	
	if( arg == "ţ��ʯ") {
	     message_vision("$N�����ĵ�ţ��ʯ���˹�ȥ��\n", me);
             if(me->query_skill("dodge", 1)<30&&me->query_dex()<28){
                      message_vision(HIY"���$Nһ�Ųȿգ�������ȥ��\n"NOR, me);
                      me->move(__DIR__"shuitan");
                      message_vision(HIC"ֻ������ͨһ����$N�������������������˴�ˮ̶�У���ཹ�ེ��˺ü���ˮ....\n"NOR, me);
                      me->unconcious();
                      me->set("water", 500);
                      return 1;
                      }
	     me->move(__DIR__"niuxinshi");
             me->add("jingli", -200);
	     message_vision("$N�����������˹�����\n", me);
             me->start_busy(1);
             }
	     return 1;
}
	
