// Room: /city/ximen.c
// YZC 1995/12/04 
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "����");
	set("long", @LONG
	���������ţ�����ǰ�����⵽���˵Ĺ�������Ե���Щ�ưܡ���������
������ǿǿ�����ϳ������š��������֣���ǽ�����ż���ͨ����ʾ(gaoshi)��
�������ﷸ��������ıؾ�֮�ء�
LONG
	);
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east" : __DIR__"xidajie2",
         "south" : __DIR__"work1",
	]));
	setup();
}


//�Ǿ���
int is_mirror() { return 1; }