// Room: /d/xiangyang/conglin4.c

inherit ROOM;
void create()
{
	set("short", "ɽ��յ�");
	set("long", @LONG
������ɽ´�ϵ�һ��յأ�·�Ե��Ӳݺ���ľ�����������ˡ�·����һ��
����ľ�����С�ݣ�С�ݵ��ſ���һЩ��������Ϣ��һЩ��������������·��
�����ϡ�����������һƬ���֣�ʷ�����ֵ������������Ҫץʲô���
LONG	);
        set("xyjob", 1);
	set("exits", ([
        	"eastdown" : __DIR__"conglin3",
        	"northwest" : "/d/gumu/xuantie/xiaolu4",

        ]));
        set("objects",([
              "/clone/npc/shijiqiang" : 1,
              "/clone/npc/shibowei" : 1,
              "/clone/npc/shimengjie" : 1,
              "/clone/npc/shishugang" : 1,
              "/clone/npc/shizhongmeng" : 1,
        ]));

        set("outdoors", "����");
	setup();
}
