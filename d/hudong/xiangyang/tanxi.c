// /d/xiangyang/tanxi.c ̴Ϫ
// Lklv Modify 2001.9.22

inherit ROOM;
void create()
{
	set("short", "̴Ϫ");
	set("long", @LONG
����һ���ļ���С�ӣ���ˮ���������峺���ס�������ž����������
������㣬������ǵ�����������׷��ʱ��Խ̴Ϫ�ĵط�������С�Ӿ��Ƕ�
��������̴Ϫ�����ϱ�����С·ͨ���Ĵ���
LONG
	);
        set("outdoors", "����");

	set("exits", ([
		"east" : __DIR__"outwroad1",
		"southwest" : __DIR__"xiaolu1",
	]));
	setup();
}
