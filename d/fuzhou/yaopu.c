// Room: /d/fuzhou/yaopu.c
// Lklv 2001.9.7
inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
����һ��ҩ�̣��������ŵ���һ���߸ߵĹ�̨����̨���濿ǽ�кü�����
���ľͷ���ӣ����濪�˺ܶ�С���룬�����ϻ�д�źܶ�С�֣��е��Ѿ�ģ��
���塣����������һ��Ũ�ҵ��в�ҩζ����һ����ɫ�Ͱ�����ͷ�������Աߵ�
�����ϱ�Ŀ����
LONG
	);

	set("exits", ([
                "east" : __DIR__"xixiang2",
	]));
    	set("objects", ([
        	__DIR__"npc/laozhe" : 1,
	]) );
	set("outdoors", "����");
	setup();
}
