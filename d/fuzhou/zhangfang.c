// Room: /d/fuzhou/zhangfang.c
// Lklv 2002.1.15
inherit ROOM;

void create()
{
	set("short", "�ھ��ʷ�");
	set("long", @LONG
���Ǹ����ھֵ��ʷ�������������һ�Ű������������Ϸ���һ����������
�žɵ����̡�ǽ�߰��˼������ӡ�
LONG
	);
	set("exits", ([
        	"west" : __DIR__"biaoju",
	]));
	set("objects", ([
		__DIR__"npc/zhangfang" : 1,
	]));
	setup();
}
