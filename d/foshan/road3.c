// road3.c by XiaoYao

inherit ROOM;
void create()
{
        set("short","�ּ��");
        set("long",@LONG
������һ���ּ�С���������������ѡ������ǹ����ˡ�����ɽ��ï�ܣ���
�����棬��λ��·Ҫʮ��С�ġ�
LONG);
	set("outdoors", "��ɽ");
	set("exits",([ /* sizeof() == 1 */
		"east"      : __DIR__"road2",
		"northwest" : __DIR__"road4",
	]));
	setup();
}
