// Room: /d/shaolin/xiaoxi.c
// by bren

inherit ROOM;

int do_jump(string arg);

void create()
{
	set("short", "СϪ");
	set("long", @LONG
����һ���ɺ�ɽ��������Ϫ����СϪ����������һԾ�ƺ��Ϳɱĵ���
����Ϫ����������ݳ��ü���ïʢ����������֮�У��������������Ϫ��
��ˮ���峺�����������Ŀ���ˮ�׵Ķ���ʯ�������ζ���С�㡣СϪ�����
�յ�����һ�������С¥��
LONG
	);

	set("exits", ([
		
		
		"west" : __DIR__"xiaolu4",
	]));

	set("outdoors", "shaolin");
	set("coor/x",100);
  set("coor/y",370);
   set("coor/z",130);
   setup();
      
}

void init()
{
	
	add_action("do_jump", "jump");
	add_action("do_jump", "yue");
}

int do_jump(string arg)
{
	object me = this_player();

	if (arg == "river" || arg == "xiaoxi") {
		if (me->is_busy() || me->is_fighting()) write("����æ���ء�\n");
		else if (me->query_skill("dodge", 1) >= 60) {
			message("vision", me->name() + "���˿��������������Ծȥ��\n",
				environment(me), ({me}) );
			write("�����˿��������������Ծȥ��\n");
			me->move(__DIR__"xiaoxi1");
			message("vision", "ֻ����Ӱһ����" + me->name() +  "����Ծ�˹�����\n",
				environment(me), ({me}) );
		}
		else {
			message("vision", me->name() + "���������Ծȥ��ֻ������ͨ��һ����" + me->name() + "ˤ��Ϫ�У��Ǳ������˻�����\n",
                                environment(me), ({me}) );
			write("�����������Ծȥ��ֻ������ͨ��һ������ˤ��Ϫ�У��Ǳ������˻�����\n");
                        me->receive_damage("qi",30);
		}
		return 1;
	}
	return 0;
}
