// Room: /city/yamen.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "���Ŵ���");
	set("long", @LONG
	���������Ŵ��ţ�������ľ���Ž����ر��š����ྲ�����رܡ������ӷ�
����ͷʯʨ�ӵ��Աߡ�ǰ����һ����ģ���Ȼ�ǹ�С����ԩ�õġ�������������ǰ
Ѳ�ߡ�
LONG
	);
	set("exits", ([
		"south" : __DIR__"xidajie1",
		"north" : __DIR__"ymzhengting",
	]));
	setup();
}

//�Ǿ���
int is_mirror() { return 1; }
