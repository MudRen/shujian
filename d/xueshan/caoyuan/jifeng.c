// Room: jifengying.c

inherit ROOM;

void create()
{
	set("short", "����Ӫ");
	set("long", @LONG
�������ɹž��������Ӫ���������ǧ�˶ӣ���ǰ��Բ������֧���˼�����
���񡣲�ʱ���ɹ����С������ڹ������ɹű����¼���������ǹҫ�ۣ������
֮�����Ǽ������¡����ѵõ�������ǧ����������������ż����ǹ���е���ײ��
���⣬�����κ����ӣ����ɵ��������ͳ�ʵĽ����ξ��з���
LONG
	);

	set("exits", ([
		"north" : __DIR__"shenfeng",
		"south" : __DIR__"yingmen",
	]));
	set("outdoor","���ԭ");
        set("objects",([
		__DIR__"../npc/zhebie" : 1,
		__DIR__"../npc/jqbing" : 3
	]));
	setup();
}
