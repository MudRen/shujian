// Room: shenfengying.c

inherit ROOM;

void create()
{
	set("short", "���Ӫ");
	set("long", @LONG
�������ɹž�������Ӫ���������ǧ�˶ӣ���ǰ��Բ������֧���˼�����
���񡣲�ʱ���ɹ����С������ڹ������ɹű����¼���������ǹҫ�ۣ������
֮�����Ǽ������¡����ѵõ�������ǧ����������������ż����ǹ���е���ײ��
���⣬�����κ����ӣ����ɵ��������ͳ�ʵĽ����ξ��з���
LONG
	);

	set("exits", ([
		"north" : __DIR__"dazhang",
		"south" : __DIR__"jifeng",
	]));
        set("outdoors", "ѩɽ");
	set("objects",([
		__DIR__"../npc/zhelemi" : 1,
		__DIR__"../npc/sqbing" : 3
	]));
	setup();
}
