// Room: /d/tianshan/pmfeng.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "��翷�");
	set("long", @LONG
��������ɽ���壬ɽ�������Ʒ����������켴����ããһƬ���վ�֮����
ԶԶ��ȥ���������ޣ���˽�����翷塣
LONG);
	 set("exits", ([
                "northdown" : __DIR__"dadao1",
		"southdown" : __DIR__"shanjin6",
        ]));        

	set("outdoors", "��ɽ");
	setup();
}


void init()
{
          add_action("do_push", "leave");
}

int do_push()
{
          object me = this_player();
          if (me->is_busy() || me->is_fighting())
                 return notify_fail("����æ���ء�\n");
if(me->query("family") && me->query("family/family_name")!="���չ�")
                   return notify_fail("ʲô?\n");
      message_vision("��Ʈ����վ��ޱȣ���·���ʣ���$N�������չ�����Ȼ��������һ������С·������ֱ��ɽ�¡�\n", me);
          me->receive_damage("jing", 30);
          me->start_busy(random(2));
        message_vision("$N���˰��죬�ѵ�ɽ�š�������ľ���ף�������ȥ��������Ұ��\n", me);
 me->move("/d/gumu/xiaolu1");
          return 1;
}
