// Room: /d/shaolin/taijie.c
// Date: YZC 96/01/19
// by zqb
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
����ɽ�ŵ��ǰ����ƽ�е���ʯ̨��ͨ��ǰ����һ���㳡��̨���Ͼ�
���ο������룬���꣬�ɺ׵����ޣ���̬���涯�ˡ��㳡���з��Ÿ����˸�
����ͭ����¯��ǰ����Ÿ���̨����λ����������Ӱݡ�����ǰ��������
�
LONG
	);

	set("exits", ([
		"east" : __DIR__"gchang-3",
		"south" : __DIR__"smdian",
		"west" : __DIR__"gchang-2",
		"north" : __DIR__"qdian",
	]));

	set("outdoors", "shaolin");
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("coor/x",50);
  set("coor/y",220);
   set("coor/z",110);
   set("coor/x",50);
 set("coor/y",220);
   set("coor/z",110);
   setup();
}

void init()
{
	 
 
        object me;
	int lvl;
        mapping learned;

        me = this_player();

	lvl = me->query_skill("hunyuan-yiqi", 1);
	learned = me->query_learned();
	me->delete_skill("hunyuan-yiqi");
	if (lvl > 0) {
		me->delete_skill("yijin-jing");
		me->set_skill("yijin-jing", lvl);
		if (mapp(learned) && learned["hunyuan-yiqi"] > 0)
			me->improve_skill("yijin-jing",
				learned["hunyuan-yiqi"], 1);
		write(HIG "ϵͳ�ѽ����ġ���Ԫһ������ת��Ϊ���׽����\n" NOR);
	}
	if (me->query_skill_mapped("force") == "hunyuan-yiqi")
		me->map_skill("force", "yijin-jing");

}


