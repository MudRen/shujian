// /d/hmy/qiandian.c

inherit ROOM;

int valid_leave(object me, string dir);

void create()
{
	set("short", "ǰ��");
	set("long", @LONG
����һ����ΰ�ĵ��ã�������Էֱ����Ű�����������񣬸�Լ�˳ߣ���
�г��Ų�ͬ����������̬�������죬����������һ����̳��̳��ȼ������
ɫ�Ļ��棬�쳣���ء�
LONG
	);
	set("valid_startroom", "1");
	set("exits", ([ 
	  "east" : __DIR__"changlang",
	  "west" : __DIR__"shibanlu",
	]));
	set("objects", ([ 
		__DIR__"npc/shizhe" : 2,
	]));

	setup();
}
