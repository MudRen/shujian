// Room: /d/city/duchang4.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����֮��");
	set("long", @LONG
������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"duchang",
]));
    
	setup();
}
//�Ǿ���
int is_mirror() { return 1; }